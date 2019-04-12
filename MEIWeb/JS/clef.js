/** 
 * A class representing a clef.
 * @class
 * @param {string} line - line the clef is on
 * @param {string} shape - shape of the clef
 */
function Clef(line, shape){
    /**
     * Specifies the line the clef is on.
     * @member {string}
     */
    this.line = line;
    /**
     * Specifies the shape of the clef.
     * @member {string}
     */
    this.shape = shape;
    /**
     * Creates the xml representation of the clef.
     * @function
     * @param {string} id - the id of the staff definition to append the clef to
     */
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