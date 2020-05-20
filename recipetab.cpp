#include "recipetab.h"

RecipeTab::RecipeTab(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout * secondLayout = new QVBoxLayout();

    categorylabel= new QLabel("Catégorie: Ipsum");
    secondLayout->addWidget(categorylabel);
    secondLayout->setAlignment(Qt::AlignTop);
    secondLayout->setAlignment(categorylabel, Qt::AlignRight);

    namelabel= new QLabel("Nom de la recette");
    secondLayout->addWidget(namelabel);
    secondLayout->setAlignment(Qt::AlignTop);
    secondLayout->setAlignment(namelabel, Qt::AlignCenter);
    namelabel->setStyleSheet("border-bottom-width: 1px; border-bottom-style: solid; border-radius: 0px; font-weight: bold;");

    QHBoxLayout * thirdLayout = new QHBoxLayout();
    thirdLayout->setAlignment(Qt::AlignLeft);

    preptimelabel= new QLabel("Temps de préparation:");
    thirdLayout->addWidget(preptimelabel);

    cooktimelabel= new QLabel("Temps de cuisson:");
    thirdLayout->addWidget(cooktimelabel);

    totaltimelabel= new QLabel("Temps total:");
    thirdLayout->addWidget(totaltimelabel);

    yieldlabel= new QLabel("Nombre de parts:");
    thirdLayout->addWidget(yieldlabel);

    secondLayout->addLayout(thirdLayout);
   // rimage = new QImage();

    desclabel= new QLabel("Description de la recette:");
    secondLayout->addWidget(desclabel);
    secondLayout->setAlignment(desclabel, Qt::AlignLeft);
    desclabel->setStyleSheet("border-bottom-width: 1px; border-bottom-style: solid; border-radius: 0px;");

    desctxtlabel= new QLabel("Lorem Ipsum Ta kompri avec du lait et des cookies pour mon plaisir personnel");
    secondLayout->addWidget(desctxtlabel);
    secondLayout->setAlignment(desctxtlabel, Qt::AlignAbsolute);

    toolslabel= new QLabel("Outils nécéssaires:");
    secondLayout->addWidget(toolslabel);
    secondLayout->setAlignment(toolslabel, Qt::AlignLeft);

    kwordslabel= new QLabel("Mots clés:");
    secondLayout->addWidget(kwordslabel);
    secondLayout->setAlignment(kwordslabel, Qt::AlignLeft);

    urllabel= new QLabel("Lien de la recette");
    secondLayout->addWidget(urllabel);
    secondLayout->setAlignment(urllabel, Qt::AlignLeft);
    urllabel->setTextFormat(Qt::RichText);
    urllabel->setText("<a href='https://www.google.fr' >Lien de la recette</a>");
    urllabel->setTextInteractionFlags(Qt::TextBrowserInteraction);
    urllabel->setOpenExternalLinks(true);


    setLayout(secondLayout);



}
