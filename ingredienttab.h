#ifndef INGREDIENTTAB_H
#define INGREDIENTTAB_H

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QListView>
#include <QVBoxLayout>
#include <QHBoxLayout>

#include "ingredientlistmodel.h"

class IngredientTab : public QWidget
{
    Q_OBJECT

    private:
        QListView* list;
        IngredientListModel* model;

    public:
        IngredientTab(QWidget *parent = nullptr);

    public slots:
        void SetIngredients(const QStringList &list);

signals:

};

#endif // INGREDIENTTAB_H
