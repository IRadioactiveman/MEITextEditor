#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    setup();

    connect(ui->metaButton, &QPushButton::clicked, this, &MainWindow::onMeta);
    connect(ui->adjustByHand, &QCheckBox::stateChanged, this, &MainWindow::onCheck);
    connect(sourceCreateButton, &QPushButton::clicked, this, &MainWindow::onCreateSource);
    connect(sourceAddButton, &QPushButton::clicked, this, &MainWindow::onAddSource);
    connect(sourceFinishButton, &QPushButton::clicked, this, &MainWindow::onFinishSource);
    connect(staffCreateButton, &QPushButton::clicked, this, &MainWindow::onCreateStaff);
    connect(staffAddclefButton, &QPushButton::clicked, this, &MainWindow::onAddclefStaff);
    connect(staffNewstaffButton, &QPushButton::clicked, this, &MainWindow::onAddNewStaff);
    connect(staffFinishButton, &QPushButton::clicked, this, &MainWindow::onFinishStaff);
    connect(sylCreateButton, &QPushButton::clicked, this, &MainWindow::onCreateSyllable);
    connect(sylFinishButton, &QPushButton::clicked, this, &MainWindow::onFinishSyllable);
    connect(pitchAddVariantButton, &QPushButton::clicked, this, &MainWindow::onAddVariant);
    connect(sylSaveButton, &QPushButton::clicked, this, &MainWindow::onSylSave);
    connect(varAddpitchButton, &QPushButton::clicked, this, &MainWindow::onVarAddpitch);
    connect(varNextButton, &QPushButton::clicked, this, &MainWindow::onVarNext);
    connect(pitchAddButton, &QPushButton::clicked, this, &MainWindow::onAddPitch);
    connect(pitchFinishButton, &QPushButton::clicked, this, &MainWindow::onFinishPitch);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setup()
{
    ui->setupUi(this);

    //ui->adjustByHand->setDisabled(true);

    readOnly = true;

    mainTextEdit = ui->textEdit;
    mainTextEdit->setReadOnly(readOnly);
    mainTextEdit->setTabStopDistance(10);

    up = new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_W), this);
    down = new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_S), this);

    renderWidget = ui->renderWidget;

    tabWidget = ui->tabWidget;

    metaTab = ui->tabWidget->widget(0);
    titleLine = metaTab->findChild<QLineEdit*>("titleLine");
    composerLine = metaTab->findChild<QLineEdit*>("composerLine");
    authorLine1 = metaTab->findChild<QLineEdit*>("authorLine1");
    availabilityText = metaTab->findChild<QTextEdit*>("availabilityText");
    commentsText = metaTab->findChild<QTextEdit*>("commentsText");

    sourcesTab = ui->tabWidget->widget(1);
    sourceIDLine = sourcesTab->findChild<QLineEdit*>("sourceIDLine");
    sourceAuthorLine = sourcesTab->findChild<QLineEdit*>("sourceAuthorLine");
    sourceTitleLine = sourcesTab->findChild<QLineEdit*>("sourceTitleLine");
    sourcePhysicallocationLine = sourcesTab->findChild<QLineEdit*>("sourcePhysicallocationLine");
    sourceOwnershipLine = sourcesTab->findChild<QLineEdit*>("sourceOwnershipLine");
    sourceDateLine = sourcesTab->findChild<QLineEdit*>("sourceDateLine");
    sourcePubStatusLine = sourcesTab->findChild<QLineEdit*>("sourcePubStatusLine");
    sourceMediumLine = sourcesTab->findChild<QLineEdit*>("sourceMediumLine");
    sourceXLine = sourcesTab->findChild<QLineEdit*>("sourceXLine");
    sourceYLine = sourcesTab->findChild<QLineEdit*>("sourceYLine");
    sourceUnitLine = sourcesTab->findChild<QLineEdit*>("sourceUnitLine");
    sourceConditionLine = sourcesTab->findChild<QLineEdit*>("sourceConditionLine");
    sourceExtentLine = sourcesTab->findChild<QLineEdit*>("sourceExtentLine");
    sourceLanguageLine = sourcesTab->findChild<QLineEdit*>("sourceLanguageLine");
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
    staffLinecountToolbutton = staffTab->findChild<QToolButton*>("staffLinecountToolbutton");
    staffCleflineToolbutton = staffTab->findChild<QToolButton*>("staffCleflineToolbutton");
    staffClefshapeToolbutton = staffTab->findChild<QToolButton*>("staffClefshapeToolbutton");
    staffCreateButton = staffTab->findChild<QPushButton*>("staffCreateButton");
    staffAddclefButton = staffTab->findChild<QPushButton*>("staffAddclefButton");
    staffFinishButton = staffTab->findChild<QPushButton*>("staffFinishButton");
    staffNewstaffButton = staffTab->findChild<QPushButton*>("staffNewstaffButton");
    staffLinecolorToolbutton = staffTab->findChild<QToolButton*>("staffLinecolorToolbutton");
    staffModeToolbutton = staffTab->findChild<QToolButton*>("staffModeToolbutton");

    genericStaff = new QString("staff");
    staffCounter = 0;

    staffAdded = false;

    staffCleflineToolbutton->setDisabled(true);
    staffClefshapeToolbutton->setDisabled(true);
    staffAddclefButton->setDisabled(true);
    staffFinishButton->setDisabled(true);
    staffNewstaffButton->setDisabled(true);

    sylTab = ui->tabWidget->widget(3);
    sylPageLine = sylTab->findChild<QLineEdit*>("sylPageLine");
    sylLineLine = sylTab->findChild<QLineEdit*>("sylLineLine");
    sylSyllableLine = sylTab->findChild<QLineEdit*>("sylSyllableLine");
    sylFilenameLine = sylTab->findChild<QLineEdit*>("sylFilenameLine");
    sylCommentText = sylTab->findChild<QTextEdit*>("sylCommentText");
    sylCreateButton = sylTab->findChild<QPushButton*>("sylCreateButton");
    sylFinishButton = sylTab->findChild<QPushButton*>("sylFinishButton");
    sylSaveButton = sylTab->findChild<QPushButton*>("sylSaveButton");
    sylSourceToolbutton = sylTab->findChild<QToolButton*>("sylSourceToolbutton");
    sylStaffToolbutton = sylTab->findChild<QToolButton*>("sylStaffToolbutton");
    sylTypeToolbutton = sylTab->findChild<QToolButton*>("sylTypeToolbutton");
    sylValidatorLabel = sylTab->findChild<QLabel*>("sylValidatorLabel");

    sylCreateButton->setDisabled(true);
    sylFilenameLine->setDisabled(true);
    sylSaveButton->setDisabled(true);

    varTab = ui->tabWidget->widget(4);
    varSourceLabel = varTab->findChild<QLabel*>("varSourceLabel");
    varConnectionToolbutton = varTab->findChild<QToolButton*>("varConnectionToolbutton");
    varPitchToolbutton = varTab->findChild<QToolButton*>("varPitchToolbutton");
    varOctaveToolbutton = varTab->findChild<QToolButton*>("varOctaveToolbutton");
    varPreviousToolbutton = varTab->findChild<QToolButton*>("varPreviousToolbutton");
    varTiltToolbutton = varTab->findChild<QToolButton*>("varTiltToolbutton");
    varAddpitchButton = varTab->findChild<QPushButton*>("varAddpitchButton");
    varNextButton = varTab->findChild<QPushButton*>("varNextButton");
    varCommentText = varTab->findChild<QTextEdit*>("varCommentText");

    pitchTab = ui->tabWidget->widget(5);
    pitchPitchToolbutton = pitchTab->findChild<QToolButton*>("pitchPitchToolbutton");
    pitchOctaveToolbutton = pitchTab->findChild<QToolButton*>("pitchOctaveToolbutton");
    pitchTiltToolbutton = pitchTab->findChild<QToolButton*>("pitchTiltToolbutton");
    pitchConnectionToolbutton = pitchTab->findChild<QToolButton*>("pitchConnectionToolbutton");
    pitchPreviousToolbutton = pitchTab->findChild<QToolButton*>("pitchPreviousToolbutton");
    pitchCommentText = pitchTab->findChild<QTextEdit*>("pitchCommentText");
    pitchAddButton = pitchTab->findChild<QPushButton*>("pitchAddButton");
    pitchFinishButton = pitchTab->findChild<QPushButton*>("pitchFinishButton");
    pitchAddVariantButton = pitchTab->findChild<QPushButton*>("pitchAddVariantButton");

    pitchAddVariantButton->setDisabled(true);

    modes.push_back(new QString(""));
    modes.push_back(qtMajor);
    modes.push_back(qtMinor);
    modes.push_back(qtDorian);
    modes.push_back(qtPhrygian);
    modes.push_back(qtLydian);
    modes.push_back(qtMixolydian);
    modes.push_back(qtAeolian);
    modes.push_back(qtLocrian);
    modesToActions();

    pitches.push_back(new QString(""));
    pitches.push_back(qtC);
    pitches.push_back(qtD);
    pitches.push_back(qtE);
    pitches.push_back(qtF);
    pitches.push_back(qtG);
    pitches.push_back(qtA);
    pitches.push_back(qtH);
    pitchesToActions();

    colors.push_back(new QString(""));
    colors.push_back(qtRed);
    colors.push_back(qtBlue);
    colors.push_back(qtGreen);
    colors.push_back(qtYellow);
    colors.push_back(qtBrown);
    colors.push_back(qtBlack);
    colors.push_back(qtGrey);
    colors.push_back(qtOrange);
    colorsToActions();

    numbers.push_back(new QString(""));
    numbers.push_back(qt0);
    numbers.push_back(qt1);
    numbers.push_back(qt2);
    numbers.push_back(qt3);
    numbers.push_back(qt4);
    numbers.push_back(qt5);
    numbers.push_back(qt6);
    numbers.push_back(qt7);
    numbersToActions();

    types.push_back(new QString(""));
    types.push_back(qtApostropha);
    types.push_back(qtBistropha);
    types.push_back(qtClimacus);
    types.push_back(qtClivis);
    types.push_back(qtOriscus);
    types.push_back(qtPes);
    types.push_back(qtPessubpunctis);
    types.push_back(qtPorrectus);
    types.push_back(qtPorrectusflexus);
    types.push_back(qtPressusmaior);
    types.push_back(qtPressusminor);
    types.push_back(qtPunctum);
    types.push_back(qtQuilisma);
    types.push_back(qtScandicus);
    types.push_back(qtStrophicus);
    types.push_back(qtTorculus);
    types.push_back(qtTorculusresupinos);
    types.push_back(qtTristopha);
    types.push_back(qtVirga);
    types.push_back(qtVirgastrata);
    typesToActions();

    directions.push_back(new QString(""));
    directions.push_back(qtNorth);
    directions.push_back(qtSouth);
    directions.push_back(qtEast);
    directions.push_back(qtWest);
    directions.push_back(qtNortheast);
    directions.push_back(qtNorthwest);
    directions.push_back(qtSoutheast);
    directions.push_back(qtSouthwest);
    directionsToActions();

    relations.push_back(new QString(""));
    relations.push_back(qtWentUp);
    relations.push_back(qtWentDown);
    relations.push_back(qtSame);
    relationsToActions();

    connections.push_back(new QString(""));
    connections.push_back(qtGapped);
    connections.push_back(qtLoop);
    connections.push_back(qtExtended);
    connectionsToActions();

    clefs.push_back(new QString(""));
    clefs.push_back(qtClefC);
    clefs.push_back(qtClefF);
    clefs.push_back(qtClefG);
    clefs.push_back(qtClefGG);
    clefs.push_back(qtClefPerc);
    clefs.push_back(qtClefTab);
    clefsToActions();

    tabWidget->removeTab(1);
    tabWidget->removeTab(1);
    tabWidget->removeTab(1);
    tabWidget->removeTab(1);
    tabWidget->removeTab(1);
}

void MainWindow::onCheck()
{
    readOnly = !readOnly;
    mainTextEdit->setReadOnly(readOnly);
}

void MainWindow::onMeta()
{

    QString title = titleLine->text();
    QString composer = composerLine->text();
    QString author = authorLine1->text();
    QStringList authors = author.split(",");
    QString availability = availabilityText->toPlainText();
    QString comments = commentsText->toPlainText();
    QString s;

    s +="<?xml version =\"1.0\" encoding =\"UTF-8\"?>\n";

    s += qtTextBeg; s += qtN;
    s += indent(1); s += qtHeaderBeg; s += qtN;

    s += indent(2); s += qtFiledescriptionBeg; s += qtN;

    if(!title.isEmpty() && !composer.isEmpty())
    {
        s += indent(3); s += qtTitlestmtBeg; s += qtN;
        s += indent(4); s += qtTitleBeg; s += qtN;
        s += indent(5); s += title; s += qtN;
        s += indent(4); s += qtTitleEnd; s += qtN;
        s += indent(4); s += qtAgentBeg; s += qtN;
        s += indent(5);  s += composer; s += qtN;
        s += indent(4); s += qtAgentEnd; s += qtN;
        s += indent(3); s += qtTitlestmtEnd; s += qtN;
    }

    s += indent(3); s += qtPublicationBeg; s += qtN;
    if(!(authors.size() <= 1))
    {
        s += indent(4); s += qtResponsibilityBeg; s += qtN;
        for(int i = 0; i < authors.size(); i++)
        {
            s += indent(5); s += qtPersnameBeg; s += qtN;
            s += indent(6); s += authors[i]; s += qtN;
            s += indent(5); s += qtPersnameEnd; s += qtN;
        }
        s += indent(4); s += qtResponsibilityEnd; s += qtN;
    }
    if(!availability.isEmpty())
    {
        s += indent(4); s += qtAvailabilityBeg; s += qtN;
        s += indent(5); s += qtUserestrictBeg; s += qtN;
        s += indent(6); s += availability; s += qtN;
        s += indent(5); s += qtUserestrictEnd; s += qtN;
        s += indent(4); s += qtAvailabilityEnd; s += qtN;
    }
    s += indent(3); s += qtPublicationEnd; s += qtN;

    s += indent(2); s += qtFiledescriptionEnd; s += qtN;

    if(!comments.isEmpty())
    {
        s += indent(2); s += qtEncodingDescBeg; s += qtN;
        s += indent(3); s += qtEditorialdeclarationBeg; s += qtN;
        s += indent(4); s += qtParagraphBeg; s += qtN;
        s += indent(5); s += comments; s += qtN;
        s += indent(4); s += qtParagraphEnd; s += qtN;
        s += indent(3); s += qtEditorialdeclarationEnd; s += qtN;
        s += indent(2); s += qtEncodingDescEnd; s += qtN;
    }

    s += indent(1); s += qtHeaderEnd; s += qtN;
    s += qtTextEnd;

    s = mutate(s);
    mainTextEdit->textCursor().insertText(s);

    QTextCursor cursor = mainTextEdit->textCursor();
    cursor.setPosition(cursor.position()-19);
    mainTextEdit->setTextCursor(cursor);

    QString *sources = new QString("Sources");
    tabWidget->addTab(sourcesTab, *sources);
    tabWidget->removeTab(tabWidget->currentIndex());
}

void MainWindow::onCreateSource()
{

    sourcesAdded = true;

    QString ID = sourceIDLine->text();
    QString author = sourceAuthorLine->text();
    QString title = sourceTitleLine->text();
    QString location = sourcePhysicallocationLine->text();
    QString ownership = sourceOwnershipLine->text();
    QString date = sourceDateLine->text();
    QString pubstatus = sourcePubStatusLine->text();
    QString medium  = sourceMediumLine->text();
    QString x = sourceXLine->text();
    QString y = sourceYLine->text();
    QString unit = sourceUnitLine->text();
    QString condition = sourceConditionLine->text();
    QString extent = sourceExtentLine->text();
    QString language = sourceLanguageLine->text();
    QString handwriting = sourceHandwritingText->toPlainText();

    QString s;

    s += qtN;
    s += indent(2); s += qtManifestationListBeg; s += qtN;

    if(ID.isEmpty()){
       ID += genericSource; ID += QString::number(sourceCounter);
       s += indent(3); s += qtManifestationAttBeg;
       s += qtAttID; s += "\""; s += ID; s += "\""; s += qtClosingBracket; s += qtN;

       sourceCounter++;
    }
    else{
       s += indent(3);
       s += qtManifestationAttBeg; s += qtAttID; s += "\""; s += ID; s += "\""; s += qtClosingBracket; s += qtN;
    }

    if(!language.isEmpty())
    {

        s += indent(4); s += qtLangusageBeg; s += qtN;
        s += indent(5); s += qtLanguageBeg; s += qtN;
        s += indent(6); s += language; s += qtN;
        s += indent(5); s += qtLanguageEnd;  s += qtN;
        s += indent(4); s += qtLangusageEnd; s += qtN;

    }

    s += indent(4); s += qtBiblListBeg; s += qtN;
    s += indent(5); s += qtBiblBeg; s += qtN;
    if(!title.isEmpty())
    {

        s += indent(6); s += qtTitleBeg; s += qtN;
        s += indent(7); s += title; s += qtN;
        s += indent(6); s += qtTitleEnd; s += qtN;
    }
    if(!author.isEmpty())
    {
        s += indent(6); s += qtAgentBeg; s += qtN;
        s += indent(7); s += author; s += qtN;
        s += indent(6); s += qtAgentEnd; s += qtN;
    }

    if(!date.isEmpty())
    {
        s += indent(6); s += qtDateBeg; s += qtN;
        s += indent(7); s += date; s += qtN;
        s += indent(6); s += qtDateEnd; s += qtN;
    }
    s += indent(5); s += qtBiblEnd; s += qtN;
    s += indent(4); s += qtBiblListEnd; s += qtN;

    s += indent(4); s += qtComponentListBeg; s += qtN;
    s += indent(5); s += qtItemBeg; s += qtN;

    if(!pubstatus.isEmpty()){
        s += indent(6); s += qtAvailabilityBeg; s += qtN;
        s += indent(7); s += pubstatus; s += qtN;
        s += indent(6); s += qtAvailabilityEnd; s += qtN;
    }

    s += indent(6); s += qtPhysdescriptionBeg; s += qtN;
    if(!extent.isEmpty())
    {
        s += indent(7); s += qtExtentBeg; s += qtN;
        s += indent(8); s += extent; s += qtN;
        s += indent(7); s += qtExtentEnd; s += qtN;
    }
    if(!medium.isEmpty())
    {
        s += indent(7); s += qtPhysmediumBeg; s += qtN;
        s += indent(8); s += medium; s += qtN;
        s += indent(7); s += qtPhysmediumEnd; s += qtN;

    }
    if(!x.isEmpty())
    {
        s += indent(7); s += qtDimensionsAttBeg; s += qtAttUnits; s += "\""; s += unit; s += "\""; s += qtClosingBracket; s += qtN;
        s += indent(8); s += x; s += " x "; s += y; s += unit; s += qtN;
        s += indent(7); s += qtDimensionsEnd; s += qtN;
    }
    if(!condition.isEmpty())
    {
        s += indent(7); s += qtConditionBeg; s += qtN;
        s += indent(8); s += condition; s += qtN;
        s += indent(7); s += qtConditionEnd; s += qtN;
    }
    if(!handwriting.isEmpty())
    {
        s += indent(7); s += qtHandlistBeg; s += qtN;
        s += indent(8); s += qtHandBeg; s += qtN;
        s += indent(9); s += qtAnnotBeg; s += qtN;
        s += indent(10); s += handwriting; s += qtN;
        s += indent(9); s += qtAnnotEnd; s += qtN;
        s += indent(8); s += qtHandEnd; s += qtN;
        s += indent(7); s += qtHandlistEnd; s += qtN;
    }

    s += indent(6); s += qtPhysdescriptionEnd; s += qtN;

    if(!location.isEmpty())
    {
        s += indent(6); s += qtPhysicallocationBeg; s += qtN;
        s += indent(7); s += qtRepositoryBeg; s += qtN;
        s += indent(8); s += location; s += qtN;
        s += indent(7); s += qtRepositoryEnd; s += qtN;
        s += indent(6); s += qtPhysicallocationEnd; s += qtN;
    }

    if(!ownership.isEmpty())
    {
        s += indent(6); s += qtHistoryBeg; s += qtN;
        s += indent(7); s += qtProvenanceBeg; s += qtN;
        s += indent(8); s += qtCorpnameBeg; s += qtN;
        s += indent(9); s += ownership; s += qtN;
        s += indent(8); s += qtCorpnameEnd; s += qtN;
        s += indent(7); s += qtProvenanceEnd; s += qtN;
        s += indent(6); s += qtHistoryEnd; s += qtN;
    }

    s += indent(5); s += qtItemEnd; s += qtN;
    s += indent(4); s += qtComponentListEnd; s += qtN;

    s += indent(3); s += qtManifestationEnd; s += qtN;
    s += indent(2); s += qtManifestationListEnd;

    s = mutate(s);
    mainTextEdit->textCursor().insertText(s);

    QTextCursor cursor = mainTextEdit->textCursor();
    cursor.setPosition(cursor.position()-22);
    mainTextEdit->setTextCursor(cursor);

    sourceCreateButton->setDisabled(true);

    sourceAddButton->setDisabled(false);
    sourceFinishButton->setDisabled(false);

    sources.append(ID);

    sourceIDLine->clear();
    sourceAuthorLine->clear();
    sourceTitleLine->clear();
    sourcePhysicallocationLine->clear();
    sourceOwnershipLine->clear();
    sourceDateLine->clear();
    sourcePubStatusLine->clear();
    sourceMediumLine->clear();
    sourceXLine->clear();
    sourceYLine->clear();
    sourceUnitLine->clear();
    sourceConditionLine->clear();
    sourceExtentLine->clear();
    sourceLanguageLine->clear();
    sourceHandwritingText->clear();
}

void MainWindow::onAddSource()
{
    QString ID = sourceIDLine->text();
    QString author = sourceAuthorLine->text();
    QString title = sourceTitleLine->text();
    QString location = sourcePhysicallocationLine->text();
    QString ownership = sourceOwnershipLine->text();
    QString date = sourceDateLine->text();
    QString pubstatus = sourcePubStatusLine->text();
    QString medium  = sourceMediumLine->text();
    QString x = sourceXLine->text();
    QString y = sourceYLine->text();
    QString unit = sourceUnitLine->text();
    QString condition = sourceConditionLine->text();
    QString extent = sourceExtentLine->text();
    QString language = sourceLanguageLine->text();
    QString handwriting = sourceHandwritingText->toPlainText();

    QString s;

    if(ID.isEmpty()){
       ID += genericSource; ID += QString::number(sourceCounter);
       s += indent(3); s += qtManifestationAttBeg; s += qtAttID; s += "\""; s += ID; s += "\""; s += qtClosingBracket; s += qtN;

       sourceCounter++;
    }
    else{
       s += indent(3); s += qtManifestationAttBeg; s += qtAttID; s += "\""; s += ID; s += "\""; s += qtClosingBracket; s += qtN;
    }


    if(!language.isEmpty())
    {

        s += indent(4); s += qtLangusageBeg; s += qtN;
        s += indent(5); s += qtLanguageBeg; s += qtN;
        s += indent(6); s += language; s += qtN;
        s += indent(5); s += qtLanguageEnd;  s += qtN;
        s += indent(4); s += qtLangusageEnd; s += qtN;

    }

    s += indent(4); s += qtBiblListBeg; s += qtN;
    s += indent(5); s += qtBiblBeg; s += qtN;
    if(!title.isEmpty())
    {

        s += indent(6); s += qtTitleBeg; s += qtN;
        s += indent(7); s += title; s += qtN;
        s += indent(6); s += qtTitleEnd; s += qtN;
    }
    if(!author.isEmpty())
    {
        s += indent(6); s += qtAgentBeg; s += qtN;
        s += indent(7); s += author; s += qtN;
        s += indent(6); s += qtAgentEnd; s += qtN;
    }

    if(!date.isEmpty())
    {
        s += indent(6); s += qtDateBeg; s += qtN;
        s += indent(7); s += date; s += qtN;
        s += indent(6); s += qtDateEnd; s += qtN;
    }
    s += indent(5); s += qtBiblEnd; s += qtN;
    s += indent(4); s += qtBiblListEnd; s += qtN;

    s += indent(4); s += qtComponentListBeg; s += qtN;
    s += indent(5); s += qtItemBeg; s += qtN;

    if(!pubstatus.isEmpty()){
        s += indent(6); s += qtAvailabilityBeg; s += qtN;
        s += indent(7); s += pubstatus; s += qtN;
        s += indent(6); s += qtAvailabilityEnd; s += qtN;
    }

    s += indent(6); s += qtPhysdescriptionBeg; s += qtN;
    if(!extent.isEmpty())
    {
        s += indent(7); s += qtExtentBeg; s += qtN;
        s += indent(8); s += extent; s += qtN;
        s += indent(7); s += qtExtentEnd; s += qtN;
    }
    if(!medium.isEmpty())
    {
        s += indent(7); s += qtPhysmediumBeg; s += qtN;
        s += indent(8); s += medium; s += qtN;
        s += indent(7); s += qtPhysmediumEnd; s += qtN;

    }
    if(!x.isEmpty())
    {
        s += indent(7); s += qtDimensionsAttBeg; s += qtAttUnits; s += "\""; s += unit; s += "\""; s += qtClosingBracket; s += qtN;
        s += indent(8); s += x; s += " x "; s += y; s += unit; s += qtN;
        s += indent(7); s += qtDimensionsEnd; s += qtN;
    }
    if(!condition.isEmpty())
    {
        s += indent(7); s += qtConditionBeg; s += qtN;
        s += indent(8); s += condition; s += qtN;
        s += indent(7); s += qtConditionEnd; s += qtN;
    }
    if(!handwriting.isEmpty())
    {
        s += indent(7); s += qtHandlistBeg; s += qtN;
        s += indent(8); s += qtHandBeg; s += qtN;
        s += indent(9); s += qtAnnotBeg; s += qtN;
        s += indent(10); s += handwriting; s += qtN;
        s += indent(9); s += qtAnnotEnd; s += qtN;
        s += indent(8); s += qtHandEnd; s += qtN;
        s += indent(7); s += qtHandlistEnd; s += qtN;
    }

    s += indent(6); s += qtPhysdescriptionEnd; s += qtN;

    if(!location.isEmpty())
    {
        s += indent(6); s += qtPhysicallocationBeg; s += qtN;
        s += indent(7); s += qtRepositoryBeg; s += qtN;
        s += indent(8); s += location; s += qtN;
        s += indent(7); s += qtRepositoryEnd; s += qtN;
        s += indent(6); s += qtPhysicallocationEnd; s += qtN;
    }

    if(!ownership.isEmpty())
    {
        s += indent(6); s += qtHistoryBeg; s += qtN;
        s += indent(7); s += qtProvenanceBeg; s += qtN;
        s += indent(8); s += qtCorpnameBeg; s += qtN;
        s += indent(9); s += ownership; s += qtN;
        s += indent(8); s += qtCorpnameEnd; s += qtN;
        s += indent(7); s += qtProvenanceEnd; s += qtN;
        s += indent(6); s += qtHistoryEnd; s += qtN;
    }

    s += indent(5); s += qtItemEnd; s += qtN;
    s += indent(4); s += qtComponentListEnd; s += qtN;

    s += indent(3); s += qtManifestationEnd; s += qtN;

    s = mutate(s);
    mainTextEdit->textCursor().insertText(s);

    sources.push_back(ID);

    sourceIDLine->clear();
    sourceAuthorLine->clear();
    sourceTitleLine->clear();
    sourcePhysicallocationLine->clear();
    sourceOwnershipLine->clear();
    sourceDateLine->clear();
    sourcePubStatusLine->clear();
    sourceMediumLine->clear();
    sourceXLine->clear();
    sourceYLine->clear();
    sourceUnitLine->clear();
    sourceConditionLine->clear();
    sourceExtentLine->clear();
    sourceLanguageLine->clear();
    sourceHandwritingText->clear();
}

void MainWindow::onFinishSource()
{


    if(sourcesAdded){
        QTextCursor cursor = mainTextEdit->textCursor();
        cursor.setPosition(cursor.position()+35);
        mainTextEdit->setTextCursor(cursor);

    }
    else {
        QTextCursor cursor = mainTextEdit->textCursor();
        cursor.setPosition(cursor.position()+23);
        mainTextEdit->setTextCursor(cursor);

    }

    sourcesToActions();

    QString *staff = new QString("Staff");
    tabWidget->addTab(staffTab, *staff);
    tabWidget->removeTab(tabWidget->currentIndex());
}

void MainWindow::onCreateStaff()
{

    staffAdded = true;

    staffNCounter++;

    QString ID = staffIDLine->text();
    QString linecount = staffLinecountToolbutton->text();
    QString mode = staffModeToolbutton->text();
    QString linecolor = staffLinecolorToolbutton->text();

    if(linecount.isEmpty())
    {
        linecount = "0";
    }

    QString s;


    s += indent(1); s += qtMusicBeg; s += qtN;
    s += indent(2); s += qtBodyBeg; s += qtN;
    s += indent(3); s += qtMdivBeg; s += qtN;
    s += indent(4); s += qtScoreBeg; s += qtN;
    s += indent(5); s += qtScoredefBeg; s += qtN;
    s += indent(6); s += qtStaffgrpAttBeg; s += qtAttID; s += "\"all\""; s += qtClosingBracket; s += qtN;

    if(ID.isEmpty()){
        ID += genericStaff; ID += QString::number(staffCounter);
        s += indent(7); s += qtStaffdefAttBeg; s += qtAttID; s += "\""; s += ID; s += "\"";
        staffCounter++;
    }
    else{
        s += indent(7); s += qtStaffdefAttBeg; s += qtAttID; s += "\""; s += ID; s += "\"";
    }

    s += qtAttN; s += "\""; s += QString::number(staffNCounter); s += "\"";
    s += qtAttLines; s += "\""; s += linecount; s += "\"";

    if(!linecolor.isEmpty())
    {
        s += qtAttLinecolor; s += "\""; s += linecolor; s += "\"";
    }

    if(!mode.isEmpty())
    {
        s += qtAttKeymode; s += "\""; s += mode; s += "\"";
    }

    s += qtClosingBracket; s += qtN;
    s += indent(7); s += qtStaffdefEnd; s += qtN;
    s += indent(6); s += qtStaffgrpEnd; s += qtN;
    s += indent(5); s += qtScoredefEnd; s += qtN;
    s += indent(4); s += qtScoreEnd; s += qtN;
    s += indent(3); s += qtMdivEnd; s += qtN;
    s += indent(2); s += qtBodyEnd; s += qtN;
    s += indent(1); s += qtMusicEnd; s += qtN;


    staffAddclefButton->setDisabled(false);
    staffCreateButton->setDisabled(true);
    staffFinishButton->setDisabled(false);
    staffNewstaffButton->setDisabled(false);

    s = mutate(s);
    mainTextEdit->textCursor().insertText(s);

    QTextCursor cursor = mainTextEdit->textCursor();
    cursor.setPosition(cursor.position()-98);
    mainTextEdit->setTextCursor(cursor);

    staffs.push_back(ID);

    connect(staffCreateButton, &QPushButton::clicked, this, &MainWindow::onAddStaff);
    disconnect(staffCreateButton, &QPushButton::clicked, this, &MainWindow::onCreateStaff);

    staffIDLine->clear();
    staffLinecountToolbutton->setText("");
    staffModeToolbutton->setText("");
    staffLinecolorToolbutton->setText("");
    staffCleflineToolbutton->setText("");

    staffIDLine->setDisabled(true);
    staffLinecountToolbutton->setDisabled(true);
    staffModeToolbutton->setDisabled(true);
    staffLinecolorToolbutton->setDisabled(true);
    staffCleflineToolbutton->setDisabled(false);
    staffClefshapeToolbutton->setDisabled(false);
}

void MainWindow::onAddStaff()
{
    staffNCounter++;

    QString ID = staffIDLine->text();
    QString linecount = staffLinecountToolbutton->text();
    QString mode = staffModeToolbutton->text();
    QString linecolor = staffLinecolorToolbutton->text();

    if(linecount.isEmpty())
    {
        linecount = "0";
    }

    QString s;

    if(ID.isEmpty()){
        ID += genericStaff; ID +=  QString::number(staffCounter);
        s += indent(7); s += qtStaffdefAttBeg; s += qtAttID; s += "\""; s += ID; s += "\"";
        staffCounter++;
    }
    else{
        s += indent(7); s += qtStaffdefAttBeg; s += qtAttID; s += "\""; s += ID; s += "\"";
    }
    s += qtAttN; s += "\""; s += QString::number(staffNCounter); s += "\"";
    s += qtAttLines; s += "\""; s += linecount; s += "\"";

    if(!linecolor.isEmpty())
    {
        s += qtAttLinecolor; s += "\""; s += linecolor; s += "\"";
    }

    if(!mode.isEmpty())
    {
        s += qtAttKeymode; s += "\""; s += mode; s += "\"";
    }
    s += qtClosingBracket; s += qtN;
    s += indent(7); s += qtStaffdefEnd; s += qtN;

    staffAddclefButton->setDisabled(false);
    staffCreateButton->setDisabled(true);
    staffFinishButton->setDisabled(false);
    staffNewstaffButton->setDisabled(false);

    s = mutate(s);
    mainTextEdit->textCursor().insertText(s);

    QTextCursor cursor = mainTextEdit->textCursor();
    cursor.setPosition(cursor.position()-19);
    mainTextEdit->setTextCursor(cursor);

    staffs.push_back(ID);

    staffIDLine->clear();
    staffLinecountToolbutton->setText("");
    staffModeToolbutton->setText("");
    staffLinecolorToolbutton->setText("");
    staffCleflineToolbutton->setText("");

    staffIDLine->setDisabled(true);
    staffLinecountToolbutton->setDisabled(true);
    staffModeToolbutton->setDisabled(true);
    staffLinecolorToolbutton->setDisabled(true);
    staffCleflineToolbutton->setDisabled(false);
    staffClefshapeToolbutton->setDisabled(false);
}

void MainWindow::onAddclefStaff()
{

    QString line = staffCleflineToolbutton->text();
    QString shape = staffClefshapeToolbutton->text();

    QString s;

    s += indent(8); s += qtClefAttBeg;

    if(!line.isEmpty())
    {
        s += qtAttLine; s += "\""; s += line; s += "\"";
    }
    if(!shape.isEmpty())
    {
        s += qtAttShape; s += "\""; s += shape; s += "\"";
    }
    s += "/"; s += qtClosingBracket; s += qtN;

    s = mutate(s);
    mainTextEdit->textCursor().insertText(s);

    staffCleflineToolbutton->setText("");
    staffClefshapeToolbutton->setText("");
    staffLinecountToolbutton->setText("");
}

void MainWindow::onAddNewStaff()
{
    QTextCursor cursor = mainTextEdit->textCursor();
    cursor.setPosition(cursor.position()+19);
    mainTextEdit->setTextCursor(cursor);

    staffAddclefButton->setDisabled(true);
    staffCreateButton->setDisabled(false);
    staffNewstaffButton->setDisabled(true);
    staffFinishButton->setDisabled(true);

    staffIDLine->setDisabled(false);
    staffLinecountToolbutton->setDisabled(false);
    staffModeToolbutton->setDisabled(false);
    staffLinecolorToolbutton->setDisabled(false);
    staffCleflineToolbutton->setDisabled(true);
    staffClefshapeToolbutton->setDisabled(true);
}

void MainWindow::onFinishStaff()
{

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

void MainWindow::onCreateSyllable()
{

    QString page = sylPageLine->text();
    QString line = sylLineLine->text();
    QString syl = sylSyllableLine->text();
    QString comment = sylCommentText->toPlainText();
    QString type = sylTypeToolbutton->text();

    QString s;

    s += indent(5); s += qtSectionBeg; s += qtN;
    s += indent(6); s += qtStaffAttBeg;
    s += qtAttDef; s += "\""; s += sylCurrentStaff; s += "\"";
    s += qtClosingBracket; s += qtN;
    s += indent(7); s += qtLayerBeg; s += qtN;
    if(!page.isEmpty()){
        s += indent(8); s += qtPbAttBeg; s += qtAttN; s += "\""; s += page; s += "\""; s += "/"; s += qtClosingBracket; s+= qtN;
    }
    if(!line.isEmpty()){
        s += indent(8); s += qtSbAttBeg; s += qtAttN; s += "\""; s += line; s += "\""; s += "/"; s += qtClosingBracket; s+= qtN;
    }
    if(!comment.isEmpty()){
        s += indent(8); s += qtAddBeg; s += qtN;
        s += indent(9); s += qtAnnotAttBeg; s += qtAttStaff; s += "\""; s += sylCurrentStaff; s += "\""; s += qtClosingBracket; s+= qtN;
        s += indent(10); s += qtParagraphBeg; s+= qtN;
        s += indent(11); s += comment; s+= qtN;
        s += indent(10); s += qtParagraphEnd; s+= qtN;
        s += indent(9); s += qtAnnotEnd; s+= qtN;
        s += indent(8); s += qtAddEnd; s += qtN;
    }
    if(!type.isEmpty()){
        s += indent(8); s += qtSyllableAttBeg;
        s += qtAttType;  s += "\""; s += type; s += "\""; s += qtClosingBracket; s+= qtN;
    }
    else {
        s += indent(8); s += qtSyllableBeg; s+= qtN;
    }

    s += indent(9); s += qtSylBeg; s+= qtN;
    s += indent(10); s += syl; s += qtN;
    s += indent(9); s += qtSylEnd; s += qtN;
    s += indent(9); s += qtNeumeBeg; s += qtN;
    s += indent(9); s += qtNeumeEnd; s += qtN;
    s += indent(8); s += qtSyllableEnd;  s+= qtN;
    s += indent(7); s += qtLayerEnd; s += qtN;
    s += indent(6); s += qtStaffEnd; s += qtN;
    s += indent(5); s += qtSectionEnd; s += qtN;

    s = mutate(s);
    mainTextEdit->textCursor().insertText(s);

    QTextCursor cursor = mainTextEdit->textCursor();
    cursor.setPosition(cursor.position()-85);
    mainTextEdit->setTextCursor(cursor);

    disconnect(sylCreateButton, &QPushButton::clicked, this, &MainWindow::onCreateSyllable);
    connect(sylCreateButton, &QPushButton::clicked, this, &MainWindow::onAddSyllable);

    QString *pitch = new QString("Pitch");
    tabWidget->addTab(pitchTab, *pitch);
    tabWidget->removeTab(tabWidget->currentIndex());

    segment = new Segment();
    segment->setSyllable(syl.toStdString());
    renderWidget->addSegment(segment);

    if(sources.size() > 1)
    {
        pitchAddVariantButton->setDisabled(false);
    }

    sylSourceToolbutton->setDisabled(true);

    sylFormerStaff = sylCurrentStaff;

    connect(up, &QShortcut::activated, this, &MainWindow::onUp);
    connect(down, &QShortcut::activated, this, &MainWindow::onDown);

    sylPageLine->clear();
    sylLineLine->clear();
    sylSyllableLine->clear();
    sylCommentText->clear();
    sylTypeToolbutton->setText("");
    pitchOctaveToolbutton->setText("");
}

void MainWindow::onAddSyllable()
{
    QString page = sylPageLine->text();
    QString line = sylLineLine->text();
    QString syl = sylSyllableLine->text();
    QString comment = sylCommentText->toPlainText();
    QString type = sylTypeToolbutton->text();

    QString s;

    if(sylCurrentStaff.compare(sylFormerStaff))
    {
        /*
        QTextCursor cursor = mainTextEdit->textCursor();
        cursor.setPosition(cursor.position()+15);
        mainTextEdit->setTextCursor(cursor);
        */
        s += indent(7); s += qtLayerEnd; s += qtN;
        s += indent(6); s += qtStaffEnd; s += qtN;
        s += indent(6); s += qtStaffAttBeg;
        s += qtAttDef; s += "\""; s += sylCurrentStaff; s += "\"";
        s += qtClosingBracket; s += qtN;

        sylFormerStaff = sylCurrentStaff;

        s += indent(7); s += qtLayerBeg; s += qtN;

        s = mutate(s);
        mainTextEdit->textCursor().insertText(s);

        /*
        cursor = mainTextEdit->textCursor();
        cursor.setPosition(cursor.position()-15);
        mainTextEdit->setTextCursor(cursor);
        */
        s.clear();
    }

    if(!page.isEmpty()){
        s += indent(8); s += qtPbAttBeg; s += qtAttN; s += "\""; s += page; s += "\""; s += "/"; s += qtClosingBracket; s+= qtN;
    }
    if(!line.isEmpty()){
        s += indent(8); s += qtSbAttBeg; s += qtAttN; s += "\""; s += line; s += "\""; s += "/"; s += qtClosingBracket; s+= qtN;
    }
    if(!comment.isEmpty()){
        s += indent(8); s += qtAddBeg; s += qtN;
        s += indent(9); s += qtAnnotAttBeg; s += qtAttStaff; s += "\""; s += sylCurrentStaff; s += "\""; s += qtClosingBracket; s+= qtN;
        s += indent(10); s += qtParagraphBeg; s+= qtN;
        s += indent(11); s += comment; s+= qtN;
        s += indent(10); s += qtParagraphEnd; s+= qtN;
        s += indent(9); s += qtAnnotEnd; s+= qtN;
        s += indent(8); s += qtAddEnd; s += qtN;
    }
    if(!type.isEmpty()){
        s += indent(8); s += qtSyllableAttBeg;
        s += qtAttType;  s += "\""; s += type; s += "\""; s += qtClosingBracket; s+= qtN;
    }
    else {
        s += indent(8); s += qtSyllableBeg; s+= qtN;
    }
    s += indent(9); s += qtSylBeg; s+= qtN;
    s += indent(10); s += syl; s += qtN;
    s += indent(9); s += qtSylEnd; s += qtN;
    s += indent(9); s += qtNeumeBeg; s += qtN;
    s += indent(9); s += qtNeumeEnd; s += qtN;
    s += indent(8); s += qtSyllableEnd;  s+= qtN;

    s = mutate(s);
    mainTextEdit->textCursor().insertText(s);

    QTextCursor cursor = mainTextEdit->textCursor();
    cursor.setPosition(cursor.position()-38);
    mainTextEdit->setTextCursor(cursor);

    QString *pitch = new QString("Pitch");
    tabWidget->addTab(pitchTab, *pitch);
    tabWidget->removeTab(tabWidget->currentIndex());

    segment = new Segment();
    segment->setSyllable(syl.toStdString());
    renderWidget->addSegment(segment);

    if(sources.size() > 1)
    {
        pitchAddVariantButton->setDisabled(false);
    }

    sylPageLine->clear();
    sylLineLine->clear();
    sylSyllableLine->clear();
    sylCommentText->clear();
    sylTypeToolbutton->setText("");
    pitchOctaveToolbutton->setText("");
}

void MainWindow::onAddVariant()
{
    varCounter = 0;
    QString *variants = new QString("Variants");
    tabWidget->addTab(varTab, *variants);
    tabWidget->removeTab(tabWidget->currentIndex());
    varSourceLabel->setText(sources[varCounter]);

    pitchAddVariantButton->setDisabled(true);
    varOctaveToolbutton->setText("");
    varPitchToolbutton->setText("");
    varTiltToolbutton->setText("");
    varPreviousToolbutton->setText("");
    varConnectionToolbutton->setText("");
}

void MainWindow::onFinishSyllable()
{
    ui->adjustByHand->setDisabled(false);
    sylFilenameLine->setDisabled(false);
    sylSaveButton->setDisabled(false);

    sylCreateButton->setDisabled(true);
    pitchAddVariantButton->setDisabled(true);
    sylFinishButton->setDisabled(true);
}

void MainWindow::onSylSave()
{
    QString filename = sylFilenameLine->text();
    if(!filename.isEmpty())
    {
        QFile file(filename + ".mei");
        file.open(QIODevice::WriteOnly);
        QTextStream stream(&file);
        stream << mainTextEdit->toPlainText();
        file.close();
    }
}

void MainWindow::onAddPitch()
{

    QString pitch = pitchPitchToolbutton->text();
    QString octave = pitchOctaveToolbutton->text();
    QString comment = pitchCommentText->toPlainText();
    QString intm = pitchPreviousToolbutton->text();
    QString connection = pitchConnectionToolbutton->text();
    QString tilt = pitchTiltToolbutton->text();

    if(intm.compare("same") == 0)
    {
        intm = *qtS;
    }
    if(intm.compare("went down from previous") == 0)
    {
        intm = *qtD;
    }
    if(intm.compare("went up from previous") == 0)
    {
        intm = *qtU;
    }

    if(connection.compare("loop") == 0)
    {
        connection = *qtL;
    }
    if(connection.compare("gapped") == 0)
    {
        connection = *qtG;
    }
    if(connection.compare("extended") == 0)
    {
        connection = *qtE;
    }

    QString s;

    if(!comment.isEmpty()){
        s += indent(10); s += qtAddBeg; s += qtN;
        s += indent(11); s += qtAnnotAttBeg; s += qtAttStaff; s += "\""; s += sylCurrentStaff; s += "\""; s += qtClosingBracket; s+= qtN;
        s += indent(12); s += qtParagraphBeg; s+= qtN;
        s += indent(13); s += comment; s+= qtN;
        s += indent(12); s += qtParagraphEnd; s+= qtN;
        s += indent(11); s += qtAnnotEnd; s+= qtN;
        s += indent(10); s += qtAddEnd; s += qtN;
    }
    s += indent(10); s += qtNcAttBeg;

    if(!octave.isEmpty())
    {
        s += qtAttOct; s += "\""; s += octave; s += "\"";
    }

    if(!pitch.isEmpty())
    {
        s += qtAttPname; s += "\""; s += pitch; s += "\"";
    }
    if(!intm.isEmpty())
    {
        s += qtAttIntm; s += "\""; s += intm; s += "\"";
    }
    if(!connection.isEmpty())
    {
        s += qtAttConnection; s += "\""; s += connection; s += "\"";
    }
    if(!tilt.isEmpty())
    {
        s += qtAttTilt; s += "\""; s += tilt; s += "\"";
    }
    s += "/"; s += qtClosingBracket; s += qtN;

    s = mutate(s);
    mainTextEdit->textCursor().insertText(s);

    Note *n;

    if(!pitch.isEmpty())
    {
        n = new Note(octave.toInt(), pitch.toStdString());
    }
    else if(!intm.isEmpty())
    {
        n = new Note(intm.toStdString());
    }
    else
    {
        n = new Note();
    }

    renderWidget->currentSegment->addNote(n);
    renderWidget->update();

    pitchPitchToolbutton->setText("");
    pitchOctaveToolbutton->setText("");
    pitchCommentText->clear();
    pitchPreviousToolbutton->setText("");
    pitchConnectionToolbutton->setText("");
    pitchTiltToolbutton->setText("");
}

void MainWindow::onFinishPitch()
{

    QString *syllable = new QString("Syllable");
    tabWidget->addTab(sylTab, *syllable);
    tabWidget->removeTab(tabWidget->currentIndex());

    QTextCursor cursor = mainTextEdit->textCursor();
    cursor.setPosition(cursor.position()+38);
    mainTextEdit->setTextCursor(cursor);

    renderWidget->update();
}

void MainWindow::onVarAddpitch()
{
    varAdded = true;

    QString s;
    QString pitch = varPitchToolbutton->text();
    QString octave = varOctaveToolbutton->text();
    QString comment = varCommentText->toPlainText();
    QString intm = varPreviousToolbutton->text();
    QString connection = varConnectionToolbutton->text();
    QString tilt = varTiltToolbutton->text();

    if(intm.compare("same") == 0)
    {
        intm = *qtS;
    }
    if(intm.compare("went down from previous") == 0)
    {
        intm = *qtD;
    }
    if(intm.compare("went up from previous") == 0)
    {
        intm = *qtU;
    }

    if(connection.compare("loop") == 0)
    {
        connection = *qtL;
    }
    if(connection.compare("gapped") == 0)
    {
        connection = *qtG;
    }
    if(connection.compare("extended") == 0)
    {
        connection = *qtE;
    }

    if(varSourceLabel->text().compare(sources[0]) == 0)
    {
        s += indent(10); s += qtAppBeg; s += qtN;
        s += indent(11); s += qtRdgAttBeg; s += qtAttSource; s += "\""; s += sources[0]; s += "\""; s += qtClosingBracket; s += qtN;

        if(!comment.isEmpty())
        {
            s += indent(12); s += qtAddBeg; s += qtN;
            s += indent(13); s += qtAnnotAttBeg; s += qtAttStaff; s += "\""; s += sylCurrentStaff; s += "\""; s += qtClosingBracket; s+= qtN;
            s += indent(14); s += qtParagraphBeg; s+= qtN;
            s += indent(15); s += comment; s+= qtN;
            s += indent(14); s += qtParagraphEnd; s+= qtN;
            s += indent(13); s += qtAnnotEnd; s+= qtN;
            s += indent(12); s += qtAddEnd; s += qtN;
        }

        s += indent(12); s += qtNcAttBeg;
        if(!octave.isEmpty())
        {
            s += qtAttOct; s += "\""; s += octave; s += "\"";
        }

        if(!pitch.isEmpty())
        {
            s += qtAttPname; s += "\""; s += pitch; s += "\"";
        }
        if(!intm.isEmpty())
        {
            s += qtAttIntm; s += "\""; s += intm; s += "\"";
        }
        if(!connection.isEmpty())
        {
            s += qtAttConnection; s += "\""; s += connection; s += "\"";
        }
        if(!tilt.isEmpty())
        {
            s += qtAttTilt; s += "\""; s += tilt; s += "\"";
        }
        s += "/"; s += qtClosingBracket; s += qtN;
        s += indent(11); s += qtRdgEnd; s += qtN;
        s += indent(10); s += qtAppEnd; s += qtN;

        connect(varAddpitchButton, &QPushButton::clicked, this, &MainWindow::onVarAddpitch2);
        disconnect(varAddpitchButton, &QPushButton::clicked, this, &MainWindow::onVarAddpitch);

        s = mutate(s);
        mainTextEdit->textCursor().insertText(s);

        QTextCursor cursor = mainTextEdit->textCursor();
        cursor.setPosition(cursor.position()-35);
        mainTextEdit->setTextCursor(cursor);

        Note *n;

        if(!pitch.isEmpty())
        {
            n = new Note(octave.toInt(), pitch.toStdString());
        }
        else if(!intm.isEmpty())
        {
            n = new Note(intm.toStdString());
        }
        else
        {
            n = new Note();
        }

        renderWidget->currentSegment->addNote(n);
        renderWidget->update();
    }
    else
    {
        s += indent(11); s += qtRdgAttBeg; s += qtAttSource; s += "\""; s += sources[varCounter]; s += "\""; s += qtClosingBracket; s += qtN;


        if(!comment.isEmpty())
        {
            s += indent(12); s += qtAddBeg; s += qtN;
            s += indent(13); s += qtAnnotAttBeg; s += qtAttStaff; s += "\""; s += sylCurrentStaff; s += "\""; s += qtClosingBracket; s+= qtN;
            s += indent(14); s += qtParagraphBeg; s+= qtN;
            s += indent(15); s += comment; s+= qtN;
            s += indent(14); s += qtParagraphEnd; s+= qtN;
            s += indent(13); s += qtAnnotEnd; s+= qtN;
            s += indent(12); s += qtAddEnd; s += qtN;
        }

        s += indent(12); s += qtNcAttBeg;
        if(!octave.isEmpty())
        {
            s += qtAttOct; s += "\""; s += octave; s += "\"";
        }

        if(!pitch.isEmpty())
        {
            s += qtAttPname; s += "\""; s += pitch; s += "\"";
        }
        if(!intm.isEmpty())
        {
            s += qtAttIntm; s += "\""; s += intm; s += "\"";
        }
        if(!connection.isEmpty())
        {
            s += qtAttConnection; s += "\""; s += connection; s += "\"";
        }
        if(!tilt.isEmpty())
        {
            s += qtAttTilt; s += "\""; s += tilt; s += "\"";
        }
        s += "/"; s += qtClosingBracket; s += qtN;
        s += indent(11); s += qtRdgEnd; s += qtN;

        connect(varAddpitchButton, &QPushButton::clicked, this, &MainWindow::onVarAddpitch2);
        disconnect(varAddpitchButton, &QPushButton::clicked, this, &MainWindow::onVarAddpitch);

        s = mutate(s);
        mainTextEdit->textCursor().insertText(s);

        QTextCursor cursor = mainTextEdit->textCursor();
        cursor.setPosition(cursor.position()-18);
        mainTextEdit->setTextCursor(cursor);

        Note *n;

        if(!pitch.isEmpty())
        {
            n = new Note(octave.toInt(), pitch.toStdString());
        }
        else
        {
            n = new Note();
        }

        renderWidget->currentSegment->addNote(n);
        renderWidget->update();
    }

    varPitchToolbutton->setText("");
    varOctaveToolbutton->setText("");
    varCommentText->clear();
    varPreviousToolbutton->setText("");
    varConnectionToolbutton->setText("");
    varTiltToolbutton->setText("");
}

void MainWindow::onVarAddpitch2()
{
    QString s;
    QString pitch = varPitchToolbutton->text();
    QString octave = varOctaveToolbutton->text();
    QString comment = varCommentText->toPlainText();
    QString intm = varPreviousToolbutton->text();
    QString connection = varConnectionToolbutton->text();
    QString tilt = varTiltToolbutton->text();

    if(intm.compare("same") == 0)
    {
        intm = *qtS;
    }
    if(intm.compare("went down from previous") == 0)
    {
        intm = *qtD;
    }
    if(intm.compare("went up from previous") == 0)
    {
        intm = *qtU;
    }

    if(connection.compare("loop") == 0)
    {
        connection = *qtL;
    }
    if(connection.compare("gapped") == 0)
    {
        connection = *qtG;
    }
    if(connection.compare("extended") == 0)
    {
        connection = *qtE;
    }

    if(!comment.isEmpty())
    {
        s += indent(12); s += qtAddBeg; s += qtN;
        s += indent(13); s += qtAnnotAttBeg; s += qtAttStaff; s += "\""; s += sylCurrentStaff; s += "\""; s += qtClosingBracket; s+= qtN;
        s += indent(14); s += qtParagraphBeg; s+= qtN;
        s += indent(15); s += comment; s+= qtN;
        s += indent(14); s += qtParagraphEnd; s+= qtN;
        s += indent(13); s += qtAnnotEnd; s+= qtN;
        s += indent(12); s += qtAddEnd; s += qtN;
    }

    s += indent(12); s += qtNcAttBeg;
    if(!octave.isEmpty())
    {
        s += qtAttOct; s += "\""; s += octave; s += "\"";
    }

    if(!pitch.isEmpty())
    {
        s += qtAttPname; s += "\""; s += pitch; s += "\"";
    }
    if(!intm.isEmpty())
    {
        s += qtAttIntm; s += "\""; s += intm; s += "\"";
    }
    if(!connection.isEmpty())
    {
        s += qtAttConnection; s += "\""; s += connection; s += "\"";
    }
    if(!tilt.isEmpty())
    {
        s += qtAttTilt; s += "\""; s += tilt; s += "\"";
    }
    s += "/"; s += qtClosingBracket; s += qtN;

    s = mutate(s);
    mainTextEdit->textCursor().insertText(s);

    Note *n;

    if(!pitch.isEmpty())
    {
        n = new Note(octave.toInt(), pitch.toStdString());
    }
    else if(!intm.isEmpty())
    {
        n = new Note(intm.toStdString());
    }
    else
    {
        n = new Note();
    }

    renderWidget->currentSegment->addNote(n);
    renderWidget->update();

    varPitchToolbutton->setText("");
    varOctaveToolbutton->setText("");
    varCommentText->clear();
    varPreviousToolbutton->setText("");
    varConnectionToolbutton->setText("");
    varTiltToolbutton->setText("");
}

void MainWindow::onVarNext()
{
    varPitchToolbutton->setText("");
    varOctaveToolbutton->setText("");
    varConnectionToolbutton->setText("");
    varPreviousToolbutton->setText("");
    varTiltToolbutton->setText("");

    if(varCounter == sources.size() - 2)
    {
        varNextButton->setText("Finish");
        disconnect(varNextButton, &QPushButton::clicked, this, &MainWindow::onVarNext);
        connect(varNextButton, &QPushButton::clicked, this, &MainWindow::onVarNext2);
    }

    connect(varAddpitchButton, &QPushButton::clicked, this, &MainWindow::onVarAddpitch);
    disconnect(varAddpitchButton, &QPushButton::clicked, this, &MainWindow::onVarAddpitch2);

    if(varAdded)
    {
        QTextCursor cursor = mainTextEdit->textCursor();
        cursor.setPosition(cursor.position()+18);
        mainTextEdit->setTextCursor(cursor);
        varCounter++;
    }
    else
    {
        QString s;
        if(varSourceLabel->text().compare(sources[0]) == 0)
        {
            s += indent(10); s += qtAppBeg; s += qtN;
            s += indent(11); s += qtRdgAttBeg;
            s += qtAttSource; s += "\""; s += sources[varCounter]; s += "\""; s += qtClosingBracket; s += qtN;
            s += indent(11); s += qtRdgEnd; s += qtN;
            s += indent(10); s += qtAppEnd; s += qtN;

            varCounter++;


            s = mutate(s);
            mainTextEdit->textCursor().insertText(s);

            QTextCursor cursor = mainTextEdit->textCursor();
            cursor.setPosition(cursor.position()-17);
            mainTextEdit->setTextCursor(cursor);
        }
        else
        {
            s += indent(11); s += qtRdgAttBeg;
            s += qtAttSource; s += "\""; s += sources[varCounter]; s += "\""; s += qtClosingBracket; s += qtN;
            s += indent(11); s += qtRdgEnd; s += qtN;

            varCounter++;

            s = mutate(s);
            mainTextEdit->textCursor().insertText(s);

        }
    }
    varSourceLabel->setText(sources[varCounter]);
    varAdded = false;
}

void MainWindow::onVarNext2()
{
    varPitchToolbutton->setText("");
    varOctaveToolbutton->setText("");
    varConnectionToolbutton->setText("");
    varPreviousToolbutton->setText("");
    varTiltToolbutton->setText("");
    varNextButton->setText("Next");

    if(!varAdded)
    {
        QString s;
        s += indent(11); s += qtRdgAttBeg;
        s += qtAttSource; s += "\""; s += sources[varCounter]; s += "\""; s += qtClosingBracket; s += qtN;
        s += indent(11); s += qtRdgEnd; s += qtN;

        s = mutate(s);
        mainTextEdit->textCursor().insertText(s);

        QTextCursor cursor = mainTextEdit->textCursor();
        cursor.setPosition(cursor.position()+17);
        mainTextEdit->setTextCursor(cursor);

    }
    else
    {
        QTextCursor cursor = mainTextEdit->textCursor();
        cursor.setPosition(cursor.position()+35);
        mainTextEdit->setTextCursor(cursor);

    }


    QString *pitch = new QString("Pitch");
    tabWidget->addTab(pitchTab, *pitch);
    tabWidget->removeTab(tabWidget->currentIndex());

    disconnect(varNextButton, &QPushButton::clicked, this, &MainWindow::onVarNext2);
    connect(varNextButton, &QPushButton::clicked, this, &MainWindow::onVarNext);

    connect(varAddpitchButton, &QPushButton::clicked, this, &MainWindow::onVarAddpitch);
    disconnect(varAddpitchButton, &QPushButton::clicked, this, &MainWindow::onVarAddpitch2);

    varCounter = 0;
    varAdded = false;

    renderWidget->update();
}

void MainWindow::onSelectSource()
{
    QObject *sender = QObject::sender();
    QAction *action = qobject_cast<QAction*>(sender);
    sylCurrentSource = action->text();
    sylSourceToolbutton->setText(sylCurrentSource);

    if(!sylCurrentSource.isEmpty() && !sylCurrentStaff.isEmpty()){
        sylCreateButton->setDisabled(false);
    }
}

void MainWindow::onSelectStaff()
{
    QObject *sender = QObject::sender();
    QAction *action = qobject_cast<QAction*>(sender);
    sylCurrentStaff = action->text();
    sylStaffToolbutton->setText(sylCurrentStaff);

    if(!sylCurrentSource.isEmpty() && !sylCurrentStaff.isEmpty()){
        sylCreateButton->setDisabled(false);
    }
}

void MainWindow::onSelectMode()
{
    QObject *sender = QObject::sender();
    QAction *action = qobject_cast<QAction*>(sender);
    QString mode = action->text();
    staffModeToolbutton->setText(action->text());
}

void MainWindow::onSelectPitch()
{
    QObject *sender = QObject::sender();
    QAction *action = qobject_cast<QAction*>(sender);
    pitchPitchToolbutton->setText(action->text());
    varPitchToolbutton->setText(action->text());
}

void MainWindow::onSelectColor()
{
    QObject *sender = QObject::sender();
    QAction *action = qobject_cast<QAction*>(sender);
    staffLinecolorToolbutton->setText(action->text());
}

void MainWindow::onSelectNumber()
{
    QObject *sender = QObject::sender();
    QAction *action = qobject_cast<QAction*>(sender);
    pitchOctaveToolbutton->setText(action->text());
    varOctaveToolbutton->setText(action->text());
    staffLinecountToolbutton->setText(action->text());
    staffCleflineToolbutton->setText(action->text());
}

void MainWindow::onSelectType()
{
    QObject *sender = QObject::sender();
    QAction *action = qobject_cast<QAction*>(sender);
    sylTypeToolbutton->setText(action->text());
}

void MainWindow::onSelectDirection()
{
    QObject *sender = QObject::sender();
    QAction *action = qobject_cast<QAction*>(sender);
    pitchTiltToolbutton->setText(action->text());
    varTiltToolbutton->setText(action->text());
}

void MainWindow::onSelectRelation()
{
    QObject *sender = QObject::sender();
    QAction *action = qobject_cast<QAction*>(sender);
    pitchPreviousToolbutton->setText(action->text());
    varPreviousToolbutton->setText(action->text());
}

void MainWindow::onSelectConnection()
{
    QObject *sender = QObject::sender();
    QAction *action = qobject_cast<QAction*>(sender);
    pitchConnectionToolbutton->setText(action->text());
    varConnectionToolbutton->setText(action->text());
}

void MainWindow::onSelectClef()
{
    QObject *sender = QObject::sender();
    QAction *action = qobject_cast<QAction*>(sender);
    staffClefshapeToolbutton->setText(action->text());
}

QString MainWindow::indent(int a)
{
    QString s;
    for(int i = 0; i < a; i++){
        s += qtT;
    }
    return s;
}

QString MainWindow::mutate(QString s)
{
    s = s.replace("Ö", "Oe");
    s = s.replace("ö", "oe");
    s = s.replace("Ä", "Ae");
    s = s.replace("ä", "ae");
    s = s.replace("Ü", "Ue");
    s = s.replace("ü", "ue");

    return s;
}

bool MainWindow::checkIDs(QString s)
{
    for(int i = 0; i < IDs.size(); i++)
    {
        if(s.compare(IDs[i]) == 0)
        {
            return false;
        }
    }

    return true;
}

void MainWindow::sourcesToActions()
{

    sourcesMenu = new QMenu();
    for(int i = 0; i < sources.size(); i++){
        QAction *action = new QAction();
        action->setText(sources[i]);
        connect(action, &QAction::triggered, this, &MainWindow::onSelectSource);
        sourcesMenu->addAction(action);
    }

    sourcesMenu->setMinimumWidth(sylSourceToolbutton->width());
    sylSourceToolbutton->setMenu(sourcesMenu);
}

void MainWindow::staffsToActions()
{

    staffMenu = new QMenu();
    for(int i = 0; i < staffs.size(); i++){
        QAction *action = new QAction();
        action->setText(staffs[i]);
        connect(action, &QAction::triggered, this, &MainWindow::onSelectStaff);
        staffMenu->addAction(action);
    }

    staffMenu->setMinimumWidth(sylStaffToolbutton->width());
    sylStaffToolbutton->setMenu(staffMenu);
}

void MainWindow::modesToActions()
{
    QList<QToolButton*> buttons;
    buttons.push_back(staffModeToolbutton);
    blankToActions(modeMenu, modes, &MainWindow::onSelectMode, buttons);
}

void MainWindow::pitchesToActions()
{
    QList<QToolButton*> buttons;
    buttons.push_back(varPitchToolbutton);
    buttons.push_back(pitchPitchToolbutton);

    blankToActions(pitchMenu, pitches, &MainWindow::onSelectPitch, buttons);
}

void MainWindow::colorsToActions()
{

    QList<QToolButton*> buttons;
    buttons.push_back(staffLinecolorToolbutton);

    blankToActions(colorMenu, colors, &MainWindow::onSelectColor, buttons);
}

void MainWindow::numbersToActions()
{
    QList<QToolButton*> buttons;
    buttons.push_back(varOctaveToolbutton);
    buttons.push_back(pitchOctaveToolbutton);
    buttons.push_back(staffCleflineToolbutton);
    buttons.push_back(staffLinecountToolbutton);

    blankToActions(numberMenu, numbers, &MainWindow::onSelectNumber, buttons);
}

void MainWindow::typesToActions()
{   
    QList<QToolButton*> buttons;
    buttons.push_back(sylTypeToolbutton);

    blankToActions(typeMenu, types, &MainWindow::onSelectType, buttons);
}

void MainWindow::directionsToActions()
{
    QList<QToolButton*> buttons;
    buttons.push_back(varTiltToolbutton);
    buttons.push_back(pitchTiltToolbutton);

    blankToActions(directionMenu, directions, &MainWindow::onSelectDirection, buttons);
}

void MainWindow::relationsToActions()
{
    QList<QToolButton*> buttons;
    buttons.push_back(varPreviousToolbutton);
    buttons.push_back(pitchPreviousToolbutton);

    blankToActions(relationMenu, relations, &MainWindow::onSelectRelation, buttons);
}

void MainWindow::connectionsToActions()
{
    QList<QToolButton*> buttons;
    buttons.push_back(varConnectionToolbutton);
    buttons.push_back(pitchConnectionToolbutton);

    blankToActions(connectionMenu, connections, &MainWindow::onSelectConnection, buttons);
}

void MainWindow::clefsToActions()
{
    QList<QToolButton*> buttons;
    buttons.push_back(staffClefshapeToolbutton);

    blankToActions(clefMenu, clefs, &MainWindow::onSelectClef, buttons);
}

void MainWindow::blankToActions(QMenu *menu, QList<QString*> list, void(MainWindow::*func)(), QList<QToolButton*> buttons)
{
    menu = new QMenu();
    int i;

    for(i = 0; i < list.size(); i++)
    {
        QAction *action = new QAction();
        action->setText(*(list[i]));
        connect(action, &QAction::triggered, this, func);
        menu->addAction(action);
    }

    for(i = 0; i < buttons.size(); i++)
    {
        menu->setMinimumWidth(buttons[i]->width());
        buttons[i]->setMenu(menu);
    }
}
void MainWindow::onUp()
{
    renderWidget->increaseInitY();
    renderWidget->update();
}

void MainWindow::onDown()
{
     renderWidget->decreaseInitY();
     renderWidget->update();
}
