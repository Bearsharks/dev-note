function solution(code) {
    var answer = [];

    const block = {
        depth: 0,
        variables: new Map(),//map은 name과 array 출력시에는 array의 마지막을 출력
        parent: null,
        child: null //새로운 블록이 담긴다;
    }
    const create = (name, num, curBlock) => {
        let vars = curBlock.variables.get(name);
        if (vars) {
            vars.push(num);
        } else {
            curBlock.variables.set(name, [num]);
        }
    }
    const print = (name, curBlock) => {
        if (curBlock.depth === -1) {
            answer.push('error');
            return;
        }
        let vars = curBlock.variables.get(name);
        if (vars) {
            answer.push(`${name}=${vars[vars.length - 1]}`);
        } else {
            print(name, curBlock.parent);
        }
    }
    const parse = (str) => {
        let depth = 0;
        let result = [];
        while (str[depth] === '.') {
            depth++;
        }

        str = str.slice(depth);

        str = str.split('=');
        if (str.length === 2) {

            result.push(str[0]);
            result.push(str[1]);
            result.push(create);
        } else {
            str = str[0].split(' ');
            result.push(str[1]);
            result.push(print);
        }
        result.push(depth);
        return result;
    }
    let b = { ...block, depth: -1 };
    for (let c of code) {
        const res = parse(c);
        const curDepth = res.pop();
        if (b.depth !== curDepth) {
            if (b.depth < curDepth) {
                b.child = { ...block, variables: new Map(), parent: b, depth: curDepth };
                b = b.child;
            } else {
                while (b.depth > curDepth) {
                    b = b.parent;
                }
                b.child = null;
            }
        }
        const curfunc = res.pop();
        curfunc(...res, b);
    }

    return answer;
}

console.log(solution(["a=3", "..b=3", "..c=3", "..print a", "print a", ".......a=6", ".......print a", "..print b"]));