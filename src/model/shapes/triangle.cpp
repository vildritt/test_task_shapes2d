#include <shapes2d/shapes/triangle.hpp>

#include <shapes2d/plotter.hpp>
#include <cmath>


void shapes2d::shapes::EquilateralTriangle::doPlot(const plotter::PlotterPtr &plotter)
{
    const auto dx = m_edgeSize / 2.0;
    const auto dy = m_edgeSize * std::sqrt(3.0) / 2.0;

    plotter->relativeLineTo(m_edgeSize, 0);
    plotter->relativeLineTo(-dx, +dy);
    plotter->relativeLineTo(-dx, -dy);
}


shapes2d::shapes::EquilateralTriangle::EquilateralTriangle(double m_edgeSize)
    : m_edgeSize(m_edgeSize)
{
}
