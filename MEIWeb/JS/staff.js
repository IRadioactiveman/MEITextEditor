function Staff(linecount, linecolor, mode){
    this.id = createStaffID();
    this.n = staffCounter;
    this.linecount = linecount;
    this.linecolor = linecolor;
    this.mode = mode;
    this.clefs = new Array();
    this.create = function(){
        
        var staffDefinition = xmlDoc.createElement("staffDef");
        staffDefinition.setAttribute("xml:id", this.id);
        staffDefinition.setAttribute("n", this.n);
        if(this.linecount && this.linecount != "none"){
            staffDefinition.setAttribute("lines", this.linecount);   
        }
        if(this.linecolor && this.linecolor != "none"){
            staffDefinition.setAttribute("lines.color", this.linecolor);
        }
        if(this.mode && this.mode != "none"){
            staffDefinition.setAttribute("key.mode", this.mode);
        }
        
        var staffGroup = xmlDoc.getElementsByTagName("staffGrp")[0];
        staffGroup.appendChild(staffDefinition);
        
        for(var i = 0; i < this.clefs.length; i++){
            this.clefs[i].create(this.id);
        }
    }
}
    
function createStaffID(){
    var id = "staff" + staffCounter;
    staffCounter++;
    return id;
}