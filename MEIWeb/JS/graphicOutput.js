var svgNS = "http://www.w3.org/2000/svg";
var svg = document.createElementNS(svgNS, "svg");
var svgAdded = false;

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
            
            for(var j = 0; j < syllables[i].pitches.length; j++){
                if(Array.isArray(syllables[i].pitches[j])){
                    for(var k = 0; k < syllables[i].pitches[j].length; k++){
                        for(var l = 0; l < syllables[i].pitches[j][k].additionalPitches.length; l++){
                            if(syllables[i].pitches[j][k].additionalPitches[l].pitch != "none"){
                                
                                lines(x, y, stride, svg);
                                
                                var value = translateNoteValue(syllables[i].pitches[j][k].additionalPitches[l].pitch);
                                ellipse(x+6,y+value,"blue", svg);
                                
                                previousValue = y + value;
                            }
                            
                            else if(syllables[i].pitches[j][k].additionalPitches[l].intm){
                                lines(x, y, stride, svg);
                                if(syllables[i].pitches[j][k].additionalPitches[l].intm == "d"){
                                    ellipse(x+6,previousValue+10,"purple",svg);
                                    
                                    previousValue += 10;
                                }
                                if(syllables[i].pitches[j][k].additionalPitches[l].intm == "u"){
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
                    if(syllables[i].pitches[j].pitch != "none"){
                        lines(x, y, stride,svg);
                        
                        var valu = translateNoteValue(syllables[i].pitches[j].pitch);
                        ellipse(x+6,y+valu,"black",svg);
                        
                        previousValue = y + valu;
                    }
                    
                    else if(syllables[i].pitches[j].intm){
                        lines(x, y, stride,svg);
                        if(syllables[i].pitches[j].intm == "d"){
                            ellipse(x+6,previousValue+10,"red",svg);
                            
                            previousValue += 10;
                        }
                        if(syllables[i].pitches[j].intm == "u"){
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
                    if(x >= 1000){
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
    
    canvas.appendChild(svg);
}