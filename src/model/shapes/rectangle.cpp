#include <shapes2d/shapes/rectangle.hpp>

#include <shapes2d/plotter.hpp>
#include "../shapes_registry.hpp"


S2D_SHAPE_REGITRATOR_HELPER_DEFAULT(shapes2d::shapes::Rectangle)


void shapes2d::shapes::Rectangle::doPlot(const plotter::PlotterPtr &plotter)
{
    plotter->relativeLineTo(m_size, 0);
    plotter->relativeLineTo(0, m_size);
    plotter->relativeLineTo(-m_size, 0);
    plotter->relativeLineTo(0, -m_size);
}


const shapes2d::shape::MetaInfo *shapes2d::shapes::Rectangle::getMeta() const
{
    return &::metaInfo;
}


shapes2d::shapes::Rectangle::Rectangle(double size)
    : m_size(size)
{
}


