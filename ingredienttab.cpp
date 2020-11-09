#include "ingredienttab.h"

IngredientTab::IngredientTab(QWidget *parent) : QWidget(parent) {

    QVBoxLayout* mainLayout = new QVBoxLayout();

    list = new QListView(this);
    model = new IngredientListModel(this);

    player = new QMediaPlayer(this);
    player->setVolume(50);
    player->setMedia(QUrl("qrc:/sounds/sardine.mp3"));

    list->setModel(model);
    list->show();

    QItemSelectionModel *selectionModel = list->selectionModel();

    connect(selectionModel, SIGNAL(selectionChanged(const QItemSelection&, const QItemSelection&)), this, SLOT(ListItemSelected(const QItemSelection&, const QItemSelection&)));

    mainLayout->addWidget(list);

    setLayout(mainLayout);
}

void IngredientTab::SetIngredients(const QStringList &list) {
    model->setIngredients(list);
}

void IngredientTab::ListItemSelected(const QItemSelection &selected, const QItemSelection &deselected) {
    if(selected.isEmpty()) {
        player->stop();
        return;
    }
    QString v = selected.first().indexes().first().data().toString();
    if(v.toLower().contains("sardine")) {
        player->play();
    }else{
        player->stop();
    }
}
