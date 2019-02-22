#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QTextCursor>
#include <QTextEdit>
#include <QCheckBox>
#include <QFile>
#include <QShortcut>
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

    void setup();

    Ui::MainWindow *ui;

    bool readOnly;

    QShortcut *up;
    QShortcut *down;

    QTextEdit *mainTextEdit;

    RenderWidget *renderWidget;

    QTabWidget *tabWidget;

    QWidget *metaTab;
    QLineEdit *titleLine;
    QLineEdit *composerLine;
    QLineEdit *authorLine1;
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
    QLineEdit *sourceLanguageLine;
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
    QPushButton *staffCreateButton;
    QPushButton *staffAddclefButton;
    QPushButton *staffFinishButton;
    QPushButton *staffNewstaffButton;
    QToolButton *staffLinecolorToolbutton;
    QToolButton *staffModeToolbutton;
    QToolButton *staffClefshapeToolbutton;
    QToolButton *staffCleflineToolbutton;
    QToolButton *staffLinecountToolbutton;
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
    QLineEdit *sylFilenameLine;
    QTextEdit *sylCommentText;
    QPushButton *sylCreateButton;
    QPushButton *sylFinishButton;
    QPushButton *sylSaveButton;
    QToolButton *sylSourceToolbutton;
    QToolButton *sylStaffToolbutton;
    QToolButton *sylTypeToolbutton;
    QString sylCurrentSource;
    QString sylCurrentStaff;
    QString sylFormerStaff = "";
    QLabel *sylValidatorLabel;

    Segment *segment;

    QWidget *varTab;
    QLabel *varSourceLabel;
    QToolButton *varConnectionToolbutton;
    QToolButton *varPitchToolbutton;
    QToolButton *varOctaveToolbutton;
    QToolButton *varPreviousToolbutton;
    QToolButton *varTiltToolbutton;
    QPushButton *varAddpitchButton;
    QPushButton *varNextButton;
    QTextEdit *varCommentText;
    int varCounter;
    bool varAdded = false;

    QWidget *pitchTab;
    QLineEdit *pitchOctaveLine;
    QLineEdit *pitchPitchLine;
    QToolButton *pitchPitchToolbutton;
    QToolButton *pitchOctaveToolbutton;
    QToolButton *pitchTiltToolbutton;
    QToolButton *pitchConnectionToolbutton;
    QToolButton *pitchPreviousToolbutton;
    QTextEdit *pitchCommentText;
    QPushButton *pitchAddButton;
    QPushButton *pitchFinishButton;
    QPushButton *pitchAddVariantButton;

    QList<QString*> modes;
    QList<QString*> pitches;
    QList<QString*> colors;
    QList<QString*> numbers;
    QList<QString*> types;
    QList<QString*> directions;
    QList<QString*> relations;
    QList<QString*> connections;
    QList<QString*> clefs;
    QList<QString*> IDs;

    QMenu *modeMenu;
    QMenu *pitchMenu;
    QMenu *colorMenu;
    QMenu *numberMenu;
    QMenu *typeMenu;
    QMenu *directionMenu;
    QMenu *relationMenu;
    QMenu *connectionMenu;
    QMenu *clefMenu;

    QString indent(int a);
    QString mutate(QString s);
    bool checkIDs(QString s);
    void sourcesToActions();
    void staffsToActions();
    void modesToActions();
    void pitchesToActions();
    void colorsToActions();
    void numbersToActions();
    void typesToActions();
    void directionsToActions();
    void relationsToActions();
    void connectionsToActions();
    void clefsToActions();
    void blankToActions(QMenu *menu, QList<QString*> list, void(MainWindow::*func)(), QList<QToolButton*> buttons);

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
    void onSylSave();
    void onAddPitch();
    void onFinishPitch();
    void onAddSyllable();
    void onVarAddpitch();
    void onVarAddpitch2();
    void onVarNext();
    void onVarNext2();
    void onSelectSource();
    void onSelectStaff();
    void onSelectMode();
    void onSelectPitch();
    void onSelectColor();
    void onSelectNumber();
    void onSelectType();
    void onSelectDirection();
    void onSelectRelation();
    void onSelectConnection();
    void onSelectClef();
    void onUp();
    void onDown();
};

#endif // MAINWINDOW_H
