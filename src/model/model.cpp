#include <shapes2d/model.hpp>
#include <shapes2d/plotter.hpp>

#include <vector>
#include <list>
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
    std::list<ShapePtr> m_shapes;
    std::unordered_map<shape::RegistryIdentifier, int> m_stats;
    std::vector<Model::OnStatUpdate> m_statUpdateHandlers;

    void clear()
    {
        m_shapes.clear();

        std::vector<shape::RegistryIdentifier> ids;
        ids.reserve(m_stats.size());
        for(const auto& stat : m_stats) {
            ids.push_back(stat.first);
        }

        m_stats.clear();

        for(const auto& id : ids) {
            notifyStatUpdate(id);
        }
    }

    void addShape(const ShapePtr &shape)
    {
        m_shapes.push_back(shape);

        // stat
        {
            const auto id = shape->meta()->id;
            m_stats[id]++;
            notifyStatUpdate(id);
        }
    }

    void notifyStatUpdate(const shape::RegistryIdentifier& id)
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


void shapes2d::Model::showAllShapes()
{
    for(auto& shape : d_ptr->m_shapes) {
        shape->setVisible(true);
    }
}


void shapes2d::Model::plotScene(const plotter::PlotterPtr &plotter)
{
    assert(plotter && "plotter required");

    // simple composer // TODO 1: extract as strategy composer
    {
        shapes2d::Palette palette = shapes2d::Palette::defaultPalette();

        Point2D prevShapeCenter;
        Point2D maxCoord;
        int idx = 0;
        for(const auto& shape : d_ptr->m_shapes) {
            if (!shape->isVisible()) {
                continue;
            }
            const auto br = shape->boundingRect();
            const auto shapeHalfSize = br.size() / 2.0;

            prevShapeCenter = prevShapeCenter + shapeHalfSize;
            maxCoord = prevShapeCenter + shapeHalfSize;

            shape->setPosition(prevShapeCenter);
            shape->setFgColor(Colors::black);
            shape->setBgColor(palette[idx++]);
        }

        // rev x coordinate
        for(const auto& shape : d_ptr->m_shapes) {
            if (!shape->isVisible()) {
                continue;
            }

            auto pt = shape->position();
            pt.x = maxCoord.x - pt.x;
            shape->setPosition(pt);
        }

        const auto plotterSize = plotter->getSize();
        const double xScale = plotterSize.x / maxCoord.x;
        const double yScale = plotterSize.y / maxCoord.y;
        const double scale = std::min(xScale, yScale);
        plotter->setScale(scale);
    }

    for(const auto& shape : d_ptr->m_shapes) {
        if (shape->isVisible()) {
            shape->plot(plotter);
        }
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


void shapes2d::Model::registerStatUpdateHandler(OnStatUpdate handler)
{
    d_ptr->m_statUpdateHandlers.push_back(handler);
}
