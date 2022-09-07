#ifndef SHAPES2D_SHAPES_CIRCLE_H
#define SHAPES2D_SHAPES_CIRCLE_H
#pragma once

#include <shapes2d/shape.hpp>


namespace shapes2d {
namespace shapes {


class Circle : public shapes2d::Shape {
    double m_radius;
protected:
    void doPlot(const plotter::PlotterPtr &plotter) override;
public:
    static constexpr const double kDefaultRadius = shapes2d::Shape::kDefaultSize / 2.0;
    Circle(double radius = kDefaultRadius);
};


} // ns shapes
} // ns shapes2d


#endif // SHAPES2D_SHAPES_CIRCLE_H
