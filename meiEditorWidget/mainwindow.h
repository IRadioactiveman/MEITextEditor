#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QTextCursor>
#include <QTextEdit>
#include <QCheckBox>
#include "qttext.h"
#include "xmltext.h"
#include "ui_mainwindow.h"
#include <QTextCursor>
#include <QLineEdit>
#include <memory>
#include "myglwidget.h"
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

    QTextEdit *mainTextEdit;

    //QOpenGLWidget * openGLWidget;

    QTabWidget *tabWidget;

    QWidget *metaTab;
    QLineEdit *titleLine;
    QLineEdit *composerLine;
    QLineEdit *authorLine1;
    QLineEdit *authorLine2;
    QLineEdit *languageLine;
    QTextEdit *availabilityText;
    QTextEdit *commentsText;
    QLineEdit *keywordsLine;

    QWidget *sourcesTab;
    QLineEdit *sourceIDLine;
    QLineEdit *sourceAuthorLine;
    QLineEdit *sourceTitleLine;
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
    bool staffAdded;
    QString *genericStaff;
    int staffCounter;
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
    QString sylCurrentSource;
    QString sylCurrentStaff;

    QWidget *pitchTab;
    QLineEdit *pitchOctaveLine;
    QLineEdit *pitchPitchLine;
    QTextEdit *pitchCommentText;
    QPushButton *pitchAddButton;
    QPushButton *pitchFinishButton;

    QString indent(int a);
    void sourcesToActions();
    void staffsToActions();

private slots:
    void onCheck();
    void onMeta();
    void onCreateSource();
    void onAddSource();
    void onFinishSource();
    void onCreateStaff();
    void onAddclefStaff();
    void onFinishStaff();
    void onCreateSyllable();
    void onAddVariant();
    void onFinishSyllable();
    void onAddPitch();
    void onFinishPitch();
    void onAddSyllable();
    void onSelectSource();
    void onSelectStaff();

    /*
    void slotActionTriggered();
    void onTextChanged();
    void onButtonPush();
    void onCreateFrame();
    void onCreateHeader();
    */
};

#endif // MAINWINDOW_H
