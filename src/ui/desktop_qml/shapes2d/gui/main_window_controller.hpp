#ifndef SHAPES2D_GUI_MAIN_WINDOW_CONTROLLER_H
#define SHAPES2D_GUI_MAIN_WINDOW_CONTROLLER_H

#include <QObject>
#include <QtQuick>

#include <shapes2d/model.hpp>
#include <shapes2d/gui/quick_plot_area.hpp>


namespace shapes2d {
namespace gui {

/**
 * @brief View controller, connect QML entity with model
 */
class MainWindowController : public QObject {
    Q_OBJECT

    shapes2d::Model* m_model = nullptr;
    QQuickItem *m_plotArea = nullptr;

public:

    MainWindowController(shapes2d::Model* model, QQmlApplicationEngine* qmlEngine);

public slots:

    void btnTriangleClicked(QQuickItem* sender);
    void btnCircleClicked(QQuickItem* sender);
    void btnRectangleClicked(QQuickItem* sender);
    void btnPlotClicked(QQuickItem* sender);
    void btnClearClicked(QQuickItem* sender);

private:
    void makeAllShapesVisibleAndReplot() const;

    Q_PROPERTY(int statCircles READ getStatCircles NOTIFY statChanged)
    Q_PROPERTY(int statRectangles READ getStatRectangles NOTIFY statChanged)
    Q_PROPERTY(int statTriangles READ getStatTriangles NOTIFY statChanged)
public:
    int getStatCircles() const;
    int getStatRectangles() const;
    int getStatTriangles() const;
signals:
    void statChanged();
};


} // ns gui
} // ns shapes2d


#endif  // SHAPES2D_GUI_MAIN_WINDOW_CONTROLLER_H
