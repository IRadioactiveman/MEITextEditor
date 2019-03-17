function createTypeSelector(){
    var s = "";
    s += "<select id=\"type\" width=\"200\">\n";
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

function createPitchSelector(onChange){
    var s ="";
     s += "<select id=\"pitc\" width=\"200\"";
    if(onChange){
        s += "onchange=\""+ onChange +"\"";
    }
    s += ">\n";
    for(var i = 0; i < currentSyllable.pitches.length; i++){
        s += "<option value=\""+i+"\""
        if(currentPitchIndex == i){
            s += " selected";
        }
        if(Array.isArray(currentSyllable.pitches[i])){
            s += ">Variation</option>\n";
        }
        else{
            s += ">"+ currentSyllable.pitches[i].pitch+"</option>\n";
        }
    }
    s += "</select>\n";
    return s;
}

function createVarPitchSelector(onChange){
    var s ="";
     s += "<select id=\"varpitch\" width=\"200\"";
    if(onChange){
        s += "onchange=\""+ onChange +"\"";
    }
    s += ">\n";
    for(var i = 0; i < currentSyllable.pitches[currentPitchIndex][currentVarSourceIndex].additionalPitches.length; i++){
        s += "<option value=\""+i+"\""
        if(currentVarPitchIndex == i){
            s += " selected";
        }
        s += ">"+ currentSyllable.pitches[currentPitchIndex][currentVarSourceIndex].additionalPitches[i].pitch +"</option>\n";
    }
    s += "</select>\n";
    return s;
}

function createVarSourceSelector(onChange){
    var s ="";
     s += "<select id=\"varsource\" width=\"200\"";
    if(onChange){
        s += "onchange=\""+ onChange +"\"";
    }
    s += ">\n";
    for(var i = 0; i < currentSyllable.pitches[currentPitchIndex].length; i++){
        s += "<option value=\""+i+"\"";
        if(currentVarSourceIndex == i){
            s += " selected";
        }
        s += ">"+ currentSyllable.pitches[currentPitchIndex][i].sourceID +"</option>\n";
    }
    s += "</select>\n";
    return s;
}