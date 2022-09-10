#include <shapes2d/plotter.hpp>


shapes2d::plotter::Plotter::Plotter()
{
}


void shapes2d::plotter::Plotter::setFgColor(Color color)
{
    m_state.fgColor = color;
    doSetFgColor(color);
}


void shapes2d::plotter::Plotter::setBgColor(Color color)
{
    m_state.bgColor = color;
    doSetBgColor(color);
}


void shapes2d::plotter::Plotter::moveTo(const Point2D &pt)
{
    doMoveTo(pt);
    m_state.pt = pt;
}


void shapes2d::plotter::Plotter::lineTo(const Point2D &pt)
{
    doLineTo(pt);
    m_state.pt = pt;
}


void shapes2d::plotter::Plotter::circle(double radius)
{
    doCircle(radius);
}


void shapes2d::plotter::Plotter::polygon(const std::vector<shapes2d::Point2D>& points)
{
    doPolygon(points);
}


shapes2d::Size2D shapes2d::plotter::Plotter::getSize() const
{
    return doGetSize();
}


void shapes2d::plotter::Plotter::relativeLineTo(const Point2D &pt)
{
    const auto& s = state();
    lineTo(s.pt + pt);
}


const shapes2d::plotter::Plotter::State& shapes2d::plotter::Plotter::state() const
{
    return m_state;
}


shapes2d::plotter::Plotter::State &shapes2d::plotter::Plotter::state()
{
    return m_state;
}


void shapes2d::plotter::Plotter::setScale(double scale)
{
    m_state.scale = scale;
}


shapes2d::Size2D shapes2d::plotter::Plotter::doGetSize() const
{
    return {0.0, 0.0};
}

