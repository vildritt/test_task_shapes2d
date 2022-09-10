#include <shapes2d/scene_composer.hpp>

#include <shapes2d/color.hpp>
#include <shapes2d/vector2d.hpp>
#include <shapes2d/plotter.hpp>
#include <shapes2d/model.hpp>


namespace  {

/**
 * simple composer - diagonal ordered
 */
class SimpleComposer : public shapes2d::SceneComposer
{
protected:
    void doCompose(shapes2d::Model* model, const shapes2d::plotter::PlotterPtr& plotter) override
    {
        shapes2d::Palette palette = shapes2d::Palette::defaultPalette();

        shapes2d::Point2D prevShapeCenter;
        shapes2d::Point2D maxCoord;
        int idx = 0;
        model->forEachShape([&prevShapeCenter, &maxCoord, &palette, &idx](const shapes2d::ShapePtr& shape) {
            if (!shape->isVisible()) {
                return;
            }
            const auto br = shape->boundingRect();
            const auto shapeHalfSize = br.size() / 2.0;

            prevShapeCenter = prevShapeCenter + shapeHalfSize;
            maxCoord = prevShapeCenter + shapeHalfSize;

            shape->setPosition(prevShapeCenter);
            shape->setFgColor(shapes2d::Colors::black);
            shape->setBgColor(palette[idx++]);
        });

        // rev x coordinate
        model->forEachShape([&prevShapeCenter, &maxCoord, &palette, &idx](const shapes2d::ShapePtr& shape) {
            if (!shape->isVisible()) {
                return;
            }

            auto pt = shape->position();
            pt.x = maxCoord.x - pt.x;
            shape->setPosition(pt);
        });

        const auto plotterSize = plotter->getSize();
        const double xScale = plotterSize.x / maxCoord.x;
        const double yScale = plotterSize.y / maxCoord.y;
        const double scale = std::min(xScale, yScale);
        plotter->setScale(scale);
    }
};


} // ns a


void shapes2d::SceneComposer::compose(Model* model, const plotter::PlotterPtr &plotter)
{
    doCompose(model, plotter);
}


shapes2d::SceneComposerPtr shapes2d::SceneComposer::defaultComposer()
{
    return std::make_shared<SimpleComposer>();
}
