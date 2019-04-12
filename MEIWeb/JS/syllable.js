/**
 * A class representing a syllable.
 * @class
 * @param {number} page - the page in the source
 * @param {number} line - the line in the source
 * @param {number} staff - the unique n of the staff used for the syllable
 * @param {string} syllable - the textual content of the syllable
 * @param {boolean} initial - defines whether syllable is an initial or not
 * @param {string} color - the color of the text
 * @param {string} comment - a comment regarding the syllable
 */
function Syllable(page, line, staff, syllable, initial, color, comment){
    
    /**
     * Specifies the page in the source.
     * @member{number}
     */
    this.page = page;
    
    /**
     * Specifies the line in the source.
     * @member{number}
     */
    this.line = line;
    
    /**
     * Specifies the unique of the staff used.
     * @member{number}
     */
    this.staff = staff;
    
    /**
     * Specifies .
     * @member{}
     */
    this.syllable = syllable;
    
    /**
     * Specifies the textual content of the syllable.
     * @member{string}
     */
    this.initial = initial;
    
    /**
     * Specifies the color of the text.
     * @member{string}
     */
    this.color = color;
    
    /**
     * Contains the neumes used for the syllable.
     * @member{Object}
     */
    this.neumes = new Array();
    
    /**
     * Specifies a comment regarding the syllable.
     * @member{string}
     */
    this.comment = comment;
    
    /**
     * Creates an XML representation of a syllable and append the created element to a given layer element.
     * @function
     * @param layer - a layer element to append the created syllable element to
     */
    this.create = function(layer){
        
        if(this.page){
            var p = xmlDoc.createElement("pb");
            p.setAttribute("n", this.page);
            layer.appendChild(p);
        }
        if(this.line){
            var l = xmlDoc.createElement("sb");
            l.setAttribute("n", this.line);
            layer.appendChild(l);
        }
        if(this.comment){
            var add = xmlDoc.createElement("add");
            var annot = xmlDoc.createElement("annot");
            var p = xmlDoc.createElement("p");
            var c = xmlDoc.createTextNode(this.comment);
            p.appendChild(c);
            annot.appendChild(p);
            add.appendChild(annot);
            layer.appendChild(add);
        }
        
        var s = xmlDoc.createElement("syllable");
        var syl = xmlDoc.createElement("syl");
        if(this.initial){
            syl.setAttribute("type", "initial");
        }
        if(this.syllable){
            var sylString = xmlDoc.createTextNode(this.syllable);
            
            if(color == "none"){
                var sylString = xmlDoc.createTextNode(this.syllable);
                syl.appendChild(sylString);
            }
            else{
                var rend = xmlDoc.createElement("rend");
                rend.setAttribute("color", this.color);
                rend.appendChild(sylString);
                syl.appendChild(rend);   
            }
            s.appendChild(syl);
        }
        for(var i = 0; i < this.neumes.length; i++){
            this.neumes[i].create(s);
        }
        layer.appendChild(s);
    }
}