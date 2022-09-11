#ifndef SHAPES2D_GUI_QT_HELPER_PAINTER_PLOTTER_H
#define SHAPES2D_GUI_QT_HELPER_PAINTER_PLOTTER_H
#pragma once

#include <QPainter>

#include <shapes2d/model_ptr.hpp>
#include <shapes2d/plotter.hpp>


namespace shapes2d {
namespace gui {
namespace qt {


class PainterPlotter : public shapes2d::Plotter {
public:

    void setPainter(QPainter* painter);

protected:

    void doSetForegroundColor(shapes2d::Color color) override;
    void doSetBackgroundColor(shapes2d::Color color) override;
    void doLineTo(const shapes2d::Point2D& pt) override;
    void doCircle(double radius) override;
    void doPolygon(const std::vector<shapes2d::Point2D>& points) override;
    Size2D doGetCanvasSize() const override;

private:
    QPen m_pen;
    QBrush m_brush;
    QPainter* m_painter = nullptr;
};


class PainterPlotterHelper
{
public:

    PainterPlotterHelper(shapes2d::Model* model = nullptr);

    void plot(QPainter* painter);
    void setModel(shapes2d::Model* model);

private:

    shapes2d::Model* m_model = nullptr;
    shapes2d::PlotterPtr m_plotter;
    PainterPlotter *m_painterPlotter = nullptr;
};


}}} // ns shapes2d::gui::qt


#endif // SHAPES2D_GUI_QT_HELPER_PAINTER_PLOTTER_H
