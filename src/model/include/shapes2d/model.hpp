#ifndef SHAPES2D_MODEL_H
#define SHAPES2D_MODEL_H
#pragma once

#include <memory>

#include <shapes2d/shape.hpp> //TODO 0: how about fwd delcaration?
#include <shapes2d/plotter_ptr.hpp>


namespace shapes2d {


class ModelPrivate;
class Model {
public:
    Model();
    ~Model();

    void clear();
    void addShape(const ShapePtr& shape);
    void plot(const plotter::PlotterPtr& plotter);

    template<typename T>
    void addShape() {
        addShape(std::make_shared<T>());
    }
private:
    std::unique_ptr<ModelPrivate> d_ptr;
};


} // ns shapes2d


#endif // SHAPES2D_MODEL_H
