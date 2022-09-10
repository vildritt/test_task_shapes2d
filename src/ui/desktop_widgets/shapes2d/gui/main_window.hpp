#ifndef SHAPES2D_GUI_MAIN_WINDOWS_H
#define SHAPES2D_GUI_MAIN_WINDOWS_H
#pragma once


#include <QMainWindow>
#include <QWindow>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGraphicsScene>
#include <QSpacerItem>
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

public slots:

private:
    shapes2d::Model* m_model = nullptr;

    struct Ui {
        QHBoxLayout* loMain = nullptr;
        QVBoxLayout* loButtons = nullptr;

        QWidget* graph = nullptr;

        QWidget* wgtButtons = nullptr;

        QPushButton* btnPlot = nullptr;
        QPushButton* btnClear = nullptr;

        QHash<QString, QLabel*> lblStats;
    } m_ui;
    QHash<QString, QString> m_trShapesNames;

    ///

    void createWidgets();
    void makeAllShapesVisibleAndReplot() const;
    QString translateShapeName(const shape::RegistryIdentifier &id);
};


}} // ns shapes2d::gui


#endif // SHAPES2D_GUI_MAIN_WINDOWS_H
