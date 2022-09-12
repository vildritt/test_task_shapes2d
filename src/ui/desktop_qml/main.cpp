#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <shapes2d/model.hpp>

#include <shapes2d/gui/main_window_controller.hpp>


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    shapes2d::Model model;
    model.setSceneAutoComposer(shapes2d::SceneComposer::defaultComposer());

    QQmlApplicationEngine qmlEngine;
    shapes2d::gui::MainWindowController uiController(&model, &qmlEngine);

    return QGuiApplication::exec();
}
