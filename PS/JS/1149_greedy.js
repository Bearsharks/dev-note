let fs = require('fs');
let input = fs.readFileSync('./BJ/stdin').toString().split('\n');
let n = parseInt(input[0]);
let rgbcost = [];
for(let i = 1; i <= n; i++){
    let cur = input[i].split(' ');
    rgbcost.push( cur.map( (x)=>parseInt(x) ) );
}

function solution(rgbcost) {
    let answer = new Array(3).fill(0);
    for(let rgb of rgbcost){
        let newAnswer = new Array(3);
        for(let i = 0 ; i < 3 ; i++){
            newAnswer[i] = rgb[i] + Math.min(answer[(i+1)%3], answer[(i+2)%3]);
        }
        answer = newAnswer;
    }
    return Math.min(...answer);
}

console.log(solution(rgbcost));