/* In this file, all possible actions that can be triggered by a button with the onclick attribute will be implemented.*/

/** This function represents the starting point of the program, leading straight to entering meta data and initializes the SVG output.*/
function start(){
    var p = document.getElementById("input");
    p.innerHTML = metaDataForm;
    createSVGOutput();
}

/** Reads the data entered in the meta data form and saves it, leading to the source form afterwards.*/
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

/** Navigational, leads to sources form.*/
function toSources(){
    document.getElementById("input").innerHTML = sourceForm();
}

/** Reads the data entered in the source form and saves it, leading to the staff form afterwards.*/
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

/** Navigational, leads to staff form.*/
function toStaffs(){
    document.getElementById("input").innerHTML = staffForm();
}

/** Reads the data entered in the staff form and saves it.*/
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

/** Reads the data entered in the staff form and saves it, leading to the clef form afterwards.*/
function createStaffWithClefs(){
    var linecount = document.getElementById("linecount").value;
    var linecolor = document.getElementById("linecolor").value;
    var mode = document.getElementById("mode").value;
    
    currentStaff = new Staff(linecount, linecolor, mode);
    
    staffs.push(currentStaff);
    
    document.getElementById("input").innerHTML = clefForm;
    document.getElementById("meiOutput").value = createMEIOutput();
}

/** Reads the data entered in the clef form and saves it.*/
function createClef(){
    var line = document.getElementById("line").value;
    var shape = document.getElementById("shape").value;
    
    var clef = new Clef(line, shape);
    currentStaff.clefs.push(clef);
    
    document.getElementById("input").innerHTML = clefForm;
    document.getElementById("meiOutput").value = createMEIOutput();
}

/** Navigational, leads to staff form.*/
function createNewStaff(){
    document.getElementById("input").innerHTML = staffForm();
    
    document.getElementsByClassName("staffdependant")[0].disabled = false;
}

/** Navigational, leads to syllable form.*/
function toSyllable(){
    document.getElementById("input").innerHTML = syllableForm();
    document.getElementById("meiOutput").value = createMEIOutput();
}

/** Navigational, leads to neume form.*/
function toNeume(){
    document.getElementById("input").innerHTML = neumeForm();
    document.getElementById("meiOutput").value = createMEIOutput();
}

/** Reads the data entered in the syllable form and saves it.*/
function createSyllable(){
    var page = document.getElementById("page").value;
    var line = document.getElementById("line").value;
    var staff = document.getElementById("staff").value;
    var syllable = document.getElementById("syllable").value;
    var initial = document.getElementById("initial").checked;
    var color = document.getElementById("color").value;
    var comment = document.getElementById("comment").value;
    
    currentSyllable = new Syllable(page, line, staff, syllable, initial, color, comment);
    
    syllables.push(currentSyllable);
    
    document.getElementById("meiOutput").value = createMEIOutput();
    document.getElementById("input").innerHTML = syllableForm();
    createSVGOutput();
    
}

/** Reads the data entered in the syllable form and saves it, leading to the neume form afterwards.*/
function createSyllableWithNeumes(){
    
    var page = document.getElementById("page").value;
    var line = document.getElementById("line").value;
    var staff = document.getElementById("staff").value;
    var syllable = document.getElementById("syllable").value;
    var initial = document.getElementById("initial").checked;
    var color = document.getElementById("color").value;
    var comment = document.getElementById("comment").value;
    
    currentSyllable = new Syllable(page, line, staff, syllable, initial, color, comment);
    
    syllables.push(currentSyllable);
    
    document.getElementById("meiOutput").value = createMEIOutput();
    document.getElementById("input").innerHTML = neumeForm();
    createSVGOutput();
}

/** Reads the data entered in the neume form and saves it. If no pitch is given and the neume type is virga, punctum, pes, clivis, torculus, porrectus, scandicus or climacus, all needed pitches will be automatically added.*/
function createNeume(){
    var type = document.getElementById("type").value;
    
    if(isClimacus){
        maxPitches = document.getElementById("numberofpitches").value;
    }
    
    currentNeume = new Neume();
    currentNeume.type = type;
    
    if(type == "virga" || type == "punctum"){
        var p = new Pitch();
        p.pitch = "none";
        currentNeume.pitches.push(p);
    }
    else if(currentNeume.type == "pes"){
        var p;
        
        p = new Pitch();
        p.pitch = "none";
        currentNeume.pitches.push(p);
        
        p = new Pitch();
        p.pitch = "none";
        p.intm = "u";
        currentNeume.pitches.push(p);
    }
    else if(currentNeume.type == "clivis"){
        var p;
        
        p = new Pitch();
        p.pitch = "none";
        currentNeume.pitches.push(p);
        
        p = new Pitch();
        p.pitch = "none";
        p.intm = "d";
        currentNeume.pitches.push(p);
    }
    else if(currentNeume.type == "torculus"){
        var p;
        
        p = new Pitch();
        p.pitch = "none";
        currentNeume.pitches.push(p);
        
        p = new Pitch();
        p.pitch = "none";
        p.intm = "u";
        currentNeume.pitches.push(p);
        
        p = new Pitch();
        p.pitch = "none";
        p.intm = "d";
        currentNeume.pitches.push(p);
    }
    else if(currentNeume.type == "porrectus"){
        var p;
        
        p = new Pitch();
        p.pitch = "none";
        currentNeume.pitches.push(p);
        
        p = new Pitch();
        p.pitch = "none";
        p.intm = "d";
        currentNeume.pitches.push(p);
        
        p = new Pitch();
        p.pitch = "none";
        p.intm = "u";
        currentNeume.pitches.push(p);
    }
    else if(currentNeume.type == "climacus"){
        var p;
        
        p = new Pitch();
        p.pitch = "none";
        currentNeume.pitches.push(p);
        
        p = new Pitch();
        p.pitch = "none";
        p.intm = "d";
        currentNeume.pitches.push(p);
        
        p = new Pitch();
        p.pitch = "none";
        p.intm = "d";
        currentNeume.pitches.push(p);
        
        if(maxPitches == 4){
            p = new Pitch();
            p.pitch = "none";
            p.intm = "d";
            currentNeume.pitches.push(p);
        }
        
        if(maxPitches == 5){
            p = new Pitch();
            p.pitch = "none";
            p.intm = "d";
            currentNeume.pitches.push(p);
            
            p = new Pitch();
            p.pitch = "none";
            p.intm = "d";
            currentNeume.pitches.push(p);
        }
    }
    else if(currentNeume.type == "scandicus"){
        var p;
        
        p = new Pitch();
        p.pitch = "none";
        currentNeume.pitches.push(p);
        
        p = new Pitch();
        p.pitch = "none";
        p.intm = "u";
        currentNeume.pitches.push(p);
        
        p = new Pitch();
        p.pitch = "none";
        p.intm = "u";
        currentNeume.pitches.push(p);
    }
    
    currentSyllable.neumes.push(currentNeume);
    document.getElementById("meiOutput").value = createMEIOutput();
    document.getElementById("input").innerHTML = neumeForm();
    createSVGOutput();
}

/** Reads the data entered in the neume form and saves it, leading to the pitch form afterwards.*/
function createNeumeWithPitches(){
    var type = document.getElementById("type").value;
    
    if(isClimacus){
        maxPitches = document.getElementById("numberofpitches").value;
    }
    
    currentNeume = new Neume();
    currentNeume.type = type;
    
    currentSyllable.neumes.push(currentNeume);
    document.getElementById("meiOutput").value = createMEIOutput();
    document.getElementById("input").innerHTML = pitchForm();
    createSVGOutput();
}

/** Reads the data entered in the neume form and saves it. Thereby the function controls the length and intervals for neumes of the types virga, punctum, pes, clivis, torculus, porrectus, scandicus and climacus. Also if the first pitch is not specified for the previously mentioned types, the function will automatically generate the rest of the neume.*/
function createPitch(){
    var pitch = document.getElementById("pitch").value;
    var octave = document.getElementById("octave").value;
    var comment = document.getElementById("comment").value;
    var intm = document.getElementById("intm").value;
    var connection = document.getElementById("connection").value;
    var tilt = document.getElementById("tilt").value;
    var variation = document.getElementById("variation").value;
    
    var p = new Pitch(pitch, octave, comment, intm, connection, tilt, variation);
    currentNeume.pitches.push(p);
    
    if(currentNeume.type == "virga" || currentNeume.type == "punctum"){
        document.getElementById("input").innerHTML = neumeForm();
    }
    else if(currentNeume.type == "pes"){
        if(pitch == "none" && pitchCounter == 0){
            p = new Pitch(pitch, octave, comment, intm, connection, tilt);
            p.intm = "u";
            currentNeume.pitches.push(p);
            document.getElementById("input").innerHTML = neumeForm();
        }
        else if(pitchCounter == 0){
            currentIntm = "u";
            pitchCounter++;
            document.getElementById("input").innerHTML = pitchForm();
        }
        else if(pitchCounter == 1)
        {
            currentIntm = "none";
            pitchCounter = 0;
            document.getElementById("input").innerHTML = neumeForm();
        }
    }
    else if(currentNeume.type == "clivis"){
        if(pitch == "none" && pitchCounter == 0){
            p = new Pitch(pitch, octave, comment, intm, connection, tilt);
            p.intm = "d";
            currentNeume.pitches.push(p);
            document.getElementById("input").innerHTML = neumeForm();
        }
        else if(pitchCounter == 0){
            currentIntm = "d";
            pitchCounter++;
            document.getElementById("input").innerHTML = pitchForm();
        }
        else if(pitchCounter == 1)
        {
            currentIntm = "none";
            pitchCounter = 0;
            document.getElementById("input").innerHTML = neumeForm();
        }
    }
    else if(currentNeume.type == "torculus"){
        if(pitch == "none" && pitchCounter == 0){
            p = new Pitch(pitch, octave, comment, intm, connection, tilt);
            p.intm = "u";
            currentNeume.pitches.push(p);
            
            p = new Pitch(pitch, octave, comment, intm, connection, tilt);
            p.intm = "d";
            currentNeume.pitches.push(p);
            
            document.getElementById("input").innerHTML = neumeForm();
        }
        else if(pitchCounter == 0){
            currentIntm = "u";
            pitchCounter++;
            document.getElementById("input").innerHTML = pitchForm();
        }
        else if(pitchCounter == 1)
        {
            currentIntm = "d";
            pitchCounter++;
            document.getElementById("input").innerHTML = pitchForm();
        }
        else if(pitchCounter == 2)
        {
            currentIntm = "none";
            pitchCounter = 0;
            document.getElementById("input").innerHTML = neumeForm();
        }
    }
    else if(currentNeume.type == "porrectus"){
        if(pitch == "none" && pitchCounter == 0){
            p = new Pitch(pitch, octave, comment, intm, connection, tilt);
            p.intm = "u";
            currentNeume.pitches.push(p);
            
            p = new Pitch(pitch, octave, comment, intm, connection, tilt);
            p.intm = "d";
            currentNeume.pitches.push(p);
            
            document.getElementById("input").innerHTML = neumeForm();
        }
        else if(pitchCounter == 0){
            currentIntm = "d";
            pitchCounter++;
            document.getElementById("input").innerHTML = pitchForm();
        }
        else if(pitchCounter == 1)
        {
            currentIntm = "u";
            pitchCounter++;
            document.getElementById("input").innerHTML = pitchForm();
        }
        else if(pitchCounter == 2)
        {
            currentIntm = "none";
            pitchCounter = 0;
            document.getElementById("input").innerHTML = neumeForm();
        }
    }
    else if(currentNeume.type == "climacus"){
        if(pitch == "none" && pitchCounter == 0){
            p = new Pitch(pitch, octave, comment, intm, connection, tilt);
            p.intm = "u";
            currentNeume.pitches.push(p);
            
            p = new Pitch(pitch, octave, comment, intm, connection, tilt);
            p.intm = "d";
            currentNeume.pitches.push(p);
            
            document.getElementById("input").innerHTML = neumeForm();
        }
        else if(pitchCounter == 0){
            currentIntm = "d";
            pitchCounter++;
            document.getElementById("input").innerHTML = pitchForm();
        }
        else if(pitchCounter == 1)
        {
            currentIntm = "d";
            pitchCounter++;
            document.getElementById("input").innerHTML = pitchForm();
        }
        else if(pitchCounter == 2)
        {
            if(maxPitches == 4 || maxPitches == 5){
                currentIntm = "d";
                pitchCounter++;
                document.getElementById("input").innerHTML = pitchForm();
            }
            else{
                currentIntm = "none";
                pitchCounter = 0;
                document.getElementById("input").innerHTML = neumeForm();
            }
        }
        else if(pitchCounter == 3)
        {
            if(maxPitches == 5){
                currentIntm = "d";
                pitchCounter++;
                document.getElementById("input").innerHTML = pitchForm();
            }
            else{
                currentIntm = "none";
                pitchCounter = 0;
                document.getElementById("input").innerHTML = neumeForm();
            }
        }
        else if(pitchCounter == 4)
        {
            currentIntm = "none";
            pitchCounter = 0;
            document.getElementById("input").innerHTML = neumeForm(); 
        }
    }
    else if(currentNeume.type == "scandicus"){
        if(pitch == "none" && pitchCounter == 0){
            p = new Pitch(pitch, octave, comment, intm, connection, tilt);
            p.intm = "u";
            currentNeume.pitches.push(p);
            
            p = new Pitch(pitch, octave, comment, intm, connection, tilt);
            p.intm = "d";
            currentNeume.pitches.push(p);
            
            document.getElementById("input").innerHTML = neumeForm();
        }
        else if(pitchCounter == 0){
            currentIntm = "u";
            pitchCounter++;
            document.getElementById("input").innerHTML = pitchForm();
        }
        else if(pitchCounter == 1)
        {
            currentIntm = "u";
            pitchCounter++;
            document.getElementById("input").innerHTML = pitchForm();
        }
        else if(pitchCounter == 2)
        {
            currentIntm = "none";
            pitchCounter = 0;
            document.getElementById("input").innerHTML = neumeForm();
        }
    } 
    else{
        document.getElementById("input").innerHTML = pitchForm();
    }
    
    document.getElementById("meiOutput").value = createMEIOutput();
    createSVGOutput();
}

/** Navigational, leads to variant form.*/
function toVariant(){
    document.getElementById("input").innerHTML = variationForm();
    document.getElementById("meiOutput").value = createMEIOutput();
}

/** Reads the data entered in the variant form and saves it.*/
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
        currentNeume.pitches.push(variations);
        pushedVariations = true;
    }
    else{
        currentNeume.pitches.pop();
        currentNeume.pitches.push(variations);
    }
    
    document.getElementById("meiOutput").value = createMEIOutput();
    document.getElementById("input").innerHTML = variationForm();
    createSVGOutput();
}

/** Navigational, leads to variation form and resets variations.*/
function toSyllableFromVariations(){
    pushedVariations = false;
    variations = new Array();
    
    document.getElementById("input").innerHTML = syllableForm();
    document.getElementById("meiOutput").value = createMEIOutput();
    createSVGOutput();
}

/** Navigational, leads to neume form and resets variations.*/
function toNeumeFromVariations(){
    pushedVariations = false;
    variations = new Array();
    
    document.getElementById("input").innerHTML = neumeForm();
    document.getElementById("meiOutput").value = createMEIOutput();
    createSVGOutput();
}

/** Navigational, leads to pitch form and resets variations.*/
function toPitchesFromVariations(){
    pushedVariations = false;
    variations = new Array();
    
    document.getElementById("input").innerHTML = pitchForm();
    document.getElementById("meiOutput").value = createMEIOutput();
    createSVGOutput();
}

/** Navigational, leads to change values form.*/
function toChangeValues(){
    document.getElementById("input").innerHTML = changeValueForm();
}

/** Navigational, leads to meta data change form.*/
function toChangeMetaData(){
    document.getElementById("input").innerHTML = metaDataChangeForm();
}

/** Applies changes made to meta data*/
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

/** Navigational, leads to change sources form.*/
function toChangeSourceData(){
    if(sources.length > 0){
       currentSID = sources[0].id;
    }
    document.getElementById("input").innerHTML = sourceDataChangeForm();
}

/** Applies cahnges made to a specified source.*/
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

/** Deletes the selected source and adjusts variations.*/
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
        for(var j = 0; j < syllables[i].neumes.length; j++){
            for(var l = 0; l < syllables[i].neumes[j].pitches.length; l++){
                if(Array.isArray(syllables[i].neumes[j].pitches[l])){
                    for(var k = 0; k < syllables[i].neumes[j].pitches[l].length; k++){
                        if(syllables[i].neumes[j].pitches[l][k].sourceID == id){
                            syllables[i].neumes[j].pitches[l].splice(k, 1);
                        }
                    }
                }
            }
        }
    }
    document.getElementById("input").innerHTML = sourceDataChangeForm();
    document.getElementById("meiOutput").value = createMEIOutput();
    createSVGOutput();
}

/** Navigational, leads to change staff data form, setting the current staff to the first of all staffs.*/
function toChangeStaffData(){
    if(staffs.length > 0){
       currentN = staffs[0].n;
    }
    document.getElementById("input").innerHTML = staffDataChangeForm();
}

/** Applies changes made to a specific staff.*/
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

/** Deletes the selected staff and the syllables using that staff.*/
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

/** Navigational, leads to the change clef form.*/
function toChangeClefData(){
    currentClefIndex = 0;
    document.getElementById("input").innerHTML = clefDataChangeForm();
}

/** Applies changes made to a certain clef.*/
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

/** Reads clef data, creates a clef and inserts the new clef  before or after the selected clef.
  * @param {boolean} before - declares whether the element should be inserted before
  */
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

/** Deletes a clef.*/
function deleteClef(){
    currentStaff.clefs.splice(currentClefIndex, 1);
    
    currentClefIndex = 0;
    
    document.getElementById("input").innerHTML = clefDataChangeForm();
    document.getElementById("meiOutput").value = createMEIOutput();
    createSVGOutput();
}

/** Navigational, leads to syllable change form.*/
function toChangeSyllableData(){
    if(syllables.length > 0){
        currentType = syllables[0].type;
        currentColor = syllables[0].color;
    }
    document.getElementById("input").innerHTML = syllableDataChangeForm();
}

/** Applies changes made to the selected syllable.*/
function applySyllableDataChanges(){
    var page = document.getElementById("page").value;
    var line = document.getElementById("line").value;
    var staff = document.getElementById("staff").value;
    var syllable = document.getElementById("syllabletext").value;
    var initial = document.getElementById("initial").checked;
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
    
    currentSyllable.initial = initial;
    
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

/** Reads the data from the change syllable form, creates a new syllable and inserts it before or after the selected syllable.
  * @param {boolean} before - declares whether the element should be inserted before
  */
function insertSyllable(before){
    var page = document.getElementById("page").value;
    var line = document.getElementById("line").value;
    var staff = document.getElementById("staff").value;
    var syllable = document.getElementById("syllabletext").value;
    var initial = document.getElementById("initial").checked;
    var color = document.getElementById("color").value;
    var comment = document.getElementById("comment").value;
    
    var syllable = new Syllable(page, line, staff, syllable, initial, color, comment);
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

/** Deletes currently selected syllable.*/
function deleteSyllable(){
    syllables.splice(currentSyllableIndex, 1);
    
    currentSyllableIndex = 0;
    
    document.getElementById("input").innerHTML = syllableDataChangeForm();
    document.getElementById("meiOutput").value = createMEIOutput();
    createSVGOutput();
}

/** Navigational, leads to neume change form.*/
function toChangeNeumeData(){
    currentNeumeIndex = 0;
    document.getElementById("input").innerHTML = neumeDataChangeForm();
}

/** Applies changes made to the selected neume.*/
function applyNeumeDataChanges(){
    var type = document.getElementById("type").value;
    
    if(type && type != "none"){
        currentNeume.type = type;
    }
    
    document.getElementById("meiOutput").value = createMEIOutput();
    document.getElementById("input").innerHTML = neumeDataChangeForm();
    createSVGOutput();
}

/** Reads data from the neume form, creates a neume and inserts it before or after the selected neume.
  * @param {boolean} before - declares whether the element should be inserted before
  */
function insertNeume(before){
    var type = document.getElementById("type").value;
    
    var neume = new Neume();
    neume.type = type;
    
    if(before){
        currentSyllable.neumes.splice(currentNeumeIndex, 0, neume);
    }
    else{
        currentSyllable.neumes.splice(currentNeumeIndex + 1, 0, neume);
    }

    document.getElementById("meiOutput").value = createMEIOutput();
    document.getElementById("input").innerHTML = neumeDataChangeForm();
    createSVGOutput();
}

/** Deletes the elcted neume.*/
function deleteNeume(){
    currentSyllable.neumes.splice(currentNeumeIndex, 1);
    
    currentNeumeIndex = 0;
    
    document.getElementById("input").innerHTML = neumeDataChangeForm();
    document.getElementById("meiOutput").value = createMEIOutput();
    createSVGOutput();
}

/** Navigational, leads to pitch change form.*/
function toChangePitchData(){
    document.getElementById("input").innerHTML = pitchDataChangeForm();
}

/** Applies changes made to the selected pitch.*/
function applyPitchDataChanges(){
    var pitch = document.getElementById("pitch").value;
    var octave = document.getElementById("octave").value;
    var comment = document.getElementById("comment").value;
    var intm = document.getElementById("intm").value;
    var connection = document.getElementById("connection").value;
    var tilt = document.getElementById("tilt").value;
    var variation = document.getElementById("variation").value;
    
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
    if(variation && variation != "none"){
        currentPitch.variation = variation;
    }
    
    document.getElementById("input").innerHTML = pitchDataChangeForm();
    document.getElementById("meiOutput").value = createMEIOutput();
    createSVGOutput();
}

/** Reads the data from the pitch change form, creates a new pitch and inserts it before or after the selected pitch.
  * @param {boolean} before - declares whether the element should be inserted before
  */
function insertPitch(before){
    var pitch = document.getElementById("pitch").value;
    var octave = document.getElementById("octave").value;
    var comment = document.getElementById("comment").value;
    var intm = document.getElementById("intm").value;
    var connection = document.getElementById("connection").value;
    var tilt = document.getElementById("tilt").value;
    
    var p = new Pitch(pitch, octave, comment, intm, connection, tilt);
    
    if(before){
        currentNeume.pitches.splice(currentPitchIndex, 0, p);
    }
    else{
        currentNeume.pitches.splice(currentPitchIndex + 1, 0, p);
    }
    
    document.getElementById("input").innerHTML = pitchDataChangeForm();
    document.getElementById("meiOutput").value = createMEIOutput();
    createSVGOutput();
}

/** Deletes the currently selected pitch.*/
function deletePitch(){
    currentNeume.pitches.splice(currentPitchIndex, 1);
    
    currentPitchIndex = 0;
    
    document.getElementById("input").innerHTML = pitchDataChangeForm();
    document.getElementById("meiOutput").value = createMEIOutput();
    createSVGOutput();
}

/** Creates a new variation which can later be tweaked by the user.*/
function createAdditionalVariation(){
    
    variations = new Array();
    
    for(i = 0; i < sources.length; i++){
        var variation = new Variation(sources[i].id);
        variations.push(variation);
    }
    
    currentNeume.pitches.splice(currentPitchIndex, 0, variations);
    
    document.getElementById("meiOutput").value = createMEIOutput();
    document.getElementById("input").innerHTML = pitchDataChangeForm();
    createSVGOutput();
}

/** Applies changes made in the variation change form.*/
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

/** Reads data from the pitch form, creates the pitch and inserts it into a variation before or after the selected pitch.
  * @param {boolean} before - declares whether the element should be inserted before
  */
function insertVariationPitch(before){
    var pitch = document.getElementById("pitch").value;
    var octave = document.getElementById("octave").value;
    var comment = document.getElementById("comment").value;
    var intm = document.getElementById("intm").value;
    var connection = document.getElementById("connection").value;
    var tilt = document.getElementById("tilt").value;
    
    var p = new Pitch(pitch, octave, comment, intm, connection, tilt);
    
    if(before){
        currentNeume.pitches[currentPitchIndex][currentVarSourceIndex].additionalPitches.splice(currentVarPitchIndex, 0, p);
    }
    else{
        currentNeume.pitches[currentPitchIndex][currentVarSourceIndex].additionalPitches.splice(currentVarPitchIndex + 1, 0, p);
    }
    
    document.getElementById("input").innerHTML = pitchDataChangeForm();
    document.getElementById("meiOutput").value = createMEIOutput();
    createSVGOutput();
}

/** Deletes the pitch of a variation.*/
function deleteVariationPitch(){
    currentNeume.pitches[currentPitchIndex][currentVarSourceIndex].additionalPitches.splice(currentVarPitchIndex, 1);
    
    currentVarPitchIndex = 0;
    
    document.getElementById("input").innerHTML = pitchDataChangeForm();
    document.getElementById("meiOutput").value = createMEIOutput();
    createSVGOutput();
}

/** Set the selected source ID to be current source ID according to the form and reload it.*/
function applyCurrentSource(){
    currentSID = document.getElementById("source").value;
    document.getElementById("input").innerHTML = sourceDataChangeForm();
}

/** Set the selected staff to be current staff according to the form and reload it.*/
function applyCurrentStaff(){
    currentN = document.getElementById("staff").value;
    document.getElementById("input").innerHTML = staffDataChangeForm();
}

/** Set the selected clef to be current clef according to the form and reload it.*/
function applyCurrentClef(){
    currentClefIndex = document.getElementById("clef").value;
    document.getElementById("input").innerHTML = clefDataChangeForm();
}

/** Set the selected syllable to be current syllable according to the form and reload it.*/
function applyCurrentSyllable(){
    currentSyllableIndex = document.getElementById("syllable").value;
    document.getElementById("input").innerHTML = syllableDataChangeForm();
}

/** Set the selected neume to be current neume according to the form and reload it.*/
function applyCurrentNeume(){
    currentNeumeIndex = document.getElementById("neume").value;
    document.getElementById("input").innerHTML = neumeDataChangeForm();
}

/** Set the selected neume type to be current current neume according to the form and reload it.*/
function applyCurrentType(){
    currentType = document.getElementById("type").value;
    if(currentType == "climacus"){
        isClimacus = true;
    }
    else{
        isClimacus = false;
    }
    document.getElementById("input").innerHTML = neumeForm();
}

/** Set the selected pitch index to be current pitch index according to the form and reload it.*/
function applyCurrentPitch(){
    currentPitchIndex = document.getElementById("pitc").value;
    document.getElementById("input").innerHTML = pitchDataChangeForm();
}

/** Set the selected variation source to be current variation source according to the form and reload it.*/
function applyCurrentVarSource(){
    currentVarSourceIndex = document.getElementById("varsource").value;
    document.getElementById("input").innerHTML = pitchDataChangeForm();
}

/** Set the selected variant to be current variation according to the form and reload it.*/
function applyCurrentVariation(){
    currentVarPitchIndex = document.getElementById("varpitch").value;
    document.getElementById("input").innerHTML = pitchDataChangeForm();
}

/** Set the selected octave to be current octave according to the form and reload it.*/
function applyCurrentOctave(){
    currentOctave = document.getElementById("octave").value;
    document.getElementById("input").innerHTML = pitchForm();
}

/** Set the selected color to be current color according to the form and reload it.*/
function applyCurrentColor(){
    currentColor = document.getElementById("color").value;
    document.getElementById("input").innerHTML = syllableForm();
}