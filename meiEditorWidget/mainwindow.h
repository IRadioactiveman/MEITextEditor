#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QTextCursor>
#include <QTextEdit>
#include <QCheckBox>
#include <QXmlSchema>
#include <QXmlSchemaValidator>
#include <QFile>
#include "qttext.h"
#include "xmltext.h"
#include "ui_mainwindow.h"
#include <QTextCursor>
#include <QLineEdit>
#include <memory>
#include "renderwidget.h"
using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    //QAction *action;
    //QString *test;

    //QString *qtFrameText;
    //QString *qtHeaderText;
    void setup();

    Ui::MainWindow *ui;

    bool readOnly;

    /*
    QUrl *url;
    QXmlSchema schema;
    QXmlSchemaValidator validator;
    */

    QTextEdit *mainTextEdit;

    RenderWidget *renderWidget;

    QTabWidget *tabWidget;

    QWidget *metaTab;
    QLineEdit *titleLine;
    QLineEdit *composerLine;
    QLineEdit *authorLine1;
    QLineEdit *languageLine;
    QTextEdit *availabilityText;
    QTextEdit *commentsText;
    QLineEdit *keywordsLine;

    QWidget *sourcesTab;
    QLineEdit *sourceIDLine;
    QLineEdit *sourceAuthorLine;
    QLineEdit *sourceTitleLine;
    QLineEdit *sourcePhysicallocationLine;
    QLineEdit *sourceOwnershipLine;
    QLineEdit *sourceDateLine;
    QLineEdit *sourcePubStatusLine;
    QLineEdit *sourceMediumLine;
    QLineEdit *sourceXLine;
    QLineEdit *sourceYLine;
    QLineEdit *sourceUnitLine;
    QLineEdit *sourceConditionLine;
    QLineEdit *sourceExtentLine;
    QTextEdit *sourceHandwritingText;
    QPushButton *sourceCreateButton;
    QPushButton *sourceAddButton;
    QPushButton *sourceFinishButton;
    bool sourcesAdded;
    QString *genericSource;
    int sourceCounter;
    QList<QString> sources;
    QMenu *sourcesMenu;

    QWidget *staffTab;
    QLineEdit *staffIDLine;
    QLineEdit *staffLinecountLine;
    QLineEdit *staffCleflineLine;
    QLineEdit *staffClefshapeLine;
    QPushButton *staffCreateButton;
    QPushButton *staffAddclefButton;
    QPushButton *staffFinishButton;
    QPushButton *staffNewstaffButton;
    QToolButton *staffLinecolorToolbutton;
    QToolButton *staffModeToolbutton;
    bool staffAdded;
    QString *genericStaff;
    int staffCounter;
    int staffNCounter = 0;
    QList<QString> staffs;
    QMenu *staffMenu;

    QWidget *sylTab;
    QLineEdit *sylPageLine;
    QLineEdit *sylLineLine;
    QLineEdit *sylSyllableLine;
    QTextEdit *sylCommentText;
    QPushButton *sylCreateButton;
    QPushButton *sylAddButton;
    QPushButton *sylVariantButton;
    QPushButton *sylFinishButton;
    QToolButton *sylSourceToolbutton;
    QToolButton *sylStaffToolbutton;
    QToolButton *sylTypeToolbutton;
    QString sylCurrentSource;
    QString sylCurrentStaff;
    QLabel *sylValidatorLabel;

    Segment *segment;

    QWidget *pitchTab;
    QLineEdit *pitchOctaveLine;
    QLineEdit *pitchPitchLine;
    QToolButton *pitchPitchToolbutton;
    QToolButton *pitchOctaveToolbutton;
    QTextEdit *pitchCommentText;
    QPushButton *pitchAddButton;
    QPushButton *pitchFinishButton;

    QList<QString*> modes;
    QList<QString*> pitches;
    QList<QString*> colors;
    QList<QString*> numbers;
    QList<QString*> types;

    QMenu *modeMenu;
    QMenu *pitchMenu;
    QMenu *colorMenu;
    QMenu *numberMenu;
    QMenu *typeMenu;

    QString indent(int a);
    void sourcesToActions();
    void staffsToActions();
    void modesToActions();
    void pitchesToActions();
    void colorsToActions();
    void numbersToActions();
    void typesToActions();

private slots:
    void onCheck();
    void onMeta();
    void onCreateSource();
    void onAddSource();
    void onFinishSource();
    void onCreateStaff();
    void onAddStaff();
    void onAddclefStaff();
    void onAddNewStaff();
    void onFinishStaff();
    void onCreateSyllable();
    void onAddVariant();
    void onFinishSyllable();
    void onAddPitch();
    void onFinishPitch();
    void onAddSyllable();
    void onSelectSource();
    void onSelectStaff();
    void onSelectMode();
    void onSelectPitch();
    void onSelectColor();
    void onSelectNumber();
    void onSelectType();
};

#endif // MAINWINDOW_H
