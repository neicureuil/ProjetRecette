#include "recipetab.h"
#include <QBitmap>

RecipeTab::RecipeTab(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout * mainLayout = new QVBoxLayout();
    mainLayout->setAlignment(Qt::AlignTop);

    //Categorie
    QHBoxLayout * categorieLayout = new QHBoxLayout();

    categoryLabelTitle = new QLabel();
    categoryLabel= new QLabel();
    categorieLayout->addWidget(categoryLabelTitle);
    categorieLayout->addWidget(categoryLabel);

    categorieLayout->setAlignment(Qt::AlignLeft);

    mainLayout->addLayout(categorieLayout);

    mainLayout->addSpacing(10);

    // Nom recette

    nameLabel= new QLabel("Nom de la recette");
    mainLayout->addWidget(nameLabel);
    mainLayout->setAlignment(nameLabel, Qt::AlignCenter);
    nameLabel->setStyleSheet("border-bottom-width: 1px; border-bottom-style: solid; border-radius: 0px; font-weight: bold;");

    mainLayout->addSpacing(10);

    // Image

    imageLabel = new QLabel();
    mainLayout->addWidget(imageLabel);
    mainLayout->setAlignment(imageLabel, Qt::AlignCenter);

    mainLayout->addSpacing(20);

    // Description

    descLabelTitle= new QLabel();
    mainLayout->addWidget(descLabelTitle);
    mainLayout->setAlignment(descLabelTitle, Qt::AlignLeft);
    descLabelTitle->setStyleSheet("border-bottom-width: 1px; border-bottom-style: solid; border-radius: 0px;");

    descLabel= new QLabel();
    descLabel->setWordWrap(true);
    mainLayout->addWidget(descLabel);

    mainLayout->addSpacing(10);

    // TIMES

    prepTimeLabelTitle = new QLabel();
    prepTimeLabel= new QLabel("0mins");
    CreateHField(mainLayout, prepTimeLabelTitle, prepTimeLabel);

    cookTimeLabelTitle = new QLabel();
    cookTimeLabel= new QLabel("0mins");
    CreateHField(mainLayout, cookTimeLabelTitle, cookTimeLabel);

    totalTimeLabelTitle = new QLabel();
    totalTimeLabel= new QLabel("0mins");
    CreateHField(mainLayout, totalTimeLabelTitle, totalTimeLabel);

    mainLayout->addSpacing(10);

    // YIELD

    yieldLabelTitle = new QLabel();
    yieldLabel= new QLabel("0");
    CreateHField(mainLayout, yieldLabelTitle, yieldLabel);

    mainLayout->addSpacing(10);

    // KEYWORDS

    kwordsLabelTitle = new QLabel();
    kwordsLabel= new QLabel("recette");
    kwordsLabel->setWordWrap(true);

    mainLayout->addWidget(kwordsLabelTitle);
    mainLayout->setAlignment(kwordsLabelTitle, Qt::AlignLeft);
    kwordsLabelTitle->setStyleSheet("border-bottom-width: 1px; border-bottom-style: solid; border-radius: 0px;");
    mainLayout->addWidget(kwordsLabel);

    // URL

    urllabel= new QLabel();
    urllabel->setTextFormat(Qt::RichText);
    urllabel->setText("<a href='https://www.google.fr' >Lien de la recette</a>");
    urllabel->setTextInteractionFlags(Qt::TextBrowserInteraction);
    urllabel->setOpenExternalLinks(true);
    mainLayout->addWidget(urllabel);
    mainLayout->setAlignment(urllabel, Qt::AlignLeft);


    setLayout(mainLayout);

    UpdateLang();
}

void RecipeTab::UpdateLang() {
    categoryLabelTitle->setText(tr("Catégorie") + ": ");
    descLabelTitle->setText(tr("Description de la recette") + ": ");
    prepTimeLabelTitle->setText(tr("Temps de préparation") + ": ");
    cookTimeLabelTitle->setText(tr("Temps de cuisson") + ": ");
    totalTimeLabelTitle->setText(tr("Temps total") + ": ");
    yieldLabelTitle->setText(tr("Nombre de parts") + ": ");
    kwordsLabelTitle->setText(tr("Mots clés") + ": ");
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
        connect(nam, SIGNAL(finished(QNetworkReply*)), this, SLOT(UpdateImage(QNetworkReply*)));

        const QUrl url = QUrl(urls);
        QNetworkRequest request(url);
        nam->get(request);
    }else {
        imageLabel->setHidden(true);
    }
}

void RecipeTab::UpdateImage(QNetworkReply *reply) {
    //Recuperation des données de l'image
    pixmap.loadFromData(reply->readAll());
    pixmap = pixmap.scaled(350,350,Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

    //Rendre l'image arrondie sur les bords
    QBitmap map(350,350);
    map.fill(Qt::color0);

    QPainter painter( &map );
    painter.setPen( Qt::transparent );
    painter.setBrush(Qt::color1);
    painter.drawRoundRect( 0, 0, 350, 350,8,8);
    pixmap.setMask(map);

    //Assigner l'image au lable correspondant
    imageLabel->setHidden(false);
    imageLabel->setPixmap(pixmap);
}

void RecipeTab::UpdateUI(Recipe* r) {
    if(r != nullptr) {

        LoadImage(r->getImage());

        nameLabel->setText(r->getName());
        descLabel->setText(r->getDesc());
        categoryLabel->setText(r->getCategory());

        urllabel->setText("<a href='"+ r->getUrl() +"' >"+tr("Lien de la recette")+"</a>");
        urllabel->setHidden(r->getUrl() == "" ? true : false);

        prepTimeLabel->setText(r->getPrepTime());
        cookTimeLabel->setText(r->getCookTime());
        totalTimeLabel->setText(r->getTotalTime());

        yieldLabel->setText(QString::number(r->getYield()));

        kwordsLabel->setText(r->getKeywords());
    }
}
