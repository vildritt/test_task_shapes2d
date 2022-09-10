#ifndef SHAPES2D_SHAPES_TRIANGLE_H
#define SHAPES2D_SHAPES_TRIANGLE_H
#pragma once


#include <shapes2d/shape.hpp>
#include <shapes2d/export.h>


namespace shapes2d {
namespace shapes {


class SHAPES2D_MODEL_EXPORT EquilateralTriangle : public shapes2d::Shape {
    double m_edgeSize;
protected:
    void doPlot(const plotter::PlotterPtr &plotter) override;
    const shape::MetaInfo* getMeta() const override;
    Rect2D doGetBoundingRect() const override;
public:
    EquilateralTriangle(double m_edgeSize = shapes2d::Shape::kDefaultSize);
};


} // ns shapes
} // ns shapes2d


#endif // SHAPES2D_SHAPES_TRIANGLE_H
