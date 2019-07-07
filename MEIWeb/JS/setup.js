/**
 * This variable holds the XML document for the MEI file.
 * @var {Object} xmlDoc
 */
var xmlDoc;

/**
 * This variable holds the meta data element.
 * @var {Object} metaData
 */
var metaData;

/**
 * This array contains all the sources.
 * @var {Object} sources
 */
var sources = new Array();

/**
 * This array contains all the staffs.
 * @var {Object} staffs
 */
var staffs = new Array();

/**
 * This array contains all the syllables.
 * @var {Object} syllables
 */
var syllables = new Array();

/**
 * This number gets incremented with each source added for XML ID creation.
 * @var {number} sourceCounter
 */
var sourceCounter = 0;

/**
 * This number gets incremented with each staff added for XML ID creation.
 * @var {number} staffCounter
 */
var staffCounter = 0;

/**
 * This object holds the currently worked on staff.
 * @var {Object} currentStaff
 */
var currentStaff;

/**
 * This object holds the currently worked on clef.
 * @var {Object} currentClef
 */
var currentClef;

/**
 * This variable holds the index of the current clef.
 * @var {number} currentClefIndex
 */
var currentClefIndex = 0;

/**
 * This object holds the currently worked on source.
 * @var {Object} currentSource
 */
var currentSource;

/**
 * This object holds the currently worked on syllable.
 * @var {Object} currentSyllable
 */
var currentSyllable;

/**
 * This variable holds the index of the current syllable.
 * @var {number} currentSyllableIndex
 */
var currentSyllableIndex = 0;

/**
 * This variable holds the n value of the currently worked on staff.
 * @var {number} currentN
 */
var currentN;

/**
 * This string contains the ID of the currently worked on source.
 * @var {string} currentSID
 */
var currentSID;

/**
 * This string contains the type of the currently worked on neume.
 * @var {string} currentType
 */
var currentType;

/**
 * This string contains the color of the currently worked on syllable, initialized with "none".
 * @var {string} currentColor
 */
var currentColor = "none";

/**
 * This object holds the currently worked on neume.
 * @var {Object} currentNeume
 */
var currentNeume;

/**
 * This object holds the index of the currently worked on neume in a variant.
 * @var {Object} currentNeumeInVariationIndex
 */
var currentNeumeInVariationIndex = 0;

/**
 * This object holds the currently worked on pitch.
 * @var {Object} currentPitch
 */
var currentPitch;

/**
 * This object holds the currently worked on pitch of a variant.
 * @var {Object} currentVarPitch
 */
var currentVarPitch;

/**
 * This variable holds the index of the currently worked on neume.
 * @var {number} currentNeumeIndex
 */
var currentNeumeIndex = 0;

/**
 * This variable holds the index of the currently worked on neume variant.
 * @var {number} currentNeumeVariationIndex
 */
var currentNeumeVariationIndex = 0;

/**
 * This variable holds the index of the currently worked on pitch.
 * @var {number} currentPitchIndex
 */
var currentPitchIndex = 0;

/**
 * This variable holds the index of the currently worked on source in a variant.
 * @var {number} currentVarSourceIndex
 */
var currentVarSourceIndex = 0;

/**
 * This variable holds the index of the currently worked on pitch in a variant.
 * @var {number} currentNeumeIndex
 */
var currentVarPitchIndex = 0;

/**
 * This string contains the octave of the currently worked on pitch, initialized with "none".
 * @var {string} currentOctave
 */
var currentOctave = "none";

/**
 * This array contains the types a neume can have.
 * @var {Object} types
 */
var types = new Array();


types.push("none");
types.push("apostropha");
types.push("bistropha");
types.push("climacus");
types.push("clivis");
types.push("oriscus");
types.push("pes");
types.push("pessubpunctis");
types.push("porrectus");
types.push("porrectusflexus");
types.push("pressusmaior");
types.push("pressusminor");
types.push("punctum");
types.push("quilisma");
types.push("scandicus");
types.push("strophicus");
types.push("torculus");
types.push("torculusresupinus");
types.push("tristopha");
types.push("virga");
types.push("virgastrata");

/**
 * This array contains the relational directions a pitch can have.
 * @var {Object} intms
 */
var intms = new Array();


intms.push("none");
intms.push("u");
intms.push("d");
intms.push("s");

/**
 * This array contains the octaves a pitch can have.
 * @var {Object} octaves
 */
var octaves = new Array();


octaves.push("none");
octaves.push("1");
octaves.push("2");
octaves.push("3");
octaves.push("4");
octaves.push("5");

/**
 * This array contains the colors a text or staff can have.
 * @var {Object} colors
 */
var colors = new Array();


colors.push("none");
colors.push("black");
colors.push("red");
colors.push("yellow");
colors.push("blue");
colors.push("green");

/**
 * This array contains pitch variations for each source. It serves as a temporary buffer.
 * @var {Object} variations
 */
var variations = new Array();

/**
 * This array contains neume variations for each source. It serves as a temporary buffer.
 * @var {Object} neumeVariations
 */
var neumeVariations = new Array();

/**
 * This variable indicates whether the pitch variations were pushed into an array of pitches.
 * @var {boolean} pushedVariations
 */
var pushedVariations = false;

/**
 * This variable indicates whether the neume variations were pushed into an array of pitches.
 * @var {boolean} pushedNeumeVariations
 */
var pushedNeumeVariations = false;

/**
 * This variable indicates whether the current neume is a variant.
 * @var {boolean} isNeumeVariant
 */
var isNeumeVariant = false;

/**
 * This variable indicates whether sources are being changed.
 * @var {boolean} isChangingSources
 */
var isChangingSources = false;

/**
 * This variable is the starting Y coordinate of the graphical output.
 * @var {number} startY
 */
var startY = 10;

/**
 * This variable holds the MEI XML output.
 * @var {string} output
 */
var output;

/**
 * This number counts the pitches added for control.
 * @var {number} pitchCounter
 */
var pitchCounter = 0;

/**
 * This string contains the currently selected relational direction of a pitch.
 * @var {string} currentIntm
 */
var currentIntm = "none";

/**
 * This value indicates whether the current type is a climacus for the climacus can have a variable number of pitches. Initially set to false.
 * @var {boolean} isClimacus
 */
var isClimacus = false;

/**
 * This number indicates the maximum number of pitches a neume can have.
 * @var {number} svgNS
 */
var maxPitches;