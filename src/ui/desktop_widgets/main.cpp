#include <QApplication>

#include <shapes2d/model.hpp>
#include <shapes2d/gui/main_window.hpp>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    shapes2d::Model model;
    model.setAutoComposer(shapes2d::SceneComposer::defaultComposer());
    shapes2d::gui::MainWindow window(&model);
    window.resize(800, 600);
    window.show();

    return QApplication::exec();
}
