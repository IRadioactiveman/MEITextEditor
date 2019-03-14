function Variation(id){
    this.sourceID = id;
    this.additionalPitches = new Array();
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