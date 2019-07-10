/**
 * This string contains the namespace of SVG.
 * @var {string} svgNS
 */
var svgNS = "http://www.w3.org/2000/svg";

/**
 * This element is the root element for the SVG output.
 * @var svg
 */
var svg = document.createElementNS(svgNS, "svg");

/**
 * This boolean represents if any SVG has been added before.
 * @var {boolean} svgAdded
 */
var svgAdded = false;

/**
 * This function seeks the svgout element - the element used for graphical output - in the underlying html document (index.html).
 * Afterwards it iterates over the syllables and draws them by creating html elements and adding children. After that the function
 * then iterates over the neumes with the according pitches and draws them on lines, considering differences between variations and
 * usual pitches.
 * @function
 */
function createSVGOutput(){
    
    var canvas = document.getElementById("svgout");
    
    if(svgAdded){
        canvas.removeChild(svg);
    }
    
    svgAdded = true;
    
    svg = document.createElementNS(svgNS, "svg");
    svg.setAttribute("width", window.innerWidth);
    svg.setAttribute("height", "200");
    
    var x = 0; 
    var y = startY;
    var stride = 15;
    
    if(syllables.length >= 1){
        for(var i = 0; i < syllables.length; i++){
            var color;
            if(syllables[i].color == "none"){
                color = "black";
            }
            else{
                color = syllables[i].color;
            }
            text(x, y + 65, syllables[i].syllable, color, svg);
            var textLength = syllables[i].syllable.length * 11;
            var notesLength = 0;
            var previousValue = startY+10;
            
            for(var j = 0; j < syllables[i].neumes.length; j++){
                
                if(Array.isArray(syllables[i].neumes[j])){
                    
                    for(var n = 0; n < syllables[i].neumes[j].length; n++){
                        
                        for(var o = 0; o < syllables[i].neumes[j][n].additionalNeumes.length; o++){
                            
                            for(var k = 0; k < syllables[i].neumes[j][n].additionalNeumes[o].pitches.length; k++){
                    
                                if(Array.isArray(syllables[i].neumes[j][n].additionalNeumes[o].pitches[k])){
                        
                                    for(var l = 0; l < syllables[i].neumes[j][n].additionalNeumes[o].pitches[k].length; l++){
                            
                                        for(var m = 0; m < syllables[i].neumes[j][n].additionalNeumes[o].pitches[k][l].additionalPitches.length; m++){
                                
                                            if(syllables[i].neumes[j][n].additionalNeumes[o].pitches[k][l].additionalPitches[m].pitch != "none"){
                                                lines(x, y, stride, svg);
                                
                                                var value = translateNoteValue(syllables[i].neumes[j][n].additionalNeumes[o].pitches[k][l].additionalPitches[m].pitch);
                                                ellipse(x+6,y+value,"blue", svg);
                                
                                                previousValue = y + value;
                                            }
                                            else if(syllables[i].neumes[j][n].additionalNeumes[o].pitches[k][l].additionalPitches[m].intm){
                                                lines(x, y, stride, svg);
                                                if(syllables[i].neumes[j][n].additionalNeumes[o].pitches[k][l].additionalPitches[m].intm == "d"){
                                                    ellipse(x+6,previousValue+10,"purple",svg);
                                    
                                                    previousValue += 10;
                                                }
                                                if(syllables[i].neumes[j][n].additionalNeumes[o].pitches[k][l].additionalPitches[m].intm == "u"){
                                                    ellipse(x+6,previousValue-10,"purple",svg);
                                                    previousValue -= 10;
                                                }
                                                else{
                                                    ellipse(x+6,previousValue,"purple",svg);
                                                }
                                            }
                                            else{
                                                lines(x, y, stride,svg);
                                                ellipse(x+6,y+10,"purple",svg);
                                
                                                previousValue = y+10;
                                            }
                                            x += stride;
                                            if(x >= (window.innerWidth - 100)){
                                                x = 0;
                                                y += 85;
                                            }
                                        }
                                    }
                                }
                                else{
                                    if(syllables[i].neumes[j][n].additionalNeumes[o].pitches[k].pitch != "none"){
                                        lines(x, y, stride,svg);
                        
                                        var valu = translateNoteValue(syllables[i].neumes[j][n].additionalNeumes[o].pitches[k].pitch);
                                        ellipse(x+6,y+valu,"blue",svg);
                        
                                        previousValue = y + valu;
                                    }
                                    else if(syllables[i].neumes[j][n].additionalNeumes[o].pitches[k].intm){
                                        lines(x, y, stride,svg);
                                        if(syllables[i].neumes[j][n].additionalNeumes[o].pitches[k].intm == "d"){
                                            ellipse(x+6,previousValue+10,"purple",svg);
                            
                                            previousValue += 10;
                                        }
                                        if(syllables[i].neumes[j][n].additionalNeumes[o].pitches[k].intm == "u"){
                                            ellipse(x+6,previousValue-10,"purple",svg);
                                            previousValue -= 10;
                                        }
                                        else{
                                            ellipse(x+6,previousValue,"purple",svg);
                                        }
                                    }
                                    else{
                                        lines(x, y, stride,svg);
                        
                                        ellipse(x+6,y+10,"red",svg);
                        
                                        previousValue = y + 10;
                                    }
                                    x += stride;
                                    if(x >= (window.innerWidth - 100)){
                                        x = 0;
                                        y += 85;
                                        previousValue += 85;
                                    }
                                }
                                notesLength += stride;
                            }
                        }
                    }
                    if(textLength > notesLength){
                        var diff = textLength - notesLength;
                        lines(x, y, diff,svg);
                        x += diff;
                    }
                }
                else{
                    for(var k = 0; k < syllables[i].neumes[j].pitches.length; k++){
                    
                        if(Array.isArray(syllables[i].neumes[j].pitches[k])){
                        
                            for(var l = 0; l < syllables[i].neumes[j].pitches[k].length; l++){
                            
                                for(var m = 0; m < syllables[i].neumes[j].pitches[k][l].additionalPitches.length; m++){
                                
                                    if(syllables[i].neumes[j].pitches[k][l].additionalPitches[m].pitch != "none"){
                                        lines(x, y, stride, svg);
                                
                                        var value = translateNoteValue(syllables[i].neumes[j].pitches[k][l].additionalPitches[m].pitch);
                                        ellipse(x+6,y+value,"blue", svg);
                                
                                        previousValue = y + value;
                                    }
                                    else if(syllables[i].neumes[j].pitches[k][l].additionalPitches[m].intm){
                                        lines(x, y, stride, svg);
                                        if(syllables[i].neumes[j].pitches[k][l].additionalPitches[m].intm == "d"){
                                            ellipse(x+6,previousValue+10,"purple",svg);
                                    
                                            previousValue += 10;
                                        }
                                        if(syllables[i].neumes[j].pitches[k][l].additionalPitches[m].intm == "u"){
                                            ellipse(x+6,previousValue-10,"purple",svg);
                                            previousValue -= 10;
                                        }
                                        else{
                                            ellipse(x+6,previousValue,"purple",svg);
                                        }
                                    }
                                    else{
                                        lines(x, y, stride,svg);
                                        ellipse(x+6,y+10,"purple",svg);
                                
                                        previousValue = y+10;
                                    }
                                    x += stride;
                                    if(x >= (window.innerWidth - 100)){
                                        x = 0;
                                        y += 85;
                                    }
                                }
                            }
                        }
                        else{
                            if(syllables[i].neumes[j].pitches[k].pitch != "none"){
                                lines(x, y, stride,svg);
                        
                                var valu = translateNoteValue(syllables[i].neumes[j].pitches[k].pitch);
                                ellipse(x+6,y+valu,"black",svg);
                        
                                previousValue = y + valu;
                            }
                            else if(syllables[i].neumes[j].pitches[k].intm){
                                lines(x, y, stride,svg);
                                if(syllables[i].neumes[j].pitches[k].intm == "d"){
                                    ellipse(x+6,previousValue+10,"red",svg);
                            
                                    previousValue += 10;
                                }
                                if(syllables[i].neumes[j].pitches[k].intm == "u"){
                                    ellipse(x+6,previousValue-10,"red",svg);
                                    previousValue -= 10;
                                }
                                else{
                                    ellipse(x+6,previousValue,"red",svg);
                                }
                            }
                            else{
                                lines(x, y, stride,svg);
                        
                                ellipse(x+6,y+10,"red",svg);
                        
                                previousValue = y + 10;
                            }
                            x += stride;
                            if(x >= (window.innerWidth - 100)){
                                x = 0;
                                y += 85;
                                previousValue += 85;
                            }
                        }
                        notesLength += stride;
                    }
                    if(textLength > notesLength){
                        var diff = textLength - notesLength;
                        lines(x, y, diff,svg);
                        x += diff;
                    }
                }
            }
        }
    }
    canvas.appendChild(svg);
}

/**
 * A function for creating five line elements (the staff), assigning them a specific starting place and length, and appending
 * the lines to a root element.
 * @function
 * @param {number} x - the x coordinate to start to draw
 * @param {number} y - the y coordinate to start to draw
 * @param {number} stride - the length to draw the lines
 * @param {object} svg - the root element to append the line elements to
 */
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

/**
 * A function for creating an ellipse element (the note), assigning it a specific starting place and length, a color, and appending
 * the ellipse to a root element.
 * @function
 * @param {number} x - the x coordinate to start to draw
 * @param {number} y - the y coordinate to start to draw
 * @param {string} color - the color of the ellipse
 * @param {object} svg - the root element to append the ellipse element to
 */
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

/**
 * A function for creating a text element (the syllable), assigning it a specific starting place and length, the text itself and a 
 * color, and appending the lines to a root element.
 * @function
 * @param {number} x - the x coordinate to start to draw
 * @param {number} y - the y coordinate to start to draw
 * @param {string} text - the text to draw
 * @param {string} color - the color of the text
 * @param {object} svg - the root element to append the text element to
 */
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