#include <QTest>

#include <shapes2d/model.hpp>
#include <shapes2d/shapes.hpp>
#include <shapes2d/plotter.hpp>
#include <shapes2d/shapes_registry.hpp>


class TestPlotter : public shapes2d::plotter::Plotter {
public:
    int nCircles = 0;
    int nFloods = 0;
    int nLines = 0;
    int nMoves = 0;
    int nColorChanges = 0;
protected:
    void doSetColor(shapes2d::plotter::Color color) override
    {
        ++nColorChanges;
    }

    void doMoveTo(double x, double y) override
    {
        ++nMoves;
    }

    void doLineTo(double x, double y) override
    {
        ++nLines;
    }

    void doCircle(double radius) override
    {
        ++nCircles;
    }

    void doFlood() override
    {
        ++nFloods;
    }
};


class TestModelSimpleOperations : public QObject
{
    Q_OBJECT

private slots:

    void registry()
    {
        auto& rs = shapes2d::shape::Registry::instance();
        const auto& shapesMetas = rs.allRegisteredShapes();
        QVERIFY(shapesMetas.size() >= 3);
        for(const auto* shapeMeta : shapesMetas) {
            auto shape = shapeMeta->factory->create();
            QVERIFY(shape.get() != nullptr);
            QVERIFY(shape->meta() == shapeMeta);
        }
    }

    void createAndFillModelCheckCounters()
    {
        shapes2d::Model model;

        model.clearScene();
        model.addShape<shapes2d::shapes::Circle>();
        model.addShape<shapes2d::shapes::Circle>();
        model.addShape<shapes2d::shapes::EquilateralTriangle>();

        QVERIFY(model.shapesCount("shapes2d::shapes::Circle") == 2);
        QVERIFY(model.shapesCount("shapes2d::shapes::EquilateralTriangle") == 1);
        QVERIFY(model.shapesCount("shapes2d::shapes::rectangle") == 0);
    }

    void plotSimpleScene()
    {
        shapes2d::plotter::PlotterPtr plotter = std::make_shared<TestPlotter>();
        shapes2d::Model model;

        model.clearScene();
        model.addShape<shapes2d::shapes::Circle>();
        model.addShape<shapes2d::shapes::Circle>();
        model.addShape<shapes2d::shapes::EquilateralTriangle>();
        model.addShape<shapes2d::shapes::Rectangle>();
        model.plotScene(plotter);

        auto* testPlotter = dynamic_cast<TestPlotter*>(plotter.get());

        QVERIFY(testPlotter->nCircles == 2);
        QVERIFY(testPlotter->nLines == (4 + 3));
    }

};


QTEST_MAIN(TestModelSimpleOperations)
#include "test_model_simple_operations.moc"
