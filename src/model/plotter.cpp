#include <shapes2d/plotter.hpp>


void shapes2d::plotter::Plotter::setColor(Color color)
{
    m_state.color = color;
    doSetColor(color);
}


void shapes2d::plotter::Plotter::moveTo(double x, double y)
{
    doMoveTo(x, y);
    m_state.x = x;
    m_state.y = y;
}


void shapes2d::plotter::Plotter::lineTo(double x, double y)
{
    doLineTo(x, y);
    m_state.x = x;
    m_state.y = y;
}


void shapes2d::plotter::Plotter::circle(double radius)
{
    doCircle(radius);
}


void shapes2d::plotter::Plotter::flood()
{
    doFlood();
}


void shapes2d::plotter::Plotter::relativeLineTo(double rx, double ry)
{
    const auto& s = state();
    lineTo(s.x + rx, s.y + ry);
}


const shapes2d::plotter::Plotter::State& shapes2d::plotter::Plotter::state() const
{
    return m_state;
}
