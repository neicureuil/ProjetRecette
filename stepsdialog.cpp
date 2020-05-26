#include "stepsdialog.h"

StepsDialog::StepsDialog(QWidget *parent) : QDialog(parent)
{

    setModal(false);

    QVBoxLayout * mainLayout = new QVBoxLayout();
    QHBoxLayout * btnLayout = new QHBoxLayout();

    mainLayout->setAlignment(Qt::AlignTop);
    mainLayout->addSpacing(10);

    choicebox = new QComboBox();
    mainLayout->addWidget(choicebox);
    mainLayout->setAlignment(choicebox, Qt::AlignLeft);

    mainLayout->addSpacing(50);

    steplabel = new QLabel("Sortez couverts");
    mainLayout->addWidget(steplabel);
    mainLayout->setAlignment(steplabel, Qt::AlignCenter);

    mainLayout->addSpacing(50);

    previousbtn = new QPushButton("Précédent");
    nextbtn = new QPushButton("Suivant");

    btnLayout->addWidget(previousbtn);
    btnLayout->addWidget(nextbtn);

    mainLayout->addLayout(btnLayout);

    setLayout(mainLayout);
}
