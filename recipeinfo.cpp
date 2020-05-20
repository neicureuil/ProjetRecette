#include <QPushButton>
#include "recipeinfo.h"

RecipeInfo::RecipeInfo(QWidget *parent)
{
    setParent(parent);
    QHBoxLayout * mainLayout = new QHBoxLayout();

    QPushButton * button = new QPushButton("eee");
    QPushButton * button2 = new QPushButton("edee");

    tabs = new QTabWidget();
    tabs->addTab(button,"Informations");
    tabs->addTab(button2,"Ingrédients");

    mainLayout->addWidget(tabs);
    setLayout(mainLayout);
}
