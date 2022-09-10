#include <shapes2d/shape.hpp>

#include <shapes2d/plotter.hpp>


void shapes2d::Shape::plot(const plotter::PlotterPtr &plotter)
{
    plotter->setFgColor(m_fgColor);
    plotter->setBgColor(m_bgColor);
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


shapes2d::Color shapes2d::Shape::fgColor() const
{
    return m_fgColor;
}


shapes2d::Color shapes2d::Shape::bgColor() const
{
    return m_bgColor;
}


void shapes2d::Shape::setFgColor(Color color)
{
    m_fgColor = color;
}


void shapes2d::Shape::setBgColor(Color color)
{
    m_bgColor = color;
}


shapes2d::Shape::Shape()
{
    //
}


const shapes2d::shape::MetaInfo *shapes2d::Shape::meta() const
{
    return getMeta();
}
