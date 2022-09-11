#include <shapes2d/shapes/triangle.hpp>

#include <shapes2d/plotter.hpp>
#include "../shapes_registry.hpp"

#include <cmath>


S2D_SHAPE_REGITRATOR_HELPER_DEFAULT(shapes2d::shapes::EquilateralTriangle)


namespace  {

const double kScaleY = std::sqrt(3.0) / 2.0;

} // ns a



void shapes2d::shapes::EquilateralTriangle::doPlot(const PlotterPtr &plotter)
{
    const auto dx = m_edgeSize / 2.0;
    const auto dy = m_edgeSize * kScaleY;

    shapes2d::PolygonBuilder polygon(3);
    polygon.addAbs(position() - Size2D{dx, -dy / 2.0});
    polygon.addRel({m_edgeSize, 0});
    polygon.addRel({-dx, -dy});

    plotter->polygon(polygon.points);
}


shapes2d::Rect2D shapes2d::shapes::EquilateralTriangle::doGetBoundingRect() const
{
    return Rect2D::fromCenterAndSizes(position(), Size2D{m_edgeSize, m_edgeSize * kScaleY});
}


shapes2d::shapes::EquilateralTriangle::EquilateralTriangle(double m_edgeSize)
    : m_edgeSize(m_edgeSize)
{
}


