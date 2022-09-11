#include "main_window_controller.hpp"

#include <shapes2d/shapes.hpp>


shapes2d::gui::MainWindowController::MainWindowController(Model *model, QQmlApplicationEngine* qmlEngine)
    : m_model(model)
{
    Q_ASSERT(model != nullptr && "model required");
    Q_ASSERT(qmlEngine != nullptr && "qml engine required");

    qmlEngine->rootContext()->setContextProperty("ctrl", this);
    qmlRegisterType<QuickPlotArea>("QuickPlotArea", 1, 0, "PlotArea");

    const QUrl url(u"qrc:shapes2d/main.qml"_qs);
    qmlEngine->load(url);

    const auto uiEngineRoots = qmlEngine->rootObjects();

    Q_ASSERT(!uiEngineRoots.empty() && "qml load failed");

    m_model->registerStatUpdateHandler([this](const shapes2d::shape::Identifier& id, int count) {
        emit statChanged();
    });

    auto* plotArea = uiEngineRoots.front()->findChild<QuickPlotArea*>();

    if (plotArea != nullptr) {
        plotArea->setup(m_model);
    }
    m_plotArea = plotArea;
}


void shapes2d::gui::MainWindowController::btnTriangleClicked(QQuickItem *sender)
{
    m_model->addShape<shapes2d::shapes::EquilateralTriangle>();
}


void shapes2d::gui::MainWindowController::btnCircleClicked(QQuickItem *sender)
{
    m_model->addShape<shapes2d::shapes::Circle>();
}


void shapes2d::gui::MainWindowController::btnSquareClicked(QQuickItem *sender)
{
    m_model->addShape<shapes2d::shapes::Square>();
}


void shapes2d::gui::MainWindowController::btnPlotClicked(QQuickItem *sender)
{
    makeAllShapesVisibleAndReplot();
}


void shapes2d::gui::MainWindowController::btnClearClicked(QQuickItem *sender)
{
    m_model->clearScene();
    makeAllShapesVisibleAndReplot();
}


void shapes2d::gui::MainWindowController::makeAllShapesVisibleAndReplot() const
{
    m_model->forEachShape([](const shapes2d::ShapePtr& shape) {
        shape->setVisible(true);
    });
    m_plotArea->update();
}


int shapes2d::gui::MainWindowController::getStatCircles() const
{
    //TODO 0: bad - hardcoded ids
    return m_model->shapesCount("shapes2d::shapes::Circle");
}


int shapes2d::gui::MainWindowController::getStatSquares() const
{
    return m_model->shapesCount("shapes2d::shapes::Square");
}


int shapes2d::gui::MainWindowController::getStatTriangles() const
{
    return m_model->shapesCount("shapes2d::shapes::EquilateralTriangle");
}
