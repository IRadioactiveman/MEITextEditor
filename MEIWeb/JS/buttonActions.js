function start(){
    var p = document.getElementById("input");
    p.innerHTML = metaDataForm;
    createSVGOutput();
}

function createMetaData(){
    var title = document.getElementById("title").value;
    var composer = document.getElementById("composer").value;
    var author = document.getElementById("author").value;
    var availability = document.getElementById("availability").value;
    var comment = document.getElementById("comment").value;
    
    metaData = new MetaData(title, composer, author, availability, comment);
    
    document.getElementById("input").innerHTML = sourceForm();
    document.getElementById("meiOutput").value = createMEIOutput();
}

function toSources(){
    document.getElementById("input").innerHTML = sourceForm();
}

function createSource(){
    var composer = document.getElementById("composer").value;
    var title = document.getElementById("title").value;
    var location = document.getElementById("location").value;
    var ownership = document.getElementById("ownership").value;
    var date = document.getElementById("date").value;
    var publicationstatus = document.getElementById("publicationstatus").value;
    var medium = document.getElementById("medium").value;
    var x = document.getElementById("x").value;
    var y = document.getElementById("y").value;
    var unit = document.getElementById("unit").value;
    var condition = document.getElementById("condition").value;
    var extent = document.getElementById("extent").value;
    var language = document.getElementById("language").value;
    var handwriting = document.getElementById("handwriting").value;
    
    currentSource = new Source(composer, title, location, ownership, date, publicationstatus, medium, x, y, unit, condition, extent, language, handwriting);
    
    sources.push(currentSource);
    
    document.getElementById("input").innerHTML = sourceForm();
    document.getElementById("meiOutput").value = createMEIOutput();
}

function toStaffs(){
    document.getElementById("input").innerHTML = staffForm();
}

function createStaff(){
    var linecount = document.getElementById("linecount").value;
    var linecolor = document.getElementById("linecolor").value;
    var mode = document.getElementById("mode").value;
    
    currentStaff = new Staff(linecount, linecolor, mode);
    
    staffs.push(currentStaff);
    
    document.getElementsByClassName("staffdependant")[0].disabled = false;
    
    document.getElementById("input").innerHTML = staffForm();
    document.getElementById("meiOutput").value = createMEIOutput();
}

function createStaffWithClefs(){
    var linecount = document.getElementById("linecount").value;
    var linecolor = document.getElementById("linecolor").value;
    var mode = document.getElementById("mode").value;
    
    currentStaff = new Staff(linecount, linecolor, mode);
    
    staffs.push(currentStaff);
    
    document.getElementById("input").innerHTML = clefForm;
    document.getElementById("meiOutput").value = createMEIOutput();
}

function createClef(){
    var line = document.getElementById("line").value;
    var shape = document.getElementById("shape").value;
    
    var clef = new Clef(line, shape);
    currentStaff.clefs.push(clef);
    
    document.getElementById("input").innerHTML = clefForm;
    document.getElementById("meiOutput").value = createMEIOutput();
}

function createNewStaff(){
    document.getElementById("input").innerHTML = staffForm();
    
    document.getElementsByClassName("staffdependant")[0].disabled = false;
}

function toSyllable(){
    document.getElementById("input").innerHTML = syllableForm();
    document.getElementById("meiOutput").value = createMEIOutput();
}

function createSyllable(){
    var page = document.getElementById("page").value;
    var line = document.getElementById("line").value;
    var staff = document.getElementById("staff").value;
    var syllable = document.getElementById("syllable").value;
    var color = document.getElementById("color").value;
    var type = document.getElementById("type").value;
    var comment = document.getElementById("comment").value;
    
    if(color == "none"){
        color = "black";
    }
    
    currentSyllable = new Syllable(page, line, staff, syllable, color, type , comment);
    syllables.push(currentSyllable);
    
    document.getElementById("meiOutput").value = createMEIOutput();
    document.getElementById("input").innerHTML = syllableForm();
    createSVGOutput();
    
}

function createSyllableWithPitches(){
    
    createSyllable();
    document.getElementById("input").innerHTML = pitchForm();
}

function createPitch(){
    var pitch = document.getElementById("pitch").value;
    var octave = document.getElementById("octave").value;
    var comment = document.getElementById("comment").value;
    var intm = document.getElementById("intm").value;
    var connection = document.getElementById("connection").value;
    var tilt = document.getElementById("tilt").value;
    
    if(currentSyllable.type == "virga" || currentSyllable.type == "punctum"){
        var p = new Pitch(pitch, octave, comment, intm, connection, tilt);
        currentSyllable.pitches.push(p);
    
        document.getElementById("input").innerHTML = syllableForm();
        document.getElementById("meiOutput").value = createMEIOutput();
        createSVGOutput();
        
        return;
    }
    else if(currentSyllable.type == "pes"){
        var p;
        
        p = new Pitch(pitch, octave, comment, intm, connection, tilt);
        currentSyllable.pitches.push(p);
        
        p = new Pitch();
        if(pitch){
            p.pitch = followingNote(pitch);
        }
        p.intm = "u";
        currentSyllable.pitches.push(p);
    
        document.getElementById("input").innerHTML = syllableForm();
        document.getElementById("meiOutput").value = createMEIOutput();
        createSVGOutput();
        
        return;
    }
    else if(currentSyllable.type == "clivis"){
        var p;
        
        p = new Pitch(pitch, octave, comment, intm, connection, tilt);
        currentSyllable.pitches.push(p);
        
        p = new Pitch();
        if(pitch){
            p.pitch = previousNote(pitch);
        }
        p.intm = "d";
        currentSyllable.pitches.push(p);
    
        document.getElementById("input").innerHTML = syllableForm();
        document.getElementById("meiOutput").value = createMEIOutput();
        createSVGOutput();
        
        return;
    }
    else if(currentSyllable.type == "torculus"){
        var p;
        
        p = new Pitch(pitch, octave, comment, intm, connection, tilt);
        currentSyllable.pitches.push(p);
        
        p = new Pitch();
        if(pitch){
            p.pitch = followingNote(pitch);
        }
        p.intm = "u";
        currentSyllable.pitches.push(p);
        
        p = new Pitch();
        if(pitch){
            p.pitch = pitch;
        }
        p.intm = "d";
        currentSyllable.pitches.push(p);
    
        document.getElementById("input").innerHTML = syllableForm();
        document.getElementById("meiOutput").value = createMEIOutput();
        createSVGOutput();
        
        return;
    }
    else if(currentSyllable.type == "porrectus"){
        var p;
        
        p = new Pitch(pitch, octave, comment, intm, connection, tilt);
        currentSyllable.pitches.push(p);
        
        p = new Pitch();
        if(pitch){
            p.pitch = previousNote(pitch);
        }
        p.intm = "d";
        currentSyllable.pitches.push(p);
        
        p = new Pitch();
        if(pitch){
            p.pitch = pitch;
        }
        p.intm = "u";
        currentSyllable.pitches.push(p);
    
        document.getElementById("input").innerHTML = syllableForm();
        document.getElementById("meiOutput").value = createMEIOutput();
        createSVGOutput();
        
        return;
    }
    else if(currentSyllable.type == "climacus"){
        var p;
        
        p = new Pitch(pitch, octave, comment, intm, connection, tilt);
        currentSyllable.pitches.push(p);
        
        p = new Pitch();
        if(pitch){
            p.pitch = previousNote(pitch);
        }
        p.intm = "d";
        currentSyllable.pitches.push(p);
        
        p = new Pitch();
        if(pitch){
            p.pitch = previousNote(previousNote(pitch));
        }
        p.intm = "d";
        currentSyllable.pitches.push(p);
    
        document.getElementById("input").innerHTML = syllableForm();
        document.getElementById("meiOutput").value = createMEIOutput();
        createSVGOutput();
        
        return;
    }
    else if(currentSyllable.type == "scandicus"){
        var p;
        
        p = new Pitch(pitch, octave, comment, intm, connection, tilt);
        currentSyllable.pitches.push(p);
        
        p = new Pitch();
        if(pitch){
            p.pitch = followingNote(pitch);
        }
        p.intm = "u";
        currentSyllable.pitches.push(p);
        
        p = new Pitch();
        if(pitch){
            p.pitch = followingNote(followingNote(pitch));
        }
        p.intm = "u";
        currentSyllable.pitches.push(p);
    
        document.getElementById("input").innerHTML = syllableForm();
        document.getElementById("meiOutput").value = createMEIOutput();
        createSVGOutput();
        
        return;
    } 
    
    var p = new Pitch(pitch, octave, comment, intm, connection, tilt);
    currentSyllable.pitches.push(p);
    
    document.getElementById("input").innerHTML = pitchForm();
    document.getElementById("meiOutput").value = createMEIOutput();
    createSVGOutput();
}

function toVariant(){
    document.getElementById("input").innerHTML = variationForm();
    document.getElementById("meiOutput").value = createMEIOutput();
}

function createVariation(){
    var sourceID = document.getElementById("source").value;
    var pitch = document.getElementById("pitch").value;
    var octave = document.getElementById("octave").value;
    var comment = document.getElementById("comment").value;
    var intm = document.getElementById("intm").value;
    var connection = document.getElementById("connection").value;
    var tilt = document.getElementById("tilt").value;
    
    currentSID = sourceID;
    
    var p = new Pitch(pitch, octave, comment, intm, connection, tilt);
    
    var variationAvailable = false;
    
    var i;
    
    if(variations.length < 1){
        for(i = 0; i < sources.length; i++){
            var variation = new Variation(sources[i].id);
            variations.push(variation);
        }
    }
    
    for(i = 0; i < variations.length; i++){
        if(variations[i].sourceID == sourceID){
            variations[i].additionalPitches.push(p);
            variationAvailable = true;
            break;
        }
    }
    
    if(!pushedVariations){
        currentSyllable.pitches.push(variations);
        pushedVariations = true;
    }
    else{
        currentSyllable.pitches.pop();
        currentSyllable.pitches.push(variations);
    }
    
    document.getElementById("meiOutput").value = createMEIOutput();
    document.getElementById("input").innerHTML = variationForm();
    createSVGOutput();
}

function toSyllableFromVariations(){
    pushedVariations = false;
    variations = new Array();
    
    document.getElementById("input").innerHTML = syllableForm();
    document.getElementById("meiOutput").value = createMEIOutput();
    createSVGOutput();
}

function toPitchesFromVariations(){
    pushedVariations = false;
    variations = new Array();
    
    document.getElementById("input").innerHTML = pitchForm();
    document.getElementById("meiOutput").value = createMEIOutput();
    createSVGOutput();
}

function toChangeValues(){
    document.getElementById("input").innerHTML = changeValueForm();
}

function toChangeMetaData(){
    document.getElementById("input").innerHTML = metaDataChangeForm();
}

function applyMetaDataChanges(){
    var title = document.getElementById("title").value;
    var composer = document.getElementById("composer").value;
    var author = document.getElementById("author").value;
    var availability = document.getElementById("availability").value;
    var comment = document.getElementById("comment").value;
    
    if(title){
        metaData.title = title;
    }
    if(composer){
        metaData.composer = composer;
    }
    if(author){
        metaData.author = author;
    }
    if(availability){
        metaData.availability = availability;
    }
    if(comment){
        metaData.comment = comment;
    }
    
    document.getElementById("input").innerHTML = metaDataChangeForm();
    document.getElementById("meiOutput").value = createMEIOutput();
}

function toChangeSourceData(){
    if(sources.length > 0){
       currentSID = sources[0].id;
    }
    document.getElementById("input").innerHTML = sourceDataChangeForm();
}

function applySourceDataChanges(){
    var composer = document.getElementById("composer").value;
    var title = document.getElementById("title").value;
    var location = document.getElementById("location").value;
    var ownership = document.getElementById("ownership").value;
    var date = document.getElementById("date").value;
    var publicationstatus = document.getElementById("publicationstatus").value;
    var medium = document.getElementById("medium").value;
    var x = document.getElementById("x").value;
    var y = document.getElementById("y").value;
    var unit = document.getElementById("unit").value;
    var condition = document.getElementById("condition").value;
    var extent = document.getElementById("extent").value;
    var language = document.getElementById("language").value;
    var handwriting = document.getElementById("handwriting").value;
    
    if(composer){
        currentSource.composer = composer;
    }
    if(title){
        currentSource.title = title;
    }
    if(location){
        currentSource.location = location;
    }
    if(ownership){
        currentSource.ownership = ownership;
    }
    if(date){
        currentSource.date = date;
    }
    if(publicationstatus){
        currentSource.publicationstatus = publicationstatus;
    }
    if(medium){
        currentSource.medium = medium;
    }
    if(x){
        currentSource.x = x;
    }
    if(y){
        currentSource.y = y;
    }
    if(unit){
        currentSource.unit = unit;
    }
    if(condition){
        currentSource.condition = condition;
    }
    if(extent){
        currentSource.extent = extent;
    }
    if(language){
        currentSource.language = language;
    }
    if(handwriting){
        currentSource.handwriting = handwriting;
    }
    
    document.getElementById("input").innerHTML = sourceDataChangeForm();
    document.getElementById("meiOutput").value = createMEIOutput();
    createSVGOutput();
}

function deleteSource(id){
    var i;
    for(i = 0; i < sources.length; i++){
        if(sources[i].id == id){
            if(sources.length == 1){
                document.getElementById("input").innerHTML = sourceForm();
                document.getElementById("meiOutput").value = createMEIOutput();
                createSVGOutput();
                return;
            }
            else if(i != 0){
                currentSID = sources[i - 1].id;
                currentSource = sources[i - 1];
            }
            else{
                currentSID = sources[i + 1].id;
                currentSource = sources[i + 1];
            }
            sources.splice(i, 1);
        }
    }
    for(i = 0; i < syllables.length; i++){
        for(var j = 0; j < syllables[i].pitches.length; j++){
            if(Array.isArray(syllables[i].pitches[j])){
                for(var k = 0; k < syllables[i].pitches[j].length; k++){
                    if(syllables[i].pitches[j][k].sourceID == id){
                        syllables[i].pitches[j].splice(k, 1);
                    }
                }
            }
        }
    }
    document.getElementById("input").innerHTML = sourceDataChangeForm();
    document.getElementById("meiOutput").value = createMEIOutput();
    createSVGOutput();
}

function toChangeStaffData(){
    if(staffs.length > 0){
       currentN = staffs[0].n;
    }
    document.getElementById("input").innerHTML = staffDataChangeForm();
}

function applyStaffDataChanges(){
    var linecount = document.getElementById("linecount").value;
    var linecolor = document.getElementById("linecolor").value;
    var mode = document.getElementById("mode").value;
    
    if(linecount && linecount != "none"){
        currentStaff.linecount = linecount;
    }
    if(linecolor && linecolor != "none"){
        currentStaff.linecolor = linecolor;
    }
    if(mode && mode != "none"){
        currentStaff.mode = mode;
    }
    document.getElementById("input").innerHTML = staffDataChangeForm();
    document.getElementById("meiOutput").value = createMEIOutput();
    createSVGOutput();
}

function deleteStaff(n){
    var i;
    for(i = 0; i < staffs.length; i++){
        if(staffs[i].n == n){
            if(staffs.length == 1){
                document.getElementById("input").innerHTML = staffForm();
                document.getElementById("meiOutput").value = createMEIOutput();
                createSVGOutput();
                return;
            }
            else if( i != 0){
                currentN = staffs[i-1].n;
                currentStaff = staffs[i-1];
            }
            else{
                currentN = staffs[i + 1].n;
                currentStaff = staffs[i + 1];
            }
            staffs.splice(i, 1);
        }
    }
    for(i = 0; i < syllables.length; i++){
        if(syllables[i].staff.n == n){
            syllables.splice(i, 1);
        }
    }
    
    document.getElementById("input").innerHTML = staffDataChangeForm();
    document.getElementById("meiOutput").value = createMEIOutput();
    createSVGOutput();
}

function toChangeClefData(){
    currentClefIndex = 0;
    document.getElementById("input").innerHTML = clefDataChangeForm();
}

function applyClefDataChanges(){
    var line = document.getElementById("line").value;
    var shape = document.getElementById("shape").value;
    
    if(line && line != "none"){
        currentStaff.clefs[currentClefIndex].line = line;
    }
    if(shape && shape != "none"){
        currentStaffs.clefs[currentClefIndex].shape = shape;
    }
    
    document.getElementById("input").innerHTML = clefDataChangeForm();
    document.getElementById("meiOutput").value = createMEIOutput();
    createSVGOutput();
}

function insertClef(before){
    var line = document.getElementById("line").value;
    var shape = document.getElementById("shape").value;
    
    var clef = new Clef(line, shape);
    if(before){
        currentStaff.clefs.splice(currentClefIndex, 0, clef);
    }
    else{
        currentStaff.clefs.splice(currentClefIndex + 1, 0, clef);
    }
    
    document.getElementById("input").innerHTML = clefDataChangeForm();
    document.getElementById("meiOutput").value = createMEIOutput();
    createSVGOutput();
}

function deleteClef(){
    currentStaff.clefs.splice(currentClefIndex, 1);
    
    currentClefIndex = 0;
    
    document.getElementById("input").innerHTML = clefDataChangeForm();
    document.getElementById("meiOutput").value = createMEIOutput();
    createSVGOutput();
}

function toChangeSyllableData(){
    if(syllables.length > 0){
        currentType = syllables[0].type;
        currentColor = syllables[0].color;
    }
    document.getElementById("input").innerHTML = syllableDataChangeForm();
}

function applySyllableDataChanges(){
    var page = document.getElementById("page").value;
    var line = document.getElementById("line").value;
    var staff = document.getElementById("staff").value;
    var syllable = document.getElementById("syllabletext").value;
    var color = document.getElementById("color").value;
    var type = document.getElementById("type").value;
    var comment = document.getElementById("comment").value;
    
    if(page){
        currentSyllable.page = page;
    }
    if(line){
        currentSyllable.line = line;
    }
    
    if(staff){
        currentSyllable.staff = staff;
    }
    
    if(syllable){
        currentSyllable.syllable = syllable;
    }
    
    if(color && color != "none"){
        currentSyllable.color = color;
    }
    
    if(type){
        currentSyllable.type = type;
    }
    
    if(comment){
        currentSyllable.comment = comment;
    }
    
    document.getElementById("meiOutput").value = createMEIOutput();
    document.getElementById("input").innerHTML = syllableDataChangeForm();
    createSVGOutput();
}

function insertSyllable(before){
    var page = document.getElementById("page").value;
    var line = document.getElementById("line").value;
    var staff = document.getElementById("staff").value;
    var syllable = document.getElementById("syllabletext").value;
    var color = document.getElementById("color").value;
    var type = document.getElementById("type").value;
    var comment = document.getElementById("comment").value;
    
    var syllable = new Syllable(page, line, staff, syllable, color, type , comment);
    if(before){
        syllables.splice(currentSyllableIndex, 0, syllable);
    }
    else{
        syllables.splice(currentSyllableIndex +1, 0, syllable);
    }
    
    document.getElementById("input").innerHTML = syllableDataChangeForm();
    document.getElementById("meiOutput").value = createMEIOutput();
    createSVGOutput();
}

function deleteSyllable(){
    syllables.splice(currentSyllableIndex, 1);
    
    currentSyllableIndex = 0;
    
    document.getElementById("input").innerHTML = syllableDataChangeForm();
    document.getElementById("meiOutput").value = createMEIOutput();
    createSVGOutput();
}

function toChangePitchData(){
    document.getElementById("input").innerHTML = pitchDataChangeForm();
}

function applyPitchDataChanges(){
    var pitch = document.getElementById("pitch").value;
    var octave = document.getElementById("octave").value;
    var comment = document.getElementById("comment").value;
    var intm = document.getElementById("intm").value;
    var connection = document.getElementById("connection").value;
    var tilt = document.getElementById("tilt").value;
    
    if(pitch && pitch != "none"){
        currentPitch.pitch = pitch;
    }
    if(octave && octave != "none"){
        currentPitch.octave = octave;
    }
    if(comment && comment != "none"){
        currentPitch.comment = comment;
    }
    if(intm && intm != "none"){
        currentPitch.intm = intm;
    }
    if(connection && connection != "none"){
        currentPitch.connection = connection;
    }
    if(tilt && tilt != "none"){
        currentPitch.tilt = tilt;
    }
    
    document.getElementById("input").innerHTML = pitchDataChangeForm();
    document.getElementById("meiOutput").value = createMEIOutput();
    createSVGOutput();
}

function insertPitch(before){
    var pitch = document.getElementById("pitch").value;
    var octave = document.getElementById("octave").value;
    var comment = document.getElementById("comment").value;
    var intm = document.getElementById("intm").value;
    var connection = document.getElementById("connection").value;
    var tilt = document.getElementById("tilt").value;
    
    var p = new Pitch(pitch, octave, comment, intm, connection, tilt);
    
    if(before){
        currentSyllable.pitches.splice(currentPitchIndex, 0, p);
    }
    else{
        currentSyllable.pitches.splice(currentPitchIndex + 1, 0, p);
    }
    
    document.getElementById("input").innerHTML = pitchDataChangeForm();
    document.getElementById("meiOutput").value = createMEIOutput();
    createSVGOutput();
}

function deletePitch(){
    currentSyllable.pitches.splice(currentPitchIndex, 1);
    
    currentPitchIndex = 0;
    
    document.getElementById("input").innerHTML = pitchDataChangeForm();
    document.getElementById("meiOutput").value = createMEIOutput();
    createSVGOutput();
}

function createAdditionalVariation(){
    
    variations = new Array();
    
    for(i = 0; i < sources.length; i++){
        var variation = new Variation(sources[i].id);
        variations.push(variation);
    }
    
    currentSyllable.pitches.splice(currentPitchIndex, 0, variations);
    
    document.getElementById("meiOutput").value = createMEIOutput();
    document.getElementById("input").innerHTML = pitchDataChangeForm();
    createSVGOutput();
}

function applyVariationDataChanges(){
    var pitch = document.getElementById("pitch").value;
    var octave = document.getElementById("octave").value;
    var comment = document.getElementById("comment").value;
    var intm = document.getElementById("intm").value;
    var connection = document.getElementById("connection").value;
    var tilt = document.getElementById("tilt").value;
    
    if(pitch && pitch != "none"){
        currentVarPitch.pitch = pitch;
    }
    if(octave && octave != "none"){
        currentVarPitch.octave = octave;
    }
    if(comment && comment != "none"){
        currentPitch.comment = comment;
    }
    if(intm && intm != "none"){
        currentVarPitch.intm = intm;
    }
    if(connection && connection != "none"){
        currentPitch.connection = connection;
    }
    if(tilt && tilt != "none"){
        currentVarPitch.tilt = tilt;
    }
    
    document.getElementById("input").innerHTML = pitchDataChangeForm();
    document.getElementById("meiOutput").value = createMEIOutput();
    createSVGOutput();
}

function insertVariationPitch(before){
    var pitch = document.getElementById("pitch").value;
    var octave = document.getElementById("octave").value;
    var comment = document.getElementById("comment").value;
    var intm = document.getElementById("intm").value;
    var connection = document.getElementById("connection").value;
    var tilt = document.getElementById("tilt").value;
    
    var p = new Pitch(pitch, octave, comment, intm, connection, tilt);
    
    if(before){
        currentSyllable.pitches[currentPitchIndex][currentVarSourceIndex].additionalPitches.splice(currentVarPitchIndex, 0, p);
    }
    else{
        currentSyllable.pitches[currentPitchIndex][currentVarSourceIndex].additionalPitches.splice(currentVarPitchIndex + 1, 0, p);
    }
    
    document.getElementById("input").innerHTML = pitchDataChangeForm();
    document.getElementById("meiOutput").value = createMEIOutput();
    createSVGOutput();
}

function deleteVariationPitch(){
    currentSyllable.pitches[currentPitchIndex][currentVarSourceIndex].additionalPitches.splice(currentVarPitchIndex, 1);
    
    currentVarPitchIndex = 0;
    
    document.getElementById("input").innerHTML = pitchDataChangeForm();
    document.getElementById("meiOutput").value = createMEIOutput();
    createSVGOutput();
}

function applyCurrentSource(){
    currentSID = document.getElementById("source").value;
    document.getElementById("input").innerHTML = sourceDataChangeForm();
}

function applyCurrentStaff(){
    currentN = document.getElementById("staff").value;
    document.getElementById("input").innerHTML = staffDataChangeForm();
}

function applyCurrentClef(){
    currentClefIndex = document.getElementById("clef").value;
    document.getElementById("input").innerHTML = clefDataChangeForm();
}

function applyCurrentSyllable(){
    currentSyllableIndex = document.getElementById("syllable").value;
    document.getElementById("input").innerHTML = syllableDataChangeForm();
}

function applyCurrentPitch(){
    currentPitchIndex = document.getElementById("pitc").value;
    document.getElementById("input").innerHTML = pitchDataChangeForm();
}

function applyCurrentVarSource(){
    currentVarSourceIndex = document.getElementById("varsource").value;
    document.getElementById("input").innerHTML = pitchDataChangeForm();
}

function applyCurrentVariation(){
    currentVarPitchIndex = document.getElementById("varpitch").value;
    document.getElementById("input").innerHTML = pitchDataChangeForm();
}