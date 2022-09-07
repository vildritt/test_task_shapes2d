#include <shapes2d/model.hpp>
#include <shapes2d/plotter.hpp>

#include <vector>
#include <unordered_map>
#include <typeinfo>
#include <typeindex>


namespace shapes2d {


class ModelPrivate {
public:
    Model* q_ptr;
    ModelPrivate(Model* q_ptr)
        : q_ptr(q_ptr)
    {
    }

    std::vector<ShapePtr> m_shapes;
    std::unordered_map<std::type_index, int> m_stats;

    void clear()
    {
        m_shapes.clear();
        m_stats.clear();
        //TODO 0: impl
        //TODO 0: clear stats, signalize about changes
    }
};


} // ns shapes2d


shapes2d::Model::Model()
    : d_ptr(new ModelPrivate(this))
{
}


shapes2d::Model::~Model()
{
    // for unique_std
}


void shapes2d::Model::clear()
{
    d_ptr->clear();
}


void shapes2d::Model::addShape(const ShapePtr &shape)
{
    //TODO 0: move to private
    d_ptr->m_shapes.push_back(shape);

    const auto tidx = std::type_index(typeid(*shape));
    d_ptr->m_stats[tidx]++;

    //TODO 0: impl
    //TODO 0: update stats
}


void shapes2d::Model::plot(const plotter::PlotterPtr &plotter)
{
    for(const auto& shape : d_ptr->m_shapes) {
        //TODO 0: setup scales
        //TODO 0: move current point on each draw
        //TODO 0: decide where to place curent point for each fogure
        //TODO 0: explore figures sized and eval points for drawing
        shape->plot(plotter);
    }
}
