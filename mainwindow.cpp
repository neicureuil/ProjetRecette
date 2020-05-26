#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {


    rloader = new RecipeLoader();
    rInfo = new RecipeInfo(this);

    setupFileMenu();
    setupLangMenu();
    setupHelpMenu();

    setCentralWidget(rInfo);

    connect(this, SIGNAL(recipeLoaded(Recipe*)), rInfo, SLOT(LoadRecipe(Recipe*)));
}

MainWindow::~MainWindow() {

}

void MainWindow::setupFileMenu() {
    QMenu *fileMenu = new QMenu(tr("&Fichier"), this);
    menuBar()->addMenu(fileMenu);

    fileMenu->addAction(tr("&Charger une recette"), this, SLOT(loadRecipe()), QKeySequence::New);
    fileMenu->addAction(tr("&Quitter"), this, SLOT(closeSlot()), QKeySequence::Close);
}

void MainWindow::setupLangMenu() {
    QMenu *langMenu = new QMenu(tr("&Langue"), this);
    menuBar()->addMenu(langMenu);

    langMenu->addAction(QIcon(QPixmap(":/images/flag_fr.png")), tr("&Français"), this, SLOT(nullptr));
    langMenu->addAction(QIcon(QPixmap(":/images/flag_en.png")), tr("&Anglais"), this, SLOT(nullptr));
}

void MainWindow::setupHelpMenu() {

}


void MainWindow::loadRecipe() {
    // Pour amelorier => Creer une class pour le dialog et la stocker en donnée membre
    QFileDialog dialog(this);
    dialog.setWindowTitle("Charger une recette");
    dialog.setFileMode(QFileDialog::AnyFile);
    dialog.setNameFilter(tr("Fichier JSON (*.json)"));
    dialog.setViewMode(QFileDialog::Detail);

    QStringList fileNames;
    if (dialog.exec()){
        fileNames = dialog.selectedFiles();
        QFile f (fileNames[0]);
        try{
            rloader->LoadFromFile(&f);
            emit recipeLoaded(rloader->GetRecipe());
        }catch(std::runtime_error& e) {
            QMessageBox::critical(0, "Erreur", e.what());
        }
    }
}

void MainWindow::closeSlot() {
    emit closeApp();
}
