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
static const char *meiSourceAtt = " source=";
static const char *meiOctAtt = " oct=";
static const char *meiPnameAtt = " pname=";
static const char *meiStaffAtt = " staff=";
static const char *meiIdrefAtt = " idref=";

static const char *meiMetaText = "";

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

static const char *meiAppstBeg = "<appst>";
static const char *meiAppstEnd = "</appst>";
static const char *meiAppstAttBeg = "<appst";

static const char *meiRdgBeg = "<rdg>";
static const char *meiRdgEnd = "</rdg>";
static const char *meiRdgAttBeg = "<rdg";

#endif // XMLTEXT_H
