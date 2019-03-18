function Neume(){
    this.type;
    this.pitches = new Array();
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