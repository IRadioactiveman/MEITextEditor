/**
 * A class representing a pitch.
 * @class
 * @param {string} pitch - the pitch or note
 * @param {number} octave - the octave of the pitch
 * @param {string} comment - a comment to the pitch
 * @param {string} intm - relation to the previous note, i.e. up, down or same
 * @param {string} connection - descreibes the connection between pitches
 * @param {string} tilt - describes the tilt of a pitch
 * @param {string} variation - describes a graphical variation
 */
function Pitch(pitch, octave, comment, intm, connection, tilt, variation){
    /**
     * Specifies the actual pitch or note.
     * @member {string}
     */
    this.pitch = pitch;
    
    /**
     * Specifies the octave of the pitch.
     * @member {number}
     */
    this.octave = octave;
    
    /**
     * Specifies a comment regarding the pitch.
     * @member {string}
     */
    this.comment = comment;
    
    /**
     * Specifies a relation to the previous pitch.
     * @member {string}
     */
    this.intm = intm;
    
    /**
     * Specifies the connection between the pitches
     * @member {string}
     */
    this.connection = connection;
    
    /**
     * Specifies the tilt of a pitch.
     * @member {string}
     */
    this.tilt = tilt;
    
    /**
     * Specifies the graphical variation of a pitch.
     * @member {string}
     */
    this.variation = variation;
    
    /**
     * Creates the XML representation of the pitch. The created element id then appended to a neume element.
     * @function
     * @param neume - a neume element to which the created pitch element is appended to
     */
    this.create = function(neume){
        var nc = xmlDoc.createElement("nc");
        if(this.pitch && this.pitch != "none"){
            nc.setAttribute("pname", this.pitch);
        }
        if(this.octave && this.octave != "none"){
            nc.setAttribute("oct", this.octave);
        }
        if(this.comment){
            var add = xmlDoc.createElement("add");
            var annot = xmlDoc.createElement("annot");
            var p = xmlDoc.createElement("p");
            var c = xmlDoc.createTextNode(this.comment);
            p.appendChild(c);
            annot.appendChild(p);
            add.appendChild(annot);
            neume.appendChild(add);
        }
        if(this.intm && this.intm != "none"){
            nc.setAttribute("intm", this.intm);
        }
        if(this.connection && this.connection != "none"){
            nc.setAttribute("con", this.connection);
        }
        if(this.tilt && this.tilt != "none"){
            nc.setAttribute("tilt", this.tilt);
        }
        if(this.variation != "none"){
            var variationElement = xmlDoc.createElement(variation);
            nc.appendChild(variationElement);
        }
        neume.appendChild(nc);
    }
}