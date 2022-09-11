#include <shapes2d/plotter.hpp>


shapes2d::Plotter::Plotter()
{
}


void shapes2d::Plotter::setForegroundColor(Color color)
{
    m_state.fgColor = color;
    doSetForegroundColor(color);
}


void shapes2d::Plotter::setBackgroundColor(Color color)
{
    m_state.bgColor = color;
    doSetBackgroundColor(color);
}


void shapes2d::Plotter::moveTo(const Point2D &pt)
{
    doMoveTo(pt);
    m_state.point = pt;
}


void shapes2d::Plotter::lineTo(const Point2D &pt)
{
    doLineTo(pt);
    m_state.point = pt;
}


void shapes2d::Plotter::circle(double radius)
{
    doCircle(radius);
}


void shapes2d::Plotter::polygon(const std::vector<shapes2d::Point2D>& points)
{
    doPolygon(points);
}


shapes2d::Size2D shapes2d::Plotter::getCanvasSize() const
{
    return doGetCanvasSize();
}


const shapes2d::Plotter::State& shapes2d::Plotter::currState() const
{
    return m_state;
}


shapes2d::Plotter::State &shapes2d::Plotter::currState()
{
    return m_state;
}


void shapes2d::Plotter::setScale(double scale)
{
    m_state.scale = scale;
}


shapes2d::Size2D shapes2d::Plotter::doGetCanvasSize() const
{
    return {0.0, 0.0};
}


shapes2d::Point2D shapes2d::Plotter::State::xyOut(const Point2D &ptIn) const
{
    return ptIn * scale;
}


shapes2d::Point2D shapes2d::Plotter::State::ptOut() const
{
    return xyOut(point);
}
