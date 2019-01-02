/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
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

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTextEdit *textEdit;
    QTabWidget *tabWidget;
    QWidget *meta;
    QPushButton *metaButton;
    QLineEdit *titleLine;
    QLabel *titleLabel;
    QLabel *composerLabel;
    QLineEdit *composerLine;
    QLabel *authorLabel1;
    QLabel *authorLabel2;
    QLabel *abailabilityLabel;
    QLineEdit *authorLine1;
    QLineEdit *authorLine2;
    QLabel *commentLabel;
    QTextEdit *availabilityText;
    QTextEdit *commentsText;
    QLineEdit *languageLine;
    QLabel *languageLabel;
    QLineEdit *keywordsLine;
    QLabel *keywordLabel;
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
    QPushButton *sylVariantButton;
    QPushButton *sylFinishButton;
    QLabel *sylStaffLabel;
    QLabel *sylSourceLabel;
    QToolButton *sylSourceToolbutton;
    QToolButton *sylStaffToolbutton;
    QWidget *pitchTab;
    QLabel *pitchPitchLabel;
    QLineEdit *pitchPitchLine;
    QLineEdit *pitchOctaveLine;
    QTextEdit *pitchCommentText;
    QLabel *pitchOctaveLabel;
    QLabel *pitchCommentLabel;
    QPushButton *pitchAddButton;
    QPushButton *pitchFinishButton;
    QCheckBox *adjustByHand;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1302, 675);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setEnabled(true);
        textEdit->setGeometry(QRect(620, 0, 681, 621));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(10, 40, 601, 581));
        meta = new QWidget();
        meta->setObjectName(QString::fromUtf8("meta"));
        metaButton = new QPushButton(meta);
        metaButton->setObjectName(QString::fromUtf8("metaButton"));
        metaButton->setGeometry(QRect(10, 450, 91, 23));
        titleLine = new QLineEdit(meta);
        titleLine->setObjectName(QString::fromUtf8("titleLine"));
        titleLine->setGeometry(QRect(70, 90, 361, 21));
        titleLabel = new QLabel(meta);
        titleLabel->setObjectName(QString::fromUtf8("titleLabel"));
        titleLabel->setGeometry(QRect(10, 90, 47, 21));
        composerLabel = new QLabel(meta);
        composerLabel->setObjectName(QString::fromUtf8("composerLabel"));
        composerLabel->setGeometry(QRect(10, 120, 47, 21));
        composerLine = new QLineEdit(meta);
        composerLine->setObjectName(QString::fromUtf8("composerLine"));
        composerLine->setGeometry(QRect(70, 120, 361, 21));
        authorLabel1 = new QLabel(meta);
        authorLabel1->setObjectName(QString::fromUtf8("authorLabel1"));
        authorLabel1->setGeometry(QRect(10, 150, 47, 21));
        authorLabel2 = new QLabel(meta);
        authorLabel2->setObjectName(QString::fromUtf8("authorLabel2"));
        authorLabel2->setGeometry(QRect(10, 180, 47, 21));
        abailabilityLabel = new QLabel(meta);
        abailabilityLabel->setObjectName(QString::fromUtf8("abailabilityLabel"));
        abailabilityLabel->setGeometry(QRect(10, 240, 61, 21));
        authorLine1 = new QLineEdit(meta);
        authorLine1->setObjectName(QString::fromUtf8("authorLine1"));
        authorLine1->setGeometry(QRect(70, 150, 361, 21));
        authorLine2 = new QLineEdit(meta);
        authorLine2->setObjectName(QString::fromUtf8("authorLine2"));
        authorLine2->setGeometry(QRect(70, 180, 361, 21));
        commentLabel = new QLabel(meta);
        commentLabel->setObjectName(QString::fromUtf8("commentLabel"));
        commentLabel->setGeometry(QRect(10, 300, 61, 21));
        availabilityText = new QTextEdit(meta);
        availabilityText->setObjectName(QString::fromUtf8("availabilityText"));
        availabilityText->setGeometry(QRect(70, 240, 361, 51));
        commentsText = new QTextEdit(meta);
        commentsText->setObjectName(QString::fromUtf8("commentsText"));
        commentsText->setGeometry(QRect(70, 300, 361, 51));
        languageLine = new QLineEdit(meta);
        languageLine->setObjectName(QString::fromUtf8("languageLine"));
        languageLine->setGeometry(QRect(70, 210, 361, 20));
        languageLabel = new QLabel(meta);
        languageLabel->setObjectName(QString::fromUtf8("languageLabel"));
        languageLabel->setGeometry(QRect(10, 210, 47, 21));
        keywordsLine = new QLineEdit(meta);
        keywordsLine->setObjectName(QString::fromUtf8("keywordsLine"));
        keywordsLine->setGeometry(QRect(70, 360, 361, 20));
        keywordLabel = new QLabel(meta);
        keywordLabel->setObjectName(QString::fromUtf8("keywordLabel"));
        keywordLabel->setGeometry(QRect(10, 360, 61, 21));
        tabWidget->addTab(meta, QString());
        sources = new QWidget();
        sources->setObjectName(QString::fromUtf8("sources"));
        sourceIDLine = new QLineEdit(sources);
        sourceIDLine->setObjectName(QString::fromUtf8("sourceIDLine"));
        sourceIDLine->setGeometry(QRect(70, 90, 361, 21));
        sourceAuthorLine = new QLineEdit(sources);
        sourceAuthorLine->setObjectName(QString::fromUtf8("sourceAuthorLine"));
        sourceAuthorLine->setGeometry(QRect(70, 120, 361, 21));
        sourceTitleLine = new QLineEdit(sources);
        sourceTitleLine->setObjectName(QString::fromUtf8("sourceTitleLine"));
        sourceTitleLine->setGeometry(QRect(70, 150, 361, 21));
        sourcePubStatusLine = new QLineEdit(sources);
        sourcePubStatusLine->setObjectName(QString::fromUtf8("sourcePubStatusLine"));
        sourcePubStatusLine->setGeometry(QRect(100, 180, 331, 21));
        sourceIDLabel = new QLabel(sources);
        sourceIDLabel->setObjectName(QString::fromUtf8("sourceIDLabel"));
        sourceIDLabel->setGeometry(QRect(10, 90, 47, 21));
        sourceAuthorLabel = new QLabel(sources);
        sourceAuthorLabel->setObjectName(QString::fromUtf8("sourceAuthorLabel"));
        sourceAuthorLabel->setGeometry(QRect(10, 120, 47, 21));
        sourceTitleLabel = new QLabel(sources);
        sourceTitleLabel->setObjectName(QString::fromUtf8("sourceTitleLabel"));
        sourceTitleLabel->setGeometry(QRect(10, 150, 47, 21));
        sourcePubStatusLabel = new QLabel(sources);
        sourcePubStatusLabel->setObjectName(QString::fromUtf8("sourcePubStatusLabel"));
        sourcePubStatusLabel->setGeometry(QRect(10, 180, 91, 21));
        sourceMediumLine = new QLineEdit(sources);
        sourceMediumLine->setObjectName(QString::fromUtf8("sourceMediumLine"));
        sourceMediumLine->setGeometry(QRect(70, 210, 361, 21));
        sourceXLine = new QLineEdit(sources);
        sourceXLine->setObjectName(QString::fromUtf8("sourceXLine"));
        sourceXLine->setGeometry(QRect(70, 240, 31, 21));
        sourceMediumLabel = new QLabel(sources);
        sourceMediumLabel->setObjectName(QString::fromUtf8("sourceMediumLabel"));
        sourceMediumLabel->setGeometry(QRect(10, 210, 47, 21));
        sourceYLine = new QLineEdit(sources);
        sourceYLine->setObjectName(QString::fromUtf8("sourceYLine"));
        sourceYLine->setGeometry(QRect(120, 240, 31, 21));
        sourceUnitLine = new QLineEdit(sources);
        sourceUnitLine->setObjectName(QString::fromUtf8("sourceUnitLine"));
        sourceUnitLine->setGeometry(QRect(190, 240, 31, 21));
        sourceDimensionLabel = new QLabel(sources);
        sourceDimensionLabel->setObjectName(QString::fromUtf8("sourceDimensionLabel"));
        sourceDimensionLabel->setGeometry(QRect(10, 240, 47, 21));
        label_13 = new QLabel(sources);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(110, 240, 16, 21));
        sourceUnitLabel = new QLabel(sources);
        sourceUnitLabel->setObjectName(QString::fromUtf8("sourceUnitLabel"));
        sourceUnitLabel->setGeometry(QRect(160, 240, 47, 21));
        sourceConditionLine = new QLineEdit(sources);
        sourceConditionLine->setObjectName(QString::fromUtf8("sourceConditionLine"));
        sourceConditionLine->setGeometry(QRect(70, 270, 361, 21));
        sourceConditionLabel = new QLabel(sources);
        sourceConditionLabel->setObjectName(QString::fromUtf8("sourceConditionLabel"));
        sourceConditionLabel->setGeometry(QRect(10, 270, 47, 21));
        sourceExtentLine = new QLineEdit(sources);
        sourceExtentLine->setObjectName(QString::fromUtf8("sourceExtentLine"));
        sourceExtentLine->setGeometry(QRect(70, 300, 361, 21));
        sourceExtentLabel = new QLabel(sources);
        sourceExtentLabel->setObjectName(QString::fromUtf8("sourceExtentLabel"));
        sourceExtentLabel->setGeometry(QRect(10, 300, 47, 21));
        sourceHandwritingLabel = new QLabel(sources);
        sourceHandwritingLabel->setObjectName(QString::fromUtf8("sourceHandwritingLabel"));
        sourceHandwritingLabel->setGeometry(QRect(10, 330, 91, 21));
        sourceStyleText = new QTextEdit(sources);
        sourceStyleText->setObjectName(QString::fromUtf8("sourceStyleText"));
        sourceStyleText->setGeometry(QRect(110, 330, 321, 51));
        sourceCreateButton = new QPushButton(sources);
        sourceCreateButton->setObjectName(QString::fromUtf8("sourceCreateButton"));
        sourceCreateButton->setGeometry(QRect(10, 400, 75, 23));
        sourceAddButton = new QPushButton(sources);
        sourceAddButton->setObjectName(QString::fromUtf8("sourceAddButton"));
        sourceAddButton->setGeometry(QRect(90, 400, 75, 23));
        sourceFinishButton = new QPushButton(sources);
        sourceFinishButton->setObjectName(QString::fromUtf8("sourceFinishButton"));
        sourceFinishButton->setGeometry(QRect(170, 400, 75, 23));
        tabWidget->addTab(sources, QString());
        staffTab = new QWidget();
        staffTab->setObjectName(QString::fromUtf8("staffTab"));
        staffIDLabel = new QLabel(staffTab);
        staffIDLabel->setObjectName(QString::fromUtf8("staffIDLabel"));
        staffIDLabel->setGeometry(QRect(10, 20, 47, 21));
        staffLinecountLabel = new QLabel(staffTab);
        staffLinecountLabel->setObjectName(QString::fromUtf8("staffLinecountLabel"));
        staffLinecountLabel->setGeometry(QRect(10, 50, 47, 21));
        staffCleflineLabel = new QLabel(staffTab);
        staffCleflineLabel->setObjectName(QString::fromUtf8("staffCleflineLabel"));
        staffCleflineLabel->setGeometry(QRect(10, 110, 47, 21));
        staffClefshapeLabel = new QLabel(staffTab);
        staffClefshapeLabel->setObjectName(QString::fromUtf8("staffClefshapeLabel"));
        staffClefshapeLabel->setGeometry(QRect(10, 140, 47, 21));
        staffIDLine = new QLineEdit(staffTab);
        staffIDLine->setObjectName(QString::fromUtf8("staffIDLine"));
        staffIDLine->setGeometry(QRect(70, 20, 361, 21));
        staffLinecountLine = new QLineEdit(staffTab);
        staffLinecountLine->setObjectName(QString::fromUtf8("staffLinecountLine"));
        staffLinecountLine->setGeometry(QRect(70, 50, 361, 21));
        staffCleflineLine = new QLineEdit(staffTab);
        staffCleflineLine->setObjectName(QString::fromUtf8("staffCleflineLine"));
        staffCleflineLine->setGeometry(QRect(70, 110, 361, 21));
        staffClefshapeLine = new QLineEdit(staffTab);
        staffClefshapeLine->setObjectName(QString::fromUtf8("staffClefshapeLine"));
        staffClefshapeLine->setGeometry(QRect(70, 140, 361, 21));
        staffCreateButton = new QPushButton(staffTab);
        staffCreateButton->setObjectName(QString::fromUtf8("staffCreateButton"));
        staffCreateButton->setGeometry(QRect(10, 80, 91, 23));
        staffAddclefButton = new QPushButton(staffTab);
        staffAddclefButton->setObjectName(QString::fromUtf8("staffAddclefButton"));
        staffAddclefButton->setGeometry(QRect(10, 170, 75, 23));
        staffFinishButton = new QPushButton(staffTab);
        staffFinishButton->setObjectName(QString::fromUtf8("staffFinishButton"));
        staffFinishButton->setGeometry(QRect(90, 170, 75, 23));
        tabWidget->addTab(staffTab, QString());
        sylTab = new QWidget();
        sylTab->setObjectName(QString::fromUtf8("sylTab"));
        sylPageLabel = new QLabel(sylTab);
        sylPageLabel->setObjectName(QString::fromUtf8("sylPageLabel"));
        sylPageLabel->setGeometry(QRect(10, 70, 47, 21));
        sylLineLabel = new QLabel(sylTab);
        sylLineLabel->setObjectName(QString::fromUtf8("sylLineLabel"));
        sylLineLabel->setGeometry(QRect(10, 100, 47, 21));
        sylSyllableLLabel = new QLabel(sylTab);
        sylSyllableLLabel->setObjectName(QString::fromUtf8("sylSyllableLLabel"));
        sylSyllableLLabel->setGeometry(QRect(10, 130, 47, 21));
        sylPageLine = new QLineEdit(sylTab);
        sylPageLine->setObjectName(QString::fromUtf8("sylPageLine"));
        sylPageLine->setGeometry(QRect(70, 70, 361, 21));
        sylLineLine = new QLineEdit(sylTab);
        sylLineLine->setObjectName(QString::fromUtf8("sylLineLine"));
        sylLineLine->setGeometry(QRect(70, 100, 361, 21));
        sylSyllableLine = new QLineEdit(sylTab);
        sylSyllableLine->setObjectName(QString::fromUtf8("sylSyllableLine"));
        sylSyllableLine->setGeometry(QRect(70, 130, 361, 21));
        sylCommentText = new QTextEdit(sylTab);
        sylCommentText->setObjectName(QString::fromUtf8("sylCommentText"));
        sylCommentText->setGeometry(QRect(70, 160, 361, 71));
        sylCommentLabel = new QLabel(sylTab);
        sylCommentLabel->setObjectName(QString::fromUtf8("sylCommentLabel"));
        sylCommentLabel->setGeometry(QRect(10, 160, 47, 21));
        sylCreateButton = new QPushButton(sylTab);
        sylCreateButton->setObjectName(QString::fromUtf8("sylCreateButton"));
        sylCreateButton->setGeometry(QRect(10, 240, 91, 23));
        sylVariantButton = new QPushButton(sylTab);
        sylVariantButton->setObjectName(QString::fromUtf8("sylVariantButton"));
        sylVariantButton->setGeometry(QRect(110, 240, 75, 23));
        sylFinishButton = new QPushButton(sylTab);
        sylFinishButton->setObjectName(QString::fromUtf8("sylFinishButton"));
        sylFinishButton->setGeometry(QRect(190, 240, 75, 23));
        sylStaffLabel = new QLabel(sylTab);
        sylStaffLabel->setObjectName(QString::fromUtf8("sylStaffLabel"));
        sylStaffLabel->setGeometry(QRect(10, 40, 47, 21));
        sylSourceLabel = new QLabel(sylTab);
        sylSourceLabel->setObjectName(QString::fromUtf8("sylSourceLabel"));
        sylSourceLabel->setGeometry(QRect(10, 10, 47, 21));
        sylSourceToolbutton = new QToolButton(sylTab);
        sylSourceToolbutton->setObjectName(QString::fromUtf8("sylSourceToolbutton"));
        sylSourceToolbutton->setGeometry(QRect(70, 10, 81, 19));
        sylSourceToolbutton->setPopupMode(QToolButton::MenuButtonPopup);
        sylStaffToolbutton = new QToolButton(sylTab);
        sylStaffToolbutton->setObjectName(QString::fromUtf8("sylStaffToolbutton"));
        sylStaffToolbutton->setGeometry(QRect(70, 40, 81, 19));
        sylStaffToolbutton->setPopupMode(QToolButton::MenuButtonPopup);
        tabWidget->addTab(sylTab, QString());
        pitchTab = new QWidget();
        pitchTab->setObjectName(QString::fromUtf8("pitchTab"));
        pitchPitchLabel = new QLabel(pitchTab);
        pitchPitchLabel->setObjectName(QString::fromUtf8("pitchPitchLabel"));
        pitchPitchLabel->setGeometry(QRect(10, 10, 47, 21));
        pitchPitchLine = new QLineEdit(pitchTab);
        pitchPitchLine->setObjectName(QString::fromUtf8("pitchPitchLine"));
        pitchPitchLine->setGeometry(QRect(70, 10, 361, 21));
        pitchOctaveLine = new QLineEdit(pitchTab);
        pitchOctaveLine->setObjectName(QString::fromUtf8("pitchOctaveLine"));
        pitchOctaveLine->setGeometry(QRect(70, 40, 361, 21));
        pitchCommentText = new QTextEdit(pitchTab);
        pitchCommentText->setObjectName(QString::fromUtf8("pitchCommentText"));
        pitchCommentText->setGeometry(QRect(70, 70, 361, 71));
        pitchOctaveLabel = new QLabel(pitchTab);
        pitchOctaveLabel->setObjectName(QString::fromUtf8("pitchOctaveLabel"));
        pitchOctaveLabel->setGeometry(QRect(10, 40, 47, 21));
        pitchCommentLabel = new QLabel(pitchTab);
        pitchCommentLabel->setObjectName(QString::fromUtf8("pitchCommentLabel"));
        pitchCommentLabel->setGeometry(QRect(10, 70, 47, 21));
        pitchAddButton = new QPushButton(pitchTab);
        pitchAddButton->setObjectName(QString::fromUtf8("pitchAddButton"));
        pitchAddButton->setGeometry(QRect(10, 150, 91, 23));
        pitchFinishButton = new QPushButton(pitchTab);
        pitchFinishButton->setObjectName(QString::fromUtf8("pitchFinishButton"));
        pitchFinishButton->setGeometry(QRect(110, 150, 75, 23));
        tabWidget->addTab(pitchTab, QString());
        adjustByHand = new QCheckBox(centralWidget);
        adjustByHand->setObjectName(QString::fromUtf8("adjustByHand"));
        adjustByHand->setGeometry(QRect(20, 10, 91, 17));
        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1302, 21));
        MainWindow->setMenuBar(menuBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(4);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "meiNeumesEditor", nullptr));
        metaButton->setText(QApplication::translate("MainWindow", "create meta data", nullptr));
        titleLine->setInputMask(QString());
        titleLine->setText(QString());
        titleLabel->setText(QApplication::translate("MainWindow", "Title", nullptr));
        composerLabel->setText(QApplication::translate("MainWindow", "Composer", nullptr));
        composerLine->setInputMask(QString());
        composerLine->setText(QString());
        authorLabel1->setText(QApplication::translate("MainWindow", "Author", nullptr));
        authorLabel2->setText(QApplication::translate("MainWindow", "Author", nullptr));
        abailabilityLabel->setText(QApplication::translate("MainWindow", "Availability", nullptr));
        authorLine1->setInputMask(QString());
        authorLine1->setText(QString());
        authorLine2->setInputMask(QString());
        authorLine2->setText(QString());
        commentLabel->setText(QApplication::translate("MainWindow", "Comments", nullptr));
        languageLabel->setText(QApplication::translate("MainWindow", "Language", nullptr));
        keywordLabel->setText(QApplication::translate("MainWindow", "Keywords", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(meta), QApplication::translate("MainWindow", "Meta", nullptr));
        sourceIDLabel->setText(QApplication::translate("MainWindow", "ID", nullptr));
        sourceAuthorLabel->setText(QApplication::translate("MainWindow", "Author", nullptr));
        sourceTitleLabel->setText(QApplication::translate("MainWindow", "Title", nullptr));
        sourcePubStatusLabel->setText(QApplication::translate("MainWindow", "Publication Status", nullptr));
        sourceMediumLabel->setText(QApplication::translate("MainWindow", "Medium", nullptr));
        sourceDimensionLabel->setText(QApplication::translate("MainWindow", "Dimension", nullptr));
        label_13->setText(QApplication::translate("MainWindow", "x", nullptr));
        sourceUnitLabel->setText(QApplication::translate("MainWindow", "Unit:", nullptr));
        sourceConditionLabel->setText(QApplication::translate("MainWindow", "Condition", nullptr));
        sourceExtentLabel->setText(QApplication::translate("MainWindow", "Extent", nullptr));
        sourceHandwritingLabel->setText(QApplication::translate("MainWindow", "Handwriting Style", nullptr));
        sourceCreateButton->setText(QApplication::translate("MainWindow", "create source", nullptr));
        sourceAddButton->setText(QApplication::translate("MainWindow", "add source", nullptr));
        sourceFinishButton->setText(QApplication::translate("MainWindow", "finish", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(sources), QApplication::translate("MainWindow", "Sources", nullptr));
        staffIDLabel->setText(QApplication::translate("MainWindow", "ID", nullptr));
        staffLinecountLabel->setText(QApplication::translate("MainWindow", "Linecount", nullptr));
        staffCleflineLabel->setText(QApplication::translate("MainWindow", "Clefline", nullptr));
        staffClefshapeLabel->setText(QApplication::translate("MainWindow", "Clefshape", nullptr));
        staffCreateButton->setText(QApplication::translate("MainWindow", "Create Staffdef", nullptr));
        staffAddclefButton->setText(QApplication::translate("MainWindow", "Add Clef", nullptr));
        staffFinishButton->setText(QApplication::translate("MainWindow", "Finish", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(staffTab), QApplication::translate("MainWindow", "Staff", nullptr));
        sylPageLabel->setText(QApplication::translate("MainWindow", "Page", nullptr));
        sylLineLabel->setText(QApplication::translate("MainWindow", "Line", nullptr));
        sylSyllableLLabel->setText(QApplication::translate("MainWindow", "Syllable", nullptr));
        sylCommentLabel->setText(QApplication::translate("MainWindow", "Comment", nullptr));
        sylCreateButton->setText(QApplication::translate("MainWindow", "Create Syllablle", nullptr));
        sylVariantButton->setText(QApplication::translate("MainWindow", "Add Variant", nullptr));
        sylFinishButton->setText(QApplication::translate("MainWindow", "Finish", nullptr));
        sylStaffLabel->setText(QApplication::translate("MainWindow", "Staff", nullptr));
        sylSourceLabel->setText(QApplication::translate("MainWindow", "Source", nullptr));
        sylSourceToolbutton->setText(QApplication::translate("MainWindow", "Choose", nullptr));
        sylStaffToolbutton->setText(QApplication::translate("MainWindow", "Choose", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(sylTab), QApplication::translate("MainWindow", "Syllable", nullptr));
        pitchPitchLabel->setText(QApplication::translate("MainWindow", "Pitch", nullptr));
        pitchOctaveLabel->setText(QApplication::translate("MainWindow", "Octave", nullptr));
        pitchCommentLabel->setText(QApplication::translate("MainWindow", "Comment", nullptr));
        pitchAddButton->setText(QApplication::translate("MainWindow", "Add Pitch", nullptr));
        pitchFinishButton->setText(QApplication::translate("MainWindow", "Finish", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(pitchTab), QApplication::translate("MainWindow", "Pitches", nullptr));
        adjustByHand->setText(QApplication::translate("MainWindow", "adjust by hand", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
