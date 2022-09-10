#include "plot_area_widget.hpp"

#include <QPainter>


namespace shapes2d {
namespace gui {

class WidgetPlotter : public shapes2d::plotter::Plotter {
public:
    QPainter* painter = nullptr;
protected:

    void doSetFgColor(shapes2d::Color color) override
    {
        m_pen.setColor(color);
        painter->setPen(m_pen);
    }

    void doSetBgColor(shapes2d::Color color) override
    {
        m_brush.setColor(color);
        m_brush.setStyle(Qt::BrushStyle::SolidPattern);
        painter->setBrush(m_brush);
        painter->setBackgroundMode(Qt::BGMode::OpaqueMode);
    }

    void doLineTo(const shapes2d::Point2D& pt) override
    {
        const auto& st = state();
        const double s = st.scale;
        const auto pt1 = st.pt * s;
        const auto pt2 = pt * s;
        painter->drawLine(pt1.x, pt1.y, pt2.x, pt2.y);
    }

    void doCircle(double radius) override
    {
        const auto& st = state();
        const double s = st.scale;
        const auto rad = Size2D{radius, radius};
        const auto lt = (st.pt - rad) * s;
        const double diameter = radius * 2.0 * s;
        const auto rect = QRectF(lt.x, lt.y, diameter, diameter);
        painter->drawEllipse(rect);
    }

    void doPolygon(const std::vector<shapes2d::Point2D>& points) override
    {
        const auto& st = state();
        const double s = st.scale;

        QPolygon polgon;
        polgon.reserve(points.size());
        for(const auto& pt : points) {
            const auto pts = pt * s;
            polgon.push_back(QPoint(pts.x, pts.y));
        }

        painter->drawPolygon(polgon);
    }

    Size2D doGetSize() const override
    {
        const auto sz = painter->window();
        return Size2D(sz.width(), sz.height());
    }

private:

    QPen m_pen;
    QBrush m_brush;

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
    m_widgetPlotter->painter = &painter;
    m_model->plotScene(m_plotter);
}
