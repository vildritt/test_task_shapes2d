#include <stdlib.h>
#include <iostream>

#include <shapes2d/model.hpp>
#include <shapes2d/shapes.hpp>
#include <shapes2d/plotter.hpp>


class TestPlotter : public shapes2d::plotter::Plotter {
protected:
    void doSetColor(shapes2d::plotter::Color color) override
    {
        std::cout << "color = " << color << std::endl;
    }
    void doMoveTo(double x, double y) override
    {
        std::cout << "move to " << x << "," << y << std::endl;
    }

    void doLineTo(double x, double y) override
    {
        std::cout << "line to " << x << "," << y << std::endl;
    }

    void doCircle(double radius) override
    {
        const auto& s = state();
        std::cout << "circle at " << s.x << "," << s.y << " r = " << radius << std::endl;
    }

    void doFlood() override
    {
        const auto& s = state();
        std::cout << "flood at " << s.x << "," << s.y << std::endl;
    }
};


int main(int argc, char* argv[])
{
    shapes2d::plotter::PlotterPtr plotter = std::make_shared<TestPlotter>();
    shapes2d::Model model;

    // TODO 0: move to tests!
    model.clear();
    model.addShape<shapes2d::shapes::Circle>();
    model.addShape<shapes2d::shapes::Circle>();
    model.addShape<shapes2d::shapes::EquilateralTriangle>();
    model.addShape<shapes2d::shapes::Rectangle>();
    model.plot(plotter);

    return EXIT_SUCCESS;
}
