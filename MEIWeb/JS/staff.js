/**
 * A class representing a staff.
 * @class
 * @param {number} linecount - the number of lines
 * @param {string} linecolor - the color of the lines
 * @param {string} mode - the mode of then work
 */
function Staff(linecount, linecolor, mode){
    
    /**
     * Specifies the unique XML ID of the staff.
     * @member {string}
     */
    this.id = createStaffID();
    
    /**
     * Specifies the unique n value of the staff.
     * @member {number}
     */
    this.n = staffCounter;
    
    /**
     * Specifies the number of lines.
     * @member {number}
     */
    this.linecount = linecount;
    
    /**
     * Specifies the color of the lines.
     * @member {string}
     */
    this.linecolor = linecolor;
    
    /**
     * Specifies the mode.
     * @member {string}
     */
    this.mode = mode;
    
    /**
     * Contains the clefs of a staff.
     * @member {Object}
     */
    this.clefs = new Array();
    
    /**
     * Creates an XML representation of a staff and appends the created element to the staffGrp element.
     * @function
     */
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

/**
 * Creates a unique staff ID.
 */
function createStaffID(){
    var id = "staff" + staffCounter;
    staffCounter++;
    return id;
}