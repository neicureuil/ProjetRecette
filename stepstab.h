#ifndef STEPSTAB_H
#define STEPSTAB_H
#include <QLabel>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QComboBox>
#include <QPushButton>

class StepsTab : public QWidget
{
    Q_OBJECT
public:
    explicit StepsTab(QWidget *parent = nullptr);

private:
    QComboBox * choicebox;
    QLabel * steplabel;
    QPushButton * previousbtn;
    QPushButton * nextbtn;
signals:

};

#endif // STEPSTAB_H