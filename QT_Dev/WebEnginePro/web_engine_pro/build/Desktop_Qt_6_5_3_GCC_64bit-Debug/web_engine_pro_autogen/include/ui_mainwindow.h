/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *backButton;
    QToolButton *forwardButton;
    QToolButton *refreshButton;
    QLineEdit *lineEdit;
    QToolButton *searchButton;
    QVBoxLayout *webContainer;
    QSpacerItem *verticalSpacer;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(988, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        backButton = new QToolButton(centralwidget);
        backButton->setObjectName("backButton");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/left-arrow.png"), QSize(), QIcon::Normal, QIcon::Off);
        backButton->setIcon(icon);
        backButton->setIconSize(QSize(32, 32));

        horizontalLayout_2->addWidget(backButton);

        forwardButton = new QToolButton(centralwidget);
        forwardButton->setObjectName("forwardButton");
        forwardButton->setStyleSheet(QString::fromUtf8("image: url(:/images/left-arrow.png);"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/right-arrow.png"), QSize(), QIcon::Normal, QIcon::Off);
        forwardButton->setIcon(icon1);
        forwardButton->setIconSize(QSize(32, 32));

        horizontalLayout_2->addWidget(forwardButton);

        refreshButton = new QToolButton(centralwidget);
        refreshButton->setObjectName("refreshButton");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/refresh.png"), QSize(), QIcon::Normal, QIcon::Off);
        refreshButton->setIcon(icon2);
        refreshButton->setIconSize(QSize(32, 32));

        horizontalLayout_2->addWidget(refreshButton);

        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");

        horizontalLayout_2->addWidget(lineEdit);

        searchButton = new QToolButton(centralwidget);
        searchButton->setObjectName("searchButton");
        QIcon icon3;
        QString iconThemeName = QString::fromUtf8("edit-find-replace");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon3 = QIcon::fromTheme(iconThemeName);
        } else {
            icon3.addFile(QString::fromUtf8(":/images/searchM.png"), QSize(), QIcon::Normal, QIcon::Off);
        }
        searchButton->setIcon(icon3);
        searchButton->setIconSize(QSize(32, 32));

        horizontalLayout_2->addWidget(searchButton);


        verticalLayout_2->addLayout(horizontalLayout_2);

        webContainer = new QVBoxLayout();
        webContainer->setObjectName("webContainer");
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        webContainer->addItem(verticalSpacer);


        verticalLayout_2->addLayout(webContainer);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 988, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        backButton->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        forwardButton->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        refreshButton->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        searchButton->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
