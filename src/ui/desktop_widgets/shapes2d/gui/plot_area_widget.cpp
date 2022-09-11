#include "plot_area_widget.hpp"

#include <QPainter>

#include <shapes2d/model.hpp>


namespace shapes2d {
namespace gui {


class WidgetPlotter : public shapes2d::Plotter {
public:
    void setPainter(QPainter* painter)
    {
        m_painter = painter;
    }
protected:

    void doSetForegroundColor(shapes2d::Color color) override
    {
        m_pen.setColor(color.argb);
        m_painter->setPen(m_pen);
    }

    void doSetBackgroundColor(shapes2d::Color color) override
    {
        m_brush.setColor(color.argb);
        m_brush.setStyle(Qt::BrushStyle::SolidPattern);
        m_painter->setBrush(m_brush);
        m_painter->setBackgroundMode(Qt::BGMode::OpaqueMode);
    }

    void doLineTo(const shapes2d::Point2D& pt) override
    {
        const auto& st = currState();
        const auto pt1 = st.ptOut();
        const auto pt2 = st.xyOut(pt);
        m_painter->drawLine(pt1.x, pt1.y, pt2.x, pt2.y);
    }

    void doCircle(double radius) override
    {
        const auto& st = currState();

        const double d = radius * 2.0 * st.scale;
        const auto lt = st.xyOut(st.point - Size2D{radius, radius});

        const auto rect = QRectF(lt.x, lt.y, d, d);

        m_painter->drawEllipse(rect);
    }

    void doPolygon(const std::vector<shapes2d::Point2D>& points) override
    {
        const auto& st = currState();

        QPolygon polgon;
        polgon.reserve(points.size());
        for(const auto& pt : points) {
            const auto pts = st.xyOut(pt);
            polgon.push_back(QPoint(pts.x, pts.y));
        }

        m_painter->drawPolygon(polgon);
    }

    Size2D doGetCanvasSize() const override
    {
        const auto csz = m_painter->window();
        return Size2D(csz.width(), csz.height());
    }

private:

    QPen m_pen;
    QBrush m_brush;
    QPainter* m_painter = nullptr;
};


struct WidgetPlotterSetPainterGuard {
    WidgetPlotter *plotter = nullptr;

    WidgetPlotterSetPainterGuard(WidgetPlotter *plotter, QPainter* patiner)
        : plotter(plotter)
    {
        plotter->setPainter(patiner);
    }

    ~WidgetPlotterSetPainterGuard() {
        try {
            plotter->setPainter(nullptr);
        } catch (...) {
        }
    }
};


}} // ns a


shapes2d::gui::PlotAreaWidget::PlotAreaWidget(Model *model, QWidget *parent)
    : QWidget(parent)
    , m_model(model)
    , m_plotter(std::make_shared<WidgetPlotter>())
    , m_widgetPlotter(dynamic_cast<WidgetPlotter*>(m_plotter.get()))
{
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
}


void shapes2d::gui::PlotAreaWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    WidgetPlotterSetPainterGuard guard(m_widgetPlotter, &painter);
    m_model->plotScene(m_plotter);
}
