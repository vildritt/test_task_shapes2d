#include "main_window.hpp"

#include <shapes2d/shapes_registry.hpp>
#include <shapes2d/shapes.hpp>

#include <QScreen>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSpacerItem>

#include <cassert>


shapes2d::gui::MainWindow::MainWindow(Model *model)
    : m_model(model)
{
    assert(model && "model required");

    createWidgets();

#if QT_VERSION >= QT_VERSION_CHECK(5,14,0)
    move(screen()->geometry().center() - frameGeometry().center());
#endif
}


void shapes2d::gui::MainWindow::createWidgets()
{
    auto* loMain = new QHBoxLayout(this);
    auto* loButtons = new QVBoxLayout(this);

    m_ui.graph = new PlotAreaWidget(m_model, this);

    auto* wgtButtons = new QWidget(this);

    auto* btnPlot = new QPushButton(this);
    auto* btnClear = new QPushButton(this);

    //

    btnPlot->setText(tr("Plot"));
    btnClear->setText(tr("Clear"));
    setWindowTitle(tr("Shapes2D"));

    //

    setCentralWidget(new QWidget(this));
    centralWidget()->setLayout(loMain);

    loMain->addWidget(m_ui.graph);
    loMain->addWidget(wgtButtons);

    wgtButtons->setLayout(loButtons);
    wgtButtons->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Minimum);

    {
        auto& regs = shapes2d::shape::Registry::instance();
        const auto metas = regs.allRegisteredShapes();
        for(const auto* meta : metas) {
            auto *wgt = new QWidget(this);
            auto *btn = new QPushButton(this);
            auto *lbl = new QLabel(this);

            wgt->setLayout(new QVBoxLayout(this));
            wgt->layout()->addWidget(btn);
            wgt->layout()->addWidget(lbl);


            btn->setText(translateShapeName(meta->id));
            lbl->setAlignment(Qt::AlignHCenter);

            connect(btn, &QPushButton::clicked, this, [this, meta](){
                m_model->addShape(meta->factory->create());
            });

            m_ui.lblStats[meta->id.c_str()] = lbl;

            loButtons->addWidget(wgt);

            uiUpdateStat(meta->id, 0);
        }
    }

    const int kSpacerSize_px = 20;
    loButtons->addItem(new QSpacerItem(kSpacerSize_px, kSpacerSize_px,
                                            QSizePolicy::Minimum,
                                            QSizePolicy::Expanding));
    loButtons->addWidget(btnPlot);
    loButtons->addWidget(btnClear);

    connect(btnPlot, &QPushButton::clicked, this, [this](){
        makeAllShapesVisibleAndReplot();
    });
    connect(btnClear, &QPushButton::clicked, this, [this](){
        m_model->clearScene();
        makeAllShapesVisibleAndReplot();
    });

    m_model->registerStatUpdateHandler([this](const shapes2d::shape::Identifier& id, int count) {
        uiUpdateStat(id, count);
    });
}


void shapes2d::gui::MainWindow::uiUpdateStat(const shape::Identifier &id, int count)
{
    auto it = m_ui.lblStats.find(id.c_str());
    if (it != m_ui.lblStats.end()) {
        it.value()->setText(tr("Count: %1").arg(count));
    }
}


void shapes2d::gui::MainWindow::makeAllShapesVisibleAndReplot() const
{
    m_model->forEachShape([](const shapes2d::ShapePtr& shape) {
        shape->setVisible(true);
    });
    m_ui.graph->update();
}


QString shapes2d::gui::MainWindow::translateShapeName(const shape::Identifier &id)
{

    //TODO 1: rethink. Bad solution because:
    //  - manual listing for all available shapes
    //  - use of macro
    //  - shapes classes not checked for existence (used as strings)

    // NOET: here is check for class existence present - better than nothing...
#define REGISTER_SHAPE_TR(ClassName, TrName) \
    do { \
        assert(sizeof(ClassName) > 0); \
        reg(#ClassName, TrName); \
    } while(0)

    if (m_trShapesNames.empty()) {
        auto reg = [this](const shape::Identifier &id, const QString& translated) {
            m_trShapesNames[id.c_str()] = translated;
        };

        REGISTER_SHAPE_TR(shapes2d::shapes::Circle, tr("Circle"));
        REGISTER_SHAPE_TR(shapes2d::shapes::Square, tr("Square"));
        REGISTER_SHAPE_TR(shapes2d::shapes::Triangle, tr("Triangle"));
    }

    const auto it = m_trShapesNames.find(id.c_str());
    if (it != m_trShapesNames.end()) {
        return it.value();
    }
    return id.c_str();
}
