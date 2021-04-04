function solution(needs, r) {
    var answer = needs.length;
    let c = needs[0].length;
    let cntorigin = new Array(c).fill(0);
    let isdelete = new Array(needs.length).fill(false);
    for(let t = 0; t < c-r;t++){
        let cnt = cntorigin.slice();
        for(let i = 0; i < needs.length ; i++){
            if(!isdelete[i]){
                for(let j = 0; j < c ; j++){
                    cnt[j] += needs[i][j];
                }
            }            
        }
        let mnj = 0;
        let mn = cnt[0];
        for(let j = 1; j < c ; j++){
            if(cnt[j]<mn){
                mnj = j;
                mn = cnt[j];
            }
        }
        answer -= mn;
        cntorigin[mnj] = Infinity;
        for(let i = 0; i < needs.length ; i++){
            if(needs[i][mnj] == 1) isdelete[i] = true;
        }
    }
    
    return answer;
}
let k =solution([ [ 1], [1], [1], [1], [1], [1] ]	,1);
let k1 = 0;