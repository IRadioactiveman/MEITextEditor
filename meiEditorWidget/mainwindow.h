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

    QWidget *musicTab;



    QString indent(int a);


private slots:
    void onCheck();
    void onMeta();
    void onCreateSource();
    void onAddSource();
    void onFinishSource();

    /*
    void slotActionTriggered();
    void onTextChanged();
    void onButtonPush();
    void onCreateFrame();
    void onCreateHeader();
    */
};

#endif // MAINWINDOW_H
