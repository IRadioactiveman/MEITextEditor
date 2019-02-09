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
static const char *meiAttUnits = " units=";
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

static const char *meiTextBeg = "<mei>";
static const char *meiTextEnd = "</mei>";

static const char *meiHeaderBeg = "<meiHead>";
static const char *meiHeaderEnd = "</meiHead>";

static const char *meiIdBeg = "<meiid>";
static const char *meiIdEnd = "</meiid>";

static const char *meiTitleBeg = "<title>";
static const char *meiTitleEnd = "</title>";

static const char *meiTitlestmtBeg = "<titlestmt>";
static const char *meiTitlestmtEnd = "</titlestmt>";

static const char *meiResponsibilityBeg = "<respstmt>";
static const char *meiResponsibilityEnd = "</respstmt>";

static const char *meiAgentBeg = "<agent>";
static const char *meiAgentEnd = "</agent>";

static const char *meiPublicationBeg = "<pubstmt>";
static const char *meiPublicationEnd = "</pubstmt>";

static const char *meiAvailabilityBeg = "<availability>";
static const char *meiAvailabilityEnd = "</availability>";

static const char *meiUserestrictBeg = "<userestrict>";
static const char *meiUserestrictEnd = "</userestrict>";

static const char *meiFiledescriptionBeg = "<filedesc>";
static const char *meiFiledescriptionEnd = "</filedesc>";

static const char *meiEditorialdeclarationBeg = "<editorialdecl>";
static const char *meiEditorialdeclarationEnd = "</editorialdecl>";

static const char *meiParagraphBeg = "<p>";
static const char *meiParagraphEnd = "</p>";

static const char *meiProfiledescriptionBeg = "<profiledesc>";
static const char *meiProfiledescriptionEnd = "</profiledesc>";

static const char *meiLangusageBeg = "<langusage>";
static const char *meiLangusageEnd = "</langusage>";

static const char *meiLanguageBeg = "<language>";
static const char *meiLanguageEnd = "</language>";

static const char *meiMusicclassBeg = "<musicclass>";
static const char *meiMusicclassEnd = "</musicclass>";

static const char *meiKeywordsBeg = "<keywords>";
static const char *meiKeywordsEnd = "</keywords>";

static const char *meiTermBeg = "<term>";
static const char *meiTermEnd = "</term>";

static const char *meiSourcedescriptionBeg = "<sourcedesc>";
static const char *meiSourcedescriptionEnd = "</sourcedesc>";

static const char *meiSourceBeg = "<source>";
static const char *meiSourceAttBeg = "<source";
static const char *meiSourceEnd = "</source>";

static const char *meiPhysdescriptionBeg = "<physdesc>";
static const char *meiPhysdescriptionEnd = "</physdesc>";

static const char *meiExtentBeg = "<extent>";
static const char *meiExtentEnd = "</extent>";

static const char *meiPhysmediumBeg = "<physmedium>";
static const char *meiPhysmediumEnd = "</physmedium>";

static const char *meiConditionBeg = "<condition>";
static const char *meiConditionEnd = "</condition>";

static const char *meiProvenanceBeg = "<provenance>";
static const char *meiProvenanceEnd = "</provenance>";

static const char *meiCorpnameBeg = "<corpname>";
static const char *meiCorpnameEnd = "</corpname>";

static const char *meiHandlistBeg = "<handlist>";
static const char *meiHandlistEnd = "</handlist>";

static const char *meiHandBeg = "<hand>";
static const char *meiHandAttBeg = "<hand ";
static const char *meiHandEnd = "</hand>";

static const char *meiPubstatusBeg = "<pubstatus>";
static const char *meiPubstatusEnd = "</pubstatus>";

static const char *meiDimensionsBeg = "<dimensions>";
static const char *meiDimensionsAttBeg = "<dimensions";
static const char *meiDimensionsEnd = "</dimensions>";

static const char *meiWorkBeg = "<work>";
static const char *meiWorkEnd = "</work>";

static const char *meiMusicBeg = "<music>";
static const char *meiMusicEnd = "</music>";

static const char *meiScoreBeg = "<score>";
static const char *meiScoreEnd = "</score>";

static const char *meiScoredefBeg = "<scoredef>";
static const char *meiScoredefEnd = "</scoredef>";

static const char *meiStaffgrpBeg = "<staffgrp>";
static const char *meiStaffgrpEnd = "</staffgrp>";
static const char *meiStaffgrpAttBeg = "<staffgrp";

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

static const char *meiStaffdefBeg = "<staffdef>";
static const char *meiStaffdefAttBeg = "<staffdef";
static const char *meiStaffdefEnd = "</staffdef>";

static const char *meiStaffBeg = "<staff>";
static const char *meiStaffAttBeg = "<staff";
static const char *meiStaffEnd = "</staff>";

static const char *meiPhysicallocationBeg = "<physloc>";
static const char *meiPhysicallocationEnd = "</physloc>";

static const char *meiDateBeg = "<date>";
static const char *meiDateEnd = "</date>";

#endif // XMLTEXT_H
