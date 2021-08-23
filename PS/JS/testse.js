function solution(arr) {
    var answer = 0;
    let prev = [arr[0]];
    let mn = 10;
    for (let n of arr) {
        mn = Math.min(mn, n);
        let back = prev[prev.length - 1];
        if (back === n) {
            continue;
        } else if (back < n) {//증가하면
            prev.push(n);
        } else {//감소하면
            while (prev.length && n < prev[prev.length - 1]) {
                //보다 큰 것을 다 지우고 answer에 추가
                answer++;
                prev.pop();
            }
            //작으면 새로추가
            if (prev.length === 0 || prev[prev.length - 1] < n) prev.push(n);
        }
    }
    if (mn === 0) answer--;
    return answer + prev.length;
}
console.log(solution([0, 1, 3, 2, 4, 2]));