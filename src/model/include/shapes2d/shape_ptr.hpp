#ifndef SHAPES2D_SHAPE_PTR_H
#define SHAPES2D_SHAPE_PTR_H
#pragma once

#include <memory>

namespace shapes2d {

class Shape;
using ShapePtr = std::shared_ptr<Shape>;

} // ns shapes2d


#endif // SHAPES2D_SHAPE_PTR_H
