#include "plot_area_widget.hpp"

#include <QPainter>

#include <shapes2d/model.hpp>


shapes2d::gui::PlotAreaWidget::PlotAreaWidget(Model *model, QWidget *parent)
    : QWidget(parent)
    , m_plotter(model)
{
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
}


void shapes2d::gui::PlotAreaWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    m_plotter.plot(&painter);
}
