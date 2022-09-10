#include <shapes2d/shape.hpp>


void shapes2d::Shape::plot(const plotter::PlotterPtr &plotter)
{
    doPlot(plotter);
}


shapes2d::Shape::Shape()
{
    //
}


const shapes2d::shape::MetaInfo *shapes2d::Shape::meta() const
{
    return getMeta();
}
