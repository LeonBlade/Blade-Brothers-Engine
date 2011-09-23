/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Fri Sep 23 16:23:27 2011
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew_Map;
    QAction *actionOpen_Map;
    QAction *actionSave_Map;
    QAction *actionSave_Map_As;
    QAction *actionClose_Map;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QWidget *widget;
    QTabWidget *tabWidget;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(811, 533);
        MainWindow->setDocumentMode(false);
        MainWindow->setUnifiedTitleAndToolBarOnMac(true);
        actionNew_Map = new QAction(MainWindow);
        actionNew_Map->setObjectName(QString::fromUtf8("actionNew_Map"));
        actionOpen_Map = new QAction(MainWindow);
        actionOpen_Map->setObjectName(QString::fromUtf8("actionOpen_Map"));
        actionSave_Map = new QAction(MainWindow);
        actionSave_Map->setObjectName(QString::fromUtf8("actionSave_Map"));
        actionSave_Map_As = new QAction(MainWindow);
        actionSave_Map_As->setObjectName(QString::fromUtf8("actionSave_Map_As"));
        actionClose_Map = new QAction(MainWindow);
        actionClose_Map->setObjectName(QString::fromUtf8("actionClose_Map"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        widget->setMinimumSize(QSize(256, 0));

        horizontalLayout->addWidget(widget);

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setUsesScrollButtons(true);
        tabWidget->setDocumentMode(true);
        tabWidget->setTabsClosable(true);
        tabWidget->setMovable(true);

        horizontalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 811, 22));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuFile->addAction(actionNew_Map);
        menuFile->addSeparator();
        menuFile->addAction(actionOpen_Map);
        menuFile->addSeparator();
        menuFile->addAction(actionSave_Map);
        menuFile->addAction(actionSave_Map_As);
        menuFile->addSeparator();
        menuFile->addAction(actionClose_Map);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Toolkit", 0, QApplication::UnicodeUTF8));
        actionNew_Map->setText(QApplication::translate("MainWindow", "New Map", 0, QApplication::UnicodeUTF8));
        actionNew_Map->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", 0, QApplication::UnicodeUTF8));
        actionOpen_Map->setText(QApplication::translate("MainWindow", "Open Map", 0, QApplication::UnicodeUTF8));
        actionSave_Map->setText(QApplication::translate("MainWindow", "Save Map", 0, QApplication::UnicodeUTF8));
        actionSave_Map_As->setText(QApplication::translate("MainWindow", "Save Map As...", 0, QApplication::UnicodeUTF8));
        actionClose_Map->setText(QApplication::translate("MainWindow", "Close Map", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
