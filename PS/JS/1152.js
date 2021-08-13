let fs = require('fs');
let input = fs.readFileSync('./dev/stdin').toString().trim();

function solution(str) {
    let cnt = 0;
    a = str.split(" ");
    for (let el of a) {
        cnt += !!(el.length);
    }
    return cnt;
}

console.log(solution(input));