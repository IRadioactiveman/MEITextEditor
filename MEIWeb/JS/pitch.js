function Pitch(pitch, octave, comment, intm, connection, tilt){
    this.pitch = pitch;
    this.octave = octave;
    this.comment = comment;
    this.intm = intm;
    this.connection = connection;
    this.tilt = tilt;
    this.create = function(neume){
        var nc = xmlDoc.createElement("nc");
        if(this.pitch && this.pitch != "none"){
            nc.setAttribute("pname", this.pitch);
        }
        if(this.octave && this.octave != "none"){
            nc.setAttribute("oct", this.octave);
        }
        if(this.comment){
            var add = xmlDoc.createElement("add");
            var annot = xmlDoc.createElement("annot");
            var p = xmlDoc.createElement("p");
            var c = xmlDoc.createTextNode(this.comment);
            p.appendChild(c);
            annot.appendChild(p);
            add.appendChild(annot);
            neume.appendChild(add);
        }
        if(this.intm && this.intm != "none"){
            nc.setAttribute("intm", this.intm);
        }
        if(this.connection && this.connection != "none"){
            nc.setAttribute("con", this.connection);
        }
        if(this.tilt && this.tilt != "none"){
            nc.setAttribute("tilt", this.tilt);
        }
        neume.appendChild(nc);
    }
}