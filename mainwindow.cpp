#include "mainwindow.h"

MainWindow::MainWindow(QApplication * _app, QWidget *parent)
    :  QMainWindow(parent) {

    app = _app;

    setWindowTitle("Squirrel Recipe");
    setAcceptDrops(true);

    setMinimumWidth(500);
    setMinimumHeight(650);

    dialog = new QFileDialog(this);
    helpdialog = new HelpDialog(this);

    rloader = new RecipeLoader();
    rInfo = new RecipeInfo(this);

    SetupFileMenu();
    SetupLangMenu();
    SetupHelpMenu();

    setCentralWidget(rInfo);

    UpdateLang();

    connect(this, SIGNAL(recipeLoaded(Recipe*)), rInfo, SLOT(LoadRecipe(Recipe*)));
    connect(this, SIGNAL(refreshLang()), rInfo, SLOT(UpdateLang()));
    connect(this, SIGNAL(refreshLang()), this, SLOT(UpdateLang()));
    connect(this, SIGNAL(refreshLang()), helpdialog, SLOT(UpdateLang()));
}

MainWindow::~MainWindow() {

}

void MainWindow::SetupFileMenu() {
    fileMenu = new QMenu("", this);
    menuBar()->addMenu(fileMenu);

    fileMenu->addAction("", this, SLOT(LoadRecipe()), QKeySequence::New);
    fileMenu->addAction("", this, SLOT(CloseSlot()), QKeySequence::Close);
}

void MainWindow::SetupLangMenu() {
    langMenu = new QMenu("", this);
    menuBar()->addMenu(langMenu);

    langMenu->addAction(QIcon(QPixmap(":/images/flag_fr.png")), "", this, SLOT(ChangeLangFr()));
    langMenu->addAction(QIcon(QPixmap(":/images/flag_en.png")), "", this, SLOT(ChangeLangEn()));
}

void MainWindow::SetupHelpMenu() {
    helpMenu = new QMenu("", this);
    menuBar()->addMenu(helpMenu);

    helpMenu->addAction("", this, SLOT(OpenHelp()), QKeySequence::HelpContents);
}

void MainWindow::UpdateLang() {
    langMenu->setTitle(tr("&Langue"));
    langMenu->actions()[0]->setText(tr("&Français"));
    langMenu->actions()[1]->setText(tr("&Anglais"));

    fileMenu->setTitle(tr("&Fichier"));
    fileMenu->actions()[0]->setText(tr("&Charger une recette"));
    fileMenu->actions()[1]->setText(tr("&Quitter"));

    helpMenu->setTitle(tr("&Aide"));
    helpMenu->actions()[0]->setText(tr("&A propos"));
}

void MainWindow::ChangeLangEn() {
    ChangeLang("en");
}

void MainWindow::ChangeLangFr() {
    ChangeLang("fr");
}

void MainWindow::ChangeLang(QString lang) {
    app->removeTranslator(&translator);
    QString fileName(":/langs/lang_" + lang + ".qm");
    translator.load(fileName);
    app->installTranslator(&translator);
    emit refreshLang();
}

void MainWindow::LoadRecipe() {
    dialog->setWindowTitle(tr("Charger une recette"));
    dialog->setFileMode(QFileDialog::AnyFile);
    dialog->setNameFilter(tr("Fichier JSON (*.json)"));
    dialog->setViewMode(QFileDialog::Detail);

    QStringList fileNames;
    if (dialog->exec()){
        fileNames = dialog->selectedFiles();
        LoadFile(fileNames[0]);
    }
}

void MainWindow::CloseSlot() {
    emit closeApp();
}

void MainWindow::dropEvent(QDropEvent *event) {
    if(event->mimeData()->hasUrls()) {
        LoadFile(event->mimeData()->urls().at(0).toLocalFile());
    }
}

void MainWindow::dragEnterEvent(QDragEnterEvent* event)
{
    event->acceptProposedAction();
}

void MainWindow::LoadFile(const QString &path) {
    QFile f(path);
    try{
        rloader->LoadFromFile(&f);
        emit recipeLoaded(rloader->GetRecipe());
    }catch(std::runtime_error& e) {
        QMessageBox::critical(0, tr("Erreur"), e.what());
    }
}

void MainWindow::OpenHelp() {
    helpdialog->show();
}
