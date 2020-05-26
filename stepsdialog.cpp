#include "stepsdialog.h"
#include <QString>

StepsDialog::StepsDialog(QWidget *parent) : QDialog(parent)
{
    setModal(false);
    //machine = new QStateMachine(this);

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
   current = i;
   steplabel->setText(steps[current]);
}

void StepsDialog::instructionSuivante() {
   if(current < steps.length()-1){
       current++;
       steplabel->setText(steps[current]);
   }
   emit endChangeInstruction();
}

void StepsDialog::instructionPrecedente() {
    if(current > 0){
        current--;
        steplabel->setText(steps[current]);
    }
    emit endChangeInstruction();
}

void StepsDialog::Init(const QStringList& liste){
    //delete machine;
    steps = liste;
    current = -1;

    for(int i=1; i<=liste.length(); i++) {
        choicebox->addItem(tr("Etape ") + QString::number(i).toStdString().c_str());
    }


    QState *etatDebut = new QState();
    QState *enCours = new QState();
    QState *etatFin = new QState();

    QState *enCoursSuivant = new QState();
    QState *enCoursPrecedent = new QState();

    etatDebut->addTransition(nextbtn, SIGNAL(clicked()), enCours);

    enCours->addTransition(nextbtn, SIGNAL(clicked()), enCoursSuivant);
    enCours->addTransition(previousbtn, SIGNAL(clicked()), enCoursPrecedent);

    enCoursSuivant->addTransition(this, SIGNAL(endChangeInstruction()), enCours);
    enCoursPrecedent->addTransition(this, SIGNAL(endChangeInstruction()), enCours);

    connect(enCoursSuivant,SIGNAL(entered()), this, SLOT(instructionSuivante()));
    connect(enCoursPrecedent,SIGNAL(entered()), this, SLOT(instructionPrecedente()));

    etatFin->addTransition(previousbtn, SIGNAL(clicked()), enCours);



    machine.addState(enCoursSuivant);
    machine.addState(enCoursPrecedent);

    machine.addState(etatDebut);
    machine.addState(enCours);
    machine.addState(etatFin);

    machine.setInitialState(etatDebut);
    machine.start();

}
