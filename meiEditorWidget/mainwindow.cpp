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

    /*
    RenderWidget *widget = ui->widget;
    Segment *seg = new Segment();
    widget->addSegment(seg);
    widget->update();
    */

    connect(ui->metaButton, &QPushButton::clicked, this, &MainWindow::onMeta);
    connect(ui->adjustByHand, &QCheckBox::stateChanged, this, &MainWindow::onCheck);
    connect(sourceCreateButton, &QPushButton::clicked, this, &MainWindow::onCreateSource);
    connect(sourceAddButton, &QPushButton::clicked, this, &MainWindow::onAddSource);
    connect(sourceFinishButton, &QPushButton::clicked, this, &MainWindow::onFinishSource);
    connect(staffCreateButton, &QPushButton::clicked, this, &MainWindow::onCreateStaff);
    connect(staffAddclefButton, &QPushButton::clicked, this, &MainWindow::onAddclefStaff);
    connect(staffFinishButton, &QPushButton::clicked, this, &MainWindow::onFinishStaff);
    connect(sylCreateButton, &QPushButton::clicked, this, &MainWindow::onCreateSyllable);
    connect(pitchAddButton, &QPushButton::clicked, this, &MainWindow::onAddPitch);
    connect(pitchFinishButton, &QPushButton::clicked, this, &MainWindow::onFinishPitch);
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
    mainTextEdit->setTabStopDistance(10);

    //openGLWidget = new MyGLWidget(this);
    //ui->openGLWidget->parentWidget()->layout()->replaceWidget(ui->openGLWidget, openGLWidget);

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

    genericSource = new QString("source");
    sourceCounter = 0;

    sourcesAdded = false;

    sourceAddButton->setDisabled(true);
    sourceFinishButton->setDisabled(true);

    staffTab = ui->tabWidget->widget(2);
    staffIDLine = staffTab->findChild<QLineEdit*>("staffIDLine");
    staffLinecountLine = staffTab->findChild<QLineEdit*>("staffLinecountLine");
    staffCleflineLine = staffTab->findChild<QLineEdit*>("staffCleflineLine");
    staffClefshapeLine = staffTab->findChild<QLineEdit*>("staffClefshapeLine");
    staffCreateButton = staffTab->findChild<QPushButton*>("staffCreateButton");
    staffAddclefButton = staffTab->findChild<QPushButton*>("staffAddclefButton");
    staffFinishButton = staffTab->findChild<QPushButton*>("staffFinishButton");

    genericStaff = new QString("staff");
    staffCounter = 0;

    staffAdded = false;

    staffAddclefButton->setDisabled(true);
    staffFinishButton->setDisabled(true);

    sylTab = ui->tabWidget->widget(3);
    sylPageLine = sylTab->findChild<QLineEdit*>("sylPageLine");
    sylLineLine = sylTab->findChild<QLineEdit*>("sylLineLine");
    sylSyllableLine = sylTab->findChild<QLineEdit*>("sylSyllableLine");
    sylCommentText = sylTab->findChild<QTextEdit*>("sylCommentText");
    sylCreateButton = sylTab->findChild<QPushButton*>("sylCreateButton");
    //sylAddButton = sylTab->findChild<QPushButton*>("sylAddButton");
    sylVariantButton = sylTab->findChild<QPushButton*>("sylVariantButton");
    sylFinishButton = sylTab->findChild<QPushButton*>("sylFinishButton");
    sylSourceToolbutton = sylTab->findChild<QToolButton*>("sylSourceToolbutton");
    sylStaffToolbutton = sylTab->findChild<QToolButton*>("sylStaffToolbutton");

    sylCreateButton->setDisabled(true);
    //sylAddButton->setDisabled(true);

    pitchTab = ui->tabWidget->widget(4);
    pitchOctaveLine = pitchTab->findChild<QLineEdit*>("pitchOctaveLine");
    pitchPitchLine = pitchTab->findChild<QLineEdit*>("pitchPitchLine");
    pitchCommentText = pitchTab->findChild<QTextEdit*>("pitchCommentText");
    pitchAddButton = pitchTab->findChild<QPushButton*>("pitchAddButton");
    pitchFinishButton = pitchTab->findChild<QPushButton*>("pitchFinishButton");

    tabWidget->removeTab(1);
    tabWidget->removeTab(1);
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
        s += indent(5); s += qtTermEnd; s += qtN;
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

    sourcesAdded = true;

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

    s += qtN;
    s += indent(2); s += qtSourcedescriptionBeg; s += qtN;

    //example on checking for empty String, can be used for optional parameters
    if(ID.isEmpty()){
       ID += genericSource; ID += QString::number(sourceCounter);
       s += indent(3); s += qtSourceAttBeg; s += qtAttID; s += "\""; s += ID; s += "\""; s += qtClosingBracket; s += qtN;

       sourceCounter++;
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
    sourceFinishButton->setDisabled(false);

    sources.append(ID);
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
       ID += genericSource; ID += QString::number(sourceCounter);
       s += indent(3); s += qtSourceAttBeg; s += qtAttID; s += "\""; s += ID; s += "\""; s += qtClosingBracket; s += qtN;

       sourceCounter++;
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

    sources.push_back(ID);
}

void MainWindow::onFinishSource(){


    if(sourcesAdded){
        QTextCursor cursor = mainTextEdit->textCursor();
        cursor.setPosition(cursor.position()+28);
        mainTextEdit->setTextCursor(cursor);

    }
    else {
        QTextCursor cursor = mainTextEdit->textCursor();
        cursor.setPosition(cursor.position()+13);
        mainTextEdit->setTextCursor(cursor);

    }

    sourcesToActions();

    QString *staff = new QString("Staff");
    tabWidget->addTab(staffTab, *staff);
    tabWidget->removeTab(tabWidget->currentIndex());
}

void MainWindow::onCreateStaff(){

    staffAdded = true;

    QString ID = staffIDLine->text();
    QString linecount = staffLinecountLine->text();

    QString s;

    s += indent(1); s += qtWorkBeg; s += qtN;
    s += indent(2); s += qtMusicBeg; s += qtN;
    s += indent(3); s += qtMdivBeg; s += qtN;
    s += indent(4); s += qtScoreBeg; s += qtN;
    s += indent(5); s += qtScoredefBeg; s += qtN;
    s += indent(6); s += qtStaffgrpAttBeg; s += qtAttID; s += "\"all\""; s += qtClosingBracket; s += qtN;
    if(ID.isEmpty()){
        ID += genericStaff; ID +=  QString::number(staffCounter);
        s += indent(7); s += qtStaffdefAttBeg; s += qtAttDef; s += "\""; s += ID; s += "\"";
        staffCounter++;
    }
    else{
        s += indent(7); s += qtStaffdefAttBeg; s += qtAttDef; s += "\""; s += ID; s += "\"";
    }
    s += qtAttLines; s += "\""; s += linecount; s += "\"";  s += qtClosingBracket; s += qtN;
    s += indent(7); s += qtStaffdefEnd; s += qtN;
    s += indent(6); s += qtStaffgrpEnd; s += qtN;
    s += indent(5); s += qtScoredefEnd; s += qtN;
    s += indent(4); s += qtScoreEnd; s += qtN;
    s += indent(3); s += qtMdivEnd; s += qtN;
    s += indent(2); s += qtMusicEnd; s += qtN;
    s += indent(1); s += qtWorkEnd; s += qtN;

    staffAddclefButton->setDisabled(false);
    staffCreateButton->setDisabled(true);
    staffFinishButton->setDisabled(false);

    mainTextEdit->textCursor().insertText(s);

    QTextCursor cursor = mainTextEdit->textCursor();
    cursor.setPosition(cursor.position()-98);
    mainTextEdit->setTextCursor(cursor);

    staffs.push_back(ID);
}

void MainWindow::onAddclefStaff(){

    QString line = staffCleflineLine->text();
    QString shape = staffClefshapeLine->text();

    QString s;

    s += indent(8); s += qtClefAttBeg;
    s += qtAttLine; s += "\""; s += line; s += "\"";
    s += qtAttShape; s += "\""; s += shape; s += "\"";
    s += qtClosingBracket; s += qtN;

    mainTextEdit->textCursor().insertText(s);
}

void MainWindow::onFinishStaff(){

    if(staffAdded){
        QTextCursor cursor = mainTextEdit->textCursor();
        cursor.setPosition(cursor.position()+54);
        mainTextEdit->setTextCursor(cursor);

    }
    else {
        QTextCursor cursor = mainTextEdit->textCursor();
        cursor.setPosition(cursor.position()+13);
        mainTextEdit->setTextCursor(cursor);

    }

    staffsToActions();

    QString *syllable = new QString("Syllable");
    tabWidget->addTab(sylTab, *syllable);
    tabWidget->removeTab(tabWidget->currentIndex());
}

void MainWindow::onCreateSyllable(){

    QString page = sylPageLine->text();
    QString line = sylLineLine->text();
    QString syl = sylSyllableLine->text();
    QString comment = sylCommentText->toPlainText();


    QString s;

    s += indent(5); s += qtSectionBeg; s += qtN;
    s += indent(6); s += qtStaffAttBeg;
    s += qtAttSource; s += "\""; s += sylCurrentSource; s += "\"";
    s += qtAttDef; s += "\""; s += sylCurrentStaff; s += "\"";
    s += qtClosingBracket; s += qtN;
    if(!page.isEmpty()){
        s += indent(7); s += qtPbAttBeg; s += qtAttN; s += "\""; s += page; s += "\""; s += "/"; s += qtClosingBracket; s+= qtN;
    }
    if(!line.isEmpty()){
        s += indent(7); s += qtSbAttBeg; s += qtAttN; s += "\""; s += line; s += "\""; s += "/"; s += qtClosingBracket; s+= qtN;
    }
    if(!comment.isEmpty()){
        s += indent(7); s += qtAnnotAttBeg; s += qtAttStaff; s += "\""; s += sylCurrentStaff; s += "\""; s += "/"; s += qtClosingBracket; s+= qtN;
        s += indent(8); s += qtParagraphBeg; s+= qtN;
        s += indent(9); s += comment; s+= qtN;
        s += indent(8); s += qtParagraphEnd; s+= qtN;
        s += indent(7); s += qtAnnotEnd; s+= qtN;
    }
    s += indent(7); s += qtSyllableBeg; s+= qtN;
    s += indent(8); s += qtSylBeg; s+= qtN;
    s += indent(9); s += syl; s += qtN;
    s += indent(8); s += qtSylEnd; s += qtN;
    s += indent(7); s += qtSyllableEnd;  s+= qtN;
    s += indent(6); s += qtStaffEnd; s += qtN;
    s += indent(5); s += qtSectionEnd; s += qtN;

    mainTextEdit->textCursor().insertText(s);

    QTextCursor cursor = mainTextEdit->textCursor();
    cursor.setPosition(cursor.position()-50);
    mainTextEdit->setTextCursor(cursor);

    disconnect(sylCreateButton, &QPushButton::clicked, this, &MainWindow::onCreateSyllable);
    connect(sylCreateButton, &QPushButton::clicked, this, &MainWindow::onAddSyllable);

    QString *pitch = new QString("Pitch");
    tabWidget->addTab(pitchTab, *pitch);
    tabWidget->removeTab(tabWidget->currentIndex());
}

void MainWindow::onAddSyllable(){
    QString page = sylPageLine->text();
    QString line = sylLineLine->text();
    QString syl = sylSyllableLine->text();
    QString comment = sylCommentText->toPlainText();


    QString s;

    if(!page.isEmpty()){
        s += indent(7); s += qtPbAttBeg; s += qtAttN; s += "\""; s += page; s += "\""; s += "/"; s += qtClosingBracket; s+= qtN;
    }
    if(!line.isEmpty()){
        s += indent(7); s += qtSbAttBeg; s += qtAttN; s += "\""; s += line; s += "\""; s += "/"; s += qtClosingBracket; s+= qtN;
    }
    if(!comment.isEmpty()){
        s += indent(7); s += qtAnnotAttBeg; s += qtAttStaff; s += "\""; s += sylCurrentStaff; s += "\""; s += "/"; s += qtClosingBracket; s+= qtN;
        s += indent(8); s += qtParagraphBeg; s+= qtN;
        s += indent(9); s += comment; s+= qtN;
        s += indent(8); s += qtParagraphEnd; s+= qtN;
        s += indent(7); s += qtAnnotEnd; s+= qtN;
    }
    s += indent(7); s += qtSyllableBeg; s+= qtN;
    s += indent(8); s += qtSylBeg; s+= qtN;
    s += indent(9); s += syl; s += qtN;
    s += indent(8); s += qtSylEnd; s += qtN;
    s += indent(7); s += qtSyllableEnd;  s+= qtN;

    mainTextEdit->textCursor().insertText(s);

    QTextCursor cursor = mainTextEdit->textCursor();
    cursor.setPosition(cursor.position()-19);
    mainTextEdit->setTextCursor(cursor);

    QString *pitch = new QString("Pitch");
    tabWidget->addTab(pitchTab, *pitch);
    tabWidget->removeTab(tabWidget->currentIndex());
}

void MainWindow::onAddVariant(){

}

void MainWindow::onFinishSyllable(){

}

void MainWindow::onAddPitch(){

    QString pitch = pitchPitchLine->text();
    QString octave = pitchOctaveLine->text();
    QString comment = pitchCommentText->toPlainText();

    QString s;

    if(!comment.isEmpty()){
        s += indent(8); s += qtAnnotAttBeg; s += qtAttStaff; s += "\""; s += sylCurrentStaff; s += "\""; s += "/"; s += qtClosingBracket; s+= qtN;
        s += indent(9); s += qtParagraphBeg; s+= qtN;
        s += indent(10); s += comment; s+= qtN;
        s += indent(9); s += qtParagraphEnd; s+= qtN;
        s += indent(8); s += qtAnnotEnd; s+= qtN;
    }
    s += indent(8); s += qtNcAttBeg;
    s += qtAttOct; s += "\""; s += octave; s += "\"";
    s += qtAttPname; s += "\""; s += pitch; s += "\"";
    s += qtClosingBracket; s += qtN;

    mainTextEdit->textCursor().insertText(s);
}

void MainWindow::onFinishPitch(){

    QString *syllable = new QString("Syllable");
    tabWidget->addTab(sylTab, *syllable);
    tabWidget->removeTab(tabWidget->currentIndex());

    QTextCursor cursor = mainTextEdit->textCursor();
    cursor.setPosition(cursor.position()+19);
    mainTextEdit->setTextCursor(cursor);
}

void MainWindow::onSelectSource(){
    QObject *sender = QObject::sender();
    QAction *action = qobject_cast<QAction*>(sender);
    sylCurrentSource = action->text();
    sylSourceToolbutton->setText(sylCurrentSource);

    if(!sylCurrentSource.isEmpty() && !sylCurrentStaff.isEmpty()){
        sylCreateButton->setDisabled(false);
        //sylAddButton->setDisabled(false);
    }
}

void MainWindow::onSelectStaff(){
    QObject *sender = QObject::sender();
    QAction *action = qobject_cast<QAction*>(sender);
    sylCurrentStaff = action->text();
    sylStaffToolbutton->setText(sylCurrentStaff);

    if(!sylCurrentSource.isEmpty() && !sylCurrentStaff.isEmpty()){
        sylCreateButton->setDisabled(false);
        //sylAddButton->setDisabled(false);
    }
}

QString MainWindow::indent(int a){
    QString s;
    for(int i = 0; i < a; i++){
        s += qtT;
    }
    return s;
}

void MainWindow::sourcesToActions(){

    sourcesMenu = new QMenu();
    for(int i = 0; i < sources.size(); i++){
        QAction *action = new QAction();
        action->setText(sources[i]);
        connect(action, &QAction::triggered, this, &MainWindow::onSelectSource);
        sourcesMenu->addAction(action);
    }

    sylSourceToolbutton->setMenu(sourcesMenu);
}

void MainWindow::staffsToActions(){

    staffMenu = new QMenu();
    for(int i = 0; i < staffs.size(); i++){
        QAction *action = new QAction();
        action->setText(staffs[i]);
        connect(action, &QAction::triggered, this, &MainWindow::onSelectStaff);
        staffMenu->addAction(action);
    }

    sylStaffToolbutton->setMenu(staffMenu);
}

