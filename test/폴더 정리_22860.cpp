//const input = require('fs').readFileSync('./mymy', "utf8").toString().trim().split('\r\n');
const input = require("fs").readFileSync("/dev/stdin").toString().trim().split('\n');
let fsPointer = 0;

function readInput() {
    return input[fsPointer++].split(' ');
}

const folders = {
}

const files = {
}

class Folder {
    childFolders = [];
    files = [];
    cnt = -1;
    fileSet = new Set();
    constructor(parent, name) {
        this.parent = parent;
        this.name = name;
    }
    initSubfileInfo() {
        if (this.cnt != = -1) {
            return[this.cnt, this.fileSet];
        }
        this.fileSet = new Set(this.files);
        this.cnt = this.files.length;
        for (let i = 0; i < this.childFolders.length; i++) {
            const [cnt, fileSet] = folders[this.childFolders[i]].initSubfileInfo();
            this.cnt += cnt;
            for (let file of fileSet) {
                this.fileSet.add(file);
            }
        }
        return[this.cnt, this.fileSet];
    }
}

class File {
    constructor(name) {
        this.name = name;
    }
}


function makeFolder(p, name) {
    if (!folders[p]) folders[p] = new Folder(null, name);
    if (folders[name] == = undefined) folders[name] = new Folder(p, name);
    else folders[name].parent = p;
    folders[p].childFolders.push(name);
}

function makeFile(p, name) {
    if (!folders[p]) folders[p] = new Folder(null, name);
    if (!files[name]) files[name] = new File(name);
    folders[p].files.push(name);
}

const [n, m] = readInput();


folders.main = new Folder(null, "main");
for (let i = 0, cnt = (+n) + (+m); i < cnt; i++) {
    const [p, name, isFolder] = readInput();
    if (+isFolder) makeFolder(p, name);
    else makeFile(p, name);
}

const [queryCnt] = readInput();

for (let i = 0, cnt = (+queryCnt); i < cnt; i++) {
    const [query] = readInput();
    const path = query.split('/');
    const folder = folders[path.pop()];
    const [cnt, fileSet] = folder.initSubfileInfo();
    console.log(fileSet.size, cnt);
}