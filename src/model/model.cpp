#include <shapes/model.hpp>


namespace shapes {


class ModelPrivate {
public:
    Model* q_ptr;
    ModelPrivate(Model* q_ptr)
        : q_ptr(q_ptr)
    {
    }
};


} // ns shapes


shapes::Model::Model()
    : d_ptr(new ModelPrivate(this))
{
}


shapes::Model::~Model()
{
    // for unique_std
}
