#ifndef SHAPES2D_SHAPES_CIRCLE_H
#define SHAPES2D_SHAPES_CIRCLE_H
#pragma once


#include <shapes2d/shape.hpp>
#include <shapes2d/export.h>


namespace shapes2d {
namespace shapes {


class SHAPES2D_MODEL_EXPORT Circle : public shapes2d::Shape {
    double m_radius;
protected:
    void doPlot(const plotter::PlotterPtr &plotter) override;
    const shape::MetaInfo* getMeta() const override;
    Rect2D doGetBoundingRect() const override;
public:
    static constexpr const double kDefaultRadius = shapes2d::Shape::kDefaultSize / 2.0;
    Circle(double radius = kDefaultRadius);
};


} // ns shapes
} // ns shapes2d


#endif // SHAPES2D_SHAPES_CIRCLE_H
