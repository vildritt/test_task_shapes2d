#include <shapes2d/vector2d.hpp>


shapes2d::Point2D::Point2D(double x, double y)
    : x(x), y(y)
{}


shapes2d::Rect2D::Rect2D(const Point2D &lt, const Point2D &rb)
    : leftTop(lt), rightBottom(rb)
{
}


shapes2d::Rect2D shapes2d::Rect2D::fromCenterAndSizes(const Point2D &center, const Point2D &size)
{
    const auto halfSize = size / 2.0;
    return Rect2D(center - halfSize, center + halfSize);
}


double shapes2d::Rect2D::width() const
{
    return rightBottom.x - leftTop.x;
}


double shapes2d::Rect2D::height() const
{
    return rightBottom.y - leftTop.y;
}


shapes2d::Size2D shapes2d::Rect2D::size() const
{
    return Size2D(width(), height());
}


shapes2d::Point2D shapes2d::operator+(const Point2D &a, const Point2D &b)
{
    return {a.x + b.x, a.y + b.y};
}


shapes2d::Point2D shapes2d::operator-(const Point2D &a, const Point2D &b)
{
    return {a.x - b.x, a.y - b.y};
}


shapes2d::Point2D shapes2d::operator/(const Point2D &a, double b)
{
    return {a.x / b, a.y / b};
}


shapes2d::Point2D shapes2d::operator*(const Point2D &a, double b)
{
    return {a.x * b, a.y * b};
}


shapes2d::PolygonBuilder::PolygonBuilder(size_t pointCountEst)
{
    if (pointCountEst > 0) {
        points.reserve(pointCountEst);
    }
}


void shapes2d::PolygonBuilder::addAbs(const Point2D &pt)
{
    points.push_back(pt);
}


void shapes2d::PolygonBuilder::addRel(const Vector2D &v)
{
    points.push_back(points.back() + v);
}
