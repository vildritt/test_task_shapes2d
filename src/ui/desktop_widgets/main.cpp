#include <QApplication>

#include <shapes2d/model.hpp>
#include <shapes2d/gui/main_window.hpp>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    shapes2d::Model model;
    model.setSceneAutoComposer(shapes2d::SceneComposer::defaultComposer());

    shapes2d::gui::MainWindow window(&model);
    window.resize(800, 600); // TODO 1: use half screen size
    window.show();

    return QApplication::exec();
}
