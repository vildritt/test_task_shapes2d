#ifndef SHAPES2D_SHAPES_TRIANGLE_H
#define SHAPES2D_SHAPES_TRIANGLE_H
#pragma once
// TODO 0!: rename other guards

#include <shapes2d/shape.hpp>


namespace shapes2d { // TODO 0!: rename namepsace in other places
namespace shapes {


class EquilateralTriangle : public shapes2d::Shape {
    double m_edgeSize;
protected:
    void doPlot(const plotter::PlotterPtr &plotter) override;
public:
    EquilateralTriangle(double m_edgeSize = shapes2d::Shape::kDefaultSize);
};


} // ns shapes
} // ns shapes2d


#endif // SHAPES2D_SHAPES_TRIANGLE_H
