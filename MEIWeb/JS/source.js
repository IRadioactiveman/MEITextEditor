/**
 * A class representing a source.
 * @class
 * @param {string} composer - the composer of the work
 * @param {string} title - the title of the work
 * @param {string} location - the location
 * @param {string} ownership - the ownership
 * @param {string} date - release date
 * @param {string} publicationstatus - publication status
 * @param {string} medium - the medium
 * @param {number} x - the width
 * @param {number} y - the height
 * @param {string} unit - unit of width and heigth
 * @param {string} condition - the condition
 * @param {string} extent - the extent
 * @param {string} language - the language
 * @param {string} handwriting - description of additional handwriting or style
 */
function Source(composer, title, location, ownership, date, publicationstatus, medium, x, y, unit, condition, extent, language, handwriting){
    /**
     * Specifies the unique XML ID of the source.
     * @member {string}
     */
    this.id = createSourceID();
    
     /**
     * Specifies the composer of the source.
     * @member {string}
     */
    this.composer = composer;
    
     /**
     * Specifies the title of the work.
     * @member {string}
     */
    this.title = title;
    
     /**
     * Specifies the physical location.
     * @member {string}
     */
    this.location = location;
    
     /**
     * Specifies the ownership of the work.
     * @member {string}
     */
    this.ownership = ownership;
    
     /**
     * Specifies the release date.
     * @member {string}
     */
    this.date = date;
    
     /**
     * Specifies the publication status.
     * @member {string}
     */
    this.publicationstatus = publicationstatus;
    
     /**
     * Specifies the medium of the work.
     * @member {string}
     */
    this.medium = medium;
    
     /**
     * Specifies the width.
     * @member {number}
     */
    this.x = x;
    
     /**
     * Specifies the height.
     * @member {number}
     */
    this.y = y;
    
     /**
     * Specifies the measuring unit for width and height.
     * @member {string}
     */
    this.unit = unit;
    
     /**
     * Specifies the condition.
     * @member {string}
     */
    this.condition = condition;
    
     /**
     * Specifies the extent.
     * @member {string}
     */
    this.extent = extent;
    
     /**
     * Specifies the language.
     * @member {string}
     */
    this.language = language;
    
     /**
     * Specifies handwriting notes and style.
     * @member {string}
     */
    this.handwriting = handwriting;
    
     /**
     * Creates an XML representation of a source and appends the created element to the manifestationList element.
     * @function
     */
    this.create = function(){ 
        var manifestationList = xmlDoc.getElementsByTagName("manifestationList")[0];
        
        var manifestation = xmlDoc.createElement("manifestation");
        manifestation.setAttribute("xml:id", this.id);
        
        if(this.language)
        {
            var langUsage = xmlDoc.createElement("langUsage");
            var l = xmlDoc.createElement("language");
            var languageString = xmlDoc.createTextNode(this.language);
            l.appendChild(languageString);
            langUsage.appendChild(l);

            manifestation.appendChild(langUsage);
        }

        if(this.title || this.composer || this.date){
            var biblList = xmlDoc.createElement("biblList");
            var bibl = xmlDoc.createElement("bibl");
            
            if(this.title){
                var t = xmlDoc.createElement("title");
                var titleString = xmlDoc.createTextNode(this.title);
                t.appendChild(titleString);
                bibl.appendChild(t);
            }
            if(this.composer){
                var c = xmlDoc.createElement("composer");
                var composerString = xmlDoc.createTextNode(this.composer);
                c.appendChild(composerString);
                bibl.appendChild(c);                
            }
            if(this.date){
                var d = xmlDoc.createElement("date");
                var dateString = xmlDoc.createTextNode(this.date);
                d.appendChild(dateString);
                bibl.appendChild(d);
            }
            biblList.appendChild(bibl);
            manifestation.appendChild(biblList);
        }
        
        if(this.publicationstatus || this.extent || this.medium || this.x || this.condition || this.handwriting || this.location || this.ownership){
            
            var componentList = xmlDoc.createElement("componentList");
            var item = xmlDoc.createElement("item");

            if(this.publicationstatus){
                var a = xmlDoc.createElement("availability");
                var availabilityString = xmlDoc.createTextNode(this.publicationstatus);
                a.appendChild(availabilityString);
                item.appendChild(a);
            }
            if(this.extent || this.medium || this.x ||  this.condition || this.handwriting){
                var physicalDescription = xmlDoc.createElement("physDesc");
                if(this.extent){
                    var e = xmlDoc.createElement("extent");
                    var eString = xmlDoc.createTextNode(this.extent);
                    e.appendChild(eString);
                    physicalDescription.appendChild(e);
                }
                if(this.medium){
                    var m = xmlDoc.createElement("physMedium");
                    var mString = xmlDoc.createTextNode(this.medium);
                    m.appendChild(mString);
                    physicalDescription.appendChild(m);
                }
                if(this.x){
                    var d = xmlDoc.createElement("dimensions");
                    d.setAttribute("unit", this.unit);
                    var dString = xmlDoc.createTextNode(this.x + " x " + this.y + this.unit);
                    d.appendChild(dString);
                    physicalDescription.append(d);
                }
                if(this.condition){
                    var c = xmlDoc.createElement("condition");
                    var cString = xmlDoc.createTextNode(this.condition);
                    c.appendChild(cString);
                    physicalDescription.appendChild(c);
                }
                if(this.handwriting){
                    var handList = xmlDoc.createElement("handList");
                    var hand = xmlDoc.createElement("hand");
                    var annot = xmlDoc.createElement("annot");
                    var h = xmlDoc.createTextNode(this.handwriting);
                    annot.appendChild(h);
                    hand.appendChild(annot);
                    handList.appendChild(hand);
                    physicalDescription.appendChild(handList);
                }
        
                item.appendChild(physicalDescription);
            }
            
            if(this.location){
                var physicalLocation = xmlDoc.createElement("physLoc");
                var repository = xmlDoc.createElement("repository");
                var l = xmlDoc.createTextNode(this.location);
                repository.appendChild(l);
                physicalLocation.appendChild(repository);
                
                item.appendChild(physicalLocation);
            }
            if(this.ownership){
                var history = xmlDoc.createElement("history");
                var provenance = xmlDoc.createElement("provenance");
                var corpName = xmlDoc.createElement("corpName");
                var o = xmlDoc.createTextNode(this.ownership);
                corpName.appendChild(o);
                provenance.appendChild(corpName);
                history.appendChild(provenance);
                item.appendChild(history);
            } 
            componentList.appendChild(item);
            manifestation.appendChild(componentList);
        }
        
        manifestationList.appendChild(manifestation);
    }
}

/**
 * Creates a unique source ID.
 */
function createSourceID(){
    var id = "source" + sourceCounter;
    sourceCounter++;
    return id;
}