#include "quick_plot_area.hpp"


shapes2d::gui::QuickPlotArea::QuickPlotArea(QQuickItem *parent)
    : QQuickPaintedItem(parent)
{
}


void shapes2d::gui::QuickPlotArea::setup(Model *model)
{
    m_plotter.setModel(model);
}


void shapes2d::gui::QuickPlotArea::paint(QPainter *painter)
{
    painter->setRenderHint(QPainter::Antialiasing, true);

    m_plotter.plot(painter);
}
