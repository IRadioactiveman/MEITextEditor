function indent(n){
    var s = "";
    for(var i = 0; i < n; i++){
        s += "\t";
    }
    return s;
}

function lines(x, y, stride){    
    var s = "";
    for(var i = 0; i < 5; i++){
        s += "<line x1=\""+x+"\" y1= \""+(y+10*i)+"\" x2=\""+(x+stride)+"\" y2=\""+(y+10*i)+"\"";
        s += " style=\"stroke:black;\"";
        s += "/>";
    }
    return s;
}

function ellipse(x, y, color){
    var s = "";
    s += "<ellipse cx=\""+x+"\" cy=\""+y+"\" rx=\"6\" ry=\"4\" style=\"stroke:"+color+";\" fill=\""+color+"\"/>"
    return s;
}

function text(x, y, text, color){
    var s = "";
    s += "<text x=\""+x+"\" y=\""+y+"\" font-size=\"12\" fill=\""+color+"\">"+text+"</text>";
    return s;
}

function translateNoteValue(note){
    if(note == "c"){
        return 50;
    }
    if(note == "d"){
        return 45;
    }
    if(note == "e"){
        return 40;
    }
    if(note == "f"){
        return 35;
    }
    if(note == "g"){
        return 30;
    }
    if(note == "a"){
        return 25;
    }
    if(note == "h"){
        return 20;
    }
    else{
        return 10;
    }
}

function scrollUp(){
    startY += 15;
    createSVGOutput();
}

function scrollDown(){
    startY -= 15;
    createSVGOutput();
}

function followingNote(note){
    if(note == "c"){
        return "d";
    }
    if(note == "d"){
        return "e";
    }
    if(note == "e"){
        return "f";
    }
    if(note == "f"){
        return "g";
    }
    if(note == "g"){
        return "a";
    }
    if(note == "a"){
        return "h";
    }
    if(note == "h"){
        return "c";
    }
    else{
        return "none";
    }
}

function previousNote(note){
    if(note == "c"){
        return "h";
    }
    if(note == "d"){
        return "c";
    }
    if(note == "e"){
        return "d";
    }
    if(note == "f"){
        return "e";
    }
    if(note == "g"){
        return "f";
    }
    if(note == "a"){
        return "g";
    }
    if(note == "h"){
        return "a";
    }
    else{
        return "none";
    }
}