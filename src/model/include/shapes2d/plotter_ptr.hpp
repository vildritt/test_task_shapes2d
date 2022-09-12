#ifndef SHAPES2D_PLOTTER_PTR_H
#define SHAPES2D_PLOTTER_PTR_H
#pragma once

#include <memory>


namespace shapes2d {

class Plotter;

using PlotterPtr = std::shared_ptr<Plotter>;


} // shapes2d


#endif // SHAPES2D_PLOTTER_PTR_H
