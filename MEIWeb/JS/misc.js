function indent(n){
    var s = "";
    for(var i = 0; i < n; i++){
        s += "\t";
    }
    return s;
}

function lines(x, y, stride, svg){    
    for(var i = 0; i < 5; i++){
        var line = document.createElementNS(svgNS, "line");
        line.setAttribute("x1", x);
        line.setAttribute("x2", (x + stride));
        line.setAttribute("y1", (y+10*i));
        line.setAttribute("y2", (y+10*i));
        line.setAttribute("style", "stroke: black;");
        svg.appendChild(line);
    }
}

function ellipse(x, y, color, svg){
    
    var ellipse = document.createElementNS(svgNS, "ellipse");
    ellipse.setAttribute("cx", x);
    ellipse.setAttribute("cy", y);
    ellipse.setAttribute("rx", 6);
    ellipse.setAttribute("ry", 5);
    ellipse.setAttribute("style", "strike:" + color + ";");
    ellipse.setAttribute("fill", color);
    svg.appendChild(ellipse);
}

function text(x, y, text, color, svg){
    
    var textElem = document.createElementNS(svgNS, "text");
    textElem.setAttribute("x", x);
    textElem.setAttribute("y", y);
    textElem.setAttribute("font-size", 12);
    textElem.setAttribute("fill", color);
    
    var textNode = document.createTextNode(text);
    textElem.appendChild(textNode);
    
    svg.appendChild(textElem);
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
    if(note == "b"){
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
        return "b";
    }
    if(note == "b"){
        return "c";
    }
    else{
        return "none";
    }
}

function previousNote(note){
    if(note == "c"){
        return "b";
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
    if(note == "b"){
        return "a";
    }
    else{
        return "none";
    }
}

function d(){
    var filename = "file.mei";
    downloadFile(filename, output);
}

function downloadFile(filename, data) {
    var blob = new Blob([data], {type: 'text/plain;charset=utf-8,'});
    if(window.navigator.msSaveOrOpenBlob) {
        window.navigator.msSaveBlob(blob, filename);
    }
    else{
        var elem = window.document.createElement('a');
        elem.href = window.URL.createObjectURL(blob);
        elem.download = filename;
        document.body.appendChild(elem);
        elem.click();
        document.body.removeChild(elem);
    }
}