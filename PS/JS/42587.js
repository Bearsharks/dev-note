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
console.log(solution([1, 1, 9, 1, 1, 1], 0));