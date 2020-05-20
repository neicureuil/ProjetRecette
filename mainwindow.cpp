#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {


    rloader = new RecipeLoader();
    rInfo = new RecipeInfo(this);

    setupFileMenu();

    //loadRecipe();
    setCentralWidget(rInfo);

    connect(this, SIGNAL(recipeLoaded(Recipe*)), rInfo->GetRecipeTab(), SLOT(updateUI(Recipe*)));
}

MainWindow::~MainWindow() {

}

void MainWindow::setupFileMenu() {
    QMenu *fileMenu = new QMenu(tr("&Fichier"), this);
    menuBar()->addMenu(fileMenu);

    fileMenu->addAction(tr("&Charger une recette"), this, SLOT(loadRecipe()), QKeySequence::New);
    fileMenu->addAction(tr("&Quitter"), this, SLOT(closeSlot()), QKeySequence::Close);
}


void MainWindow::loadRecipe() {
    QFileDialog dialog(this);
    dialog.setFileMode(QFileDialog::AnyFile);
    dialog.setNameFilter(tr("Fichier JSON (*.json)"));
    dialog.setViewMode(QFileDialog::Detail);

    QStringList fileNames;
    if (dialog.exec()){
        fileNames = dialog.selectedFiles();
        QFile f (fileNames[0]);
        rloader->LoadFromFile(&f);
        emit recipeLoaded(rloader->GetRecipe());
    }
}

void MainWindow::closeSlot() {
    emit closeApp();
}
