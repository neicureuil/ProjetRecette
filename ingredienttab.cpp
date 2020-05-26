#include "ingredienttab.h"

IngredientTab::IngredientTab(QWidget *parent) : QWidget(parent) {

    QVBoxLayout* mainLayout = new QVBoxLayout();

    list = new QListView(this);
    model = new IngredientListModel(this);

    list->setModel(model);
    list->show();

    mainLayout->addWidget(list);

    setLayout(mainLayout);
}

void IngredientTab::SetIngredients(const QStringList &list) {
    model->setIngredients(list);
}
