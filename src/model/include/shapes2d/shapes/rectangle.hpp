#ifndef SHAPES2D_SHAPES_RECTANGLE_H
#define SHAPES2D_SHAPES_RECTANGLE_H
#pragma once

#include <shapes2d/shape.hpp>


namespace shapes2d {
namespace shapes {


class Rectangle : public shapes2d::Shape {
    double m_size;
protected:
    void doPlot(const plotter::PlotterPtr &plotter) override;
    const shape::MetaInfo* getMeta() const override;
public:
    Rectangle(double size = shapes2d::Shape::kDefaultSize);
};


} // ns shapes
} // ns shapes2d


#endif // SHAPES2D_SHAPES_RECTANGLE_H
