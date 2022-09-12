#include <shapes2d/shape.hpp>

#include <shapes2d/plotter.hpp>


void shapes2d::Shape::plot(const PlotterPtr &plotter)
{
    plotter->setForegroundColor(m_foregroundColor);
    plotter->setBackgroundColor(m_backgroundColor);
    doPlot(plotter);
}


shapes2d::Rect2D shapes2d::Shape::boundingRect() const
{
    return doGetBoundingRect();
}


bool shapes2d::Shape::isVisible() const
{
    return m_visible;
}


void shapes2d::Shape::setVisible(bool visible)
{
    m_visible = visible;
}


void shapes2d::Shape::setPosition(const Point2D &position)
{
    m_position = position;
}


const shapes2d::Point2D &shapes2d::Shape::position() const
{
    return m_position;
}


shapes2d::Color shapes2d::Shape::foregroundColor() const
{
    return m_foregroundColor;
}


shapes2d::Color shapes2d::Shape::backgroundColor() const
{
    return m_backgroundColor;
}


void shapes2d::Shape::setForegroundColor(Color color)
{
    m_foregroundColor = color;
}


void shapes2d::Shape::setBackgroundColor(Color color)
{
    m_backgroundColor = color;
}


shapes2d::Shape::Shape()
{
    //
}


const shapes2d::shape::MetaInfo *shapes2d::Shape::meta() const
{
    return getMeta();
}
