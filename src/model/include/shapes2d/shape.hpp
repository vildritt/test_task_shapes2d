#ifndef SHAPES2D_SHAPE_H
#define SHAPES2D_SHAPE_H
#pragma once

#include <memory>

#include <shapes2d/plotter_ptr.hpp>


namespace shapes2d {


class Shape {
protected:
    virtual void doPlot(const plotter::PlotterPtr &plotter) = 0;
public:
    void plot(const plotter::PlotterPtr &plotter);

    // consts

    static constexpr const double kDefaultSize = 20.0;
};


using ShapePtr = std::shared_ptr<Shape>;


} // ns shapes2d


#endif // SHAPES2D_SHAPE_H
