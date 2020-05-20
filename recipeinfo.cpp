#include <QPushButton>
#include "recipeinfo.h"

RecipeInfo::RecipeInfo(QWidget *parent)
{
    setParent(parent);
    QHBoxLayout * mainLayout = new QHBoxLayout();

    recipetab= new RecipeTab();
    QPushButton * button2 = new QPushButton("edee");

    tabs = new QTabWidget();
    tabs->addTab(recipetab,"Informations");
    tabs->addTab(button2,"Ingrédients");

    mainLayout->addWidget(tabs);
    setLayout(mainLayout);
}
