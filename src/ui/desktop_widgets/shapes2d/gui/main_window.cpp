#include "main_window.hpp"

#include <shapes2d/shapes_registry.hpp>
#include <shapes2d/shapes.hpp>

#include <QScreen>


shapes2d::gui::MainWindow::MainWindow(Model *model)
    : m_model(model)
{
    createWidgets();
#if QT_VERSION >= QT_VERSION_CHECK(5,14,0)
    move(screen()->geometry().center() - frameGeometry().center());
#endif
}


void shapes2d::gui::MainWindow::createWidgets()
{
    m_ui.loMain = new QHBoxLayout(this);
    m_ui.loButtons = new QVBoxLayout(this);

    m_ui.graph = new PlotAreaWidget(m_model, this);

    m_ui.wgtButtons = new QWidget(this);

    m_ui.btnPlot = new QPushButton(this);
    m_ui.btnClear = new QPushButton(this);

    //

    m_ui.btnPlot->setText(tr("Plot"));
    m_ui.btnClear->setText(tr("Clear"));
    setWindowTitle(tr("Shapes2D"));

    //

    setCentralWidget(new QWidget(this));
    centralWidget()->setLayout(m_ui.loMain);

    m_ui.loMain->addWidget(m_ui.graph);
    m_ui.loMain->addWidget(m_ui.wgtButtons);

    m_ui.wgtButtons->setLayout(m_ui.loButtons);
    m_ui.wgtButtons->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Minimum);

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
            lbl->setText("0");

            connect(btn, &QPushButton::clicked, this, [this, meta](){
                m_model->addShape(meta->factory->create());
            });

            m_ui.lblStats[meta->id.c_str()] = lbl;

            m_ui.loButtons->addWidget(wgt);
        }
    }

    const int kSpacerSize_px = 20;
    m_ui.loButtons->addItem(new QSpacerItem(kSpacerSize_px, kSpacerSize_px,
                                            QSizePolicy::Minimum,
                                            QSizePolicy::Expanding));
    m_ui.loButtons->addWidget(m_ui.btnPlot);
    m_ui.loButtons->addWidget(m_ui.btnClear);

    connect(m_ui.btnPlot, &QPushButton::clicked, this, [this](){
        makeAllShapesVisibleAndReplot();
    });
    connect(m_ui.btnClear, &QPushButton::clicked, this, [this](){
        m_model->clearScene();
        makeAllShapesVisibleAndReplot();
    });

    m_model->registerStatUpdateHandler([this](const shapes2d::shape::RegistryIdentifier& id, int count) {
        auto it = m_ui.lblStats.find(id.c_str());
        if (it != m_ui.lblStats.end()) {
            it.value()->setText(QString("%1").arg(count));
        }
    });

}


void shapes2d::gui::MainWindow::makeAllShapesVisibleAndReplot() const
{
    m_model->forEachShape([](const shapes2d::ShapePtr& shape) {
        shape->setVisible(true);
    });
    m_ui.graph->update();
}


QString shapes2d::gui::MainWindow::translateShapeName(const shape::RegistryIdentifier &id)
{

    //TODO 1: rethink. Bad solution because:
    //  - manual listing for all available shapes
    //  - use of macro
    //  - shapes classes not checked for existence (used as strings)

    // NOET: here is check for class existence present - better than nothing...
#define REGISTER_SHAPE_TR(ClassName, TrName) \
    do { \
        assert(sizeof(ClassName) > 0); \
        reg(#ClassName, tr(TrName)); \
    } while(0)

    if (m_trShapesNames.empty()) {
        auto reg = [this](const shape::RegistryIdentifier &id, const QString& translated) {
            m_trShapesNames[id.c_str()] = translated;
        };

        REGISTER_SHAPE_TR(shapes2d::shapes::Circle, "Circle");
        REGISTER_SHAPE_TR(shapes2d::shapes::Rectangle, "Rectrange");
        REGISTER_SHAPE_TR(shapes2d::shapes::EquilateralTriangle, "Triangle");
    }

    const auto it = m_trShapesNames.find(id.c_str());
    if (it != m_trShapesNames.end()) {
        return it.value();
    }
    return id.c_str();
}
