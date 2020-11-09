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
    tabs->addTab(recipeTabScroll, "");
    tabs->addTab(ingtab, "");


    startBtn = new QPushButton();
    startBtn->setDisabled(true);

    mainLayout->addWidget(tabs);
    mainLayout->addWidget(startBtn);

    startLabel = new QLabel();
    startLabel->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(startLabel);

    setLayout(mainLayout);

    UpdateLang();

    connect(startBtn, SIGNAL(clicked()), this, SLOT(StartCooking()));
    connect(this, SIGNAL(recipeLoaded(Recipe*)), recipetab, SLOT(UpdateUI(Recipe*)));
    connect(this, SIGNAL(ingredientsLoaded(const QStringList&)), ingtab, SLOT(SetIngredients(const QStringList&)));
    connect(this, SIGNAL(stepLoaded(const QStringList&)), stepdialog, SLOT(Init(const QStringList&)));

    connect(this, SIGNAL(changeLang()), recipetab, SLOT(UpdateLang()));


    tabs->hide();
    startBtn->hide();
}

void RecipeInfo::UpdateLang() {
    startLabel->setText(tr("Veuillez charger une recette\nFichier -> Charger une recette\nOU\nGlissez-Déposez un fichier de recette"));
    tabs->setTabText(0, tr("Informations"));
    tabs->setTabText(1, tr("Ingrédients"));
    startBtn->setText(tr("Cuisiner"));
    emit changeLang();
}

void RecipeInfo::StartCooking() {
    stepdialog->show();
}

void RecipeInfo::LoadRecipe(Recipe * r) {
    emit recipeLoaded(r);
    emit ingredientsLoaded(r->getIngredients());
    emit stepLoaded(r->getInstructions());
    startBtn->setEnabled(true);

    startLabel->hide();
    tabs->show();
    startBtn->show();
}
