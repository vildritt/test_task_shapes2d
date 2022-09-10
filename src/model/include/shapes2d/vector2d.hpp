#ifndef SHAPES2D_VECTOR_2D_H
#define SHAPES2D_VECTOR_2D_H
#pragma once


#include <shapes2d/export.h>


namespace shapes2d {


struct SHAPES2D_MODEL_EXPORT Point2D {
    double x = 0.0;
    double y = 0.0;

    Point2D(double x = 0.0, double y = 0.0);

    // defaults
    Point2D(Point2D&&) = default;
    Point2D(const Point2D&) = default;
    Point2D& operator=(Point2D&&) = default;
    Point2D& operator=(const Point2D&) = default;
    ~Point2D() = default;

    // operations
};


using Size2D = Point2D;


struct SHAPES2D_MODEL_EXPORT Rect2D {
    Point2D leftTop;
    Point2D rightBottom;

    Rect2D(const Point2D& lt = Point2D(), const Point2D& rb = Point2D());

    // defaults
    Rect2D(Rect2D&&) = default;
    Rect2D(const Rect2D&) = default;
    Rect2D& operator=(Rect2D&&) = default;
    Rect2D& operator=(const Rect2D&) = default;
    ~Rect2D() = default;

    // builders

    static Rect2D fromCenterAndSizes(const Point2D& center, const Point2D &size);

    double width() const;
    double height() const;

    Size2D size() const;
};


Point2D SHAPES2D_MODEL_EXPORT operator-(const Point2D& a, const Point2D& b);
Point2D SHAPES2D_MODEL_EXPORT operator+(const Point2D& a, const Point2D& b);
Point2D SHAPES2D_MODEL_EXPORT operator/(const Point2D& a, double b);
Point2D SHAPES2D_MODEL_EXPORT operator*(const Point2D& a, double b);


} // ns shapes2d


#endif // SHAPES2D_VECTOR_2D_H
