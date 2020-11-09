#ifndef HELPDIALOG_H
#define HELPDIALOG_H

#include <QDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPainter>
#include <QPixmap>
#include <QBitmap>

/**
 *  La class HelpDialog. Dialogue qui affiche la fenetre "a propros" de l'application.
 */
class HelpDialog : public QDialog
{
    Q_OBJECT

    private:
        QLabel* infoLabel; /**< QLabel*. Label d'informations sur le projet. */
        QLabel* jeremyTextLabel; /**< QLabel*. Label de conseil de cuisine de Jérémy. */
        QLabel* dylanTextLabel; /**< QLabel*. Label de conseil de cuisine de Dylan. */

    public:
        /**
         * Constructeur de la class HelpDialog.
         * Initialise le dialog et les différents widgets qui compose cette classe.
         * @param parent Un QWidget* correspondant au Widget parent
         */
        explicit HelpDialog(QWidget *parent = nullptr);

    public slots:
        /**
         * Slot qui actualise la langue des textes du dialogue.
         */
        void UpdateLang();

};

#endif // HELPDIALOG_H
