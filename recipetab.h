#ifndef RECIPETAB_H
#define RECIPETAB_H
#include <QLabel>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QImage>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>

#include <recipe.h>

class RecipeTab : public QWidget
{
    Q_OBJECT
public:
    explicit RecipeTab(QWidget *parent = nullptr);
    void LoadImage(QString);

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
    QLabel * imagelabel;

public slots:
    void updateUI(Recipe* r);
    void updateImage(QNetworkReply*);

signals:

};

#endif // RECIPETAB_H
