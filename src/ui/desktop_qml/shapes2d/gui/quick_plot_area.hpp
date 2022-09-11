#ifndef SHAPES2D_GUI_QUICK_PLOT_AREA_H
#define SHAPES2D_GUI_QUICK_PLOT_AREA_H
#pragma once

#include <QQuickPaintedItem>

#include <shapes2d/gui/qt_helper/painter_plotter.hpp>


namespace shapes2d {
namespace gui {


class QuickPlotArea : public QQuickPaintedItem
{
    //QML_ELEMENT

public:
    QuickPlotArea(QQuickItem *parent = nullptr);

    void setup(shapes2d::Model* model);

    void paint(QPainter *painter) override;

private:
    shapes2d::gui::qt::PainterPlotterHelper m_plotter;
};


}} // ns gui::shapes2d


#endif // SHAPES2D_GUI_QUICK_PLOT_AREA_H
