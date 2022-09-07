#include <shapes2d/shapes/rectangle.hpp>

#include <shapes2d/plotter.hpp>


void shapes2d::shapes::Rectangle::doPlot(const plotter::PlotterPtr &plotter)
{
    plotter->relativeLineTo(m_size, 0);
    plotter->relativeLineTo(0, m_size);
    plotter->relativeLineTo(-m_size, 0);
    plotter->relativeLineTo(0, -m_size);
}


shapes2d::shapes::Rectangle::Rectangle(double size)
    : m_size(size)
{
}
