let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');
let t = parseInt(input[0]);

function solution(priorities, location) {
    var answer = 1;
    var v = new Array(10).fill(0);
    for(let prior of priorities){
        v[prior]++;
    }
    let p = priorities[location];
    priorities[location] = -1;
    let curp = 9;
    let curi = 0;
    while(curp >= p){
        if(curp > p){
            while(v[curp]){
                if(priorities[curi%priorities.length] == curp){
                    v[curp]--;
                    answer++;
                }
                curi++;
            }
        }else{
            while(priorities[curi%priorities.length] != -1){
                if(priorities[curi%priorities.length] == curp){
                    answer++;
                } 
                curi++;
            }
            return answer;
        }
        curp--;
    }
    return answer;
}

for(let i = 1; i <= t*2; i+=2){
    let cur = input[i].split(' ');
    let location = parseInt(cur[1]);
    cur = input[i+1].split(' ');
    let priorities = cur.map(element => parseInt(element));   
    
    console.log(solution(priorities, location));
}