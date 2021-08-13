// 1. 하나의 값을 입력받을 때
const input = require('fs').readFileSync('/dev/stdin').toString().trim();

// 2. 공백으로 구분된 한 줄의 값들을 입력받을 때
const input = require('fs').readFileSync('/dev/stdin').toString().trim().split(' ');

// 3. 여러 줄의 값들을 입력받을 때
const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');

// 4. 첫 번째 줄에 자연수 n을 입력받고, 그 다음줄에 공백으로 구분된 n개의 값들을 입력받을 때
const [n, ...arr] = require('fs').readFileSync('/dev/stdin').toString().trim().split(/\s+/);

// 5. 첫 번째 줄에 자연수 n을 입력받고, 그 다음줄부터 n개의 줄에 걸쳐 한 줄에 하나의 값을 입력받을 때
const [n, ...arr] = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');

// 6. 하나의 값 또는 공백으로 구분된 여러 값들을 여러 줄에 걸쳐 뒤죽박죽 섞여서 입력받을 때
// ex) n 입력 - 공백으로 구분된 n개의 값 입력 - m 입력 - 여러 줄에 걸쳐 m개의 값 입력
const input = require('fs').readFileSync('/dev/stdin').toString().trim().split(/\s+/);
const n = input[0];
const n_arr = input.slice(1, n + 1);
const [m, ...m_arr] = input.slice(n + 1);

// 2~6에서 입력받는 값들을 모두 String에서 Number로 바꾸려면 split()뒤에 .map(v => +v)를 추가


let fs = require('fs');
let input = fs.readFileSync('./dev/stdin').toString().split('\n');

let n = parseInt(input[0].toString().split(' ')[0]);
let k = parseInt(input[0].toString().split(' ')[1]);
let numbers = input[1].split(' ');
numbers = numbers.map(x => Number(x));

function solution(n, k, numbers) {
    var answer = 1e18;
    let powsum = [0];
    let sum = [0];
    for (let i of numbers) {
        sum.push(sum[sum.length - 1] + i);
        powsum.push(powsum[powsum.length - 1] + i * i);
    }
    for (let i = 1; i <= n - (k - 1); i++) {
        for (let j = i + k - 1; j <= n; j++) {
            let num = (j - i + 1);
            let m = (sum[j] - sum[i - 1]) / num;
            let candi = (powsum[j] - powsum[i - 1]) - 2 * m * (sum[j] - sum[i - 1]) + m * m * num;
            answer = answer > (candi / num) ? (candi / num) : answer;
        }
    }
    return Math.sqrt(answer).toFixed(12);
}

console.log(solution(n, k, numbers));