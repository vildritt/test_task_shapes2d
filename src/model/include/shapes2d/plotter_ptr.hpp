#ifndef SHAPES2D_PLOTTER_PTR_H
#define SHAPES2D_PLOTTER_PTR_H
#pragma once

#include <memory>


namespace shapes2d {
namespace plotter {

class Plotter;

using PlotterPtr = std::shared_ptr<Plotter>;


} // plotter
} // shapes2d


#endif // SHAPES2D_PLOTTER_PTR_H
