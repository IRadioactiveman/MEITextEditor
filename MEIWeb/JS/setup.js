var xmlDoc;
var metaData;
var sources = new Array();
var staffs = new Array();
var syllables = new Array();
var sourceCounter = 0;
var staffCounter = 0;
var meiN = "\n";
var currentStaff;
var currentClef;
var currentClefIndex = 0;
var currentSource;
var currentSyllable;
var currentSyllableIndex = 0;
var currentN;
var currentSID;
var currentType;
var currentColor;
var currentPitch;
var currentVarSource;
var currentVarPitch;
var currentPitchIndex = 0;
var currentVarSourceIndex = 0;
var currentVarPitchIndex = 0;
var types = new Array();
types.push("none");
types.push("apostropha");
types.push("bistropha");
types.push("climacus");
types.push("clivis");
types.push("oriscus");
types.push("pes");
types.push("pessubpuctis");
types.push("porrectus");
types.push("porrectusflexus");
types.push("pressusmaior");
types.push("pressusminor");
types.push("punctum");
types.push("quilisma");
types.push("scandicus");
types.push("strophicus");
types.push("torculus");
types.push("torculusresupinos");
types.push("tristopha");
types.push("virga");
types.push("virgastrata");
var colors = new Array();
colors.push("black");
colors.push();
var multipleSourcesAdded = "";
var variations = new Array();
var pushedVariations = false;
var startY = 5;