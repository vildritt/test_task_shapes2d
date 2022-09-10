#ifndef SHAPES2D_SHAPE_H
#define SHAPES2D_SHAPE_H
#pragma once


#include <shapes2d/plotter_ptr.hpp>
#include <shapes2d/shape_meta_info.hpp>
#include <shapes2d/misc.hpp>
#include <shapes2d/color.hpp>
#include <shapes2d/vector2d.hpp>


namespace shapes2d {


/**
 * @brief Abstract 2d shape base class
 */
class Shape {
private:
    bool m_visible = true;
    Point2D m_position;
    Color m_fgColor = Colors::black;
    Color m_bgColor = Colors::white;
protected:
    virtual void doPlot(const plotter::PlotterPtr &plotter) = 0;
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
    void plot(const plotter::PlotterPtr &plotter);

    /**
     * @brief minimal rect that fully contains shape
     */
    Rect2D boundingRect() const;

    /// visible property
    bool isVisible() const;
    void setVisible(bool visible);

    void setPosition(const Point2D& position);
    const Point2D& position() const;

    Color fgColor() const;
    Color bgColor() const;

    void setFgColor(Color color);
    void setBgColor(Color color);

    /// consts

    static constexpr const double kDefaultSize = 20.0;
};


} // ns shapes2d


#endif // SHAPES2D_SHAPE_H
