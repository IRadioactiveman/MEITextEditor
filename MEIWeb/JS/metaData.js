/** 
 * A class representing meta data.
 * @class
 * @param {string} title - the title of the song
 * @param {string} composer - the composer of the song
 * @param {string} author - the author of the file
 * @param {string} availability - an availability statement
 * @param {string} comment - an editorial comment
 */
function MetaData(title, composer, author, availability, comment){
    /**
     * Specifies the title of the work.
     * @member {string}
     */
    this.title = title;
    /**
     * Specifies the composer of the work.
     * @member {string}
     */
    this.composer = composer;
    /**
     * Specifies the author of the file.
     * @member {string}
     */
    this.author = author;
    /**
     * Specifies the availability of the file.
     * @member {string}
     */
    this.availability = availability;
    /**
     * Specifies editorial comments concerning the data and coding.
     * @member {string}
     */
    this.comment = comment;
    /**
     * Creates the xml representation of the meta data. It is automatically added to the root element "mei".
     * @function
     */
    this.create = function (){
        var meiHeader = xmlDoc.getElementsByTagName("meiHead")[0];
        
        var fileDescription;
        var encodingDescription;
        
        if(this.title){
            fileDescription = xmlDoc.createElement("fileDesc");
            
            var titleStatement = xmlDoc.createElement("titleStmt");
            
            var t = xmlDoc.createElement("title");
            var titleString = xmlDoc.createTextNode(this.title);
            t.appendChild(titleString);
            titleStatement.appendChild(t);
            
            if(this.composer){
                var c = xmlDoc.createElement("composer");
                var composerString = xmlDoc.createTextNode(this.composer);
                c.appendChild(composerString);
                titleStatement.appendChild(c);
            }
            
            fileDescription.appendChild(titleStatement);
            
            if(this.author || this.availability){
                var publicationStatement = xmlDoc.createElement("pubStmt");
                if(this.author){
                    var authors = author.split(",");
                    var responsibilityStatement = xmlDoc.createElement("respStmt");
                    for(var i = 0; i < authors.length; i++){
                        var personName = xmlDoc.createElement("persName");
                        var person = xmlDoc.createTextNode(authors[i]);
                        personName.appendChild(person);
                        responsibilityStatement.appendChild(personName);
                       
                    }
                    publicationStatement.appendChild(responsibilityStatement);
                }
        
                if(this.availability){
                    var a = xmlDoc.createElement("availability");
                    var useRestrict = xmlDoc.createElement("useRestrict");
                    var availabilityString = xmlDoc.createTextNode(this.availability);
                    useRestrict.appendChild(availabilityString);
                    a.appendChild(useRestrict);
                    publicationStatement.appendChild(a);
                }
                
                fileDescription.appendChild(publicationStatement);

            }

        }
        
        if(this.comment){
            encodingDescription = xmlDoc.createElement("encodingDesc");
            var editorialDeclaration = xmlDoc.createElement("editorialDecl");
            var paragraph = xmlDoc.createElement("p");
            var c = xmlDoc.createTextNode(this.comment);
            paragraph.appendChild(c);
            editorialDeclaration.appendChild(paragraph);
            encodingDescription.appendChild(editorialDeclaration);
        }
        
        if(fileDescription){
            meiHeader.appendChild(fileDescription);
        }
           
        if(encodingDescription){
            meiHeader.appendChild(encodingDescription);
        }   
    }
}