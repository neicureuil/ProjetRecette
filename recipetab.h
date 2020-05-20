#ifndef RECIPETAB_H
#define RECIPETAB_H
#include <QLabel>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>

class RecipeTab : public QWidget
{
    Q_OBJECT
public:
    explicit RecipeTab(QWidget *parent = nullptr);

private:
    QLabel * categorylabel;
    QLabel * namelabel;
    QLabel * desclabel;
    QLabel * desctxtlabel;
    QLabel * urllabel;
    QLabel * kwordslabel;
    QLabel * preptimelabel;
    QLabel * cooktimelabel;
    QLabel * totaltimelabel;
    QLabel * yieldlabel;
    QLabel * toolslabel;
signals:

};

#endif // RECIPETAB_H
