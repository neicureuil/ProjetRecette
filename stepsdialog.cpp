#include "stepsdialog.h"
#include <QString>

StepsDialog::StepsDialog(QWidget *parent) : QDialog(parent)
{

    setModal(false);
    machine = new QStateMachine(this);

    QVBoxLayout * mainLayout = new QVBoxLayout();
    QHBoxLayout * btnLayout = new QHBoxLayout();

    mainLayout->setAlignment(Qt::AlignTop);
    mainLayout->addSpacing(10);

    choicebox = new QComboBox();
    mainLayout->addWidget(choicebox);
    mainLayout->setAlignment(choicebox, Qt::AlignLeft);

    mainLayout->addSpacing(50);

    steplabel = new QLabel("Sortez couverts");
    steplabel->setWordWrap(true);
    mainLayout->addWidget(steplabel);
    mainLayout->setAlignment(steplabel, Qt::AlignCenter);

    mainLayout->addSpacing(50);

    previousbtn = new QPushButton("Précédent");
    nextbtn = new QPushButton("Suivant");

    btnLayout->addWidget(previousbtn);
    btnLayout->addWidget(nextbtn);

    mainLayout->addLayout(btnLayout);

    setLayout(mainLayout);

    connect(choicebox,SIGNAL(currentIndexChanged(int)), this, SLOT(ComboChanged(int)));
}

void StepsDialog::ComboChanged(int i) {
    machine->stop();
    machine->setRunning(false);
    machine->setInitialState(states[i]);
    machine->start();
}

void StepsDialog::Init(const QStringList& liste){
    //delete machine;


    QState *etatDebut = new QState();
    etatDebut->assignProperty(steplabel, "text", QString(tr("Appuyez sur Suivant pour commencer")));
    machine->addState(etatDebut);

    QState *etattmp = etatDebut;
    for(int i=0; i<liste.length(); i++) {
        QState *etat = new QState();
        etat->assignProperty(steplabel, "text", QString(liste[i]));
        etat->addTransition(previousbtn, SIGNAL(clicked()), etattmp);
        etattmp->addTransition(nextbtn, SIGNAL(clicked()), etat);
        etattmp=etat;
        machine->addState(etat);
        states.append(etat);
        choicebox->addItem(tr("Etape ") + QString::number(i).toStdString().c_str());
    }

    QState *etatFin = new QState();
    etatFin->assignProperty(steplabel, "text", QString(tr("Fin, appuyez sur précédent pour revenir en arrière")));
    etattmp->addTransition(nextbtn, SIGNAL(clicked()), etatFin);
    etatFin->addTransition(previousbtn, SIGNAL(clicked()), etattmp);
    machine->addState(etatFin);

    machine->setInitialState(etatDebut);
    machine->start();

}
