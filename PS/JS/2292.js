let fs = require('fs');
const n = parseInt(require('fs').readFileSync('./dev/stdin').toString());

function solution(n) {
    let cur = 1;
    let cnt = 1;
    while (cur < n) {
        cur += cnt++ * 6;
    }
    return cnt;
}

console.log(solution(n));