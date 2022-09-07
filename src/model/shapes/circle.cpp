#include <shapes2d/shapes/circle.hpp>
#include <shapes2d/plotter.hpp>


void shapes2d::shapes::Circle::doPlot(const plotter::PlotterPtr &plotter)
{
    plotter->circle(m_radius);
}


shapes2d::shapes::Circle::Circle(double radius)
    : m_radius(radius)
{
}
