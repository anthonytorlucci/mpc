#ifndef VIEW01MINERALDATA_H
#define VIEW01MINERALDATA_H

#include <QObject>
#include <QWidget>
#include <QLineEdit>
#include <QStringList>

#include <QtDataVisualization>
using namespace QtDataVisualization;

#include <mpc/data/mineraldataproperties.hpp>
#include <mpc/data/mineraldatatensors.hpp>

class View01MineralData : public QWidget
{
    Q_OBJECT
public:
    explicit View01MineralData(QWidget *parent = nullptr);
    ~View01MineralData();

signals:

public slots:
    void MineralComboBoxChanged(int);

private:
    QLineEdit* density_line_edit;
    QLineEdit* bulk_modulus_line_edit;
    QLineEdit* shear_modulus_line_edit;
    QLineEdit* c11_line_edit;
    QLineEdit* c12_line_edit;
    QLineEdit* c13_line_edit;
    QLineEdit* c14_line_edit;
    QLineEdit* c15_line_edit;
    QLineEdit* c16_line_edit;
    QLineEdit* c22_line_edit;
    QLineEdit* c23_line_edit;
    QLineEdit* c24_line_edit;
    QLineEdit* c25_line_edit;
    QLineEdit* c26_line_edit;
    QLineEdit* c33_line_edit;
    QLineEdit* c34_line_edit;
    QLineEdit* c35_line_edit;
    QLineEdit* c36_line_edit;
    QLineEdit* c44_line_edit;
    QLineEdit* c45_line_edit;
    QLineEdit* c46_line_edit;
    QLineEdit* c55_line_edit;
    QLineEdit* c56_line_edit;
    QLineEdit* c66_line_edit;

    // bar graph
    Q3DBars* bar_graph;
    QStringList ij_list;
    QValue3DAxis* cijkl_value_axis;
    QCategory3DAxis* ij_axis;
    QCategory3DAxis* kl_axis;
    QBar3DSeries* primary_series;
    //QAbstract3DSeries::Mesh bar_mesh;
};

#endif // VIEW01MINERALDATA_H
