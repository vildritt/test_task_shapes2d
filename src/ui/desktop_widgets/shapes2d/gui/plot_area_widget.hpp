#ifndef SHAPES2D_GUI_PLOT_AREA_WIDGET_H
#define SHAPES2D_GUI_PLOT_AREA_WIDGET_H
#pragma once

#include <QWidget>

#include <shapes2d/model_ptr.hpp>
#include <shapes2d/plotter.hpp>

#include <shapes2d/gui/qt_helper/painter_plotter.hpp>


namespace shapes2d {
namespace gui {


class PlotAreaWidget : public QWidget
{
    Q_OBJECT

public:

    explicit PlotAreaWidget(shapes2d::Model* model, QWidget *parent = nullptr);

protected:

    void paintEvent(QPaintEvent *event) override;

private:
    shapes2d::gui::qt::PainterPlotterHelper m_plotter;
};


}} // ns shapes2d::gui


#endif // SHAPES2D_GUI_PLOT_AREA_WIDGET_H
