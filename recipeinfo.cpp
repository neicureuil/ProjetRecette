#include "recipeinfo.h"

RecipeInfo::RecipeInfo(QWidget *parent) : QWidget(parent)
{
    stepdialog = new StepsDialog(this);

    QVBoxLayout * mainLayout = new QVBoxLayout();

    recipetab = new RecipeTab();
    ingtab = new IngredientTab();

    QScrollArea * recipeTabScroll = new QScrollArea(this);
    recipeTabScroll->setWidgetResizable(true);
    recipeTabScroll->setWidget(recipetab);


    tabs = new QTabWidget();
    tabs->addTab(recipeTabScroll,"Informations");
    tabs->addTab(ingtab,"Ingrédients");


    startBtn = new QPushButton("Cuisiner");

    mainLayout->addWidget(tabs);
    mainLayout->addWidget(startBtn);

    setLayout(mainLayout);

    connect(startBtn, SIGNAL(clicked()), this, SLOT(StartCooking()));

    connect(this, SIGNAL(recipeLoaded(Recipe*)), recipetab, SLOT(updateUI(Recipe*)));
    connect(this, SIGNAL(ingredientsLoaded(const QStringList&)), ingtab, SLOT(SetIngredients(const QStringList&)));
   connect(this, SIGNAL(stepLoaded(const QStringList&)), stepdialog, SLOT(Init(const QStringList&)));
}



void RecipeInfo::StartCooking() {
    stepdialog->show();
}

void RecipeInfo::LoadRecipe(Recipe * r) {
    emit recipeLoaded(r);
    emit ingredientsLoaded(r->getIngredients());
    emit stepLoaded(r->getInstructions());
}
