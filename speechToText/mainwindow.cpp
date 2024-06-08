#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow),
    imagePath_m(":/cars/images/bmw.png")

{
    ui->setupUi(this);

    showImage(imagePath_m);

    m_speech = new QTextToSpeech(this);


    connect(ui->speakReady, &QPushButton::clicked,this, &MainWindow::speak);
    connect(ui->volume_2, &QSlider::valueChanged, this,&MainWindow::setVolume);
    connect(ui->rate, &QSlider::valueChanged, this, &MainWindow::setRate);
    connect(ui->pitch, &QSlider::valueChanged, this, &MainWindow::setPitch);

    // Connect localeChanged slot to QTextToSpeech's localeChanged signal

    connect(m_speech, &QTextToSpeech::localeChanged, this, &MainWindow::localChanged);


    // Initialize voice combo box
    localChanged(QLocale::system());

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::speak(){
    m_speech->say(ui->enterText->toPlainText());
    qDebug() << ui->enterText->toPlainText();
}
void MainWindow::setVolume(double volume){
    m_speech->setVolume(volume/100.0);
    qDebug() << volume;
}
void MainWindow::setRate(double rate){

    m_speech->setRate(rate/2.0);
    qDebug() << rate;
}
void MainWindow::setPitch(double pitch){
    m_speech->setPitch(pitch /10.0);
    qDebug() << pitch;
}


void MainWindow::voiceSelected(double index){
    m_speech->setVoice(m_voices.at(index));
    qDebug() << "current index : " << index;
}

void MainWindow::localChanged(const QLocale &locale)
{
    disconnect(ui->voice, &QComboBox::currentIndexChanged, this, &MainWindow::voiceSelected);

    m_voices = m_speech->availableVoices();
    ui->voice->clear();

    // name of voice
    QString currentTalkingPerson = m_speech->voice().name();


    int currentIndex = -1;

    for (int i=0; i<m_voices.size(); ++i){
        QVoice &voice = m_voices[i];

        QString voiceDescription = QString("%1 - %2 - %3").arg(voice.name(),
                                            QVoice::genderName(voice.gender()),
                                            QVoice::ageName(voice.age()));

        ui->voice->addItem(voiceDescription);

        if (voice.name()==currentTalkingPerson) {
            currentIndex = i;
        }
    }

    if (currentIndex!=-1){
        ui->voice->setCurrentIndex(currentIndex);
    }

    connect(ui->voice, &QComboBox::currentIndexChanged, this, &MainWindow::voiceSelected);




}

void MainWindow::showImage(const QString &imagePath){


    QPixmap pixmap(imagePath);


    /*ui->imageLabel->setPixmap(pixmap.scaled(ui->imageLabel->width(),
                                            ui->imageLabel->height(), Qt::KeepAspectRatio));*/

    ui->imageLabel->setPixmap(pixmap.scaled(400,
                                            280, Qt::KeepAspectRatio));

    ui->imageLabel->show();
}




