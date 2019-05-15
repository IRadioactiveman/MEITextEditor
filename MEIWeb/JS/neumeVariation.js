/** 
 * A class representing a neume variant.
 * @class
 * @param id - the id of the source that contains the variant
 */
function NeumeVariation(id){
    
    /**
     * Specifies the ID of the source containing the variant.
     * @member {string}
     */
    this.sourceID = id;
    
    /**
     * Additional neumes as specified in the source.
     * @member {Object}
     */
    this.additionalNeumes = new Array();
    
    /**
     * Creates an XML representation of a variant and append it to a specified app element.
     * @function
     * @param app - an app element to append the created element to
     */
    this.create = function(app){
        var rdg = xmlDoc.createElement("rdg");
        rdg.setAttribute("source", this.sourceID);
        if(this.additionalNeumes){
            for(var i = 0; i < this.additionalNeumes.length; i++){
                this.additionalNeumes[i].create(rdg);
            }
        }
        app.appendChild(rdg);
    }
}