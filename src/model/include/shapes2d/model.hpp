#ifndef SHAPES2D_MODEL_H
#define SHAPES2D_MODEL_H
#pragma once


#include <memory>
#include <functional>

#include <shapes2d/shape.hpp>
#include <shapes2d/plotter_ptr.hpp>
#include <shapes2d/scene_composer.hpp>
#include <shapes2d/export.h>


namespace shapes2d {


class ModelPrivate;

/**
 * @brief Shapes2D: scene of 2d simple shapes
 */
class SHAPES2D_MODEL_EXPORT Model {
public:
    Model();
    ~Model();

    // non copiable/movable
    Model(const Model&) = delete;
    Model& operator=(const Model&) = delete;
    Model(Model&&) = delete;
    Model& operator=(Model&&) = delete;


    /// scene build


    /**
     * @brief Clear scene - remove all shapes
     */
    void clearScene();

    /**
     * @brief z-ordered add new shape to scene
     */
    void addShape(const ShapePtr& shape);

    /**
     * @brief add helper for simple typed, default constructed shapes
     */
    template<typename T>
    void addShape() {
        addShape(std::make_shared<T>());
    }

    /**
     * @brief enumerator
     */
    using ShapeHandler = std::function<void (const ShapePtr& shape)>;
    void forEachShape(ShapeHandler handler);


    /// scene plot and compose

    void setAutoComposer(const SceneComposerPtr& composer);

    /**
     * @brief plot scene with given plotter
     */
    void plotScene(const plotter::PlotterPtr& plotter);


    /// stats

    int shapesCount(const shape::RegistryIdentifier& id) const;

    using OnStatUpdate = std::function<void (const shape::RegistryIdentifier& id, int count)>;
    void registerStatUpdateHandler(OnStatUpdate handler);

private:

    std::unique_ptr<ModelPrivate> d_ptr;

};


} // ns shapes2d


#endif // SHAPES2D_MODEL_H
