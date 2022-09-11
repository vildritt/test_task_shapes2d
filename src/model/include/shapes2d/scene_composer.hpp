#ifndef SHAPES2D_SCENE_COMPOSER_H
#define SHAPES2D_SCENE_COMPOSER_H
#pragma once

#include <shapes2d/plotter_ptr.hpp>
#include <shapes2d/model_ptr.hpp>
#include <shapes2d/export.h>


namespace shapes2d {


class SceneComposer;
using SceneComposerPtr = std::shared_ptr<SceneComposer>;


/**
 * @brief Abstract composer. Base class for impl. any automatic composition strategies of scene objects
 */
class SHAPES2D_MODEL_EXPORT SceneComposer {
protected:
    virtual void doCompose(Model* model, const PlotterPtr& plotter) = 0;
public:
    virtual ~SceneComposer() {}

    void compose(Model* model, const PlotterPtr& plotter);

    //

    static SceneComposerPtr defaultComposer();
};


} // ns shapes2d


#endif // SHAPES2D_SCENE_COMPOSER_H
