let fs = require('fs');
let input = fs.readFileSync('./dev/stdin').toString().trim();

function solution(str) {
    let answer = 0;
    let i = 0;
    while (i < str.length) {
        if (str[i] === 'c') {
            if (i + 1 < str.length && (str[i + 1] === '=' || str[i + 1] === '-')) {
                i++;
            }
        } else if (str[i] === 'd') {
            if (i + 1 < str.length && str[i + 1] === 'z' && i + 2 < str.length && str[i + 2] === '=') {
                i += 2;
            } else if (i + 1 < str.length && str[i + 1] === '-') {
                i++;
            }
        } else if (str[i] === 'l' || str[i] === 'n') {
            if (i + 1 < str.length && str[i + 1] === 'j') i++;
        } else if (str[i] === 's' || str[i] === 'z') {
            if (i + 1 < str.length && str[i + 1] === '=') i++;
        }
        answer++;
        i++;
    }
    return answer;
}

console.log(solution(input));