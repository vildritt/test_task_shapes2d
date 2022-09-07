#ifndef SHAPES_MODEL_H
#define SHAPES_MODEL_H
#pragma once

#include <memory>


namespace shapes {


class ModelPrivate;
class Model {
public:
    Model();
    ~Model();
private:
    std::unique_ptr<ModelPrivate> d_ptr;
};


} // ns shapes


#endif // SHAPES_MODEL_H
