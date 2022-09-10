#include <shapes2d/shapes/rectangle.hpp>

#include <shapes2d/plotter.hpp>
#include "../shapes_registry.hpp"


S2D_SHAPE_REGITRATOR_HELPER_DEFAULT(shapes2d::shapes::Rectangle)


void shapes2d::shapes::Rectangle::doPlot(const plotter::PlotterPtr &plotter)
{
    const double halfSize = m_size / 2.0;

    std::vector<shapes2d::Point2D> pts;
    pts.reserve(4);

    shapes2d::Point2D pt = position() - Size2D{halfSize, halfSize};
    pts.push_back(pt);
    pt = pt + Point2D{m_size, 0.0};
    pts.push_back(pt);
    pt = pt + Point2D{0.0, m_size};
    pts.push_back(pt);
    pt = pt + Point2D{-m_size, 0.0};
    pts.push_back(pt);
    pt = pt + Point2D{0.0, -m_size};
    pts.push_back(pt);

    plotter->polygon(pts);
}


const shapes2d::shape::MetaInfo *shapes2d::shapes::Rectangle::getMeta() const
{
    return &::metaInfo;
}


shapes2d::Rect2D shapes2d::shapes::Rectangle::doGetBoundingRect() const
{
    return Rect2D::fromCenterAndSizes(position(), Size2D{m_size, m_size});
}


shapes2d::shapes::Rectangle::Rectangle(double size)
    : m_size(size)
{
}


