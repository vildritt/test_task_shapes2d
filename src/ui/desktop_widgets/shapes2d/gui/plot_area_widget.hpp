#ifndef SHAPES2D_GUI_PLOT_AREA_WIDGET_H
#define SHAPES2D_GUI_PLOT_AREA_WIDGET_H
#pragma once

#include <QWidget>

#include <shapes2d/model_ptr.hpp>
#include <shapes2d/plotter.hpp>


namespace shapes2d {
namespace gui {


class WidgetPlotter;


class PlotAreaWidget : public QWidget
{
    Q_OBJECT

public:

    explicit PlotAreaWidget(shapes2d::Model* model, QWidget *parent = nullptr);

protected:

    void paintEvent(QPaintEvent *event) override;

private:
    shapes2d::Model* m_model = nullptr;

    shapes2d::PlotterPtr m_plotter;
    shapes2d::gui::WidgetPlotter *m_widgetPlotter = nullptr;
};


}} // ns shapes2d::gui


#endif // SHAPES2D_GUI_PLOT_AREA_WIDGET_H
