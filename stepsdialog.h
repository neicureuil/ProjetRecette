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

class StepsDialog : public QDialog
{
    Q_OBJECT

    private:
        QStateMachine machine;
        QComboBox * choicebox;
        QLabel * steplabel;
        QPushButton * previousbtn;
        QPushButton * nextbtn;
        QStringList steps;
        int current;

    public:
        explicit StepsDialog(QWidget *parent = nullptr);

    signals:
        void endChangeInstruction();


    public slots:
        void ComboChanged(int i);
        void instructionSuivante();
        void instructionPrecedente();
        void Init(const QStringList& liste);
};

#endif // STEPSDIALOG_H
