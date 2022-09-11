#ifndef SHAPES2D_MODEL_H
#define SHAPES2D_MODEL_H
#pragma once


#include <memory>
#include <functional>

#include <shapes2d/shape.hpp>
#include <shapes2d/plotter_ptr.hpp>
#include <shapes2d/scene_composer.hpp>
#include <shapes2d/export.h>
#include <shapes2d/misc.hpp>


namespace shapes2d {


/**
 * @brief Shapes2D: scene of 2d simple shapes
 */
class ModelPrivate;
class SHAPES2D_MODEL_EXPORT Model {
public:
    Model();
    ~Model();

    S2D_DISABLE_COPY_AND_ASSIGN(Model);
    S2D_DISABLE_MOVE_AND_MOVE_ASSIGN(Model);


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
     * @brief shapes enumerator
     */
    using ShapeHandler = std::function<void (const ShapePtr& shape)>;
    void forEachShape(const ShapeHandler &handler);


    /// scene plot and compose


    /**
     * @brief is compser assigned - will automatically compose objects on scene
     */
    void setSceneAutoComposer(const SceneComposerPtr& composer);


    /**
     * @brief plot scene with given plotter
     */
    void plotScene(const PlotterPtr& plotter);


    /// stats

    /**
     * @brief get count of shape of a given type id
     */
    int shapesCount(const shape::Identifier& id) const;

    /**
     * @brief stats observation
     * TODO 1: add ability to unregister/disconnect - return some object with disconnect ability
     */
    using OnStatUpdate = std::function<void (const shape::Identifier& id, int count)>;
    void registerStatUpdateHandler(OnStatUpdate handler);

    // TODO 1: impl also get count from static type (use typeinfo)

private:

    std::unique_ptr<ModelPrivate> d_ptr;

};


} // ns shapes2d


#endif // SHAPES2D_MODEL_H
