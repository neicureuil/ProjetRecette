#ifndef RECIPEINFO_H
#define RECIPEINFO_H

#include <QWidget>
#include <QTabWidget>
#include <QHBoxLayout>
#include <QPushButton>
#include <QScrollArea>

#include "ingredienttab.h"
#include "recipetab.h"
#include "stepstab.h"

class RecipeInfo : public QWidget
{
    Q_OBJECT

    private:
        QPushButton* startBtn;
        QTabWidget* tabs;
        RecipeTab* recipetab;
        IngredientTab* ingtab;
        StepsTab* steptab;

    public:
        RecipeInfo(QWidget *parent = nullptr);
        inline RecipeTab* GetRecipeTab() { return recipetab; };
        inline IngredientTab* GetIngredientTab() { return ingtab; };

    public slots:
        void StartCooking();
        void LoadRecipe(Recipe* r);

    signals:
        //TODO doc
        void recipeLoaded(Recipe *);
        //TODO doc
        void ingredientsLoaded(const QStringList& list);

};

#endif // RECIPEINFO_H

