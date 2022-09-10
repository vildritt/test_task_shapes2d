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


namespace shapes2d {
namespace plotter {

class Plotter {
public:
    Plotter();
    virtual ~Plotter() {}
    S2D_DISABLE_COPY_AND_ASSIGN(Plotter);
    S2D_DISABLE_MOVE_AND_MOVE_ASSIGN(Plotter);

    struct State {
        Point2D pt;
        Color fgColor = Colors::black;
        Color bgColor = Colors::white;
        double scale = 1.0;
    };

    /// set foreground color
    void setFgColor(Color color);
    /// set background color
    void setBgColor(Color color);
    /// set current 2d position
    void moveTo(const shapes2d::Point2D& pt);
    /// line from current positionto givem and make new point as current
    void lineTo(const shapes2d::Point2D& pt);
    /// plot circle with given radius with center at current position
    void circle(double radius);
    /// flood with selected color staring at current position
    void polygon(const std::vector<shapes2d::Point2D>& points);

    /// get canvas size
    Size2D getSize() const;

    /// relative line to - xy given relative to current position
    void relativeLineTo(const shapes2d::Point2D& pt);

    const State& state() const;

    /**
     * @brief simple scale for input -> output coordinates
     */
    void setScale(double scale);

protected:
    State& state();

    // virtual intf

    virtual void doSetFgColor(Color color) {}
    virtual void doSetBgColor(Color color) {}
    virtual void doMoveTo(const shapes2d::Point2D& pt) {}
    virtual void doLineTo(const shapes2d::Point2D& pt) {}
    virtual void doCircle(double radius) {}
    virtual void doPolygon(const std::vector<shapes2d::Point2D>& points) {}
    virtual Size2D doGetSize() const;
private:
    State m_state;
};


} // plotter
} // shapes2d


#endif // SHAPES2D_PLOTTER_H
