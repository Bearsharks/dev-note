function solution(places) {
    var answer = [];
    const d = [[-1, 0], [0, 1], [1, 0], [0, -1]];

    const getRes = (testCase) => {
        testCase = testCase.map(el => el.split(''));
        const dfs = (i, j, depth) => {
            if (testCase[i][j] === 'P') return false;
            if (depth + 1 == 2) return true;
            for (let p of d) {
                let nexti = p[0] + i;
                let nextj = p[1] + j;
                if (0 <= nexti && nexti < 5 && 0 <= nextj && nextj < 5
                    && testCase[nexti][nextj] != 'X' && !dfs(nexti, nextj, depth + 1)) {
                    return false;
                }
            }
            return true;
        }

        for (let i = 0; i < 5; i++) {
            for (let j = 0; j < 5; j++) {
                if (testCase[i][j] !== 'P') continue;
                testCase[i][j] = "X";
                if (!dfs(i, j, 0)) return false;
            }
        }
        return true;
    }

    for (let t of places) {
        answer.push(getRes(t) ? 1 : 0);
    }
    return answer;
}
console.log(solution([["POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"], ["POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"], ["PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"], ["OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"], ["PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"]]));