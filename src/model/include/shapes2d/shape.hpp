#ifndef SHAPES2D_SHAPE_H
#define SHAPES2D_SHAPE_H
#pragma once


#include <shapes2d/plotter_ptr.hpp>
#include <shapes2d/shape_meta_info.hpp>
#include <shapes2d/misc.hpp>
#include <shapes2d/color.hpp>
#include <shapes2d/vector2d.hpp>
#include <shapes2d/export.h>


namespace shapes2d {


/**
 * @brief Abstract 2d shape base class
 */
class SHAPES2D_MODEL_EXPORT Shape {
private:
    bool m_visible = true;
    Point2D m_position;
    Color m_foregroundColor = Color::black;
    Color m_backgroundColor = Color::white;
protected:
    virtual void doPlot(const PlotterPtr &plotter) = 0;
    virtual const shape::MetaInfo* getMeta() const = 0;
    virtual Rect2D doGetBoundingRect() const = 0;
public:
    Shape();
    virtual ~Shape() {}
    S2D_DISABLE_COPY_AND_ASSIGN(Shape);
    S2D_DISABLE_MOVE_AND_MOVE_ASSIGN(Shape);

    /**
     * @brief get meta info dynamically
     */
    const shape::MetaInfo* meta() const;

    /**
     * @brief plot request with given plotter
     */
    void plot(const PlotterPtr &plotter);

    /**
     * @brief minimal rect that fully contains shape
     */
    Rect2D boundingRect() const;

    /// visible property
    bool isVisible() const;
    void setVisible(bool visible);

    /// center point of shape
    void setPosition(const Point2D& position);
    const Point2D& position() const;

    /// fg/bg color of shape setter/getter
    Color foregroundColor() const;
    void setForegroundColor(Color color);
    Color backgroundColor() const;
    void setBackgroundColor(Color color);

    /// consts

    static constexpr const double kDefaultSize = 20.0;
};


} // ns shapes2d


#endif // SHAPES2D_SHAPE_H
