#ifndef RECIPEINFO_H
#define RECIPEINFO_H

#include <QWidget>
#include <QTabWidget>
#include <QHBoxLayout>
#include "recipetab.h"

class RecipeInfo : public QWidget
{
    Q_OBJECT

    private:
        QTabWidget* tabs;
        RecipeTab* recipetab;

    public:
        RecipeInfo(QWidget *parent = nullptr);
};

#endif // RECIPEINFO_H

