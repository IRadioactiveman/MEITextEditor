/* This file contains functions that create selectors. That means html elements of the type select, while maintaining the selected option and adding onchange attributes if necessary. */

/**
 * This function creates a selector for neume types.
 * @param {string} onChange - a string representing a function that executes on change of an option
 * @returns {string} s - a string conatining the html select element with the specified options
 */
function createTypeSelector(onChange){
    var s = "";
    s += "<select id=\"type\" width=\"200\"";
    if(onChange){
        s += "onchange=\""+ onChange +"\"";
    }
    s += ">\n";
    for(var i = 0; i < types.length; i++){
        s += "<option value=\""+types[i]+"\"";
        if(currentType == types[i]){
            s += " selected";
        }
        s += ">"+types[i]+"</option>\n";
    }
    s += "</select>\n";
    return s;
}

/**
 * This function creates a selector for octaves.
 * @param {string} onChange - a string representing a function that executes on change of an option
 * @returns {string} s - a string conatining the html select element with the specified options
 */
function createOctaveSelector(onChange){
    var s = "";
    s += "<select id=\"octave\" width=\"200\"";
    if(onChange){
        s += "onchange=\""+ onChange +"\"";
    }
    s += ">\n";
    for(var i = 0; i < octaves.length; i++){
        s += "<option value=\""+octaves[i]+"\"";
        if(currentOctave == octaves[i]){
            s += " selected";
        }
        s += ">"+octaves[i]+"</option>\n";
    }
    s += "</select>\n";
    return s;
}

/**
 * This function creates a selector for colors.
 * @param {string} onChange - a string representing a function that executes on change of an option
 * @returns {string} s - a string conatining the html select element with the specified options
 */
function createColorSelector(onChange){
    var s = "";
    s += "<select id=\"color\" width=\"200\"";
    if(onChange){
        s += "onchange=\""+ onChange +"\"";
    }
    s += ">\n";
    for(var i = 0; i < colors.length; i++){
        s += "<option value=\""+colors[i]+"\"";
        if(currentColor == colors[i]){
            s += " selected";
        }
        s += ">"+colors[i]+"</option>\n";
    }
    s += "</select>\n";
    return s;
}

/**
 * This function creates a selector for pitch relations.
 * @param {string} onChange - a string representing a function that executes on change of an option
 * @returns {string} s - a string conatining the html select element with the specified options
 */
function createIntmSelector(){
     var s = "";
    s += "<select id=\"intm\" width=\"200\">\n";
    for(var i = 0; i < intms.length; i++){
        s += "<option value=\""+intms[i]+"\"";
        if(currentIntm == intms[i]){
            s += " selected";
        }
        s += ">";
        if(intms[i] == "u"){
            s += "went up";
        }
        else if(intms[i] == "d"){
            s += "went down";
        }
        else if(intms[i] == "s"){
            s += "same";
        }
        else{
            s += "none";
        }
            
        s += "</option>\n";
    }
    s += "</select>\n";
    return s;
}

/**
 * This function creates a selector for staffs.
 * @param {string} onChange - a string representing a function that executes on change of an option
 * @returns {string} s - a string conatining the html select element with the specified options
 */
function createStaffSelector(onChange){ 
    var s = "";
    s += "<select id=\"staff\" width=\"200\"";
    if(onChange){
        s += "onchange=\""+ onChange +"\"";
    }
    s += ">\n";
    for(var i = 0; i < staffs.length; i++){
        s += "<option value=\""+staffs[i].n+"\"";
        if(currentN == staffs[i].n){
            s += " selected";
        }
        s += ">"+staffs[i].id+"</option>\n";
    }
    s += "</select>\n";
    return s;
}

/**
 * This function creates a selector for sources.
 * @param {string} onChange - a string representing a function that executes on change of an option
 * @returns {string} s - a string conatining the html select element with the specified options
 */
function createSourceSelector(onChange){ 
    var s = "";
    s += "<select id=\"source\" width=\"200\"";
    if(onChange){
        s += "onchange=\""+ onChange +"\"";
    }
    s += ">\n";
    for(var i = 0; i < sources.length; i++){
        s += "<option value=\""+sources[i].id+"\""
        if(currentSID == sources[i].id){
            s += " selected";
        }
        s += ">"+sources[i].id+"</option>\n";
    }
    s += "</select>\n";
    return s;
}

/**
 * This function creates a selector for supplied sources.
 * @param {string} onChange - a string representing a function that executes on change of an option
 * @returns {string} s - a string conatining the html select element with the specified options
 */
function createSuppliedSourceSelector(onChange){ 
    var s = "";
    s += "<select id=\"supplied\" width=\"200\"";
    if(onChange){
        s += "onchange=\""+ onChange +"\"";
    }
    s += ">\n";
    s += "<option value=\"none\">none</option>\n";
    for(var i = 0; i < sources.length; i++){
        s += "<option value=\""+sources[i].id+"\">"+sources[i].id+"</option>\n";
    }
    s += "</select>";
    return s;
}

/**
 * This function creates a selector for clefs.
 * @param {string} onChange - a string representing a function that executes on change of an option
 * @returns {string} s - a string conatining the html select element with the specified options
 */
function createClefSelector(staff, onChange){
    var s = "";
    s += "<select id=\"clef\" width=\"200\"";
    if(onChange){
        s += "onchange=\""+ onChange +"\"";
    }
    s += ">\n";
    for(var i = 0; i < staff.clefs.length; i++){
        s += "<option value=\""+i+"\""
        if(currentClefIndex == i){
            s += " selected";
        }
        s += ">Clef "+(i+1)+"</option>\n";
    }
    s += "</select>\n";
    return s;
}

/**
 * This function creates a selector for syllables.
 * @param {string} onChange - a string representing a function that executes on change of an option
 * @returns {string} s - a string conatining the html select element with the specified options
 */
function createSyllableSelector(onChange){
    var s ="";
     s += "<select id=\"syllable\" width=\"200\"";
    if(onChange){
        s += "onchange=\""+ onChange +"\"";
    }
    s += ">\n";
    for(var i = 0; i < syllables.length; i++){
        s += "<option value=\""+i+"\""
        if(currentSyllableIndex == i){
            s += " selected";
        }
        
        s += ">"+syllables[i].syllable+"</option>\n";
    }
    s += "</select>\n";
    return s;
}

/**
 * This function creates a selector for neumes.
 * @param {string} onChange - a string representing a function that executes on change of an option
 * @returns {string} s - a string conatining the html select element with the specified options
 */
function createNeumeSelector(onChange){
    var s ="";
     s += "<select id=\"neume\" width=\"200\"";
    if(onChange){
        s += "onchange=\""+ onChange +"\"";
    }
    s += ">";
    for(var i = 0; i < currentSyllable.neumes.length; i++){
        s += "<option value=\""+i+"\""
        if(currentNeumeIndex == i){
            s += " selected";
        }
        
        if(Array.isArray(currentSyllable.neumes[i])){
            s += ">Variation</option>";
        }
        else{
            s += ">"+currentSyllable.neumes[i].type+"</option>";
        }
    }
    s += "</select>";
    return s;
}

/**
 * This function creates a selector for variants of neumes.
 * @param {string} onChange - a string representing a function that executes on change of an option
 * @returns {string} s - a string conatining the html select element with the specified options
 */
function createNeumeVariationSelector(onChange){
    var s ="";
     s += "<select id=\"neumevariation\" width=\"200\"";
    if(onChange){
        s += "onchange=\""+ onChange +"\"";
    }
    s += ">";
    for(var i = 0; i < currentSyllable.neumes[currentNeumeIndex].length; i++){
        s += "<option value=\""+i+"\""
        if(currentNeumeVariationIndex == i){
            s += " selected";
        }
        s += ">"+currentSyllable.neumes[currentNeumeIndex][i].sourceID+"</option>";
    }
    s += "</select>";
    return s;
}

/**
 * This function creates a selector neumes in variants of neumes.
 * @param {string} onChange - a string representing a function that executes on change of an option
 * @returns {string} s - a string conatining the html select element with the specified options
 */
function createNeumeInVariationSelector(onChange){
    var s ="";
     s += "<select id=\"neumeinvariation\" width=\"200\"";
    if(onChange){
        s += "onchange=\""+ onChange +"\"";
    }
    s += ">";
    for(var i = 0; i < currentSyllable.neumes[currentNeumeIndex][currentNeumeVariationIndex].additionalNeumes.length; i++){
        s += "<option value=\""+i+"\""
        if(currentNeumeInVariationIndex == i){
            s += " selected";
        }
        s += ">" + currentSyllable.neumes[currentNeumeIndex][currentNeumeVariationIndex].additionalNeumes[i].type;
    }
    
    s += "</select>";
    return s;
}


/**
 * This function creates a selector for pitches.
 * @param {string} onChange - a string representing a function that executes on change of an option
 * @returns {string} s - a string conatining the html select element with the specified options
 */
function createPitchSelector(onChange){
    var s ="";
     s += "<select id=\"pitc\" width=\"200\"";
    if(onChange){
        s += "onchange=\""+ onChange +"\"";
    }
    s += ">\n";
    for(var i = 0; i < currentNeume.pitches.length; i++){
        s += "<option value=\""+i+"\""
        if(currentPitchIndex == i){
            s += " selected";
        }
        if(Array.isArray(currentNeume.pitches[i])){
            s += ">Variation</option>\n";
        }
        else{
            s += ">"+ currentNeume.pitches[i].pitch+"</option>\n";
        }
    }
    s += "</select>\n";
    return s;
}

/**
 * This function creates a selector for pitches of a variation.
 * @param {string} onChange - a string representing a function that executes on change of an option
 * @returns {string} s - a string conatining the html select element with the specified options
 */
function createVarPitchSelector(onChange){
    var s ="";
     s += "<select id=\"varpitch\" width=\"200\"";
    if(onChange){
        s += "onchange=\""+ onChange +"\"";
    }
    s += ">\n";
    for(var i = 0; i < currentNeume.pitches[currentPitchIndex][currentVarSourceIndex].additionalPitches.length; i++){
        s += "<option value=\""+i+"\""
        if(currentVarPitchIndex == i){
            s += " selected";
        }
        s += ">"+ currentNeume.pitches[currentPitchIndex][currentVarSourceIndex].additionalPitches[i].pitch +"</option>\n";
    }
    s += "</select>\n";
    return s;
}

/**
 * This function creates a selector for the source of a variation.
 * @param {string} onChange - a string representing a function that executes on change of an option
 * @returns {string} s - a string conatining the html select element with the specified options
 */
function createVarSourceSelector(onChange){
    var s ="";
     s += "<select id=\"varsource\" width=\"200\"";
    if(onChange){
        s += "onchange=\""+ onChange +"\"";
    }
    s += ">\n";
    for(var i = 0; i < currentNeume.pitches[currentPitchIndex].length; i++){
        s += "<option value=\""+i+"\"";
        if(currentVarSourceIndex == i){
            s += " selected";
        }
        s += ">"+ currentNeume.pitches[currentPitchIndex][i].sourceID +"</option>\n";
    }
    s += "</select>\n";
    return s;
}