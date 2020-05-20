#include "stepstab.h"

StepsTab::StepsTab(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout * secondLayout = new QVBoxLayout();
    QHBoxLayout * thirdLayout = new QHBoxLayout();

    choicebox = new QComboBox();
    secondLayout->addWidget(choicebox);
    secondLayout->setAlignment(Qt::AlignTop);
    secondLayout->setAlignment(choicebox, Qt::AlignLeft);

    steplabel = new QLabel("Sortez couverts");
    secondLayout->addWidget(steplabel);
    secondLayout->setAlignment(steplabel, Qt::AlignCenter);
    secondLayout->setAlignment(thirdLayout, Qt::AlignBottom);

    previousbtn = new QPushButton("Précédent");
    thirdLayout->addWidget(previousbtn);

    nextbtn = new QPushButton("Suivant");
    thirdLayout->addWidget(nextbtn);

    setLayout(secondLayout);
    secondLayout->addLayout(thirdLayout);
}
