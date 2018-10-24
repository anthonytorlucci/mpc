#include "view01mineraldata.h"


#include <QMessageBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QComboBox>
#include <QLabel>
#include <QLineEdit>
#include <QGridLayout>
#include <QString>



View01MineralData::View01MineralData(QWidget *parent) : QWidget(parent)
{
    // based on qt data visualization example:
    //     http://doc.qt.io/qt-5/qtdatavisualization-bars-example.html
    bar_graph = new Q3DBars();
    QWidget *container = QWidget::createWindowContainer(bar_graph);
    /* NOTE: The call to QWidget::createWindowContainer is required, as all
     * data visualization graph classes (Q3DBars, Q3DScatter, Q3DSurface)
     * inherit QWindow. Any class inheriting QWindow cannot be used as a
     * widget any other way.
     */

    if (!bar_graph->hasContext()) {
        QMessageBox msgBox;
        msgBox.setText("Couldn't initialize the OpenGL context.");
        msgBox.exec();
        //return -1;
    }

    QSize screenSize = bar_graph->screen()->size();
    container->setMinimumSize(QSize(screenSize.width() / 2, screenSize.height() / 1.5));
    container->setMaximumSize(screenSize);
    container->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    container->setFocusPolicy(Qt::StrongFocus);

    QWidget *widget = new QWidget;
    QHBoxLayout *hLayout = new QHBoxLayout(widget);
    QVBoxLayout *vLayout = new QVBoxLayout();
    hLayout->addWidget(container, 1);
    hLayout->addLayout(vLayout);

    widget->setWindowTitle(QStringLiteral("Mineral Data"));

    QComboBox *mineral_combo_box = new QComboBox(widget);
    mineral_combo_box->addItem(QStringLiteral("Augite"));
    mineral_combo_box->addItem(QStringLiteral("Albite"));
    mineral_combo_box->addItem(QStringLiteral("Anorthite"));
    mineral_combo_box->addItem(QStringLiteral("Labradorite"));
    mineral_combo_box->addItem(QStringLiteral("Microcline"));
    mineral_combo_box->addItem(QStringLiteral("Oligoclase"));
    mineral_combo_box->addItem(QStringLiteral("Coesite"));
    mineral_combo_box->addItem(QStringLiteral("Epidote"));
    mineral_combo_box->addItem(QStringLiteral("Hornblende"));
    mineral_combo_box->addItem(QStringLiteral("Muscovite"));
    mineral_combo_box->addItem(QStringLiteral("Gypsum"));
    mineral_combo_box->addItem(QStringLiteral("Enstatite"));
    mineral_combo_box->addItem(QStringLiteral("Forsterite"));
    mineral_combo_box->addItem(QStringLiteral("Fayalite"));
    mineral_combo_box->addItem(QStringLiteral("Montecellite"));
    mineral_combo_box->addItem(QStringLiteral("Andalusite"));
    mineral_combo_box->addItem(QStringLiteral("Silimanite"));
    mineral_combo_box->addItem(QStringLiteral("Barite"));
    mineral_combo_box->addItem(QStringLiteral("Anhydrite"));
    mineral_combo_box->addItem(QStringLiteral("Dolomite"));
    mineral_combo_box->addItem(QStringLiteral("Rutile"));
    mineral_combo_box->addItem(QStringLiteral("Zircon"));
    mineral_combo_box->addItem(QStringLiteral("Corundum"));
    mineral_combo_box->addItem(QStringLiteral("Calcite"));
    mineral_combo_box->addItem(QStringLiteral("Quartz"));
    mineral_combo_box->addItem(QStringLiteral("Tourmaline"));
    mineral_combo_box->addItem(QStringLiteral("Beryl"));
    mineral_combo_box->addItem(QStringLiteral("Graphite"));
    mineral_combo_box->addItem(QStringLiteral("Wusite"));
    mineral_combo_box->addItem(QStringLiteral("Manganosite"));
    mineral_combo_box->addItem(QStringLiteral("Periclase"));
    mineral_combo_box->addItem(QStringLiteral("Magnetite"));
    mineral_combo_box->addItem(QStringLiteral("Chromite"));
    mineral_combo_box->addItem(QStringLiteral("Spinel"));
    mineral_combo_box->addItem(QStringLiteral("Pyrite"));
    mineral_combo_box->addItem(QStringLiteral("Galena"));
    mineral_combo_box->addItem(QStringLiteral("Sphalerite"));
    mineral_combo_box->addItem(QStringLiteral("Fluorite"));
    mineral_combo_box->addItem(QStringLiteral("Halite"));
    mineral_combo_box->addItem(QStringLiteral("Sylvite"));
    mineral_combo_box->setCurrentIndex(0);

    QWidget* mineral_properties_widget = new QWidget();
    QLabel* density_label = new QLabel("density (g/cm**3)");
    density_line_edit = new QLineEdit();
    density_line_edit->setText(QString::number(mpc::data::AugiteDensity<double>()));
    density_line_edit->setReadOnly(true);
    QLabel* bulk_modulus_label = new QLabel("bulk_modulus (GPa)");
    bulk_modulus_line_edit = new QLineEdit();
    bulk_modulus_line_edit->setText(QString::number(mpc::data::AugiteBulkModulus<double>()));
    bulk_modulus_line_edit->setReadOnly(true);
    QLabel* shear_modulus_label = new QLabel("shear_modulus (GPa)");
    shear_modulus_line_edit = new QLineEdit();
    shear_modulus_line_edit->setText(QString::number(mpc::data::AugiteShearModulus<double>()));
    shear_modulus_line_edit->setReadOnly(true);
    QLabel* c11_label = new QLabel("C11 (GPa)");
    c11_line_edit = new QLineEdit();
    c11_line_edit->setText(QString::number(mpc::data::AugiteC11<double>()));
    c11_line_edit->setReadOnly(true);
    QLabel* c12_label = new QLabel("C12 (GPa)");
    c12_line_edit = new QLineEdit();
    c12_line_edit->setText(QString::number(mpc::data::AugiteC12<double>()));
    c12_line_edit->setReadOnly(true);
    QLabel* c13_label = new QLabel("C13 (GPa)");
    c13_line_edit = new QLineEdit();
    c13_line_edit->setText(QString::number(mpc::data::AugiteC13<double>()));
    c13_line_edit->setReadOnly(true);
    QLabel* c14_label = new QLabel("C14 (GPa)");
    c14_line_edit = new QLineEdit();
    c14_line_edit->setText(QString::number(mpc::data::AugiteC14<double>()));
    c14_line_edit->setReadOnly(true);
    QLabel* c15_label = new QLabel("C15 (GPa)");
    c15_line_edit = new QLineEdit();
    c15_line_edit->setText(QString::number(mpc::data::AugiteC15<double>()));
    c15_line_edit->setReadOnly(true);
    QLabel* c16_label = new QLabel("C16 (GPa)");
    c16_line_edit = new QLineEdit();
    c16_line_edit->setText(QString::number(mpc::data::AugiteC16<double>()));
    c16_line_edit->setReadOnly(true);
    QLabel* c22_label = new QLabel("C22 (GPa)");
    c22_line_edit = new QLineEdit();
    c22_line_edit->setText(QString::number(mpc::data::AugiteC22<double>()));
    c22_line_edit->setReadOnly(true);
    QLabel* c23_label = new QLabel("C23 (GPa)");
    c23_line_edit = new QLineEdit();
    c23_line_edit->setText(QString::number(mpc::data::AugiteC23<double>()));
    c23_line_edit->setReadOnly(true);
    QLabel* c24_label = new QLabel("C24 (GPa)");
    c24_line_edit = new QLineEdit();
    c24_line_edit->setText(QString::number(mpc::data::AugiteC24<double>()));
    c24_line_edit->setReadOnly(true);
    QLabel* c25_label = new QLabel("C25 (GPa)");
    c25_line_edit = new QLineEdit();
    c25_line_edit->setText(QString::number(mpc::data::AugiteC25<double>()));
    c25_line_edit->setReadOnly(true);
    QLabel* c26_label = new QLabel("C26 (GPa)");
    c26_line_edit = new QLineEdit();
    c26_line_edit->setText(QString::number(mpc::data::AugiteC26<double>()));
    c26_line_edit->setReadOnly(true);
    QLabel* c33_label = new QLabel("C33 (GPa)");
    c33_line_edit = new QLineEdit();
    c33_line_edit->setText(QString::number(mpc::data::AugiteC33<double>()));
    c33_line_edit->setReadOnly(true);
    QLabel* c34_label = new QLabel("C34 (GPa)");
    c34_line_edit = new QLineEdit();
    c34_line_edit->setText(QString::number(mpc::data::AugiteC34<double>()));
    c34_line_edit->setReadOnly(true);
    QLabel* c35_label = new QLabel("C35 (GPa)");
    c35_line_edit = new QLineEdit();
    c35_line_edit->setText(QString::number(mpc::data::AugiteC35<double>()));
    c35_line_edit->setReadOnly(true);
    QLabel* c36_label = new QLabel("C36 (GPa)");
    c36_line_edit = new QLineEdit();
    c36_line_edit->setText(QString::number(mpc::data::AugiteC36<double>()));
    c36_line_edit->setReadOnly(true);
    QLabel* c44_label = new QLabel("C44 (GPa)");
    c44_line_edit = new QLineEdit();
    c44_line_edit->setText(QString::number(mpc::data::AugiteC44<double>()));
    c44_line_edit->setReadOnly(true);
    QLabel* c45_label = new QLabel("C45 (GPa)");
    c45_line_edit = new QLineEdit();
    c45_line_edit->setText(QString::number(mpc::data::AugiteC45<double>()));
    c45_line_edit->setReadOnly(true);
    QLabel* c46_label = new QLabel("C46 (GPa)");
    c46_line_edit = new QLineEdit();
    c46_line_edit->setText(QString::number(mpc::data::AugiteC46<double>()));
    c46_line_edit->setReadOnly(true);
    QLabel* c55_label = new QLabel("C55 (GPa)");
    c55_line_edit = new QLineEdit();
    c55_line_edit->setText(QString::number(mpc::data::AugiteC55<double>()));
    c55_line_edit->setReadOnly(true);
    QLabel* c56_label = new QLabel("C56 (GPa)");
    c56_line_edit = new QLineEdit();
    c56_line_edit->setText(QString::number(mpc::data::AugiteC56<double>()));
    c56_line_edit->setReadOnly(true);
    QLabel* c66_label = new QLabel("C66 (GPa)");
    c66_line_edit = new QLineEdit();
    c66_line_edit->setText(QString::number(mpc::data::AugiteC66<double>()));
    c66_line_edit->setReadOnly(true);
    QGridLayout* grid_layout = new QGridLayout();
    // addWidget(*Widget, row, column, rowspan, colspan)
    grid_layout->addWidget(density_label, 0, 0, 1, 1);
    grid_layout->addWidget(density_line_edit, 0, 1, 1, 1);
    grid_layout->addWidget(bulk_modulus_label, 1, 0, 1, 1);
    grid_layout->addWidget(bulk_modulus_line_edit, 1, 1, 1, 1);
    grid_layout->addWidget(shear_modulus_label, 2, 0, 1, 1);
    grid_layout->addWidget(shear_modulus_line_edit, 2, 1, 1, 1);
    grid_layout->addWidget(c11_label, 3, 0, 1, 1);
    grid_layout->addWidget(c11_line_edit, 3, 1, 1, 1);
    grid_layout->addWidget(c12_label, 4, 0, 1, 1);
    grid_layout->addWidget(c12_line_edit, 4, 1, 1, 1);
    grid_layout->addWidget(c13_label, 5, 0, 1, 1);
    grid_layout->addWidget(c13_line_edit, 5, 1, 1, 1);
    grid_layout->addWidget(c14_label, 6, 0, 1, 1);
    grid_layout->addWidget(c14_line_edit, 6, 1, 1, 1);
    grid_layout->addWidget(c15_label, 7, 0, 1, 1);
    grid_layout->addWidget(c15_line_edit, 7, 1, 1, 1);
    grid_layout->addWidget(c16_label, 8, 0, 1, 1);
    grid_layout->addWidget(c16_line_edit, 8, 1, 1, 1);
    grid_layout->addWidget(c22_label, 9, 0, 1, 1);
    grid_layout->addWidget(c22_line_edit, 9, 1, 1, 1);
    grid_layout->addWidget(c23_label, 10, 0, 1, 1);
    grid_layout->addWidget(c23_line_edit, 10, 1, 1, 1);
    grid_layout->addWidget(c24_label, 11, 0, 1, 1);
    grid_layout->addWidget(c24_line_edit, 11, 1, 1, 1);
    grid_layout->addWidget(c25_label, 12, 0, 1, 1);
    grid_layout->addWidget(c25_line_edit, 12, 1, 1, 1);
    grid_layout->addWidget(c26_label, 13, 0, 1, 1);
    grid_layout->addWidget(c26_line_edit, 13, 1, 1, 1);
    grid_layout->addWidget(c33_label, 14, 0, 1, 1);
    grid_layout->addWidget(c33_line_edit, 14, 1, 1, 1);
    grid_layout->addWidget(c34_label, 15, 0, 1, 1);
    grid_layout->addWidget(c34_line_edit, 15, 1, 1, 1);
    grid_layout->addWidget(c35_label, 16, 0, 1, 1);
    grid_layout->addWidget(c35_line_edit, 16, 1, 1, 1);
    grid_layout->addWidget(c36_label, 17, 0, 1, 1);
    grid_layout->addWidget(c36_line_edit, 17, 1, 1, 1);
    grid_layout->addWidget(c44_label, 18, 0, 1, 1);
    grid_layout->addWidget(c44_line_edit, 18, 1, 1, 1);
    grid_layout->addWidget(c45_label, 19, 0, 1, 1);
    grid_layout->addWidget(c45_line_edit, 19, 1, 1, 1);
    grid_layout->addWidget(c46_label, 20, 0, 1, 1);
    grid_layout->addWidget(c46_line_edit, 20, 1, 1, 1);
    grid_layout->addWidget(c55_label, 21, 0, 1, 1);
    grid_layout->addWidget(c55_line_edit, 21, 1, 1, 1);
    grid_layout->addWidget(c56_label, 22, 0, 1, 1);
    grid_layout->addWidget(c56_line_edit, 22, 1, 1, 1);
    grid_layout->addWidget(c66_label, 23, 0, 1, 1);
    grid_layout->addWidget(c66_line_edit, 23, 1, 1, 1);

    mineral_properties_widget->setLayout(grid_layout);

    vLayout->addWidget(mineral_combo_box);
    vLayout->addWidget(mineral_properties_widget);
    vLayout->addStretch();

    // bar graph
    cijkl_value_axis = new QValue3DAxis();
    cijkl_value_axis->setTitle("Average temperature");
    //cijkl_value_axis->setSegmentCount(5);
    //cijkl_value_axis->setSubSegmentCount(1);
    //cijkl_value_axis->setRange(m_minval, m_maxval);
    cijkl_value_axis->setLabelFormat(QString(QStringLiteral("%.2f ") + " (GPa)"));
    cijkl_value_axis->setLabelAutoRotation(30.0f);
    cijkl_value_axis->setTitleVisible(true);

    ij_list << "11" << "12" << "13" << "21" << "22" << "23" << "31" << "32" << "33";

    ij_axis = new QCategory3DAxis();
    ij_axis->setTitle("ij indices");
    ij_axis->setLabelAutoRotation(30.0f);
    ij_axis->setTitleVisible(true);

    kl_axis = new QCategory3DAxis();
    kl_axis->setTitle("kl indices");
    kl_axis->setLabelAutoRotation(30.0f);
    kl_axis->setTitleVisible(true);

    bar_graph->setValueAxis(cijkl_value_axis);
    bar_graph->setRowAxis(ij_axis);
    bar_graph->setColumnAxis(kl_axis);

    primary_series = new QBar3DSeries();
    primary_series->setItemLabelFormat(QStringLiteral("c_ijkl - @colLabel @rowLabel: @valueLabel"));
    primary_series->setMesh(QAbstract3DSeries::MeshBevelBar);
    primary_series->setMeshSmooth(false);

    bar_graph->addSeries(primary_series);

    // theme...
    bar_graph->activeTheme()->setType(Q3DTheme::ThemeArmyBlue);
    //bar_graph->activeTheme()->setType(Q3DTheme::ThemeDigia);
    //bar_graph->activeTheme()->setType(Q3DTheme::ThemeEbony);
    //bar_graph->activeTheme()->setType(Q3DTheme::ThemeIsabelle);
    //bar_graph->activeTheme()->setType(Q3DTheme::ThemePrimaryColors);
    //bar_graph->activeTheme()->setType(Q3DTheme::ThemeQt);
    //bar_graph->activeTheme()->setType(Q3DTheme::ThemeRetro);
    //bar_graph->activeTheme()->setType(Q3DTheme::ThemeStoneMoss);
    //bar_graph->activeTheme()->setType(Q3DTheme::ThemeUserDefined);

    // data
    mpc::core::StiffnessTensor<float> c_ijkl = mpc::data::AugiteStiffnessTensor<float>();
    float c_ijkl_data[9][9] = {
            {c_ijkl.tensor(0,0,0,0), c_ijkl.tensor(0,0,0,1), c_ijkl.tensor(0,0,0,2),
             c_ijkl.tensor(0,0,1,0), c_ijkl.tensor(0,0,1,1), c_ijkl.tensor(0,0,1,2),
             c_ijkl.tensor(0,0,2,0), c_ijkl.tensor(0,0,2,1), c_ijkl.tensor(0,0,2,2)},  // ij 1,1
            {c_ijkl.tensor(0,1,0,0), c_ijkl.tensor(0,1,0,1), c_ijkl.tensor(0,1,0,2),
             c_ijkl.tensor(0,1,1,0), c_ijkl.tensor(0,1,1,1), c_ijkl.tensor(0,1,1,2),
             c_ijkl.tensor(0,1,2,0), c_ijkl.tensor(0,1,2,1), c_ijkl.tensor(0,1,2,2)},  // ij 1,2
            {c_ijkl.tensor(0,2,0,0), c_ijkl.tensor(0,2,0,1), c_ijkl.tensor(0,2,0,2),
             c_ijkl.tensor(0,2,1,0), c_ijkl.tensor(0,2,1,1), c_ijkl.tensor(0,2,1,2),
             c_ijkl.tensor(0,2,2,0), c_ijkl.tensor(0,2,2,1), c_ijkl.tensor(0,2,2,2)},  // ij 1,3
            {c_ijkl.tensor(1,0,0,0), c_ijkl.tensor(1,0,0,1), c_ijkl.tensor(1,0,0,2),
             c_ijkl.tensor(1,0,1,0), c_ijkl.tensor(1,0,1,1), c_ijkl.tensor(1,0,1,2),
             c_ijkl.tensor(1,0,2,0), c_ijkl.tensor(1,0,2,1), c_ijkl.tensor(1,0,2,2)},  // ij 2,1
            {c_ijkl.tensor(1,1,0,0), c_ijkl.tensor(1,1,0,1), c_ijkl.tensor(1,1,0,2),
             c_ijkl.tensor(1,1,1,0), c_ijkl.tensor(1,1,1,1), c_ijkl.tensor(1,1,1,2),
             c_ijkl.tensor(1,1,2,0), c_ijkl.tensor(1,1,2,1), c_ijkl.tensor(1,1,2,2)},  // ij 2,2
            {c_ijkl.tensor(1,2,0,0), c_ijkl.tensor(1,2,0,1), c_ijkl.tensor(1,2,0,2),
             c_ijkl.tensor(1,2,1,0), c_ijkl.tensor(1,2,1,1), c_ijkl.tensor(1,2,1,2),
             c_ijkl.tensor(1,2,2,0), c_ijkl.tensor(1,2,2,1), c_ijkl.tensor(1,2,2,2)},  // ij 2,3
            {c_ijkl.tensor(2,0,0,0), c_ijkl.tensor(2,0,0,1), c_ijkl.tensor(2,0,0,2),
             c_ijkl.tensor(2,0,1,0), c_ijkl.tensor(2,0,1,1), c_ijkl.tensor(2,0,1,2),
             c_ijkl.tensor(2,0,2,0), c_ijkl.tensor(2,0,2,1), c_ijkl.tensor(2,0,2,2)},  // ij 3,1
            {c_ijkl.tensor(2,1,0,0), c_ijkl.tensor(2,1,0,1), c_ijkl.tensor(2,1,0,2),
             c_ijkl.tensor(2,1,1,0), c_ijkl.tensor(2,1,1,1), c_ijkl.tensor(2,1,1,2),
             c_ijkl.tensor(2,1,2,0), c_ijkl.tensor(2,1,2,1), c_ijkl.tensor(2,1,2,2)},  // ij 3,2
            {c_ijkl.tensor(2,2,0,0), c_ijkl.tensor(2,2,0,1), c_ijkl.tensor(2,2,0,2),
             c_ijkl.tensor(2,2,1,0), c_ijkl.tensor(2,2,1,1), c_ijkl.tensor(2,2,1,2),
             c_ijkl.tensor(2,2,2,0), c_ijkl.tensor(2,2,2,1), c_ijkl.tensor(2,2,2,2)}   // ij 3,3
    };

    // create data arrays
    QBarDataArray *dataSet = new QBarDataArray;
    QBarDataRow *dataRow;

    dataSet->reserve(9);
    for (int ij = 0; ij < 9; ij++) {
        // Create a data row
        dataRow = new QBarDataRow(9);
        for (int kl = 0; kl < 9; kl++) {
            // Add data to the row
            (*dataRow)[kl].setValue(c_ijkl_data[ij][kl]);
        }
        // Add the row to the set
        dataSet->append(dataRow);
    }

    // Add data to the data proxy (the data proxy assumes ownership of it)
    primary_series->dataProxy()->resetArray(dataSet, ij_list, ij_list);

    // signals/slots
    connect(mineral_combo_box, SIGNAL(currentIndexChanged(int)), this, SLOT(MineralComboBoxChanged(int)));

    //
    setLayout(hLayout);
}

View01MineralData::~View01MineralData()
{
    //
    delete density_line_edit;
    delete bulk_modulus_line_edit;
    delete shear_modulus_line_edit;
    delete c11_line_edit;
    delete c12_line_edit;
    delete c13_line_edit;
    delete c14_line_edit;
    delete c15_line_edit;
    delete c16_line_edit;
    delete c22_line_edit;
    delete c23_line_edit;
    delete c24_line_edit;
    delete c25_line_edit;
    delete c26_line_edit;
    delete c33_line_edit;
    delete c34_line_edit;
    delete c35_line_edit;
    delete c36_line_edit;
    delete c44_line_edit;
    delete c45_line_edit;
    delete c46_line_edit;
    delete c55_line_edit;
    delete c56_line_edit;
    delete c66_line_edit;

    delete bar_graph;

}

void View01MineralData::MineralComboBoxChanged(int i)
{
    // slot when the mineral combo box is changed
    switch(i) {
    case 0: { // Augite
        density_line_edit->setText(QString::number(mpc::data::AugiteDensity<double>()));
        bulk_modulus_line_edit->setText(QString::number(mpc::data::AugiteBulkModulus<double>()));
        shear_modulus_line_edit->setText(QString::number(mpc::data::AugiteShearModulus<double>()));
        c11_line_edit->setText(QString::number(mpc::data::AugiteC11<double>()));
        c12_line_edit->setText(QString::number(mpc::data::AugiteC12<double>()));
        c13_line_edit->setText(QString::number(mpc::data::AugiteC13<double>()));
        c14_line_edit->setText(QString::number(mpc::data::AugiteC14<double>()));
        c15_line_edit->setText(QString::number(mpc::data::AugiteC15<double>()));
        c16_line_edit->setText(QString::number(mpc::data::AugiteC16<double>()));
        c22_line_edit->setText(QString::number(mpc::data::AugiteC22<double>()));
        c23_line_edit->setText(QString::number(mpc::data::AugiteC23<double>()));
        c24_line_edit->setText(QString::number(mpc::data::AugiteC24<double>()));
        c25_line_edit->setText(QString::number(mpc::data::AugiteC25<double>()));
        c26_line_edit->setText(QString::number(mpc::data::AugiteC26<double>()));
        c33_line_edit->setText(QString::number(mpc::data::AugiteC33<double>()));
        c34_line_edit->setText(QString::number(mpc::data::AugiteC34<double>()));
        c35_line_edit->setText(QString::number(mpc::data::AugiteC35<double>()));
        c36_line_edit->setText(QString::number(mpc::data::AugiteC36<double>()));
        c44_line_edit->setText(QString::number(mpc::data::AugiteC44<double>()));
        c45_line_edit->setText(QString::number(mpc::data::AugiteC45<double>()));
        c46_line_edit->setText(QString::number(mpc::data::AugiteC46<double>()));
        c55_line_edit->setText(QString::number(mpc::data::AugiteC55<double>()));
        c56_line_edit->setText(QString::number(mpc::data::AugiteC56<double>()));
        c66_line_edit->setText(QString::number(mpc::data::AugiteC66<double>()));
        // data
        mpc::core::StiffnessTensor<float> c_ijkl = mpc::data::AugiteStiffnessTensor<float>();
        float c_ijkl_data[9][9] = {
                {c_ijkl.tensor(0,0,0,0), c_ijkl.tensor(0,0,0,1), c_ijkl.tensor(0,0,0,2),
                 c_ijkl.tensor(0,0,1,0), c_ijkl.tensor(0,0,1,1), c_ijkl.tensor(0,0,1,2),
                 c_ijkl.tensor(0,0,2,0), c_ijkl.tensor(0,0,2,1), c_ijkl.tensor(0,0,2,2)},  // ij 1,1
                {c_ijkl.tensor(0,1,0,0), c_ijkl.tensor(0,1,0,1), c_ijkl.tensor(0,1,0,2),
                 c_ijkl.tensor(0,1,1,0), c_ijkl.tensor(0,1,1,1), c_ijkl.tensor(0,1,1,2),
                 c_ijkl.tensor(0,1,2,0), c_ijkl.tensor(0,1,2,1), c_ijkl.tensor(0,1,2,2)},  // ij 1,2
                {c_ijkl.tensor(0,2,0,0), c_ijkl.tensor(0,2,0,1), c_ijkl.tensor(0,2,0,2),
                 c_ijkl.tensor(0,2,1,0), c_ijkl.tensor(0,2,1,1), c_ijkl.tensor(0,2,1,2),
                 c_ijkl.tensor(0,2,2,0), c_ijkl.tensor(0,2,2,1), c_ijkl.tensor(0,2,2,2)},  // ij 1,3
                {c_ijkl.tensor(1,0,0,0), c_ijkl.tensor(1,0,0,1), c_ijkl.tensor(1,0,0,2),
                 c_ijkl.tensor(1,0,1,0), c_ijkl.tensor(1,0,1,1), c_ijkl.tensor(1,0,1,2),
                 c_ijkl.tensor(1,0,2,0), c_ijkl.tensor(1,0,2,1), c_ijkl.tensor(1,0,2,2)},  // ij 2,1
                {c_ijkl.tensor(1,1,0,0), c_ijkl.tensor(1,1,0,1), c_ijkl.tensor(1,1,0,2),
                 c_ijkl.tensor(1,1,1,0), c_ijkl.tensor(1,1,1,1), c_ijkl.tensor(1,1,1,2),
                 c_ijkl.tensor(1,1,2,0), c_ijkl.tensor(1,1,2,1), c_ijkl.tensor(1,1,2,2)},  // ij 2,2
                {c_ijkl.tensor(1,2,0,0), c_ijkl.tensor(1,2,0,1), c_ijkl.tensor(1,2,0,2),
                 c_ijkl.tensor(1,2,1,0), c_ijkl.tensor(1,2,1,1), c_ijkl.tensor(1,2,1,2),
                 c_ijkl.tensor(1,2,2,0), c_ijkl.tensor(1,2,2,1), c_ijkl.tensor(1,2,2,2)},  // ij 2,3
                {c_ijkl.tensor(2,0,0,0), c_ijkl.tensor(2,0,0,1), c_ijkl.tensor(2,0,0,2),
                 c_ijkl.tensor(2,0,1,0), c_ijkl.tensor(2,0,1,1), c_ijkl.tensor(2,0,1,2),
                 c_ijkl.tensor(2,0,2,0), c_ijkl.tensor(2,0,2,1), c_ijkl.tensor(2,0,2,2)},  // ij 3,1
                {c_ijkl.tensor(2,1,0,0), c_ijkl.tensor(2,1,0,1), c_ijkl.tensor(2,1,0,2),
                 c_ijkl.tensor(2,1,1,0), c_ijkl.tensor(2,1,1,1), c_ijkl.tensor(2,1,1,2),
                 c_ijkl.tensor(2,1,2,0), c_ijkl.tensor(2,1,2,1), c_ijkl.tensor(2,1,2,2)},  // ij 3,2
                {c_ijkl.tensor(2,2,0,0), c_ijkl.tensor(2,2,0,1), c_ijkl.tensor(2,2,0,2),
                 c_ijkl.tensor(2,2,1,0), c_ijkl.tensor(2,2,1,1), c_ijkl.tensor(2,2,1,2),
                 c_ijkl.tensor(2,2,2,0), c_ijkl.tensor(2,2,2,1), c_ijkl.tensor(2,2,2,2)}   // ij 3,3
        };

        // create data arrays
        QBarDataArray *dataSet = new QBarDataArray;
        QBarDataRow *dataRow;

        dataSet->reserve(9);
        for (int ij = 0; ij < 9; ij++) {
            // Create a data row
            dataRow = new QBarDataRow(9);
            for (int kl = 0; kl < 9; kl++) {
                // Add data to the row
                (*dataRow)[kl].setValue(c_ijkl_data[ij][kl]);
            }
            // Add the row to the set
            dataSet->append(dataRow);
        }

        // Add data to the data proxy (the data proxy assumes ownership of it)
        primary_series->dataProxy()->resetArray(dataSet, ij_list, ij_list);
        break;
    }
    case 1: { // Albite
        density_line_edit->setText(QString::number(mpc::data::AlbiteDensity<double>()));
        bulk_modulus_line_edit->setText(QString::number(mpc::data::AlbiteBulkModulus<double>()));
        shear_modulus_line_edit->setText(QString::number(mpc::data::AlbiteShearModulus<double>()));
        c11_line_edit->setText(QString::number(mpc::data::AlbiteC11<double>()));
        c12_line_edit->setText(QString::number(mpc::data::AlbiteC12<double>()));
        c13_line_edit->setText(QString::number(mpc::data::AlbiteC13<double>()));
        c14_line_edit->setText(QString::number(mpc::data::AlbiteC14<double>()));
        c15_line_edit->setText(QString::number(mpc::data::AlbiteC15<double>()));
        c16_line_edit->setText(QString::number(mpc::data::AlbiteC16<double>()));
        c22_line_edit->setText(QString::number(mpc::data::AlbiteC22<double>()));
        c23_line_edit->setText(QString::number(mpc::data::AlbiteC23<double>()));
        c24_line_edit->setText(QString::number(mpc::data::AlbiteC24<double>()));
        c25_line_edit->setText(QString::number(mpc::data::AlbiteC25<double>()));
        c26_line_edit->setText(QString::number(mpc::data::AlbiteC26<double>()));
        c33_line_edit->setText(QString::number(mpc::data::AlbiteC33<double>()));
        c34_line_edit->setText(QString::number(mpc::data::AlbiteC34<double>()));
        c35_line_edit->setText(QString::number(mpc::data::AlbiteC35<double>()));
        c36_line_edit->setText(QString::number(mpc::data::AlbiteC36<double>()));
        c44_line_edit->setText(QString::number(mpc::data::AlbiteC44<double>()));
        c45_line_edit->setText(QString::number(mpc::data::AlbiteC45<double>()));
        c46_line_edit->setText(QString::number(mpc::data::AlbiteC46<double>()));
        c55_line_edit->setText(QString::number(mpc::data::AlbiteC55<double>()));
        c56_line_edit->setText(QString::number(mpc::data::AlbiteC56<double>()));
        c66_line_edit->setText(QString::number(mpc::data::AlbiteC66<double>()));
        // data
        mpc::core::StiffnessTensor<float> c_ijkl = mpc::data::AlbiteStiffnessTensor<float>();
        float c_ijkl_data[9][9] = {
                {c_ijkl.tensor(0,0,0,0), c_ijkl.tensor(0,0,0,1), c_ijkl.tensor(0,0,0,2),
                 c_ijkl.tensor(0,0,1,0), c_ijkl.tensor(0,0,1,1), c_ijkl.tensor(0,0,1,2),
                 c_ijkl.tensor(0,0,2,0), c_ijkl.tensor(0,0,2,1), c_ijkl.tensor(0,0,2,2)},  // ij 1,1
                {c_ijkl.tensor(0,1,0,0), c_ijkl.tensor(0,1,0,1), c_ijkl.tensor(0,1,0,2),
                 c_ijkl.tensor(0,1,1,0), c_ijkl.tensor(0,1,1,1), c_ijkl.tensor(0,1,1,2),
                 c_ijkl.tensor(0,1,2,0), c_ijkl.tensor(0,1,2,1), c_ijkl.tensor(0,1,2,2)},  // ij 1,2
                {c_ijkl.tensor(0,2,0,0), c_ijkl.tensor(0,2,0,1), c_ijkl.tensor(0,2,0,2),
                 c_ijkl.tensor(0,2,1,0), c_ijkl.tensor(0,2,1,1), c_ijkl.tensor(0,2,1,2),
                 c_ijkl.tensor(0,2,2,0), c_ijkl.tensor(0,2,2,1), c_ijkl.tensor(0,2,2,2)},  // ij 1,3
                {c_ijkl.tensor(1,0,0,0), c_ijkl.tensor(1,0,0,1), c_ijkl.tensor(1,0,0,2),
                 c_ijkl.tensor(1,0,1,0), c_ijkl.tensor(1,0,1,1), c_ijkl.tensor(1,0,1,2),
                 c_ijkl.tensor(1,0,2,0), c_ijkl.tensor(1,0,2,1), c_ijkl.tensor(1,0,2,2)},  // ij 2,1
                {c_ijkl.tensor(1,1,0,0), c_ijkl.tensor(1,1,0,1), c_ijkl.tensor(1,1,0,2),
                 c_ijkl.tensor(1,1,1,0), c_ijkl.tensor(1,1,1,1), c_ijkl.tensor(1,1,1,2),
                 c_ijkl.tensor(1,1,2,0), c_ijkl.tensor(1,1,2,1), c_ijkl.tensor(1,1,2,2)},  // ij 2,2
                {c_ijkl.tensor(1,2,0,0), c_ijkl.tensor(1,2,0,1), c_ijkl.tensor(1,2,0,2),
                 c_ijkl.tensor(1,2,1,0), c_ijkl.tensor(1,2,1,1), c_ijkl.tensor(1,2,1,2),
                 c_ijkl.tensor(1,2,2,0), c_ijkl.tensor(1,2,2,1), c_ijkl.tensor(1,2,2,2)},  // ij 2,3
                {c_ijkl.tensor(2,0,0,0), c_ijkl.tensor(2,0,0,1), c_ijkl.tensor(2,0,0,2),
                 c_ijkl.tensor(2,0,1,0), c_ijkl.tensor(2,0,1,1), c_ijkl.tensor(2,0,1,2),
                 c_ijkl.tensor(2,0,2,0), c_ijkl.tensor(2,0,2,1), c_ijkl.tensor(2,0,2,2)},  // ij 3,1
                {c_ijkl.tensor(2,1,0,0), c_ijkl.tensor(2,1,0,1), c_ijkl.tensor(2,1,0,2),
                 c_ijkl.tensor(2,1,1,0), c_ijkl.tensor(2,1,1,1), c_ijkl.tensor(2,1,1,2),
                 c_ijkl.tensor(2,1,2,0), c_ijkl.tensor(2,1,2,1), c_ijkl.tensor(2,1,2,2)},  // ij 3,2
                {c_ijkl.tensor(2,2,0,0), c_ijkl.tensor(2,2,0,1), c_ijkl.tensor(2,2,0,2),
                 c_ijkl.tensor(2,2,1,0), c_ijkl.tensor(2,2,1,1), c_ijkl.tensor(2,2,1,2),
                 c_ijkl.tensor(2,2,2,0), c_ijkl.tensor(2,2,2,1), c_ijkl.tensor(2,2,2,2)}   // ij 3,3
        };

        // create data arrays
        QBarDataArray *dataSet = new QBarDataArray;
        QBarDataRow *dataRow;

        dataSet->reserve(9);
        for (int ij = 0; ij < 9; ij++) {
            // Create a data row
            dataRow = new QBarDataRow(9);
            for (int kl = 0; kl < 9; kl++) {
                // Add data to the row
                (*dataRow)[kl].setValue(c_ijkl_data[ij][kl]);
            }
            // Add the row to the set
            dataSet->append(dataRow);
        }

        // Add data to the data proxy (the data proxy assumes ownership of it)
        primary_series->dataProxy()->resetArray(dataSet, ij_list, ij_list);
        break;
    }
    case 2: { // Anorthite
        density_line_edit->setText(QString::number(mpc::data::AnorthiteDensity<double>()));
        bulk_modulus_line_edit->setText(QString::number(mpc::data::AnorthiteBulkModulus<double>()));
        shear_modulus_line_edit->setText(QString::number(mpc::data::AnorthiteShearModulus<double>()));
        c11_line_edit->setText(QString::number(mpc::data::AnorthiteC11<double>()));
        c12_line_edit->setText(QString::number(mpc::data::AnorthiteC12<double>()));
        c13_line_edit->setText(QString::number(mpc::data::AnorthiteC13<double>()));
        c14_line_edit->setText(QString::number(mpc::data::AnorthiteC14<double>()));
        c15_line_edit->setText(QString::number(mpc::data::AnorthiteC15<double>()));
        c16_line_edit->setText(QString::number(mpc::data::AnorthiteC16<double>()));
        c22_line_edit->setText(QString::number(mpc::data::AnorthiteC22<double>()));
        c23_line_edit->setText(QString::number(mpc::data::AnorthiteC23<double>()));
        c24_line_edit->setText(QString::number(mpc::data::AnorthiteC24<double>()));
        c25_line_edit->setText(QString::number(mpc::data::AnorthiteC25<double>()));
        c26_line_edit->setText(QString::number(mpc::data::AnorthiteC26<double>()));
        c33_line_edit->setText(QString::number(mpc::data::AnorthiteC33<double>()));
        c34_line_edit->setText(QString::number(mpc::data::AnorthiteC34<double>()));
        c35_line_edit->setText(QString::number(mpc::data::AnorthiteC35<double>()));
        c36_line_edit->setText(QString::number(mpc::data::AnorthiteC36<double>()));
        c44_line_edit->setText(QString::number(mpc::data::AnorthiteC44<double>()));
        c45_line_edit->setText(QString::number(mpc::data::AnorthiteC45<double>()));
        c46_line_edit->setText(QString::number(mpc::data::AnorthiteC46<double>()));
        c55_line_edit->setText(QString::number(mpc::data::AnorthiteC55<double>()));
        c56_line_edit->setText(QString::number(mpc::data::AnorthiteC56<double>()));
        c66_line_edit->setText(QString::number(mpc::data::AnorthiteC66<double>()));
        // data
        mpc::core::StiffnessTensor<float> c_ijkl = mpc::data::AnorthiteStiffnessTensor<float>();
        float c_ijkl_data[9][9] = {
                {c_ijkl.tensor(0,0,0,0), c_ijkl.tensor(0,0,0,1), c_ijkl.tensor(0,0,0,2),
                 c_ijkl.tensor(0,0,1,0), c_ijkl.tensor(0,0,1,1), c_ijkl.tensor(0,0,1,2),
                 c_ijkl.tensor(0,0,2,0), c_ijkl.tensor(0,0,2,1), c_ijkl.tensor(0,0,2,2)},  // ij 1,1
                {c_ijkl.tensor(0,1,0,0), c_ijkl.tensor(0,1,0,1), c_ijkl.tensor(0,1,0,2),
                 c_ijkl.tensor(0,1,1,0), c_ijkl.tensor(0,1,1,1), c_ijkl.tensor(0,1,1,2),
                 c_ijkl.tensor(0,1,2,0), c_ijkl.tensor(0,1,2,1), c_ijkl.tensor(0,1,2,2)},  // ij 1,2
                {c_ijkl.tensor(0,2,0,0), c_ijkl.tensor(0,2,0,1), c_ijkl.tensor(0,2,0,2),
                 c_ijkl.tensor(0,2,1,0), c_ijkl.tensor(0,2,1,1), c_ijkl.tensor(0,2,1,2),
                 c_ijkl.tensor(0,2,2,0), c_ijkl.tensor(0,2,2,1), c_ijkl.tensor(0,2,2,2)},  // ij 1,3
                {c_ijkl.tensor(1,0,0,0), c_ijkl.tensor(1,0,0,1), c_ijkl.tensor(1,0,0,2),
                 c_ijkl.tensor(1,0,1,0), c_ijkl.tensor(1,0,1,1), c_ijkl.tensor(1,0,1,2),
                 c_ijkl.tensor(1,0,2,0), c_ijkl.tensor(1,0,2,1), c_ijkl.tensor(1,0,2,2)},  // ij 2,1
                {c_ijkl.tensor(1,1,0,0), c_ijkl.tensor(1,1,0,1), c_ijkl.tensor(1,1,0,2),
                 c_ijkl.tensor(1,1,1,0), c_ijkl.tensor(1,1,1,1), c_ijkl.tensor(1,1,1,2),
                 c_ijkl.tensor(1,1,2,0), c_ijkl.tensor(1,1,2,1), c_ijkl.tensor(1,1,2,2)},  // ij 2,2
                {c_ijkl.tensor(1,2,0,0), c_ijkl.tensor(1,2,0,1), c_ijkl.tensor(1,2,0,2),
                 c_ijkl.tensor(1,2,1,0), c_ijkl.tensor(1,2,1,1), c_ijkl.tensor(1,2,1,2),
                 c_ijkl.tensor(1,2,2,0), c_ijkl.tensor(1,2,2,1), c_ijkl.tensor(1,2,2,2)},  // ij 2,3
                {c_ijkl.tensor(2,0,0,0), c_ijkl.tensor(2,0,0,1), c_ijkl.tensor(2,0,0,2),
                 c_ijkl.tensor(2,0,1,0), c_ijkl.tensor(2,0,1,1), c_ijkl.tensor(2,0,1,2),
                 c_ijkl.tensor(2,0,2,0), c_ijkl.tensor(2,0,2,1), c_ijkl.tensor(2,0,2,2)},  // ij 3,1
                {c_ijkl.tensor(2,1,0,0), c_ijkl.tensor(2,1,0,1), c_ijkl.tensor(2,1,0,2),
                 c_ijkl.tensor(2,1,1,0), c_ijkl.tensor(2,1,1,1), c_ijkl.tensor(2,1,1,2),
                 c_ijkl.tensor(2,1,2,0), c_ijkl.tensor(2,1,2,1), c_ijkl.tensor(2,1,2,2)},  // ij 3,2
                {c_ijkl.tensor(2,2,0,0), c_ijkl.tensor(2,2,0,1), c_ijkl.tensor(2,2,0,2),
                 c_ijkl.tensor(2,2,1,0), c_ijkl.tensor(2,2,1,1), c_ijkl.tensor(2,2,1,2),
                 c_ijkl.tensor(2,2,2,0), c_ijkl.tensor(2,2,2,1), c_ijkl.tensor(2,2,2,2)}   // ij 3,3
        };

        // create data arrays
        QBarDataArray *dataSet = new QBarDataArray;
        QBarDataRow *dataRow;

        dataSet->reserve(9);
        for (int ij = 0; ij < 9; ij++) {
            // Create a data row
            dataRow = new QBarDataRow(9);
            for (int kl = 0; kl < 9; kl++) {
                // Add data to the row
                (*dataRow)[kl].setValue(c_ijkl_data[ij][kl]);
            }
            // Add the row to the set
            dataSet->append(dataRow);
        }

        // Add data to the data proxy (the data proxy assumes ownership of it)
        primary_series->dataProxy()->resetArray(dataSet, ij_list, ij_list);
        break;
    }
    case 3: { // Labradorite
        density_line_edit->setText(QString::number(mpc::data::LabradoriteDensity<double>()));
        bulk_modulus_line_edit->setText(QString::number(mpc::data::LabradoriteBulkModulus<double>()));
        shear_modulus_line_edit->setText(QString::number(mpc::data::LabradoriteShearModulus<double>()));
        c11_line_edit->setText(QString::number(mpc::data::LabradoriteC11<double>()));
        c12_line_edit->setText(QString::number(mpc::data::LabradoriteC12<double>()));
        c13_line_edit->setText(QString::number(mpc::data::LabradoriteC13<double>()));
        c14_line_edit->setText(QString::number(mpc::data::LabradoriteC14<double>()));
        c15_line_edit->setText(QString::number(mpc::data::LabradoriteC15<double>()));
        c16_line_edit->setText(QString::number(mpc::data::LabradoriteC16<double>()));
        c22_line_edit->setText(QString::number(mpc::data::LabradoriteC22<double>()));
        c23_line_edit->setText(QString::number(mpc::data::LabradoriteC23<double>()));
        c24_line_edit->setText(QString::number(mpc::data::LabradoriteC24<double>()));
        c25_line_edit->setText(QString::number(mpc::data::LabradoriteC25<double>()));
        c26_line_edit->setText(QString::number(mpc::data::LabradoriteC26<double>()));
        c33_line_edit->setText(QString::number(mpc::data::LabradoriteC33<double>()));
        c34_line_edit->setText(QString::number(mpc::data::LabradoriteC34<double>()));
        c35_line_edit->setText(QString::number(mpc::data::LabradoriteC35<double>()));
        c36_line_edit->setText(QString::number(mpc::data::LabradoriteC36<double>()));
        c44_line_edit->setText(QString::number(mpc::data::LabradoriteC44<double>()));
        c45_line_edit->setText(QString::number(mpc::data::LabradoriteC45<double>()));
        c46_line_edit->setText(QString::number(mpc::data::LabradoriteC46<double>()));
        c55_line_edit->setText(QString::number(mpc::data::LabradoriteC55<double>()));
        c56_line_edit->setText(QString::number(mpc::data::LabradoriteC56<double>()));
        c66_line_edit->setText(QString::number(mpc::data::LabradoriteC66<double>()));
        // data
        mpc::core::StiffnessTensor<float> c_ijkl = mpc::data::LabradoriteStiffnessTensor<float>();
        float c_ijkl_data[9][9] = {
                {c_ijkl.tensor(0,0,0,0), c_ijkl.tensor(0,0,0,1), c_ijkl.tensor(0,0,0,2),
                 c_ijkl.tensor(0,0,1,0), c_ijkl.tensor(0,0,1,1), c_ijkl.tensor(0,0,1,2),
                 c_ijkl.tensor(0,0,2,0), c_ijkl.tensor(0,0,2,1), c_ijkl.tensor(0,0,2,2)},  // ij 1,1
                {c_ijkl.tensor(0,1,0,0), c_ijkl.tensor(0,1,0,1), c_ijkl.tensor(0,1,0,2),
                 c_ijkl.tensor(0,1,1,0), c_ijkl.tensor(0,1,1,1), c_ijkl.tensor(0,1,1,2),
                 c_ijkl.tensor(0,1,2,0), c_ijkl.tensor(0,1,2,1), c_ijkl.tensor(0,1,2,2)},  // ij 1,2
                {c_ijkl.tensor(0,2,0,0), c_ijkl.tensor(0,2,0,1), c_ijkl.tensor(0,2,0,2),
                 c_ijkl.tensor(0,2,1,0), c_ijkl.tensor(0,2,1,1), c_ijkl.tensor(0,2,1,2),
                 c_ijkl.tensor(0,2,2,0), c_ijkl.tensor(0,2,2,1), c_ijkl.tensor(0,2,2,2)},  // ij 1,3
                {c_ijkl.tensor(1,0,0,0), c_ijkl.tensor(1,0,0,1), c_ijkl.tensor(1,0,0,2),
                 c_ijkl.tensor(1,0,1,0), c_ijkl.tensor(1,0,1,1), c_ijkl.tensor(1,0,1,2),
                 c_ijkl.tensor(1,0,2,0), c_ijkl.tensor(1,0,2,1), c_ijkl.tensor(1,0,2,2)},  // ij 2,1
                {c_ijkl.tensor(1,1,0,0), c_ijkl.tensor(1,1,0,1), c_ijkl.tensor(1,1,0,2),
                 c_ijkl.tensor(1,1,1,0), c_ijkl.tensor(1,1,1,1), c_ijkl.tensor(1,1,1,2),
                 c_ijkl.tensor(1,1,2,0), c_ijkl.tensor(1,1,2,1), c_ijkl.tensor(1,1,2,2)},  // ij 2,2
                {c_ijkl.tensor(1,2,0,0), c_ijkl.tensor(1,2,0,1), c_ijkl.tensor(1,2,0,2),
                 c_ijkl.tensor(1,2,1,0), c_ijkl.tensor(1,2,1,1), c_ijkl.tensor(1,2,1,2),
                 c_ijkl.tensor(1,2,2,0), c_ijkl.tensor(1,2,2,1), c_ijkl.tensor(1,2,2,2)},  // ij 2,3
                {c_ijkl.tensor(2,0,0,0), c_ijkl.tensor(2,0,0,1), c_ijkl.tensor(2,0,0,2),
                 c_ijkl.tensor(2,0,1,0), c_ijkl.tensor(2,0,1,1), c_ijkl.tensor(2,0,1,2),
                 c_ijkl.tensor(2,0,2,0), c_ijkl.tensor(2,0,2,1), c_ijkl.tensor(2,0,2,2)},  // ij 3,1
                {c_ijkl.tensor(2,1,0,0), c_ijkl.tensor(2,1,0,1), c_ijkl.tensor(2,1,0,2),
                 c_ijkl.tensor(2,1,1,0), c_ijkl.tensor(2,1,1,1), c_ijkl.tensor(2,1,1,2),
                 c_ijkl.tensor(2,1,2,0), c_ijkl.tensor(2,1,2,1), c_ijkl.tensor(2,1,2,2)},  // ij 3,2
                {c_ijkl.tensor(2,2,0,0), c_ijkl.tensor(2,2,0,1), c_ijkl.tensor(2,2,0,2),
                 c_ijkl.tensor(2,2,1,0), c_ijkl.tensor(2,2,1,1), c_ijkl.tensor(2,2,1,2),
                 c_ijkl.tensor(2,2,2,0), c_ijkl.tensor(2,2,2,1), c_ijkl.tensor(2,2,2,2)}   // ij 3,3
        };

        // create data arrays
        QBarDataArray *dataSet = new QBarDataArray;
        QBarDataRow *dataRow;

        dataSet->reserve(9);
        for (int ij = 0; ij < 9; ij++) {
            // Create a data row
            dataRow = new QBarDataRow(9);
            for (int kl = 0; kl < 9; kl++) {
                // Add data to the row
                (*dataRow)[kl].setValue(c_ijkl_data[ij][kl]);
            }
            // Add the row to the set
            dataSet->append(dataRow);
        }

        // Add data to the data proxy (the data proxy assumes ownership of it)
        primary_series->dataProxy()->resetArray(dataSet, ij_list, ij_list);
        break;
    }
    case 4: { // Microcline
        density_line_edit->setText(QString::number(mpc::data::MicroclineDensity<double>()));
        bulk_modulus_line_edit->setText(QString::number(mpc::data::MicroclineBulkModulus<double>()));
        shear_modulus_line_edit->setText(QString::number(mpc::data::MicroclineShearModulus<double>()));
        c11_line_edit->setText(QString::number(mpc::data::MicroclineC11<double>()));
        c12_line_edit->setText(QString::number(mpc::data::MicroclineC12<double>()));
        c13_line_edit->setText(QString::number(mpc::data::MicroclineC13<double>()));
        c14_line_edit->setText(QString::number(mpc::data::MicroclineC14<double>()));
        c15_line_edit->setText(QString::number(mpc::data::MicroclineC15<double>()));
        c16_line_edit->setText(QString::number(mpc::data::MicroclineC16<double>()));
        c22_line_edit->setText(QString::number(mpc::data::MicroclineC22<double>()));
        c23_line_edit->setText(QString::number(mpc::data::MicroclineC23<double>()));
        c24_line_edit->setText(QString::number(mpc::data::MicroclineC24<double>()));
        c25_line_edit->setText(QString::number(mpc::data::MicroclineC25<double>()));
        c26_line_edit->setText(QString::number(mpc::data::MicroclineC26<double>()));
        c33_line_edit->setText(QString::number(mpc::data::MicroclineC33<double>()));
        c34_line_edit->setText(QString::number(mpc::data::MicroclineC34<double>()));
        c35_line_edit->setText(QString::number(mpc::data::MicroclineC35<double>()));
        c36_line_edit->setText(QString::number(mpc::data::MicroclineC36<double>()));
        c44_line_edit->setText(QString::number(mpc::data::MicroclineC44<double>()));
        c45_line_edit->setText(QString::number(mpc::data::MicroclineC45<double>()));
        c46_line_edit->setText(QString::number(mpc::data::MicroclineC46<double>()));
        c55_line_edit->setText(QString::number(mpc::data::MicroclineC55<double>()));
        c56_line_edit->setText(QString::number(mpc::data::MicroclineC56<double>()));
        c66_line_edit->setText(QString::number(mpc::data::MicroclineC66<double>()));
        // data
        mpc::core::StiffnessTensor<float> c_ijkl = mpc::data::MicroclineStiffnessTensor<float>();
        float c_ijkl_data[9][9] = {
                {c_ijkl.tensor(0,0,0,0), c_ijkl.tensor(0,0,0,1), c_ijkl.tensor(0,0,0,2),
                 c_ijkl.tensor(0,0,1,0), c_ijkl.tensor(0,0,1,1), c_ijkl.tensor(0,0,1,2),
                 c_ijkl.tensor(0,0,2,0), c_ijkl.tensor(0,0,2,1), c_ijkl.tensor(0,0,2,2)},  // ij 1,1
                {c_ijkl.tensor(0,1,0,0), c_ijkl.tensor(0,1,0,1), c_ijkl.tensor(0,1,0,2),
                 c_ijkl.tensor(0,1,1,0), c_ijkl.tensor(0,1,1,1), c_ijkl.tensor(0,1,1,2),
                 c_ijkl.tensor(0,1,2,0), c_ijkl.tensor(0,1,2,1), c_ijkl.tensor(0,1,2,2)},  // ij 1,2
                {c_ijkl.tensor(0,2,0,0), c_ijkl.tensor(0,2,0,1), c_ijkl.tensor(0,2,0,2),
                 c_ijkl.tensor(0,2,1,0), c_ijkl.tensor(0,2,1,1), c_ijkl.tensor(0,2,1,2),
                 c_ijkl.tensor(0,2,2,0), c_ijkl.tensor(0,2,2,1), c_ijkl.tensor(0,2,2,2)},  // ij 1,3
                {c_ijkl.tensor(1,0,0,0), c_ijkl.tensor(1,0,0,1), c_ijkl.tensor(1,0,0,2),
                 c_ijkl.tensor(1,0,1,0), c_ijkl.tensor(1,0,1,1), c_ijkl.tensor(1,0,1,2),
                 c_ijkl.tensor(1,0,2,0), c_ijkl.tensor(1,0,2,1), c_ijkl.tensor(1,0,2,2)},  // ij 2,1
                {c_ijkl.tensor(1,1,0,0), c_ijkl.tensor(1,1,0,1), c_ijkl.tensor(1,1,0,2),
                 c_ijkl.tensor(1,1,1,0), c_ijkl.tensor(1,1,1,1), c_ijkl.tensor(1,1,1,2),
                 c_ijkl.tensor(1,1,2,0), c_ijkl.tensor(1,1,2,1), c_ijkl.tensor(1,1,2,2)},  // ij 2,2
                {c_ijkl.tensor(1,2,0,0), c_ijkl.tensor(1,2,0,1), c_ijkl.tensor(1,2,0,2),
                 c_ijkl.tensor(1,2,1,0), c_ijkl.tensor(1,2,1,1), c_ijkl.tensor(1,2,1,2),
                 c_ijkl.tensor(1,2,2,0), c_ijkl.tensor(1,2,2,1), c_ijkl.tensor(1,2,2,2)},  // ij 2,3
                {c_ijkl.tensor(2,0,0,0), c_ijkl.tensor(2,0,0,1), c_ijkl.tensor(2,0,0,2),
                 c_ijkl.tensor(2,0,1,0), c_ijkl.tensor(2,0,1,1), c_ijkl.tensor(2,0,1,2),
                 c_ijkl.tensor(2,0,2,0), c_ijkl.tensor(2,0,2,1), c_ijkl.tensor(2,0,2,2)},  // ij 3,1
                {c_ijkl.tensor(2,1,0,0), c_ijkl.tensor(2,1,0,1), c_ijkl.tensor(2,1,0,2),
                 c_ijkl.tensor(2,1,1,0), c_ijkl.tensor(2,1,1,1), c_ijkl.tensor(2,1,1,2),
                 c_ijkl.tensor(2,1,2,0), c_ijkl.tensor(2,1,2,1), c_ijkl.tensor(2,1,2,2)},  // ij 3,2
                {c_ijkl.tensor(2,2,0,0), c_ijkl.tensor(2,2,0,1), c_ijkl.tensor(2,2,0,2),
                 c_ijkl.tensor(2,2,1,0), c_ijkl.tensor(2,2,1,1), c_ijkl.tensor(2,2,1,2),
                 c_ijkl.tensor(2,2,2,0), c_ijkl.tensor(2,2,2,1), c_ijkl.tensor(2,2,2,2)}   // ij 3,3
        };

        // create data arrays
        QBarDataArray *dataSet = new QBarDataArray;
        QBarDataRow *dataRow;

        dataSet->reserve(9);
        for (int ij = 0; ij < 9; ij++) {
            // Create a data row
            dataRow = new QBarDataRow(9);
            for (int kl = 0; kl < 9; kl++) {
                // Add data to the row
                (*dataRow)[kl].setValue(c_ijkl_data[ij][kl]);
            }
            // Add the row to the set
            dataSet->append(dataRow);
        }

        // Add data to the data proxy (the data proxy assumes ownership of it)
        primary_series->dataProxy()->resetArray(dataSet, ij_list, ij_list);
        break;
    }
    case 5: { // Oligoclase
        density_line_edit->setText(QString::number(mpc::data::OligoclaseDensity<double>()));
        bulk_modulus_line_edit->setText(QString::number(mpc::data::OligoclaseBulkModulus<double>()));
        shear_modulus_line_edit->setText(QString::number(mpc::data::OligoclaseShearModulus<double>()));
        c11_line_edit->setText(QString::number(mpc::data::OligoclaseC11<double>()));
        c12_line_edit->setText(QString::number(mpc::data::OligoclaseC12<double>()));
        c13_line_edit->setText(QString::number(mpc::data::OligoclaseC13<double>()));
        c14_line_edit->setText(QString::number(mpc::data::OligoclaseC14<double>()));
        c15_line_edit->setText(QString::number(mpc::data::OligoclaseC15<double>()));
        c16_line_edit->setText(QString::number(mpc::data::OligoclaseC16<double>()));
        c22_line_edit->setText(QString::number(mpc::data::OligoclaseC22<double>()));
        c23_line_edit->setText(QString::number(mpc::data::OligoclaseC23<double>()));
        c24_line_edit->setText(QString::number(mpc::data::OligoclaseC24<double>()));
        c25_line_edit->setText(QString::number(mpc::data::OligoclaseC25<double>()));
        c26_line_edit->setText(QString::number(mpc::data::OligoclaseC26<double>()));
        c33_line_edit->setText(QString::number(mpc::data::OligoclaseC33<double>()));
        c34_line_edit->setText(QString::number(mpc::data::OligoclaseC34<double>()));
        c35_line_edit->setText(QString::number(mpc::data::OligoclaseC35<double>()));
        c36_line_edit->setText(QString::number(mpc::data::OligoclaseC36<double>()));
        c44_line_edit->setText(QString::number(mpc::data::OligoclaseC44<double>()));
        c45_line_edit->setText(QString::number(mpc::data::OligoclaseC45<double>()));
        c46_line_edit->setText(QString::number(mpc::data::OligoclaseC46<double>()));
        c55_line_edit->setText(QString::number(mpc::data::OligoclaseC55<double>()));
        c56_line_edit->setText(QString::number(mpc::data::OligoclaseC56<double>()));
        c66_line_edit->setText(QString::number(mpc::data::OligoclaseC66<double>()));
        // data
        mpc::core::StiffnessTensor<float> c_ijkl = mpc::data::OligoclaseStiffnessTensor<float>();
        float c_ijkl_data[9][9] = {
                {c_ijkl.tensor(0,0,0,0), c_ijkl.tensor(0,0,0,1), c_ijkl.tensor(0,0,0,2),
                 c_ijkl.tensor(0,0,1,0), c_ijkl.tensor(0,0,1,1), c_ijkl.tensor(0,0,1,2),
                 c_ijkl.tensor(0,0,2,0), c_ijkl.tensor(0,0,2,1), c_ijkl.tensor(0,0,2,2)},  // ij 1,1
                {c_ijkl.tensor(0,1,0,0), c_ijkl.tensor(0,1,0,1), c_ijkl.tensor(0,1,0,2),
                 c_ijkl.tensor(0,1,1,0), c_ijkl.tensor(0,1,1,1), c_ijkl.tensor(0,1,1,2),
                 c_ijkl.tensor(0,1,2,0), c_ijkl.tensor(0,1,2,1), c_ijkl.tensor(0,1,2,2)},  // ij 1,2
                {c_ijkl.tensor(0,2,0,0), c_ijkl.tensor(0,2,0,1), c_ijkl.tensor(0,2,0,2),
                 c_ijkl.tensor(0,2,1,0), c_ijkl.tensor(0,2,1,1), c_ijkl.tensor(0,2,1,2),
                 c_ijkl.tensor(0,2,2,0), c_ijkl.tensor(0,2,2,1), c_ijkl.tensor(0,2,2,2)},  // ij 1,3
                {c_ijkl.tensor(1,0,0,0), c_ijkl.tensor(1,0,0,1), c_ijkl.tensor(1,0,0,2),
                 c_ijkl.tensor(1,0,1,0), c_ijkl.tensor(1,0,1,1), c_ijkl.tensor(1,0,1,2),
                 c_ijkl.tensor(1,0,2,0), c_ijkl.tensor(1,0,2,1), c_ijkl.tensor(1,0,2,2)},  // ij 2,1
                {c_ijkl.tensor(1,1,0,0), c_ijkl.tensor(1,1,0,1), c_ijkl.tensor(1,1,0,2),
                 c_ijkl.tensor(1,1,1,0), c_ijkl.tensor(1,1,1,1), c_ijkl.tensor(1,1,1,2),
                 c_ijkl.tensor(1,1,2,0), c_ijkl.tensor(1,1,2,1), c_ijkl.tensor(1,1,2,2)},  // ij 2,2
                {c_ijkl.tensor(1,2,0,0), c_ijkl.tensor(1,2,0,1), c_ijkl.tensor(1,2,0,2),
                 c_ijkl.tensor(1,2,1,0), c_ijkl.tensor(1,2,1,1), c_ijkl.tensor(1,2,1,2),
                 c_ijkl.tensor(1,2,2,0), c_ijkl.tensor(1,2,2,1), c_ijkl.tensor(1,2,2,2)},  // ij 2,3
                {c_ijkl.tensor(2,0,0,0), c_ijkl.tensor(2,0,0,1), c_ijkl.tensor(2,0,0,2),
                 c_ijkl.tensor(2,0,1,0), c_ijkl.tensor(2,0,1,1), c_ijkl.tensor(2,0,1,2),
                 c_ijkl.tensor(2,0,2,0), c_ijkl.tensor(2,0,2,1), c_ijkl.tensor(2,0,2,2)},  // ij 3,1
                {c_ijkl.tensor(2,1,0,0), c_ijkl.tensor(2,1,0,1), c_ijkl.tensor(2,1,0,2),
                 c_ijkl.tensor(2,1,1,0), c_ijkl.tensor(2,1,1,1), c_ijkl.tensor(2,1,1,2),
                 c_ijkl.tensor(2,1,2,0), c_ijkl.tensor(2,1,2,1), c_ijkl.tensor(2,1,2,2)},  // ij 3,2
                {c_ijkl.tensor(2,2,0,0), c_ijkl.tensor(2,2,0,1), c_ijkl.tensor(2,2,0,2),
                 c_ijkl.tensor(2,2,1,0), c_ijkl.tensor(2,2,1,1), c_ijkl.tensor(2,2,1,2),
                 c_ijkl.tensor(2,2,2,0), c_ijkl.tensor(2,2,2,1), c_ijkl.tensor(2,2,2,2)}   // ij 3,3
        };

        // create data arrays
        QBarDataArray *dataSet = new QBarDataArray;
        QBarDataRow *dataRow;

        dataSet->reserve(9);
        for (int ij = 0; ij < 9; ij++) {
            // Create a data row
            dataRow = new QBarDataRow(9);
            for (int kl = 0; kl < 9; kl++) {
                // Add data to the row
                (*dataRow)[kl].setValue(c_ijkl_data[ij][kl]);
            }
            // Add the row to the set
            dataSet->append(dataRow);
        }

        // Add data to the data proxy (the data proxy assumes ownership of it)
        primary_series->dataProxy()->resetArray(dataSet, ij_list, ij_list);
        break;
    }
    case 6: { // Coesite
        density_line_edit->setText(QString::number(mpc::data::CoesiteDensity<double>()));
        bulk_modulus_line_edit->setText(QString::number(mpc::data::CoesiteBulkModulus<double>()));
        shear_modulus_line_edit->setText(QString::number(mpc::data::CoesiteShearModulus<double>()));
        c11_line_edit->setText(QString::number(mpc::data::CoesiteC11<double>()));
        c12_line_edit->setText(QString::number(mpc::data::CoesiteC12<double>()));
        c13_line_edit->setText(QString::number(mpc::data::CoesiteC13<double>()));
        c14_line_edit->setText(QString::number(mpc::data::CoesiteC14<double>()));
        c15_line_edit->setText(QString::number(mpc::data::CoesiteC15<double>()));
        c16_line_edit->setText(QString::number(mpc::data::CoesiteC16<double>()));
        c22_line_edit->setText(QString::number(mpc::data::CoesiteC22<double>()));
        c23_line_edit->setText(QString::number(mpc::data::CoesiteC23<double>()));
        c24_line_edit->setText(QString::number(mpc::data::CoesiteC24<double>()));
        c25_line_edit->setText(QString::number(mpc::data::CoesiteC25<double>()));
        c26_line_edit->setText(QString::number(mpc::data::CoesiteC26<double>()));
        c33_line_edit->setText(QString::number(mpc::data::CoesiteC33<double>()));
        c34_line_edit->setText(QString::number(mpc::data::CoesiteC34<double>()));
        c35_line_edit->setText(QString::number(mpc::data::CoesiteC35<double>()));
        c36_line_edit->setText(QString::number(mpc::data::CoesiteC36<double>()));
        c44_line_edit->setText(QString::number(mpc::data::CoesiteC44<double>()));
        c45_line_edit->setText(QString::number(mpc::data::CoesiteC45<double>()));
        c46_line_edit->setText(QString::number(mpc::data::CoesiteC46<double>()));
        c55_line_edit->setText(QString::number(mpc::data::CoesiteC55<double>()));
        c56_line_edit->setText(QString::number(mpc::data::CoesiteC56<double>()));
        c66_line_edit->setText(QString::number(mpc::data::CoesiteC66<double>()));
        // data
        mpc::core::StiffnessTensor<float> c_ijkl = mpc::data::CoesiteStiffnessTensor<float>();
        float c_ijkl_data[9][9] = {
                {c_ijkl.tensor(0,0,0,0), c_ijkl.tensor(0,0,0,1), c_ijkl.tensor(0,0,0,2),
                 c_ijkl.tensor(0,0,1,0), c_ijkl.tensor(0,0,1,1), c_ijkl.tensor(0,0,1,2),
                 c_ijkl.tensor(0,0,2,0), c_ijkl.tensor(0,0,2,1), c_ijkl.tensor(0,0,2,2)},  // ij 1,1
                {c_ijkl.tensor(0,1,0,0), c_ijkl.tensor(0,1,0,1), c_ijkl.tensor(0,1,0,2),
                 c_ijkl.tensor(0,1,1,0), c_ijkl.tensor(0,1,1,1), c_ijkl.tensor(0,1,1,2),
                 c_ijkl.tensor(0,1,2,0), c_ijkl.tensor(0,1,2,1), c_ijkl.tensor(0,1,2,2)},  // ij 1,2
                {c_ijkl.tensor(0,2,0,0), c_ijkl.tensor(0,2,0,1), c_ijkl.tensor(0,2,0,2),
                 c_ijkl.tensor(0,2,1,0), c_ijkl.tensor(0,2,1,1), c_ijkl.tensor(0,2,1,2),
                 c_ijkl.tensor(0,2,2,0), c_ijkl.tensor(0,2,2,1), c_ijkl.tensor(0,2,2,2)},  // ij 1,3
                {c_ijkl.tensor(1,0,0,0), c_ijkl.tensor(1,0,0,1), c_ijkl.tensor(1,0,0,2),
                 c_ijkl.tensor(1,0,1,0), c_ijkl.tensor(1,0,1,1), c_ijkl.tensor(1,0,1,2),
                 c_ijkl.tensor(1,0,2,0), c_ijkl.tensor(1,0,2,1), c_ijkl.tensor(1,0,2,2)},  // ij 2,1
                {c_ijkl.tensor(1,1,0,0), c_ijkl.tensor(1,1,0,1), c_ijkl.tensor(1,1,0,2),
                 c_ijkl.tensor(1,1,1,0), c_ijkl.tensor(1,1,1,1), c_ijkl.tensor(1,1,1,2),
                 c_ijkl.tensor(1,1,2,0), c_ijkl.tensor(1,1,2,1), c_ijkl.tensor(1,1,2,2)},  // ij 2,2
                {c_ijkl.tensor(1,2,0,0), c_ijkl.tensor(1,2,0,1), c_ijkl.tensor(1,2,0,2),
                 c_ijkl.tensor(1,2,1,0), c_ijkl.tensor(1,2,1,1), c_ijkl.tensor(1,2,1,2),
                 c_ijkl.tensor(1,2,2,0), c_ijkl.tensor(1,2,2,1), c_ijkl.tensor(1,2,2,2)},  // ij 2,3
                {c_ijkl.tensor(2,0,0,0), c_ijkl.tensor(2,0,0,1), c_ijkl.tensor(2,0,0,2),
                 c_ijkl.tensor(2,0,1,0), c_ijkl.tensor(2,0,1,1), c_ijkl.tensor(2,0,1,2),
                 c_ijkl.tensor(2,0,2,0), c_ijkl.tensor(2,0,2,1), c_ijkl.tensor(2,0,2,2)},  // ij 3,1
                {c_ijkl.tensor(2,1,0,0), c_ijkl.tensor(2,1,0,1), c_ijkl.tensor(2,1,0,2),
                 c_ijkl.tensor(2,1,1,0), c_ijkl.tensor(2,1,1,1), c_ijkl.tensor(2,1,1,2),
                 c_ijkl.tensor(2,1,2,0), c_ijkl.tensor(2,1,2,1), c_ijkl.tensor(2,1,2,2)},  // ij 3,2
                {c_ijkl.tensor(2,2,0,0), c_ijkl.tensor(2,2,0,1), c_ijkl.tensor(2,2,0,2),
                 c_ijkl.tensor(2,2,1,0), c_ijkl.tensor(2,2,1,1), c_ijkl.tensor(2,2,1,2),
                 c_ijkl.tensor(2,2,2,0), c_ijkl.tensor(2,2,2,1), c_ijkl.tensor(2,2,2,2)}   // ij 3,3
        };

        // create data arrays
        QBarDataArray *dataSet = new QBarDataArray;
        QBarDataRow *dataRow;

        dataSet->reserve(9);
        for (int ij = 0; ij < 9; ij++) {
            // Create a data row
            dataRow = new QBarDataRow(9);
            for (int kl = 0; kl < 9; kl++) {
                // Add data to the row
                (*dataRow)[kl].setValue(c_ijkl_data[ij][kl]);
            }
            // Add the row to the set
            dataSet->append(dataRow);
        }

        // Add data to the data proxy (the data proxy assumes ownership of it)
        primary_series->dataProxy()->resetArray(dataSet, ij_list, ij_list);
        break;
    }
    case 7: { // Epidote
        density_line_edit->setText(QString::number(mpc::data::EpidoteDensity<double>()));
        bulk_modulus_line_edit->setText(QString::number(mpc::data::EpidoteBulkModulus<double>()));
        shear_modulus_line_edit->setText(QString::number(mpc::data::EpidoteShearModulus<double>()));
        c11_line_edit->setText(QString::number(mpc::data::EpidoteC11<double>()));
        c12_line_edit->setText(QString::number(mpc::data::EpidoteC12<double>()));
        c13_line_edit->setText(QString::number(mpc::data::EpidoteC13<double>()));
        c14_line_edit->setText(QString::number(mpc::data::EpidoteC14<double>()));
        c15_line_edit->setText(QString::number(mpc::data::EpidoteC15<double>()));
        c16_line_edit->setText(QString::number(mpc::data::EpidoteC16<double>()));
        c22_line_edit->setText(QString::number(mpc::data::EpidoteC22<double>()));
        c23_line_edit->setText(QString::number(mpc::data::EpidoteC23<double>()));
        c24_line_edit->setText(QString::number(mpc::data::EpidoteC24<double>()));
        c25_line_edit->setText(QString::number(mpc::data::EpidoteC25<double>()));
        c26_line_edit->setText(QString::number(mpc::data::EpidoteC26<double>()));
        c33_line_edit->setText(QString::number(mpc::data::EpidoteC33<double>()));
        c34_line_edit->setText(QString::number(mpc::data::EpidoteC34<double>()));
        c35_line_edit->setText(QString::number(mpc::data::EpidoteC35<double>()));
        c36_line_edit->setText(QString::number(mpc::data::EpidoteC36<double>()));
        c44_line_edit->setText(QString::number(mpc::data::EpidoteC44<double>()));
        c45_line_edit->setText(QString::number(mpc::data::EpidoteC45<double>()));
        c46_line_edit->setText(QString::number(mpc::data::EpidoteC46<double>()));
        c55_line_edit->setText(QString::number(mpc::data::EpidoteC55<double>()));
        c56_line_edit->setText(QString::number(mpc::data::EpidoteC56<double>()));
        c66_line_edit->setText(QString::number(mpc::data::EpidoteC66<double>()));
        // data
        mpc::core::StiffnessTensor<float> c_ijkl = mpc::data::EpidoteStiffnessTensor<float>();
        float c_ijkl_data[9][9] = {
                {c_ijkl.tensor(0,0,0,0), c_ijkl.tensor(0,0,0,1), c_ijkl.tensor(0,0,0,2),
                 c_ijkl.tensor(0,0,1,0), c_ijkl.tensor(0,0,1,1), c_ijkl.tensor(0,0,1,2),
                 c_ijkl.tensor(0,0,2,0), c_ijkl.tensor(0,0,2,1), c_ijkl.tensor(0,0,2,2)},  // ij 1,1
                {c_ijkl.tensor(0,1,0,0), c_ijkl.tensor(0,1,0,1), c_ijkl.tensor(0,1,0,2),
                 c_ijkl.tensor(0,1,1,0), c_ijkl.tensor(0,1,1,1), c_ijkl.tensor(0,1,1,2),
                 c_ijkl.tensor(0,1,2,0), c_ijkl.tensor(0,1,2,1), c_ijkl.tensor(0,1,2,2)},  // ij 1,2
                {c_ijkl.tensor(0,2,0,0), c_ijkl.tensor(0,2,0,1), c_ijkl.tensor(0,2,0,2),
                 c_ijkl.tensor(0,2,1,0), c_ijkl.tensor(0,2,1,1), c_ijkl.tensor(0,2,1,2),
                 c_ijkl.tensor(0,2,2,0), c_ijkl.tensor(0,2,2,1), c_ijkl.tensor(0,2,2,2)},  // ij 1,3
                {c_ijkl.tensor(1,0,0,0), c_ijkl.tensor(1,0,0,1), c_ijkl.tensor(1,0,0,2),
                 c_ijkl.tensor(1,0,1,0), c_ijkl.tensor(1,0,1,1), c_ijkl.tensor(1,0,1,2),
                 c_ijkl.tensor(1,0,2,0), c_ijkl.tensor(1,0,2,1), c_ijkl.tensor(1,0,2,2)},  // ij 2,1
                {c_ijkl.tensor(1,1,0,0), c_ijkl.tensor(1,1,0,1), c_ijkl.tensor(1,1,0,2),
                 c_ijkl.tensor(1,1,1,0), c_ijkl.tensor(1,1,1,1), c_ijkl.tensor(1,1,1,2),
                 c_ijkl.tensor(1,1,2,0), c_ijkl.tensor(1,1,2,1), c_ijkl.tensor(1,1,2,2)},  // ij 2,2
                {c_ijkl.tensor(1,2,0,0), c_ijkl.tensor(1,2,0,1), c_ijkl.tensor(1,2,0,2),
                 c_ijkl.tensor(1,2,1,0), c_ijkl.tensor(1,2,1,1), c_ijkl.tensor(1,2,1,2),
                 c_ijkl.tensor(1,2,2,0), c_ijkl.tensor(1,2,2,1), c_ijkl.tensor(1,2,2,2)},  // ij 2,3
                {c_ijkl.tensor(2,0,0,0), c_ijkl.tensor(2,0,0,1), c_ijkl.tensor(2,0,0,2),
                 c_ijkl.tensor(2,0,1,0), c_ijkl.tensor(2,0,1,1), c_ijkl.tensor(2,0,1,2),
                 c_ijkl.tensor(2,0,2,0), c_ijkl.tensor(2,0,2,1), c_ijkl.tensor(2,0,2,2)},  // ij 3,1
                {c_ijkl.tensor(2,1,0,0), c_ijkl.tensor(2,1,0,1), c_ijkl.tensor(2,1,0,2),
                 c_ijkl.tensor(2,1,1,0), c_ijkl.tensor(2,1,1,1), c_ijkl.tensor(2,1,1,2),
                 c_ijkl.tensor(2,1,2,0), c_ijkl.tensor(2,1,2,1), c_ijkl.tensor(2,1,2,2)},  // ij 3,2
                {c_ijkl.tensor(2,2,0,0), c_ijkl.tensor(2,2,0,1), c_ijkl.tensor(2,2,0,2),
                 c_ijkl.tensor(2,2,1,0), c_ijkl.tensor(2,2,1,1), c_ijkl.tensor(2,2,1,2),
                 c_ijkl.tensor(2,2,2,0), c_ijkl.tensor(2,2,2,1), c_ijkl.tensor(2,2,2,2)}   // ij 3,3
        };

        // create data arrays
        QBarDataArray *dataSet = new QBarDataArray;
        QBarDataRow *dataRow;

        dataSet->reserve(9);
        for (int ij = 0; ij < 9; ij++) {
            // Create a data row
            dataRow = new QBarDataRow(9);
            for (int kl = 0; kl < 9; kl++) {
                // Add data to the row
                (*dataRow)[kl].setValue(c_ijkl_data[ij][kl]);
            }
            // Add the row to the set
            dataSet->append(dataRow);
        }

        // Add data to the data proxy (the data proxy assumes ownership of it)
        primary_series->dataProxy()->resetArray(dataSet, ij_list, ij_list);
        break;
    }
    case 8: { // Hornblende
        density_line_edit->setText(QString::number(mpc::data::HornblendeDensity<double>()));
        bulk_modulus_line_edit->setText(QString::number(mpc::data::HornblendeBulkModulus<double>()));
        shear_modulus_line_edit->setText(QString::number(mpc::data::HornblendeShearModulus<double>()));
        c11_line_edit->setText(QString::number(mpc::data::HornblendeC11<double>()));
        c12_line_edit->setText(QString::number(mpc::data::HornblendeC12<double>()));
        c13_line_edit->setText(QString::number(mpc::data::HornblendeC13<double>()));
        c14_line_edit->setText(QString::number(mpc::data::HornblendeC14<double>()));
        c15_line_edit->setText(QString::number(mpc::data::HornblendeC15<double>()));
        c16_line_edit->setText(QString::number(mpc::data::HornblendeC16<double>()));
        c22_line_edit->setText(QString::number(mpc::data::HornblendeC22<double>()));
        c23_line_edit->setText(QString::number(mpc::data::HornblendeC23<double>()));
        c24_line_edit->setText(QString::number(mpc::data::HornblendeC24<double>()));
        c25_line_edit->setText(QString::number(mpc::data::HornblendeC25<double>()));
        c26_line_edit->setText(QString::number(mpc::data::HornblendeC26<double>()));
        c33_line_edit->setText(QString::number(mpc::data::HornblendeC33<double>()));
        c34_line_edit->setText(QString::number(mpc::data::HornblendeC34<double>()));
        c35_line_edit->setText(QString::number(mpc::data::HornblendeC35<double>()));
        c36_line_edit->setText(QString::number(mpc::data::HornblendeC36<double>()));
        c44_line_edit->setText(QString::number(mpc::data::HornblendeC44<double>()));
        c45_line_edit->setText(QString::number(mpc::data::HornblendeC45<double>()));
        c46_line_edit->setText(QString::number(mpc::data::HornblendeC46<double>()));
        c55_line_edit->setText(QString::number(mpc::data::HornblendeC55<double>()));
        c56_line_edit->setText(QString::number(mpc::data::HornblendeC56<double>()));
        c66_line_edit->setText(QString::number(mpc::data::HornblendeC66<double>()));
        // data
        mpc::core::StiffnessTensor<float> c_ijkl = mpc::data::HornblendeStiffnessTensor<float>();
        float c_ijkl_data[9][9] = {
                {c_ijkl.tensor(0,0,0,0), c_ijkl.tensor(0,0,0,1), c_ijkl.tensor(0,0,0,2),
                 c_ijkl.tensor(0,0,1,0), c_ijkl.tensor(0,0,1,1), c_ijkl.tensor(0,0,1,2),
                 c_ijkl.tensor(0,0,2,0), c_ijkl.tensor(0,0,2,1), c_ijkl.tensor(0,0,2,2)},  // ij 1,1
                {c_ijkl.tensor(0,1,0,0), c_ijkl.tensor(0,1,0,1), c_ijkl.tensor(0,1,0,2),
                 c_ijkl.tensor(0,1,1,0), c_ijkl.tensor(0,1,1,1), c_ijkl.tensor(0,1,1,2),
                 c_ijkl.tensor(0,1,2,0), c_ijkl.tensor(0,1,2,1), c_ijkl.tensor(0,1,2,2)},  // ij 1,2
                {c_ijkl.tensor(0,2,0,0), c_ijkl.tensor(0,2,0,1), c_ijkl.tensor(0,2,0,2),
                 c_ijkl.tensor(0,2,1,0), c_ijkl.tensor(0,2,1,1), c_ijkl.tensor(0,2,1,2),
                 c_ijkl.tensor(0,2,2,0), c_ijkl.tensor(0,2,2,1), c_ijkl.tensor(0,2,2,2)},  // ij 1,3
                {c_ijkl.tensor(1,0,0,0), c_ijkl.tensor(1,0,0,1), c_ijkl.tensor(1,0,0,2),
                 c_ijkl.tensor(1,0,1,0), c_ijkl.tensor(1,0,1,1), c_ijkl.tensor(1,0,1,2),
                 c_ijkl.tensor(1,0,2,0), c_ijkl.tensor(1,0,2,1), c_ijkl.tensor(1,0,2,2)},  // ij 2,1
                {c_ijkl.tensor(1,1,0,0), c_ijkl.tensor(1,1,0,1), c_ijkl.tensor(1,1,0,2),
                 c_ijkl.tensor(1,1,1,0), c_ijkl.tensor(1,1,1,1), c_ijkl.tensor(1,1,1,2),
                 c_ijkl.tensor(1,1,2,0), c_ijkl.tensor(1,1,2,1), c_ijkl.tensor(1,1,2,2)},  // ij 2,2
                {c_ijkl.tensor(1,2,0,0), c_ijkl.tensor(1,2,0,1), c_ijkl.tensor(1,2,0,2),
                 c_ijkl.tensor(1,2,1,0), c_ijkl.tensor(1,2,1,1), c_ijkl.tensor(1,2,1,2),
                 c_ijkl.tensor(1,2,2,0), c_ijkl.tensor(1,2,2,1), c_ijkl.tensor(1,2,2,2)},  // ij 2,3
                {c_ijkl.tensor(2,0,0,0), c_ijkl.tensor(2,0,0,1), c_ijkl.tensor(2,0,0,2),
                 c_ijkl.tensor(2,0,1,0), c_ijkl.tensor(2,0,1,1), c_ijkl.tensor(2,0,1,2),
                 c_ijkl.tensor(2,0,2,0), c_ijkl.tensor(2,0,2,1), c_ijkl.tensor(2,0,2,2)},  // ij 3,1
                {c_ijkl.tensor(2,1,0,0), c_ijkl.tensor(2,1,0,1), c_ijkl.tensor(2,1,0,2),
                 c_ijkl.tensor(2,1,1,0), c_ijkl.tensor(2,1,1,1), c_ijkl.tensor(2,1,1,2),
                 c_ijkl.tensor(2,1,2,0), c_ijkl.tensor(2,1,2,1), c_ijkl.tensor(2,1,2,2)},  // ij 3,2
                {c_ijkl.tensor(2,2,0,0), c_ijkl.tensor(2,2,0,1), c_ijkl.tensor(2,2,0,2),
                 c_ijkl.tensor(2,2,1,0), c_ijkl.tensor(2,2,1,1), c_ijkl.tensor(2,2,1,2),
                 c_ijkl.tensor(2,2,2,0), c_ijkl.tensor(2,2,2,1), c_ijkl.tensor(2,2,2,2)}   // ij 3,3
        };

        // create data arrays
        QBarDataArray *dataSet = new QBarDataArray;
        QBarDataRow *dataRow;

        dataSet->reserve(9);
        for (int ij = 0; ij < 9; ij++) {
            // Create a data row
            dataRow = new QBarDataRow(9);
            for (int kl = 0; kl < 9; kl++) {
                // Add data to the row
                (*dataRow)[kl].setValue(c_ijkl_data[ij][kl]);
            }
            // Add the row to the set
            dataSet->append(dataRow);
        }

        // Add data to the data proxy (the data proxy assumes ownership of it)
        primary_series->dataProxy()->resetArray(dataSet, ij_list, ij_list);
        break;
    }
    case 9: { // Muscovite
        density_line_edit->setText(QString::number(mpc::data::MuscoviteDensity<double>()));
        bulk_modulus_line_edit->setText(QString::number(mpc::data::MuscoviteBulkModulus<double>()));
        shear_modulus_line_edit->setText(QString::number(mpc::data::MuscoviteShearModulus<double>()));
        c11_line_edit->setText(QString::number(mpc::data::MuscoviteC11<double>()));
        c12_line_edit->setText(QString::number(mpc::data::MuscoviteC12<double>()));
        c13_line_edit->setText(QString::number(mpc::data::MuscoviteC13<double>()));
        c14_line_edit->setText(QString::number(mpc::data::MuscoviteC14<double>()));
        c15_line_edit->setText(QString::number(mpc::data::MuscoviteC15<double>()));
        c16_line_edit->setText(QString::number(mpc::data::MuscoviteC16<double>()));
        c22_line_edit->setText(QString::number(mpc::data::MuscoviteC22<double>()));
        c23_line_edit->setText(QString::number(mpc::data::MuscoviteC23<double>()));
        c24_line_edit->setText(QString::number(mpc::data::MuscoviteC24<double>()));
        c25_line_edit->setText(QString::number(mpc::data::MuscoviteC25<double>()));
        c26_line_edit->setText(QString::number(mpc::data::MuscoviteC26<double>()));
        c33_line_edit->setText(QString::number(mpc::data::MuscoviteC33<double>()));
        c34_line_edit->setText(QString::number(mpc::data::MuscoviteC34<double>()));
        c35_line_edit->setText(QString::number(mpc::data::MuscoviteC35<double>()));
        c36_line_edit->setText(QString::number(mpc::data::MuscoviteC36<double>()));
        c44_line_edit->setText(QString::number(mpc::data::MuscoviteC44<double>()));
        c45_line_edit->setText(QString::number(mpc::data::MuscoviteC45<double>()));
        c46_line_edit->setText(QString::number(mpc::data::MuscoviteC46<double>()));
        c55_line_edit->setText(QString::number(mpc::data::MuscoviteC55<double>()));
        c56_line_edit->setText(QString::number(mpc::data::MuscoviteC56<double>()));
        c66_line_edit->setText(QString::number(mpc::data::MuscoviteC66<double>()));
        // data
        mpc::core::StiffnessTensor<float> c_ijkl = mpc::data::MuscoviteStiffnessTensor<float>();
        float c_ijkl_data[9][9] = {
                {c_ijkl.tensor(0,0,0,0), c_ijkl.tensor(0,0,0,1), c_ijkl.tensor(0,0,0,2),
                 c_ijkl.tensor(0,0,1,0), c_ijkl.tensor(0,0,1,1), c_ijkl.tensor(0,0,1,2),
                 c_ijkl.tensor(0,0,2,0), c_ijkl.tensor(0,0,2,1), c_ijkl.tensor(0,0,2,2)},  // ij 1,1
                {c_ijkl.tensor(0,1,0,0), c_ijkl.tensor(0,1,0,1), c_ijkl.tensor(0,1,0,2),
                 c_ijkl.tensor(0,1,1,0), c_ijkl.tensor(0,1,1,1), c_ijkl.tensor(0,1,1,2),
                 c_ijkl.tensor(0,1,2,0), c_ijkl.tensor(0,1,2,1), c_ijkl.tensor(0,1,2,2)},  // ij 1,2
                {c_ijkl.tensor(0,2,0,0), c_ijkl.tensor(0,2,0,1), c_ijkl.tensor(0,2,0,2),
                 c_ijkl.tensor(0,2,1,0), c_ijkl.tensor(0,2,1,1), c_ijkl.tensor(0,2,1,2),
                 c_ijkl.tensor(0,2,2,0), c_ijkl.tensor(0,2,2,1), c_ijkl.tensor(0,2,2,2)},  // ij 1,3
                {c_ijkl.tensor(1,0,0,0), c_ijkl.tensor(1,0,0,1), c_ijkl.tensor(1,0,0,2),
                 c_ijkl.tensor(1,0,1,0), c_ijkl.tensor(1,0,1,1), c_ijkl.tensor(1,0,1,2),
                 c_ijkl.tensor(1,0,2,0), c_ijkl.tensor(1,0,2,1), c_ijkl.tensor(1,0,2,2)},  // ij 2,1
                {c_ijkl.tensor(1,1,0,0), c_ijkl.tensor(1,1,0,1), c_ijkl.tensor(1,1,0,2),
                 c_ijkl.tensor(1,1,1,0), c_ijkl.tensor(1,1,1,1), c_ijkl.tensor(1,1,1,2),
                 c_ijkl.tensor(1,1,2,0), c_ijkl.tensor(1,1,2,1), c_ijkl.tensor(1,1,2,2)},  // ij 2,2
                {c_ijkl.tensor(1,2,0,0), c_ijkl.tensor(1,2,0,1), c_ijkl.tensor(1,2,0,2),
                 c_ijkl.tensor(1,2,1,0), c_ijkl.tensor(1,2,1,1), c_ijkl.tensor(1,2,1,2),
                 c_ijkl.tensor(1,2,2,0), c_ijkl.tensor(1,2,2,1), c_ijkl.tensor(1,2,2,2)},  // ij 2,3
                {c_ijkl.tensor(2,0,0,0), c_ijkl.tensor(2,0,0,1), c_ijkl.tensor(2,0,0,2),
                 c_ijkl.tensor(2,0,1,0), c_ijkl.tensor(2,0,1,1), c_ijkl.tensor(2,0,1,2),
                 c_ijkl.tensor(2,0,2,0), c_ijkl.tensor(2,0,2,1), c_ijkl.tensor(2,0,2,2)},  // ij 3,1
                {c_ijkl.tensor(2,1,0,0), c_ijkl.tensor(2,1,0,1), c_ijkl.tensor(2,1,0,2),
                 c_ijkl.tensor(2,1,1,0), c_ijkl.tensor(2,1,1,1), c_ijkl.tensor(2,1,1,2),
                 c_ijkl.tensor(2,1,2,0), c_ijkl.tensor(2,1,2,1), c_ijkl.tensor(2,1,2,2)},  // ij 3,2
                {c_ijkl.tensor(2,2,0,0), c_ijkl.tensor(2,2,0,1), c_ijkl.tensor(2,2,0,2),
                 c_ijkl.tensor(2,2,1,0), c_ijkl.tensor(2,2,1,1), c_ijkl.tensor(2,2,1,2),
                 c_ijkl.tensor(2,2,2,0), c_ijkl.tensor(2,2,2,1), c_ijkl.tensor(2,2,2,2)}   // ij 3,3
        };

        // create data arrays
        QBarDataArray *dataSet = new QBarDataArray;
        QBarDataRow *dataRow;

        dataSet->reserve(9);
        for (int ij = 0; ij < 9; ij++) {
            // Create a data row
            dataRow = new QBarDataRow(9);
            for (int kl = 0; kl < 9; kl++) {
                // Add data to the row
                (*dataRow)[kl].setValue(c_ijkl_data[ij][kl]);
            }
            // Add the row to the set
            dataSet->append(dataRow);
        }

        // Add data to the data proxy (the data proxy assumes ownership of it)
        primary_series->dataProxy()->resetArray(dataSet, ij_list, ij_list);
        break;
    }
    case 10: { // Gypsum
        density_line_edit->setText(QString::number(mpc::data::GypsumDensity<double>()));
        bulk_modulus_line_edit->setText(QString::number(mpc::data::GypsumBulkModulus<double>()));
        shear_modulus_line_edit->setText(QString::number(mpc::data::GypsumShearModulus<double>()));
        c11_line_edit->setText(QString::number(mpc::data::GypsumC11<double>()));
        c12_line_edit->setText(QString::number(mpc::data::GypsumC12<double>()));
        c13_line_edit->setText(QString::number(mpc::data::GypsumC13<double>()));
        c14_line_edit->setText(QString::number(mpc::data::GypsumC14<double>()));
        c15_line_edit->setText(QString::number(mpc::data::GypsumC15<double>()));
        c16_line_edit->setText(QString::number(mpc::data::GypsumC16<double>()));
        c22_line_edit->setText(QString::number(mpc::data::GypsumC22<double>()));
        c23_line_edit->setText(QString::number(mpc::data::GypsumC23<double>()));
        c24_line_edit->setText(QString::number(mpc::data::GypsumC24<double>()));
        c25_line_edit->setText(QString::number(mpc::data::GypsumC25<double>()));
        c26_line_edit->setText(QString::number(mpc::data::GypsumC26<double>()));
        c33_line_edit->setText(QString::number(mpc::data::GypsumC33<double>()));
        c34_line_edit->setText(QString::number(mpc::data::GypsumC34<double>()));
        c35_line_edit->setText(QString::number(mpc::data::GypsumC35<double>()));
        c36_line_edit->setText(QString::number(mpc::data::GypsumC36<double>()));
        c44_line_edit->setText(QString::number(mpc::data::GypsumC44<double>()));
        c45_line_edit->setText(QString::number(mpc::data::GypsumC45<double>()));
        c46_line_edit->setText(QString::number(mpc::data::GypsumC46<double>()));
        c55_line_edit->setText(QString::number(mpc::data::GypsumC55<double>()));
        c56_line_edit->setText(QString::number(mpc::data::GypsumC56<double>()));
        c66_line_edit->setText(QString::number(mpc::data::GypsumC66<double>()));
        // data
        mpc::core::StiffnessTensor<float> c_ijkl = mpc::data::GypsumStiffnessTensor<float>();
        float c_ijkl_data[9][9] = {
                {c_ijkl.tensor(0,0,0,0), c_ijkl.tensor(0,0,0,1), c_ijkl.tensor(0,0,0,2),
                 c_ijkl.tensor(0,0,1,0), c_ijkl.tensor(0,0,1,1), c_ijkl.tensor(0,0,1,2),
                 c_ijkl.tensor(0,0,2,0), c_ijkl.tensor(0,0,2,1), c_ijkl.tensor(0,0,2,2)},  // ij 1,1
                {c_ijkl.tensor(0,1,0,0), c_ijkl.tensor(0,1,0,1), c_ijkl.tensor(0,1,0,2),
                 c_ijkl.tensor(0,1,1,0), c_ijkl.tensor(0,1,1,1), c_ijkl.tensor(0,1,1,2),
                 c_ijkl.tensor(0,1,2,0), c_ijkl.tensor(0,1,2,1), c_ijkl.tensor(0,1,2,2)},  // ij 1,2
                {c_ijkl.tensor(0,2,0,0), c_ijkl.tensor(0,2,0,1), c_ijkl.tensor(0,2,0,2),
                 c_ijkl.tensor(0,2,1,0), c_ijkl.tensor(0,2,1,1), c_ijkl.tensor(0,2,1,2),
                 c_ijkl.tensor(0,2,2,0), c_ijkl.tensor(0,2,2,1), c_ijkl.tensor(0,2,2,2)},  // ij 1,3
                {c_ijkl.tensor(1,0,0,0), c_ijkl.tensor(1,0,0,1), c_ijkl.tensor(1,0,0,2),
                 c_ijkl.tensor(1,0,1,0), c_ijkl.tensor(1,0,1,1), c_ijkl.tensor(1,0,1,2),
                 c_ijkl.tensor(1,0,2,0), c_ijkl.tensor(1,0,2,1), c_ijkl.tensor(1,0,2,2)},  // ij 2,1
                {c_ijkl.tensor(1,1,0,0), c_ijkl.tensor(1,1,0,1), c_ijkl.tensor(1,1,0,2),
                 c_ijkl.tensor(1,1,1,0), c_ijkl.tensor(1,1,1,1), c_ijkl.tensor(1,1,1,2),
                 c_ijkl.tensor(1,1,2,0), c_ijkl.tensor(1,1,2,1), c_ijkl.tensor(1,1,2,2)},  // ij 2,2
                {c_ijkl.tensor(1,2,0,0), c_ijkl.tensor(1,2,0,1), c_ijkl.tensor(1,2,0,2),
                 c_ijkl.tensor(1,2,1,0), c_ijkl.tensor(1,2,1,1), c_ijkl.tensor(1,2,1,2),
                 c_ijkl.tensor(1,2,2,0), c_ijkl.tensor(1,2,2,1), c_ijkl.tensor(1,2,2,2)},  // ij 2,3
                {c_ijkl.tensor(2,0,0,0), c_ijkl.tensor(2,0,0,1), c_ijkl.tensor(2,0,0,2),
                 c_ijkl.tensor(2,0,1,0), c_ijkl.tensor(2,0,1,1), c_ijkl.tensor(2,0,1,2),
                 c_ijkl.tensor(2,0,2,0), c_ijkl.tensor(2,0,2,1), c_ijkl.tensor(2,0,2,2)},  // ij 3,1
                {c_ijkl.tensor(2,1,0,0), c_ijkl.tensor(2,1,0,1), c_ijkl.tensor(2,1,0,2),
                 c_ijkl.tensor(2,1,1,0), c_ijkl.tensor(2,1,1,1), c_ijkl.tensor(2,1,1,2),
                 c_ijkl.tensor(2,1,2,0), c_ijkl.tensor(2,1,2,1), c_ijkl.tensor(2,1,2,2)},  // ij 3,2
                {c_ijkl.tensor(2,2,0,0), c_ijkl.tensor(2,2,0,1), c_ijkl.tensor(2,2,0,2),
                 c_ijkl.tensor(2,2,1,0), c_ijkl.tensor(2,2,1,1), c_ijkl.tensor(2,2,1,2),
                 c_ijkl.tensor(2,2,2,0), c_ijkl.tensor(2,2,2,1), c_ijkl.tensor(2,2,2,2)}   // ij 3,3
        };

        // create data arrays
        QBarDataArray *dataSet = new QBarDataArray;
        QBarDataRow *dataRow;

        dataSet->reserve(9);
        for (int ij = 0; ij < 9; ij++) {
            // Create a data row
            dataRow = new QBarDataRow(9);
            for (int kl = 0; kl < 9; kl++) {
                // Add data to the row
                (*dataRow)[kl].setValue(c_ijkl_data[ij][kl]);
            }
            // Add the row to the set
            dataSet->append(dataRow);
        }

        // Add data to the data proxy (the data proxy assumes ownership of it)
        primary_series->dataProxy()->resetArray(dataSet, ij_list, ij_list);
        break;
    }
    case 11: { // Enstatite
        density_line_edit->setText(QString::number(mpc::data::EnstatiteDensity<double>()));
        bulk_modulus_line_edit->setText(QString::number(mpc::data::EnstatiteBulkModulus<double>()));
        shear_modulus_line_edit->setText(QString::number(mpc::data::EnstatiteShearModulus<double>()));
        c11_line_edit->setText(QString::number(mpc::data::EnstatiteC11<double>()));
        c12_line_edit->setText(QString::number(mpc::data::EnstatiteC12<double>()));
        c13_line_edit->setText(QString::number(mpc::data::EnstatiteC13<double>()));
        c14_line_edit->setText(QString::number(mpc::data::EnstatiteC14<double>()));
        c15_line_edit->setText(QString::number(mpc::data::EnstatiteC15<double>()));
        c16_line_edit->setText(QString::number(mpc::data::EnstatiteC16<double>()));
        c22_line_edit->setText(QString::number(mpc::data::EnstatiteC22<double>()));
        c23_line_edit->setText(QString::number(mpc::data::EnstatiteC23<double>()));
        c24_line_edit->setText(QString::number(mpc::data::EnstatiteC24<double>()));
        c25_line_edit->setText(QString::number(mpc::data::EnstatiteC25<double>()));
        c26_line_edit->setText(QString::number(mpc::data::EnstatiteC26<double>()));
        c33_line_edit->setText(QString::number(mpc::data::EnstatiteC33<double>()));
        c34_line_edit->setText(QString::number(mpc::data::EnstatiteC34<double>()));
        c35_line_edit->setText(QString::number(mpc::data::EnstatiteC35<double>()));
        c36_line_edit->setText(QString::number(mpc::data::EnstatiteC36<double>()));
        c44_line_edit->setText(QString::number(mpc::data::EnstatiteC44<double>()));
        c45_line_edit->setText(QString::number(mpc::data::EnstatiteC45<double>()));
        c46_line_edit->setText(QString::number(mpc::data::EnstatiteC46<double>()));
        c55_line_edit->setText(QString::number(mpc::data::EnstatiteC55<double>()));
        c56_line_edit->setText(QString::number(mpc::data::EnstatiteC56<double>()));
        c66_line_edit->setText(QString::number(mpc::data::EnstatiteC66<double>()));
        // data
        mpc::core::StiffnessTensor<float> c_ijkl = mpc::data::EnstatiteStiffnessTensor<float>();
        float c_ijkl_data[9][9] = {
                {c_ijkl.tensor(0,0,0,0), c_ijkl.tensor(0,0,0,1), c_ijkl.tensor(0,0,0,2),
                 c_ijkl.tensor(0,0,1,0), c_ijkl.tensor(0,0,1,1), c_ijkl.tensor(0,0,1,2),
                 c_ijkl.tensor(0,0,2,0), c_ijkl.tensor(0,0,2,1), c_ijkl.tensor(0,0,2,2)},  // ij 1,1
                {c_ijkl.tensor(0,1,0,0), c_ijkl.tensor(0,1,0,1), c_ijkl.tensor(0,1,0,2),
                 c_ijkl.tensor(0,1,1,0), c_ijkl.tensor(0,1,1,1), c_ijkl.tensor(0,1,1,2),
                 c_ijkl.tensor(0,1,2,0), c_ijkl.tensor(0,1,2,1), c_ijkl.tensor(0,1,2,2)},  // ij 1,2
                {c_ijkl.tensor(0,2,0,0), c_ijkl.tensor(0,2,0,1), c_ijkl.tensor(0,2,0,2),
                 c_ijkl.tensor(0,2,1,0), c_ijkl.tensor(0,2,1,1), c_ijkl.tensor(0,2,1,2),
                 c_ijkl.tensor(0,2,2,0), c_ijkl.tensor(0,2,2,1), c_ijkl.tensor(0,2,2,2)},  // ij 1,3
                {c_ijkl.tensor(1,0,0,0), c_ijkl.tensor(1,0,0,1), c_ijkl.tensor(1,0,0,2),
                 c_ijkl.tensor(1,0,1,0), c_ijkl.tensor(1,0,1,1), c_ijkl.tensor(1,0,1,2),
                 c_ijkl.tensor(1,0,2,0), c_ijkl.tensor(1,0,2,1), c_ijkl.tensor(1,0,2,2)},  // ij 2,1
                {c_ijkl.tensor(1,1,0,0), c_ijkl.tensor(1,1,0,1), c_ijkl.tensor(1,1,0,2),
                 c_ijkl.tensor(1,1,1,0), c_ijkl.tensor(1,1,1,1), c_ijkl.tensor(1,1,1,2),
                 c_ijkl.tensor(1,1,2,0), c_ijkl.tensor(1,1,2,1), c_ijkl.tensor(1,1,2,2)},  // ij 2,2
                {c_ijkl.tensor(1,2,0,0), c_ijkl.tensor(1,2,0,1), c_ijkl.tensor(1,2,0,2),
                 c_ijkl.tensor(1,2,1,0), c_ijkl.tensor(1,2,1,1), c_ijkl.tensor(1,2,1,2),
                 c_ijkl.tensor(1,2,2,0), c_ijkl.tensor(1,2,2,1), c_ijkl.tensor(1,2,2,2)},  // ij 2,3
                {c_ijkl.tensor(2,0,0,0), c_ijkl.tensor(2,0,0,1), c_ijkl.tensor(2,0,0,2),
                 c_ijkl.tensor(2,0,1,0), c_ijkl.tensor(2,0,1,1), c_ijkl.tensor(2,0,1,2),
                 c_ijkl.tensor(2,0,2,0), c_ijkl.tensor(2,0,2,1), c_ijkl.tensor(2,0,2,2)},  // ij 3,1
                {c_ijkl.tensor(2,1,0,0), c_ijkl.tensor(2,1,0,1), c_ijkl.tensor(2,1,0,2),
                 c_ijkl.tensor(2,1,1,0), c_ijkl.tensor(2,1,1,1), c_ijkl.tensor(2,1,1,2),
                 c_ijkl.tensor(2,1,2,0), c_ijkl.tensor(2,1,2,1), c_ijkl.tensor(2,1,2,2)},  // ij 3,2
                {c_ijkl.tensor(2,2,0,0), c_ijkl.tensor(2,2,0,1), c_ijkl.tensor(2,2,0,2),
                 c_ijkl.tensor(2,2,1,0), c_ijkl.tensor(2,2,1,1), c_ijkl.tensor(2,2,1,2),
                 c_ijkl.tensor(2,2,2,0), c_ijkl.tensor(2,2,2,1), c_ijkl.tensor(2,2,2,2)}   // ij 3,3
        };

        // create data arrays
        QBarDataArray *dataSet = new QBarDataArray;
        QBarDataRow *dataRow;

        dataSet->reserve(9);
        for (int ij = 0; ij < 9; ij++) {
            // Create a data row
            dataRow = new QBarDataRow(9);
            for (int kl = 0; kl < 9; kl++) {
                // Add data to the row
                (*dataRow)[kl].setValue(c_ijkl_data[ij][kl]);
            }
            // Add the row to the set
            dataSet->append(dataRow);
        }

        // Add data to the data proxy (the data proxy assumes ownership of it)
        primary_series->dataProxy()->resetArray(dataSet, ij_list, ij_list);
        break;
    }
    case 12: { // Forsterite
        density_line_edit->setText(QString::number(mpc::data::ForsteriteDensity<double>()));
        bulk_modulus_line_edit->setText(QString::number(mpc::data::ForsteriteBulkModulus<double>()));
        shear_modulus_line_edit->setText(QString::number(mpc::data::ForsteriteShearModulus<double>()));
        c11_line_edit->setText(QString::number(mpc::data::ForsteriteC11<double>()));
        c12_line_edit->setText(QString::number(mpc::data::ForsteriteC12<double>()));
        c13_line_edit->setText(QString::number(mpc::data::ForsteriteC13<double>()));
        c14_line_edit->setText(QString::number(mpc::data::ForsteriteC14<double>()));
        c15_line_edit->setText(QString::number(mpc::data::ForsteriteC15<double>()));
        c16_line_edit->setText(QString::number(mpc::data::ForsteriteC16<double>()));
        c22_line_edit->setText(QString::number(mpc::data::ForsteriteC22<double>()));
        c23_line_edit->setText(QString::number(mpc::data::ForsteriteC23<double>()));
        c24_line_edit->setText(QString::number(mpc::data::ForsteriteC24<double>()));
        c25_line_edit->setText(QString::number(mpc::data::ForsteriteC25<double>()));
        c26_line_edit->setText(QString::number(mpc::data::ForsteriteC26<double>()));
        c33_line_edit->setText(QString::number(mpc::data::ForsteriteC33<double>()));
        c34_line_edit->setText(QString::number(mpc::data::ForsteriteC34<double>()));
        c35_line_edit->setText(QString::number(mpc::data::ForsteriteC35<double>()));
        c36_line_edit->setText(QString::number(mpc::data::ForsteriteC36<double>()));
        c44_line_edit->setText(QString::number(mpc::data::ForsteriteC44<double>()));
        c45_line_edit->setText(QString::number(mpc::data::ForsteriteC45<double>()));
        c46_line_edit->setText(QString::number(mpc::data::ForsteriteC46<double>()));
        c55_line_edit->setText(QString::number(mpc::data::ForsteriteC55<double>()));
        c56_line_edit->setText(QString::number(mpc::data::ForsteriteC56<double>()));
        c66_line_edit->setText(QString::number(mpc::data::ForsteriteC66<double>()));
        // data
        mpc::core::StiffnessTensor<float> c_ijkl = mpc::data::ForsteriteStiffnessTensor<float>();
        float c_ijkl_data[9][9] = {
                {c_ijkl.tensor(0,0,0,0), c_ijkl.tensor(0,0,0,1), c_ijkl.tensor(0,0,0,2),
                 c_ijkl.tensor(0,0,1,0), c_ijkl.tensor(0,0,1,1), c_ijkl.tensor(0,0,1,2),
                 c_ijkl.tensor(0,0,2,0), c_ijkl.tensor(0,0,2,1), c_ijkl.tensor(0,0,2,2)},  // ij 1,1
                {c_ijkl.tensor(0,1,0,0), c_ijkl.tensor(0,1,0,1), c_ijkl.tensor(0,1,0,2),
                 c_ijkl.tensor(0,1,1,0), c_ijkl.tensor(0,1,1,1), c_ijkl.tensor(0,1,1,2),
                 c_ijkl.tensor(0,1,2,0), c_ijkl.tensor(0,1,2,1), c_ijkl.tensor(0,1,2,2)},  // ij 1,2
                {c_ijkl.tensor(0,2,0,0), c_ijkl.tensor(0,2,0,1), c_ijkl.tensor(0,2,0,2),
                 c_ijkl.tensor(0,2,1,0), c_ijkl.tensor(0,2,1,1), c_ijkl.tensor(0,2,1,2),
                 c_ijkl.tensor(0,2,2,0), c_ijkl.tensor(0,2,2,1), c_ijkl.tensor(0,2,2,2)},  // ij 1,3
                {c_ijkl.tensor(1,0,0,0), c_ijkl.tensor(1,0,0,1), c_ijkl.tensor(1,0,0,2),
                 c_ijkl.tensor(1,0,1,0), c_ijkl.tensor(1,0,1,1), c_ijkl.tensor(1,0,1,2),
                 c_ijkl.tensor(1,0,2,0), c_ijkl.tensor(1,0,2,1), c_ijkl.tensor(1,0,2,2)},  // ij 2,1
                {c_ijkl.tensor(1,1,0,0), c_ijkl.tensor(1,1,0,1), c_ijkl.tensor(1,1,0,2),
                 c_ijkl.tensor(1,1,1,0), c_ijkl.tensor(1,1,1,1), c_ijkl.tensor(1,1,1,2),
                 c_ijkl.tensor(1,1,2,0), c_ijkl.tensor(1,1,2,1), c_ijkl.tensor(1,1,2,2)},  // ij 2,2
                {c_ijkl.tensor(1,2,0,0), c_ijkl.tensor(1,2,0,1), c_ijkl.tensor(1,2,0,2),
                 c_ijkl.tensor(1,2,1,0), c_ijkl.tensor(1,2,1,1), c_ijkl.tensor(1,2,1,2),
                 c_ijkl.tensor(1,2,2,0), c_ijkl.tensor(1,2,2,1), c_ijkl.tensor(1,2,2,2)},  // ij 2,3
                {c_ijkl.tensor(2,0,0,0), c_ijkl.tensor(2,0,0,1), c_ijkl.tensor(2,0,0,2),
                 c_ijkl.tensor(2,0,1,0), c_ijkl.tensor(2,0,1,1), c_ijkl.tensor(2,0,1,2),
                 c_ijkl.tensor(2,0,2,0), c_ijkl.tensor(2,0,2,1), c_ijkl.tensor(2,0,2,2)},  // ij 3,1
                {c_ijkl.tensor(2,1,0,0), c_ijkl.tensor(2,1,0,1), c_ijkl.tensor(2,1,0,2),
                 c_ijkl.tensor(2,1,1,0), c_ijkl.tensor(2,1,1,1), c_ijkl.tensor(2,1,1,2),
                 c_ijkl.tensor(2,1,2,0), c_ijkl.tensor(2,1,2,1), c_ijkl.tensor(2,1,2,2)},  // ij 3,2
                {c_ijkl.tensor(2,2,0,0), c_ijkl.tensor(2,2,0,1), c_ijkl.tensor(2,2,0,2),
                 c_ijkl.tensor(2,2,1,0), c_ijkl.tensor(2,2,1,1), c_ijkl.tensor(2,2,1,2),
                 c_ijkl.tensor(2,2,2,0), c_ijkl.tensor(2,2,2,1), c_ijkl.tensor(2,2,2,2)}   // ij 3,3
        };

        // create data arrays
        QBarDataArray *dataSet = new QBarDataArray;
        QBarDataRow *dataRow;

        dataSet->reserve(9);
        for (int ij = 0; ij < 9; ij++) {
            // Create a data row
            dataRow = new QBarDataRow(9);
            for (int kl = 0; kl < 9; kl++) {
                // Add data to the row
                (*dataRow)[kl].setValue(c_ijkl_data[ij][kl]);
            }
            // Add the row to the set
            dataSet->append(dataRow);
        }

        // Add data to the data proxy (the data proxy assumes ownership of it)
        primary_series->dataProxy()->resetArray(dataSet, ij_list, ij_list);
        break;
    }
    case 13: { // Fayalite
        density_line_edit->setText(QString::number(mpc::data::FayaliteDensity<double>()));
        bulk_modulus_line_edit->setText(QString::number(mpc::data::FayaliteBulkModulus<double>()));
        shear_modulus_line_edit->setText(QString::number(mpc::data::FayaliteShearModulus<double>()));
        c11_line_edit->setText(QString::number(mpc::data::FayaliteC11<double>()));
        c12_line_edit->setText(QString::number(mpc::data::FayaliteC12<double>()));
        c13_line_edit->setText(QString::number(mpc::data::FayaliteC13<double>()));
        c14_line_edit->setText(QString::number(mpc::data::FayaliteC14<double>()));
        c15_line_edit->setText(QString::number(mpc::data::FayaliteC15<double>()));
        c16_line_edit->setText(QString::number(mpc::data::FayaliteC16<double>()));
        c22_line_edit->setText(QString::number(mpc::data::FayaliteC22<double>()));
        c23_line_edit->setText(QString::number(mpc::data::FayaliteC23<double>()));
        c24_line_edit->setText(QString::number(mpc::data::FayaliteC24<double>()));
        c25_line_edit->setText(QString::number(mpc::data::FayaliteC25<double>()));
        c26_line_edit->setText(QString::number(mpc::data::FayaliteC26<double>()));
        c33_line_edit->setText(QString::number(mpc::data::FayaliteC33<double>()));
        c34_line_edit->setText(QString::number(mpc::data::FayaliteC34<double>()));
        c35_line_edit->setText(QString::number(mpc::data::FayaliteC35<double>()));
        c36_line_edit->setText(QString::number(mpc::data::FayaliteC36<double>()));
        c44_line_edit->setText(QString::number(mpc::data::FayaliteC44<double>()));
        c45_line_edit->setText(QString::number(mpc::data::FayaliteC45<double>()));
        c46_line_edit->setText(QString::number(mpc::data::FayaliteC46<double>()));
        c55_line_edit->setText(QString::number(mpc::data::FayaliteC55<double>()));
        c56_line_edit->setText(QString::number(mpc::data::FayaliteC56<double>()));
        c66_line_edit->setText(QString::number(mpc::data::FayaliteC66<double>()));
        // data
        mpc::core::StiffnessTensor<float> c_ijkl = mpc::data::FayaliteStiffnessTensor<float>();
        float c_ijkl_data[9][9] = {
                {c_ijkl.tensor(0,0,0,0), c_ijkl.tensor(0,0,0,1), c_ijkl.tensor(0,0,0,2),
                 c_ijkl.tensor(0,0,1,0), c_ijkl.tensor(0,0,1,1), c_ijkl.tensor(0,0,1,2),
                 c_ijkl.tensor(0,0,2,0), c_ijkl.tensor(0,0,2,1), c_ijkl.tensor(0,0,2,2)},  // ij 1,1
                {c_ijkl.tensor(0,1,0,0), c_ijkl.tensor(0,1,0,1), c_ijkl.tensor(0,1,0,2),
                 c_ijkl.tensor(0,1,1,0), c_ijkl.tensor(0,1,1,1), c_ijkl.tensor(0,1,1,2),
                 c_ijkl.tensor(0,1,2,0), c_ijkl.tensor(0,1,2,1), c_ijkl.tensor(0,1,2,2)},  // ij 1,2
                {c_ijkl.tensor(0,2,0,0), c_ijkl.tensor(0,2,0,1), c_ijkl.tensor(0,2,0,2),
                 c_ijkl.tensor(0,2,1,0), c_ijkl.tensor(0,2,1,1), c_ijkl.tensor(0,2,1,2),
                 c_ijkl.tensor(0,2,2,0), c_ijkl.tensor(0,2,2,1), c_ijkl.tensor(0,2,2,2)},  // ij 1,3
                {c_ijkl.tensor(1,0,0,0), c_ijkl.tensor(1,0,0,1), c_ijkl.tensor(1,0,0,2),
                 c_ijkl.tensor(1,0,1,0), c_ijkl.tensor(1,0,1,1), c_ijkl.tensor(1,0,1,2),
                 c_ijkl.tensor(1,0,2,0), c_ijkl.tensor(1,0,2,1), c_ijkl.tensor(1,0,2,2)},  // ij 2,1
                {c_ijkl.tensor(1,1,0,0), c_ijkl.tensor(1,1,0,1), c_ijkl.tensor(1,1,0,2),
                 c_ijkl.tensor(1,1,1,0), c_ijkl.tensor(1,1,1,1), c_ijkl.tensor(1,1,1,2),
                 c_ijkl.tensor(1,1,2,0), c_ijkl.tensor(1,1,2,1), c_ijkl.tensor(1,1,2,2)},  // ij 2,2
                {c_ijkl.tensor(1,2,0,0), c_ijkl.tensor(1,2,0,1), c_ijkl.tensor(1,2,0,2),
                 c_ijkl.tensor(1,2,1,0), c_ijkl.tensor(1,2,1,1), c_ijkl.tensor(1,2,1,2),
                 c_ijkl.tensor(1,2,2,0), c_ijkl.tensor(1,2,2,1), c_ijkl.tensor(1,2,2,2)},  // ij 2,3
                {c_ijkl.tensor(2,0,0,0), c_ijkl.tensor(2,0,0,1), c_ijkl.tensor(2,0,0,2),
                 c_ijkl.tensor(2,0,1,0), c_ijkl.tensor(2,0,1,1), c_ijkl.tensor(2,0,1,2),
                 c_ijkl.tensor(2,0,2,0), c_ijkl.tensor(2,0,2,1), c_ijkl.tensor(2,0,2,2)},  // ij 3,1
                {c_ijkl.tensor(2,1,0,0), c_ijkl.tensor(2,1,0,1), c_ijkl.tensor(2,1,0,2),
                 c_ijkl.tensor(2,1,1,0), c_ijkl.tensor(2,1,1,1), c_ijkl.tensor(2,1,1,2),
                 c_ijkl.tensor(2,1,2,0), c_ijkl.tensor(2,1,2,1), c_ijkl.tensor(2,1,2,2)},  // ij 3,2
                {c_ijkl.tensor(2,2,0,0), c_ijkl.tensor(2,2,0,1), c_ijkl.tensor(2,2,0,2),
                 c_ijkl.tensor(2,2,1,0), c_ijkl.tensor(2,2,1,1), c_ijkl.tensor(2,2,1,2),
                 c_ijkl.tensor(2,2,2,0), c_ijkl.tensor(2,2,2,1), c_ijkl.tensor(2,2,2,2)}   // ij 3,3
        };

        // create data arrays
        QBarDataArray *dataSet = new QBarDataArray;
        QBarDataRow *dataRow;

        dataSet->reserve(9);
        for (int ij = 0; ij < 9; ij++) {
            // Create a data row
            dataRow = new QBarDataRow(9);
            for (int kl = 0; kl < 9; kl++) {
                // Add data to the row
                (*dataRow)[kl].setValue(c_ijkl_data[ij][kl]);
            }
            // Add the row to the set
            dataSet->append(dataRow);
        }

        // Add data to the data proxy (the data proxy assumes ownership of it)
        primary_series->dataProxy()->resetArray(dataSet, ij_list, ij_list);
        break;
    }
    case 14: { // Montecellite
        density_line_edit->setText(QString::number(mpc::data::MontecelliteDensity<double>()));
        bulk_modulus_line_edit->setText(QString::number(mpc::data::MontecelliteBulkModulus<double>()));
        shear_modulus_line_edit->setText(QString::number(mpc::data::MontecelliteShearModulus<double>()));
        c11_line_edit->setText(QString::number(mpc::data::MontecelliteC11<double>()));
        c12_line_edit->setText(QString::number(mpc::data::MontecelliteC12<double>()));
        c13_line_edit->setText(QString::number(mpc::data::MontecelliteC13<double>()));
        c14_line_edit->setText(QString::number(mpc::data::MontecelliteC14<double>()));
        c15_line_edit->setText(QString::number(mpc::data::MontecelliteC15<double>()));
        c16_line_edit->setText(QString::number(mpc::data::MontecelliteC16<double>()));
        c22_line_edit->setText(QString::number(mpc::data::MontecelliteC22<double>()));
        c23_line_edit->setText(QString::number(mpc::data::MontecelliteC23<double>()));
        c24_line_edit->setText(QString::number(mpc::data::MontecelliteC24<double>()));
        c25_line_edit->setText(QString::number(mpc::data::MontecelliteC25<double>()));
        c26_line_edit->setText(QString::number(mpc::data::MontecelliteC26<double>()));
        c33_line_edit->setText(QString::number(mpc::data::MontecelliteC33<double>()));
        c34_line_edit->setText(QString::number(mpc::data::MontecelliteC34<double>()));
        c35_line_edit->setText(QString::number(mpc::data::MontecelliteC35<double>()));
        c36_line_edit->setText(QString::number(mpc::data::MontecelliteC36<double>()));
        c44_line_edit->setText(QString::number(mpc::data::MontecelliteC44<double>()));
        c45_line_edit->setText(QString::number(mpc::data::MontecelliteC45<double>()));
        c46_line_edit->setText(QString::number(mpc::data::MontecelliteC46<double>()));
        c55_line_edit->setText(QString::number(mpc::data::MontecelliteC55<double>()));
        c56_line_edit->setText(QString::number(mpc::data::MontecelliteC56<double>()));
        c66_line_edit->setText(QString::number(mpc::data::MontecelliteC66<double>()));
        // data
        mpc::core::StiffnessTensor<float> c_ijkl = mpc::data::MontecelliteStiffnessTensor<float>();
        float c_ijkl_data[9][9] = {
                {c_ijkl.tensor(0,0,0,0), c_ijkl.tensor(0,0,0,1), c_ijkl.tensor(0,0,0,2),
                 c_ijkl.tensor(0,0,1,0), c_ijkl.tensor(0,0,1,1), c_ijkl.tensor(0,0,1,2),
                 c_ijkl.tensor(0,0,2,0), c_ijkl.tensor(0,0,2,1), c_ijkl.tensor(0,0,2,2)},  // ij 1,1
                {c_ijkl.tensor(0,1,0,0), c_ijkl.tensor(0,1,0,1), c_ijkl.tensor(0,1,0,2),
                 c_ijkl.tensor(0,1,1,0), c_ijkl.tensor(0,1,1,1), c_ijkl.tensor(0,1,1,2),
                 c_ijkl.tensor(0,1,2,0), c_ijkl.tensor(0,1,2,1), c_ijkl.tensor(0,1,2,2)},  // ij 1,2
                {c_ijkl.tensor(0,2,0,0), c_ijkl.tensor(0,2,0,1), c_ijkl.tensor(0,2,0,2),
                 c_ijkl.tensor(0,2,1,0), c_ijkl.tensor(0,2,1,1), c_ijkl.tensor(0,2,1,2),
                 c_ijkl.tensor(0,2,2,0), c_ijkl.tensor(0,2,2,1), c_ijkl.tensor(0,2,2,2)},  // ij 1,3
                {c_ijkl.tensor(1,0,0,0), c_ijkl.tensor(1,0,0,1), c_ijkl.tensor(1,0,0,2),
                 c_ijkl.tensor(1,0,1,0), c_ijkl.tensor(1,0,1,1), c_ijkl.tensor(1,0,1,2),
                 c_ijkl.tensor(1,0,2,0), c_ijkl.tensor(1,0,2,1), c_ijkl.tensor(1,0,2,2)},  // ij 2,1
                {c_ijkl.tensor(1,1,0,0), c_ijkl.tensor(1,1,0,1), c_ijkl.tensor(1,1,0,2),
                 c_ijkl.tensor(1,1,1,0), c_ijkl.tensor(1,1,1,1), c_ijkl.tensor(1,1,1,2),
                 c_ijkl.tensor(1,1,2,0), c_ijkl.tensor(1,1,2,1), c_ijkl.tensor(1,1,2,2)},  // ij 2,2
                {c_ijkl.tensor(1,2,0,0), c_ijkl.tensor(1,2,0,1), c_ijkl.tensor(1,2,0,2),
                 c_ijkl.tensor(1,2,1,0), c_ijkl.tensor(1,2,1,1), c_ijkl.tensor(1,2,1,2),
                 c_ijkl.tensor(1,2,2,0), c_ijkl.tensor(1,2,2,1), c_ijkl.tensor(1,2,2,2)},  // ij 2,3
                {c_ijkl.tensor(2,0,0,0), c_ijkl.tensor(2,0,0,1), c_ijkl.tensor(2,0,0,2),
                 c_ijkl.tensor(2,0,1,0), c_ijkl.tensor(2,0,1,1), c_ijkl.tensor(2,0,1,2),
                 c_ijkl.tensor(2,0,2,0), c_ijkl.tensor(2,0,2,1), c_ijkl.tensor(2,0,2,2)},  // ij 3,1
                {c_ijkl.tensor(2,1,0,0), c_ijkl.tensor(2,1,0,1), c_ijkl.tensor(2,1,0,2),
                 c_ijkl.tensor(2,1,1,0), c_ijkl.tensor(2,1,1,1), c_ijkl.tensor(2,1,1,2),
                 c_ijkl.tensor(2,1,2,0), c_ijkl.tensor(2,1,2,1), c_ijkl.tensor(2,1,2,2)},  // ij 3,2
                {c_ijkl.tensor(2,2,0,0), c_ijkl.tensor(2,2,0,1), c_ijkl.tensor(2,2,0,2),
                 c_ijkl.tensor(2,2,1,0), c_ijkl.tensor(2,2,1,1), c_ijkl.tensor(2,2,1,2),
                 c_ijkl.tensor(2,2,2,0), c_ijkl.tensor(2,2,2,1), c_ijkl.tensor(2,2,2,2)}   // ij 3,3
        };

        // create data arrays
        QBarDataArray *dataSet = new QBarDataArray;
        QBarDataRow *dataRow;

        dataSet->reserve(9);
        for (int ij = 0; ij < 9; ij++) {
            // Create a data row
            dataRow = new QBarDataRow(9);
            for (int kl = 0; kl < 9; kl++) {
                // Add data to the row
                (*dataRow)[kl].setValue(c_ijkl_data[ij][kl]);
            }
            // Add the row to the set
            dataSet->append(dataRow);
        }

        // Add data to the data proxy (the data proxy assumes ownership of it)
        primary_series->dataProxy()->resetArray(dataSet, ij_list, ij_list);
        break;
    }
    case 15: { // Andalusite
        density_line_edit->setText(QString::number(mpc::data::AndalusiteDensity<double>()));
        bulk_modulus_line_edit->setText(QString::number(mpc::data::AndalusiteBulkModulus<double>()));
        shear_modulus_line_edit->setText(QString::number(mpc::data::AndalusiteShearModulus<double>()));
        c11_line_edit->setText(QString::number(mpc::data::AndalusiteC11<double>()));
        c12_line_edit->setText(QString::number(mpc::data::AndalusiteC12<double>()));
        c13_line_edit->setText(QString::number(mpc::data::AndalusiteC13<double>()));
        c14_line_edit->setText(QString::number(mpc::data::AndalusiteC14<double>()));
        c15_line_edit->setText(QString::number(mpc::data::AndalusiteC15<double>()));
        c16_line_edit->setText(QString::number(mpc::data::AndalusiteC16<double>()));
        c22_line_edit->setText(QString::number(mpc::data::AndalusiteC22<double>()));
        c23_line_edit->setText(QString::number(mpc::data::AndalusiteC23<double>()));
        c24_line_edit->setText(QString::number(mpc::data::AndalusiteC24<double>()));
        c25_line_edit->setText(QString::number(mpc::data::AndalusiteC25<double>()));
        c26_line_edit->setText(QString::number(mpc::data::AndalusiteC26<double>()));
        c33_line_edit->setText(QString::number(mpc::data::AndalusiteC33<double>()));
        c34_line_edit->setText(QString::number(mpc::data::AndalusiteC34<double>()));
        c35_line_edit->setText(QString::number(mpc::data::AndalusiteC35<double>()));
        c36_line_edit->setText(QString::number(mpc::data::AndalusiteC36<double>()));
        c44_line_edit->setText(QString::number(mpc::data::AndalusiteC44<double>()));
        c45_line_edit->setText(QString::number(mpc::data::AndalusiteC45<double>()));
        c46_line_edit->setText(QString::number(mpc::data::AndalusiteC46<double>()));
        c55_line_edit->setText(QString::number(mpc::data::AndalusiteC55<double>()));
        c56_line_edit->setText(QString::number(mpc::data::AndalusiteC56<double>()));
        c66_line_edit->setText(QString::number(mpc::data::AndalusiteC66<double>()));
        // data
        mpc::core::StiffnessTensor<float> c_ijkl = mpc::data::AndalusiteStiffnessTensor<float>();
        float c_ijkl_data[9][9] = {
                {c_ijkl.tensor(0,0,0,0), c_ijkl.tensor(0,0,0,1), c_ijkl.tensor(0,0,0,2),
                 c_ijkl.tensor(0,0,1,0), c_ijkl.tensor(0,0,1,1), c_ijkl.tensor(0,0,1,2),
                 c_ijkl.tensor(0,0,2,0), c_ijkl.tensor(0,0,2,1), c_ijkl.tensor(0,0,2,2)},  // ij 1,1
                {c_ijkl.tensor(0,1,0,0), c_ijkl.tensor(0,1,0,1), c_ijkl.tensor(0,1,0,2),
                 c_ijkl.tensor(0,1,1,0), c_ijkl.tensor(0,1,1,1), c_ijkl.tensor(0,1,1,2),
                 c_ijkl.tensor(0,1,2,0), c_ijkl.tensor(0,1,2,1), c_ijkl.tensor(0,1,2,2)},  // ij 1,2
                {c_ijkl.tensor(0,2,0,0), c_ijkl.tensor(0,2,0,1), c_ijkl.tensor(0,2,0,2),
                 c_ijkl.tensor(0,2,1,0), c_ijkl.tensor(0,2,1,1), c_ijkl.tensor(0,2,1,2),
                 c_ijkl.tensor(0,2,2,0), c_ijkl.tensor(0,2,2,1), c_ijkl.tensor(0,2,2,2)},  // ij 1,3
                {c_ijkl.tensor(1,0,0,0), c_ijkl.tensor(1,0,0,1), c_ijkl.tensor(1,0,0,2),
                 c_ijkl.tensor(1,0,1,0), c_ijkl.tensor(1,0,1,1), c_ijkl.tensor(1,0,1,2),
                 c_ijkl.tensor(1,0,2,0), c_ijkl.tensor(1,0,2,1), c_ijkl.tensor(1,0,2,2)},  // ij 2,1
                {c_ijkl.tensor(1,1,0,0), c_ijkl.tensor(1,1,0,1), c_ijkl.tensor(1,1,0,2),
                 c_ijkl.tensor(1,1,1,0), c_ijkl.tensor(1,1,1,1), c_ijkl.tensor(1,1,1,2),
                 c_ijkl.tensor(1,1,2,0), c_ijkl.tensor(1,1,2,1), c_ijkl.tensor(1,1,2,2)},  // ij 2,2
                {c_ijkl.tensor(1,2,0,0), c_ijkl.tensor(1,2,0,1), c_ijkl.tensor(1,2,0,2),
                 c_ijkl.tensor(1,2,1,0), c_ijkl.tensor(1,2,1,1), c_ijkl.tensor(1,2,1,2),
                 c_ijkl.tensor(1,2,2,0), c_ijkl.tensor(1,2,2,1), c_ijkl.tensor(1,2,2,2)},  // ij 2,3
                {c_ijkl.tensor(2,0,0,0), c_ijkl.tensor(2,0,0,1), c_ijkl.tensor(2,0,0,2),
                 c_ijkl.tensor(2,0,1,0), c_ijkl.tensor(2,0,1,1), c_ijkl.tensor(2,0,1,2),
                 c_ijkl.tensor(2,0,2,0), c_ijkl.tensor(2,0,2,1), c_ijkl.tensor(2,0,2,2)},  // ij 3,1
                {c_ijkl.tensor(2,1,0,0), c_ijkl.tensor(2,1,0,1), c_ijkl.tensor(2,1,0,2),
                 c_ijkl.tensor(2,1,1,0), c_ijkl.tensor(2,1,1,1), c_ijkl.tensor(2,1,1,2),
                 c_ijkl.tensor(2,1,2,0), c_ijkl.tensor(2,1,2,1), c_ijkl.tensor(2,1,2,2)},  // ij 3,2
                {c_ijkl.tensor(2,2,0,0), c_ijkl.tensor(2,2,0,1), c_ijkl.tensor(2,2,0,2),
                 c_ijkl.tensor(2,2,1,0), c_ijkl.tensor(2,2,1,1), c_ijkl.tensor(2,2,1,2),
                 c_ijkl.tensor(2,2,2,0), c_ijkl.tensor(2,2,2,1), c_ijkl.tensor(2,2,2,2)}   // ij 3,3
        };

        // create data arrays
        QBarDataArray *dataSet = new QBarDataArray;
        QBarDataRow *dataRow;

        dataSet->reserve(9);
        for (int ij = 0; ij < 9; ij++) {
            // Create a data row
            dataRow = new QBarDataRow(9);
            for (int kl = 0; kl < 9; kl++) {
                // Add data to the row
                (*dataRow)[kl].setValue(c_ijkl_data[ij][kl]);
            }
            // Add the row to the set
            dataSet->append(dataRow);
        }

        // Add data to the data proxy (the data proxy assumes ownership of it)
        primary_series->dataProxy()->resetArray(dataSet, ij_list, ij_list);
        break;
    }
    case 16: { // Silimanite
        density_line_edit->setText(QString::number(mpc::data::SilimaniteDensity<double>()));
        bulk_modulus_line_edit->setText(QString::number(mpc::data::SilimaniteBulkModulus<double>()));
        shear_modulus_line_edit->setText(QString::number(mpc::data::SilimaniteShearModulus<double>()));
        c11_line_edit->setText(QString::number(mpc::data::SilimaniteC11<double>()));
        c12_line_edit->setText(QString::number(mpc::data::SilimaniteC12<double>()));
        c13_line_edit->setText(QString::number(mpc::data::SilimaniteC13<double>()));
        c14_line_edit->setText(QString::number(mpc::data::SilimaniteC14<double>()));
        c15_line_edit->setText(QString::number(mpc::data::SilimaniteC15<double>()));
        c16_line_edit->setText(QString::number(mpc::data::SilimaniteC16<double>()));
        c22_line_edit->setText(QString::number(mpc::data::SilimaniteC22<double>()));
        c23_line_edit->setText(QString::number(mpc::data::SilimaniteC23<double>()));
        c24_line_edit->setText(QString::number(mpc::data::SilimaniteC24<double>()));
        c25_line_edit->setText(QString::number(mpc::data::SilimaniteC25<double>()));
        c26_line_edit->setText(QString::number(mpc::data::SilimaniteC26<double>()));
        c33_line_edit->setText(QString::number(mpc::data::SilimaniteC33<double>()));
        c34_line_edit->setText(QString::number(mpc::data::SilimaniteC34<double>()));
        c35_line_edit->setText(QString::number(mpc::data::SilimaniteC35<double>()));
        c36_line_edit->setText(QString::number(mpc::data::SilimaniteC36<double>()));
        c44_line_edit->setText(QString::number(mpc::data::SilimaniteC44<double>()));
        c45_line_edit->setText(QString::number(mpc::data::SilimaniteC45<double>()));
        c46_line_edit->setText(QString::number(mpc::data::SilimaniteC46<double>()));
        c55_line_edit->setText(QString::number(mpc::data::SilimaniteC55<double>()));
        c56_line_edit->setText(QString::number(mpc::data::SilimaniteC56<double>()));
        c66_line_edit->setText(QString::number(mpc::data::SilimaniteC66<double>()));
        // data
        mpc::core::StiffnessTensor<float> c_ijkl = mpc::data::SilimaniteStiffnessTensor<float>();
        float c_ijkl_data[9][9] = {
                {c_ijkl.tensor(0,0,0,0), c_ijkl.tensor(0,0,0,1), c_ijkl.tensor(0,0,0,2),
                 c_ijkl.tensor(0,0,1,0), c_ijkl.tensor(0,0,1,1), c_ijkl.tensor(0,0,1,2),
                 c_ijkl.tensor(0,0,2,0), c_ijkl.tensor(0,0,2,1), c_ijkl.tensor(0,0,2,2)},  // ij 1,1
                {c_ijkl.tensor(0,1,0,0), c_ijkl.tensor(0,1,0,1), c_ijkl.tensor(0,1,0,2),
                 c_ijkl.tensor(0,1,1,0), c_ijkl.tensor(0,1,1,1), c_ijkl.tensor(0,1,1,2),
                 c_ijkl.tensor(0,1,2,0), c_ijkl.tensor(0,1,2,1), c_ijkl.tensor(0,1,2,2)},  // ij 1,2
                {c_ijkl.tensor(0,2,0,0), c_ijkl.tensor(0,2,0,1), c_ijkl.tensor(0,2,0,2),
                 c_ijkl.tensor(0,2,1,0), c_ijkl.tensor(0,2,1,1), c_ijkl.tensor(0,2,1,2),
                 c_ijkl.tensor(0,2,2,0), c_ijkl.tensor(0,2,2,1), c_ijkl.tensor(0,2,2,2)},  // ij 1,3
                {c_ijkl.tensor(1,0,0,0), c_ijkl.tensor(1,0,0,1), c_ijkl.tensor(1,0,0,2),
                 c_ijkl.tensor(1,0,1,0), c_ijkl.tensor(1,0,1,1), c_ijkl.tensor(1,0,1,2),
                 c_ijkl.tensor(1,0,2,0), c_ijkl.tensor(1,0,2,1), c_ijkl.tensor(1,0,2,2)},  // ij 2,1
                {c_ijkl.tensor(1,1,0,0), c_ijkl.tensor(1,1,0,1), c_ijkl.tensor(1,1,0,2),
                 c_ijkl.tensor(1,1,1,0), c_ijkl.tensor(1,1,1,1), c_ijkl.tensor(1,1,1,2),
                 c_ijkl.tensor(1,1,2,0), c_ijkl.tensor(1,1,2,1), c_ijkl.tensor(1,1,2,2)},  // ij 2,2
                {c_ijkl.tensor(1,2,0,0), c_ijkl.tensor(1,2,0,1), c_ijkl.tensor(1,2,0,2),
                 c_ijkl.tensor(1,2,1,0), c_ijkl.tensor(1,2,1,1), c_ijkl.tensor(1,2,1,2),
                 c_ijkl.tensor(1,2,2,0), c_ijkl.tensor(1,2,2,1), c_ijkl.tensor(1,2,2,2)},  // ij 2,3
                {c_ijkl.tensor(2,0,0,0), c_ijkl.tensor(2,0,0,1), c_ijkl.tensor(2,0,0,2),
                 c_ijkl.tensor(2,0,1,0), c_ijkl.tensor(2,0,1,1), c_ijkl.tensor(2,0,1,2),
                 c_ijkl.tensor(2,0,2,0), c_ijkl.tensor(2,0,2,1), c_ijkl.tensor(2,0,2,2)},  // ij 3,1
                {c_ijkl.tensor(2,1,0,0), c_ijkl.tensor(2,1,0,1), c_ijkl.tensor(2,1,0,2),
                 c_ijkl.tensor(2,1,1,0), c_ijkl.tensor(2,1,1,1), c_ijkl.tensor(2,1,1,2),
                 c_ijkl.tensor(2,1,2,0), c_ijkl.tensor(2,1,2,1), c_ijkl.tensor(2,1,2,2)},  // ij 3,2
                {c_ijkl.tensor(2,2,0,0), c_ijkl.tensor(2,2,0,1), c_ijkl.tensor(2,2,0,2),
                 c_ijkl.tensor(2,2,1,0), c_ijkl.tensor(2,2,1,1), c_ijkl.tensor(2,2,1,2),
                 c_ijkl.tensor(2,2,2,0), c_ijkl.tensor(2,2,2,1), c_ijkl.tensor(2,2,2,2)}   // ij 3,3
        };

        // create data arrays
        QBarDataArray *dataSet = new QBarDataArray;
        QBarDataRow *dataRow;

        dataSet->reserve(9);
        for (int ij = 0; ij < 9; ij++) {
            // Create a data row
            dataRow = new QBarDataRow(9);
            for (int kl = 0; kl < 9; kl++) {
                // Add data to the row
                (*dataRow)[kl].setValue(c_ijkl_data[ij][kl]);
            }
            // Add the row to the set
            dataSet->append(dataRow);
        }

        // Add data to the data proxy (the data proxy assumes ownership of it)
        primary_series->dataProxy()->resetArray(dataSet, ij_list, ij_list);
        break;
    }
    case 17: { // Barite
        density_line_edit->setText(QString::number(mpc::data::BariteDensity<double>()));
        bulk_modulus_line_edit->setText(QString::number(mpc::data::BariteBulkModulus<double>()));
        shear_modulus_line_edit->setText(QString::number(mpc::data::BariteShearModulus<double>()));
        c11_line_edit->setText(QString::number(mpc::data::BariteC11<double>()));
        c12_line_edit->setText(QString::number(mpc::data::BariteC12<double>()));
        c13_line_edit->setText(QString::number(mpc::data::BariteC13<double>()));
        c14_line_edit->setText(QString::number(mpc::data::BariteC14<double>()));
        c15_line_edit->setText(QString::number(mpc::data::BariteC15<double>()));
        c16_line_edit->setText(QString::number(mpc::data::BariteC16<double>()));
        c22_line_edit->setText(QString::number(mpc::data::BariteC22<double>()));
        c23_line_edit->setText(QString::number(mpc::data::BariteC23<double>()));
        c24_line_edit->setText(QString::number(mpc::data::BariteC24<double>()));
        c25_line_edit->setText(QString::number(mpc::data::BariteC25<double>()));
        c26_line_edit->setText(QString::number(mpc::data::BariteC26<double>()));
        c33_line_edit->setText(QString::number(mpc::data::BariteC33<double>()));
        c34_line_edit->setText(QString::number(mpc::data::BariteC34<double>()));
        c35_line_edit->setText(QString::number(mpc::data::BariteC35<double>()));
        c36_line_edit->setText(QString::number(mpc::data::BariteC36<double>()));
        c44_line_edit->setText(QString::number(mpc::data::BariteC44<double>()));
        c45_line_edit->setText(QString::number(mpc::data::BariteC45<double>()));
        c46_line_edit->setText(QString::number(mpc::data::BariteC46<double>()));
        c55_line_edit->setText(QString::number(mpc::data::BariteC55<double>()));
        c56_line_edit->setText(QString::number(mpc::data::BariteC56<double>()));
        c66_line_edit->setText(QString::number(mpc::data::BariteC66<double>()));
        // data
        mpc::core::StiffnessTensor<float> c_ijkl = mpc::data::BariteStiffnessTensor<float>();
        float c_ijkl_data[9][9] = {
                {c_ijkl.tensor(0,0,0,0), c_ijkl.tensor(0,0,0,1), c_ijkl.tensor(0,0,0,2),
                 c_ijkl.tensor(0,0,1,0), c_ijkl.tensor(0,0,1,1), c_ijkl.tensor(0,0,1,2),
                 c_ijkl.tensor(0,0,2,0), c_ijkl.tensor(0,0,2,1), c_ijkl.tensor(0,0,2,2)},  // ij 1,1
                {c_ijkl.tensor(0,1,0,0), c_ijkl.tensor(0,1,0,1), c_ijkl.tensor(0,1,0,2),
                 c_ijkl.tensor(0,1,1,0), c_ijkl.tensor(0,1,1,1), c_ijkl.tensor(0,1,1,2),
                 c_ijkl.tensor(0,1,2,0), c_ijkl.tensor(0,1,2,1), c_ijkl.tensor(0,1,2,2)},  // ij 1,2
                {c_ijkl.tensor(0,2,0,0), c_ijkl.tensor(0,2,0,1), c_ijkl.tensor(0,2,0,2),
                 c_ijkl.tensor(0,2,1,0), c_ijkl.tensor(0,2,1,1), c_ijkl.tensor(0,2,1,2),
                 c_ijkl.tensor(0,2,2,0), c_ijkl.tensor(0,2,2,1), c_ijkl.tensor(0,2,2,2)},  // ij 1,3
                {c_ijkl.tensor(1,0,0,0), c_ijkl.tensor(1,0,0,1), c_ijkl.tensor(1,0,0,2),
                 c_ijkl.tensor(1,0,1,0), c_ijkl.tensor(1,0,1,1), c_ijkl.tensor(1,0,1,2),
                 c_ijkl.tensor(1,0,2,0), c_ijkl.tensor(1,0,2,1), c_ijkl.tensor(1,0,2,2)},  // ij 2,1
                {c_ijkl.tensor(1,1,0,0), c_ijkl.tensor(1,1,0,1), c_ijkl.tensor(1,1,0,2),
                 c_ijkl.tensor(1,1,1,0), c_ijkl.tensor(1,1,1,1), c_ijkl.tensor(1,1,1,2),
                 c_ijkl.tensor(1,1,2,0), c_ijkl.tensor(1,1,2,1), c_ijkl.tensor(1,1,2,2)},  // ij 2,2
                {c_ijkl.tensor(1,2,0,0), c_ijkl.tensor(1,2,0,1), c_ijkl.tensor(1,2,0,2),
                 c_ijkl.tensor(1,2,1,0), c_ijkl.tensor(1,2,1,1), c_ijkl.tensor(1,2,1,2),
                 c_ijkl.tensor(1,2,2,0), c_ijkl.tensor(1,2,2,1), c_ijkl.tensor(1,2,2,2)},  // ij 2,3
                {c_ijkl.tensor(2,0,0,0), c_ijkl.tensor(2,0,0,1), c_ijkl.tensor(2,0,0,2),
                 c_ijkl.tensor(2,0,1,0), c_ijkl.tensor(2,0,1,1), c_ijkl.tensor(2,0,1,2),
                 c_ijkl.tensor(2,0,2,0), c_ijkl.tensor(2,0,2,1), c_ijkl.tensor(2,0,2,2)},  // ij 3,1
                {c_ijkl.tensor(2,1,0,0), c_ijkl.tensor(2,1,0,1), c_ijkl.tensor(2,1,0,2),
                 c_ijkl.tensor(2,1,1,0), c_ijkl.tensor(2,1,1,1), c_ijkl.tensor(2,1,1,2),
                 c_ijkl.tensor(2,1,2,0), c_ijkl.tensor(2,1,2,1), c_ijkl.tensor(2,1,2,2)},  // ij 3,2
                {c_ijkl.tensor(2,2,0,0), c_ijkl.tensor(2,2,0,1), c_ijkl.tensor(2,2,0,2),
                 c_ijkl.tensor(2,2,1,0), c_ijkl.tensor(2,2,1,1), c_ijkl.tensor(2,2,1,2),
                 c_ijkl.tensor(2,2,2,0), c_ijkl.tensor(2,2,2,1), c_ijkl.tensor(2,2,2,2)}   // ij 3,3
        };

        // create data arrays
        QBarDataArray *dataSet = new QBarDataArray;
        QBarDataRow *dataRow;

        dataSet->reserve(9);
        for (int ij = 0; ij < 9; ij++) {
            // Create a data row
            dataRow = new QBarDataRow(9);
            for (int kl = 0; kl < 9; kl++) {
                // Add data to the row
                (*dataRow)[kl].setValue(c_ijkl_data[ij][kl]);
            }
            // Add the row to the set
            dataSet->append(dataRow);
        }

        // Add data to the data proxy (the data proxy assumes ownership of it)
        primary_series->dataProxy()->resetArray(dataSet, ij_list, ij_list);
        break;
    }
    case 18: { // Anhydrite
        density_line_edit->setText(QString::number(mpc::data::AnhydriteDensity<double>()));
        bulk_modulus_line_edit->setText(QString::number(mpc::data::AnhydriteBulkModulus<double>()));
        shear_modulus_line_edit->setText(QString::number(mpc::data::AnhydriteShearModulus<double>()));
        c11_line_edit->setText(QString::number(mpc::data::AnhydriteC11<double>()));
        c12_line_edit->setText(QString::number(mpc::data::AnhydriteC12<double>()));
        c13_line_edit->setText(QString::number(mpc::data::AnhydriteC13<double>()));
        c14_line_edit->setText(QString::number(mpc::data::AnhydriteC14<double>()));
        c15_line_edit->setText(QString::number(mpc::data::AnhydriteC15<double>()));
        c16_line_edit->setText(QString::number(mpc::data::AnhydriteC16<double>()));
        c22_line_edit->setText(QString::number(mpc::data::AnhydriteC22<double>()));
        c23_line_edit->setText(QString::number(mpc::data::AnhydriteC23<double>()));
        c24_line_edit->setText(QString::number(mpc::data::AnhydriteC24<double>()));
        c25_line_edit->setText(QString::number(mpc::data::AnhydriteC25<double>()));
        c26_line_edit->setText(QString::number(mpc::data::AnhydriteC26<double>()));
        c33_line_edit->setText(QString::number(mpc::data::AnhydriteC33<double>()));
        c34_line_edit->setText(QString::number(mpc::data::AnhydriteC34<double>()));
        c35_line_edit->setText(QString::number(mpc::data::AnhydriteC35<double>()));
        c36_line_edit->setText(QString::number(mpc::data::AnhydriteC36<double>()));
        c44_line_edit->setText(QString::number(mpc::data::AnhydriteC44<double>()));
        c45_line_edit->setText(QString::number(mpc::data::AnhydriteC45<double>()));
        c46_line_edit->setText(QString::number(mpc::data::AnhydriteC46<double>()));
        c55_line_edit->setText(QString::number(mpc::data::AnhydriteC55<double>()));
        c56_line_edit->setText(QString::number(mpc::data::AnhydriteC56<double>()));
        c66_line_edit->setText(QString::number(mpc::data::AnhydriteC66<double>()));
        // data
        mpc::core::StiffnessTensor<float> c_ijkl = mpc::data::AnhydriteStiffnessTensor<float>();
        float c_ijkl_data[9][9] = {
                {c_ijkl.tensor(0,0,0,0), c_ijkl.tensor(0,0,0,1), c_ijkl.tensor(0,0,0,2),
                 c_ijkl.tensor(0,0,1,0), c_ijkl.tensor(0,0,1,1), c_ijkl.tensor(0,0,1,2),
                 c_ijkl.tensor(0,0,2,0), c_ijkl.tensor(0,0,2,1), c_ijkl.tensor(0,0,2,2)},  // ij 1,1
                {c_ijkl.tensor(0,1,0,0), c_ijkl.tensor(0,1,0,1), c_ijkl.tensor(0,1,0,2),
                 c_ijkl.tensor(0,1,1,0), c_ijkl.tensor(0,1,1,1), c_ijkl.tensor(0,1,1,2),
                 c_ijkl.tensor(0,1,2,0), c_ijkl.tensor(0,1,2,1), c_ijkl.tensor(0,1,2,2)},  // ij 1,2
                {c_ijkl.tensor(0,2,0,0), c_ijkl.tensor(0,2,0,1), c_ijkl.tensor(0,2,0,2),
                 c_ijkl.tensor(0,2,1,0), c_ijkl.tensor(0,2,1,1), c_ijkl.tensor(0,2,1,2),
                 c_ijkl.tensor(0,2,2,0), c_ijkl.tensor(0,2,2,1), c_ijkl.tensor(0,2,2,2)},  // ij 1,3
                {c_ijkl.tensor(1,0,0,0), c_ijkl.tensor(1,0,0,1), c_ijkl.tensor(1,0,0,2),
                 c_ijkl.tensor(1,0,1,0), c_ijkl.tensor(1,0,1,1), c_ijkl.tensor(1,0,1,2),
                 c_ijkl.tensor(1,0,2,0), c_ijkl.tensor(1,0,2,1), c_ijkl.tensor(1,0,2,2)},  // ij 2,1
                {c_ijkl.tensor(1,1,0,0), c_ijkl.tensor(1,1,0,1), c_ijkl.tensor(1,1,0,2),
                 c_ijkl.tensor(1,1,1,0), c_ijkl.tensor(1,1,1,1), c_ijkl.tensor(1,1,1,2),
                 c_ijkl.tensor(1,1,2,0), c_ijkl.tensor(1,1,2,1), c_ijkl.tensor(1,1,2,2)},  // ij 2,2
                {c_ijkl.tensor(1,2,0,0), c_ijkl.tensor(1,2,0,1), c_ijkl.tensor(1,2,0,2),
                 c_ijkl.tensor(1,2,1,0), c_ijkl.tensor(1,2,1,1), c_ijkl.tensor(1,2,1,2),
                 c_ijkl.tensor(1,2,2,0), c_ijkl.tensor(1,2,2,1), c_ijkl.tensor(1,2,2,2)},  // ij 2,3
                {c_ijkl.tensor(2,0,0,0), c_ijkl.tensor(2,0,0,1), c_ijkl.tensor(2,0,0,2),
                 c_ijkl.tensor(2,0,1,0), c_ijkl.tensor(2,0,1,1), c_ijkl.tensor(2,0,1,2),
                 c_ijkl.tensor(2,0,2,0), c_ijkl.tensor(2,0,2,1), c_ijkl.tensor(2,0,2,2)},  // ij 3,1
                {c_ijkl.tensor(2,1,0,0), c_ijkl.tensor(2,1,0,1), c_ijkl.tensor(2,1,0,2),
                 c_ijkl.tensor(2,1,1,0), c_ijkl.tensor(2,1,1,1), c_ijkl.tensor(2,1,1,2),
                 c_ijkl.tensor(2,1,2,0), c_ijkl.tensor(2,1,2,1), c_ijkl.tensor(2,1,2,2)},  // ij 3,2
                {c_ijkl.tensor(2,2,0,0), c_ijkl.tensor(2,2,0,1), c_ijkl.tensor(2,2,0,2),
                 c_ijkl.tensor(2,2,1,0), c_ijkl.tensor(2,2,1,1), c_ijkl.tensor(2,2,1,2),
                 c_ijkl.tensor(2,2,2,0), c_ijkl.tensor(2,2,2,1), c_ijkl.tensor(2,2,2,2)}   // ij 3,3
        };

        // create data arrays
        QBarDataArray *dataSet = new QBarDataArray;
        QBarDataRow *dataRow;

        dataSet->reserve(9);
        for (int ij = 0; ij < 9; ij++) {
            // Create a data row
            dataRow = new QBarDataRow(9);
            for (int kl = 0; kl < 9; kl++) {
                // Add data to the row
                (*dataRow)[kl].setValue(c_ijkl_data[ij][kl]);
            }
            // Add the row to the set
            dataSet->append(dataRow);
        }

        // Add data to the data proxy (the data proxy assumes ownership of it)
        primary_series->dataProxy()->resetArray(dataSet, ij_list, ij_list);
        break;
    }
    case 19: { // Dolomite
        density_line_edit->setText(QString::number(mpc::data::DolomiteDensity<double>()));
        bulk_modulus_line_edit->setText(QString::number(mpc::data::DolomiteBulkModulus<double>()));
        shear_modulus_line_edit->setText(QString::number(mpc::data::DolomiteShearModulus<double>()));
        c11_line_edit->setText(QString::number(mpc::data::DolomiteC11<double>()));
        c12_line_edit->setText(QString::number(mpc::data::DolomiteC12<double>()));
        c13_line_edit->setText(QString::number(mpc::data::DolomiteC13<double>()));
        c14_line_edit->setText(QString::number(mpc::data::DolomiteC14<double>()));
        c15_line_edit->setText(QString::number(mpc::data::DolomiteC15<double>()));
        c16_line_edit->setText(QString::number(mpc::data::DolomiteC16<double>()));
        c22_line_edit->setText(QString::number(mpc::data::DolomiteC22<double>()));
        c23_line_edit->setText(QString::number(mpc::data::DolomiteC23<double>()));
        c24_line_edit->setText(QString::number(mpc::data::DolomiteC24<double>()));
        c25_line_edit->setText(QString::number(mpc::data::DolomiteC25<double>()));
        c26_line_edit->setText(QString::number(mpc::data::DolomiteC26<double>()));
        c33_line_edit->setText(QString::number(mpc::data::DolomiteC33<double>()));
        c34_line_edit->setText(QString::number(mpc::data::DolomiteC34<double>()));
        c35_line_edit->setText(QString::number(mpc::data::DolomiteC35<double>()));
        c36_line_edit->setText(QString::number(mpc::data::DolomiteC36<double>()));
        c44_line_edit->setText(QString::number(mpc::data::DolomiteC44<double>()));
        c45_line_edit->setText(QString::number(mpc::data::DolomiteC45<double>()));
        c46_line_edit->setText(QString::number(mpc::data::DolomiteC46<double>()));
        c55_line_edit->setText(QString::number(mpc::data::DolomiteC55<double>()));
        c56_line_edit->setText(QString::number(mpc::data::DolomiteC56<double>()));
        c66_line_edit->setText(QString::number(mpc::data::DolomiteC66<double>()));
        // data
        mpc::core::StiffnessTensor<float> c_ijkl = mpc::data::DolomiteStiffnessTensor<float>();
        float c_ijkl_data[9][9] = {
                {c_ijkl.tensor(0,0,0,0), c_ijkl.tensor(0,0,0,1), c_ijkl.tensor(0,0,0,2),
                 c_ijkl.tensor(0,0,1,0), c_ijkl.tensor(0,0,1,1), c_ijkl.tensor(0,0,1,2),
                 c_ijkl.tensor(0,0,2,0), c_ijkl.tensor(0,0,2,1), c_ijkl.tensor(0,0,2,2)},  // ij 1,1
                {c_ijkl.tensor(0,1,0,0), c_ijkl.tensor(0,1,0,1), c_ijkl.tensor(0,1,0,2),
                 c_ijkl.tensor(0,1,1,0), c_ijkl.tensor(0,1,1,1), c_ijkl.tensor(0,1,1,2),
                 c_ijkl.tensor(0,1,2,0), c_ijkl.tensor(0,1,2,1), c_ijkl.tensor(0,1,2,2)},  // ij 1,2
                {c_ijkl.tensor(0,2,0,0), c_ijkl.tensor(0,2,0,1), c_ijkl.tensor(0,2,0,2),
                 c_ijkl.tensor(0,2,1,0), c_ijkl.tensor(0,2,1,1), c_ijkl.tensor(0,2,1,2),
                 c_ijkl.tensor(0,2,2,0), c_ijkl.tensor(0,2,2,1), c_ijkl.tensor(0,2,2,2)},  // ij 1,3
                {c_ijkl.tensor(1,0,0,0), c_ijkl.tensor(1,0,0,1), c_ijkl.tensor(1,0,0,2),
                 c_ijkl.tensor(1,0,1,0), c_ijkl.tensor(1,0,1,1), c_ijkl.tensor(1,0,1,2),
                 c_ijkl.tensor(1,0,2,0), c_ijkl.tensor(1,0,2,1), c_ijkl.tensor(1,0,2,2)},  // ij 2,1
                {c_ijkl.tensor(1,1,0,0), c_ijkl.tensor(1,1,0,1), c_ijkl.tensor(1,1,0,2),
                 c_ijkl.tensor(1,1,1,0), c_ijkl.tensor(1,1,1,1), c_ijkl.tensor(1,1,1,2),
                 c_ijkl.tensor(1,1,2,0), c_ijkl.tensor(1,1,2,1), c_ijkl.tensor(1,1,2,2)},  // ij 2,2
                {c_ijkl.tensor(1,2,0,0), c_ijkl.tensor(1,2,0,1), c_ijkl.tensor(1,2,0,2),
                 c_ijkl.tensor(1,2,1,0), c_ijkl.tensor(1,2,1,1), c_ijkl.tensor(1,2,1,2),
                 c_ijkl.tensor(1,2,2,0), c_ijkl.tensor(1,2,2,1), c_ijkl.tensor(1,2,2,2)},  // ij 2,3
                {c_ijkl.tensor(2,0,0,0), c_ijkl.tensor(2,0,0,1), c_ijkl.tensor(2,0,0,2),
                 c_ijkl.tensor(2,0,1,0), c_ijkl.tensor(2,0,1,1), c_ijkl.tensor(2,0,1,2),
                 c_ijkl.tensor(2,0,2,0), c_ijkl.tensor(2,0,2,1), c_ijkl.tensor(2,0,2,2)},  // ij 3,1
                {c_ijkl.tensor(2,1,0,0), c_ijkl.tensor(2,1,0,1), c_ijkl.tensor(2,1,0,2),
                 c_ijkl.tensor(2,1,1,0), c_ijkl.tensor(2,1,1,1), c_ijkl.tensor(2,1,1,2),
                 c_ijkl.tensor(2,1,2,0), c_ijkl.tensor(2,1,2,1), c_ijkl.tensor(2,1,2,2)},  // ij 3,2
                {c_ijkl.tensor(2,2,0,0), c_ijkl.tensor(2,2,0,1), c_ijkl.tensor(2,2,0,2),
                 c_ijkl.tensor(2,2,1,0), c_ijkl.tensor(2,2,1,1), c_ijkl.tensor(2,2,1,2),
                 c_ijkl.tensor(2,2,2,0), c_ijkl.tensor(2,2,2,1), c_ijkl.tensor(2,2,2,2)}   // ij 3,3
        };

        // create data arrays
        QBarDataArray *dataSet = new QBarDataArray;
        QBarDataRow *dataRow;

        dataSet->reserve(9);
        for (int ij = 0; ij < 9; ij++) {
            // Create a data row
            dataRow = new QBarDataRow(9);
            for (int kl = 0; kl < 9; kl++) {
                // Add data to the row
                (*dataRow)[kl].setValue(c_ijkl_data[ij][kl]);
            }
            // Add the row to the set
            dataSet->append(dataRow);
        }

        // Add data to the data proxy (the data proxy assumes ownership of it)
        primary_series->dataProxy()->resetArray(dataSet, ij_list, ij_list);
        break;
    }
    case 20: { // Rutile
        density_line_edit->setText(QString::number(mpc::data::RutileDensity<double>()));
        bulk_modulus_line_edit->setText(QString::number(mpc::data::RutileBulkModulus<double>()));
        shear_modulus_line_edit->setText(QString::number(mpc::data::RutileShearModulus<double>()));
        c11_line_edit->setText(QString::number(mpc::data::RutileC11<double>()));
        c12_line_edit->setText(QString::number(mpc::data::RutileC12<double>()));
        c13_line_edit->setText(QString::number(mpc::data::RutileC13<double>()));
        c14_line_edit->setText(QString::number(mpc::data::RutileC14<double>()));
        c15_line_edit->setText(QString::number(mpc::data::RutileC15<double>()));
        c16_line_edit->setText(QString::number(mpc::data::RutileC16<double>()));
        c22_line_edit->setText(QString::number(mpc::data::RutileC22<double>()));
        c23_line_edit->setText(QString::number(mpc::data::RutileC23<double>()));
        c24_line_edit->setText(QString::number(mpc::data::RutileC24<double>()));
        c25_line_edit->setText(QString::number(mpc::data::RutileC25<double>()));
        c26_line_edit->setText(QString::number(mpc::data::RutileC26<double>()));
        c33_line_edit->setText(QString::number(mpc::data::RutileC33<double>()));
        c34_line_edit->setText(QString::number(mpc::data::RutileC34<double>()));
        c35_line_edit->setText(QString::number(mpc::data::RutileC35<double>()));
        c36_line_edit->setText(QString::number(mpc::data::RutileC36<double>()));
        c44_line_edit->setText(QString::number(mpc::data::RutileC44<double>()));
        c45_line_edit->setText(QString::number(mpc::data::RutileC45<double>()));
        c46_line_edit->setText(QString::number(mpc::data::RutileC46<double>()));
        c55_line_edit->setText(QString::number(mpc::data::RutileC55<double>()));
        c56_line_edit->setText(QString::number(mpc::data::RutileC56<double>()));
        c66_line_edit->setText(QString::number(mpc::data::RutileC66<double>()));
        // data
        mpc::core::StiffnessTensor<float> c_ijkl = mpc::data::RutileStiffnessTensor<float>();
        float c_ijkl_data[9][9] = {
                {c_ijkl.tensor(0,0,0,0), c_ijkl.tensor(0,0,0,1), c_ijkl.tensor(0,0,0,2),
                 c_ijkl.tensor(0,0,1,0), c_ijkl.tensor(0,0,1,1), c_ijkl.tensor(0,0,1,2),
                 c_ijkl.tensor(0,0,2,0), c_ijkl.tensor(0,0,2,1), c_ijkl.tensor(0,0,2,2)},  // ij 1,1
                {c_ijkl.tensor(0,1,0,0), c_ijkl.tensor(0,1,0,1), c_ijkl.tensor(0,1,0,2),
                 c_ijkl.tensor(0,1,1,0), c_ijkl.tensor(0,1,1,1), c_ijkl.tensor(0,1,1,2),
                 c_ijkl.tensor(0,1,2,0), c_ijkl.tensor(0,1,2,1), c_ijkl.tensor(0,1,2,2)},  // ij 1,2
                {c_ijkl.tensor(0,2,0,0), c_ijkl.tensor(0,2,0,1), c_ijkl.tensor(0,2,0,2),
                 c_ijkl.tensor(0,2,1,0), c_ijkl.tensor(0,2,1,1), c_ijkl.tensor(0,2,1,2),
                 c_ijkl.tensor(0,2,2,0), c_ijkl.tensor(0,2,2,1), c_ijkl.tensor(0,2,2,2)},  // ij 1,3
                {c_ijkl.tensor(1,0,0,0), c_ijkl.tensor(1,0,0,1), c_ijkl.tensor(1,0,0,2),
                 c_ijkl.tensor(1,0,1,0), c_ijkl.tensor(1,0,1,1), c_ijkl.tensor(1,0,1,2),
                 c_ijkl.tensor(1,0,2,0), c_ijkl.tensor(1,0,2,1), c_ijkl.tensor(1,0,2,2)},  // ij 2,1
                {c_ijkl.tensor(1,1,0,0), c_ijkl.tensor(1,1,0,1), c_ijkl.tensor(1,1,0,2),
                 c_ijkl.tensor(1,1,1,0), c_ijkl.tensor(1,1,1,1), c_ijkl.tensor(1,1,1,2),
                 c_ijkl.tensor(1,1,2,0), c_ijkl.tensor(1,1,2,1), c_ijkl.tensor(1,1,2,2)},  // ij 2,2
                {c_ijkl.tensor(1,2,0,0), c_ijkl.tensor(1,2,0,1), c_ijkl.tensor(1,2,0,2),
                 c_ijkl.tensor(1,2,1,0), c_ijkl.tensor(1,2,1,1), c_ijkl.tensor(1,2,1,2),
                 c_ijkl.tensor(1,2,2,0), c_ijkl.tensor(1,2,2,1), c_ijkl.tensor(1,2,2,2)},  // ij 2,3
                {c_ijkl.tensor(2,0,0,0), c_ijkl.tensor(2,0,0,1), c_ijkl.tensor(2,0,0,2),
                 c_ijkl.tensor(2,0,1,0), c_ijkl.tensor(2,0,1,1), c_ijkl.tensor(2,0,1,2),
                 c_ijkl.tensor(2,0,2,0), c_ijkl.tensor(2,0,2,1), c_ijkl.tensor(2,0,2,2)},  // ij 3,1
                {c_ijkl.tensor(2,1,0,0), c_ijkl.tensor(2,1,0,1), c_ijkl.tensor(2,1,0,2),
                 c_ijkl.tensor(2,1,1,0), c_ijkl.tensor(2,1,1,1), c_ijkl.tensor(2,1,1,2),
                 c_ijkl.tensor(2,1,2,0), c_ijkl.tensor(2,1,2,1), c_ijkl.tensor(2,1,2,2)},  // ij 3,2
                {c_ijkl.tensor(2,2,0,0), c_ijkl.tensor(2,2,0,1), c_ijkl.tensor(2,2,0,2),
                 c_ijkl.tensor(2,2,1,0), c_ijkl.tensor(2,2,1,1), c_ijkl.tensor(2,2,1,2),
                 c_ijkl.tensor(2,2,2,0), c_ijkl.tensor(2,2,2,1), c_ijkl.tensor(2,2,2,2)}   // ij 3,3
        };

        // create data arrays
        QBarDataArray *dataSet = new QBarDataArray;
        QBarDataRow *dataRow;

        dataSet->reserve(9);
        for (int ij = 0; ij < 9; ij++) {
            // Create a data row
            dataRow = new QBarDataRow(9);
            for (int kl = 0; kl < 9; kl++) {
                // Add data to the row
                (*dataRow)[kl].setValue(c_ijkl_data[ij][kl]);
            }
            // Add the row to the set
            dataSet->append(dataRow);
        }

        // Add data to the data proxy (the data proxy assumes ownership of it)
        primary_series->dataProxy()->resetArray(dataSet, ij_list, ij_list);
        break;
    }
    case 21: { // Zircon
        density_line_edit->setText(QString::number(mpc::data::ZirconDensity<double>()));
        bulk_modulus_line_edit->setText(QString::number(mpc::data::ZirconBulkModulus<double>()));
        shear_modulus_line_edit->setText(QString::number(mpc::data::ZirconShearModulus<double>()));
        c11_line_edit->setText(QString::number(mpc::data::ZirconC11<double>()));
        c12_line_edit->setText(QString::number(mpc::data::ZirconC12<double>()));
        c13_line_edit->setText(QString::number(mpc::data::ZirconC13<double>()));
        c14_line_edit->setText(QString::number(mpc::data::ZirconC14<double>()));
        c15_line_edit->setText(QString::number(mpc::data::ZirconC15<double>()));
        c16_line_edit->setText(QString::number(mpc::data::ZirconC16<double>()));
        c22_line_edit->setText(QString::number(mpc::data::ZirconC22<double>()));
        c23_line_edit->setText(QString::number(mpc::data::ZirconC23<double>()));
        c24_line_edit->setText(QString::number(mpc::data::ZirconC24<double>()));
        c25_line_edit->setText(QString::number(mpc::data::ZirconC25<double>()));
        c26_line_edit->setText(QString::number(mpc::data::ZirconC26<double>()));
        c33_line_edit->setText(QString::number(mpc::data::ZirconC33<double>()));
        c34_line_edit->setText(QString::number(mpc::data::ZirconC34<double>()));
        c35_line_edit->setText(QString::number(mpc::data::ZirconC35<double>()));
        c36_line_edit->setText(QString::number(mpc::data::ZirconC36<double>()));
        c44_line_edit->setText(QString::number(mpc::data::ZirconC44<double>()));
        c45_line_edit->setText(QString::number(mpc::data::ZirconC45<double>()));
        c46_line_edit->setText(QString::number(mpc::data::ZirconC46<double>()));
        c55_line_edit->setText(QString::number(mpc::data::ZirconC55<double>()));
        c56_line_edit->setText(QString::number(mpc::data::ZirconC56<double>()));
        c66_line_edit->setText(QString::number(mpc::data::ZirconC66<double>()));
        // data
        mpc::core::StiffnessTensor<float> c_ijkl = mpc::data::ZirconStiffnessTensor<float>();
        float c_ijkl_data[9][9] = {
                {c_ijkl.tensor(0,0,0,0), c_ijkl.tensor(0,0,0,1), c_ijkl.tensor(0,0,0,2),
                 c_ijkl.tensor(0,0,1,0), c_ijkl.tensor(0,0,1,1), c_ijkl.tensor(0,0,1,2),
                 c_ijkl.tensor(0,0,2,0), c_ijkl.tensor(0,0,2,1), c_ijkl.tensor(0,0,2,2)},  // ij 1,1
                {c_ijkl.tensor(0,1,0,0), c_ijkl.tensor(0,1,0,1), c_ijkl.tensor(0,1,0,2),
                 c_ijkl.tensor(0,1,1,0), c_ijkl.tensor(0,1,1,1), c_ijkl.tensor(0,1,1,2),
                 c_ijkl.tensor(0,1,2,0), c_ijkl.tensor(0,1,2,1), c_ijkl.tensor(0,1,2,2)},  // ij 1,2
                {c_ijkl.tensor(0,2,0,0), c_ijkl.tensor(0,2,0,1), c_ijkl.tensor(0,2,0,2),
                 c_ijkl.tensor(0,2,1,0), c_ijkl.tensor(0,2,1,1), c_ijkl.tensor(0,2,1,2),
                 c_ijkl.tensor(0,2,2,0), c_ijkl.tensor(0,2,2,1), c_ijkl.tensor(0,2,2,2)},  // ij 1,3
                {c_ijkl.tensor(1,0,0,0), c_ijkl.tensor(1,0,0,1), c_ijkl.tensor(1,0,0,2),
                 c_ijkl.tensor(1,0,1,0), c_ijkl.tensor(1,0,1,1), c_ijkl.tensor(1,0,1,2),
                 c_ijkl.tensor(1,0,2,0), c_ijkl.tensor(1,0,2,1), c_ijkl.tensor(1,0,2,2)},  // ij 2,1
                {c_ijkl.tensor(1,1,0,0), c_ijkl.tensor(1,1,0,1), c_ijkl.tensor(1,1,0,2),
                 c_ijkl.tensor(1,1,1,0), c_ijkl.tensor(1,1,1,1), c_ijkl.tensor(1,1,1,2),
                 c_ijkl.tensor(1,1,2,0), c_ijkl.tensor(1,1,2,1), c_ijkl.tensor(1,1,2,2)},  // ij 2,2
                {c_ijkl.tensor(1,2,0,0), c_ijkl.tensor(1,2,0,1), c_ijkl.tensor(1,2,0,2),
                 c_ijkl.tensor(1,2,1,0), c_ijkl.tensor(1,2,1,1), c_ijkl.tensor(1,2,1,2),
                 c_ijkl.tensor(1,2,2,0), c_ijkl.tensor(1,2,2,1), c_ijkl.tensor(1,2,2,2)},  // ij 2,3
                {c_ijkl.tensor(2,0,0,0), c_ijkl.tensor(2,0,0,1), c_ijkl.tensor(2,0,0,2),
                 c_ijkl.tensor(2,0,1,0), c_ijkl.tensor(2,0,1,1), c_ijkl.tensor(2,0,1,2),
                 c_ijkl.tensor(2,0,2,0), c_ijkl.tensor(2,0,2,1), c_ijkl.tensor(2,0,2,2)},  // ij 3,1
                {c_ijkl.tensor(2,1,0,0), c_ijkl.tensor(2,1,0,1), c_ijkl.tensor(2,1,0,2),
                 c_ijkl.tensor(2,1,1,0), c_ijkl.tensor(2,1,1,1), c_ijkl.tensor(2,1,1,2),
                 c_ijkl.tensor(2,1,2,0), c_ijkl.tensor(2,1,2,1), c_ijkl.tensor(2,1,2,2)},  // ij 3,2
                {c_ijkl.tensor(2,2,0,0), c_ijkl.tensor(2,2,0,1), c_ijkl.tensor(2,2,0,2),
                 c_ijkl.tensor(2,2,1,0), c_ijkl.tensor(2,2,1,1), c_ijkl.tensor(2,2,1,2),
                 c_ijkl.tensor(2,2,2,0), c_ijkl.tensor(2,2,2,1), c_ijkl.tensor(2,2,2,2)}   // ij 3,3
        };

        // create data arrays
        QBarDataArray *dataSet = new QBarDataArray;
        QBarDataRow *dataRow;

        dataSet->reserve(9);
        for (int ij = 0; ij < 9; ij++) {
            // Create a data row
            dataRow = new QBarDataRow(9);
            for (int kl = 0; kl < 9; kl++) {
                // Add data to the row
                (*dataRow)[kl].setValue(c_ijkl_data[ij][kl]);
            }
            // Add the row to the set
            dataSet->append(dataRow);
        }

        // Add data to the data proxy (the data proxy assumes ownership of it)
        primary_series->dataProxy()->resetArray(dataSet, ij_list, ij_list);
        break;
    }
    case 22: { // Corundum
        density_line_edit->setText(QString::number(mpc::data::CorundumDensity<double>()));
        bulk_modulus_line_edit->setText(QString::number(mpc::data::CorundumBulkModulus<double>()));
        shear_modulus_line_edit->setText(QString::number(mpc::data::CorundumShearModulus<double>()));
        c11_line_edit->setText(QString::number(mpc::data::CorundumC11<double>()));
        c12_line_edit->setText(QString::number(mpc::data::CorundumC12<double>()));
        c13_line_edit->setText(QString::number(mpc::data::CorundumC13<double>()));
        c14_line_edit->setText(QString::number(mpc::data::CorundumC14<double>()));
        c15_line_edit->setText(QString::number(mpc::data::CorundumC15<double>()));
        c16_line_edit->setText(QString::number(mpc::data::CorundumC16<double>()));
        c22_line_edit->setText(QString::number(mpc::data::CorundumC22<double>()));
        c23_line_edit->setText(QString::number(mpc::data::CorundumC23<double>()));
        c24_line_edit->setText(QString::number(mpc::data::CorundumC24<double>()));
        c25_line_edit->setText(QString::number(mpc::data::CorundumC25<double>()));
        c26_line_edit->setText(QString::number(mpc::data::CorundumC26<double>()));
        c33_line_edit->setText(QString::number(mpc::data::CorundumC33<double>()));
        c34_line_edit->setText(QString::number(mpc::data::CorundumC34<double>()));
        c35_line_edit->setText(QString::number(mpc::data::CorundumC35<double>()));
        c36_line_edit->setText(QString::number(mpc::data::CorundumC36<double>()));
        c44_line_edit->setText(QString::number(mpc::data::CorundumC44<double>()));
        c45_line_edit->setText(QString::number(mpc::data::CorundumC45<double>()));
        c46_line_edit->setText(QString::number(mpc::data::CorundumC46<double>()));
        c55_line_edit->setText(QString::number(mpc::data::CorundumC55<double>()));
        c56_line_edit->setText(QString::number(mpc::data::CorundumC56<double>()));
        c66_line_edit->setText(QString::number(mpc::data::CorundumC66<double>()));
        // data
        mpc::core::StiffnessTensor<float> c_ijkl = mpc::data::CorundumStiffnessTensor<float>();
        float c_ijkl_data[9][9] = {
                {c_ijkl.tensor(0,0,0,0), c_ijkl.tensor(0,0,0,1), c_ijkl.tensor(0,0,0,2),
                 c_ijkl.tensor(0,0,1,0), c_ijkl.tensor(0,0,1,1), c_ijkl.tensor(0,0,1,2),
                 c_ijkl.tensor(0,0,2,0), c_ijkl.tensor(0,0,2,1), c_ijkl.tensor(0,0,2,2)},  // ij 1,1
                {c_ijkl.tensor(0,1,0,0), c_ijkl.tensor(0,1,0,1), c_ijkl.tensor(0,1,0,2),
                 c_ijkl.tensor(0,1,1,0), c_ijkl.tensor(0,1,1,1), c_ijkl.tensor(0,1,1,2),
                 c_ijkl.tensor(0,1,2,0), c_ijkl.tensor(0,1,2,1), c_ijkl.tensor(0,1,2,2)},  // ij 1,2
                {c_ijkl.tensor(0,2,0,0), c_ijkl.tensor(0,2,0,1), c_ijkl.tensor(0,2,0,2),
                 c_ijkl.tensor(0,2,1,0), c_ijkl.tensor(0,2,1,1), c_ijkl.tensor(0,2,1,2),
                 c_ijkl.tensor(0,2,2,0), c_ijkl.tensor(0,2,2,1), c_ijkl.tensor(0,2,2,2)},  // ij 1,3
                {c_ijkl.tensor(1,0,0,0), c_ijkl.tensor(1,0,0,1), c_ijkl.tensor(1,0,0,2),
                 c_ijkl.tensor(1,0,1,0), c_ijkl.tensor(1,0,1,1), c_ijkl.tensor(1,0,1,2),
                 c_ijkl.tensor(1,0,2,0), c_ijkl.tensor(1,0,2,1), c_ijkl.tensor(1,0,2,2)},  // ij 2,1
                {c_ijkl.tensor(1,1,0,0), c_ijkl.tensor(1,1,0,1), c_ijkl.tensor(1,1,0,2),
                 c_ijkl.tensor(1,1,1,0), c_ijkl.tensor(1,1,1,1), c_ijkl.tensor(1,1,1,2),
                 c_ijkl.tensor(1,1,2,0), c_ijkl.tensor(1,1,2,1), c_ijkl.tensor(1,1,2,2)},  // ij 2,2
                {c_ijkl.tensor(1,2,0,0), c_ijkl.tensor(1,2,0,1), c_ijkl.tensor(1,2,0,2),
                 c_ijkl.tensor(1,2,1,0), c_ijkl.tensor(1,2,1,1), c_ijkl.tensor(1,2,1,2),
                 c_ijkl.tensor(1,2,2,0), c_ijkl.tensor(1,2,2,1), c_ijkl.tensor(1,2,2,2)},  // ij 2,3
                {c_ijkl.tensor(2,0,0,0), c_ijkl.tensor(2,0,0,1), c_ijkl.tensor(2,0,0,2),
                 c_ijkl.tensor(2,0,1,0), c_ijkl.tensor(2,0,1,1), c_ijkl.tensor(2,0,1,2),
                 c_ijkl.tensor(2,0,2,0), c_ijkl.tensor(2,0,2,1), c_ijkl.tensor(2,0,2,2)},  // ij 3,1
                {c_ijkl.tensor(2,1,0,0), c_ijkl.tensor(2,1,0,1), c_ijkl.tensor(2,1,0,2),
                 c_ijkl.tensor(2,1,1,0), c_ijkl.tensor(2,1,1,1), c_ijkl.tensor(2,1,1,2),
                 c_ijkl.tensor(2,1,2,0), c_ijkl.tensor(2,1,2,1), c_ijkl.tensor(2,1,2,2)},  // ij 3,2
                {c_ijkl.tensor(2,2,0,0), c_ijkl.tensor(2,2,0,1), c_ijkl.tensor(2,2,0,2),
                 c_ijkl.tensor(2,2,1,0), c_ijkl.tensor(2,2,1,1), c_ijkl.tensor(2,2,1,2),
                 c_ijkl.tensor(2,2,2,0), c_ijkl.tensor(2,2,2,1), c_ijkl.tensor(2,2,2,2)}   // ij 3,3
        };

        // create data arrays
        QBarDataArray *dataSet = new QBarDataArray;
        QBarDataRow *dataRow;

        dataSet->reserve(9);
        for (int ij = 0; ij < 9; ij++) {
            // Create a data row
            dataRow = new QBarDataRow(9);
            for (int kl = 0; kl < 9; kl++) {
                // Add data to the row
                (*dataRow)[kl].setValue(c_ijkl_data[ij][kl]);
            }
            // Add the row to the set
            dataSet->append(dataRow);
        }

        // Add data to the data proxy (the data proxy assumes ownership of it)
        primary_series->dataProxy()->resetArray(dataSet, ij_list, ij_list);
        break;
    }
    case 23: { // Calcite
        density_line_edit->setText(QString::number(mpc::data::CalciteDensity<double>()));
        bulk_modulus_line_edit->setText(QString::number(mpc::data::CalciteBulkModulus<double>()));
        shear_modulus_line_edit->setText(QString::number(mpc::data::CalciteShearModulus<double>()));
        c11_line_edit->setText(QString::number(mpc::data::CalciteC11<double>()));
        c12_line_edit->setText(QString::number(mpc::data::CalciteC12<double>()));
        c13_line_edit->setText(QString::number(mpc::data::CalciteC13<double>()));
        c14_line_edit->setText(QString::number(mpc::data::CalciteC14<double>()));
        c15_line_edit->setText(QString::number(mpc::data::CalciteC15<double>()));
        c16_line_edit->setText(QString::number(mpc::data::CalciteC16<double>()));
        c22_line_edit->setText(QString::number(mpc::data::CalciteC22<double>()));
        c23_line_edit->setText(QString::number(mpc::data::CalciteC23<double>()));
        c24_line_edit->setText(QString::number(mpc::data::CalciteC24<double>()));
        c25_line_edit->setText(QString::number(mpc::data::CalciteC25<double>()));
        c26_line_edit->setText(QString::number(mpc::data::CalciteC26<double>()));
        c33_line_edit->setText(QString::number(mpc::data::CalciteC33<double>()));
        c34_line_edit->setText(QString::number(mpc::data::CalciteC34<double>()));
        c35_line_edit->setText(QString::number(mpc::data::CalciteC35<double>()));
        c36_line_edit->setText(QString::number(mpc::data::CalciteC36<double>()));
        c44_line_edit->setText(QString::number(mpc::data::CalciteC44<double>()));
        c45_line_edit->setText(QString::number(mpc::data::CalciteC45<double>()));
        c46_line_edit->setText(QString::number(mpc::data::CalciteC46<double>()));
        c55_line_edit->setText(QString::number(mpc::data::CalciteC55<double>()));
        c56_line_edit->setText(QString::number(mpc::data::CalciteC56<double>()));
        c66_line_edit->setText(QString::number(mpc::data::CalciteC66<double>()));
        // data
        mpc::core::StiffnessTensor<float> c_ijkl = mpc::data::CalciteStiffnessTensor<float>();
        float c_ijkl_data[9][9] = {
                {c_ijkl.tensor(0,0,0,0), c_ijkl.tensor(0,0,0,1), c_ijkl.tensor(0,0,0,2),
                 c_ijkl.tensor(0,0,1,0), c_ijkl.tensor(0,0,1,1), c_ijkl.tensor(0,0,1,2),
                 c_ijkl.tensor(0,0,2,0), c_ijkl.tensor(0,0,2,1), c_ijkl.tensor(0,0,2,2)},  // ij 1,1
                {c_ijkl.tensor(0,1,0,0), c_ijkl.tensor(0,1,0,1), c_ijkl.tensor(0,1,0,2),
                 c_ijkl.tensor(0,1,1,0), c_ijkl.tensor(0,1,1,1), c_ijkl.tensor(0,1,1,2),
                 c_ijkl.tensor(0,1,2,0), c_ijkl.tensor(0,1,2,1), c_ijkl.tensor(0,1,2,2)},  // ij 1,2
                {c_ijkl.tensor(0,2,0,0), c_ijkl.tensor(0,2,0,1), c_ijkl.tensor(0,2,0,2),
                 c_ijkl.tensor(0,2,1,0), c_ijkl.tensor(0,2,1,1), c_ijkl.tensor(0,2,1,2),
                 c_ijkl.tensor(0,2,2,0), c_ijkl.tensor(0,2,2,1), c_ijkl.tensor(0,2,2,2)},  // ij 1,3
                {c_ijkl.tensor(1,0,0,0), c_ijkl.tensor(1,0,0,1), c_ijkl.tensor(1,0,0,2),
                 c_ijkl.tensor(1,0,1,0), c_ijkl.tensor(1,0,1,1), c_ijkl.tensor(1,0,1,2),
                 c_ijkl.tensor(1,0,2,0), c_ijkl.tensor(1,0,2,1), c_ijkl.tensor(1,0,2,2)},  // ij 2,1
                {c_ijkl.tensor(1,1,0,0), c_ijkl.tensor(1,1,0,1), c_ijkl.tensor(1,1,0,2),
                 c_ijkl.tensor(1,1,1,0), c_ijkl.tensor(1,1,1,1), c_ijkl.tensor(1,1,1,2),
                 c_ijkl.tensor(1,1,2,0), c_ijkl.tensor(1,1,2,1), c_ijkl.tensor(1,1,2,2)},  // ij 2,2
                {c_ijkl.tensor(1,2,0,0), c_ijkl.tensor(1,2,0,1), c_ijkl.tensor(1,2,0,2),
                 c_ijkl.tensor(1,2,1,0), c_ijkl.tensor(1,2,1,1), c_ijkl.tensor(1,2,1,2),
                 c_ijkl.tensor(1,2,2,0), c_ijkl.tensor(1,2,2,1), c_ijkl.tensor(1,2,2,2)},  // ij 2,3
                {c_ijkl.tensor(2,0,0,0), c_ijkl.tensor(2,0,0,1), c_ijkl.tensor(2,0,0,2),
                 c_ijkl.tensor(2,0,1,0), c_ijkl.tensor(2,0,1,1), c_ijkl.tensor(2,0,1,2),
                 c_ijkl.tensor(2,0,2,0), c_ijkl.tensor(2,0,2,1), c_ijkl.tensor(2,0,2,2)},  // ij 3,1
                {c_ijkl.tensor(2,1,0,0), c_ijkl.tensor(2,1,0,1), c_ijkl.tensor(2,1,0,2),
                 c_ijkl.tensor(2,1,1,0), c_ijkl.tensor(2,1,1,1), c_ijkl.tensor(2,1,1,2),
                 c_ijkl.tensor(2,1,2,0), c_ijkl.tensor(2,1,2,1), c_ijkl.tensor(2,1,2,2)},  // ij 3,2
                {c_ijkl.tensor(2,2,0,0), c_ijkl.tensor(2,2,0,1), c_ijkl.tensor(2,2,0,2),
                 c_ijkl.tensor(2,2,1,0), c_ijkl.tensor(2,2,1,1), c_ijkl.tensor(2,2,1,2),
                 c_ijkl.tensor(2,2,2,0), c_ijkl.tensor(2,2,2,1), c_ijkl.tensor(2,2,2,2)}   // ij 3,3
        };

        // create data arrays
        QBarDataArray *dataSet = new QBarDataArray;
        QBarDataRow *dataRow;

        dataSet->reserve(9);
        for (int ij = 0; ij < 9; ij++) {
            // Create a data row
            dataRow = new QBarDataRow(9);
            for (int kl = 0; kl < 9; kl++) {
                // Add data to the row
                (*dataRow)[kl].setValue(c_ijkl_data[ij][kl]);
            }
            // Add the row to the set
            dataSet->append(dataRow);
        }

        // Add data to the data proxy (the data proxy assumes ownership of it)
        primary_series->dataProxy()->resetArray(dataSet, ij_list, ij_list);
        break;
    }
    case 24: { // Quartz
        density_line_edit->setText(QString::number(mpc::data::QuartzDensity<double>()));
        bulk_modulus_line_edit->setText(QString::number(mpc::data::QuartzBulkModulus<double>()));
        shear_modulus_line_edit->setText(QString::number(mpc::data::QuartzShearModulus<double>()));
        c11_line_edit->setText(QString::number(mpc::data::QuartzC11<double>()));
        c12_line_edit->setText(QString::number(mpc::data::QuartzC12<double>()));
        c13_line_edit->setText(QString::number(mpc::data::QuartzC13<double>()));
        c14_line_edit->setText(QString::number(mpc::data::QuartzC14<double>()));
        c15_line_edit->setText(QString::number(mpc::data::QuartzC15<double>()));
        c16_line_edit->setText(QString::number(mpc::data::QuartzC16<double>()));
        c22_line_edit->setText(QString::number(mpc::data::QuartzC22<double>()));
        c23_line_edit->setText(QString::number(mpc::data::QuartzC23<double>()));
        c24_line_edit->setText(QString::number(mpc::data::QuartzC24<double>()));
        c25_line_edit->setText(QString::number(mpc::data::QuartzC25<double>()));
        c26_line_edit->setText(QString::number(mpc::data::QuartzC26<double>()));
        c33_line_edit->setText(QString::number(mpc::data::QuartzC33<double>()));
        c34_line_edit->setText(QString::number(mpc::data::QuartzC34<double>()));
        c35_line_edit->setText(QString::number(mpc::data::QuartzC35<double>()));
        c36_line_edit->setText(QString::number(mpc::data::QuartzC36<double>()));
        c44_line_edit->setText(QString::number(mpc::data::QuartzC44<double>()));
        c45_line_edit->setText(QString::number(mpc::data::QuartzC45<double>()));
        c46_line_edit->setText(QString::number(mpc::data::QuartzC46<double>()));
        c55_line_edit->setText(QString::number(mpc::data::QuartzC55<double>()));
        c56_line_edit->setText(QString::number(mpc::data::QuartzC56<double>()));
        c66_line_edit->setText(QString::number(mpc::data::QuartzC66<double>()));
        // data
        mpc::core::StiffnessTensor<float> c_ijkl = mpc::data::QuartzStiffnessTensor<float>();
        float c_ijkl_data[9][9] = {
                {c_ijkl.tensor(0,0,0,0), c_ijkl.tensor(0,0,0,1), c_ijkl.tensor(0,0,0,2),
                 c_ijkl.tensor(0,0,1,0), c_ijkl.tensor(0,0,1,1), c_ijkl.tensor(0,0,1,2),
                 c_ijkl.tensor(0,0,2,0), c_ijkl.tensor(0,0,2,1), c_ijkl.tensor(0,0,2,2)},  // ij 1,1
                {c_ijkl.tensor(0,1,0,0), c_ijkl.tensor(0,1,0,1), c_ijkl.tensor(0,1,0,2),
                 c_ijkl.tensor(0,1,1,0), c_ijkl.tensor(0,1,1,1), c_ijkl.tensor(0,1,1,2),
                 c_ijkl.tensor(0,1,2,0), c_ijkl.tensor(0,1,2,1), c_ijkl.tensor(0,1,2,2)},  // ij 1,2
                {c_ijkl.tensor(0,2,0,0), c_ijkl.tensor(0,2,0,1), c_ijkl.tensor(0,2,0,2),
                 c_ijkl.tensor(0,2,1,0), c_ijkl.tensor(0,2,1,1), c_ijkl.tensor(0,2,1,2),
                 c_ijkl.tensor(0,2,2,0), c_ijkl.tensor(0,2,2,1), c_ijkl.tensor(0,2,2,2)},  // ij 1,3
                {c_ijkl.tensor(1,0,0,0), c_ijkl.tensor(1,0,0,1), c_ijkl.tensor(1,0,0,2),
                 c_ijkl.tensor(1,0,1,0), c_ijkl.tensor(1,0,1,1), c_ijkl.tensor(1,0,1,2),
                 c_ijkl.tensor(1,0,2,0), c_ijkl.tensor(1,0,2,1), c_ijkl.tensor(1,0,2,2)},  // ij 2,1
                {c_ijkl.tensor(1,1,0,0), c_ijkl.tensor(1,1,0,1), c_ijkl.tensor(1,1,0,2),
                 c_ijkl.tensor(1,1,1,0), c_ijkl.tensor(1,1,1,1), c_ijkl.tensor(1,1,1,2),
                 c_ijkl.tensor(1,1,2,0), c_ijkl.tensor(1,1,2,1), c_ijkl.tensor(1,1,2,2)},  // ij 2,2
                {c_ijkl.tensor(1,2,0,0), c_ijkl.tensor(1,2,0,1), c_ijkl.tensor(1,2,0,2),
                 c_ijkl.tensor(1,2,1,0), c_ijkl.tensor(1,2,1,1), c_ijkl.tensor(1,2,1,2),
                 c_ijkl.tensor(1,2,2,0), c_ijkl.tensor(1,2,2,1), c_ijkl.tensor(1,2,2,2)},  // ij 2,3
                {c_ijkl.tensor(2,0,0,0), c_ijkl.tensor(2,0,0,1), c_ijkl.tensor(2,0,0,2),
                 c_ijkl.tensor(2,0,1,0), c_ijkl.tensor(2,0,1,1), c_ijkl.tensor(2,0,1,2),
                 c_ijkl.tensor(2,0,2,0), c_ijkl.tensor(2,0,2,1), c_ijkl.tensor(2,0,2,2)},  // ij 3,1
                {c_ijkl.tensor(2,1,0,0), c_ijkl.tensor(2,1,0,1), c_ijkl.tensor(2,1,0,2),
                 c_ijkl.tensor(2,1,1,0), c_ijkl.tensor(2,1,1,1), c_ijkl.tensor(2,1,1,2),
                 c_ijkl.tensor(2,1,2,0), c_ijkl.tensor(2,1,2,1), c_ijkl.tensor(2,1,2,2)},  // ij 3,2
                {c_ijkl.tensor(2,2,0,0), c_ijkl.tensor(2,2,0,1), c_ijkl.tensor(2,2,0,2),
                 c_ijkl.tensor(2,2,1,0), c_ijkl.tensor(2,2,1,1), c_ijkl.tensor(2,2,1,2),
                 c_ijkl.tensor(2,2,2,0), c_ijkl.tensor(2,2,2,1), c_ijkl.tensor(2,2,2,2)}   // ij 3,3
        };

        // create data arrays
        QBarDataArray *dataSet = new QBarDataArray;
        QBarDataRow *dataRow;

        dataSet->reserve(9);
        for (int ij = 0; ij < 9; ij++) {
            // Create a data row
            dataRow = new QBarDataRow(9);
            for (int kl = 0; kl < 9; kl++) {
                // Add data to the row
                (*dataRow)[kl].setValue(c_ijkl_data[ij][kl]);
            }
            // Add the row to the set
            dataSet->append(dataRow);
        }

        // Add data to the data proxy (the data proxy assumes ownership of it)
        primary_series->dataProxy()->resetArray(dataSet, ij_list, ij_list);
        break;
    }
    case 25: { // Tourmaline
        density_line_edit->setText(QString::number(mpc::data::TourmalineDensity<double>()));
        bulk_modulus_line_edit->setText(QString::number(mpc::data::TourmalineBulkModulus<double>()));
        shear_modulus_line_edit->setText(QString::number(mpc::data::TourmalineShearModulus<double>()));
        c11_line_edit->setText(QString::number(mpc::data::TourmalineC11<double>()));
        c12_line_edit->setText(QString::number(mpc::data::TourmalineC12<double>()));
        c13_line_edit->setText(QString::number(mpc::data::TourmalineC13<double>()));
        c14_line_edit->setText(QString::number(mpc::data::TourmalineC14<double>()));
        c15_line_edit->setText(QString::number(mpc::data::TourmalineC15<double>()));
        c16_line_edit->setText(QString::number(mpc::data::TourmalineC16<double>()));
        c22_line_edit->setText(QString::number(mpc::data::TourmalineC22<double>()));
        c23_line_edit->setText(QString::number(mpc::data::TourmalineC23<double>()));
        c24_line_edit->setText(QString::number(mpc::data::TourmalineC24<double>()));
        c25_line_edit->setText(QString::number(mpc::data::TourmalineC25<double>()));
        c26_line_edit->setText(QString::number(mpc::data::TourmalineC26<double>()));
        c33_line_edit->setText(QString::number(mpc::data::TourmalineC33<double>()));
        c34_line_edit->setText(QString::number(mpc::data::TourmalineC34<double>()));
        c35_line_edit->setText(QString::number(mpc::data::TourmalineC35<double>()));
        c36_line_edit->setText(QString::number(mpc::data::TourmalineC36<double>()));
        c44_line_edit->setText(QString::number(mpc::data::TourmalineC44<double>()));
        c45_line_edit->setText(QString::number(mpc::data::TourmalineC45<double>()));
        c46_line_edit->setText(QString::number(mpc::data::TourmalineC46<double>()));
        c55_line_edit->setText(QString::number(mpc::data::TourmalineC55<double>()));
        c56_line_edit->setText(QString::number(mpc::data::TourmalineC56<double>()));
        c66_line_edit->setText(QString::number(mpc::data::TourmalineC66<double>()));
        // data
        mpc::core::StiffnessTensor<float> c_ijkl = mpc::data::TourmalineStiffnessTensor<float>();
        float c_ijkl_data[9][9] = {
                {c_ijkl.tensor(0,0,0,0), c_ijkl.tensor(0,0,0,1), c_ijkl.tensor(0,0,0,2),
                 c_ijkl.tensor(0,0,1,0), c_ijkl.tensor(0,0,1,1), c_ijkl.tensor(0,0,1,2),
                 c_ijkl.tensor(0,0,2,0), c_ijkl.tensor(0,0,2,1), c_ijkl.tensor(0,0,2,2)},  // ij 1,1
                {c_ijkl.tensor(0,1,0,0), c_ijkl.tensor(0,1,0,1), c_ijkl.tensor(0,1,0,2),
                 c_ijkl.tensor(0,1,1,0), c_ijkl.tensor(0,1,1,1), c_ijkl.tensor(0,1,1,2),
                 c_ijkl.tensor(0,1,2,0), c_ijkl.tensor(0,1,2,1), c_ijkl.tensor(0,1,2,2)},  // ij 1,2
                {c_ijkl.tensor(0,2,0,0), c_ijkl.tensor(0,2,0,1), c_ijkl.tensor(0,2,0,2),
                 c_ijkl.tensor(0,2,1,0), c_ijkl.tensor(0,2,1,1), c_ijkl.tensor(0,2,1,2),
                 c_ijkl.tensor(0,2,2,0), c_ijkl.tensor(0,2,2,1), c_ijkl.tensor(0,2,2,2)},  // ij 1,3
                {c_ijkl.tensor(1,0,0,0), c_ijkl.tensor(1,0,0,1), c_ijkl.tensor(1,0,0,2),
                 c_ijkl.tensor(1,0,1,0), c_ijkl.tensor(1,0,1,1), c_ijkl.tensor(1,0,1,2),
                 c_ijkl.tensor(1,0,2,0), c_ijkl.tensor(1,0,2,1), c_ijkl.tensor(1,0,2,2)},  // ij 2,1
                {c_ijkl.tensor(1,1,0,0), c_ijkl.tensor(1,1,0,1), c_ijkl.tensor(1,1,0,2),
                 c_ijkl.tensor(1,1,1,0), c_ijkl.tensor(1,1,1,1), c_ijkl.tensor(1,1,1,2),
                 c_ijkl.tensor(1,1,2,0), c_ijkl.tensor(1,1,2,1), c_ijkl.tensor(1,1,2,2)},  // ij 2,2
                {c_ijkl.tensor(1,2,0,0), c_ijkl.tensor(1,2,0,1), c_ijkl.tensor(1,2,0,2),
                 c_ijkl.tensor(1,2,1,0), c_ijkl.tensor(1,2,1,1), c_ijkl.tensor(1,2,1,2),
                 c_ijkl.tensor(1,2,2,0), c_ijkl.tensor(1,2,2,1), c_ijkl.tensor(1,2,2,2)},  // ij 2,3
                {c_ijkl.tensor(2,0,0,0), c_ijkl.tensor(2,0,0,1), c_ijkl.tensor(2,0,0,2),
                 c_ijkl.tensor(2,0,1,0), c_ijkl.tensor(2,0,1,1), c_ijkl.tensor(2,0,1,2),
                 c_ijkl.tensor(2,0,2,0), c_ijkl.tensor(2,0,2,1), c_ijkl.tensor(2,0,2,2)},  // ij 3,1
                {c_ijkl.tensor(2,1,0,0), c_ijkl.tensor(2,1,0,1), c_ijkl.tensor(2,1,0,2),
                 c_ijkl.tensor(2,1,1,0), c_ijkl.tensor(2,1,1,1), c_ijkl.tensor(2,1,1,2),
                 c_ijkl.tensor(2,1,2,0), c_ijkl.tensor(2,1,2,1), c_ijkl.tensor(2,1,2,2)},  // ij 3,2
                {c_ijkl.tensor(2,2,0,0), c_ijkl.tensor(2,2,0,1), c_ijkl.tensor(2,2,0,2),
                 c_ijkl.tensor(2,2,1,0), c_ijkl.tensor(2,2,1,1), c_ijkl.tensor(2,2,1,2),
                 c_ijkl.tensor(2,2,2,0), c_ijkl.tensor(2,2,2,1), c_ijkl.tensor(2,2,2,2)}   // ij 3,3
        };

        // create data arrays
        QBarDataArray *dataSet = new QBarDataArray;
        QBarDataRow *dataRow;

        dataSet->reserve(9);
        for (int ij = 0; ij < 9; ij++) {
            // Create a data row
            dataRow = new QBarDataRow(9);
            for (int kl = 0; kl < 9; kl++) {
                // Add data to the row
                (*dataRow)[kl].setValue(c_ijkl_data[ij][kl]);
            }
            // Add the row to the set
            dataSet->append(dataRow);
        }

        // Add data to the data proxy (the data proxy assumes ownership of it)
        primary_series->dataProxy()->resetArray(dataSet, ij_list, ij_list);
        break;
    }
    case 26: { // Beryl
        density_line_edit->setText(QString::number(mpc::data::BerylDensity<double>()));
        bulk_modulus_line_edit->setText(QString::number(mpc::data::BerylBulkModulus<double>()));
        shear_modulus_line_edit->setText(QString::number(mpc::data::BerylShearModulus<double>()));
        c11_line_edit->setText(QString::number(mpc::data::BerylC11<double>()));
        c12_line_edit->setText(QString::number(mpc::data::BerylC12<double>()));
        c13_line_edit->setText(QString::number(mpc::data::BerylC13<double>()));
        c14_line_edit->setText(QString::number(mpc::data::BerylC14<double>()));
        c15_line_edit->setText(QString::number(mpc::data::BerylC15<double>()));
        c16_line_edit->setText(QString::number(mpc::data::BerylC16<double>()));
        c22_line_edit->setText(QString::number(mpc::data::BerylC22<double>()));
        c23_line_edit->setText(QString::number(mpc::data::BerylC23<double>()));
        c24_line_edit->setText(QString::number(mpc::data::BerylC24<double>()));
        c25_line_edit->setText(QString::number(mpc::data::BerylC25<double>()));
        c26_line_edit->setText(QString::number(mpc::data::BerylC26<double>()));
        c33_line_edit->setText(QString::number(mpc::data::BerylC33<double>()));
        c34_line_edit->setText(QString::number(mpc::data::BerylC34<double>()));
        c35_line_edit->setText(QString::number(mpc::data::BerylC35<double>()));
        c36_line_edit->setText(QString::number(mpc::data::BerylC36<double>()));
        c44_line_edit->setText(QString::number(mpc::data::BerylC44<double>()));
        c45_line_edit->setText(QString::number(mpc::data::BerylC45<double>()));
        c46_line_edit->setText(QString::number(mpc::data::BerylC46<double>()));
        c55_line_edit->setText(QString::number(mpc::data::BerylC55<double>()));
        c56_line_edit->setText(QString::number(mpc::data::BerylC56<double>()));
        c66_line_edit->setText(QString::number(mpc::data::BerylC66<double>()));
        // data
        mpc::core::StiffnessTensor<float> c_ijkl = mpc::data::BerylStiffnessTensor<float>();
        float c_ijkl_data[9][9] = {
                {c_ijkl.tensor(0,0,0,0), c_ijkl.tensor(0,0,0,1), c_ijkl.tensor(0,0,0,2),
                 c_ijkl.tensor(0,0,1,0), c_ijkl.tensor(0,0,1,1), c_ijkl.tensor(0,0,1,2),
                 c_ijkl.tensor(0,0,2,0), c_ijkl.tensor(0,0,2,1), c_ijkl.tensor(0,0,2,2)},  // ij 1,1
                {c_ijkl.tensor(0,1,0,0), c_ijkl.tensor(0,1,0,1), c_ijkl.tensor(0,1,0,2),
                 c_ijkl.tensor(0,1,1,0), c_ijkl.tensor(0,1,1,1), c_ijkl.tensor(0,1,1,2),
                 c_ijkl.tensor(0,1,2,0), c_ijkl.tensor(0,1,2,1), c_ijkl.tensor(0,1,2,2)},  // ij 1,2
                {c_ijkl.tensor(0,2,0,0), c_ijkl.tensor(0,2,0,1), c_ijkl.tensor(0,2,0,2),
                 c_ijkl.tensor(0,2,1,0), c_ijkl.tensor(0,2,1,1), c_ijkl.tensor(0,2,1,2),
                 c_ijkl.tensor(0,2,2,0), c_ijkl.tensor(0,2,2,1), c_ijkl.tensor(0,2,2,2)},  // ij 1,3
                {c_ijkl.tensor(1,0,0,0), c_ijkl.tensor(1,0,0,1), c_ijkl.tensor(1,0,0,2),
                 c_ijkl.tensor(1,0,1,0), c_ijkl.tensor(1,0,1,1), c_ijkl.tensor(1,0,1,2),
                 c_ijkl.tensor(1,0,2,0), c_ijkl.tensor(1,0,2,1), c_ijkl.tensor(1,0,2,2)},  // ij 2,1
                {c_ijkl.tensor(1,1,0,0), c_ijkl.tensor(1,1,0,1), c_ijkl.tensor(1,1,0,2),
                 c_ijkl.tensor(1,1,1,0), c_ijkl.tensor(1,1,1,1), c_ijkl.tensor(1,1,1,2),
                 c_ijkl.tensor(1,1,2,0), c_ijkl.tensor(1,1,2,1), c_ijkl.tensor(1,1,2,2)},  // ij 2,2
                {c_ijkl.tensor(1,2,0,0), c_ijkl.tensor(1,2,0,1), c_ijkl.tensor(1,2,0,2),
                 c_ijkl.tensor(1,2,1,0), c_ijkl.tensor(1,2,1,1), c_ijkl.tensor(1,2,1,2),
                 c_ijkl.tensor(1,2,2,0), c_ijkl.tensor(1,2,2,1), c_ijkl.tensor(1,2,2,2)},  // ij 2,3
                {c_ijkl.tensor(2,0,0,0), c_ijkl.tensor(2,0,0,1), c_ijkl.tensor(2,0,0,2),
                 c_ijkl.tensor(2,0,1,0), c_ijkl.tensor(2,0,1,1), c_ijkl.tensor(2,0,1,2),
                 c_ijkl.tensor(2,0,2,0), c_ijkl.tensor(2,0,2,1), c_ijkl.tensor(2,0,2,2)},  // ij 3,1
                {c_ijkl.tensor(2,1,0,0), c_ijkl.tensor(2,1,0,1), c_ijkl.tensor(2,1,0,2),
                 c_ijkl.tensor(2,1,1,0), c_ijkl.tensor(2,1,1,1), c_ijkl.tensor(2,1,1,2),
                 c_ijkl.tensor(2,1,2,0), c_ijkl.tensor(2,1,2,1), c_ijkl.tensor(2,1,2,2)},  // ij 3,2
                {c_ijkl.tensor(2,2,0,0), c_ijkl.tensor(2,2,0,1), c_ijkl.tensor(2,2,0,2),
                 c_ijkl.tensor(2,2,1,0), c_ijkl.tensor(2,2,1,1), c_ijkl.tensor(2,2,1,2),
                 c_ijkl.tensor(2,2,2,0), c_ijkl.tensor(2,2,2,1), c_ijkl.tensor(2,2,2,2)}   // ij 3,3
        };

        // create data arrays
        QBarDataArray *dataSet = new QBarDataArray;
        QBarDataRow *dataRow;

        dataSet->reserve(9);
        for (int ij = 0; ij < 9; ij++) {
            // Create a data row
            dataRow = new QBarDataRow(9);
            for (int kl = 0; kl < 9; kl++) {
                // Add data to the row
                (*dataRow)[kl].setValue(c_ijkl_data[ij][kl]);
            }
            // Add the row to the set
            dataSet->append(dataRow);
        }

        // Add data to the data proxy (the data proxy assumes ownership of it)
        primary_series->dataProxy()->resetArray(dataSet, ij_list, ij_list);
        break;
    }
    case 27: { // Graphite
        density_line_edit->setText(QString::number(mpc::data::GraphiteDensity<double>()));
        bulk_modulus_line_edit->setText(QString::number(mpc::data::GraphiteBulkModulus<double>()));
        shear_modulus_line_edit->setText(QString::number(mpc::data::GraphiteShearModulus<double>()));
        c11_line_edit->setText(QString::number(mpc::data::GraphiteC11<double>()));
        c12_line_edit->setText(QString::number(mpc::data::GraphiteC12<double>()));
        c13_line_edit->setText(QString::number(mpc::data::GraphiteC13<double>()));
        c14_line_edit->setText(QString::number(mpc::data::GraphiteC14<double>()));
        c15_line_edit->setText(QString::number(mpc::data::GraphiteC15<double>()));
        c16_line_edit->setText(QString::number(mpc::data::GraphiteC16<double>()));
        c22_line_edit->setText(QString::number(mpc::data::GraphiteC22<double>()));
        c23_line_edit->setText(QString::number(mpc::data::GraphiteC23<double>()));
        c24_line_edit->setText(QString::number(mpc::data::GraphiteC24<double>()));
        c25_line_edit->setText(QString::number(mpc::data::GraphiteC25<double>()));
        c26_line_edit->setText(QString::number(mpc::data::GraphiteC26<double>()));
        c33_line_edit->setText(QString::number(mpc::data::GraphiteC33<double>()));
        c34_line_edit->setText(QString::number(mpc::data::GraphiteC34<double>()));
        c35_line_edit->setText(QString::number(mpc::data::GraphiteC35<double>()));
        c36_line_edit->setText(QString::number(mpc::data::GraphiteC36<double>()));
        c44_line_edit->setText(QString::number(mpc::data::GraphiteC44<double>()));
        c45_line_edit->setText(QString::number(mpc::data::GraphiteC45<double>()));
        c46_line_edit->setText(QString::number(mpc::data::GraphiteC46<double>()));
        c55_line_edit->setText(QString::number(mpc::data::GraphiteC55<double>()));
        c56_line_edit->setText(QString::number(mpc::data::GraphiteC56<double>()));
        c66_line_edit->setText(QString::number(mpc::data::GraphiteC66<double>()));
        // data
        mpc::core::StiffnessTensor<float> c_ijkl = mpc::data::GraphiteStiffnessTensor<float>();
        float c_ijkl_data[9][9] = {
                {c_ijkl.tensor(0,0,0,0), c_ijkl.tensor(0,0,0,1), c_ijkl.tensor(0,0,0,2),
                 c_ijkl.tensor(0,0,1,0), c_ijkl.tensor(0,0,1,1), c_ijkl.tensor(0,0,1,2),
                 c_ijkl.tensor(0,0,2,0), c_ijkl.tensor(0,0,2,1), c_ijkl.tensor(0,0,2,2)},  // ij 1,1
                {c_ijkl.tensor(0,1,0,0), c_ijkl.tensor(0,1,0,1), c_ijkl.tensor(0,1,0,2),
                 c_ijkl.tensor(0,1,1,0), c_ijkl.tensor(0,1,1,1), c_ijkl.tensor(0,1,1,2),
                 c_ijkl.tensor(0,1,2,0), c_ijkl.tensor(0,1,2,1), c_ijkl.tensor(0,1,2,2)},  // ij 1,2
                {c_ijkl.tensor(0,2,0,0), c_ijkl.tensor(0,2,0,1), c_ijkl.tensor(0,2,0,2),
                 c_ijkl.tensor(0,2,1,0), c_ijkl.tensor(0,2,1,1), c_ijkl.tensor(0,2,1,2),
                 c_ijkl.tensor(0,2,2,0), c_ijkl.tensor(0,2,2,1), c_ijkl.tensor(0,2,2,2)},  // ij 1,3
                {c_ijkl.tensor(1,0,0,0), c_ijkl.tensor(1,0,0,1), c_ijkl.tensor(1,0,0,2),
                 c_ijkl.tensor(1,0,1,0), c_ijkl.tensor(1,0,1,1), c_ijkl.tensor(1,0,1,2),
                 c_ijkl.tensor(1,0,2,0), c_ijkl.tensor(1,0,2,1), c_ijkl.tensor(1,0,2,2)},  // ij 2,1
                {c_ijkl.tensor(1,1,0,0), c_ijkl.tensor(1,1,0,1), c_ijkl.tensor(1,1,0,2),
                 c_ijkl.tensor(1,1,1,0), c_ijkl.tensor(1,1,1,1), c_ijkl.tensor(1,1,1,2),
                 c_ijkl.tensor(1,1,2,0), c_ijkl.tensor(1,1,2,1), c_ijkl.tensor(1,1,2,2)},  // ij 2,2
                {c_ijkl.tensor(1,2,0,0), c_ijkl.tensor(1,2,0,1), c_ijkl.tensor(1,2,0,2),
                 c_ijkl.tensor(1,2,1,0), c_ijkl.tensor(1,2,1,1), c_ijkl.tensor(1,2,1,2),
                 c_ijkl.tensor(1,2,2,0), c_ijkl.tensor(1,2,2,1), c_ijkl.tensor(1,2,2,2)},  // ij 2,3
                {c_ijkl.tensor(2,0,0,0), c_ijkl.tensor(2,0,0,1), c_ijkl.tensor(2,0,0,2),
                 c_ijkl.tensor(2,0,1,0), c_ijkl.tensor(2,0,1,1), c_ijkl.tensor(2,0,1,2),
                 c_ijkl.tensor(2,0,2,0), c_ijkl.tensor(2,0,2,1), c_ijkl.tensor(2,0,2,2)},  // ij 3,1
                {c_ijkl.tensor(2,1,0,0), c_ijkl.tensor(2,1,0,1), c_ijkl.tensor(2,1,0,2),
                 c_ijkl.tensor(2,1,1,0), c_ijkl.tensor(2,1,1,1), c_ijkl.tensor(2,1,1,2),
                 c_ijkl.tensor(2,1,2,0), c_ijkl.tensor(2,1,2,1), c_ijkl.tensor(2,1,2,2)},  // ij 3,2
                {c_ijkl.tensor(2,2,0,0), c_ijkl.tensor(2,2,0,1), c_ijkl.tensor(2,2,0,2),
                 c_ijkl.tensor(2,2,1,0), c_ijkl.tensor(2,2,1,1), c_ijkl.tensor(2,2,1,2),
                 c_ijkl.tensor(2,2,2,0), c_ijkl.tensor(2,2,2,1), c_ijkl.tensor(2,2,2,2)}   // ij 3,3
        };

        // create data arrays
        QBarDataArray *dataSet = new QBarDataArray;
        QBarDataRow *dataRow;

        dataSet->reserve(9);
        for (int ij = 0; ij < 9; ij++) {
            // Create a data row
            dataRow = new QBarDataRow(9);
            for (int kl = 0; kl < 9; kl++) {
                // Add data to the row
                (*dataRow)[kl].setValue(c_ijkl_data[ij][kl]);
            }
            // Add the row to the set
            dataSet->append(dataRow);
        }

        // Add data to the data proxy (the data proxy assumes ownership of it)
        primary_series->dataProxy()->resetArray(dataSet, ij_list, ij_list);
        break;
    }
    case 28: { // Wusite
        density_line_edit->setText(QString::number(mpc::data::WusiteDensity<double>()));
        bulk_modulus_line_edit->setText(QString::number(mpc::data::WusiteBulkModulus<double>()));
        shear_modulus_line_edit->setText(QString::number(mpc::data::WusiteShearModulus<double>()));
        c11_line_edit->setText(QString::number(mpc::data::WusiteC11<double>()));
        c12_line_edit->setText(QString::number(mpc::data::WusiteC12<double>()));
        c13_line_edit->setText(QString::number(mpc::data::WusiteC13<double>()));
        c14_line_edit->setText(QString::number(mpc::data::WusiteC14<double>()));
        c15_line_edit->setText(QString::number(mpc::data::WusiteC15<double>()));
        c16_line_edit->setText(QString::number(mpc::data::WusiteC16<double>()));
        c22_line_edit->setText(QString::number(mpc::data::WusiteC22<double>()));
        c23_line_edit->setText(QString::number(mpc::data::WusiteC23<double>()));
        c24_line_edit->setText(QString::number(mpc::data::WusiteC24<double>()));
        c25_line_edit->setText(QString::number(mpc::data::WusiteC25<double>()));
        c26_line_edit->setText(QString::number(mpc::data::WusiteC26<double>()));
        c33_line_edit->setText(QString::number(mpc::data::WusiteC33<double>()));
        c34_line_edit->setText(QString::number(mpc::data::WusiteC34<double>()));
        c35_line_edit->setText(QString::number(mpc::data::WusiteC35<double>()));
        c36_line_edit->setText(QString::number(mpc::data::WusiteC36<double>()));
        c44_line_edit->setText(QString::number(mpc::data::WusiteC44<double>()));
        c45_line_edit->setText(QString::number(mpc::data::WusiteC45<double>()));
        c46_line_edit->setText(QString::number(mpc::data::WusiteC46<double>()));
        c55_line_edit->setText(QString::number(mpc::data::WusiteC55<double>()));
        c56_line_edit->setText(QString::number(mpc::data::WusiteC56<double>()));
        c66_line_edit->setText(QString::number(mpc::data::WusiteC66<double>()));
        // data
        mpc::core::StiffnessTensor<float> c_ijkl = mpc::data::WusiteStiffnessTensor<float>();
        float c_ijkl_data[9][9] = {
                {c_ijkl.tensor(0,0,0,0), c_ijkl.tensor(0,0,0,1), c_ijkl.tensor(0,0,0,2),
                 c_ijkl.tensor(0,0,1,0), c_ijkl.tensor(0,0,1,1), c_ijkl.tensor(0,0,1,2),
                 c_ijkl.tensor(0,0,2,0), c_ijkl.tensor(0,0,2,1), c_ijkl.tensor(0,0,2,2)},  // ij 1,1
                {c_ijkl.tensor(0,1,0,0), c_ijkl.tensor(0,1,0,1), c_ijkl.tensor(0,1,0,2),
                 c_ijkl.tensor(0,1,1,0), c_ijkl.tensor(0,1,1,1), c_ijkl.tensor(0,1,1,2),
                 c_ijkl.tensor(0,1,2,0), c_ijkl.tensor(0,1,2,1), c_ijkl.tensor(0,1,2,2)},  // ij 1,2
                {c_ijkl.tensor(0,2,0,0), c_ijkl.tensor(0,2,0,1), c_ijkl.tensor(0,2,0,2),
                 c_ijkl.tensor(0,2,1,0), c_ijkl.tensor(0,2,1,1), c_ijkl.tensor(0,2,1,2),
                 c_ijkl.tensor(0,2,2,0), c_ijkl.tensor(0,2,2,1), c_ijkl.tensor(0,2,2,2)},  // ij 1,3
                {c_ijkl.tensor(1,0,0,0), c_ijkl.tensor(1,0,0,1), c_ijkl.tensor(1,0,0,2),
                 c_ijkl.tensor(1,0,1,0), c_ijkl.tensor(1,0,1,1), c_ijkl.tensor(1,0,1,2),
                 c_ijkl.tensor(1,0,2,0), c_ijkl.tensor(1,0,2,1), c_ijkl.tensor(1,0,2,2)},  // ij 2,1
                {c_ijkl.tensor(1,1,0,0), c_ijkl.tensor(1,1,0,1), c_ijkl.tensor(1,1,0,2),
                 c_ijkl.tensor(1,1,1,0), c_ijkl.tensor(1,1,1,1), c_ijkl.tensor(1,1,1,2),
                 c_ijkl.tensor(1,1,2,0), c_ijkl.tensor(1,1,2,1), c_ijkl.tensor(1,1,2,2)},  // ij 2,2
                {c_ijkl.tensor(1,2,0,0), c_ijkl.tensor(1,2,0,1), c_ijkl.tensor(1,2,0,2),
                 c_ijkl.tensor(1,2,1,0), c_ijkl.tensor(1,2,1,1), c_ijkl.tensor(1,2,1,2),
                 c_ijkl.tensor(1,2,2,0), c_ijkl.tensor(1,2,2,1), c_ijkl.tensor(1,2,2,2)},  // ij 2,3
                {c_ijkl.tensor(2,0,0,0), c_ijkl.tensor(2,0,0,1), c_ijkl.tensor(2,0,0,2),
                 c_ijkl.tensor(2,0,1,0), c_ijkl.tensor(2,0,1,1), c_ijkl.tensor(2,0,1,2),
                 c_ijkl.tensor(2,0,2,0), c_ijkl.tensor(2,0,2,1), c_ijkl.tensor(2,0,2,2)},  // ij 3,1
                {c_ijkl.tensor(2,1,0,0), c_ijkl.tensor(2,1,0,1), c_ijkl.tensor(2,1,0,2),
                 c_ijkl.tensor(2,1,1,0), c_ijkl.tensor(2,1,1,1), c_ijkl.tensor(2,1,1,2),
                 c_ijkl.tensor(2,1,2,0), c_ijkl.tensor(2,1,2,1), c_ijkl.tensor(2,1,2,2)},  // ij 3,2
                {c_ijkl.tensor(2,2,0,0), c_ijkl.tensor(2,2,0,1), c_ijkl.tensor(2,2,0,2),
                 c_ijkl.tensor(2,2,1,0), c_ijkl.tensor(2,2,1,1), c_ijkl.tensor(2,2,1,2),
                 c_ijkl.tensor(2,2,2,0), c_ijkl.tensor(2,2,2,1), c_ijkl.tensor(2,2,2,2)}   // ij 3,3
        };

        // create data arrays
        QBarDataArray *dataSet = new QBarDataArray;
        QBarDataRow *dataRow;

        dataSet->reserve(9);
        for (int ij = 0; ij < 9; ij++) {
            // Create a data row
            dataRow = new QBarDataRow(9);
            for (int kl = 0; kl < 9; kl++) {
                // Add data to the row
                (*dataRow)[kl].setValue(c_ijkl_data[ij][kl]);
            }
            // Add the row to the set
            dataSet->append(dataRow);
        }

        // Add data to the data proxy (the data proxy assumes ownership of it)
        primary_series->dataProxy()->resetArray(dataSet, ij_list, ij_list);
        break;
    }
    case 29: { // Manganosite
        density_line_edit->setText(QString::number(mpc::data::ManganositeDensity<double>()));
        bulk_modulus_line_edit->setText(QString::number(mpc::data::ManganositeBulkModulus<double>()));
        shear_modulus_line_edit->setText(QString::number(mpc::data::ManganositeShearModulus<double>()));
        c11_line_edit->setText(QString::number(mpc::data::ManganositeC11<double>()));
        c12_line_edit->setText(QString::number(mpc::data::ManganositeC12<double>()));
        c13_line_edit->setText(QString::number(mpc::data::ManganositeC13<double>()));
        c14_line_edit->setText(QString::number(mpc::data::ManganositeC14<double>()));
        c15_line_edit->setText(QString::number(mpc::data::ManganositeC15<double>()));
        c16_line_edit->setText(QString::number(mpc::data::ManganositeC16<double>()));
        c22_line_edit->setText(QString::number(mpc::data::ManganositeC22<double>()));
        c23_line_edit->setText(QString::number(mpc::data::ManganositeC23<double>()));
        c24_line_edit->setText(QString::number(mpc::data::ManganositeC24<double>()));
        c25_line_edit->setText(QString::number(mpc::data::ManganositeC25<double>()));
        c26_line_edit->setText(QString::number(mpc::data::ManganositeC26<double>()));
        c33_line_edit->setText(QString::number(mpc::data::ManganositeC33<double>()));
        c34_line_edit->setText(QString::number(mpc::data::ManganositeC34<double>()));
        c35_line_edit->setText(QString::number(mpc::data::ManganositeC35<double>()));
        c36_line_edit->setText(QString::number(mpc::data::ManganositeC36<double>()));
        c44_line_edit->setText(QString::number(mpc::data::ManganositeC44<double>()));
        c45_line_edit->setText(QString::number(mpc::data::ManganositeC45<double>()));
        c46_line_edit->setText(QString::number(mpc::data::ManganositeC46<double>()));
        c55_line_edit->setText(QString::number(mpc::data::ManganositeC55<double>()));
        c56_line_edit->setText(QString::number(mpc::data::ManganositeC56<double>()));
        c66_line_edit->setText(QString::number(mpc::data::ManganositeC66<double>()));
        // data
        mpc::core::StiffnessTensor<float> c_ijkl = mpc::data::ManganositeStiffnessTensor<float>();
        float c_ijkl_data[9][9] = {
                {c_ijkl.tensor(0,0,0,0), c_ijkl.tensor(0,0,0,1), c_ijkl.tensor(0,0,0,2),
                 c_ijkl.tensor(0,0,1,0), c_ijkl.tensor(0,0,1,1), c_ijkl.tensor(0,0,1,2),
                 c_ijkl.tensor(0,0,2,0), c_ijkl.tensor(0,0,2,1), c_ijkl.tensor(0,0,2,2)},  // ij 1,1
                {c_ijkl.tensor(0,1,0,0), c_ijkl.tensor(0,1,0,1), c_ijkl.tensor(0,1,0,2),
                 c_ijkl.tensor(0,1,1,0), c_ijkl.tensor(0,1,1,1), c_ijkl.tensor(0,1,1,2),
                 c_ijkl.tensor(0,1,2,0), c_ijkl.tensor(0,1,2,1), c_ijkl.tensor(0,1,2,2)},  // ij 1,2
                {c_ijkl.tensor(0,2,0,0), c_ijkl.tensor(0,2,0,1), c_ijkl.tensor(0,2,0,2),
                 c_ijkl.tensor(0,2,1,0), c_ijkl.tensor(0,2,1,1), c_ijkl.tensor(0,2,1,2),
                 c_ijkl.tensor(0,2,2,0), c_ijkl.tensor(0,2,2,1), c_ijkl.tensor(0,2,2,2)},  // ij 1,3
                {c_ijkl.tensor(1,0,0,0), c_ijkl.tensor(1,0,0,1), c_ijkl.tensor(1,0,0,2),
                 c_ijkl.tensor(1,0,1,0), c_ijkl.tensor(1,0,1,1), c_ijkl.tensor(1,0,1,2),
                 c_ijkl.tensor(1,0,2,0), c_ijkl.tensor(1,0,2,1), c_ijkl.tensor(1,0,2,2)},  // ij 2,1
                {c_ijkl.tensor(1,1,0,0), c_ijkl.tensor(1,1,0,1), c_ijkl.tensor(1,1,0,2),
                 c_ijkl.tensor(1,1,1,0), c_ijkl.tensor(1,1,1,1), c_ijkl.tensor(1,1,1,2),
                 c_ijkl.tensor(1,1,2,0), c_ijkl.tensor(1,1,2,1), c_ijkl.tensor(1,1,2,2)},  // ij 2,2
                {c_ijkl.tensor(1,2,0,0), c_ijkl.tensor(1,2,0,1), c_ijkl.tensor(1,2,0,2),
                 c_ijkl.tensor(1,2,1,0), c_ijkl.tensor(1,2,1,1), c_ijkl.tensor(1,2,1,2),
                 c_ijkl.tensor(1,2,2,0), c_ijkl.tensor(1,2,2,1), c_ijkl.tensor(1,2,2,2)},  // ij 2,3
                {c_ijkl.tensor(2,0,0,0), c_ijkl.tensor(2,0,0,1), c_ijkl.tensor(2,0,0,2),
                 c_ijkl.tensor(2,0,1,0), c_ijkl.tensor(2,0,1,1), c_ijkl.tensor(2,0,1,2),
                 c_ijkl.tensor(2,0,2,0), c_ijkl.tensor(2,0,2,1), c_ijkl.tensor(2,0,2,2)},  // ij 3,1
                {c_ijkl.tensor(2,1,0,0), c_ijkl.tensor(2,1,0,1), c_ijkl.tensor(2,1,0,2),
                 c_ijkl.tensor(2,1,1,0), c_ijkl.tensor(2,1,1,1), c_ijkl.tensor(2,1,1,2),
                 c_ijkl.tensor(2,1,2,0), c_ijkl.tensor(2,1,2,1), c_ijkl.tensor(2,1,2,2)},  // ij 3,2
                {c_ijkl.tensor(2,2,0,0), c_ijkl.tensor(2,2,0,1), c_ijkl.tensor(2,2,0,2),
                 c_ijkl.tensor(2,2,1,0), c_ijkl.tensor(2,2,1,1), c_ijkl.tensor(2,2,1,2),
                 c_ijkl.tensor(2,2,2,0), c_ijkl.tensor(2,2,2,1), c_ijkl.tensor(2,2,2,2)}   // ij 3,3
        };

        // create data arrays
        QBarDataArray *dataSet = new QBarDataArray;
        QBarDataRow *dataRow;

        dataSet->reserve(9);
        for (int ij = 0; ij < 9; ij++) {
            // Create a data row
            dataRow = new QBarDataRow(9);
            for (int kl = 0; kl < 9; kl++) {
                // Add data to the row
                (*dataRow)[kl].setValue(c_ijkl_data[ij][kl]);
            }
            // Add the row to the set
            dataSet->append(dataRow);
        }

        // Add data to the data proxy (the data proxy assumes ownership of it)
        primary_series->dataProxy()->resetArray(dataSet, ij_list, ij_list);
        break;
    }
    case 30: { // Periclase
        density_line_edit->setText(QString::number(mpc::data::PericlaseDensity<double>()));
        bulk_modulus_line_edit->setText(QString::number(mpc::data::PericlaseBulkModulus<double>()));
        shear_modulus_line_edit->setText(QString::number(mpc::data::PericlaseShearModulus<double>()));
        c11_line_edit->setText(QString::number(mpc::data::PericlaseC11<double>()));
        c12_line_edit->setText(QString::number(mpc::data::PericlaseC12<double>()));
        c13_line_edit->setText(QString::number(mpc::data::PericlaseC13<double>()));
        c14_line_edit->setText(QString::number(mpc::data::PericlaseC14<double>()));
        c15_line_edit->setText(QString::number(mpc::data::PericlaseC15<double>()));
        c16_line_edit->setText(QString::number(mpc::data::PericlaseC16<double>()));
        c22_line_edit->setText(QString::number(mpc::data::PericlaseC22<double>()));
        c23_line_edit->setText(QString::number(mpc::data::PericlaseC23<double>()));
        c24_line_edit->setText(QString::number(mpc::data::PericlaseC24<double>()));
        c25_line_edit->setText(QString::number(mpc::data::PericlaseC25<double>()));
        c26_line_edit->setText(QString::number(mpc::data::PericlaseC26<double>()));
        c33_line_edit->setText(QString::number(mpc::data::PericlaseC33<double>()));
        c34_line_edit->setText(QString::number(mpc::data::PericlaseC34<double>()));
        c35_line_edit->setText(QString::number(mpc::data::PericlaseC35<double>()));
        c36_line_edit->setText(QString::number(mpc::data::PericlaseC36<double>()));
        c44_line_edit->setText(QString::number(mpc::data::PericlaseC44<double>()));
        c45_line_edit->setText(QString::number(mpc::data::PericlaseC45<double>()));
        c46_line_edit->setText(QString::number(mpc::data::PericlaseC46<double>()));
        c55_line_edit->setText(QString::number(mpc::data::PericlaseC55<double>()));
        c56_line_edit->setText(QString::number(mpc::data::PericlaseC56<double>()));
        c66_line_edit->setText(QString::number(mpc::data::PericlaseC66<double>()));
        // data
        mpc::core::StiffnessTensor<float> c_ijkl = mpc::data::PericlaseStiffnessTensor<float>();
        float c_ijkl_data[9][9] = {
                {c_ijkl.tensor(0,0,0,0), c_ijkl.tensor(0,0,0,1), c_ijkl.tensor(0,0,0,2),
                 c_ijkl.tensor(0,0,1,0), c_ijkl.tensor(0,0,1,1), c_ijkl.tensor(0,0,1,2),
                 c_ijkl.tensor(0,0,2,0), c_ijkl.tensor(0,0,2,1), c_ijkl.tensor(0,0,2,2)},  // ij 1,1
                {c_ijkl.tensor(0,1,0,0), c_ijkl.tensor(0,1,0,1), c_ijkl.tensor(0,1,0,2),
                 c_ijkl.tensor(0,1,1,0), c_ijkl.tensor(0,1,1,1), c_ijkl.tensor(0,1,1,2),
                 c_ijkl.tensor(0,1,2,0), c_ijkl.tensor(0,1,2,1), c_ijkl.tensor(0,1,2,2)},  // ij 1,2
                {c_ijkl.tensor(0,2,0,0), c_ijkl.tensor(0,2,0,1), c_ijkl.tensor(0,2,0,2),
                 c_ijkl.tensor(0,2,1,0), c_ijkl.tensor(0,2,1,1), c_ijkl.tensor(0,2,1,2),
                 c_ijkl.tensor(0,2,2,0), c_ijkl.tensor(0,2,2,1), c_ijkl.tensor(0,2,2,2)},  // ij 1,3
                {c_ijkl.tensor(1,0,0,0), c_ijkl.tensor(1,0,0,1), c_ijkl.tensor(1,0,0,2),
                 c_ijkl.tensor(1,0,1,0), c_ijkl.tensor(1,0,1,1), c_ijkl.tensor(1,0,1,2),
                 c_ijkl.tensor(1,0,2,0), c_ijkl.tensor(1,0,2,1), c_ijkl.tensor(1,0,2,2)},  // ij 2,1
                {c_ijkl.tensor(1,1,0,0), c_ijkl.tensor(1,1,0,1), c_ijkl.tensor(1,1,0,2),
                 c_ijkl.tensor(1,1,1,0), c_ijkl.tensor(1,1,1,1), c_ijkl.tensor(1,1,1,2),
                 c_ijkl.tensor(1,1,2,0), c_ijkl.tensor(1,1,2,1), c_ijkl.tensor(1,1,2,2)},  // ij 2,2
                {c_ijkl.tensor(1,2,0,0), c_ijkl.tensor(1,2,0,1), c_ijkl.tensor(1,2,0,2),
                 c_ijkl.tensor(1,2,1,0), c_ijkl.tensor(1,2,1,1), c_ijkl.tensor(1,2,1,2),
                 c_ijkl.tensor(1,2,2,0), c_ijkl.tensor(1,2,2,1), c_ijkl.tensor(1,2,2,2)},  // ij 2,3
                {c_ijkl.tensor(2,0,0,0), c_ijkl.tensor(2,0,0,1), c_ijkl.tensor(2,0,0,2),
                 c_ijkl.tensor(2,0,1,0), c_ijkl.tensor(2,0,1,1), c_ijkl.tensor(2,0,1,2),
                 c_ijkl.tensor(2,0,2,0), c_ijkl.tensor(2,0,2,1), c_ijkl.tensor(2,0,2,2)},  // ij 3,1
                {c_ijkl.tensor(2,1,0,0), c_ijkl.tensor(2,1,0,1), c_ijkl.tensor(2,1,0,2),
                 c_ijkl.tensor(2,1,1,0), c_ijkl.tensor(2,1,1,1), c_ijkl.tensor(2,1,1,2),
                 c_ijkl.tensor(2,1,2,0), c_ijkl.tensor(2,1,2,1), c_ijkl.tensor(2,1,2,2)},  // ij 3,2
                {c_ijkl.tensor(2,2,0,0), c_ijkl.tensor(2,2,0,1), c_ijkl.tensor(2,2,0,2),
                 c_ijkl.tensor(2,2,1,0), c_ijkl.tensor(2,2,1,1), c_ijkl.tensor(2,2,1,2),
                 c_ijkl.tensor(2,2,2,0), c_ijkl.tensor(2,2,2,1), c_ijkl.tensor(2,2,2,2)}   // ij 3,3
        };

        // create data arrays
        QBarDataArray *dataSet = new QBarDataArray;
        QBarDataRow *dataRow;

        dataSet->reserve(9);
        for (int ij = 0; ij < 9; ij++) {
            // Create a data row
            dataRow = new QBarDataRow(9);
            for (int kl = 0; kl < 9; kl++) {
                // Add data to the row
                (*dataRow)[kl].setValue(c_ijkl_data[ij][kl]);
            }
            // Add the row to the set
            dataSet->append(dataRow);
        }

        // Add data to the data proxy (the data proxy assumes ownership of it)
        primary_series->dataProxy()->resetArray(dataSet, ij_list, ij_list);
        break;
    }
    case 31: { // Magnetite
        density_line_edit->setText(QString::number(mpc::data::MagnetiteDensity<double>()));
        bulk_modulus_line_edit->setText(QString::number(mpc::data::MagnetiteBulkModulus<double>()));
        shear_modulus_line_edit->setText(QString::number(mpc::data::MagnetiteShearModulus<double>()));
        c11_line_edit->setText(QString::number(mpc::data::MagnetiteC11<double>()));
        c12_line_edit->setText(QString::number(mpc::data::MagnetiteC12<double>()));
        c13_line_edit->setText(QString::number(mpc::data::MagnetiteC13<double>()));
        c14_line_edit->setText(QString::number(mpc::data::MagnetiteC14<double>()));
        c15_line_edit->setText(QString::number(mpc::data::MagnetiteC15<double>()));
        c16_line_edit->setText(QString::number(mpc::data::MagnetiteC16<double>()));
        c22_line_edit->setText(QString::number(mpc::data::MagnetiteC22<double>()));
        c23_line_edit->setText(QString::number(mpc::data::MagnetiteC23<double>()));
        c24_line_edit->setText(QString::number(mpc::data::MagnetiteC24<double>()));
        c25_line_edit->setText(QString::number(mpc::data::MagnetiteC25<double>()));
        c26_line_edit->setText(QString::number(mpc::data::MagnetiteC26<double>()));
        c33_line_edit->setText(QString::number(mpc::data::MagnetiteC33<double>()));
        c34_line_edit->setText(QString::number(mpc::data::MagnetiteC34<double>()));
        c35_line_edit->setText(QString::number(mpc::data::MagnetiteC35<double>()));
        c36_line_edit->setText(QString::number(mpc::data::MagnetiteC36<double>()));
        c44_line_edit->setText(QString::number(mpc::data::MagnetiteC44<double>()));
        c45_line_edit->setText(QString::number(mpc::data::MagnetiteC45<double>()));
        c46_line_edit->setText(QString::number(mpc::data::MagnetiteC46<double>()));
        c55_line_edit->setText(QString::number(mpc::data::MagnetiteC55<double>()));
        c56_line_edit->setText(QString::number(mpc::data::MagnetiteC56<double>()));
        c66_line_edit->setText(QString::number(mpc::data::MagnetiteC66<double>()));
        // data
        mpc::core::StiffnessTensor<float> c_ijkl = mpc::data::MagnetiteStiffnessTensor<float>();
        float c_ijkl_data[9][9] = {
                {c_ijkl.tensor(0,0,0,0), c_ijkl.tensor(0,0,0,1), c_ijkl.tensor(0,0,0,2),
                 c_ijkl.tensor(0,0,1,0), c_ijkl.tensor(0,0,1,1), c_ijkl.tensor(0,0,1,2),
                 c_ijkl.tensor(0,0,2,0), c_ijkl.tensor(0,0,2,1), c_ijkl.tensor(0,0,2,2)},  // ij 1,1
                {c_ijkl.tensor(0,1,0,0), c_ijkl.tensor(0,1,0,1), c_ijkl.tensor(0,1,0,2),
                 c_ijkl.tensor(0,1,1,0), c_ijkl.tensor(0,1,1,1), c_ijkl.tensor(0,1,1,2),
                 c_ijkl.tensor(0,1,2,0), c_ijkl.tensor(0,1,2,1), c_ijkl.tensor(0,1,2,2)},  // ij 1,2
                {c_ijkl.tensor(0,2,0,0), c_ijkl.tensor(0,2,0,1), c_ijkl.tensor(0,2,0,2),
                 c_ijkl.tensor(0,2,1,0), c_ijkl.tensor(0,2,1,1), c_ijkl.tensor(0,2,1,2),
                 c_ijkl.tensor(0,2,2,0), c_ijkl.tensor(0,2,2,1), c_ijkl.tensor(0,2,2,2)},  // ij 1,3
                {c_ijkl.tensor(1,0,0,0), c_ijkl.tensor(1,0,0,1), c_ijkl.tensor(1,0,0,2),
                 c_ijkl.tensor(1,0,1,0), c_ijkl.tensor(1,0,1,1), c_ijkl.tensor(1,0,1,2),
                 c_ijkl.tensor(1,0,2,0), c_ijkl.tensor(1,0,2,1), c_ijkl.tensor(1,0,2,2)},  // ij 2,1
                {c_ijkl.tensor(1,1,0,0), c_ijkl.tensor(1,1,0,1), c_ijkl.tensor(1,1,0,2),
                 c_ijkl.tensor(1,1,1,0), c_ijkl.tensor(1,1,1,1), c_ijkl.tensor(1,1,1,2),
                 c_ijkl.tensor(1,1,2,0), c_ijkl.tensor(1,1,2,1), c_ijkl.tensor(1,1,2,2)},  // ij 2,2
                {c_ijkl.tensor(1,2,0,0), c_ijkl.tensor(1,2,0,1), c_ijkl.tensor(1,2,0,2),
                 c_ijkl.tensor(1,2,1,0), c_ijkl.tensor(1,2,1,1), c_ijkl.tensor(1,2,1,2),
                 c_ijkl.tensor(1,2,2,0), c_ijkl.tensor(1,2,2,1), c_ijkl.tensor(1,2,2,2)},  // ij 2,3
                {c_ijkl.tensor(2,0,0,0), c_ijkl.tensor(2,0,0,1), c_ijkl.tensor(2,0,0,2),
                 c_ijkl.tensor(2,0,1,0), c_ijkl.tensor(2,0,1,1), c_ijkl.tensor(2,0,1,2),
                 c_ijkl.tensor(2,0,2,0), c_ijkl.tensor(2,0,2,1), c_ijkl.tensor(2,0,2,2)},  // ij 3,1
                {c_ijkl.tensor(2,1,0,0), c_ijkl.tensor(2,1,0,1), c_ijkl.tensor(2,1,0,2),
                 c_ijkl.tensor(2,1,1,0), c_ijkl.tensor(2,1,1,1), c_ijkl.tensor(2,1,1,2),
                 c_ijkl.tensor(2,1,2,0), c_ijkl.tensor(2,1,2,1), c_ijkl.tensor(2,1,2,2)},  // ij 3,2
                {c_ijkl.tensor(2,2,0,0), c_ijkl.tensor(2,2,0,1), c_ijkl.tensor(2,2,0,2),
                 c_ijkl.tensor(2,2,1,0), c_ijkl.tensor(2,2,1,1), c_ijkl.tensor(2,2,1,2),
                 c_ijkl.tensor(2,2,2,0), c_ijkl.tensor(2,2,2,1), c_ijkl.tensor(2,2,2,2)}   // ij 3,3
        };

        // create data arrays
        QBarDataArray *dataSet = new QBarDataArray;
        QBarDataRow *dataRow;

        dataSet->reserve(9);
        for (int ij = 0; ij < 9; ij++) {
            // Create a data row
            dataRow = new QBarDataRow(9);
            for (int kl = 0; kl < 9; kl++) {
                // Add data to the row
                (*dataRow)[kl].setValue(c_ijkl_data[ij][kl]);
            }
            // Add the row to the set
            dataSet->append(dataRow);
        }

        // Add data to the data proxy (the data proxy assumes ownership of it)
        primary_series->dataProxy()->resetArray(dataSet, ij_list, ij_list);
        break;
    }
    case 32: { // Chromite
        density_line_edit->setText(QString::number(mpc::data::ChromiteDensity<double>()));
        bulk_modulus_line_edit->setText(QString::number(mpc::data::ChromiteBulkModulus<double>()));
        shear_modulus_line_edit->setText(QString::number(mpc::data::ChromiteShearModulus<double>()));
        c11_line_edit->setText(QString::number(mpc::data::ChromiteC11<double>()));
        c12_line_edit->setText(QString::number(mpc::data::ChromiteC12<double>()));
        c13_line_edit->setText(QString::number(mpc::data::ChromiteC13<double>()));
        c14_line_edit->setText(QString::number(mpc::data::ChromiteC14<double>()));
        c15_line_edit->setText(QString::number(mpc::data::ChromiteC15<double>()));
        c16_line_edit->setText(QString::number(mpc::data::ChromiteC16<double>()));
        c22_line_edit->setText(QString::number(mpc::data::ChromiteC22<double>()));
        c23_line_edit->setText(QString::number(mpc::data::ChromiteC23<double>()));
        c24_line_edit->setText(QString::number(mpc::data::ChromiteC24<double>()));
        c25_line_edit->setText(QString::number(mpc::data::ChromiteC25<double>()));
        c26_line_edit->setText(QString::number(mpc::data::ChromiteC26<double>()));
        c33_line_edit->setText(QString::number(mpc::data::ChromiteC33<double>()));
        c34_line_edit->setText(QString::number(mpc::data::ChromiteC34<double>()));
        c35_line_edit->setText(QString::number(mpc::data::ChromiteC35<double>()));
        c36_line_edit->setText(QString::number(mpc::data::ChromiteC36<double>()));
        c44_line_edit->setText(QString::number(mpc::data::ChromiteC44<double>()));
        c45_line_edit->setText(QString::number(mpc::data::ChromiteC45<double>()));
        c46_line_edit->setText(QString::number(mpc::data::ChromiteC46<double>()));
        c55_line_edit->setText(QString::number(mpc::data::ChromiteC55<double>()));
        c56_line_edit->setText(QString::number(mpc::data::ChromiteC56<double>()));
        c66_line_edit->setText(QString::number(mpc::data::ChromiteC66<double>()));
        // data
        mpc::core::StiffnessTensor<float> c_ijkl = mpc::data::ChromiteStiffnessTensor<float>();
        float c_ijkl_data[9][9] = {
                {c_ijkl.tensor(0,0,0,0), c_ijkl.tensor(0,0,0,1), c_ijkl.tensor(0,0,0,2),
                 c_ijkl.tensor(0,0,1,0), c_ijkl.tensor(0,0,1,1), c_ijkl.tensor(0,0,1,2),
                 c_ijkl.tensor(0,0,2,0), c_ijkl.tensor(0,0,2,1), c_ijkl.tensor(0,0,2,2)},  // ij 1,1
                {c_ijkl.tensor(0,1,0,0), c_ijkl.tensor(0,1,0,1), c_ijkl.tensor(0,1,0,2),
                 c_ijkl.tensor(0,1,1,0), c_ijkl.tensor(0,1,1,1), c_ijkl.tensor(0,1,1,2),
                 c_ijkl.tensor(0,1,2,0), c_ijkl.tensor(0,1,2,1), c_ijkl.tensor(0,1,2,2)},  // ij 1,2
                {c_ijkl.tensor(0,2,0,0), c_ijkl.tensor(0,2,0,1), c_ijkl.tensor(0,2,0,2),
                 c_ijkl.tensor(0,2,1,0), c_ijkl.tensor(0,2,1,1), c_ijkl.tensor(0,2,1,2),
                 c_ijkl.tensor(0,2,2,0), c_ijkl.tensor(0,2,2,1), c_ijkl.tensor(0,2,2,2)},  // ij 1,3
                {c_ijkl.tensor(1,0,0,0), c_ijkl.tensor(1,0,0,1), c_ijkl.tensor(1,0,0,2),
                 c_ijkl.tensor(1,0,1,0), c_ijkl.tensor(1,0,1,1), c_ijkl.tensor(1,0,1,2),
                 c_ijkl.tensor(1,0,2,0), c_ijkl.tensor(1,0,2,1), c_ijkl.tensor(1,0,2,2)},  // ij 2,1
                {c_ijkl.tensor(1,1,0,0), c_ijkl.tensor(1,1,0,1), c_ijkl.tensor(1,1,0,2),
                 c_ijkl.tensor(1,1,1,0), c_ijkl.tensor(1,1,1,1), c_ijkl.tensor(1,1,1,2),
                 c_ijkl.tensor(1,1,2,0), c_ijkl.tensor(1,1,2,1), c_ijkl.tensor(1,1,2,2)},  // ij 2,2
                {c_ijkl.tensor(1,2,0,0), c_ijkl.tensor(1,2,0,1), c_ijkl.tensor(1,2,0,2),
                 c_ijkl.tensor(1,2,1,0), c_ijkl.tensor(1,2,1,1), c_ijkl.tensor(1,2,1,2),
                 c_ijkl.tensor(1,2,2,0), c_ijkl.tensor(1,2,2,1), c_ijkl.tensor(1,2,2,2)},  // ij 2,3
                {c_ijkl.tensor(2,0,0,0), c_ijkl.tensor(2,0,0,1), c_ijkl.tensor(2,0,0,2),
                 c_ijkl.tensor(2,0,1,0), c_ijkl.tensor(2,0,1,1), c_ijkl.tensor(2,0,1,2),
                 c_ijkl.tensor(2,0,2,0), c_ijkl.tensor(2,0,2,1), c_ijkl.tensor(2,0,2,2)},  // ij 3,1
                {c_ijkl.tensor(2,1,0,0), c_ijkl.tensor(2,1,0,1), c_ijkl.tensor(2,1,0,2),
                 c_ijkl.tensor(2,1,1,0), c_ijkl.tensor(2,1,1,1), c_ijkl.tensor(2,1,1,2),
                 c_ijkl.tensor(2,1,2,0), c_ijkl.tensor(2,1,2,1), c_ijkl.tensor(2,1,2,2)},  // ij 3,2
                {c_ijkl.tensor(2,2,0,0), c_ijkl.tensor(2,2,0,1), c_ijkl.tensor(2,2,0,2),
                 c_ijkl.tensor(2,2,1,0), c_ijkl.tensor(2,2,1,1), c_ijkl.tensor(2,2,1,2),
                 c_ijkl.tensor(2,2,2,0), c_ijkl.tensor(2,2,2,1), c_ijkl.tensor(2,2,2,2)}   // ij 3,3
        };

        // create data arrays
        QBarDataArray *dataSet = new QBarDataArray;
        QBarDataRow *dataRow;

        dataSet->reserve(9);
        for (int ij = 0; ij < 9; ij++) {
            // Create a data row
            dataRow = new QBarDataRow(9);
            for (int kl = 0; kl < 9; kl++) {
                // Add data to the row
                (*dataRow)[kl].setValue(c_ijkl_data[ij][kl]);
            }
            // Add the row to the set
            dataSet->append(dataRow);
        }

        // Add data to the data proxy (the data proxy assumes ownership of it)
        primary_series->dataProxy()->resetArray(dataSet, ij_list, ij_list);
        break;
    }
    case 33: { // Spinel
        density_line_edit->setText(QString::number(mpc::data::SpinelDensity<double>()));
        bulk_modulus_line_edit->setText(QString::number(mpc::data::SpinelBulkModulus<double>()));
        shear_modulus_line_edit->setText(QString::number(mpc::data::SpinelShearModulus<double>()));
        c11_line_edit->setText(QString::number(mpc::data::SpinelC11<double>()));
        c12_line_edit->setText(QString::number(mpc::data::SpinelC12<double>()));
        c13_line_edit->setText(QString::number(mpc::data::SpinelC13<double>()));
        c14_line_edit->setText(QString::number(mpc::data::SpinelC14<double>()));
        c15_line_edit->setText(QString::number(mpc::data::SpinelC15<double>()));
        c16_line_edit->setText(QString::number(mpc::data::SpinelC16<double>()));
        c22_line_edit->setText(QString::number(mpc::data::SpinelC22<double>()));
        c23_line_edit->setText(QString::number(mpc::data::SpinelC23<double>()));
        c24_line_edit->setText(QString::number(mpc::data::SpinelC24<double>()));
        c25_line_edit->setText(QString::number(mpc::data::SpinelC25<double>()));
        c26_line_edit->setText(QString::number(mpc::data::SpinelC26<double>()));
        c33_line_edit->setText(QString::number(mpc::data::SpinelC33<double>()));
        c34_line_edit->setText(QString::number(mpc::data::SpinelC34<double>()));
        c35_line_edit->setText(QString::number(mpc::data::SpinelC35<double>()));
        c36_line_edit->setText(QString::number(mpc::data::SpinelC36<double>()));
        c44_line_edit->setText(QString::number(mpc::data::SpinelC44<double>()));
        c45_line_edit->setText(QString::number(mpc::data::SpinelC45<double>()));
        c46_line_edit->setText(QString::number(mpc::data::SpinelC46<double>()));
        c55_line_edit->setText(QString::number(mpc::data::SpinelC55<double>()));
        c56_line_edit->setText(QString::number(mpc::data::SpinelC56<double>()));
        c66_line_edit->setText(QString::number(mpc::data::SpinelC66<double>()));
        // data
        mpc::core::StiffnessTensor<float> c_ijkl = mpc::data::SpinelStiffnessTensor<float>();
        float c_ijkl_data[9][9] = {
                {c_ijkl.tensor(0,0,0,0), c_ijkl.tensor(0,0,0,1), c_ijkl.tensor(0,0,0,2),
                 c_ijkl.tensor(0,0,1,0), c_ijkl.tensor(0,0,1,1), c_ijkl.tensor(0,0,1,2),
                 c_ijkl.tensor(0,0,2,0), c_ijkl.tensor(0,0,2,1), c_ijkl.tensor(0,0,2,2)},  // ij 1,1
                {c_ijkl.tensor(0,1,0,0), c_ijkl.tensor(0,1,0,1), c_ijkl.tensor(0,1,0,2),
                 c_ijkl.tensor(0,1,1,0), c_ijkl.tensor(0,1,1,1), c_ijkl.tensor(0,1,1,2),
                 c_ijkl.tensor(0,1,2,0), c_ijkl.tensor(0,1,2,1), c_ijkl.tensor(0,1,2,2)},  // ij 1,2
                {c_ijkl.tensor(0,2,0,0), c_ijkl.tensor(0,2,0,1), c_ijkl.tensor(0,2,0,2),
                 c_ijkl.tensor(0,2,1,0), c_ijkl.tensor(0,2,1,1), c_ijkl.tensor(0,2,1,2),
                 c_ijkl.tensor(0,2,2,0), c_ijkl.tensor(0,2,2,1), c_ijkl.tensor(0,2,2,2)},  // ij 1,3
                {c_ijkl.tensor(1,0,0,0), c_ijkl.tensor(1,0,0,1), c_ijkl.tensor(1,0,0,2),
                 c_ijkl.tensor(1,0,1,0), c_ijkl.tensor(1,0,1,1), c_ijkl.tensor(1,0,1,2),
                 c_ijkl.tensor(1,0,2,0), c_ijkl.tensor(1,0,2,1), c_ijkl.tensor(1,0,2,2)},  // ij 2,1
                {c_ijkl.tensor(1,1,0,0), c_ijkl.tensor(1,1,0,1), c_ijkl.tensor(1,1,0,2),
                 c_ijkl.tensor(1,1,1,0), c_ijkl.tensor(1,1,1,1), c_ijkl.tensor(1,1,1,2),
                 c_ijkl.tensor(1,1,2,0), c_ijkl.tensor(1,1,2,1), c_ijkl.tensor(1,1,2,2)},  // ij 2,2
                {c_ijkl.tensor(1,2,0,0), c_ijkl.tensor(1,2,0,1), c_ijkl.tensor(1,2,0,2),
                 c_ijkl.tensor(1,2,1,0), c_ijkl.tensor(1,2,1,1), c_ijkl.tensor(1,2,1,2),
                 c_ijkl.tensor(1,2,2,0), c_ijkl.tensor(1,2,2,1), c_ijkl.tensor(1,2,2,2)},  // ij 2,3
                {c_ijkl.tensor(2,0,0,0), c_ijkl.tensor(2,0,0,1), c_ijkl.tensor(2,0,0,2),
                 c_ijkl.tensor(2,0,1,0), c_ijkl.tensor(2,0,1,1), c_ijkl.tensor(2,0,1,2),
                 c_ijkl.tensor(2,0,2,0), c_ijkl.tensor(2,0,2,1), c_ijkl.tensor(2,0,2,2)},  // ij 3,1
                {c_ijkl.tensor(2,1,0,0), c_ijkl.tensor(2,1,0,1), c_ijkl.tensor(2,1,0,2),
                 c_ijkl.tensor(2,1,1,0), c_ijkl.tensor(2,1,1,1), c_ijkl.tensor(2,1,1,2),
                 c_ijkl.tensor(2,1,2,0), c_ijkl.tensor(2,1,2,1), c_ijkl.tensor(2,1,2,2)},  // ij 3,2
                {c_ijkl.tensor(2,2,0,0), c_ijkl.tensor(2,2,0,1), c_ijkl.tensor(2,2,0,2),
                 c_ijkl.tensor(2,2,1,0), c_ijkl.tensor(2,2,1,1), c_ijkl.tensor(2,2,1,2),
                 c_ijkl.tensor(2,2,2,0), c_ijkl.tensor(2,2,2,1), c_ijkl.tensor(2,2,2,2)}   // ij 3,3
        };

        // create data arrays
        QBarDataArray *dataSet = new QBarDataArray;
        QBarDataRow *dataRow;

        dataSet->reserve(9);
        for (int ij = 0; ij < 9; ij++) {
            // Create a data row
            dataRow = new QBarDataRow(9);
            for (int kl = 0; kl < 9; kl++) {
                // Add data to the row
                (*dataRow)[kl].setValue(c_ijkl_data[ij][kl]);
            }
            // Add the row to the set
            dataSet->append(dataRow);
        }

        // Add data to the data proxy (the data proxy assumes ownership of it)
        primary_series->dataProxy()->resetArray(dataSet, ij_list, ij_list);
        break;
    }
    case 34: { // Pyrite
        density_line_edit->setText(QString::number(mpc::data::PyriteDensity<double>()));
        bulk_modulus_line_edit->setText(QString::number(mpc::data::PyriteBulkModulus<double>()));
        shear_modulus_line_edit->setText(QString::number(mpc::data::PyriteShearModulus<double>()));
        c11_line_edit->setText(QString::number(mpc::data::PyriteC11<double>()));
        c12_line_edit->setText(QString::number(mpc::data::PyriteC12<double>()));
        c13_line_edit->setText(QString::number(mpc::data::PyriteC13<double>()));
        c14_line_edit->setText(QString::number(mpc::data::PyriteC14<double>()));
        c15_line_edit->setText(QString::number(mpc::data::PyriteC15<double>()));
        c16_line_edit->setText(QString::number(mpc::data::PyriteC16<double>()));
        c22_line_edit->setText(QString::number(mpc::data::PyriteC22<double>()));
        c23_line_edit->setText(QString::number(mpc::data::PyriteC23<double>()));
        c24_line_edit->setText(QString::number(mpc::data::PyriteC24<double>()));
        c25_line_edit->setText(QString::number(mpc::data::PyriteC25<double>()));
        c26_line_edit->setText(QString::number(mpc::data::PyriteC26<double>()));
        c33_line_edit->setText(QString::number(mpc::data::PyriteC33<double>()));
        c34_line_edit->setText(QString::number(mpc::data::PyriteC34<double>()));
        c35_line_edit->setText(QString::number(mpc::data::PyriteC35<double>()));
        c36_line_edit->setText(QString::number(mpc::data::PyriteC36<double>()));
        c44_line_edit->setText(QString::number(mpc::data::PyriteC44<double>()));
        c45_line_edit->setText(QString::number(mpc::data::PyriteC45<double>()));
        c46_line_edit->setText(QString::number(mpc::data::PyriteC46<double>()));
        c55_line_edit->setText(QString::number(mpc::data::PyriteC55<double>()));
        c56_line_edit->setText(QString::number(mpc::data::PyriteC56<double>()));
        c66_line_edit->setText(QString::number(mpc::data::PyriteC66<double>()));
        // data
        mpc::core::StiffnessTensor<float> c_ijkl = mpc::data::PyriteStiffnessTensor<float>();
        float c_ijkl_data[9][9] = {
                {c_ijkl.tensor(0,0,0,0), c_ijkl.tensor(0,0,0,1), c_ijkl.tensor(0,0,0,2),
                 c_ijkl.tensor(0,0,1,0), c_ijkl.tensor(0,0,1,1), c_ijkl.tensor(0,0,1,2),
                 c_ijkl.tensor(0,0,2,0), c_ijkl.tensor(0,0,2,1), c_ijkl.tensor(0,0,2,2)},  // ij 1,1
                {c_ijkl.tensor(0,1,0,0), c_ijkl.tensor(0,1,0,1), c_ijkl.tensor(0,1,0,2),
                 c_ijkl.tensor(0,1,1,0), c_ijkl.tensor(0,1,1,1), c_ijkl.tensor(0,1,1,2),
                 c_ijkl.tensor(0,1,2,0), c_ijkl.tensor(0,1,2,1), c_ijkl.tensor(0,1,2,2)},  // ij 1,2
                {c_ijkl.tensor(0,2,0,0), c_ijkl.tensor(0,2,0,1), c_ijkl.tensor(0,2,0,2),
                 c_ijkl.tensor(0,2,1,0), c_ijkl.tensor(0,2,1,1), c_ijkl.tensor(0,2,1,2),
                 c_ijkl.tensor(0,2,2,0), c_ijkl.tensor(0,2,2,1), c_ijkl.tensor(0,2,2,2)},  // ij 1,3
                {c_ijkl.tensor(1,0,0,0), c_ijkl.tensor(1,0,0,1), c_ijkl.tensor(1,0,0,2),
                 c_ijkl.tensor(1,0,1,0), c_ijkl.tensor(1,0,1,1), c_ijkl.tensor(1,0,1,2),
                 c_ijkl.tensor(1,0,2,0), c_ijkl.tensor(1,0,2,1), c_ijkl.tensor(1,0,2,2)},  // ij 2,1
                {c_ijkl.tensor(1,1,0,0), c_ijkl.tensor(1,1,0,1), c_ijkl.tensor(1,1,0,2),
                 c_ijkl.tensor(1,1,1,0), c_ijkl.tensor(1,1,1,1), c_ijkl.tensor(1,1,1,2),
                 c_ijkl.tensor(1,1,2,0), c_ijkl.tensor(1,1,2,1), c_ijkl.tensor(1,1,2,2)},  // ij 2,2
                {c_ijkl.tensor(1,2,0,0), c_ijkl.tensor(1,2,0,1), c_ijkl.tensor(1,2,0,2),
                 c_ijkl.tensor(1,2,1,0), c_ijkl.tensor(1,2,1,1), c_ijkl.tensor(1,2,1,2),
                 c_ijkl.tensor(1,2,2,0), c_ijkl.tensor(1,2,2,1), c_ijkl.tensor(1,2,2,2)},  // ij 2,3
                {c_ijkl.tensor(2,0,0,0), c_ijkl.tensor(2,0,0,1), c_ijkl.tensor(2,0,0,2),
                 c_ijkl.tensor(2,0,1,0), c_ijkl.tensor(2,0,1,1), c_ijkl.tensor(2,0,1,2),
                 c_ijkl.tensor(2,0,2,0), c_ijkl.tensor(2,0,2,1), c_ijkl.tensor(2,0,2,2)},  // ij 3,1
                {c_ijkl.tensor(2,1,0,0), c_ijkl.tensor(2,1,0,1), c_ijkl.tensor(2,1,0,2),
                 c_ijkl.tensor(2,1,1,0), c_ijkl.tensor(2,1,1,1), c_ijkl.tensor(2,1,1,2),
                 c_ijkl.tensor(2,1,2,0), c_ijkl.tensor(2,1,2,1), c_ijkl.tensor(2,1,2,2)},  // ij 3,2
                {c_ijkl.tensor(2,2,0,0), c_ijkl.tensor(2,2,0,1), c_ijkl.tensor(2,2,0,2),
                 c_ijkl.tensor(2,2,1,0), c_ijkl.tensor(2,2,1,1), c_ijkl.tensor(2,2,1,2),
                 c_ijkl.tensor(2,2,2,0), c_ijkl.tensor(2,2,2,1), c_ijkl.tensor(2,2,2,2)}   // ij 3,3
        };

        // create data arrays
        QBarDataArray *dataSet = new QBarDataArray;
        QBarDataRow *dataRow;

        dataSet->reserve(9);
        for (int ij = 0; ij < 9; ij++) {
            // Create a data row
            dataRow = new QBarDataRow(9);
            for (int kl = 0; kl < 9; kl++) {
                // Add data to the row
                (*dataRow)[kl].setValue(c_ijkl_data[ij][kl]);
            }
            // Add the row to the set
            dataSet->append(dataRow);
        }

        // Add data to the data proxy (the data proxy assumes ownership of it)
        primary_series->dataProxy()->resetArray(dataSet, ij_list, ij_list);
        break;
    }
    case 35: { // Galena
        density_line_edit->setText(QString::number(mpc::data::GalenaDensity<double>()));
        bulk_modulus_line_edit->setText(QString::number(mpc::data::GalenaBulkModulus<double>()));
        shear_modulus_line_edit->setText(QString::number(mpc::data::GalenaShearModulus<double>()));
        c11_line_edit->setText(QString::number(mpc::data::GalenaC11<double>()));
        c12_line_edit->setText(QString::number(mpc::data::GalenaC12<double>()));
        c13_line_edit->setText(QString::number(mpc::data::GalenaC13<double>()));
        c14_line_edit->setText(QString::number(mpc::data::GalenaC14<double>()));
        c15_line_edit->setText(QString::number(mpc::data::GalenaC15<double>()));
        c16_line_edit->setText(QString::number(mpc::data::GalenaC16<double>()));
        c22_line_edit->setText(QString::number(mpc::data::GalenaC22<double>()));
        c23_line_edit->setText(QString::number(mpc::data::GalenaC23<double>()));
        c24_line_edit->setText(QString::number(mpc::data::GalenaC24<double>()));
        c25_line_edit->setText(QString::number(mpc::data::GalenaC25<double>()));
        c26_line_edit->setText(QString::number(mpc::data::GalenaC26<double>()));
        c33_line_edit->setText(QString::number(mpc::data::GalenaC33<double>()));
        c34_line_edit->setText(QString::number(mpc::data::GalenaC34<double>()));
        c35_line_edit->setText(QString::number(mpc::data::GalenaC35<double>()));
        c36_line_edit->setText(QString::number(mpc::data::GalenaC36<double>()));
        c44_line_edit->setText(QString::number(mpc::data::GalenaC44<double>()));
        c45_line_edit->setText(QString::number(mpc::data::GalenaC45<double>()));
        c46_line_edit->setText(QString::number(mpc::data::GalenaC46<double>()));
        c55_line_edit->setText(QString::number(mpc::data::GalenaC55<double>()));
        c56_line_edit->setText(QString::number(mpc::data::GalenaC56<double>()));
        c66_line_edit->setText(QString::number(mpc::data::GalenaC66<double>()));
        // data
        mpc::core::StiffnessTensor<float> c_ijkl = mpc::data::GalenaStiffnessTensor<float>();
        float c_ijkl_data[9][9] = {
                {c_ijkl.tensor(0,0,0,0), c_ijkl.tensor(0,0,0,1), c_ijkl.tensor(0,0,0,2),
                 c_ijkl.tensor(0,0,1,0), c_ijkl.tensor(0,0,1,1), c_ijkl.tensor(0,0,1,2),
                 c_ijkl.tensor(0,0,2,0), c_ijkl.tensor(0,0,2,1), c_ijkl.tensor(0,0,2,2)},  // ij 1,1
                {c_ijkl.tensor(0,1,0,0), c_ijkl.tensor(0,1,0,1), c_ijkl.tensor(0,1,0,2),
                 c_ijkl.tensor(0,1,1,0), c_ijkl.tensor(0,1,1,1), c_ijkl.tensor(0,1,1,2),
                 c_ijkl.tensor(0,1,2,0), c_ijkl.tensor(0,1,2,1), c_ijkl.tensor(0,1,2,2)},  // ij 1,2
                {c_ijkl.tensor(0,2,0,0), c_ijkl.tensor(0,2,0,1), c_ijkl.tensor(0,2,0,2),
                 c_ijkl.tensor(0,2,1,0), c_ijkl.tensor(0,2,1,1), c_ijkl.tensor(0,2,1,2),
                 c_ijkl.tensor(0,2,2,0), c_ijkl.tensor(0,2,2,1), c_ijkl.tensor(0,2,2,2)},  // ij 1,3
                {c_ijkl.tensor(1,0,0,0), c_ijkl.tensor(1,0,0,1), c_ijkl.tensor(1,0,0,2),
                 c_ijkl.tensor(1,0,1,0), c_ijkl.tensor(1,0,1,1), c_ijkl.tensor(1,0,1,2),
                 c_ijkl.tensor(1,0,2,0), c_ijkl.tensor(1,0,2,1), c_ijkl.tensor(1,0,2,2)},  // ij 2,1
                {c_ijkl.tensor(1,1,0,0), c_ijkl.tensor(1,1,0,1), c_ijkl.tensor(1,1,0,2),
                 c_ijkl.tensor(1,1,1,0), c_ijkl.tensor(1,1,1,1), c_ijkl.tensor(1,1,1,2),
                 c_ijkl.tensor(1,1,2,0), c_ijkl.tensor(1,1,2,1), c_ijkl.tensor(1,1,2,2)},  // ij 2,2
                {c_ijkl.tensor(1,2,0,0), c_ijkl.tensor(1,2,0,1), c_ijkl.tensor(1,2,0,2),
                 c_ijkl.tensor(1,2,1,0), c_ijkl.tensor(1,2,1,1), c_ijkl.tensor(1,2,1,2),
                 c_ijkl.tensor(1,2,2,0), c_ijkl.tensor(1,2,2,1), c_ijkl.tensor(1,2,2,2)},  // ij 2,3
                {c_ijkl.tensor(2,0,0,0), c_ijkl.tensor(2,0,0,1), c_ijkl.tensor(2,0,0,2),
                 c_ijkl.tensor(2,0,1,0), c_ijkl.tensor(2,0,1,1), c_ijkl.tensor(2,0,1,2),
                 c_ijkl.tensor(2,0,2,0), c_ijkl.tensor(2,0,2,1), c_ijkl.tensor(2,0,2,2)},  // ij 3,1
                {c_ijkl.tensor(2,1,0,0), c_ijkl.tensor(2,1,0,1), c_ijkl.tensor(2,1,0,2),
                 c_ijkl.tensor(2,1,1,0), c_ijkl.tensor(2,1,1,1), c_ijkl.tensor(2,1,1,2),
                 c_ijkl.tensor(2,1,2,0), c_ijkl.tensor(2,1,2,1), c_ijkl.tensor(2,1,2,2)},  // ij 3,2
                {c_ijkl.tensor(2,2,0,0), c_ijkl.tensor(2,2,0,1), c_ijkl.tensor(2,2,0,2),
                 c_ijkl.tensor(2,2,1,0), c_ijkl.tensor(2,2,1,1), c_ijkl.tensor(2,2,1,2),
                 c_ijkl.tensor(2,2,2,0), c_ijkl.tensor(2,2,2,1), c_ijkl.tensor(2,2,2,2)}   // ij 3,3
        };

        // create data arrays
        QBarDataArray *dataSet = new QBarDataArray;
        QBarDataRow *dataRow;

        dataSet->reserve(9);
        for (int ij = 0; ij < 9; ij++) {
            // Create a data row
            dataRow = new QBarDataRow(9);
            for (int kl = 0; kl < 9; kl++) {
                // Add data to the row
                (*dataRow)[kl].setValue(c_ijkl_data[ij][kl]);
            }
            // Add the row to the set
            dataSet->append(dataRow);
        }

        // Add data to the data proxy (the data proxy assumes ownership of it)
        primary_series->dataProxy()->resetArray(dataSet, ij_list, ij_list);
        break;
    }
    case 36: { // Sphalerite
        density_line_edit->setText(QString::number(mpc::data::SphaleriteDensity<double>()));
        bulk_modulus_line_edit->setText(QString::number(mpc::data::SphaleriteBulkModulus<double>()));
        shear_modulus_line_edit->setText(QString::number(mpc::data::SphaleriteShearModulus<double>()));
        c11_line_edit->setText(QString::number(mpc::data::SphaleriteC11<double>()));
        c12_line_edit->setText(QString::number(mpc::data::SphaleriteC12<double>()));
        c13_line_edit->setText(QString::number(mpc::data::SphaleriteC13<double>()));
        c14_line_edit->setText(QString::number(mpc::data::SphaleriteC14<double>()));
        c15_line_edit->setText(QString::number(mpc::data::SphaleriteC15<double>()));
        c16_line_edit->setText(QString::number(mpc::data::SphaleriteC16<double>()));
        c22_line_edit->setText(QString::number(mpc::data::SphaleriteC22<double>()));
        c23_line_edit->setText(QString::number(mpc::data::SphaleriteC23<double>()));
        c24_line_edit->setText(QString::number(mpc::data::SphaleriteC24<double>()));
        c25_line_edit->setText(QString::number(mpc::data::SphaleriteC25<double>()));
        c26_line_edit->setText(QString::number(mpc::data::SphaleriteC26<double>()));
        c33_line_edit->setText(QString::number(mpc::data::SphaleriteC33<double>()));
        c34_line_edit->setText(QString::number(mpc::data::SphaleriteC34<double>()));
        c35_line_edit->setText(QString::number(mpc::data::SphaleriteC35<double>()));
        c36_line_edit->setText(QString::number(mpc::data::SphaleriteC36<double>()));
        c44_line_edit->setText(QString::number(mpc::data::SphaleriteC44<double>()));
        c45_line_edit->setText(QString::number(mpc::data::SphaleriteC45<double>()));
        c46_line_edit->setText(QString::number(mpc::data::SphaleriteC46<double>()));
        c55_line_edit->setText(QString::number(mpc::data::SphaleriteC55<double>()));
        c56_line_edit->setText(QString::number(mpc::data::SphaleriteC56<double>()));
        c66_line_edit->setText(QString::number(mpc::data::SphaleriteC66<double>()));
        // data
        mpc::core::StiffnessTensor<float> c_ijkl = mpc::data::SphaleriteStiffnessTensor<float>();
        float c_ijkl_data[9][9] = {
                {c_ijkl.tensor(0,0,0,0), c_ijkl.tensor(0,0,0,1), c_ijkl.tensor(0,0,0,2),
                 c_ijkl.tensor(0,0,1,0), c_ijkl.tensor(0,0,1,1), c_ijkl.tensor(0,0,1,2),
                 c_ijkl.tensor(0,0,2,0), c_ijkl.tensor(0,0,2,1), c_ijkl.tensor(0,0,2,2)},  // ij 1,1
                {c_ijkl.tensor(0,1,0,0), c_ijkl.tensor(0,1,0,1), c_ijkl.tensor(0,1,0,2),
                 c_ijkl.tensor(0,1,1,0), c_ijkl.tensor(0,1,1,1), c_ijkl.tensor(0,1,1,2),
                 c_ijkl.tensor(0,1,2,0), c_ijkl.tensor(0,1,2,1), c_ijkl.tensor(0,1,2,2)},  // ij 1,2
                {c_ijkl.tensor(0,2,0,0), c_ijkl.tensor(0,2,0,1), c_ijkl.tensor(0,2,0,2),
                 c_ijkl.tensor(0,2,1,0), c_ijkl.tensor(0,2,1,1), c_ijkl.tensor(0,2,1,2),
                 c_ijkl.tensor(0,2,2,0), c_ijkl.tensor(0,2,2,1), c_ijkl.tensor(0,2,2,2)},  // ij 1,3
                {c_ijkl.tensor(1,0,0,0), c_ijkl.tensor(1,0,0,1), c_ijkl.tensor(1,0,0,2),
                 c_ijkl.tensor(1,0,1,0), c_ijkl.tensor(1,0,1,1), c_ijkl.tensor(1,0,1,2),
                 c_ijkl.tensor(1,0,2,0), c_ijkl.tensor(1,0,2,1), c_ijkl.tensor(1,0,2,2)},  // ij 2,1
                {c_ijkl.tensor(1,1,0,0), c_ijkl.tensor(1,1,0,1), c_ijkl.tensor(1,1,0,2),
                 c_ijkl.tensor(1,1,1,0), c_ijkl.tensor(1,1,1,1), c_ijkl.tensor(1,1,1,2),
                 c_ijkl.tensor(1,1,2,0), c_ijkl.tensor(1,1,2,1), c_ijkl.tensor(1,1,2,2)},  // ij 2,2
                {c_ijkl.tensor(1,2,0,0), c_ijkl.tensor(1,2,0,1), c_ijkl.tensor(1,2,0,2),
                 c_ijkl.tensor(1,2,1,0), c_ijkl.tensor(1,2,1,1), c_ijkl.tensor(1,2,1,2),
                 c_ijkl.tensor(1,2,2,0), c_ijkl.tensor(1,2,2,1), c_ijkl.tensor(1,2,2,2)},  // ij 2,3
                {c_ijkl.tensor(2,0,0,0), c_ijkl.tensor(2,0,0,1), c_ijkl.tensor(2,0,0,2),
                 c_ijkl.tensor(2,0,1,0), c_ijkl.tensor(2,0,1,1), c_ijkl.tensor(2,0,1,2),
                 c_ijkl.tensor(2,0,2,0), c_ijkl.tensor(2,0,2,1), c_ijkl.tensor(2,0,2,2)},  // ij 3,1
                {c_ijkl.tensor(2,1,0,0), c_ijkl.tensor(2,1,0,1), c_ijkl.tensor(2,1,0,2),
                 c_ijkl.tensor(2,1,1,0), c_ijkl.tensor(2,1,1,1), c_ijkl.tensor(2,1,1,2),
                 c_ijkl.tensor(2,1,2,0), c_ijkl.tensor(2,1,2,1), c_ijkl.tensor(2,1,2,2)},  // ij 3,2
                {c_ijkl.tensor(2,2,0,0), c_ijkl.tensor(2,2,0,1), c_ijkl.tensor(2,2,0,2),
                 c_ijkl.tensor(2,2,1,0), c_ijkl.tensor(2,2,1,1), c_ijkl.tensor(2,2,1,2),
                 c_ijkl.tensor(2,2,2,0), c_ijkl.tensor(2,2,2,1), c_ijkl.tensor(2,2,2,2)}   // ij 3,3
        };

        // create data arrays
        QBarDataArray *dataSet = new QBarDataArray;
        QBarDataRow *dataRow;

        dataSet->reserve(9);
        for (int ij = 0; ij < 9; ij++) {
            // Create a data row
            dataRow = new QBarDataRow(9);
            for (int kl = 0; kl < 9; kl++) {
                // Add data to the row
                (*dataRow)[kl].setValue(c_ijkl_data[ij][kl]);
            }
            // Add the row to the set
            dataSet->append(dataRow);
        }

        // Add data to the data proxy (the data proxy assumes ownership of it)
        primary_series->dataProxy()->resetArray(dataSet, ij_list, ij_list);
        break;
    }
    case 37: { // Fluorite
        density_line_edit->setText(QString::number(mpc::data::FluoriteDensity<double>()));
        bulk_modulus_line_edit->setText(QString::number(mpc::data::FluoriteBulkModulus<double>()));
        shear_modulus_line_edit->setText(QString::number(mpc::data::FluoriteShearModulus<double>()));
        c11_line_edit->setText(QString::number(mpc::data::FluoriteC11<double>()));
        c12_line_edit->setText(QString::number(mpc::data::FluoriteC12<double>()));
        c13_line_edit->setText(QString::number(mpc::data::FluoriteC13<double>()));
        c14_line_edit->setText(QString::number(mpc::data::FluoriteC14<double>()));
        c15_line_edit->setText(QString::number(mpc::data::FluoriteC15<double>()));
        c16_line_edit->setText(QString::number(mpc::data::FluoriteC16<double>()));
        c22_line_edit->setText(QString::number(mpc::data::FluoriteC22<double>()));
        c23_line_edit->setText(QString::number(mpc::data::FluoriteC23<double>()));
        c24_line_edit->setText(QString::number(mpc::data::FluoriteC24<double>()));
        c25_line_edit->setText(QString::number(mpc::data::FluoriteC25<double>()));
        c26_line_edit->setText(QString::number(mpc::data::FluoriteC26<double>()));
        c33_line_edit->setText(QString::number(mpc::data::FluoriteC33<double>()));
        c34_line_edit->setText(QString::number(mpc::data::FluoriteC34<double>()));
        c35_line_edit->setText(QString::number(mpc::data::FluoriteC35<double>()));
        c36_line_edit->setText(QString::number(mpc::data::FluoriteC36<double>()));
        c44_line_edit->setText(QString::number(mpc::data::FluoriteC44<double>()));
        c45_line_edit->setText(QString::number(mpc::data::FluoriteC45<double>()));
        c46_line_edit->setText(QString::number(mpc::data::FluoriteC46<double>()));
        c55_line_edit->setText(QString::number(mpc::data::FluoriteC55<double>()));
        c56_line_edit->setText(QString::number(mpc::data::FluoriteC56<double>()));
        c66_line_edit->setText(QString::number(mpc::data::FluoriteC66<double>()));
        // data
        mpc::core::StiffnessTensor<float> c_ijkl = mpc::data::FluoriteStiffnessTensor<float>();
        float c_ijkl_data[9][9] = {
                {c_ijkl.tensor(0,0,0,0), c_ijkl.tensor(0,0,0,1), c_ijkl.tensor(0,0,0,2),
                 c_ijkl.tensor(0,0,1,0), c_ijkl.tensor(0,0,1,1), c_ijkl.tensor(0,0,1,2),
                 c_ijkl.tensor(0,0,2,0), c_ijkl.tensor(0,0,2,1), c_ijkl.tensor(0,0,2,2)},  // ij 1,1
                {c_ijkl.tensor(0,1,0,0), c_ijkl.tensor(0,1,0,1), c_ijkl.tensor(0,1,0,2),
                 c_ijkl.tensor(0,1,1,0), c_ijkl.tensor(0,1,1,1), c_ijkl.tensor(0,1,1,2),
                 c_ijkl.tensor(0,1,2,0), c_ijkl.tensor(0,1,2,1), c_ijkl.tensor(0,1,2,2)},  // ij 1,2
                {c_ijkl.tensor(0,2,0,0), c_ijkl.tensor(0,2,0,1), c_ijkl.tensor(0,2,0,2),
                 c_ijkl.tensor(0,2,1,0), c_ijkl.tensor(0,2,1,1), c_ijkl.tensor(0,2,1,2),
                 c_ijkl.tensor(0,2,2,0), c_ijkl.tensor(0,2,2,1), c_ijkl.tensor(0,2,2,2)},  // ij 1,3
                {c_ijkl.tensor(1,0,0,0), c_ijkl.tensor(1,0,0,1), c_ijkl.tensor(1,0,0,2),
                 c_ijkl.tensor(1,0,1,0), c_ijkl.tensor(1,0,1,1), c_ijkl.tensor(1,0,1,2),
                 c_ijkl.tensor(1,0,2,0), c_ijkl.tensor(1,0,2,1), c_ijkl.tensor(1,0,2,2)},  // ij 2,1
                {c_ijkl.tensor(1,1,0,0), c_ijkl.tensor(1,1,0,1), c_ijkl.tensor(1,1,0,2),
                 c_ijkl.tensor(1,1,1,0), c_ijkl.tensor(1,1,1,1), c_ijkl.tensor(1,1,1,2),
                 c_ijkl.tensor(1,1,2,0), c_ijkl.tensor(1,1,2,1), c_ijkl.tensor(1,1,2,2)},  // ij 2,2
                {c_ijkl.tensor(1,2,0,0), c_ijkl.tensor(1,2,0,1), c_ijkl.tensor(1,2,0,2),
                 c_ijkl.tensor(1,2,1,0), c_ijkl.tensor(1,2,1,1), c_ijkl.tensor(1,2,1,2),
                 c_ijkl.tensor(1,2,2,0), c_ijkl.tensor(1,2,2,1), c_ijkl.tensor(1,2,2,2)},  // ij 2,3
                {c_ijkl.tensor(2,0,0,0), c_ijkl.tensor(2,0,0,1), c_ijkl.tensor(2,0,0,2),
                 c_ijkl.tensor(2,0,1,0), c_ijkl.tensor(2,0,1,1), c_ijkl.tensor(2,0,1,2),
                 c_ijkl.tensor(2,0,2,0), c_ijkl.tensor(2,0,2,1), c_ijkl.tensor(2,0,2,2)},  // ij 3,1
                {c_ijkl.tensor(2,1,0,0), c_ijkl.tensor(2,1,0,1), c_ijkl.tensor(2,1,0,2),
                 c_ijkl.tensor(2,1,1,0), c_ijkl.tensor(2,1,1,1), c_ijkl.tensor(2,1,1,2),
                 c_ijkl.tensor(2,1,2,0), c_ijkl.tensor(2,1,2,1), c_ijkl.tensor(2,1,2,2)},  // ij 3,2
                {c_ijkl.tensor(2,2,0,0), c_ijkl.tensor(2,2,0,1), c_ijkl.tensor(2,2,0,2),
                 c_ijkl.tensor(2,2,1,0), c_ijkl.tensor(2,2,1,1), c_ijkl.tensor(2,2,1,2),
                 c_ijkl.tensor(2,2,2,0), c_ijkl.tensor(2,2,2,1), c_ijkl.tensor(2,2,2,2)}   // ij 3,3
        };

        // create data arrays
        QBarDataArray *dataSet = new QBarDataArray;
        QBarDataRow *dataRow;

        dataSet->reserve(9);
        for (int ij = 0; ij < 9; ij++) {
            // Create a data row
            dataRow = new QBarDataRow(9);
            for (int kl = 0; kl < 9; kl++) {
                // Add data to the row
                (*dataRow)[kl].setValue(c_ijkl_data[ij][kl]);
            }
            // Add the row to the set
            dataSet->append(dataRow);
        }

        // Add data to the data proxy (the data proxy assumes ownership of it)
        primary_series->dataProxy()->resetArray(dataSet, ij_list, ij_list);
        break;
    }
    case 38: { // Halite
        density_line_edit->setText(QString::number(mpc::data::HaliteDensity<double>()));
        bulk_modulus_line_edit->setText(QString::number(mpc::data::HaliteBulkModulus<double>()));
        shear_modulus_line_edit->setText(QString::number(mpc::data::HaliteShearModulus<double>()));
        c11_line_edit->setText(QString::number(mpc::data::HaliteC11<double>()));
        c12_line_edit->setText(QString::number(mpc::data::HaliteC12<double>()));
        c13_line_edit->setText(QString::number(mpc::data::HaliteC13<double>()));
        c14_line_edit->setText(QString::number(mpc::data::HaliteC14<double>()));
        c15_line_edit->setText(QString::number(mpc::data::HaliteC15<double>()));
        c16_line_edit->setText(QString::number(mpc::data::HaliteC16<double>()));
        c22_line_edit->setText(QString::number(mpc::data::HaliteC22<double>()));
        c23_line_edit->setText(QString::number(mpc::data::HaliteC23<double>()));
        c24_line_edit->setText(QString::number(mpc::data::HaliteC24<double>()));
        c25_line_edit->setText(QString::number(mpc::data::HaliteC25<double>()));
        c26_line_edit->setText(QString::number(mpc::data::HaliteC26<double>()));
        c33_line_edit->setText(QString::number(mpc::data::HaliteC33<double>()));
        c34_line_edit->setText(QString::number(mpc::data::HaliteC34<double>()));
        c35_line_edit->setText(QString::number(mpc::data::HaliteC35<double>()));
        c36_line_edit->setText(QString::number(mpc::data::HaliteC36<double>()));
        c44_line_edit->setText(QString::number(mpc::data::HaliteC44<double>()));
        c45_line_edit->setText(QString::number(mpc::data::HaliteC45<double>()));
        c46_line_edit->setText(QString::number(mpc::data::HaliteC46<double>()));
        c55_line_edit->setText(QString::number(mpc::data::HaliteC55<double>()));
        c56_line_edit->setText(QString::number(mpc::data::HaliteC56<double>()));
        c66_line_edit->setText(QString::number(mpc::data::HaliteC66<double>()));
        // data
        mpc::core::StiffnessTensor<float> c_ijkl = mpc::data::HaliteStiffnessTensor<float>();
        float c_ijkl_data[9][9] = {
                {c_ijkl.tensor(0,0,0,0), c_ijkl.tensor(0,0,0,1), c_ijkl.tensor(0,0,0,2),
                 c_ijkl.tensor(0,0,1,0), c_ijkl.tensor(0,0,1,1), c_ijkl.tensor(0,0,1,2),
                 c_ijkl.tensor(0,0,2,0), c_ijkl.tensor(0,0,2,1), c_ijkl.tensor(0,0,2,2)},  // ij 1,1
                {c_ijkl.tensor(0,1,0,0), c_ijkl.tensor(0,1,0,1), c_ijkl.tensor(0,1,0,2),
                 c_ijkl.tensor(0,1,1,0), c_ijkl.tensor(0,1,1,1), c_ijkl.tensor(0,1,1,2),
                 c_ijkl.tensor(0,1,2,0), c_ijkl.tensor(0,1,2,1), c_ijkl.tensor(0,1,2,2)},  // ij 1,2
                {c_ijkl.tensor(0,2,0,0), c_ijkl.tensor(0,2,0,1), c_ijkl.tensor(0,2,0,2),
                 c_ijkl.tensor(0,2,1,0), c_ijkl.tensor(0,2,1,1), c_ijkl.tensor(0,2,1,2),
                 c_ijkl.tensor(0,2,2,0), c_ijkl.tensor(0,2,2,1), c_ijkl.tensor(0,2,2,2)},  // ij 1,3
                {c_ijkl.tensor(1,0,0,0), c_ijkl.tensor(1,0,0,1), c_ijkl.tensor(1,0,0,2),
                 c_ijkl.tensor(1,0,1,0), c_ijkl.tensor(1,0,1,1), c_ijkl.tensor(1,0,1,2),
                 c_ijkl.tensor(1,0,2,0), c_ijkl.tensor(1,0,2,1), c_ijkl.tensor(1,0,2,2)},  // ij 2,1
                {c_ijkl.tensor(1,1,0,0), c_ijkl.tensor(1,1,0,1), c_ijkl.tensor(1,1,0,2),
                 c_ijkl.tensor(1,1,1,0), c_ijkl.tensor(1,1,1,1), c_ijkl.tensor(1,1,1,2),
                 c_ijkl.tensor(1,1,2,0), c_ijkl.tensor(1,1,2,1), c_ijkl.tensor(1,1,2,2)},  // ij 2,2
                {c_ijkl.tensor(1,2,0,0), c_ijkl.tensor(1,2,0,1), c_ijkl.tensor(1,2,0,2),
                 c_ijkl.tensor(1,2,1,0), c_ijkl.tensor(1,2,1,1), c_ijkl.tensor(1,2,1,2),
                 c_ijkl.tensor(1,2,2,0), c_ijkl.tensor(1,2,2,1), c_ijkl.tensor(1,2,2,2)},  // ij 2,3
                {c_ijkl.tensor(2,0,0,0), c_ijkl.tensor(2,0,0,1), c_ijkl.tensor(2,0,0,2),
                 c_ijkl.tensor(2,0,1,0), c_ijkl.tensor(2,0,1,1), c_ijkl.tensor(2,0,1,2),
                 c_ijkl.tensor(2,0,2,0), c_ijkl.tensor(2,0,2,1), c_ijkl.tensor(2,0,2,2)},  // ij 3,1
                {c_ijkl.tensor(2,1,0,0), c_ijkl.tensor(2,1,0,1), c_ijkl.tensor(2,1,0,2),
                 c_ijkl.tensor(2,1,1,0), c_ijkl.tensor(2,1,1,1), c_ijkl.tensor(2,1,1,2),
                 c_ijkl.tensor(2,1,2,0), c_ijkl.tensor(2,1,2,1), c_ijkl.tensor(2,1,2,2)},  // ij 3,2
                {c_ijkl.tensor(2,2,0,0), c_ijkl.tensor(2,2,0,1), c_ijkl.tensor(2,2,0,2),
                 c_ijkl.tensor(2,2,1,0), c_ijkl.tensor(2,2,1,1), c_ijkl.tensor(2,2,1,2),
                 c_ijkl.tensor(2,2,2,0), c_ijkl.tensor(2,2,2,1), c_ijkl.tensor(2,2,2,2)}   // ij 3,3
        };

        // create data arrays
        QBarDataArray *dataSet = new QBarDataArray;
        QBarDataRow *dataRow;

        dataSet->reserve(9);
        for (int ij = 0; ij < 9; ij++) {
            // Create a data row
            dataRow = new QBarDataRow(9);
            for (int kl = 0; kl < 9; kl++) {
                // Add data to the row
                (*dataRow)[kl].setValue(c_ijkl_data[ij][kl]);
            }
            // Add the row to the set
            dataSet->append(dataRow);
        }

        // Add data to the data proxy (the data proxy assumes ownership of it)
        primary_series->dataProxy()->resetArray(dataSet, ij_list, ij_list);
        break;
    }
    case 39: { // Sylvite
        density_line_edit->setText(QString::number(mpc::data::SylviteDensity<double>()));
        bulk_modulus_line_edit->setText(QString::number(mpc::data::SylviteBulkModulus<double>()));
        shear_modulus_line_edit->setText(QString::number(mpc::data::SylviteShearModulus<double>()));
        c11_line_edit->setText(QString::number(mpc::data::SylviteC11<double>()));
        c12_line_edit->setText(QString::number(mpc::data::SylviteC12<double>()));
        c13_line_edit->setText(QString::number(mpc::data::SylviteC13<double>()));
        c14_line_edit->setText(QString::number(mpc::data::SylviteC14<double>()));
        c15_line_edit->setText(QString::number(mpc::data::SylviteC15<double>()));
        c16_line_edit->setText(QString::number(mpc::data::SylviteC16<double>()));
        c22_line_edit->setText(QString::number(mpc::data::SylviteC22<double>()));
        c23_line_edit->setText(QString::number(mpc::data::SylviteC23<double>()));
        c24_line_edit->setText(QString::number(mpc::data::SylviteC24<double>()));
        c25_line_edit->setText(QString::number(mpc::data::SylviteC25<double>()));
        c26_line_edit->setText(QString::number(mpc::data::SylviteC26<double>()));
        c33_line_edit->setText(QString::number(mpc::data::SylviteC33<double>()));
        c34_line_edit->setText(QString::number(mpc::data::SylviteC34<double>()));
        c35_line_edit->setText(QString::number(mpc::data::SylviteC35<double>()));
        c36_line_edit->setText(QString::number(mpc::data::SylviteC36<double>()));
        c44_line_edit->setText(QString::number(mpc::data::SylviteC44<double>()));
        c45_line_edit->setText(QString::number(mpc::data::SylviteC45<double>()));
        c46_line_edit->setText(QString::number(mpc::data::SylviteC46<double>()));
        c55_line_edit->setText(QString::number(mpc::data::SylviteC55<double>()));
        c56_line_edit->setText(QString::number(mpc::data::SylviteC56<double>()));
        c66_line_edit->setText(QString::number(mpc::data::SylviteC66<double>()));
        // data
        mpc::core::StiffnessTensor<float> c_ijkl = mpc::data::SylviteStiffnessTensor<float>();
        float c_ijkl_data[9][9] = {
                {c_ijkl.tensor(0,0,0,0), c_ijkl.tensor(0,0,0,1), c_ijkl.tensor(0,0,0,2),
                 c_ijkl.tensor(0,0,1,0), c_ijkl.tensor(0,0,1,1), c_ijkl.tensor(0,0,1,2),
                 c_ijkl.tensor(0,0,2,0), c_ijkl.tensor(0,0,2,1), c_ijkl.tensor(0,0,2,2)},  // ij 1,1
                {c_ijkl.tensor(0,1,0,0), c_ijkl.tensor(0,1,0,1), c_ijkl.tensor(0,1,0,2),
                 c_ijkl.tensor(0,1,1,0), c_ijkl.tensor(0,1,1,1), c_ijkl.tensor(0,1,1,2),
                 c_ijkl.tensor(0,1,2,0), c_ijkl.tensor(0,1,2,1), c_ijkl.tensor(0,1,2,2)},  // ij 1,2
                {c_ijkl.tensor(0,2,0,0), c_ijkl.tensor(0,2,0,1), c_ijkl.tensor(0,2,0,2),
                 c_ijkl.tensor(0,2,1,0), c_ijkl.tensor(0,2,1,1), c_ijkl.tensor(0,2,1,2),
                 c_ijkl.tensor(0,2,2,0), c_ijkl.tensor(0,2,2,1), c_ijkl.tensor(0,2,2,2)},  // ij 1,3
                {c_ijkl.tensor(1,0,0,0), c_ijkl.tensor(1,0,0,1), c_ijkl.tensor(1,0,0,2),
                 c_ijkl.tensor(1,0,1,0), c_ijkl.tensor(1,0,1,1), c_ijkl.tensor(1,0,1,2),
                 c_ijkl.tensor(1,0,2,0), c_ijkl.tensor(1,0,2,1), c_ijkl.tensor(1,0,2,2)},  // ij 2,1
                {c_ijkl.tensor(1,1,0,0), c_ijkl.tensor(1,1,0,1), c_ijkl.tensor(1,1,0,2),
                 c_ijkl.tensor(1,1,1,0), c_ijkl.tensor(1,1,1,1), c_ijkl.tensor(1,1,1,2),
                 c_ijkl.tensor(1,1,2,0), c_ijkl.tensor(1,1,2,1), c_ijkl.tensor(1,1,2,2)},  // ij 2,2
                {c_ijkl.tensor(1,2,0,0), c_ijkl.tensor(1,2,0,1), c_ijkl.tensor(1,2,0,2),
                 c_ijkl.tensor(1,2,1,0), c_ijkl.tensor(1,2,1,1), c_ijkl.tensor(1,2,1,2),
                 c_ijkl.tensor(1,2,2,0), c_ijkl.tensor(1,2,2,1), c_ijkl.tensor(1,2,2,2)},  // ij 2,3
                {c_ijkl.tensor(2,0,0,0), c_ijkl.tensor(2,0,0,1), c_ijkl.tensor(2,0,0,2),
                 c_ijkl.tensor(2,0,1,0), c_ijkl.tensor(2,0,1,1), c_ijkl.tensor(2,0,1,2),
                 c_ijkl.tensor(2,0,2,0), c_ijkl.tensor(2,0,2,1), c_ijkl.tensor(2,0,2,2)},  // ij 3,1
                {c_ijkl.tensor(2,1,0,0), c_ijkl.tensor(2,1,0,1), c_ijkl.tensor(2,1,0,2),
                 c_ijkl.tensor(2,1,1,0), c_ijkl.tensor(2,1,1,1), c_ijkl.tensor(2,1,1,2),
                 c_ijkl.tensor(2,1,2,0), c_ijkl.tensor(2,1,2,1), c_ijkl.tensor(2,1,2,2)},  // ij 3,2
                {c_ijkl.tensor(2,2,0,0), c_ijkl.tensor(2,2,0,1), c_ijkl.tensor(2,2,0,2),
                 c_ijkl.tensor(2,2,1,0), c_ijkl.tensor(2,2,1,1), c_ijkl.tensor(2,2,1,2),
                 c_ijkl.tensor(2,2,2,0), c_ijkl.tensor(2,2,2,1), c_ijkl.tensor(2,2,2,2)}   // ij 3,3
        };

        // create data arrays
        QBarDataArray *dataSet = new QBarDataArray;
        QBarDataRow *dataRow;

        dataSet->reserve(9);
        for (int ij = 0; ij < 9; ij++) {
            // Create a data row
            dataRow = new QBarDataRow(9);
            for (int kl = 0; kl < 9; kl++) {
                // Add data to the row
                (*dataRow)[kl].setValue(c_ijkl_data[ij][kl]);
            }
            // Add the row to the set
            dataSet->append(dataRow);
        }

        // Add data to the data proxy (the data proxy assumes ownership of it)
        primary_series->dataProxy()->resetArray(dataSet, ij_list, ij_list);
        break;
    }
    default: {}

    }  // end switch
}
