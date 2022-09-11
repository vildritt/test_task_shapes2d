#ifndef SHAPES2D_SHAPES_RECTANGLE_H
#define SHAPES2D_SHAPES_RECTANGLE_H
#pragma once


#include <shapes2d/shape.hpp>
#include <shapes2d/export.h>


namespace shapes2d {
namespace shapes {


class SHAPES2D_MODEL_EXPORT Rectangle : public shapes2d::Shape {
    double m_size;
protected:
    void doPlot(const PlotterPtr &plotter) override;
    const shape::MetaInfo* getMeta() const override;
    Rect2D doGetBoundingRect() const override;
public:
    Rectangle(double size = shapes2d::Shape::kDefaultSize);
};


} // ns shapes
} // ns shapes2d


#endif // SHAPES2D_SHAPES_RECTANGLE_H
