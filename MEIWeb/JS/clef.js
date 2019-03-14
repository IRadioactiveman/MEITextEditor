function Clef(line, shape){
    this.line = line;
    this.shape = shape;
    this.create = function(id){
        
        var staffDefinition = xmlDoc.getElementsByTagName("staffDef");
        
        var clef = xmlDoc.createElement("clef");
        
        if(line && line != "none"){
            clef.setAttribute("line", this.line);
        }
        if(shape && shape != "none"){
            clef.setAttribute("shape", this.shape);
        }
        
        for(var i = 0; i < staffDefinition.length; i++){
            if(staffDefinition[i].getAttribute("xml:id") == id){
                staffDefinition[i].appendChild(clef);
            }
        }
    }
}