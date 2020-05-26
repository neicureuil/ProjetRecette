#include "recipeinfo.h"

RecipeInfo::RecipeInfo(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout * mainLayout = new QVBoxLayout();

    recipetab = new RecipeTab();
    //steptab = new StepsTab();
    ingtab = new IngredientTab();

    QScrollArea * recipeTabScroll = new QScrollArea(this);
    recipeTabScroll->setWidgetResizable(true);
    recipeTabScroll->setWidget(recipetab);


    tabs = new QTabWidget();
    tabs->addTab(recipeTabScroll,"Informations");
    tabs->addTab(ingtab,"Ingrédients");
    //tabs->addTab(steptab, "Etapes");


    startBtn = new QPushButton("Cuisiner");

    mainLayout->addWidget(tabs);
    mainLayout->addWidget(startBtn);

    setLayout(mainLayout);

    connect(startBtn, SIGNAL(clicked()), this, SLOT(StartCooking()));

    connect(this, SIGNAL(recipeLoaded(Recipe*)), recipetab, SLOT(updateUI(Recipe*)));
    connect(this, SIGNAL(ingredientsLoaded(const QStringList&)), ingtab, SLOT(SetIngredients(const QStringList&)));
}

void RecipeInfo::StartCooking() {

}

void RecipeInfo::LoadRecipe(Recipe * r) {
    emit recipeLoaded(r);
    emit ingredientsLoaded(r->getIngredients());
}
