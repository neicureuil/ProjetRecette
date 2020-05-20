#ifndef RECIPEINFO_H
#define RECIPEINFO_H

#include <QWidget>
#include <QTabWidget>
#include <QHBoxLayout>

class RecipeInfo : public QWidget
{
    Q_OBJECT

    private:
        QTabWidget* tabs;

    public:
        RecipeInfo(QWidget *parent = nullptr);
};

#endif // RECIPEINFO_H
