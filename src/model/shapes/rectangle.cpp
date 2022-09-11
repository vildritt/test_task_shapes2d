#include <shapes2d/shapes/rectangle.hpp>

#include <shapes2d/plotter.hpp>
#include "../shapes_registry.hpp"


S2D_SHAPE_REGITRATOR_HELPER_DEFAULT(shapes2d::shapes::Rectangle)


void shapes2d::shapes::Rectangle::doPlot(const PlotterPtr &plotter)
{
    shapes2d::PolygonBuilder polygon(4);

    polygon.addAbs(position() - (Size2D{m_size, m_size} / 2.0));
    polygon.addRel({m_size, 0.0});
    polygon.addRel({0.0, m_size});
    polygon.addRel({-m_size, 0.0});

    plotter->polygon(polygon.points);
}


shapes2d::Rect2D shapes2d::shapes::Rectangle::doGetBoundingRect() const
{
    return Rect2D::fromCenterAndSizes(position(), Size2D{m_size, m_size});
}


shapes2d::shapes::Rectangle::Rectangle(double size)
    : m_size(size)
{
}
