/* In this file, all dynamically integrated html forms are stored. Some of them are implemented as functions since they contain information that is only available at runtime.*/

/** 
 * The meta data form.
 * @var {string} metaDataForm
 */
var metaDataForm =
"<h4>Meta data:</h4>\
<form autocomplete=\"on\">\
    <pre>\
Title:              <input id=\"title\" type=\"text\"><br>\
Composer:           <input id=\"composer\" type=\"text\"><br>\
Author:             <input id=\"author\" type=\"text\"><br>\
Availability:       <input id=\"availability\" type=\"text\"><br>\
Comments:           <textarea class=\"formArea\" id=\"comment\" rows=\"5\"></textarea><br><br>\
<button onclick=\"createMetaData()\">save/continue to sources</button>\
    </pre>\
</form><br>";

/**
 * The source data form.
 * @function
 * @returns {string} s - the source form as a string
 */
function sourceForm(){
    var s = "";
    s += 
"<h4>Source:</h4>\
<form autocomplete=\"on\">\
    <pre>\
Author/Composer:    <input id=\"composer\" type=\"text\"><br>\
Source title:       <input id=\"title\" type=\"text\"><br>\
Location:           <input id=\"location\" type=\"text\"><br>\
Ownership:          <input id=\"ownership\" type=\"text\"><br>\
Date:               <input id=\"date\" type=\"text\"><br>\
Publication status: <input id=\"publicationstatus\" type=\"text\"><br>\
Medium:             <input id=\"medium\" type=\"text\"><br>\
Dimensions:<br>\
  Width:            <input id=\"x\" type=\"text\"><br>\
  Height:           <input id=\"y\" type=\"text\"><br>\
  Unit:             <input id=\"unit\" type=\"text\"><br>\
Condition:          <input id=\"condition\" type=\"text\"><br>\
Extent:             <input id=\"extent\" type=\"text\"><br>\
Language:           <input id=\"language\" type=\"text\"><br>\
Handwriting:        <textarea class=\"formArea\" id=\"handwriting\" rows=\"5\" cols=\"20\"></textarea><br><br>\
<button onclick=\"createSource()\">save source</button><br><br>\
<button class=\"sourcedependant\" onclick=\"toStaffs()\"";
    if(sources.length < 1){
        s += " disabled";
    }
    s += ">continue to staffs</button>\
    </pre>\
</form><br>";
    return s;
}

/**
 * The staff data form.
 * @function
 * @returns {string} s - the staff form as a string
 */
function staffForm(){
    var s = "";
    s +=
"<h4>Staff:</h4>\
<form autocomplete=\"on\">\
    <pre>\
Line count:         <select id=\"linecount\">\
                                <option value=\"none\">none</option>\
                                <option value=\"1\">1</option>\
                                <option value=\"2\">2</option>\
                                <option value=\"3\">3</option>\
                                <option value=\"4\">4</option>\
                                <option value=\"5\">5</option>\
                            </select><br>\
Line color:         <select id=\"linecolor\">\
                                <option value=\"none\">none</option>\
                                <option value=\"black\">black</option>\
                                <option value=\"red\">red</option>\
                                <option value=\"yellow\">yellow</option>\
                                <option value=\"brown\">brown</option>\
                                <option value=\"grey\">grey</option>\
                            </select><br>\
Mode:               <select id=\"mode\">\
                                <option value=\"none\">none</option>\
                                <option value=\"major\">major</option>\
                                <option value=\"minor\">minor</option>\
                                <option value=\"dorian\">dorian</option>\
                                <option value=\"phrygian\">phrygian</option>\
                                <option value=\"lydian\">lydian</option>\
                                <option value=\"mixolydian\">mixolydian</option>\
                                <option value=\"aeolian\">aeolian</option>\
                                <option value=\"locrian\">locrian</option>\
                            </select><br><br>\
<button onclick=\"createStaff()\">save staff without clefs</button><br><br>\
<button onclick=\"createStaffWithClefs()\">save staff and add clefs</button><br><br>\
<button class=\"staffdependant\" onclick=\"toSyllable()\"";
    if(staffs.length < 1){
        s += " disabled";
    }
    s +=  ">continue to syllables</button>\
    </pre>\
</form><br>";
    return s;
}

/** 
 * The clef data form.
 * @var {string} clefForm
 */
var clefForm =
"<h4>Clef:</h4>\
<form autocomplete=\"on\">\
    <pre>\
Line:               <select id=\"line\">\
                                <option value=\"none\">none</option>\
                                <option value=\"1\">1</option>\
                                <option value=\"2\">2</option>\
                                <option value=\"3\">3</option>\
                                <option value=\"4\">4</option>\
                                <option value=\"5\">5</option>\
                            </select><br>\
Shape:              <select id=\"shape\">\
                                <option value=\"none\">none</option>\
                                <option value=\"C\">C</option>\
                                <option value=\"F\">F</option>\
                                <option value=\"G\">G</option>\
                                <option value=\"GG\">GG</option>\
                            </select><br><br>\
<button onclick=\"createClef()\">save clef</button><br><br>\
<button onclick=\"createNewStaff()\">create another staff</button><br><br>\
<button onclick=\"toSyllable()\">continue to syllables</button>\
    </pre>\
</form><br>";

/**
 * The syllable data form.
 * @function
 * @returns {string} s - the syllable form as a string
 */
function syllableForm(){   
    var s = "";
    s +=
"<h4>Syllable:</h4>\
<form autocomplete=\"on\">\
        <pre>\
Page:               <input id=\"page\" type=\"text\"><br>\
Line:               <input id=\"line\" type=\"text\"><br>\
Staff:              " + createStaffSelector();
s += "Text color:         " + createColorSelector();
s += "Syllable:           <input id=\"syllable\" type=\"text\"><br>\
Initial?            <input type=\"checkbox\" id=\"initial\"><br>\
Comments:           <textarea class=\"formArea\" id=\"comment\" rows=\"5\" cols=\"20\"></textarea><br><br>\
<button onclick=\"createSyllable()\">save syllable</button><br><br>\
<button onclick=\"createSyllableWithNeumes()\">save syllable and add neumes</button>\
    </pre>\
</form><br>";
    
    return s;
}

/**
 * The neume data form.
 * @function
 * @returns {string} s - the neume form as a string
 */
function neumeForm(){
    var s = "";
    s +=
"<h4>Neume:</h4>\
<form>\
    <pre>\
Neume type:         " + createTypeSelector("applyCurrentType()") + "<br>";
    if(isClimacus){
        s += 
"Number of Pitches:  <select id=\"numberofpitches\">\
                        <option value=\"3\">3</option>\
                        <option value=\"4\">4</option>\
                        <option value=\"5\">5</option>\
                    </select><br><br>";
    }
    s +=
"<button onclick=\"createNeume()\">save neume</button><br><br>\
<button onclick=\"createNeumeWithPitches()\">save neume and add pitches</button><br><br>\
<button onclick=\"toSyllable()\">add another syllable</button><br><br>\
<button onclick=\"toChangeSyllableData()\">change syllables</button><br><br>\
<button onclick=\"toNeumeVariationForm()\"";
    
    if(sources.length <= 1){
        s += " disabled";
    }
    s += 
">add variant</button>\
    </pre>\
</form><br>";
    
    return s;
}

/**
 * The neume variation form.
 * @function
 * @returns {string} s - the neume variation form as a string
 */
function neumeVariationForm(){
    var s = "";
    s +=
"<h4>Neume variant:</h4>\
<form>\
    <pre>\
Source:             "+createSourceSelector();
s += "Neume type:         " + createTypeSelector("applyCurrentTypeVariation()") + "<br>";
    if(isClimacus){
        s += 
"Number of Pitches:  <select id=\"numberofpitches\">\
                        <option value=\"3\">3</option>\
                        <option value=\"4\">4</option>\
                        <option value=\"5\">5</option>\
                    </select><br><br>";
    }
    s +=
"<button onclick=\"createNeumeVariation()\">save neume for this source</button><br><br>\
<button onclick=\"createNeumeVariationWithPitches()\">save neume for this source and add pitches</button><br><br>\
<button onclick=\"toNeumeFromNeumeVariations()\">add more neumes</button><br><br>\
<button onclick=\"toSyllableFromNeumeVariations()\">add another syllable</button><br><br>\
<button onclick=\"toChangeSyllableData()\">change syllables</button>\
    </pre>\
</form><br>";
    
    return s;
}

/**
 * The pitch data form.
 * @function
 * @returns {string} s - the pitch form as a string
 */
function pitchForm(){
    var s = "";
s += "<h4>Pitch:</h4>\
<form autocomplete=\"on\">\
    <pre>\
Pitch:              <select id=\"pitch\">\
                                <option value=\"none\">none</option>\
                                <option value=\"c\">C</option>\
                                <option value=\"d\">D</option>\
                                <option value=\"e\">E</option>\
                                <option value=\"f\">F</option>\
                                <option value=\"g\">G</option>\
                                <option value=\"a\">A</option>\
                                <option value=\"b\">B</option>\
                            </select><br>\
Octave:             " + createOctaveSelector("applyCurrentOctave()");
s += "From previous note: "+createIntmSelector()+"<br>\
Connection:         <select id=\"connection\">\
                                <option value=\"none\">none</option>\
                                <option value=\"g\">gapped</option>\
                                <option value=\"l\">loop</option>\
                                <option value=\"e\">extended</option>\
                            </select><br>\
Tilt:               <select id=\"tilt\">\
                                <option value=\"none\">none</option>\
                                <option value=\"n\">north</option>\
                                <option value=\"s\">south</option>\
                                <option value=\"w\">west</option>\
                                <option value=\"e\">east</option>\
                                <option value=\"nw\">northwest</option>\
                                <option value=\"ne\">northeast</option>\
                                <option value=\"sw\">southwest</option>\
                                <option value=\"se\">southeast</option>\
                    </select><br>\
Graphical variation:<select id=\"variation\">\
                                <option value=\"none\">none</option>\
                                <option value=\"quilisma\">quilisma</option>\
                                <option value=\"oriscus\">oriscus</option>\
                                <option value=\"liquescent\">liquescent</option>\
                                <option value=\"strophicus\">strophicus</option>\
                    </select><br>\
Supplied?        By " + createSuppliedSourceSelector() + "<br>\
Comments:           <textarea class=\"formArea\" id=\"comment\" rows=\"5\" cols=\"20\"></textarea><br><br>\
<button onclick=\"createPitch()\">save pitch</button><br><br>\
<button onclick=\"toVariant()\"";
    if(sources.length <= 1){
        s += " disabled";
    }
        s += ">add variant</button><br><br>";
    
    if(isNeumeVariant){
        s +=
"<button onclick=\"toNeumeVariationForm()\">add pitches to other source</button><br><br>\
<button onclick=\"toNeumeFromNeumeVariations()\">add another neume</button><br><br>\
<button onclick=\"toSyllableFromNeumeVariations()\">add another syllable</button>";
    }
    else{
        s +=
"<button onclick=\"toNeume()\">add another neume</button><br><br>\
<button onclick=\"toSyllable()\">add another syllable</button>";
    }
    s +=
"</pre>\
</form><br>";
    return s;
}

/**
 * The variant data form.
 * @function
 * @returns {string} s - the variant form as a string
 */
function variationForm(){
    var s = "";
    s +=
"<h4>Pitch variant</h4>\
<form autocomplete=\"on\">\
    <pre>\
Source:             "+createSourceSelector();
s += "Pitch:              <select id=\"pitch\">\
                                <option value=\"none\">none</option>\
                                <option value=\"c\">C</option>\
                                <option value=\"d\">D</option>\
                                <option value=\"e\">E</option>\
                                <option value=\"f\">F</option>\
                                <option value=\"g\">G</option>\
                                <option value=\"a\">A</option>\
                                <option value=\"b\">B</option>\
                            </select><br>\
Octacve:            " + createOctaveSelector("applyCurrentOctave()");
s += "\
From previous note: <select id=\"intm\">\
                                <option value=\"none\">none</option>\
                                <option value=\"s\">same</option>\
                                <option value=\"d\">went down</option>\
                                <option value=\"u\">went up</option>\
                            </select><br>\
Connection:         <select id=\"connection\">\
                                <option value=\"none\">none</option>\
                                <option value=\"g\">gapped</option>\
                                <option value=\"l\">loop</option>\
                                <option value=\"e\">extended</option>\
                            </select><br>\
Tilt:               <select id=\"tilt\">\
                                <option value=\"none\">none</option>\
                                <option value=\"n\">north</option>\
                                <option value=\"s\">south</option>\
                                <option value=\"w\">west</option>\
                                <option value=\"e\">east</option>\
                                <option value=\"nw\">northwest</option>\
                                <option value=\"ne\">northeast</option>\
                                <option value=\"sw\">southwest</option>\
                                <option value=\"se\">southeast</option>\
                            </select><br>\
Graphical variation:<select id=\"variation\">\
                                <option value=\"none\">none</option>\
                                <option value=\"quilisma\">quilisma</option>\
                                <option value=\"oriscus\">oriscus</option>\
                                <option value=\"liquescent\">liquescent</option>\
                                <option value=\"strophicus\">strophicus</option>\
                    </select><br>\
Supplied?        By " + createSuppliedSourceSelector() + "<br>\
Comments:           <textarea class=\"formArea\" id=\"comment\" rows=\"5\" cols=\"20\"></textarea><br><br>\
<button onclick=\"createVariation()\">save additional pitch for this source</button><br><br>\
<button onclick=\"toPitchesFromVariations()\">add more original pitches</button><br><br>\
<button onclick=\"toNeumeFromVariations()\">add more neumes</button><br><br>\
<button onclick=\"toSyllableFromVariations()\">add another syllable</button>\
    </pre>\
</form><br>";
    
    return s;
}

/**
 * The form for changing values.
 * @function
 * @returns {string} s - the form for changing vaalues as a string
 */
function changeValueForm(){
    var s ="";
    
    s +="<button onclick=\"toChangeMetaData()\">change meta data</button><br><br>\
    <button onclick=\"toChangeSourceData()\">change source data</button><br><br>\
    <button onclick=\"toChangeStaffData()\">change staff data</button><br><br>\
    <button onclick=\"toChangeSyllableData()\">change syllable data</button><br><br>";
    
    return s;
}    

/**
 * The meta data change form.
 * @function
 * @returns {string} s - the form for changing meta data as a string
 */
function metaDataChangeForm(){
    var s = "";
    if(!metaData){
        s += "<b>You should create the data before changing it!</b><br>";
        s += metaDataForm;
    }
    else{
        s += 
"<h4>Change meta data:</h4>\
<form autocomplete=\"on\">\
    <pre>\
                                            Current:<br>\
Title:              <input id=\"title\" type=\"text\">"+ metaData.title +"<br>\
Composer:           <input id=\"composer\" type=\"text\">"+ metaData.composer +"<br>\
Author:             <input id=\"author\" type=\"text\">"+ metaData.author +"<br>\
Availability:       <input id=\"availability\" type=\"text\">"+ metaData.availability +"<br>\
Comments:           <textarea class=\"formArea\" id=\"comment\" rows=\"5\"></textarea>"+ metaData.comment +"<br><br>\
<button onclick=\"applyMetaDataChanges()\">save changes</button>\
    </pre>\
</form><br>";
    }
    s += "<button onclick=\"toSources()\">add more sources</button><br><br>";
    return s;
}

/**
 * The source data change form.
 * @function
 * @returns {string} s - the form for changing sources as a string
 */
function sourceDataChangeForm(){
    var s = "";
    if(sources.length < 1){
        s += "<b>You should create the data before changing it!</b><br>";
        s += sourceForm();
    }
    else{
        s += 
"<h4>Change Source:</h4>\
Select source:      "+ createSourceSelector("applyCurrentSource()") + "<br>";
        for(var i = 0; i < sources.length; i++){
            if(currentSID == sources[i].id){
                currentSource = sources[i];
            }
        }
        s += 
"<form autocomplete=\"on\">\
    <pre>\
                                            Current:<br>\
Author/Composer:    <input id=\"composer\" type=\"text\">"+ currentSource.composer +"<br>\
Source title:       <input id=\"title\" type=\"text\">"+ currentSource.title +"<br>\
Location:           <input id=\"location\" type=\"text\">"+ currentSource.location +"<br>\
Ownership:          <input id=\"ownership\" type=\"text\">"+ currentSource.ownership +"<br>\
Date:               <input id=\"date\" type=\"text\">"+ currentSource.date +"<br>\
Publication status: <input id=\"publicationstatus\" type=\"text\">"+ currentSource.publicationstatus +"<br>\
Medium:             <input id=\"medium\" type=\"text\">"+ currentSource.medium +"<br>\
Dimensions:<br>\
  Width:            <input id=\"x\" type=\"text\">"+ currentSource.x +"<br>\
  Height:           <input id=\"y\" type=\"text\">"+ currentSource.y +"<br>\
  Unit:             <input id=\"unit\" type=\"text\">"+ currentSource.unit +"<br>\
Condition:          <input id=\"condition\" type=\"text\">"+ currentSource.condition +"<br>\
Extent:             <input id=\"extent\" type=\"text\">"+ currentSource.extent +"<br>\
Language:           <input id=\"language\" type=\"text\">"+ currentSource.language +"<br>\
Handwriting:        <textarea class=\"formArea\" id=\"handwriting\" rows=\"5\" cols=\"20\"></textarea>"+ currentSource.handwriting +"<br><br>\
<button onclick=\"applySourceDataChanges()\">apply changes</button><br><br>\
<button onclick=\"createSource()\">create new source</button><br>\
<button onclick=\"deleteSource(currentSID)\">delete selected source</button>\
    </pre>\
</form><br>";
    }
    s += "<button onclick=\"toSources()\">back to adding sources</button><br><br>";
    return s;
}

/**
 * The staff data change form.
 * @function
 * @returns {string} s - the form for changing staffs as a string
 */
function staffDataChangeForm(){
    var s = "";
    if(staffs.length < 1){
        s += "<b>You should create the data before changing it!</b><br>";
        s += staffForm();
    }
    else{
        var i;
        s +=
"<h4>Change Staff:</h4>\
Select source:      "+ createStaffSelector("applyCurrentStaff()") + "<br>";
        for(i = 0; i < staffs.length; i++){
            if(currentN == staffs[i].n){
                currentStaff = staffs[i];
            }
        }
        s +=
"<form autocomplete=\"on\">\
    <pre>\
                                            Current:<br>\
Line count:         <select id=\"linecount\">\
                                <option value=\"none\">none</option>\
                                <option value=\"1\">1</option>\
                                <option value=\"2\">2</option>\
                                <option value=\"3\">3</option>\
                                <option value=\"4\">4</option>\
                                <option value=\"5\">5</option>\
                            </select>"+ currentStaff.linecount +"<br>\
Line color:         <select id=\"linecolor\">\
                                <option value=\"none\">none</option>\
                                <option value=\"black\">black</option>\
                                <option value=\"red\">red</option>\
                                <option value=\"yellow\">yellow</option>\
                                <option value=\"brown\">brown</option>\
                                <option value=\"grey\">grey</option>\
                            </select>"+ currentStaff.linecolor +"<br>\
Mode:               <select id=\"mode\">\
                                <option value=\"none\">none</option>\
                                <option value=\"major\">major</option>\
                                <option value=\"minor\">minor</option>\
                                <option value=\"dorian\">dorian</option>\
                                <option value=\"phrygian\">phrygian</option>\
                                <option value=\"lydian\">lydian</option>\
                                <option value=\"mixolydian\">mixolydian</option>\
                                <option value=\"aeolian\">aeolian</option>\
                                <option value=\"locrian\">locrian</option>\
                            </select>"+ currentStaff.mode +"<br><br>\
Clefs:<br>";
        for(i = 0; i < currentStaff.clefs.length; i++){
            s += "Clef "+ (i+1)
            if(currentStaff.clefs[i].line){
               s += ": line: "+ currentStaff.clefs[i].line;
            }
            if(currentStaff.clefs[i].shape){
               s += "; shape:" +currentStaff.clefs[i].shape + ";";
            }
            s += "<br>";
        }
        
        s +=
"<button onclick=\"applyStaffDataChanges()\">apply changes</button><br><br>\
<button onclick=\"toChangeClefData()\">change clefs</button><br>\
<button onclick=\"toStaffs()\">create new staff</button><br>\
<button onclick=\"deleteStaff(currentN)\">delete selected staff</button>\
    </pre>\
</form><br>";
    }
    s += "<button onclick=\"toStaffs()\">back to adding staffs</button><br><br>";
    return s;
}

/**
 * The clef data change form.
 * @function
 * @returns {string} s - the form for changing clefs as a string
 */
function clefDataChangeForm(){
    var s = "";

    if(currentStaff.clefs.length >= 1){
        s += "<h4>Change Clef:</h4>";
        s += "Select Clef: " + createClefSelector(currentStaff, "applyCurrentClef()");
        currentClef = currentStaff.clefs[currentClefIndex];
        s +=
"<form autocomplete=\"on\">\
    <pre>\
                                            Current:<br>\
Line:               <select id=\"line\">\
                                <option value=\"none\">None</option>\
                                <option value=\"1\">1</option>\
                                <option value=\"2\">2</option>\
                                <option value=\"3\">3</option>\
                                <option value=\"4\">4</option>\
                                <option value=\"5\">5</option>\
                            </select>"+ currentClef.line +"<br>\
Shape:              <select id=\"shape\">\
                                <option value=\"none\">None</option>\
                                <option value=\"C\">C</option>\
                                <option value=\"F\">F</option>\
                                <option value=\"G\">G</option>\
                                <option value=\"GG\">GG</option>\
                            </select>"+ currentClef.shape +"<br><br>\
<button onclick=\"applyClefDataChanges()\">apply change</button><br><br>\
<button onclick=\"insertClef(true)\">insert clef before selected clef</button><br>\
<button onclick=\"insertClef(false)\">insert clef after selected clef</button><br>\
<button onclick=\"deleteClef()\">delete clef</button>\
    </pre>\
</form><br>";
    }
    else{
        s += 
"<h4>Create Clef:</h4>\
<form autocomplete=\"on\">\
    <pre>\
Line:               <select id=\"line\">\
                                <option value=\"none\">None</option>\
                                <option value=\"1\">1</option>\
                                <option value=\"2\">2</option>\
                                <option value=\"3\">3</option>\
                                <option value=\"4\">4</option>\
                                <option value=\"5\">5</option>\
                            </select><br>\
Shape:              <select id=\"shape\">\
                                <option value=\"none\">None</option>\
                                <option value=\"C\">C</option>\
                                <option value=\"F\">F</option>\
                                <option value=\"G\">G</option>\
                                <option value=\"GG\">GG</option>\
                            </select><br><br>\
<button onclick=\"insertClef(true)\">save clef</button><br>\
    </pre>\
</form><br>";
    }
    s += "<button onclick=\"toChangeStaffData()\">back to editing staffs</button><br><br>";
    return s;
}

/**
 * The syllable data change form.
 * @function
 * @returns {string} s - the form for changing syllables as a string
 */
function syllableDataChangeForm(){
    var s = "";
    if(syllables.length < 1){
        s += "<b>You should create the data before changing it!</b><br>";
        if(staffs.length < 1){
            s += "Also, you need to create at least one staff. <br>"
            s += "<button onclick=\"toStaffs()\">to staffs</button><br><br>";
        }
        else{
            s += syllableForm();
        }
    }
    else{
        s +=
"<h4>Syllable:</h4>\
Select syllable:      "+ createSyllableSelector("applyCurrentSyllable()") + "<br>";
        currentSyllable = syllables[currentSyllableIndex];
        currentType = currentSyllable.type;
        currentN = currentSyllable.staff;
        s +=
"<form autocomplete=\"on\">\
        <pre>\
                                            Current:<br>\
Page:               <input id=\"page\" type=\"text\">"+ currentSyllable.page +"<br>\
Line:               <input id=\"line\" type=\"text\">"+ currentSyllable.line +"<br>\
Staff:              " + createStaffSelector();
        var staffID;
        for(var i = 0; i < staffs.length; i++){
            if(currentSyllable.staff == staffs[i].n){
                staffID = staffs[i].id;
            }
        }
        s += staffID + "<br>";
        s += 
"Syllable:           <input id=\"syllabletext\" type=\"text\">"+ currentSyllable.syllable +"<br>\
Initial?            <input type=\"checkbox\" id=\"initial\"";
        
        if(currentSyllable.initial){
            s += " checked";
        }
        
        s += "><br>\
Text color:         <select id=\"color\">\
                                <option value=\"none\">none</option>\
                                <option value=\"black\">Black</option>\
                                <option value=\"red\">Red</option>\
                                <option value=\"blue\">Blue</option>\
                                <option value=\"green\">Green</option>\
                                <option value=\"yellow\">Yellow</option>\
                            </select>"+ currentSyllable.color +"<br>\
Comments:           <textarea class=\"formArea\" id=\"comment\" rows=\"5\" cols=\"20\"></textarea>"+ currentSyllable.comment +"<br><br>\
Neumes:<br>";
            
        for(var i = 0; i < currentSyllable.neumes.length; i++){
            s += "   ";
            
            if(currentSyllable.neumes[i].type == "none"){
                s += "undefined neume";
            }
            else{
                s += currentSyllable.neumes[i].type
            }
            
            s += "<br>";
        }
        s += 
"<button onclick=\"applySyllableDataChanges()\">apply changes</button><br><br>\
<button onclick=\"toChangeNeumeData()\">change neumes</button><br><br>\
<button onclick=\"insertSyllable(true)\">insert syllable before selected syllable</button><br><br>\
<button onclick=\"insertSyllable(false)\">insert syllable after selected syllable</button><br><br>\
<button onclick=\"deleteSyllable()\">delete syllable</button><br><br>\
<button onclick=\"toSyllable()\">back to adding syllables</button><br><br>\
    </pre>\
</form><br>";
    }
    return s;
}

/**
 * The neume data change form.
 * @function
 * @returns {string} s - the form for changing neumes as a string
 */
function neumeDataChangeForm(){
    var s = "";
    var isNeumeVariation = false;
    
    if(currentSyllable.neumes.length >= 1){
        s +=
"<h4>Change neume:</h4>\
<form>\
    <pre>";
        s += "Select neume:       " + createNeumeSelector("applyCurrentNeume()") + "<br>";
        
        if(Array.isArray(currentSyllable.neumes[currentNeumeIndex])){
            s += "Select variant:     " + createNeumeVariationSelector("applyCurrentNeumeVariation()") + "<br>";
            if(currentSyllable.neumes[currentNeumeIndex][currentNeumeVariationIndex].additionalNeumes.length > 0){
                s += "Select variant neume:" + createNeumeInVariationSelector("applyCurrentNeumeInVariation()") + "<br>";
            }
            currentNeume = currentSyllable.neumes[currentNeumeIndex][currentNeumeVariationIndex].additionalNeumes[currentNeumeInVariationIndex];
            
            s +=
"Neume type:         " + createTypeSelector();
            ///if(currentNeume.type){
            ///    s += "Current neume type: " + currentNeume.type + "<br>";
            ///}
            
            isNeumeVariation = true;
        }
        else{
        
            currentNeume = currentSyllable.neumes[currentNeumeIndex];
            
            s +=
"Neume type:         " + createTypeSelector();
            s += "Current neume type: " + currentNeume.type + "<br>";
    
            for(var i = 0; i < currentNeume.pitches.length; i++){
        
                s += "  Pitch " + i + ": ";
                if(currentNeume.pitches[i].pitch){
                    s += currentNeume.pitches[i].pitch + "<br>";
                }
                else{
                    s += "Variant<br>";
                }
            }
        }
    
        s +=
"<button onclick=\"applyNeumeDataChanges()\">apply changes</button><br><br>\
<button onclick=\"toChangePitchData()\"";
        
        
        if(isNeumeVariation && currentSyllable.neumes[currentNeumeIndex][currentNeumeVariationIndex].additionalNeumes.length <= 0){
           s += " disabled";
        }
        
        
        s += ">change pitches</button><br><br>\
<button onclick=\"insertNeume(true)\">insert neume before selected neume</button><br><br>\
<button onclick=\"insertNeume(false)\">insert neume after selected neume</button><br><br>\
<button onclick=\"deleteNeume()\">delete neume/variant</button><br><br>";
        
        if(sources.length > 1){
            s +=
"<button onclick=\"insertNeumeVariant(true)\">insert neume variant before selected neume</button><br><br>\
<button onclick=\"insertNeumeVariant(false)\">insert neume variant after selected neume</button><br><br>";
        }
        
        if(Array.isArray(currentSyllable.neumes[currentNeumeIndex])){
            s +=
"<button onclick=\"insertNeumeInVariant(true)\">insert neume in variant before selected neume</button><br><br>\
<button onclick=\"insertNeumeInVariant(false)\">insert neume in variant after selected neume</button><br><br>\
<button onclick=\"deleteNeumeInVariant()\">delete selected neume in variant</button>";
        }
        
        s +=
    "</pre>\
</form><br>";
    }
    else{
        s += "<b>You have not yet created any neumes!</b><br>";
        s += neumeForm();
    }
    
    return s;
}

/**
 * The pitch data change form. It is applied for changing pitches in both neumes and variants.
 * @function
 * @returns {string} s - the form for changing pitches as a string
 */
function pitchDataChangeForm(){
    var s = "";
    if(currentNeume.pitches.length < 1){
        s += 
"<h4>Create Pitch:</h4>\
<form autocomplete=\"on\">\
    <pre>\
Pitch:              <select id=\"pitch\">\
                                <option value=\"none\">none</option>\
                                <option value=\"c\">C</option>\
                                <option value=\"d\">D</option>\
                                <option value=\"e\">E</option>\
                                <option value=\"f\">F</option>\
                                <option value=\"g\">G</option>\
                                <option value=\"a\">A</option>\
                                <option value=\"b\">B</option>\
                            </select><br>\
Octacve:            <select id=\"octave\">\
                                <option value=\"none\">none</option>\
                                <option value=\"1\">1</option>\
                                <option value=\"2\">2</option>\
                                <option value=\"3\">3</option>\
                                <option value=\"4\">4</option>\
                                <option value=\"5\">5</option>\
                            </select><br>\
From previous note: <select id=\"intm\">\
                                <option value=\"none\">none</option>\
                                <option value=\"s\">same</option>\
                                <option value=\"d\">went down</option>\
                                <option value=\"u\">went up</option>\
                            </select><br>\
Connection:         <select id=\"connection\">\
                                <option value=\"none\">none</option>\
                                <option value=\"g\">gapped</option>\
                                <option value=\"l\">loop</option>\
                                <option value=\"e\">extended</option>\
                            </select><br>\
Tilt:               <select id=\"tilt\">\
                                <option value=\"none\">none</option>\
                                <option value=\"n\">north</option>\
                                <option value=\"s\">south</option>\
                                <option value=\"w\">west</option>\
                                <option value=\"e\">east</option>\
                                <option value=\"nw\">northwest</option>\
                                <option value=\"ne\">northeast</option>\
                                <option value=\"sw\">southwest</option>\
                                <option value=\"se\">southeast</option>\
                            </select><br>\
Graphical variation:<select id=\"variation\">\
                                <option value=\"none\">none</option>\
                                <option value=\"quilisma\">quilisma</option>\
                                <option value=\"oriscus\">oriscus</option>\
                                <option value=\"liquescent\">liquescent</option>\
                                <option value=\"strophicus\">strophicus</option>\
                    </select><br>\
Supplied?        By " + createSuppliedSourceSelector() + "<br>\
Comments:           <textarea class=\"formArea\" id=\"comment\" rows=\"5\" cols=\"20\"></textarea><br><br>\
<button onclick=\"insertPitch(true)\">create pitch</button><br><br>\
<button onclick=\"createAdditionalVariation()\"";
        if(sources.length <= 1){
            s += " disabled";
        }
        s += ">add variant before selected pitch</button><br><br>\
    </pre>\
</form><br>";
    }
    else{
        s += "<h4>Change Pitch:</h4>";
        s += "Select Pitch:     " + createPitchSelector("applyCurrentPitch()") +"<br>";
        currentPitch = currentNeume.pitches[currentPitchIndex];
        
        if(Array.isArray(currentPitch)){
            
            s +=
"<form autocomplete=\"on\">\
    <pre>";
            s += "Select Source of Variant:" + createVarSourceSelector("applyCurrentVarSource()");
            
            s += "Select Pitch in Variant: " + createVarPitchSelector("applyCurrentVariation()") + "<br>";
            
            currentVarPitch = currentPitch[currentVarSourceIndex].additionalPitches[currentVarPitchIndex];
            
            if(currentVarPitch){
                s +=
"<br>                                            Current:<br>";
            }
            else{
                s += 
"No pitch has been created yet for this source, create a new one or take another selection!<br><br>"
            }
            
            s +=
"Pitch:              <select id=\"pitch\">\
                                <option value=\"none\">none</option>\
                                <option value=\"c\">C</option>\
                                <option value=\"d\">D</option>\
                                <option value=\"e\">E</option>\
                                <option value=\"f\">F</option>\
                                <option value=\"g\">G</option>\
                                <option value=\"a\">A</option>\
                                <option value=\"b\">B</option>\
                            </select>";
            if(currentVarPitch){
                s += currentVarPitch.pitch;
            }
             
            s += 
"<br>\
Octacve:            <select id=\"octave\">\
                                <option value=\"none\">none</option>\
                                <option value=\"1\">1</option>\
                                <option value=\"2\">2</option>\
                                <option value=\"3\">3</option>\
                                <option value=\"4\">4</option>\
                                <option value=\"5\">5</option>\
                            </select>";
            if(currentVarPitch){
                s += currentVarPitch.octave;
            } 
            s +=
"<br>\
From previous note: <select id=\"intm\">\
                                <option value=\"none\">none</option>\
                                <option value=\"s\">same</option>\
                                <option value=\"d\">went down</option>\
                                <option value=\"u\">went up</option>\
                            </select>";
            if(currentVarPitch){
                s += currentVarPitch.intm;
            }
            s +=                                
"<br>\
Connection:         <select id=\"connection\">\
                                <option value=\"none\">none</option>\
                                <option value=\"g\">gapped</option>\
                                <option value=\"l\">loop</option>\
                                <option value=\"e\">extended</option>\
                            </select>";
            if(currentVarPitch){
                s += currentVarPitch.connection;
            }
            s +=
"<br>\
Tilt:               <select id=\"tilt\">\
                                <option value=\"none\">none</option>\
                                <option value=\"n\">north</option>\
                                <option value=\"s\">south</option>\
                                <option value=\"w\">west</option>\
                                <option value=\"e\">east</option>\
                                <option value=\"nw\">northwest</option>\
                                <option value=\"ne\">northeast</option>\
                                <option value=\"sw\">southwest</option>\
                                <option value=\"se\">southeast</option>\
                            </select>";
            if(currentVarPitch){
                s += currentVarPitch.tilt;
            }
            s +=            
"<br>\
Graphical variation:<select id=\"variation\">\
                                <option value=\"none\">none</option>\
                                <option value=\"quilisma\">quilisma</option>\
                                <option value=\"oriscus\">oriscus</option>\
                                <option value=\"liquescent\">liquescent</option>\
                                <option value=\"strophicus\">strophicus</option>\
                    </select>";
            if(currentVarPitch){
                s += currentVarPitch.variation;
            }
            s +=
"<br>\
Supplied?        By " + createSuppliedSourceSelector();
            if(currentVarPitch){
                s += currentVarPitch.supplied;
            }
            s +=
"<br>Comments:           <textarea class=\"formArea\" id=\"comment\" rows=\"5\" cols=\"20\"></textarea>";
            if(currentVarPitch){
                s += currentVarPitch.comment;
            }
            if(currentVarPitch){
                s +=
"<br><br>\
<button onclick=\"applyVariationDataChanges()\">apply changes</button><br><br>\
<button onclick=\"insertVariationPitch(true)\">insert pitch before selected pitch</button><br><br>\
<button onclick=\"insertVariationPitch(false)\">insert pitch after selected pitch</button><br><br>\
<button onclick=\"deleteVariationPitch()\">delete pitch</button><br>\
<button onclick=\"deletePitch()\">delete whole variant</button><br><br>\
    </pre>\
</form><br>";
            }
            else{
                s +=
"<br><br>\
<button onclick=\"insertVariationPitch(true)\">create pitch</button><br>\
<button onclick=\"deletePitch()\">delete whole variant</button><br><br>\
    </pre>\
</form><br>";
            }

        }
        
        else{
            s += "<form autocomplete=\"on\">\
    <pre>\
Pitch:              <select id=\"pitch\">\
                                <option value=\"none\">none</option>\
                                <option value=\"c\">C</option>\
                                <option value=\"d\">D</option>\
                                <option value=\"e\">E</option>\
                                <option value=\"f\">F</option>\
                                <option value=\"g\">G</option>\
                                <option value=\"a\">A</option>\
                                <option value=\"b\">B</option>\
                            </select>" + currentPitch.pitch +"<br>\
Octave:             <select id=\"octave\">\
                                <option value=\"none\">none</option>\
                                <option value=\"1\">1</option>\
                                <option value=\"2\">2</option>\
                                <option value=\"3\">3</option>\
                                <option value=\"4\">4</option>\
                                <option value=\"5\">5</option>\
                            </select>" + currentPitch.octave +"<br>\
From previous note: <select id=\"intm\">\
                                <option value=\"none\">none</option>\
                                <option value=\"s\">same</option>\
                                <option value=\"d\">went down</option>\
                                <option value=\"u\">went up</option>\
                            </select>" + currentPitch.intm +"<br>\
Connection:         <select id=\"connection\">\
                                <option value=\"none\">none</option>\
                                <option value=\"g\">gapped</option>\
                                <option value=\"l\">loop</option>\
                                <option value=\"e\">extended</option>\
                            </select>" + currentPitch.connection +"<br>\
Tilt:               <select id=\"tilt\">\
                                <option value=\"none\">none</option>\
                                <option value=\"n\">north</option>\
                                <option value=\"s\">south</option>\
                                <option value=\"w\">west</option>\
                                <option value=\"e\">east</option>\
                                <option value=\"nw\">northwest</option>\
                                <option value=\"ne\">northeast</option>\
                                <option value=\"sw\">southwest</option>\
                                <option value=\"se\">southeast</option>\
                            </select>" + currentPitch.tilt +"<br>\
Graphical variation:<select id=\"variation\">\
                                <option value=\"none\">none</option>\
                                <option value=\"quilisma\">quilisma</option>\
                                <option value=\"oriscus\">oriscus</option>\
                                <option value=\"liquescent\">liquescent</option>\
                                <option value=\"strophicus\">strophicus</option>\
                    </select>" + currentPitch.variation +"<br>\
Supplied?        By " + createSuppliedSourceSelector() + currentPitch.supplied + "<br>\
Comments:           <textarea class=\"formArea\" id=\"comment\" rows=\"5\" cols=\"20\"></textarea><br><br>\
<button onclick=\"applyPitchDataChanges()\">apply changes</button><br><br>\
<button onclick=\"insertPitch(true)\">insert new pitch before selected pitch</button><br><br>\
<button onclick=\"insertPitch(false)\">insert new pitch after selected pitch</button><br><br>\
<button onclick=\"deletePitch()\">delete pitch</button><br><br>\
<button onclick=\"createAdditionalVariation()\"";
        if(sources.length <= 1){
            s += " disabled";
        }
        s += ">add variant before selected pitch</button><br><br>\
    </pre>\
</form><br>";
        }

    }
    s += "<button onclick=\"toSyllable()\">back to adding syllables</button><br><br>";
    return s;
}