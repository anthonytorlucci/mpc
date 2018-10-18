#include "homepage.h"

#include <QLabel>
#include <QVBoxLayout>

HomePage::HomePage(QWidget *parent) {
    //
    QLabel* mpc_title = new QLabel(this);
    mpc_title->setText("mpc");
    QLabel* mpc_desc = new QLabel(this);
    mpc_desc->setText("mechanical properties of crystals and polycrystalline aggregates");

    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addStretch();
    layout->addWidget(mpc_title);
    layout->addWidget(mpc_desc);
    layout->addStretch();

    setLayout(layout);
}