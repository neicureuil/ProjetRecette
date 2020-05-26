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


class StepsDialog : public QDialog
{
    Q_OBJECT

    private:
        QStateMachine * machine;
        QComboBox * choicebox;
        QLabel * steplabel;
        QPushButton * previousbtn;
        QPushButton * nextbtn;

    public:
        explicit StepsDialog(QWidget *parent = nullptr);

    signals:

};

#endif // STEPSDIALOG_H
