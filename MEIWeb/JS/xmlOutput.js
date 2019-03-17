function createMEIOutput(){
    xmlDoc = document.implementation.createDocument("http://www.music-encoding.org/ns/mei", "mei", null);
    xmlDoc.getElementsByTagName("mei")[0].setAttribute("meiversion", "4.0.0");
    xmlDoc.xmlVersion="1.0";
    xmlDoc.xmlEncoding="UTF-8";
    
    var meiHead = xmlDoc.createElement("meiHead");
    xmlDoc.documentElement.appendChild(meiHead);
    
    if(metaData){
        metaData.create();
    }
    
    if(sources.length >= 1 && meiHead){
        var manifestationList = xmlDoc.createElement("manifestationList");
        meiHead.appendChild(manifestationList);
        for(var i = 0; i < sources.length; i++){
            sources[i].create();
        }
    }
    
    if(staffs.length >= 1){
        var music = xmlDoc.createElement("music");
        var body = xmlDoc.createElement("body");
        var mdiv = xmlDoc.createElement("mdiv");
        var score = xmlDoc.createElement("score");
        mdiv.appendChild(score);
        body.appendChild(mdiv);
        music.appendChild(body);
        xmlDoc.documentElement.appendChild(music);
        
        var staffGroup = xmlDoc.createElement("staffGrp");
        staffGroup.setAttribute("xml:id", "all");
        var scoreDefinition = xmlDoc.createElement("scoreDef");
        scoreDefinition.appendChild(staffGroup);
        xmlDoc.getElementsByTagName("score")[0].appendChild(scoreDefinition);
        
        for(var i = 0; i < staffs.length; i++){
            staffs[i].create();
        }
    }
    
    if(syllables.length >=1){
        var section = xmlDoc.createElement("section");
        
        var currentLayer;
        
        for(var i = 0; i < syllables.length; i++){
            if(i == 0 || syllables[i].staff != currentN){
                currentN = syllables[i].staff;
                var staff = xmlDoc.createElement("staff");
                staff.setAttribute("def", currentN);
                var layer = xmlDoc.createElement("layer");
                currentLayer = layer;
                staff.appendChild(currentLayer);
                section.appendChild(staff);
            }
            syllables[i].create(currentLayer);
        }
        xmlDoc.getElementsByTagName("score")[0].appendChild(section);
    }
    
    var serializer = new XMLSerializer();
    var toStr = serializer.serializeToString(xmlDoc);
    toStr = toStr.replace(" xmlns=\"\"", "");
    toStr = toStr.replace(" xmlns=\"\"", "");
    
    output = vkbeautify.xml(toStr);
    
    return output;
}