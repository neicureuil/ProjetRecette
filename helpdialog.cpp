#include "helpdialog.h"

HelpDialog::HelpDialog(QWidget *parent) : QDialog(parent)
{
    setModal(true);
    setMinimumWidth(360);
    setMinimumHeight(300);
    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);

    QVBoxLayout * mainLayout = new QVBoxLayout();
    mainLayout->setAlignment(Qt::AlignLeft);

    infoLabel = new QLabel();
    mainLayout->addWidget(infoLabel);
    mainLayout->setAlignment(infoLabel, Qt::AlignLeft);

    //Masque pour image arrondis
    QBitmap mask(100,100);
    mask.fill(Qt::color0);
    QPainter painter(&mask);
    painter.setPen( Qt::transparent );
    painter.setBrush(Qt::color1);
    painter.drawRoundRect( 0, 0, 100, 100,12,12);

    QPixmap dylanMap(":/images/dylan.jpg");;
    dylanMap = dylanMap.scaled(100, 100,Qt::KeepAspectRatio, Qt::SmoothTransformation);
    dylanMap.setMask(mask);

    QPixmap jeremyMap(":/images/jeremy.jpg");;
    jeremyMap = jeremyMap.scaled(100, 100,Qt::KeepAspectRatio, Qt::SmoothTransformation);
    jeremyMap.setMask(mask);



    QHBoxLayout * dylanLayout = new QHBoxLayout();
    QLabel * dylanLabel = new QLabel();
    dylanTextLabel = new QLabel();
    dylanTextLabel->setWordWrap(true);
    dylanLabel->setPixmap(dylanMap);
    dylanLayout->addWidget(dylanLabel);
    dylanLayout->addWidget(dylanTextLabel);
    mainLayout->addLayout(dylanLayout);


    QHBoxLayout * jeremyLayout = new QHBoxLayout();
    QLabel * jeremyLabel = new QLabel();
    jeremyTextLabel = new QLabel();
    jeremyTextLabel->setWordWrap(true);
    jeremyLabel->setPixmap(jeremyMap);
    jeremyLayout->addWidget(jeremyLabel);
    jeremyLayout->addWidget(jeremyTextLabel);
    mainLayout->addLayout(jeremyLayout);

    QLabel * usingLabel = new QLabel();
    usingLabel->setPixmap(QPixmap(":/images/qt.png"));
    mainLayout->addWidget(usingLabel);
    mainLayout->setAlignment(usingLabel, Qt::AlignCenter);


    setLayout(mainLayout);
    UpdateLang();
}

void HelpDialog::UpdateLang() {
    setWindowTitle(tr("A Propos"));
    infoLabel->setText(tr("Projet QT : Lecteur de recette"));
    jeremyTextLabel->setText(tr("\" Ne pas lancer une partie de 6h de CivilizationVI quand vous avez un plat qui cuit sous peine de l'oublier \" - Jérémy"));
    dylanTextLabel->setText(tr("\" Le meilleur dans la cuisine c'est faire la vaisselle \" - Dylan"));
}
