/** 
 * A class representing a variant.
 * @class
 * @param id - the id of the source that contains the variant
 */
function Variation(id){
    
    /**
     * Specifies the ID of the source containing the variant.
     * @member {string}
     */
    this.sourceID = id;
    
    /**
     * Contains additional pitches as specified in the source.
     * @member {Object}
     */
    this.additionalPitches = new Array();
    
    /**
     * Creates an XML representation of a variant and append it to a specified app element.
     * @function
     * @param app - an app element to append the created element to
     */
    this.create = function(app){
        var rdg = xmlDoc.createElement("rdg");
        rdg.setAttribute("source", this.sourceID);
        if(this.additionalPitches.length >= 1 ){
            for(var i = 0; i < this.additionalPitches.length; i++){
                this.additionalPitches[i].create(rdg);
            }
        }
        app.appendChild(rdg);
    }
}