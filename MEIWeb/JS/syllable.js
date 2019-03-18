function Syllable(page, line, staff, syllable, initial, color, comment){
    this.page = page;
    this.line = line;
    this.staff = staff;
    this.syllable = syllable;
    this.initial = initial;
    this.color = color;
    this.neumes = new Array();
    this.comment = comment;
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
        /*
        var neume = xmlDoc.createElement("neume");
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
        s.appendChild(neume);
        */
        layer.appendChild(s);
    }
}