#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {
   setupFileMenu();


   //loadRecipe();
   setCentralWidget(new RecipeInfo(this));
}

MainWindow::~MainWindow() {

}

void MainWindow::setupFileMenu() {
    QMenu *fileMenu = new QMenu(tr("&Fichier"), this);
    menuBar()->addMenu(fileMenu);

    fileMenu->addAction(tr("&Charger une recette"), this, SLOT(loadRecipe()), QKeySequence::New);
    fileMenu->addAction(tr("&Quitter"), this, SLOT(closeSlot()), QKeySequence::Quit);
}


void MainWindow::loadRecipe() {
    QString fileName = QFileDialog::getOpenFileName(this, tr("Charger une recette"), "", tr("Fichier JSON (*.json)"));
}

void MainWindow::closeSlot() {
    emit closeApp();
}
