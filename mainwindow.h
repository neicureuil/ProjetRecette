#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QMenu>
#include <QMenuBar>
#include <QFileDialog>
#include <QMessageBox>
#include <QPixmap>
#include <QTranslator>
#include <QDropEvent>
#include <QMimeData>

#include "recipeinfo.h"
#include "recipeloader.h"
#include "helpdialog.h"

/**
 *  La class MainWindow. La fenetre principale de l'application.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

    private:
        QMenu * fileMenu; /**< QMenu*. Menu "fichier" de l'application. */
        QMenu * langMenu; /**< QMenu*. Menu "langue" de l'application. */
        QMenu * helpMenu; /**< QMenu*. Menu "help" de l'application. */

        QFileDialog* dialog; /**< QFileDialog*. Boite de dialogue qui correspond a la fenetre de selection de fichier pour charger une recette. */
        QApplication *app; /**< QApplication*. Pointeur correspondant a l'application principale (celle créée dans le main. */
        QTranslator translator; /**< QTranslator. Gestionnaire des traductions de l'application. */
        RecipeInfo *rInfo; /**< RecipeInfo*. Pointeur correspondant au widget central de l'application. */
        RecipeLoader *rloader; /**< RecipeLoader*. Chargeur de recette. */
        HelpDialog *helpdialog;  /**< HelpDialog*. Fenetre d'aide (a propos). */
        /**
         * Fonction qui initialise le menu "fichier" dans la barre de menus.
         */
        void SetupFileMenu();
        /**
         * Fonction qui initialise le menu "langue" dans la barre de menus.
         */
        void SetupLangMenu();
        /**
         * Fonction qui initialise le menu "aide" dans la barre de menus.
         */
        void SetupHelpMenu();
        /**
         * Fonction qui gère le changement dynamique le lang de l'application.
         * @param lang un QString correspondant a la langue souhaité (Langues supportées : fr et en)
         */
        void ChangeLang(QString lang);
        /**
         * Fonction qui appel la fonction de chargement d'une recette a partir du chemin d'un fichier.
         * Charge la recette grace au RecipeLoader.
         * En cas d'erreur, ouvre une message box contenant l'erreur.
         * Sinon emet le signal recipeLoaded.
         * @param path Un const QString& correspondant au chemin du fichier de recette.
         * @see rloader
         * @see recipeLoaded(Recipe*)
         */
        void LoadFile(const QString& path);

    public:
        /**
         * Constructeur de la class MainWindow.
         * Initialise la fenetre avec les différents widgets qui la compose ainsi que les menus et le traducteur.
         * @param app Une QApplication* correspondant a l'application principale
         * @param parent Un QWidget* correspondant au Widget parent
         */
        MainWindow(QApplication * app, QWidget *parent = nullptr);
        /**
         * Le destructeur de la class MainWindow.
         */
        ~MainWindow();


    protected:
        /**
         * Fonction hérité de QMainWindow.
         * Autorise de drop de fichier sur la fenetre.
         * @param event Un QDragEnterEvent* correspondant a l'event de dtop de fichiers.
         */
        void dragEnterEvent(QDragEnterEvent *event) override;
        /**
         * Fonction hérité de QMainWindow.
         * Appel le chargement d'une recette a partir d'un fichier glisser sur la fenetre.
         * @param event Un QDragEnterEvent* correspondant a l'event de dtop de fichiers.
         * @see  LoadFile(const QString& path)
         */
        void dropEvent(QDropEvent* event) override;

    public slots:
        /**
         * Slot qui ouvre une fenetre du dialogue pour choisir une recette puis demande son chargement.
         * @see  LoadFile(const QString& path)
         */
        void LoadRecipe();
        /**
         * Slot qui demande la fermeture de l'application en emettant le signal closeApp().
         * @see closeApp()
         */
        void CloseSlot();
        /**
         * Slot qui demande le changement de langue de l'application vers l'anglais.
         * Appel la fonction ChangeLang().
         * @see ChangeLang()
         */
        void ChangeLangEn();
        /**
         * Slot qui demande le changement de langue de l'application vers le francais.
         * Appel la fonction ChangeLang().
         * @see ChangeLang()
         */
        void ChangeLangFr();
        /**
         * Slot met a jours la langue des textes des menus.
         */
        void UpdateLang();
        /**
         * Slot qui ouvre la fenetre d'aide (a propos).
         * @see helpdialog
         */
        void OpenHelp();


    signals:
        /**
         * Signal emis lorsque l'utilisareur demande a fermer l'application.
         */
        void closeApp();
        /**
         * Signal emis lorsque le chargement de la recette est terminé.
         * @param r un Recipe* pointant sur la recette chargée.
         */
        void recipeLoaded(Recipe* r);
        /**
         * Signal emis lorsque un changement de langue a été effectué.
         */
        void refreshLang();
};
#endif // MAINWINDOW_H
