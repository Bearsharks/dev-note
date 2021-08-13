function solution(s) {
    var answer = s.length;
    //1부터 s길이 절반까지 시도
    //갯수, 위치 주면 압축된 문자열 길이를 함수 작성 함수 안에서 현재문자인덱스를 갱신
    let cur = 0;
    const getRepeatCnt = (n) => {
        let first = cur;
        if (cur + n >= s.length) {
            cur = s.length;
            return s.length - first;
        }
        let cnt = 1;
        cur = cur + n;
        for (; cur + n <= s.length; cur += n) {
            for (let j = 0; j < n; j++) {
                if (s[cur + j] !== s[first + j]) {
                    return (cnt === 1) ? n : cnt.toString().length + n;
                }
            }
            cnt++;
        }
        return (cnt === 1) ? n : cnt.toString().length + n;
    }
    for (let i = 1; i <= s.length / 2; i++) {
        cur = 0;
        let candi = 0;
        while (cur < s.length) {
            let cnt = getRepeatCnt(i);
            candi += cnt;
        }
        answer = Math.min(candi, answer);
    }
    return answer;
}
console.log(solution("ababcdcdababcdcd"));