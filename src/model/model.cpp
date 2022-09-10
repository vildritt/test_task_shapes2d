#include <shapes2d/model.hpp>
#include <shapes2d/plotter.hpp>

#include <vector>
#include <unordered_map>
#include <typeinfo>
#include <typeindex>

#include <cassert>


namespace shapes2d {


class ModelPrivate {
public:
    Model* q_ptr;
    ModelPrivate(Model* q_ptr)
        : q_ptr(q_ptr)
    {
    }

    // z ordered shapes
    std::vector<ShapePtr> m_shapes;

    std::unordered_map<shape::RegistryIdentifier, int> m_stats;

    void clear()
    {
        m_shapes.clear();
        m_stats.clear();
        //TODO 0: signalize about changes
    }

    void addShape(const ShapePtr &shape)
    {
        m_shapes.push_back(shape);
        m_stats[shape->meta()->id]++;
        //TODO 0: signalize about changes
    }
};


} // ns shapes2d


shapes2d::Model::Model()
    : d_ptr(new ModelPrivate(this))
{
}


shapes2d::Model::~Model()
{
    // NOTE: just for unique_std to work
}


void shapes2d::Model::clearScene()
{
    d_ptr->clear();
}


void shapes2d::Model::addShape(const ShapePtr &shape)
{
    d_ptr->addShape(shape);
}


void shapes2d::Model::plotScene(const plotter::PlotterPtr &plotter)
{
    assert(plotter && "plotter required");

    for(const auto& shape : d_ptr->m_shapes) {
        //TODO 0: setup scales
        //TODO 0: move current point on each draw
        //TODO 0: decide where to place curent point for each fogure
        //TODO 0: explore figures sized and eval points for drawing
        shape->plot(plotter);
    }
}


int shapes2d::Model::shapesCount(const shape::RegistryIdentifier &id) const
{
    const auto it = d_ptr->m_stats.find(id);
    if (it == d_ptr->m_stats.end()) {
        return 0;
    }
    return it->second;
}
