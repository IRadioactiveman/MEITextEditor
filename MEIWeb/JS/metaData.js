function MetaData(title, composer, author, availability, comment){
    this.title = title;
    this.composer = composer;
    this.author = author;
    this.availability = availability;
    this.comment = comment;
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
/*
    this.create = function (){ 
        var s = "";
        
        s += indent(2); s += meiFiledescriptionBeg; s += meiN;
        
        if(this.title){
            s += indent(3); s += meiTitlestmtBeg; s += meiN;
            s += indent(4); s += meiTitleBeg; s += meiN;
            s += indent(5); s += title; s += meiN;
            s += indent(4); s += meiTitleEnd; s += meiN;
            
            if(this.composer){
                s += indent(4); s += meiAgentBeg; s += meiN;
                s += indent(5);  s += composer; s += meiN;
                s += indent(4); s += meiAgentEnd; s += meiN;
            }
            s += indent(3); s += meiTitlestmtEnd; s += meiN;
            
            if(author || availability){
                s += indent(3); s += meiPublicationBeg; s += meiN;
                if(author){
                    var authors = author.split(",");
                    
                    s += indent(4); s += meiResponsibilityBeg; s += meiN;
                    for(var i = 0; i < authors.length; i++){
                        s += indent(5); s += meiPersnameBeg; s += meiN;
                        s += indent(6); s += authors[i]; s += meiN;
                        s += indent(5); s += meiPersnameEnd; s += meiN;
                    }
                    s += indent(4); s += meiResponsibilityEnd; s += meiN;
                }
        
                if(this.availability){
                    s += indent(4); s += meiAvailabilityBeg; s += meiN;
                    s += indent(5); s += meiUserestrictBeg; s += meiN;
                    s += indent(6); s += availability; s += meiN;
                    s += indent(5); s += meiUserestrictEnd; s += meiN;
                    s += indent(4); s += meiAvailabilityEnd; s += meiN;
                }
                s += indent(3); s += meiPublicationEnd; s += meiN;
            }
        }
        
        
        s += indent(2); s += meiFiledescriptionEnd; s += meiN;

        if(this.comment){
            s += indent(2); s += meiEncodingDescBeg; s += meiN;
            s += indent(3); s += meiEditorialdeclarationBeg; s += meiN;
            s += indent(4); s += meiParagraphBeg; s += meiN;
            s += indent(5); s += comment; s += meiN;
            s += indent(4); s += meiParagraphEnd; s += meiN;
            s += indent(3); s += meiEditorialdeclarationEnd; s += meiN;
            s += indent(2); s += meiEncodingDescEnd; s += meiN;
        }
        
        return s;
    }*/