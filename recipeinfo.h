#ifndef RECIPEINFO_H
#define RECIPEINFO_H

#include <QWidget>
#include <QTabWidget>
#include <QHBoxLayout>
#include <QPushButton>

#include "recipetab.h"
#include "stepstab.h"

class RecipeInfo : public QWidget
{
    Q_OBJECT

    private:
        QPushButton* startBtn;
        QTabWidget* tabs;
        RecipeTab* recipetab;
        StepsTab* steptab;

    public:
        RecipeInfo(QWidget *parent = nullptr);
        inline RecipeTab* GetRecipeTab() { return recipetab; };
};

#endif // RECIPEINFO_H

