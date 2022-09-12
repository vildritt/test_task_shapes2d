#ifndef SHAPES2D_GUI_MAIN_WINDOWS_H
#define SHAPES2D_GUI_MAIN_WINDOWS_H
#pragma once

#include <QMainWindow>
#include <QLabel>
#include <QString>
#include <QHash>


#include <shapes2d/model.hpp>
#include <shapes2d/gui/plot_area_widget.hpp>


namespace shapes2d {
namespace gui {


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(shapes2d::Model* model);

private:
    shapes2d::Model* m_model = nullptr;

    struct Ui {
        QWidget* graph = nullptr;
        QHash<QString, QLabel*> lblStats;
    } m_ui;
    QHash<QString, QString> m_trShapesNames;

    ///

    void createWidgets();
    void makeAllShapesVisibleAndReplot() const;
    QString translateShapeName(const shape::Identifier &id);
    void uiUpdateStat(const shape::Identifier &id, int count);
};


}} // ns shapes2d::gui


#endif // SHAPES2D_GUI_MAIN_WINDOWS_H
