#include <QPushButton>
#include "recipeinfo.h"

RecipeInfo::RecipeInfo(QWidget *parent)
{
    setParent(parent);
    QHBoxLayout * mainLayout = new QHBoxLayout();

    recipetab = new RecipeTab();
    steptab = new StepsTab();
    QPushButton * button2 = new QPushButton("edee");

    tabs = new QTabWidget();
    tabs->addTab(recipetab,"Informations");
    tabs->addTab(button2,"Ingrédients");
    tabs->addTab(steptab, "Etapes");

    mainLayout->addWidget(tabs);

    startBtn = new QPushButton("Cuisiner");
    mainLayout->addWidget(startBtn);

    setLayout(mainLayout);
}
