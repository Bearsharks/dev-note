let fs = require('fs');
let input = fs.readFileSync('./dev/stdin').toString().split('\n');

let n = parseInt(input[0].toString().split(' ')[0]);
let k = parseInt(input[0].toString().split(' ')[1]);
let numbers = input[1].split(' ');
numbers = numbers.map(x=>Number(x));

function solution(n, k, numbers) {
    var answer = 1e18;
    let powsum = [0];
    let sum = [0];
    for(let i of numbers){
        sum.push(sum[sum.length -1] + i);
        powsum.push(powsum[powsum.length -1] + i*i);
    }
    for(let i = 1; i <= n - (k-1);i++){
        for(let j = i+k-1; j <= n ; j++){
            let num  = (j - i + 1);
            let m = (sum[j] - sum[i-1]) / num;
            let candi = (powsum[j] - powsum[i-1]) - 2 *  m * (sum[j] - sum[i-1]) + m*m*num;
            answer = answer > (candi / num) ? (candi / num) : answer;
        }
    }
    return Math.sqrt(answer).toFixed(12);
}

console.log(solution(n,k,numbers));