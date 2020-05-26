#include "recipetab.h"

RecipeTab::RecipeTab(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout * mainLayout = new QVBoxLayout();
    mainLayout->setAlignment(Qt::AlignTop);

    //Categorie

    categorylabel= new QLabel("Catégorie: Ipsum");
    mainLayout->addWidget(categorylabel);
    mainLayout->setAlignment(categorylabel, Qt::AlignRight);

    mainLayout->addSpacing(10);

    // Nom recette

    namelabel= new QLabel("Nom de la recette");
    mainLayout->addWidget(namelabel);
    mainLayout->setAlignment(namelabel, Qt::AlignCenter);
    namelabel->setStyleSheet("border-bottom-width: 1px; border-bottom-style: solid; border-radius: 0px; font-weight: bold;");

    mainLayout->addSpacing(10);

    // Image

    imagelabel = new QLabel("");
    mainLayout->addWidget(imagelabel);
    mainLayout->setAlignment(imagelabel, Qt::AlignCenter);

    mainLayout->addSpacing(20);

    // Description

    QLabel * descTitleLabel= new QLabel("Description de la recette:");
    mainLayout->addWidget(descTitleLabel);
    mainLayout->setAlignment(descTitleLabel, Qt::AlignLeft);
    descTitleLabel->setStyleSheet("border-bottom-width: 1px; border-bottom-style: solid; border-radius: 0px;");

    desclabel= new QLabel("Lorem Ipsum Ta kompri avec du lait et des cookies pour mon plaisir personnel");
    desclabel->setWordWrap(true);
    mainLayout->addWidget(desclabel);

    mainLayout->addSpacing(10);

    // TIMES AND YIELDS

    QLabel * prepTimeTitleLabel = new QLabel("Temps de préparation:");
    preptimelabel= new QLabel("0mins");
    CreateHField(mainLayout, prepTimeTitleLabel, preptimelabel);

    QLabel * cookTimeTitleLabel = new QLabel("Temps de cuisson:");
    cooktimelabel= new QLabel("0mins");
    CreateHField(mainLayout, cookTimeTitleLabel, cooktimelabel);

    QLabel * totalTimeTitleLabel = new QLabel("Temps total:");
    totaltimelabel= new QLabel("0mins");
    CreateHField(mainLayout, totalTimeTitleLabel, totaltimelabel);

    mainLayout->addSpacing(10);

    QLabel * yieldTitleLabel = new QLabel("Nombre de parts:");
    yieldlabel= new QLabel("0");
    CreateHField(mainLayout, yieldTitleLabel, yieldlabel);

    mainLayout->addSpacing(10);

    // KEYWORDS

    QLabel * kwordsTitleLabel = new QLabel("Mots clés:");
    kwordslabel= new QLabel("recette");
    kwordslabel->setWordWrap(true);

    mainLayout->addWidget(kwordsTitleLabel);
    mainLayout->setAlignment(kwordsTitleLabel, Qt::AlignLeft);
    kwordsTitleLabel->setStyleSheet("border-bottom-width: 1px; border-bottom-style: solid; border-radius: 0px;");
    mainLayout->addWidget(kwordslabel);

    //URL

    urllabel= new QLabel();
    urllabel->setTextFormat(Qt::RichText);
    urllabel->setText("<a href='https://www.google.fr' >Lien de la recette</a>");
    urllabel->setTextInteractionFlags(Qt::TextBrowserInteraction);
    urllabel->setOpenExternalLinks(true);
    mainLayout->addWidget(urllabel);
    mainLayout->setAlignment(urllabel, Qt::AlignLeft);


    setLayout(mainLayout);
}


void RecipeTab::CreateHField(QBoxLayout *container, QWidget *w1, QWidget *w2) {
    QHBoxLayout *layout = new QHBoxLayout();
    layout->setAlignment(Qt::AlignLeft);
    layout->addWidget(w1);
    layout->addWidget(w2);
    container->addLayout(layout);
}

void RecipeTab::LoadImage(QString urls) {
    if(urls != "") {
        QNetworkAccessManager *nam = new QNetworkAccessManager(this);
        connect(nam, SIGNAL(finished(QNetworkReply*)), this, SLOT(updateImage(QNetworkReply*)));

        const QUrl url = QUrl(urls);
        QNetworkRequest request(url);
        nam->get(request);
    }else {
        imagelabel->setHidden(true);
    }
}

void RecipeTab::updateImage(QNetworkReply *reply) {
    pixmap.loadFromData(reply->readAll());
    imagelabel->setHidden(false);
    imagelabel->setPixmap(pixmap);
    imagelabel->setPixmap(pixmap.scaled(350,350,Qt::KeepAspectRatio));
}

void RecipeTab::updateUI(Recipe* r) {
    if(r != nullptr) {

        LoadImage(r->getImage());

        namelabel->setText(r->getName());
        desclabel->setText(r->getDesc());
        categorylabel->setText("Catégorie: " + r->getCategory());

        urllabel->setText("<a href='"+ r->getUrl() +"' >Lien de la recette</a>");
        urllabel->setHidden(r->getUrl() == "" ? true : false);

        preptimelabel->setText(r->getPrepTime());
        cooktimelabel->setText(r->getCookTime());
        totaltimelabel->setText(r->getTotalTime());

        yieldlabel->setText(QString::number(r->getYield()));

        kwordslabel->setText(r->getKeywords());
    }
}
