#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    /*QMenu *menu = new QMenu();
    action = new QAction();
    test = new QString("test");

    qtFrameText = new QString(meiFrameText);
    qtHeaderText = new QString(meiHeaderText);

    action->setText(*test);
    menu->addAction(action);

    ui->toolButton->setMenu(menu);*/

    /*
    ui->setupUi(this);

    readOnly = true;

    mainTextEdit = ui->textEdit;
    mainTextEdit->setReadOnly(readOnly);
    mainTextEdit->setTabStopDistance(30); 

    tabWidget = ui->tabWidget;

    metaTab = ui->tabWidget->widget(0);
    titleLine = metaTab->findChild<QLineEdit*>("titleLine");
    composerLine = metaTab->findChild<QLineEdit*>("composerLine");
    authorLine1 = metaTab->findChild<QLineEdit*>("authorLine1");
    authorLine2 = metaTab->findChild<QLineEdit*>("authorLine2");
    languageLine = metaTab->findChild<QLineEdit*>("languageLine");
    availabilityText = metaTab->findChild<QTextEdit*>("availabilityText");
    commentsText = metaTab->findChild<QTextEdit*>("commentsText");
    keywordsLine = metaTab->findChild<QLineEdit*>("keywordsLine");

    sourcesTab = ui->tabWidget->widget(1);
    tabWidget->removeTab(1);
*/

    /*
    connect(action, &QAction::triggered, this, &MainWindow::slotActionTriggered);
    connect(ui->textEdit, &QTextEdit::cursorPositionChanged, this, &MainWindow::onTextChanged);
    connect(ui->toolButton, &QToolButton::triggered, this, &MainWindow::onButtonPush);
    */

    setup();

    connect(ui->metaButton, &QPushButton::clicked, this, &MainWindow::onMeta);
    connect(ui->adjustByHand, &QCheckBox::stateChanged, this, &MainWindow::onCheck);
    connect(sourceCreateButton, &QPushButton::clicked, this, &MainWindow::onCreateSource);
    connect(sourceAddButton, &QPushButton::clicked, this, &MainWindow::onAddSource);
    connect(sourceFinishButton, &QPushButton::clicked, this, &MainWindow::onFinishSource);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setup(){

    ui->setupUi(this);

    readOnly = true;

    mainTextEdit = ui->textEdit;
    mainTextEdit->setReadOnly(readOnly);
    mainTextEdit->setTabStopDistance(30);

    tabWidget = ui->tabWidget;

    metaTab = ui->tabWidget->widget(0);
    titleLine = metaTab->findChild<QLineEdit*>("titleLine");
    composerLine = metaTab->findChild<QLineEdit*>("composerLine");
    authorLine1 = metaTab->findChild<QLineEdit*>("authorLine1");
    authorLine2 = metaTab->findChild<QLineEdit*>("authorLine2");
    languageLine = metaTab->findChild<QLineEdit*>("languageLine");
    availabilityText = metaTab->findChild<QTextEdit*>("availabilityText");
    commentsText = metaTab->findChild<QTextEdit*>("commentsText");
    keywordsLine = metaTab->findChild<QLineEdit*>("keywordsLine");

    sourcesTab = ui->tabWidget->widget(1);
    sourceIDLine = sourcesTab->findChild<QLineEdit*>("sourceIDLine");
    sourceAuthorLine = sourcesTab->findChild<QLineEdit*>("sourceAuthorLine");
    sourceTitleLine = sourcesTab->findChild<QLineEdit*>("sourceTitleLine");
    sourcePubStatusLine = sourcesTab->findChild<QLineEdit*>("sourcePubStatusLine");
    sourceMediumLine = sourcesTab->findChild<QLineEdit*>("sourceMediumLine");
    sourceXLine = sourcesTab->findChild<QLineEdit*>("sourceXLine");
    sourceYLine = sourcesTab->findChild<QLineEdit*>("sourceYLine");
    sourceUnitLine = sourcesTab->findChild<QLineEdit*>("sourceUnitLine");
    sourceConditionLine = sourcesTab->findChild<QLineEdit*>("sourceConditionLine");
    sourceExtentLine = sourcesTab->findChild<QLineEdit*>("sourceExtentLine");
    sourceHandwritingText = sourcesTab->findChild<QTextEdit*>("sourceStyleText");
    sourceCreateButton = sourcesTab->findChild<QPushButton*>("sourceCreateButton");
    sourceAddButton = sourcesTab->findChild<QPushButton*>("sourceAddButton");
    sourceFinishButton = sourcesTab->findChild<QPushButton*>("sourceFinishButton");

    sourceAddButton->setDisabled(true);

    musicTab = ui->tabWidget->widget(2);

    tabWidget->removeTab(1);
    tabWidget->removeTab(1);

}

void MainWindow::onCheck(){
    readOnly = !readOnly;
    mainTextEdit->setReadOnly(readOnly);
}

/*
void MainWindow::slotActionTriggered(){
    ui->toolButton->setText(action->text());
}

void MainWindow::onTextChanged(){
    QString s = QVariant(ui->textEdit->textCursor().position()).toString();
    ui->toolButton->setText(s);
}

void MainWindow::onButtonPush(){
    ui->textEdit->textCursor().insertText(action->text());
}

void MainWindow::onCreateFrame(){
    QTextCursor cursor = ui->textEdit->textCursor();
    ui->textEdit->textCursor().insertText(*qtFrameText);
    cursor.setPosition(cursor.position()-7);
    ui->textEdit->setTextCursor(cursor);
}

void MainWindow::onCreateHeader(){
    QTextCursor cursor = ui->textEdit->textCursor();
    ui->textEdit->textCursor().insertText(*qtHeaderText);
    cursor.setPosition(cursor.position()-11);
    ui->textEdit->setTextCursor(cursor);
}
*/

void MainWindow::onMeta(){

    QString title = titleLine->text();
    QString composer = composerLine->text();
    QString author1 = authorLine1->text();
    QString author2 = authorLine2->text();
    QString language = languageLine->text();
    QString availability = availabilityText->toPlainText();
    QString comments = commentsText->toPlainText();
    QString keyword = keywordsLine->text();
    QStringList keywords = keyword.split(",");

    QString s;

    s += qtTextBeg; s += qtN;
    s += indent(1); s += qtHeaderBeg; s += qtN;
    s += indent(2); s += qtIdBeg; s += qtN;
    s += indent(3); s += title; s += qtN;
    s += indent(2); s += qtIdEnd; s += qtN;
    s += indent(2); s += qtFiledescriptionBeg; s += qtN;
    s += indent(3); s += qtTitlestmtBeg; s += qtN;
    s += indent(4); s += qtTitleBeg; s += qtN;
    s += indent(5); s += title; s += qtN;
    s += indent(4); s += qtTitleEnd; s += qtN;
    s += indent(4); s += qtResponsibilityBeg; s += qtN;
    s += indent(5); s += qtAgentBeg; s += qtN;
    s += indent(6);  s += composer; s += qtN;
    s += indent(5); s += qtAgentEnd; s += qtN;
    s += indent(4); s += qtResponsibilityEnd; s += qtN;
    s += indent(3); s += qtTitlestmtEnd; s += qtN;
    s += indent(3); s += qtPublicationBeg; s += qtN;
    s += indent(4); s += qtResponsibilityBeg; s += qtN;
    s += indent(5); s += qtAgentBeg; s += qtN;
    s += indent(6); s += author1; s += qtN;
    s += indent(5); s += qtAgentEnd; s += qtN;
    s += indent(5); s += qtAgentBeg; s += qtN;
    s += indent(6); s += author2; s += qtN;
    s += indent(5); s += qtAgentEnd; s += qtN;
    s += indent(4); s += qtResponsibilityEnd; s += qtN;
    s += indent(4); s += qtAvailabilityBeg; s += qtN;
    s += indent(5); s += qtUserestrictBeg; s += qtN;
    s += indent(6); s += availability; s += qtN;
    s += indent(5); s += qtUserestrictEnd; s += qtN;
    s += indent(4); s += qtAvailabilityEnd; s += qtN;
    s += indent(3); s += qtPublicationEnd; s += qtN;
    s += indent(2); s += qtFiledescriptionEnd; s += qtN;
    s += indent(2); s += qtEditorialdeclarationBeg; s += qtN;
    s += indent(3); s += qtParagraphBeg; s += qtN;
    s += indent(4); s += comments; s += qtN;
    s += indent(3); s += qtParagraphEnd; s += qtN;
    s += indent(2); s += qtEditorialdeclarationEnd; s += qtN;
    s += indent(2); s += qtProfiledescriptionBeg; s += qtN;
    s += indent(3); s += qtLangusageBeg; s += qtN;
    s += indent(4); s += qtLanguageBeg; s += qtN;
    s += indent(4); s += qtT; s += language; s += qtN;
    s += indent(4); s += qtLanguageEnd;  s += qtN;
    s += indent(3); s += qtLangusageEnd; s += qtN;
    s += indent(3); s += qtMusicclassBeg;  s += qtN;
    s += indent(4); s += qtKeywordsBeg; s += qtN;

    for(int i = 0; i < keywords.size(); i++){
        s += indent(5); s += qtTermBeg; s += qtN;
        s += indent(6); s += keywords[i]; s += qtN;
        s += indent(6); s += qtTermEnd; s += qtN;
    }

    s += indent(4); s += qtKeywordsEnd; s += qtN;
    s += indent(3); s += qtMusicclassEnd; s += qtN;
    s += indent(2); s += qtProfiledescriptionEnd; s += qtN;
    s += indent(1); s += qtHeaderEnd; s += qtN;
    s += qtTextEnd;

    mainTextEdit->textCursor().insertText(s);

    QTextCursor cursor = mainTextEdit->textCursor();
    cursor.setPosition(cursor.position()-19);
    mainTextEdit->setTextCursor(cursor);

    QString *sources = new QString("Sources");
    tabWidget->addTab(sourcesTab, *sources);
    tabWidget->removeTab(tabWidget->currentIndex());
}

void MainWindow::onCreateSource(){

    QString ID = sourceIDLine->text();
    QString author = sourceAuthorLine->text();
    QString title = sourceTitleLine->text();
    QString pubstatus = sourcePubStatusLine->text();
    QString medium  = sourceMediumLine->text();
    QString x = sourceXLine->text();
    QString y = sourceYLine->text();
    QString unit = sourceUnitLine->text();
    QString condition = sourceConditionLine->text();
    QString extent = sourceExtentLine->text();
    QString handwriting = sourceHandwritingText->toPlainText();

    QString s;

    s += indent(2); s += qtSourcedescriptionBeg; s += qtN;

    //example on checking for empty String, can be used for optional parameters
    if(ID.isEmpty()){
        s += indent(3); s += qtSourceBeg; s += qtN;
    }
    else{
       s += indent(3); s += qtSourceAttBeg; s += qtAttID; s += "\""; s += ID; s += "\""; s += qtClosingBracket; s += qtN;
    }

    s += indent(4); s += qtTitlestmtBeg; s += qtN;
    s += indent(5); s += qtTitleBeg; s += qtN;
    s += qtT; s += qtT; s += qtT; s += qtT; s += qtT; s += qtT; s += title; s += qtN;
    s += indent(5); s += qtTitleEnd; s += qtN;
    s += indent(5); s += qtResponsibilityBeg; s += qtN;
    s += indent(6); s += qtAgentBeg; s += qtN;
    s += indent(7); s += author; s += qtN;
    s += indent(6); s += qtAgentEnd; s += qtN;
    s += indent(5); s += qtResponsibilityEnd; s += qtN;
    s += indent(4); s += qtTitlestmtEnd; s += qtN;
    s += indent(4); s += qtPublicationBeg; s += qtN;
    s += indent(5); s += qtPubstatusBeg; s += qtN;
    s += indent(6); s += pubstatus; s += qtN;
    s += indent(5); s += qtPubstatusEnd; s += qtN;
    s += indent(4); s += qtPublicationEnd; s += qtN;
    s += indent(4); s += qtPhysdescriptionEnd; s += qtN;
    s += indent(5); s += qtExtentBeg; s += qtN;
    s += indent(6); s += extent; s += qtN;
    s += indent(5); s += qtExtentEnd; s += qtN;
    s += indent(5); s += qtPhysmediumBeg; s += qtN;
    s += indent(6); s += medium; s += qtN;
    s += indent(5); s += qtPhysmediumEnd; s += qtN;
    s += indent(5); s += qtDimensionsAttBeg; s += qtAttUnits; s += "\""; s += unit; s += "\""; s += qtClosingBracket; s += qtN;
    s += indent(6); s += x; s += " x "; s += y; s += unit; s += qtN;
    s += indent(5); s += qtDimensionsEnd; s += qtN;
    s += indent(5); s += qtConditionBeg; s += qtN;
    s += indent(6); s += condition; s += qtN;
    s += indent(5); s += qtConditionEnd; s += qtN;
    s += indent(5); s += qtProvenanceBeg; s += qtN;
    s += indent(6); s += qtCorpnameBeg; s += qtN;
    s += indent(7); s += "test"; s += qtN; // add additional field in ui!!
    s += indent(6); s += qtCorpnameEnd; s += qtN;
    s += indent(5); s += qtProvenanceEnd; s += qtN;
    s += indent(4); s += qtPhysdescriptionEnd; s += qtN;
    s += indent(4); s += qtHandlistBeg; s += qtN;
    s += indent(5); s += qtHandAttBeg; s += qtAttCharacter; s += "\""; s += handwriting; s += "\""; s += "/"; s += qtClosingBracket; s += qtN; // add additional attributes!!
    s += indent(4); s += qtHandlistEnd; s += qtN;
    s += indent(3); s += qtSourceEnd; s += qtN;
    s += indent(2); s += qtSourcedescriptionEnd;// s += qtN;

    mainTextEdit->textCursor().insertText(s);

    QTextCursor cursor = mainTextEdit->textCursor();
    cursor.setPosition(cursor.position()-15);
    mainTextEdit->setTextCursor(cursor);

    sourceCreateButton->setDisabled(true);

    sourceAddButton->setDisabled(false);

}

void MainWindow::onAddSource(){
    QString ID = sourceIDLine->text();
    QString author = sourceAuthorLine->text();
    QString title = sourceTitleLine->text();
    QString pubstatus = sourcePubStatusLine->text();
    QString medium  = sourceMediumLine->text();
    QString x = sourceXLine->text();
    QString y = sourceYLine->text();
    QString unit = sourceUnitLine->text();
    QString condition = sourceConditionLine->text();
    QString extent = sourceExtentLine->text();
    QString handwriting = sourceHandwritingText->toPlainText();

    QString s;

    if(ID.isEmpty()){
        s += indent(3); s += qtSourceBeg; s += qtN;
    }
    else{
       s += indent(3); s += qtSourceAttBeg; s += qtAttID; s += "\""; s += ID; s += "\""; s += qtClosingBracket; s += qtN;
    }

    s += indent(4); s += qtTitlestmtBeg; s += qtN;
    s += indent(5); s += qtTitleBeg; s += qtN;
    s += qtT; s += qtT; s += qtT; s += qtT; s += qtT; s += qtT; s += title; s += qtN;
    s += indent(5); s += qtTitleEnd; s += qtN;
    s += indent(5); s += qtResponsibilityBeg; s += qtN;
    s += indent(6); s += qtAgentBeg; s += qtN;
    s += indent(7); s += author; s += qtN;
    s += indent(6); s += qtAgentEnd; s += qtN;
    s += indent(5); s += qtResponsibilityEnd; s += qtN;
    s += indent(4); s += qtTitlestmtEnd; s += qtN;
    s += indent(4); s += qtPublicationBeg; s += qtN;
    s += indent(5); s += qtPubstatusBeg; s += qtN;
    s += indent(6); s += pubstatus; s += qtN;
    s += indent(5); s += qtPubstatusEnd; s += qtN;
    s += indent(4); s += qtPublicationEnd; s += qtN;
    s += indent(4); s += qtPhysdescriptionEnd; s += qtN;
    s += indent(5); s += qtExtentBeg; s += qtN;
    s += indent(6); s += extent; s += qtN;
    s += indent(5); s += qtExtentEnd; s += qtN;
    s += indent(5); s += qtPhysmediumBeg; s += qtN;
    s += indent(6); s += medium; s += qtN;
    s += indent(5); s += qtPhysmediumEnd; s += qtN;
    s += indent(5); s += qtDimensionsAttBeg; s += qtAttUnits; s += "\""; s += unit; s += "\""; s += qtClosingBracket; s += qtN;
    s += indent(6); s += x; s += " x "; s += y; s += unit; s += qtN;
    s += indent(5); s += qtDimensionsEnd; s += qtN;
    s += indent(5); s += qtConditionBeg; s += qtN;
    s += indent(6); s += condition; s += qtN;
    s += indent(5); s += qtConditionEnd; s += qtN;
    s += indent(5); s += qtProvenanceBeg; s += qtN;
    s += indent(6); s += qtCorpnameBeg; s += qtN;
    s += indent(7); s += "test"; s += qtN; // add additional field in ui!!
    s += indent(6); s += qtCorpnameEnd; s += qtN;
    s += indent(5); s += qtProvenanceEnd; s += qtN;
    s += indent(4); s += qtPhysdescriptionEnd; s += qtN;
    s += indent(4); s += qtHandlistBeg; s += qtN;
    s += indent(5); s += qtHandAttBeg; s += qtAttCharacter; s += "\""; s += handwriting; s += "\""; s += "/"; s += qtClosingBracket; s += qtN; // add additional attributes!!
    s += indent(4); s += qtHandlistEnd; s += qtN;
    s += indent(3); s += qtSourceEnd; s += qtN;

    mainTextEdit->textCursor().insertText(s);
}

void MainWindow::onFinishSource(){

    QTextCursor cursor = mainTextEdit->textCursor();
    cursor.setPosition(cursor.position()+28);
    mainTextEdit->setTextCursor(cursor);

    QString *music = new QString("Music");
    tabWidget->addTab(musicTab, *music);
    tabWidget->removeTab(tabWidget->currentIndex());
}

QString MainWindow::indent(int a){
    QString s;
    for(int i = 0; i < a; i++){
        s += qtT;
    }
    return s;
}
