#ifndef SHAPES2D_PLOTTER_H
#define SHAPES2D_PLOTTER_H
#pragma once


#include <memory>
#include <vector>

#include <cstdint>

#include <shapes2d/plotter_ptr.hpp>
#include <shapes2d/misc.hpp>
#include <shapes2d/color.hpp>
#include <shapes2d/vector2d.hpp>
#include <shapes2d/export.h>


namespace shapes2d {

class SHAPES2D_MODEL_EXPORT Plotter {
public:
    Plotter();
    virtual ~Plotter() {}
    S2D_DISABLE_COPY_AND_ASSIGN(Plotter);
    S2D_DISABLE_MOVE_AND_MOVE_ASSIGN(Plotter);

    // current plotter state - point, colors, scale
    struct State {
        Point2D point;
        Color fgColor = Color::black;
        Color bgColor = Color::white;
        double scale = 1.0;

        // get in -> out transformation
        Point2D xyOut(const Point2D& ptIn) const;
        Point2D ptOut() const;
    };

    /// set foreground color
    void setForegroundColor(Color color);
    /// set background color
    void setBackgroundColor(Color color);
    /// set current 2d position
    void moveTo(const shapes2d::Point2D& pt);
    /// line from current positionto givem and make new point as current
    void lineTo(const shapes2d::Point2D& pt);
    /// plot circle with given radius with center at current position
    void circle(double radius);
    /// draw polygon
    void polygon(const std::vector<shapes2d::Point2D>& points);

    Size2D getCanvasSize() const;

    const State& currState() const;

    /**
     * @brief simple scale transformation for input -> output coordinates
     *      Xout = S * Xin
     *      Yout = S * Yin
     */
    void setScale(double scale);

protected:
    // writable
    State& currState();

    // virtual intf

    virtual void doSetForegroundColor(Color color) {}
    virtual void doSetBackgroundColor(Color color) {}
    virtual void doMoveTo(const shapes2d::Point2D& pt) {}
    virtual void doLineTo(const shapes2d::Point2D& pt) {}
    virtual void doCircle(double radius) {}
    virtual void doPolygon(const std::vector<shapes2d::Point2D>& points) {}
    virtual Size2D doGetCanvasSize() const;
private:
    State m_state;
};


} // shapes2d


#endif // SHAPES2D_PLOTTER_H
