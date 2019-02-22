#ifndef XMLTEXT_H
#define XMLTEXT_H

#include<string>

static const char *meiBeg = "<>";
static const char *meiEnd = "</>";
static const char *meiAtt = " =";

static const char *meiFrameText = "<mei></mei>";
static const char *meiHeaderText = "\n<meiHead>\n</meiHead>\n";

static const char *meiClosingBracket = ">";

static const char *meiAttID = " xml:id=";
static const char *meiAttRole = " role=";
static const char *meiAttLines = " lines=";
static const char *meiAttLine = " line=";
static const char *meiAttShape = " shape=";
static const char *meiAttDef = " def=";
static const char *meiAttSource = " source=";
static const char *meiAttUnits = " unit=";
static const char *meiAttLabel = " label=";
static const char *meiAttCharacter = " character=";
static const char *meiAttType = " type=";
static const char *meiAttColor = " color=";
static const char *meiAttInk = " ink=";
static const char *meiAttN = " n=";
static const char *meiAttOct = " oct=";
static const char *meiAttPname = " pname=";
static const char *meiAttStaff = " staff=";
static const char *meiAttIdref = " idref=";
static const char *meiAttKeymode = " key.mode=";
static const char *meiAttLinecolor = " lines.color=";
static const char *meiAttIntm = " intm=";
static const char *meiAttTilt = " tilt=";
static const char *meiAttConnection = " con=";
static const char *meiMetaText = "";

static const char *meiMajor = "major";
static const char *meiMinor = "minor";
static const char *meiDorian = "dorian";
static const char *meiPhrygian = "phrygian";
static const char *meiLydian = "lydian";
static const char *meiMixolydian = "mixolydian";
static const char *meiAeolian = "aeolian";
static const char *meiLocrian = "locrian";

static const char *meiRed = "red";
static const char *meiGreen = "green";
static const char *meiBlue = "blue";
static const char *meiYellow = "yellow";
static const char *meiBrown = "brown";
static const char *meiBlack = "black";
static const char *meiGrey = "grey";
static const char *meiOrange = "orange";

static const char *meiC = "c";
static const char *meiD = "d";
static const char *meiE = "e";
static const char *meiF = "f";
static const char *meiG = "g";
static const char *meiA = "a";
static const char *meiH = "h";

static const char *meiL = "l";
static const char *meiS = "s";
static const char *meiU = "u";

static const char *meiNorth = "n";
static const char *meiSouth = "s";
static const char *meiEast = "e";
static const char *meiWest = "w";
static const char *meiNortheast = "ne";
static const char *meiNorthwest = "nw";
static const char *meiSoutheast = "se";
static const char *meiSouthwest = "sw";

static const char *mei0 = "0";
static const char *mei1 = "1";
static const char *mei2 = "2";
static const char *mei3 = "3";
static const char *mei4 = "4";
static const char *mei5 = "5";
static const char *mei6 = "6";
static const char *mei7 = "7";

static const char *meiApostropha = "apostropha";
static const char *meiBistropha = "bistropha";
static const char *meiClimacus = "climacus";
static const char *meiClivis = "clivis";
static const char *meiOriscus = "oriscus";
static const char *meiPes = "pes";
static const char *meiPessubpunctis = "pessubpunctis";
static const char *meiPorrectus = "porrectus";
static const char *meiPorrectusflexus = "porrectusflexus";
static const char *meiPressusmaior = "pressusmaior";
static const char *meiPressusminor = "pressusminor";
static const char *meiPunctum = "punctum";
static const char *meiQuilisma = "quilisma";
static const char *meiScandicus = "scandicus";
static const char *meiStrophicus = "strophicus";
static const char *meiTorculus = "torculus";
static const char *meiTorculusresupinos = "torculusresupinus";
static const char *meiTristopha = "tristropha";
static const char *meiVirga = "virga";
static const char *meiVirgastrata = "virgastrata";

static const char *meiClefC = "C";
static const char *meiClefF = "F";
static const char *meiClefG = "G";
static const char *meiClefGG = "GG";
static const char *meiClefPerc = "perc";
static const char *meiClefTab = "TAB";

static const char *meiTextBeg = "<mei xmlns=\"http://www.music-encoding.org/ns/mei\" meiversion=\"4.0.0\">";
static const char *meiTextEnd = "</mei>";

static const char *meiHeaderBeg = "<meiHead>";
static const char *meiHeaderEnd = "</meiHead>";

static const char *meiTitleBeg = "<title>";
static const char *meiTitleEnd = "</title>";

static const char *meiTitlestmtBeg = "<titleStmt>";
static const char *meiTitlestmtEnd = "</titleStmt>";

static const char *meiResponsibilityBeg = "<respStmt>";
static const char *meiResponsibilityEnd = "</respStmt>";

static const char *meiAgentBeg = "<composer>";
static const char *meiAgentEnd = "</composer>";

static const char *meiPublicationBeg = "<pubStmt>";
static const char *meiPublicationEnd = "</pubStmt>";

static const char *meiAvailabilityBeg = "<availability>";
static const char *meiAvailabilityEnd = "</availability>";

static const char *meiUserestrictBeg = "<useRestrict>";
static const char *meiUserestrictEnd = "</useRestrict>";

static const char *meiFiledescriptionBeg = "<fileDesc>";
static const char *meiFiledescriptionEnd = "</fileDesc>";

static const char *meiEditorialdeclarationBeg = "<editorialDecl>";
static const char *meiEditorialdeclarationEnd = "</editorialDecl>";

static const char *meiParagraphBeg = "<p>";
static const char *meiParagraphEnd = "</p>";

static const char *meiProfiledescriptionBeg = "<profileDesc>";
static const char *meiProfiledescriptionEnd = "</profileDesc>";

static const char *meiLangusageBeg = "<langUsage>";
static const char *meiLangusageEnd = "</langUsage>";

static const char *meiLanguageBeg = "<language>";
static const char *meiLanguageEnd = "</language>";

static const char *meiMusicclassBeg = "<musicclass>";
static const char *meiMusicclassEnd = "</musicclass>";

static const char *meiKeywordsBeg = "<keywords>";
static const char *meiKeywordsEnd = "</keywords>";

static const char *meiTermBeg = "<term>";
static const char *meiTermEnd = "</term>";

static const char *meiSourcedescriptionBeg = "<sourceDesc>";
static const char *meiSourcedescriptionEnd = "</sourceDesc>";

static const char *meiSourceBeg = "<source>";
static const char *meiSourceAttBeg = "<source";
static const char *meiSourceEnd = "</source>";

static const char *meiPhysdescriptionBeg = "<physDesc>";
static const char *meiPhysdescriptionEnd = "</physDesc>";

static const char *meiExtentBeg = "<extent>";
static const char *meiExtentEnd = "</extent>";

static const char *meiPhysmediumBeg = "<physMedium>";
static const char *meiPhysmediumEnd = "</physMedium>";

static const char *meiConditionBeg = "<condition>";
static const char *meiConditionEnd = "</condition>";

static const char *meiProvenanceBeg = "<provenance>";
static const char *meiProvenanceEnd = "</provenance>";

static const char *meiCorpnameBeg = "<corpName>";
static const char *meiCorpnameEnd = "</corpName>";

static const char *meiHandlistBeg = "<handList>";
static const char *meiHandlistEnd = "</handList>";

static const char *meiHandBeg = "<hand>";
static const char *meiHandAttBeg = "<hand ";
static const char *meiHandEnd = "</hand>";

static const char *meiDimensionsBeg = "<dimensions>";
static const char *meiDimensionsAttBeg = "<dimensions";
static const char *meiDimensionsEnd = "</dimensions>";

static const char *meiWorkBeg = "<work>";
static const char *meiWorkEnd = "</work>";

static const char *meiMusicBeg = "<music>";
static const char *meiMusicEnd = "</music>";

static const char *meiScoreBeg = "<score>";
static const char *meiScoreEnd = "</score>";

static const char *meiScoredefBeg = "<scoreDef>";
static const char *meiScoredefEnd = "</scoreDef>";

static const char *meiStaffgrpBeg = "<staffGrp>";
static const char *meiStaffgrpEnd = "</staffGrp>";
static const char *meiStaffgrpAttBeg = "<staffGrp";

static const char *meiClefBeg = "<clef>";
static const char *meiClefEnd = "</clef>";
static const char *meiClefAttBeg = "<clef";

static const char *meiSectionBeg = "<section>";
static const char *meiSectionEnd = "</section>";

static const char *meiPbBeg = "<pb>";
static const char *meiPbEnd = "</pb>";
static const char *meiPbAttBeg = "<pb";

static const char *meiSbBeg = "<sb>";
static const char *meiSbEnd = "</sb>";
static const char *meiSbAttBeg = "<sb";

static const char *meiSyllableBeg = "<syllable>";
static const char *meiSyllableAttBeg = "<syllable";
static const char *meiSyllableEnd = "</syllable>";

static const char *meiSylBeg = "<syl>";
static const char *meiSylEnd = "</syl>";
static const char *meiSylAttBeg = "<syl";

static const char *meiRendBeg = "<rend>";
static const char *meiRendAttBeg = "<rend";
static const char *meiRendEnd = "</rend>";

static const char *meiNeumeBeg = "<neume>";
static const char *meiNeumeEnd = "</neume>";
static const char *meiNeumeAttBeg = "<neume";

static const char *meiNcBeg = "<nc>";
static const char *meiNcEnd = "</nc>";
static const char *meiNcAttBeg = "<nc";

static const char *meiAnnotBeg = "<annot>";
static const char *meiAnnotEnd = "</annot>";
static const char *meiAnnotAttBeg = "<annot";

static const char *meiAppBeg = "<app>";
static const char *meiAppEnd = "</app>";
static const char *meiAppAttBeg = "<app";

static const char *meiRdgBeg = "<rdg>";
static const char *meiRdgEnd = "</rdg>";
static const char *meiRdgAttBeg = "<rdg";

static const char *meiMdivBeg = "<mdiv>";
static const char *meiMdivEnd = "</mdiv>";

static const char *meiStaffdefBeg = "<staffDef>";
static const char *meiStaffdefAttBeg = "<staffDef";
static const char *meiStaffdefEnd = "</staffDef>";

static const char *meiStaffBeg = "<staff>";
static const char *meiStaffAttBeg = "<staff";
static const char *meiStaffEnd = "</staff>";

static const char *meiPhysicallocationBeg = "<physLoc>";
static const char *meiPhysicallocationEnd = "</physLoc>";

static const char *meiDateBeg = "<date>";
static const char *meiDateEnd = "</date>";

static const char *meiPersnameBeg = "<persName>";
static const char *meiPersnameEnd = "</persName>";

static const char *meiWorkdescBeg = "<workDesc>";
static const char *meiWorkdescEnd = "</workDesc>";

static const char *meiManifestationBeg = "<manifestation>";
static const char *meiManifestationEnd = "</manifestation>";
static const char *meiManifestationAttBeg = "<manifestation";

static const char *meiEncodingDescBeg = "<encodingDesc>";
static const char *meiEncodingDescEnd = "</encodingDesc>";

static const char *meiManifestationListBeg = "<manifestationList>";
static const char *meiManifestationListEnd = "</manifestationList>";

static const char *meiHistoryBeg = "<history>";
static const char *meiHistoryEnd = "</history>";

static const char *meiLayerBeg = "<layer>";
static const char *meiLayerEnd = "</layer>";

static const char *meiRepositoryBeg = "<repository>";
static const char *meiRepositoryEnd = "</repository>";

static const char *meiAddBeg = "<add>";
static const char *meiAddEnd = "</add>";

static const char *meiClassificationBeg = "<classification>";
static const char *meiClassificationEnd = "</classification>";

static const char *meiTermListBeg = "<termList>";
static const char *meiTermListEnd = "</termList>";

static const char *meiBodyBeg = "<body>";
static const char *meiBodyEnd = "</body>";

static const char *meiComponentListBeg = "<componentList>";
static const char *meiComponentListEnd = "</componentList>";

static const char *meiItemBeg = "<item>";
static const char *meiItemEnd = "</item>";

static const char *meiBiblListBeg = "<biblList>";
static const char *meiBiblListEnd = "</biblList>";

static const char *meiBiblBeg = "<bibl>";
static const char *meiBiblEnd = "</bibl>";

#endif // XMLTEXT_H
