/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>
#include "renderwidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QTextEdit *textEdit;
    RenderWidget *renderWidget;
    QCheckBox *adjustByHand;
    QTabWidget *tabWidget;
    QWidget *meta;
    QPushButton *metaButton;
    QLineEdit *titleLine;
    QLabel *titleLabel;
    QLabel *composerLabel;
    QLineEdit *composerLine;
    QLabel *authorLabel1;
    QLabel *abailabilityLabel;
    QLineEdit *authorLine1;
    QLabel *commentLabel;
    QTextEdit *availabilityText;
    QTextEdit *commentsText;
    QLineEdit *languageLine;
    QLabel *languageLabel;
    QWidget *sources;
    QLineEdit *sourceIDLine;
    QLineEdit *sourceAuthorLine;
    QLineEdit *sourceTitleLine;
    QLineEdit *sourcePubStatusLine;
    QLabel *sourceIDLabel;
    QLabel *sourceAuthorLabel;
    QLabel *sourceTitleLabel;
    QLabel *sourcePubStatusLabel;
    QLineEdit *sourceMediumLine;
    QLineEdit *sourceXLine;
    QLabel *sourceMediumLabel;
    QLineEdit *sourceYLine;
    QLineEdit *sourceUnitLine;
    QLabel *sourceDimensionLabel;
    QLabel *label_13;
    QLabel *sourceUnitLabel;
    QLineEdit *sourceConditionLine;
    QLabel *sourceConditionLabel;
    QLineEdit *sourceExtentLine;
    QLabel *sourceExtentLabel;
    QLabel *sourceHandwritingLabel;
    QTextEdit *sourceStyleText;
    QPushButton *sourceCreateButton;
    QPushButton *sourceAddButton;
    QPushButton *sourceFinishButton;
    QLineEdit *sourcePhysicallocationLine;
    QLineEdit *sourceOwnershipLine;
    QLineEdit *sourceDateLine;
    QLabel *sourceTitleLabel_3;
    QLabel *sourceTitleLabel_4;
    QLabel *sourceTitleLabel_5;
    QWidget *staffTab;
    QLabel *staffIDLabel;
    QLabel *staffLinecountLabel;
    QLabel *staffCleflineLabel;
    QLabel *staffClefshapeLabel;
    QLineEdit *staffIDLine;
    QLineEdit *staffLinecountLine;
    QLineEdit *staffCleflineLine;
    QLineEdit *staffClefshapeLine;
    QPushButton *staffCreateButton;
    QPushButton *staffAddclefButton;
    QPushButton *staffFinishButton;
    QPushButton *staffNewstaffButton;
    QLabel *staffLinecolorLabel;
    QToolButton *staffLinecolorToolbutton;
    QToolButton *staffModeToolbutton;
    QLabel *staffModeLabel;
    QWidget *sylTab;
    QLabel *sylPageLabel;
    QLabel *sylLineLabel;
    QLabel *sylSyllableLLabel;
    QLineEdit *sylPageLine;
    QLineEdit *sylLineLine;
    QLineEdit *sylSyllableLine;
    QTextEdit *sylCommentText;
    QLabel *sylCommentLabel;
    QPushButton *sylCreateButton;
    QPushButton *sylFinishButton;
    QLabel *sylStaffLabel;
    QLabel *sylSourceLabel;
    QToolButton *sylSourceToolbutton;
    QToolButton *sylStaffToolbutton;
    QToolButton *sylTypeToolbutton;
    QLabel *sylTypeLabel;
    QLabel *sylFilenameLabel;
    QLineEdit *sylFilenameLine;
    QPushButton *sylSaveButton;
    QWidget *varTab;
    QLabel *label;
    QLabel *varSourceLabel;
    QToolButton *varPitchToolbutton;
    QTextEdit *varCommentText;
    QToolButton *varOctaveToolbutton;
    QToolButton *varPreviousToolbutton;
    QLabel *varPitchLabel;
    QLabel *varOctaveLabel;
    QLabel *varPreviousLabel;
    QLabel *varConnectionLabel;
    QPushButton *varAddpitchButton;
    QPushButton *varNextButton;
    QToolButton *varConnectionToolbutton;
    QToolButton *varTiltToolbutton;
    QLabel *varTiltLabel;
    QLabel *varCommentLabel;
    QWidget *pitchTab;
    QLabel *pitchPitchLabel;
    QTextEdit *pitchCommentText;
    QLabel *pitchOctaveLabel;
    QLabel *pitchCommentLabel;
    QPushButton *pitchAddButton;
    QPushButton *pitchFinishButton;
    QToolButton *pitchPitchToolbutton;
    QToolButton *pitchOctaveToolbutton;
    QToolButton *pitchPreviousToolbutton;
    QLabel *pitchPreviousLabel;
    QToolButton *pitchConnectionToolbutton;
    QToolButton *pitchTiltToolbutton;
    QLabel *pitchConnectionLabel;
    QLabel *pitchTiltLabel;
    QPushButton *pitchAddVariantButton;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1302, 662);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setEnabled(true);

        gridLayout->addWidget(textEdit, 0, 2, 2, 1);

        renderWidget = new RenderWidget(centralWidget);
        renderWidget->setObjectName(QStringLiteral("renderWidget"));

        gridLayout->addWidget(renderWidget, 2, 2, 1, 1);

        adjustByHand = new QCheckBox(centralWidget);
        adjustByHand->setObjectName(QStringLiteral("adjustByHand"));

        gridLayout->addWidget(adjustByHand, 0, 0, 1, 1);

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        meta = new QWidget();
        meta->setObjectName(QStringLiteral("meta"));
        metaButton = new QPushButton(meta);
        metaButton->setObjectName(QStringLiteral("metaButton"));
        metaButton->setGeometry(QRect(10, 250, 91, 23));
        titleLine = new QLineEdit(meta);
        titleLine->setObjectName(QStringLiteral("titleLine"));
        titleLine->setGeometry(QRect(70, 10, 361, 21));
        titleLabel = new QLabel(meta);
        titleLabel->setObjectName(QStringLiteral("titleLabel"));
        titleLabel->setGeometry(QRect(10, 10, 47, 21));
        composerLabel = new QLabel(meta);
        composerLabel->setObjectName(QStringLiteral("composerLabel"));
        composerLabel->setGeometry(QRect(10, 40, 47, 21));
        composerLine = new QLineEdit(meta);
        composerLine->setObjectName(QStringLiteral("composerLine"));
        composerLine->setGeometry(QRect(70, 40, 361, 21));
        authorLabel1 = new QLabel(meta);
        authorLabel1->setObjectName(QStringLiteral("authorLabel1"));
        authorLabel1->setGeometry(QRect(10, 70, 47, 21));
        abailabilityLabel = new QLabel(meta);
        abailabilityLabel->setObjectName(QStringLiteral("abailabilityLabel"));
        abailabilityLabel->setGeometry(QRect(10, 130, 61, 21));
        authorLine1 = new QLineEdit(meta);
        authorLine1->setObjectName(QStringLiteral("authorLine1"));
        authorLine1->setGeometry(QRect(70, 70, 361, 21));
        commentLabel = new QLabel(meta);
        commentLabel->setObjectName(QStringLiteral("commentLabel"));
        commentLabel->setGeometry(QRect(10, 190, 61, 21));
        availabilityText = new QTextEdit(meta);
        availabilityText->setObjectName(QStringLiteral("availabilityText"));
        availabilityText->setGeometry(QRect(70, 130, 361, 51));
        commentsText = new QTextEdit(meta);
        commentsText->setObjectName(QStringLiteral("commentsText"));
        commentsText->setGeometry(QRect(70, 190, 361, 51));
        languageLine = new QLineEdit(meta);
        languageLine->setObjectName(QStringLiteral("languageLine"));
        languageLine->setGeometry(QRect(70, 100, 361, 20));
        languageLabel = new QLabel(meta);
        languageLabel->setObjectName(QStringLiteral("languageLabel"));
        languageLabel->setGeometry(QRect(10, 100, 47, 21));
        tabWidget->addTab(meta, QString());
        sources = new QWidget();
        sources->setObjectName(QStringLiteral("sources"));
        sourceIDLine = new QLineEdit(sources);
        sourceIDLine->setObjectName(QStringLiteral("sourceIDLine"));
        sourceIDLine->setGeometry(QRect(70, 10, 361, 21));
        sourceAuthorLine = new QLineEdit(sources);
        sourceAuthorLine->setObjectName(QStringLiteral("sourceAuthorLine"));
        sourceAuthorLine->setGeometry(QRect(70, 40, 361, 21));
        sourceTitleLine = new QLineEdit(sources);
        sourceTitleLine->setObjectName(QStringLiteral("sourceTitleLine"));
        sourceTitleLine->setGeometry(QRect(70, 70, 361, 21));
        sourcePubStatusLine = new QLineEdit(sources);
        sourcePubStatusLine->setObjectName(QStringLiteral("sourcePubStatusLine"));
        sourcePubStatusLine->setGeometry(QRect(100, 190, 331, 21));
        sourceIDLabel = new QLabel(sources);
        sourceIDLabel->setObjectName(QStringLiteral("sourceIDLabel"));
        sourceIDLabel->setGeometry(QRect(10, 10, 47, 21));
        sourceAuthorLabel = new QLabel(sources);
        sourceAuthorLabel->setObjectName(QStringLiteral("sourceAuthorLabel"));
        sourceAuthorLabel->setGeometry(QRect(10, 40, 47, 21));
        sourceTitleLabel = new QLabel(sources);
        sourceTitleLabel->setObjectName(QStringLiteral("sourceTitleLabel"));
        sourceTitleLabel->setGeometry(QRect(10, 70, 47, 21));
        sourcePubStatusLabel = new QLabel(sources);
        sourcePubStatusLabel->setObjectName(QStringLiteral("sourcePubStatusLabel"));
        sourcePubStatusLabel->setGeometry(QRect(10, 190, 91, 21));
        sourceMediumLine = new QLineEdit(sources);
        sourceMediumLine->setObjectName(QStringLiteral("sourceMediumLine"));
        sourceMediumLine->setGeometry(QRect(70, 220, 361, 21));
        sourceXLine = new QLineEdit(sources);
        sourceXLine->setObjectName(QStringLiteral("sourceXLine"));
        sourceXLine->setGeometry(QRect(70, 250, 31, 21));
        sourceMediumLabel = new QLabel(sources);
        sourceMediumLabel->setObjectName(QStringLiteral("sourceMediumLabel"));
        sourceMediumLabel->setGeometry(QRect(10, 220, 47, 21));
        sourceYLine = new QLineEdit(sources);
        sourceYLine->setObjectName(QStringLiteral("sourceYLine"));
        sourceYLine->setGeometry(QRect(120, 250, 31, 21));
        sourceUnitLine = new QLineEdit(sources);
        sourceUnitLine->setObjectName(QStringLiteral("sourceUnitLine"));
        sourceUnitLine->setGeometry(QRect(190, 250, 31, 21));
        sourceDimensionLabel = new QLabel(sources);
        sourceDimensionLabel->setObjectName(QStringLiteral("sourceDimensionLabel"));
        sourceDimensionLabel->setGeometry(QRect(10, 250, 47, 21));
        label_13 = new QLabel(sources);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(110, 250, 16, 21));
        sourceUnitLabel = new QLabel(sources);
        sourceUnitLabel->setObjectName(QStringLiteral("sourceUnitLabel"));
        sourceUnitLabel->setGeometry(QRect(160, 250, 47, 21));
        sourceConditionLine = new QLineEdit(sources);
        sourceConditionLine->setObjectName(QStringLiteral("sourceConditionLine"));
        sourceConditionLine->setGeometry(QRect(70, 280, 361, 21));
        sourceConditionLabel = new QLabel(sources);
        sourceConditionLabel->setObjectName(QStringLiteral("sourceConditionLabel"));
        sourceConditionLabel->setGeometry(QRect(10, 280, 47, 21));
        sourceExtentLine = new QLineEdit(sources);
        sourceExtentLine->setObjectName(QStringLiteral("sourceExtentLine"));
        sourceExtentLine->setGeometry(QRect(70, 310, 361, 21));
        sourceExtentLabel = new QLabel(sources);
        sourceExtentLabel->setObjectName(QStringLiteral("sourceExtentLabel"));
        sourceExtentLabel->setGeometry(QRect(10, 310, 47, 21));
        sourceHandwritingLabel = new QLabel(sources);
        sourceHandwritingLabel->setObjectName(QStringLiteral("sourceHandwritingLabel"));
        sourceHandwritingLabel->setGeometry(QRect(10, 340, 91, 21));
        sourceStyleText = new QTextEdit(sources);
        sourceStyleText->setObjectName(QStringLiteral("sourceStyleText"));
        sourceStyleText->setGeometry(QRect(110, 340, 321, 51));
        sourceCreateButton = new QPushButton(sources);
        sourceCreateButton->setObjectName(QStringLiteral("sourceCreateButton"));
        sourceCreateButton->setGeometry(QRect(10, 400, 75, 23));
        sourceAddButton = new QPushButton(sources);
        sourceAddButton->setObjectName(QStringLiteral("sourceAddButton"));
        sourceAddButton->setGeometry(QRect(90, 400, 75, 23));
        sourceFinishButton = new QPushButton(sources);
        sourceFinishButton->setObjectName(QStringLiteral("sourceFinishButton"));
        sourceFinishButton->setGeometry(QRect(170, 400, 75, 23));
        sourcePhysicallocationLine = new QLineEdit(sources);
        sourcePhysicallocationLine->setObjectName(QStringLiteral("sourcePhysicallocationLine"));
        sourcePhysicallocationLine->setGeometry(QRect(100, 100, 331, 21));
        sourceOwnershipLine = new QLineEdit(sources);
        sourceOwnershipLine->setObjectName(QStringLiteral("sourceOwnershipLine"));
        sourceOwnershipLine->setGeometry(QRect(70, 130, 361, 21));
        sourceDateLine = new QLineEdit(sources);
        sourceDateLine->setObjectName(QStringLiteral("sourceDateLine"));
        sourceDateLine->setGeometry(QRect(100, 160, 331, 21));
        sourceTitleLabel_3 = new QLabel(sources);
        sourceTitleLabel_3->setObjectName(QStringLiteral("sourceTitleLabel_3"));
        sourceTitleLabel_3->setGeometry(QRect(10, 100, 81, 21));
        sourceTitleLabel_4 = new QLabel(sources);
        sourceTitleLabel_4->setObjectName(QStringLiteral("sourceTitleLabel_4"));
        sourceTitleLabel_4->setGeometry(QRect(10, 130, 61, 21));
        sourceTitleLabel_5 = new QLabel(sources);
        sourceTitleLabel_5->setObjectName(QStringLiteral("sourceTitleLabel_5"));
        sourceTitleLabel_5->setGeometry(QRect(10, 160, 81, 21));
        tabWidget->addTab(sources, QString());
        staffTab = new QWidget();
        staffTab->setObjectName(QStringLiteral("staffTab"));
        staffIDLabel = new QLabel(staffTab);
        staffIDLabel->setObjectName(QStringLiteral("staffIDLabel"));
        staffIDLabel->setGeometry(QRect(10, 10, 47, 21));
        staffLinecountLabel = new QLabel(staffTab);
        staffLinecountLabel->setObjectName(QStringLiteral("staffLinecountLabel"));
        staffLinecountLabel->setGeometry(QRect(10, 40, 47, 21));
        staffCleflineLabel = new QLabel(staffTab);
        staffCleflineLabel->setObjectName(QStringLiteral("staffCleflineLabel"));
        staffCleflineLabel->setGeometry(QRect(10, 170, 47, 21));
        staffClefshapeLabel = new QLabel(staffTab);
        staffClefshapeLabel->setObjectName(QStringLiteral("staffClefshapeLabel"));
        staffClefshapeLabel->setGeometry(QRect(10, 200, 47, 21));
        staffIDLine = new QLineEdit(staffTab);
        staffIDLine->setObjectName(QStringLiteral("staffIDLine"));
        staffIDLine->setGeometry(QRect(70, 10, 361, 21));
        staffLinecountLine = new QLineEdit(staffTab);
        staffLinecountLine->setObjectName(QStringLiteral("staffLinecountLine"));
        staffLinecountLine->setGeometry(QRect(70, 40, 361, 21));
        staffCleflineLine = new QLineEdit(staffTab);
        staffCleflineLine->setObjectName(QStringLiteral("staffCleflineLine"));
        staffCleflineLine->setGeometry(QRect(70, 170, 361, 21));
        staffClefshapeLine = new QLineEdit(staffTab);
        staffClefshapeLine->setObjectName(QStringLiteral("staffClefshapeLine"));
        staffClefshapeLine->setGeometry(QRect(70, 200, 361, 21));
        staffCreateButton = new QPushButton(staffTab);
        staffCreateButton->setObjectName(QStringLiteral("staffCreateButton"));
        staffCreateButton->setGeometry(QRect(10, 130, 121, 23));
        staffAddclefButton = new QPushButton(staffTab);
        staffAddclefButton->setObjectName(QStringLiteral("staffAddclefButton"));
        staffAddclefButton->setGeometry(QRect(10, 230, 75, 23));
        staffFinishButton = new QPushButton(staffTab);
        staffFinishButton->setObjectName(QStringLiteral("staffFinishButton"));
        staffFinishButton->setGeometry(QRect(170, 230, 75, 23));
        staffNewstaffButton = new QPushButton(staffTab);
        staffNewstaffButton->setObjectName(QStringLiteral("staffNewstaffButton"));
        staffNewstaffButton->setGeometry(QRect(90, 230, 75, 23));
        staffLinecolorLabel = new QLabel(staffTab);
        staffLinecolorLabel->setObjectName(QStringLiteral("staffLinecolorLabel"));
        staffLinecolorLabel->setGeometry(QRect(10, 70, 51, 21));
        staffLinecolorToolbutton = new QToolButton(staffTab);
        staffLinecolorToolbutton->setObjectName(QStringLiteral("staffLinecolorToolbutton"));
        staffLinecolorToolbutton->setGeometry(QRect(70, 70, 361, 21));
        staffLinecolorToolbutton->setPopupMode(QToolButton::InstantPopup);
        staffLinecolorToolbutton->setToolButtonStyle(Qt::ToolButtonTextOnly);
        staffLinecolorToolbutton->setArrowType(Qt::DownArrow);
        staffModeToolbutton = new QToolButton(staffTab);
        staffModeToolbutton->setObjectName(QStringLiteral("staffModeToolbutton"));
        staffModeToolbutton->setGeometry(QRect(70, 100, 361, 21));
        staffModeToolbutton->setPopupMode(QToolButton::InstantPopup);
        staffModeToolbutton->setToolButtonStyle(Qt::ToolButtonTextOnly);
        staffModeToolbutton->setArrowType(Qt::DownArrow);
        staffModeLabel = new QLabel(staffTab);
        staffModeLabel->setObjectName(QStringLiteral("staffModeLabel"));
        staffModeLabel->setGeometry(QRect(10, 100, 51, 21));
        tabWidget->addTab(staffTab, QString());
        sylTab = new QWidget();
        sylTab->setObjectName(QStringLiteral("sylTab"));
        sylPageLabel = new QLabel(sylTab);
        sylPageLabel->setObjectName(QStringLiteral("sylPageLabel"));
        sylPageLabel->setGeometry(QRect(10, 100, 47, 21));
        sylLineLabel = new QLabel(sylTab);
        sylLineLabel->setObjectName(QStringLiteral("sylLineLabel"));
        sylLineLabel->setGeometry(QRect(10, 130, 47, 21));
        sylSyllableLLabel = new QLabel(sylTab);
        sylSyllableLLabel->setObjectName(QStringLiteral("sylSyllableLLabel"));
        sylSyllableLLabel->setGeometry(QRect(10, 160, 47, 21));
        sylPageLine = new QLineEdit(sylTab);
        sylPageLine->setObjectName(QStringLiteral("sylPageLine"));
        sylPageLine->setGeometry(QRect(70, 100, 361, 21));
        sylLineLine = new QLineEdit(sylTab);
        sylLineLine->setObjectName(QStringLiteral("sylLineLine"));
        sylLineLine->setGeometry(QRect(70, 130, 361, 21));
        sylSyllableLine = new QLineEdit(sylTab);
        sylSyllableLine->setObjectName(QStringLiteral("sylSyllableLine"));
        sylSyllableLine->setGeometry(QRect(70, 160, 361, 21));
        sylCommentText = new QTextEdit(sylTab);
        sylCommentText->setObjectName(QStringLiteral("sylCommentText"));
        sylCommentText->setGeometry(QRect(70, 190, 361, 71));
        sylCommentLabel = new QLabel(sylTab);
        sylCommentLabel->setObjectName(QStringLiteral("sylCommentLabel"));
        sylCommentLabel->setGeometry(QRect(10, 190, 47, 21));
        sylCreateButton = new QPushButton(sylTab);
        sylCreateButton->setObjectName(QStringLiteral("sylCreateButton"));
        sylCreateButton->setGeometry(QRect(10, 270, 91, 23));
        sylFinishButton = new QPushButton(sylTab);
        sylFinishButton->setObjectName(QStringLiteral("sylFinishButton"));
        sylFinishButton->setGeometry(QRect(110, 270, 75, 23));
        sylStaffLabel = new QLabel(sylTab);
        sylStaffLabel->setObjectName(QStringLiteral("sylStaffLabel"));
        sylStaffLabel->setGeometry(QRect(10, 40, 47, 21));
        sylSourceLabel = new QLabel(sylTab);
        sylSourceLabel->setObjectName(QStringLiteral("sylSourceLabel"));
        sylSourceLabel->setGeometry(QRect(10, 10, 47, 21));
        sylSourceToolbutton = new QToolButton(sylTab);
        sylSourceToolbutton->setObjectName(QStringLiteral("sylSourceToolbutton"));
        sylSourceToolbutton->setGeometry(QRect(70, 10, 361, 21));
        sylSourceToolbutton->setPopupMode(QToolButton::InstantPopup);
        sylStaffToolbutton = new QToolButton(sylTab);
        sylStaffToolbutton->setObjectName(QStringLiteral("sylStaffToolbutton"));
        sylStaffToolbutton->setGeometry(QRect(70, 40, 361, 21));
        sylStaffToolbutton->setPopupMode(QToolButton::InstantPopup);
        sylTypeToolbutton = new QToolButton(sylTab);
        sylTypeToolbutton->setObjectName(QStringLiteral("sylTypeToolbutton"));
        sylTypeToolbutton->setGeometry(QRect(70, 70, 361, 21));
        sylTypeToolbutton->setPopupMode(QToolButton::InstantPopup);
        sylTypeLabel = new QLabel(sylTab);
        sylTypeLabel->setObjectName(QStringLiteral("sylTypeLabel"));
        sylTypeLabel->setGeometry(QRect(10, 70, 47, 21));
        sylFilenameLabel = new QLabel(sylTab);
        sylFilenameLabel->setObjectName(QStringLiteral("sylFilenameLabel"));
        sylFilenameLabel->setGeometry(QRect(10, 320, 47, 21));
        sylFilenameLine = new QLineEdit(sylTab);
        sylFilenameLine->setObjectName(QStringLiteral("sylFilenameLine"));
        sylFilenameLine->setGeometry(QRect(70, 320, 361, 21));
        sylSaveButton = new QPushButton(sylTab);
        sylSaveButton->setObjectName(QStringLiteral("sylSaveButton"));
        sylSaveButton->setGeometry(QRect(10, 350, 75, 23));
        tabWidget->addTab(sylTab, QString());
        varTab = new QWidget();
        varTab->setObjectName(QStringLiteral("varTab"));
        label = new QLabel(varTab);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 101, 21));
        varSourceLabel = new QLabel(varTab);
        varSourceLabel->setObjectName(QStringLiteral("varSourceLabel"));
        varSourceLabel->setGeometry(QRect(110, 10, 521, 21));
        varPitchToolbutton = new QToolButton(varTab);
        varPitchToolbutton->setObjectName(QStringLiteral("varPitchToolbutton"));
        varPitchToolbutton->setGeometry(QRect(70, 40, 361, 21));
        varPitchToolbutton->setPopupMode(QToolButton::InstantPopup);
        varCommentText = new QTextEdit(varTab);
        varCommentText->setObjectName(QStringLiteral("varCommentText"));
        varCommentText->setGeometry(QRect(70, 190, 361, 71));
        varOctaveToolbutton = new QToolButton(varTab);
        varOctaveToolbutton->setObjectName(QStringLiteral("varOctaveToolbutton"));
        varOctaveToolbutton->setGeometry(QRect(70, 70, 361, 21));
        varOctaveToolbutton->setPopupMode(QToolButton::InstantPopup);
        varPreviousToolbutton = new QToolButton(varTab);
        varPreviousToolbutton->setObjectName(QStringLiteral("varPreviousToolbutton"));
        varPreviousToolbutton->setGeometry(QRect(70, 100, 361, 21));
        varPreviousToolbutton->setPopupMode(QToolButton::InstantPopup);
        varPitchLabel = new QLabel(varTab);
        varPitchLabel->setObjectName(QStringLiteral("varPitchLabel"));
        varPitchLabel->setGeometry(QRect(10, 40, 47, 21));
        varOctaveLabel = new QLabel(varTab);
        varOctaveLabel->setObjectName(QStringLiteral("varOctaveLabel"));
        varOctaveLabel->setGeometry(QRect(10, 70, 47, 21));
        varPreviousLabel = new QLabel(varTab);
        varPreviousLabel->setObjectName(QStringLiteral("varPreviousLabel"));
        varPreviousLabel->setGeometry(QRect(10, 100, 47, 21));
        varConnectionLabel = new QLabel(varTab);
        varConnectionLabel->setObjectName(QStringLiteral("varConnectionLabel"));
        varConnectionLabel->setGeometry(QRect(10, 130, 61, 21));
        varAddpitchButton = new QPushButton(varTab);
        varAddpitchButton->setObjectName(QStringLiteral("varAddpitchButton"));
        varAddpitchButton->setGeometry(QRect(10, 270, 91, 23));
        varNextButton = new QPushButton(varTab);
        varNextButton->setObjectName(QStringLiteral("varNextButton"));
        varNextButton->setGeometry(QRect(110, 270, 75, 23));
        varConnectionToolbutton = new QToolButton(varTab);
        varConnectionToolbutton->setObjectName(QStringLiteral("varConnectionToolbutton"));
        varConnectionToolbutton->setGeometry(QRect(70, 130, 361, 21));
        varConnectionToolbutton->setPopupMode(QToolButton::InstantPopup);
        varTiltToolbutton = new QToolButton(varTab);
        varTiltToolbutton->setObjectName(QStringLiteral("varTiltToolbutton"));
        varTiltToolbutton->setGeometry(QRect(70, 160, 361, 21));
        varTiltToolbutton->setPopupMode(QToolButton::InstantPopup);
        varTiltLabel = new QLabel(varTab);
        varTiltLabel->setObjectName(QStringLiteral("varTiltLabel"));
        varTiltLabel->setGeometry(QRect(10, 160, 47, 21));
        varCommentLabel = new QLabel(varTab);
        varCommentLabel->setObjectName(QStringLiteral("varCommentLabel"));
        varCommentLabel->setGeometry(QRect(10, 190, 47, 21));
        tabWidget->addTab(varTab, QString());
        pitchTab = new QWidget();
        pitchTab->setObjectName(QStringLiteral("pitchTab"));
        pitchPitchLabel = new QLabel(pitchTab);
        pitchPitchLabel->setObjectName(QStringLiteral("pitchPitchLabel"));
        pitchPitchLabel->setGeometry(QRect(10, 10, 47, 21));
        pitchCommentText = new QTextEdit(pitchTab);
        pitchCommentText->setObjectName(QStringLiteral("pitchCommentText"));
        pitchCommentText->setGeometry(QRect(70, 160, 361, 71));
        pitchOctaveLabel = new QLabel(pitchTab);
        pitchOctaveLabel->setObjectName(QStringLiteral("pitchOctaveLabel"));
        pitchOctaveLabel->setGeometry(QRect(10, 40, 47, 21));
        pitchCommentLabel = new QLabel(pitchTab);
        pitchCommentLabel->setObjectName(QStringLiteral("pitchCommentLabel"));
        pitchCommentLabel->setGeometry(QRect(10, 160, 47, 21));
        pitchAddButton = new QPushButton(pitchTab);
        pitchAddButton->setObjectName(QStringLiteral("pitchAddButton"));
        pitchAddButton->setGeometry(QRect(10, 240, 91, 23));
        pitchFinishButton = new QPushButton(pitchTab);
        pitchFinishButton->setObjectName(QStringLiteral("pitchFinishButton"));
        pitchFinishButton->setGeometry(QRect(110, 240, 75, 23));
        pitchPitchToolbutton = new QToolButton(pitchTab);
        pitchPitchToolbutton->setObjectName(QStringLiteral("pitchPitchToolbutton"));
        pitchPitchToolbutton->setGeometry(QRect(70, 10, 361, 21));
        pitchPitchToolbutton->setPopupMode(QToolButton::InstantPopup);
        pitchOctaveToolbutton = new QToolButton(pitchTab);
        pitchOctaveToolbutton->setObjectName(QStringLiteral("pitchOctaveToolbutton"));
        pitchOctaveToolbutton->setGeometry(QRect(70, 40, 361, 21));
        pitchOctaveToolbutton->setPopupMode(QToolButton::InstantPopup);
        pitchPreviousToolbutton = new QToolButton(pitchTab);
        pitchPreviousToolbutton->setObjectName(QStringLiteral("pitchPreviousToolbutton"));
        pitchPreviousToolbutton->setGeometry(QRect(70, 70, 361, 21));
        pitchPreviousToolbutton->setPopupMode(QToolButton::InstantPopup);
        pitchPreviousLabel = new QLabel(pitchTab);
        pitchPreviousLabel->setObjectName(QStringLiteral("pitchPreviousLabel"));
        pitchPreviousLabel->setGeometry(QRect(10, 70, 47, 21));
        pitchConnectionToolbutton = new QToolButton(pitchTab);
        pitchConnectionToolbutton->setObjectName(QStringLiteral("pitchConnectionToolbutton"));
        pitchConnectionToolbutton->setGeometry(QRect(70, 100, 361, 21));
        pitchConnectionToolbutton->setPopupMode(QToolButton::InstantPopup);
        pitchTiltToolbutton = new QToolButton(pitchTab);
        pitchTiltToolbutton->setObjectName(QStringLiteral("pitchTiltToolbutton"));
        pitchTiltToolbutton->setGeometry(QRect(70, 130, 361, 21));
        pitchTiltToolbutton->setPopupMode(QToolButton::InstantPopup);
        pitchConnectionLabel = new QLabel(pitchTab);
        pitchConnectionLabel->setObjectName(QStringLiteral("pitchConnectionLabel"));
        pitchConnectionLabel->setGeometry(QRect(10, 100, 61, 21));
        pitchTiltLabel = new QLabel(pitchTab);
        pitchTiltLabel->setObjectName(QStringLiteral("pitchTiltLabel"));
        pitchTiltLabel->setGeometry(QRect(10, 130, 47, 21));
        pitchAddVariantButton = new QPushButton(pitchTab);
        pitchAddVariantButton->setObjectName(QStringLiteral("pitchAddVariantButton"));
        pitchAddVariantButton->setGeometry(QRect(200, 240, 75, 23));
        tabWidget->addTab(pitchTab, QString());

        gridLayout->addWidget(tabWidget, 1, 0, 2, 1);

        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1302, 21));
        MainWindow->setMenuBar(menuBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "meiNeumesEditor", nullptr));
        adjustByHand->setText(QApplication::translate("MainWindow", "adjust by hand", nullptr));
        metaButton->setText(QApplication::translate("MainWindow", "create meta data", nullptr));
        titleLine->setInputMask(QString());
        titleLine->setText(QString());
        titleLabel->setText(QApplication::translate("MainWindow", "Title", nullptr));
        composerLabel->setText(QApplication::translate("MainWindow", "Composer", nullptr));
        composerLine->setInputMask(QString());
        composerLine->setText(QString());
        authorLabel1->setText(QApplication::translate("MainWindow", "Author/s", nullptr));
        abailabilityLabel->setText(QApplication::translate("MainWindow", "Availability", nullptr));
        authorLine1->setInputMask(QString());
        authorLine1->setText(QString());
        commentLabel->setText(QApplication::translate("MainWindow", "Comments", nullptr));
        languageLabel->setText(QApplication::translate("MainWindow", "Language", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(meta), QApplication::translate("MainWindow", "Meta", nullptr));
        sourceIDLabel->setText(QApplication::translate("MainWindow", "ID", nullptr));
        sourceAuthorLabel->setText(QApplication::translate("MainWindow", "Author", nullptr));
        sourceTitleLabel->setText(QApplication::translate("MainWindow", "Title", nullptr));
        sourcePubStatusLabel->setText(QApplication::translate("MainWindow", "Publication Status", nullptr));
        sourceMediumLabel->setText(QApplication::translate("MainWindow", "Medium", nullptr));
        sourceDimensionLabel->setText(QApplication::translate("MainWindow", "Dimension", nullptr));
        label_13->setText(QApplication::translate("MainWindow", "x", nullptr));
        sourceUnitLabel->setText(QApplication::translate("MainWindow", "Unit", nullptr));
        sourceConditionLabel->setText(QApplication::translate("MainWindow", "Condition", nullptr));
        sourceExtentLabel->setText(QApplication::translate("MainWindow", "Extent", nullptr));
        sourceHandwritingLabel->setText(QApplication::translate("MainWindow", "Handwriting Style", nullptr));
        sourceCreateButton->setText(QApplication::translate("MainWindow", "create source", nullptr));
        sourceAddButton->setText(QApplication::translate("MainWindow", "add source", nullptr));
        sourceFinishButton->setText(QApplication::translate("MainWindow", "finish", nullptr));
        sourceTitleLabel_3->setText(QApplication::translate("MainWindow", "Physical Location", nullptr));
        sourceTitleLabel_4->setText(QApplication::translate("MainWindow", "Ownership", nullptr));
        sourceTitleLabel_5->setText(QApplication::translate("MainWindow", "Publication Date", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(sources), QApplication::translate("MainWindow", "Sources", nullptr));
        staffIDLabel->setText(QApplication::translate("MainWindow", "ID", nullptr));
        staffLinecountLabel->setText(QApplication::translate("MainWindow", "Linecount", nullptr));
        staffCleflineLabel->setText(QApplication::translate("MainWindow", "Clefline", nullptr));
        staffClefshapeLabel->setText(QApplication::translate("MainWindow", "Clefshape", nullptr));
        staffCreateButton->setText(QApplication::translate("MainWindow", "Create Staffdefinition", nullptr));
        staffAddclefButton->setText(QApplication::translate("MainWindow", "Add Clef", nullptr));
        staffFinishButton->setText(QApplication::translate("MainWindow", "Finish", nullptr));
        staffNewstaffButton->setText(QApplication::translate("MainWindow", "New Staff", nullptr));
        staffLinecolorLabel->setText(QApplication::translate("MainWindow", "Linecolor", nullptr));
        staffLinecolorToolbutton->setText(QString());
        staffModeToolbutton->setText(QString());
        staffModeLabel->setText(QApplication::translate("MainWindow", "Mode", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(staffTab), QApplication::translate("MainWindow", "Staff", nullptr));
        sylPageLabel->setText(QApplication::translate("MainWindow", "Page", nullptr));
        sylLineLabel->setText(QApplication::translate("MainWindow", "Line", nullptr));
        sylSyllableLLabel->setText(QApplication::translate("MainWindow", "Syllable", nullptr));
        sylCommentLabel->setText(QApplication::translate("MainWindow", "Comment", nullptr));
        sylCreateButton->setText(QApplication::translate("MainWindow", "Create Syllablle", nullptr));
        sylFinishButton->setText(QApplication::translate("MainWindow", "Finish", nullptr));
        sylStaffLabel->setText(QApplication::translate("MainWindow", "Staff", nullptr));
        sylSourceLabel->setText(QApplication::translate("MainWindow", "Source", nullptr));
        sylSourceToolbutton->setText(QApplication::translate("MainWindow", "Choose", nullptr));
        sylStaffToolbutton->setText(QApplication::translate("MainWindow", "Choose", nullptr));
        sylTypeToolbutton->setText(QString());
        sylTypeLabel->setText(QApplication::translate("MainWindow", "Type", nullptr));
        sylFilenameLabel->setText(QApplication::translate("MainWindow", "Filename", nullptr));
        sylSaveButton->setText(QApplication::translate("MainWindow", "Save", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(sylTab), QApplication::translate("MainWindow", "Syllable", nullptr));
        label->setText(QApplication::translate("MainWindow", "Changes for source", nullptr));
        varSourceLabel->setText(QString());
        varPitchToolbutton->setText(QString());
        varOctaveToolbutton->setText(QString());
        varPreviousToolbutton->setText(QString());
        varPitchLabel->setText(QApplication::translate("MainWindow", "Pitch", nullptr));
        varOctaveLabel->setText(QApplication::translate("MainWindow", "Octave", nullptr));
        varPreviousLabel->setText(QApplication::translate("MainWindow", "Previous", nullptr));
        varConnectionLabel->setText(QApplication::translate("MainWindow", "Connection", nullptr));
        varAddpitchButton->setText(QApplication::translate("MainWindow", "Add Pitch", nullptr));
        varNextButton->setText(QApplication::translate("MainWindow", "Next", nullptr));
        varConnectionToolbutton->setText(QString());
        varTiltToolbutton->setText(QString());
        varTiltLabel->setText(QApplication::translate("MainWindow", "Tilt", nullptr));
        varCommentLabel->setText(QApplication::translate("MainWindow", "Comment", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(varTab), QApplication::translate("MainWindow", "Variations", nullptr));
        pitchPitchLabel->setText(QApplication::translate("MainWindow", "Pitch", nullptr));
        pitchOctaveLabel->setText(QApplication::translate("MainWindow", "Octave", nullptr));
        pitchCommentLabel->setText(QApplication::translate("MainWindow", "Comment", nullptr));
        pitchAddButton->setText(QApplication::translate("MainWindow", "Add Pitch", nullptr));
        pitchFinishButton->setText(QApplication::translate("MainWindow", "Finish", nullptr));
        pitchPitchToolbutton->setText(QString());
        pitchOctaveToolbutton->setText(QString());
        pitchPreviousToolbutton->setText(QString());
        pitchPreviousLabel->setText(QApplication::translate("MainWindow", "Previous", nullptr));
        pitchConnectionToolbutton->setText(QString());
        pitchTiltToolbutton->setText(QString());
        pitchConnectionLabel->setText(QApplication::translate("MainWindow", "Connection", nullptr));
        pitchTiltLabel->setText(QApplication::translate("MainWindow", "Tilt", nullptr));
        pitchAddVariantButton->setText(QApplication::translate("MainWindow", "Add Variant", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(pitchTab), QApplication::translate("MainWindow", "Pitches", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
