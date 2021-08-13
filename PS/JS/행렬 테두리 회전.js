function solution(rows, columns, queries) {
    var answer = [];
    let rowStart = 1;
    const makeRow = (a, n) => {
        let row = new Array(n).fill(null).map(() => a++);
        rowStart += n;
        return row;
    }

    let arr = new Array(rows).fill(null).map(() => makeRow(rowStart, columns));
    //console.log(arr);
    const rotNums = (i, j, dx, dy) => {
        let nums = [];
        for (let k = 0; k <= dy; k++) nums.push(arr[i][j + k]);
        for (let k = 1; k <= dx; k++) nums.push(arr[i + k][j + dy]);
        for (let k = dy - 1; k >= 0; k--) nums.push(arr[i + dx][j + k]);
        for (let k = dx - 1; k >= 1; k--) nums.push(arr[i + k][j]);
        let idx = 0;
        for (let k = 1; k <= dy; k++) arr[i][j + k] = nums[idx++];
        for (let k = 1; k <= dx; k++) arr[i + k][j + dy] = nums[idx++];
        for (let k = dy - 1; k >= 0; k--) arr[i + dx][j + k] = nums[idx++];
        for (let k = dx - 1; k >= 1; k--) arr[i + k][j] = nums[idx++];
        arr[i][j] = nums[idx];
        return Math.min(...nums);
    }
    queries.map((q) => {
        let ulx = q[0], uly = q[1], drx = q[2], dry = q[3];
        let dx = drx - ulx;
        let dy = dry - uly;
        answer.push(rotNums(ulx - 1, uly - 1, dx, dy));
    });
    return answer;
}
