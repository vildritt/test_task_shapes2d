#include <shapes2d/model.hpp>

#include <shapes2d/plotter.hpp>
#include <shapes2d/shapes_registry.hpp>

#include <vector>
#include <list>
#include <unordered_map>
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
    std::list<ShapePtr> m_shapes;
    std::unordered_map<shape::Identifier, int> m_stats;
    std::vector<Model::OnStatUpdate> m_statUpdateHandlers;
    SceneComposerPtr m_composer;

    void clear()
    {
        m_shapes.clear();

        // update stats
        {
            std::vector<shape::Identifier> ids;
            ids.reserve(m_stats.size());
            for(const auto& stat : m_stats) {
                ids.push_back(stat.first);
            }

            m_stats.clear();

            for(const auto& id : ids) {
                notifyStatUpdate(id);
            }
        }
    }

    void addShape(const ShapePtr &shape)
    {
        m_shapes.push_back(shape);

        // update stat
        {
            const auto id = shape->meta()->id;
            m_stats[id]++;
            notifyStatUpdate(id);
        }
    }

    void notifyStatUpdate(const shape::Identifier& id)
    {
        for(const auto& handler : m_statUpdateHandlers) {
            handler(id, q_ptr->shapesCount(id));
        }
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


void shapes2d::Model::forEachShape(const ShapeHandler& handler)
{
    for(const auto& shape : d_ptr->m_shapes) {
        handler(shape);
    }
}


void shapes2d::Model::setSceneAutoComposer(const SceneComposerPtr &composer)
{
    d_ptr->m_composer = composer;
}


void shapes2d::Model::plotScene(const PlotterPtr &plotter)
{
    assert(plotter && "plotter required");

    if (d_ptr->m_composer) {
        d_ptr->m_composer->compose(this, plotter);
    }

    for(const auto& shape : d_ptr->m_shapes) {
        if (shape->isVisible()) {
            shape->plot(plotter);
        }
    }
}


int shapes2d::Model::shapesCount(const shape::Identifier &id) const
{
    const auto it = d_ptr->m_stats.find(id);
    if (it == d_ptr->m_stats.end()) {
        return 0;
    }
    return it->second;
}


int shapes2d::Model::shapesCount(const std::type_index &typeIndex) const
{
    auto& rs = shapes2d::shape::Registry::instance();
    const auto id = rs.typeIdentifier(typeIndex);
    return shapesCount(id);
}


void shapes2d::Model::registerStatUpdateHandler(OnStatUpdate handler)
{
    d_ptr->m_statUpdateHandlers.push_back(handler);
}
