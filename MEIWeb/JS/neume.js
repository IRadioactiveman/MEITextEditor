/** 
 * A class representing a neume.
 * @class
 */
function Neume(){
    /**
     * Specifies the type of the neume.
     * @member {string}
     */
    this.type;
    
    /**
     * An array containing the pitches of a neume.
     * @member {Object}
     */
    this.pitches = new Array();
    
    /**
     * Creates the XML representation of a neume. The created element is appended to a syllable element.
     * @function
     * @param syllable - the syllable parent element that the created neume is appended to
     */
    this.create = function(syllable){
        var neume = xmlDoc.createElement("neume");
        if(this.type != "none"){
            neume.setAttribute("type", this.type);
        }
        if(this.pitches.length >= 1){
            for(var i = 0; i < this.pitches.length; i++){
                if(Array.isArray(this.pitches[i])){
                    var app = xmlDoc.createElement("app");
                    var vars = new Array();
                    for(var h = 0; h < sources.length; h++){
                        var x;
                        for(var g = 0; g < this.pitches[i].length; g++){
                            if(sources[h].id == this.pitches[i][g].sourceID){
                                x = this.pitches[i][g];
                                break;
                            }
                            else{
                                x = new Variation(sources[h].id);  
                            }
                        }
                        vars.push(x);
                    }
                    for(var j = 0; j < vars.length; j++){
                        vars[j].create(app);
                    }
                    neume.appendChild(app);
                }
                else{
                    this.pitches[i].create(neume);
                }
            }
        }
        syllable.appendChild(neume);
    }
}