/********************************************************************************
** Form generated from reading UI file 'voiceidentification.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VOICEIDENTIFICATION_H
#define UI_VOICEIDENTIFICATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VoiceIdentificationClass
{
public:
    QWidget *centralWidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *startRecordButton;
    QPushButton *stopRecordButton;
    QPushButton *playButton;
    QPushButton *pauseButton;
    QSlider *timerSlider;
    QTimeEdit *timeEdit;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *VoiceIdentificationClass)
    {
        if (VoiceIdentificationClass->objectName().isEmpty())
            VoiceIdentificationClass->setObjectName(QStringLiteral("VoiceIdentificationClass"));
        VoiceIdentificationClass->resize(539, 400);
        centralWidget = new QWidget(VoiceIdentificationClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(20, 30, 501, 51));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        startRecordButton = new QPushButton(horizontalLayoutWidget);
        startRecordButton->setObjectName(QStringLiteral("startRecordButton"));

        horizontalLayout->addWidget(startRecordButton);

        stopRecordButton = new QPushButton(horizontalLayoutWidget);
        stopRecordButton->setObjectName(QStringLiteral("stopRecordButton"));

        horizontalLayout->addWidget(stopRecordButton);

        playButton = new QPushButton(horizontalLayoutWidget);
        playButton->setObjectName(QStringLiteral("playButton"));

        horizontalLayout->addWidget(playButton);

        pauseButton = new QPushButton(horizontalLayoutWidget);
        pauseButton->setObjectName(QStringLiteral("pauseButton"));

        horizontalLayout->addWidget(pauseButton);

        timerSlider = new QSlider(centralWidget);
        timerSlider->setObjectName(QStringLiteral("timerSlider"));
        timerSlider->setGeometry(QRect(20, 110, 501, 22));
        timerSlider->setOrientation(Qt::Horizontal);
        timeEdit = new QTimeEdit(centralWidget);
        timeEdit->setObjectName(QStringLiteral("timeEdit"));
        timeEdit->setGeometry(QRect(190, 150, 118, 22));
        timeEdit->setFrame(false);
        timeEdit->setAlignment(Qt::AlignCenter);
        timeEdit->setButtonSymbols(QAbstractSpinBox::NoButtons);
        timeEdit->setCurrentSection(QDateTimeEdit::MinuteSection);
        VoiceIdentificationClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(VoiceIdentificationClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 539, 21));
        VoiceIdentificationClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(VoiceIdentificationClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        VoiceIdentificationClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(VoiceIdentificationClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        VoiceIdentificationClass->setStatusBar(statusBar);

        retranslateUi(VoiceIdentificationClass);

        startRecordButton->setDefault(false);


        QMetaObject::connectSlotsByName(VoiceIdentificationClass);
    } // setupUi

    void retranslateUi(QMainWindow *VoiceIdentificationClass)
    {
        VoiceIdentificationClass->setWindowTitle(QApplication::translate("VoiceIdentificationClass", "VoiceIdentification", Q_NULLPTR));
        startRecordButton->setText(QApplication::translate("VoiceIdentificationClass", "\320\235\320\260\321\207\320\260\321\202\321\214 \320\267\320\260\320\277\320\270\321\201\321\214", Q_NULLPTR));
        stopRecordButton->setText(QApplication::translate("VoiceIdentificationClass", "\320\236\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214 \320\267\320\260\320\277\320\270\321\201\321\214", Q_NULLPTR));
        playButton->setText(QApplication::translate("VoiceIdentificationClass", "\320\222\320\276\321\201\320\277\321\200\320\276\320\270\320\267\320\262\320\265\321\201\321\202\320\270", Q_NULLPTR));
        pauseButton->setText(QApplication::translate("VoiceIdentificationClass", "\320\237\320\260\321\203\320\267\320\260", Q_NULLPTR));
        timeEdit->setDisplayFormat(QApplication::translate("VoiceIdentificationClass", "mm:ss.zz", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class VoiceIdentificationClass: public Ui_VoiceIdentificationClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VOICEIDENTIFICATION_H
