#include "stepsdialog.h"


StepsDialog::StepsDialog(QWidget *parent) : QDialog(parent)
{
    setModal(false);
    endGif = new QMovie(":/images/end.gif");

    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    setMinimumWidth(400);
    setMinimumHeight(250);

    QVBoxLayout * mainLayout = new QVBoxLayout();
    QHBoxLayout * topLayout = new QHBoxLayout();
    QHBoxLayout * btnLayout = new QHBoxLayout();

    mainLayout->setAlignment(Qt::AlignTop);
    mainLayout->addSpacing(5);

    choicebox = new QComboBox();
    stepNumberLabel = new QLabel();

    topLayout->addWidget(choicebox);
    topLayout->addWidget(stepNumberLabel);

    topLayout->setAlignment(choicebox, Qt::AlignLeft);
    topLayout->setAlignment(stepNumberLabel, Qt::AlignRight);

    mainLayout->addLayout(topLayout);

    mainLayout->addSpacing(5);

    QScrollArea * labelScrollArea = new QScrollArea();

    steplabel = new QLabel();
    steplabel->setWordWrap(true);
    steplabel->setScaledContents(true);
    steplabel->setAlignment(Qt::AlignCenter);
    labelScrollArea->setWidget(steplabel);
    labelScrollArea->setAlignment(Qt::AlignCenter);
    labelScrollArea->setWidgetResizable(true);

    mainLayout->addWidget(labelScrollArea);


    previousbtn = new QPushButton();
    nextbtn = new QPushButton();

    btnLayout->addWidget(previousbtn);
    btnLayout->addWidget(nextbtn);

    mainLayout->addLayout(btnLayout);

    setLayout(mainLayout);

    CreateMachine();
    UpdateLang();

    connect(&machine, SIGNAL(stopped()), this, SLOT(LoadMachineDatas()));
    connect(choicebox,SIGNAL(currentIndexChanged(int)), this, SLOT(ComboChanged(int)));
}

void StepsDialog::CreateMachine() {
    QState *etatDebut = new QState();
    QState *enCours = new QState();
    QState *etatFin = new QState();

    QState *enCoursSuivant = new QState();
    QState *enCoursPrecedent = new QState();

    etatDebut->addTransition(nextbtn, SIGNAL(clicked()), enCours);
    etatDebut->assignProperty(steplabel, "text", tr("Préparez vos ingrédients et appuyez sur suivant pour commencer la recette."));

    enCours->addTransition(nextbtn, SIGNAL(clicked()), enCoursSuivant);
    enCours->addTransition(previousbtn, SIGNAL(clicked()), enCoursPrecedent);

    enCoursSuivant->addTransition(this, SIGNAL(endChangeInstruction()), enCours);
    enCoursSuivant->addTransition(this, SIGNAL(goToEndState()), etatFin);

    enCoursPrecedent->addTransition(this, SIGNAL(endChangeInstruction()), enCours);
    enCoursPrecedent->addTransition(this, SIGNAL(goToStartState()), etatDebut);

    etatFin->addTransition(previousbtn, SIGNAL(clicked()), enCours);


    enCours->addTransition(this, SIGNAL(endChangeInstruction()), enCours);

    connect(enCours, SIGNAL(entered()), this, SLOT(UpdateSteps()));
    connect(enCoursSuivant,SIGNAL(entered()), this, SLOT(InstructionSuivante()));
    connect(enCoursPrecedent,SIGNAL(entered()), this, SLOT(InstructionPrecedente()));


    machine.addState(enCoursSuivant);
    machine.addState(enCoursPrecedent);

    machine.addState(etatDebut);
    machine.addState(enCours);
    machine.addState(etatFin);

    machine.setInitialState(etatDebut);
}

void StepsDialog::UpdateSteps() {
    ResetBtn();
    choicebox->setCurrentIndex(current);
    steplabel->setText(steps[current]);
    stepNumberLabel->setText(QString::number(current+1) + "/" + QString::number(steps.length()));
}

void StepsDialog::UpdateLang() {
    setWindowTitle(tr("Instructions"));
    previousbtn->setText(tr("Précédent"));
    nextbtn->setText(tr("Suivant"));
    for(int i=0; i<steps.length(); i++) {
        choicebox->setItemText(i, tr("Etape") + " " + QString::number(i+1).toStdString().c_str());
    }
}

void StepsDialog::ComboChanged(int i) {
    if(machine.isRunning()){
       current = i;
       emit endChangeInstruction();
    }
}

void StepsDialog::InstructionSuivante() {
   ResetBtn();
   if(current < steps.length()-1){
       current++;
       emit endChangeInstruction();
   }else {
       nextbtn->setDisabled(true);
       steplabel->setMovie(endGif);
       endGif->start();

       stepNumberLabel->setText(QString::number(steps.length()) + "/" + QString::number(steps.length()));
       emit goToEndState();
   }
}

void StepsDialog::InstructionPrecedente() {
    ResetBtn();
    if(current > 0){
        current--;
        emit endChangeInstruction();
    }else{
        previousbtn->setDisabled(true);
        stepNumberLabel->setText("0/" + QString::number(steps.length()));
        emit goToStartState();
    }

}

void StepsDialog::ResetBtn(){
    endGif->stop();
    previousbtn->setEnabled(true);
    nextbtn->setEnabled(true);
}

void StepsDialog::LoadMachineDatas() {
    current = 0;
    stepNumberLabel->setText("0/" + QString::number(steps.length()));
    choicebox->clear();

    for(int i=0; i<steps.length(); i++) {
        choicebox->addItem("");
    }

    UpdateLang();
    ResetBtn();
    previousbtn->setDisabled(true);
    machine.start();
}

void StepsDialog::Init(const QStringList& liste){
    steps = liste;
    if(machine.isRunning()){
        machine.stop();
    }else {
        LoadMachineDatas();
    }
}
