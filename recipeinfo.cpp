#include <QPushButton>
#include "recipeinfo.h"

RecipeInfo::RecipeInfo(QWidget *parent)
{
    setParent(parent);
    QHBoxLayout * mainLayout = new QHBoxLayout();

    recipetab= new RecipeTab();
    stepstab= new StepsTab();
    QPushButton * button2 = new QPushButton("edee");

    tabs = new QTabWidget();
    tabs->addTab(recipetab,"Informations");
    tabs->addTab(button2,"Ingrédients");
    tabs->addTab(stepstab, "Etapes");

    mainLayout->addWidget(tabs);
    setLayout(mainLayout);
}
