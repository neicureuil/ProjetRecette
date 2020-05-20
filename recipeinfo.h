#ifndef RECIPEINFO_H
#define RECIPEINFO_H

#include <QWidget>
#include <QTabWidget>
#include <QHBoxLayout>
#include "recipetab.h"
#include "stepstab.h"

class RecipeInfo : public QWidget
{
    Q_OBJECT

    private:
        QTabWidget* tabs;
        RecipeTab* recipetab;
        StepsTab* stepstab;

    public:
        RecipeInfo(QWidget *parent = nullptr);
};

#endif // RECIPEINFO_H

