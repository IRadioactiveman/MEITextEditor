function createSVGOutput(){
    
    var canvas = document.getElementById("svgout");
    
    var s = "";
    s += "<svg width=\"1100\" height=\"200\">";
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
            s += text(x, y + 65, syllables[i].syllable, color);
            var textLength = syllables[i].syllable.length * 11;
            var notesLength = 0;
            var previousValue = startY+10;
            
            for(var j = 0; j < syllables[i].pitches.length; j++){
                if(Array.isArray(syllables[i].pitches[j])){
                    for(var k = 0; k < syllables[i].pitches[j].length; k++){
                        for(var l = 0; l < syllables[i].pitches[j][k].additionalPitches.length; l++){
                            if(syllables[i].pitches[j][k].additionalPitches[l].pitch != "none"){
                                s += lines(x, y, stride);
                                
                                var value = translateNoteValue(syllables[i].pitches[j][k].additionalPitches[l].pitch);
                                s += ellipse(x+6,y+value,"blue");
                                
                                previousValue = y + value;
                            }
                            
                            else if(syllables[i].pitches[j][k].additionalPitches[l].intm){
                                s += lines(x, y, stride);
                                if(syllables[i].pitches[j][k].additionalPitches[l].intm == "d"){
                                    s += ellipse(x+6,previousValue+10,"purple");
                                    
                                    previousValue += 10;
                                }
                                if(syllables[i].pitches[j][k].additionalPitches[l].intm == "u"){
                                    s += ellipse(x+6,previousValue-10,"purple");
                                    previousValue -= 10;
                                }
                                else{
                                    s += ellipse(x+6,previousValue,"purple");
                                }
                            }
                            else{
                                s += lines(x, y, stride);
                                s += ellipse(x+6,y+10,"purple");
                                
                                previousValue = y+10;
                            }
                            x += stride;
                            if(x >= 1000){
                                x = 0;
                                y += 85;
                            }
                        }
                    }
                }
                else{
                    if(syllables[i].pitches[j].pitch != "none"){
                        s += lines(x, y, stride);
                        
                        var valu = translateNoteValue(syllables[i].pitches[j].pitch);
                        s += ellipse(x+6,y+valu,"black");
                        
                        previousValue = y + valu;
                    }
                    
                    else if(syllables[i].pitches[j].intm){
                        s += lines(x, y, stride);
                        if(syllables[i].pitches[j].intm == "d"){
                            s += ellipse(x+6,previousValue+10,"red");
                            
                            previousValue += 10;
                        }
                        if(syllables[i].pitches[j].intm == "u"){
                            s += ellipse(x+6,previousValue-10,"red");
                            previousValue -= 10;
                        }
                        else{
                            s += ellipse(x+6,previousValue,"red");
                        }
                    }
                    
                    else{
                        s += lines(x, y, stride);
                        
                        s += ellipse(x+6,y+10,"red");
                        
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
                s += lines(x, y, diff);
                x += diff;
            }
        }
    }
    s += "</svg>";
    canvas.innerHTML = s;
    
    return s;
}