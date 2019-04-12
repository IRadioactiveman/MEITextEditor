/* In this file miscellaneous functions used in th program are defined whcih includes indenting, translating note values, scrolling the graphical output and downloading the MEI file.*/

/**
 * This function returns a specified number of indents.
 * @param {number} n - the amount of indents
 * @returns {string} s - the string containing n indents
 */
function indent(n){
    var s = "";
    for(var i = 0; i < n; i++){
        s += "\t";
    }
    return s;
}

/**
 * This function translates a note value to a predefined y value that is used in graphical output.
 * @param {string} note - the note to be translated
 * @returns {number} a number representing the y value in the graphical output
 */
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

/**
 * This function scrolls the graphical output up.
 */
function scrollUp(){
    startY += 15;
    createSVGOutput();
}

/**
 * This function scrolls the graphical output down.
 */
function scrollDown(){
    startY -= 15;
    createSVGOutput();
}

/**
 * This function is called by the download button and in itself defines a filename before calling the actual function to download the MEI file.
 */
function d(){
    var filename = "file.mei";
    downloadFile(filename, output);
}

/**
 * This function downloads a text file with given name and data.
 * @param {string} filename - specifies the name of the file to download
 * @param {string} data - specifies the data that is to be included in the text file
 */
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