function Source(composer, title, location, ownership, date, publicationstatus, medium, x, y, unit, condition, extent, language, handwriting){
    this.id = createSourceID();
    this.composer = composer;
    this.title = title;
    this.location = location;
    this.ownership = ownership;
    this.date = date;
    this.publicationstatus = publicationstatus;
    this.medium = medium;
    this.x = x;
    this.y = y;
    this.unit = unit;
    this.condition = condition;
    this.extent = extent;
    this.language = language;
    this.handwriting = handwriting;
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
                    var m = xmlDoc.createElement("medium");
                    var mString = xmlDoc.createTextNode(this.medium);
                    m.appendChild(mString);
                    physicalDescription.appendChild(m);
                }
                if(this.x){
                    var d = xmlDoc.createElement("dimension");
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

function createSourceID(){
    var id = "source" + sourceCounter;
    sourceCounter++;
    return id;
}

/*  
        var s = "";
        
        s += indent(3);
        s += meiManifestationAttBeg; s += meiAttID; s += "\""; s += this.id; s += "\""; s += meiClosingBracket; s += meiN;
    

        if(this.language)
        {

            s += indent(4); s += meiLangusageBeg; s += meiN;
            s += indent(5); s += meiLanguageBeg; s += meiN;
            s += indent(6); s += this.language; s += meiN;
            s += indent(5); s += meiLanguageEnd;  s += meiN;
            s += indent(4); s += meiLangusageEnd; s += meiN;

        }

        s += indent(4); s += meiBiblListBeg; s += meiN;
        s += indent(5); s += meiBiblBeg; s += meiN;
        if(this.title)
        {

            s += indent(6); s += meiTitleBeg; s += meiN;
            s += indent(7); s += this.title; s += meiN;
            s += indent(6); s += meiTitleEnd; s += meiN;
        }
        if(this.composer)
        {
            s += indent(6); s += meiAgentBeg; s += meiN;
            s += indent(7); s += this.composer; s += meiN;
            s += indent(6); s += meiAgentEnd; s += meiN;
        }

        if(this.date)
        {
            s += indent(6); s += meiDateBeg; s += meiN;
            s += indent(7); s += this.date; s += meiN;
            s += indent(6); s += meiDateEnd; s += meiN;
        }
        s += indent(5); s += meiBiblEnd; s += meiN;
        s += indent(4); s += meiBiblListEnd; s += meiN;
        
        s += indent(4); s += meiComponentListBeg; s += meiN;
        s += indent(5); s += meiItemBeg; s += meiN;
        
        if(this.publicationstatus){
            s += indent(6); s += meiAvailabilityBeg; s += meiN;
            s += indent(7); s += this.publicationstatus; s += meiN;
            s += indent(6); s += meiAvailabilityEnd; s += meiN;
        }

        s += indent(6); s += meiPhysdescriptionBeg; s += meiN;
        if(this.extent)
        {
            s += indent(7); s += meiExtentBeg; s += meiN;
            s += indent(8); s += this.extent; s += meiN;
            s += indent(7); s += meiExtentEnd; s += meiN;
        }
        if(this.medium)
        {
            s += indent(7); s += meiPhysmediumBeg; s += meiN;
            s += indent(8); s += this.medium; s += meiN;
            s += indent(7); s += meiPhysmediumEnd; s += meiN;
            
        }
        if(this.x)
        {
            s += indent(7); s += meiDimensionsAttBeg; s += meiAttUnits; s += "\""; s += this.unit; s += "\""; s +=     meiClosingBracket; s += meiN;
            s += indent(8); s += this.x; s += " x "; s += this.y; s += this.unit; s += meiN;
            s += indent(7); s += meiDimensionsEnd; s += meiN;
        }
        if(this.condition)
        {
            s += indent(7); s += meiConditionBeg; s += meiN;
            s += indent(8); s += this.condition; s += meiN;
            s += indent(7); s += meiConditionEnd; s += meiN;
        }
        if(this.handwriting)
        {
            s += indent(7); s += meiHandlistBeg; s += meiN;
            s += indent(8); s += meiHandBeg; s += meiN;
            s += indent(9); s += meiAnnotBeg; s += meiN;
            s += indent(10); s += this.handwriting; s += meiN;
            s += indent(9); s += meiAnnotEnd; s += meiN;
            s += indent(8); s += meiHandEnd; s += meiN;
            s += indent(7); s += meiHandlistEnd; s += meiN;
        }
        
        s += indent(6); s += meiPhysdescriptionEnd; s += meiN;
        
        if(this.location)
        {
            s += indent(6); s += meiPhysicallocationBeg; s += meiN;
            s += indent(7); s += meiRepositoryBeg; s += meiN;
            s += indent(8); s += this.location; s += meiN;
            s += indent(7); s += meiRepositoryEnd; s += meiN;
            s += indent(6); s += meiPhysicallocationEnd; s += meiN;
        }

        if(this.ownership)
        {
            s += indent(6); s += meiHistoryBeg; s += meiN;
            s += indent(7); s += meiProvenanceBeg; s += meiN;
            s += indent(8); s += meiCorpnameBeg; s += meiN;
            s += indent(9); s += this.ownership; s += meiN;
            s += indent(8); s += meiCorpnameEnd; s += meiN;
            s += indent(7); s += meiProvenanceEnd; s += meiN;
            s += indent(6); s += meiHistoryEnd; s += meiN;
        }
        
        s += indent(5); s += meiItemEnd; s += meiN;
        s += indent(4); s += meiComponentListEnd; s += meiN;
        
        s += indent(3); s += meiManifestationEnd; s += meiN;
        
        return s;
*/