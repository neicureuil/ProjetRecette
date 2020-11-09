#ifndef STEPSDIALOG_H
#define STEPSDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QComboBox>
#include <QPushButton>
#include <QStateMachine>
#include <QString>
#include <QStringList>
#include <QVector>
#include <QString>
#include <QScrollArea>
#include <QMovie>

/**
 *  La class StepsDialog. Dialogue qui gère l'affichage des étapes d'une recette.
 */
class StepsDialog : public QDialog
{
    Q_OBJECT

    private:
        QStateMachine machine; /**< QStateMachine. Machine a état qui gère la logique de parcours des étapes de la recette. */
        QComboBox * choicebox; /**< QComboBox*. Menu déroulant permertant l'acces a une étape spécifique de la recette. */
        QLabel * steplabel; /**< QLabel*. Label qui affiche le texte de l'étape courrante de la recette. */
        QLabel * stepNumberLabel; /**< QLabel*. Label qui affiche un compteur d'étape. C'est a dire la progression (exemple 5/8). */
        QPushButton * previousbtn; /**< QPushButton*. Button "precedent". Demande l'étape précédente. */
        QPushButton * nextbtn; /**< QPushButton*. Button "suivant". Demande l'étape suivante. */
        QMovie * endGif; /**< QMovie*. Contient les données du GIF qui s'affiche a la progression. */
        QStringList steps; /**< QStringList. Liste des différentes étapes de la recette a afficher. */
        int current; /**< int. Compteur qui contient l'étape courante. */

        /**
         * Fonction qui créer et initialise la machine a état.
         * @see machine
         */
        void CreateMachine();
        /**
         * Fonction qui reset les différents boutons du dialogue.
         */
        void ResetBtn();

    public:
        /**
         * Constructeur de la class StepsDialog.
         * Initialise le dialog et les différents widgets qui compose cette classe.
         * Appel la fonction d'initialisation de la StateMachine.
         * @param parent Un QWidget* correspondant au Widget parent
         */
        explicit StepsDialog(QWidget *parent = nullptr);

    signals:
        /**
         * Signal emit lors de la fin d'un changement d'étape.
         */
        void endChangeInstruction();
        /**
         * Signal emit lors du retours a l'état initial de la StateMachine.
         */
        void goToStartState();
        /**
         * Signal emit lors de l'arrivé a l'état final de la StateMachine.
         */
        void goToEndState();


    public slots:
        /**
         * Slot qui actualise la langue des textes du widget.
         */
        void UpdateLang();
        /**
         * Slot qui actualise le texte de l'étape en cours, ainsi que le menu déroulant et le label de progression.
         * @see steplabl
         * @see choicebox
         * @see stepNumberLabel
         */
        void UpdateSteps();
        /**
         * Slot appeler a chaque interaction avec le menu déroulant.
         * Change l'étape actuel par celle selectionner.
         * @param i Un int correspondant a l'index de l'étape selectionnée
         */
        void ComboChanged(int i);
        /**
         * Slot qui update l'affichage avec les informations de l'étape suivante.
         */
        void InstructionSuivante();
        /**
         * Slot qui update l'affichage avec les informations de l'étape précédente.
         */
        void InstructionPrecedente();
        /**
         * Slot reset les données de la machine a état et change les étapes par celles passées en paramètre.
         * Appel LoadMachineDatas().
         * @see LoadMachineDatas()
         * @param liste Une const QStringList& correspondant a la liste des étapes de la recette.
         */
        void Init(const QStringList& liste);
        /**
         * Slot qui remplit la combo box a partir de la liste d'étape steps et finit l'initialisation de la machine a état ainsi que de ses données.
         * @see steps
         */
        void LoadMachineDatas();
};

#endif // STEPSDIALOG_H
