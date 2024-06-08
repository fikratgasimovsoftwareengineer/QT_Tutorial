#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtTextToSpeech/QTextToSpeech>
#include <QVector>
#include <QLocale>
#include <QPixmap>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;

}
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

    void showImage(const QString &imagePath);

public slots:

    void speak();
    void setRate(double rate);
    void setPitch(double pitch);
    void setVolume(double volume);
    void voiceSelected(double index);
    void localChanged(const QLocale &locale);

private:
    Ui::MainWindow *ui;
    QTextToSpeech *m_speech;
    QVector<QVoice> m_voices;
    QString imagePath_m;
};
#endif // MAINWINDOW_H
