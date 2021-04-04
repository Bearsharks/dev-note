function solution(key, lock) {
    var answer = true;
    const rot90 = (key)=>{
        let ret = new Array(key.length).fill(null).map(()=>new Array(key.length));
        for(let i = 0; i < key.length ; i++){
            for(let j = 0; j < key.length ; j++){
                ret[j][key.length-1-i] = key[i][j];
            }
        }
        return ret;
    }
    const keys = [key];
    for(let i =1;i < 4;i++){
        keys.push(rot90(keys[i-1]));
    }
    
    let mni = 987654321,mxi=-1,mnj=987654321,mxj=-1;
    for(let i = 0; i < lock.length ; i++){
        for(let j = 0; j < lock.length ; j++){
            if(lock[i][j] == 0){
                mni = mni > i ? i : mni;
                mxi = mxi < i ? i : mxi;
                mnj = mnj > j ? j : mnj;
                mxj = mxj < j ? j : mxj;
            }
        }
    }
    if(mxi - mni + 1 > key.length || mxj - mnj + 1 > key.length) return false 
    let starti, startj;
    starti = mxi - key.length + 1;
    startj = mxj - key.length + 1;
 
    const test = (y,x,keyi)=>{
        for(let i = 0; i < key.length ; i++){
            for(let j = 0; j < key.length ; j++){
                if(0 <= i+y && i+y < lock.length && 0 <= j+x && j+x < lock.length){
                    //자물쇠 영역안에서
                    if(lock[i+y][j+x] == 0){
                        //자물쇠 홈인데
                        if(keys[keyi][i][j] == 0) return false;
                        //열쇠 홈이면 실패
                    } else {
                        //자물쇠 돌기인데
                        if(keys[keyi][i][j] == 1) return false;
                        //열쇠 돌기면 실패
                    } 
                }                               
            }
        }
        return true;
    }
    const isPossible = ()=>{
        for(let i = starti;i <= mni;i++){
            for(let j = startj;j <= mnj;j++){
                for(let k = 0 ; k < 4;k++){
                    if(test(i,j,k)) return true;
                }
            }
        }
        return false;
    }
    return isPossible();
}
console.log(solution([[0, 0, 0], [1, 0, 0], [0, 1, 1]] ,	[[1, 1, 1], [1, 1, 0], [1, 0, 1]]));