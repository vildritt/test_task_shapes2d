#include <shapes2d/gui/qt_helper/painter_plotter.hpp>

#include <shapes2d/model.hpp>


namespace  {


struct PainterPlotterSetPainterGuard {
    shapes2d::gui::qt::PainterPlotter *plotter = nullptr;

    PainterPlotterSetPainterGuard(shapes2d::gui::qt::PainterPlotter *plotter, QPainter* painter)
        : plotter(plotter)
    {
        plotter->setPainter(painter);
    }

    ~PainterPlotterSetPainterGuard() {
        try {
            plotter->setPainter(nullptr);
        } catch (...) {
        }
    }
};


} // ns


void shapes2d::gui::qt::PainterPlotter::setPainter(QPainter *painter)
{
    m_painter = painter;
}


void shapes2d::gui::qt::PainterPlotter::doSetForegroundColor(Color color)
{
    m_pen.setColor(color.argb);
    m_painter->setPen(m_pen);
}


void shapes2d::gui::qt::PainterPlotter::doSetBackgroundColor(Color color)
{
    m_brush.setColor(color.argb);
    m_brush.setStyle(Qt::BrushStyle::SolidPattern);
    m_painter->setBrush(m_brush);
    m_painter->setBackgroundMode(Qt::BGMode::OpaqueMode);
}


void shapes2d::gui::qt::PainterPlotter::doLineTo(const Point2D &pt)
{
    const auto& st = currState();
    const auto pt1 = st.ptOut();
    const auto pt2 = st.xyOut(pt);
    m_painter->drawLine(pt1.x, pt1.y, pt2.x, pt2.y);
}


void shapes2d::gui::qt::PainterPlotter::doCircle(double radius)
{
    const auto& st = currState();

    const double d = radius * 2.0 * st.scale;
    const auto lt = st.xyOut(st.point - Size2D{radius, radius});

    const auto rect = QRectF(lt.x, lt.y, d, d);

    m_painter->drawEllipse(rect);
}


void shapes2d::gui::qt::PainterPlotter::doPolygon(const std::vector<Point2D> &points)
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


shapes2d::Size2D shapes2d::gui::qt::PainterPlotter::doGetCanvasSize() const
{
    const auto csz = m_painter->window();
    return Size2D(csz.width(), csz.height());
}


shapes2d::gui::qt::PainterPlotterHelper::PainterPlotterHelper(Model *model)
    : m_model(model)
    , m_plotter(std::make_shared<PainterPlotter>())
    , m_painterPlotter(dynamic_cast<PainterPlotter*>(m_plotter.get()))
{
}


void shapes2d::gui::qt::PainterPlotterHelper::plot(QPainter *painter)
{
    assert(m_painterPlotter && "plotter not created");

    PainterPlotterSetPainterGuard guard(m_painterPlotter, painter);

    if (m_model) {
        m_model->plotScene(m_plotter);
    }
}


void shapes2d::gui::qt::PainterPlotterHelper::setModel(Model *model)
{
    m_model = model;
}
