#ifndef SHAPES2D_SHAPE_H
#define SHAPES2D_SHAPE_H
#pragma once

#include <shapes2d/plotter_ptr.hpp>
#include <shapes2d/shape_meta_info.hpp>
#include <shapes2d/misc.hpp>

namespace shapes2d {

/**
 * @brief Abstract 2d shape base class
 */
class Shape {
protected:
    virtual void doPlot(const plotter::PlotterPtr &plotter) = 0;
    virtual const shape::MetaInfo* getMeta() const = 0;
public:
    Shape();
    virtual ~Shape() {}
    S2D_DISABLE_COPY_AND_ASSIGN(Shape);
    S2D_DISABLE_MOVE_AND_MOVE_ASSIGN(Shape);

    const shape::MetaInfo* meta() const;
    void plot(const plotter::PlotterPtr &plotter);

    // consts

    static constexpr const double kDefaultSize = 20.0;
};


} // ns shapes2d


#endif // SHAPES2D_SHAPE_H
