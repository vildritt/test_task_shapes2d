#ifndef SHAPES2D_SCENE_COMPOSER_H
#define SHAPES2D_SCENE_COMPOSER_H
#pragma once

#include <shapes2d/plotter_ptr.hpp>
#include <shapes2d/model_ptr.hpp>
#include <shapes2d/export.h>


namespace shapes2d {


class SceneComposer;
using SceneComposerPtr = std::shared_ptr<SceneComposer>;


class SHAPES2D_MODEL_EXPORT SceneComposer {
protected:
    virtual void doCompose(Model* model, const plotter::PlotterPtr& plotter) = 0;
public:
    virtual ~SceneComposer() {}

    void compose(Model* model, const plotter::PlotterPtr& plotter);

    //

    static SceneComposerPtr defaultComposer();
};


} // ns shapes2d


#endif // SHAPES2D_SCENE_COMPOSER_H
