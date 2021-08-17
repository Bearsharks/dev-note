function solution(lineinfo, s, e) {
    let stops = new Array(20001).fill(null).map(() => []);
    let lines = lineinfo.map((info, idx) => {
        let linestops = info.trim().split(' ').map(n => parseInt(n));
        for (let s of linestops) {
            stops[s].push(idx);
        }
        return new Set(linestops);
    })
    let node = [];
    for (let linestops of lines) {
        let adjs = new Set();
        for (let s of linestops) {
            for (let adj of stops[s]) {
                adjs.add(adj);
            }
        }
        adjs.delete(node.length);
        node.push(adjs);
    }

    let isVisit = new Array(node.length).fill(false);
    let q = [];
    let cur = 0;
    for (let linenumber of stops[s]) {
        isVisit[linenumber] = true;
        q.push([linenumber, 0]);
    }
    while (cur < q.length) {
        let [linenumber, depth] = q[cur++];
        if (lines[linenumber].has(e)) return depth;
        for (let adj of node[linenumber]) {
            if (!isVisit[adj]) {
                isVisit[adj] = true;
                q.push([adj, depth + 1]);
            }
        }
    }
    return -1;
}
console.log(solution(['1 2 3 4 5 6  ', '2 8 9 10 7', '8 11 12', '3 13 14 15'], 2, 12));