/********************************************************************************
** Form generated from reading UI file 'ourtempest.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OURTEMPEST_H
#define UI_OURTEMPEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OurTempestClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *OurTempestClass)
    {
        if (OurTempestClass->objectName().isEmpty())
            OurTempestClass->setObjectName(QStringLiteral("OurTempestClass"));
        OurTempestClass->resize(600, 400);
        menuBar = new QMenuBar(OurTempestClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        OurTempestClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(OurTempestClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        OurTempestClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(OurTempestClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        OurTempestClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(OurTempestClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        OurTempestClass->setStatusBar(statusBar);

        retranslateUi(OurTempestClass);

        QMetaObject::connectSlotsByName(OurTempestClass);
    } // setupUi

    void retranslateUi(QMainWindow *OurTempestClass)
    {
        OurTempestClass->setWindowTitle(QApplication::translate("OurTempestClass", "OurTempest", 0));
    } // retranslateUi

};

namespace Ui {
    class OurTempestClass: public Ui_OurTempestClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OURTEMPEST_H
