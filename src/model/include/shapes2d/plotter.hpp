#ifndef SHAPES2D_PLOTTER_H
#define SHAPES2D_PLOTTER_H
#pragma once

#include <memory>
#include <stdint.h>
#include <shapes2d/plotter_ptr.hpp>


namespace shapes2d {
namespace plotter {


using Color = int32_t; // TODO 0: ref, make friendly class

class Plotter {
public:
    struct State {
        double x = 0.0;
        double y = 0.0;
        Color color = 0;
    };

    /// set active color
    void setColor(Color color);
    /// set current 2d position
    void moveTo(double x, double y);
    /// line from current positionto givem and make new point as current
    void lineTo(double x, double y);
    /// plot circle with given radius with center at current position
    void circle(double radius);
    /// flood with selected color staring at current position
    void flood();

    /// relative line to - xy given relative to current position
    void relativeLineTo(double rx, double ry);

    const State& state() const;

protected:
    State m_state;

    // virtual intf

    virtual void doSetColor(Color color) {}
    virtual void doMoveTo(double x, double y) {}
    virtual void doLineTo(double x, double y) {}
    virtual void doCircle(double radius) {}
    virtual void doFlood() {}

};


} // plotter
} // shapes2d


#endif // SHAPES2D_PLOTTER_H
