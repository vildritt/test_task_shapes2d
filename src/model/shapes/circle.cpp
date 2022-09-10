#include <shapes2d/shapes/circle.hpp>

#include <shapes2d/plotter.hpp>
#include "../shapes_registry.hpp"


S2D_SHAPE_REGITRATOR_HELPER_DEFAULT(shapes2d::shapes::Circle)


void shapes2d::shapes::Circle::doPlot(const plotter::PlotterPtr &plotter)
{
    plotter->circle(m_radius);
}


const shapes2d::shape::MetaInfo *shapes2d::shapes::Circle::getMeta() const
{
    return &::metaInfo;
}


shapes2d::shapes::Circle::Circle(double radius)
    : m_radius(radius)
{
}
