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
var currentColor = "none";
var currentNeume;
var currentPitch;
var currentVarSource;
var currentVarPitch;
var currentNeumeIndex = 0;
var currentPitchIndex = 0;
var currentVarSourceIndex = 0;
var currentVarPitchIndex = 0;
var currentOctave = "none";
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
var intms = new Array();
intms.push("none");
intms.push("u");
intms.push("d");
intms.push("s");
var octaves = new Array();
octaves.push("none");
octaves.push("1");
octaves.push("2");
octaves.push("3");
octaves.push("4");
octaves.push("5");
var colors = new Array();
colors.push("none");
colors.push("black");
colors.push("red");
colors.push("yellow");
colors.push("blue");
colors.push("green");
var multipleSourcesAdded = "";
var variations = new Array();
var pushedVariations = false;
var startY = 10;
var output;
var pitchCounter = 0;
var currentIntm = "none";
var svgNS = "http://www.w3.org/2000/svg";
var svg = document.createElementNS(svgNS, "svg");
var isClimacus = false;
var maxPitches;