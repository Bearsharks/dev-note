function solution(n) {
    const getCnt = (n)=>{
        var dp = [0,1,2];
        for(let i = 3; i <= n;i++){
            dp.push(dp[i-1] + dp[i-2]);
        }
        return dp[n];
    }
    return getCnt(n);
}

console.log(solution(7));