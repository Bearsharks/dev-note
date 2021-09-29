export default function queryselector(html) {
    return "abc";
}
export class DomNode {
    constructor(tag, className = "", text = "") {
        this.tag = tag;
        this.childs = [];
        this.className = className;
        this.text = text;
    }
}
export function tokenize(str) {
    str = str.trim();

    const words = str.split(" ");

    let tagName = "";
    let className = "";
    let text = "";
    if (str[0] !== "<") {
        tagName = 'text';
        text = str;
    } else {
        tagName = words[0].slice(1);
        if (tagName[tagName.length - 1] == ">") tagName = tagName.slice(0, -1);
        for (let i = 1; i < words.length; i++) {
            if (words[i].length < 1) continue;
            if (words[i].slice(0, 5) === 'class') {
                let strarr = words[i].split(`"`);
                className = strarr[1];
            }
        }
    }

    return new DomNode(tagName, className, text);
}
export function getTokens(html) {
    function getTagPos(start) {
        if (html[start] !== "<") throw Error(`시작 위치 : ${start}~ 태그 아님`);
        let end = start + 1;
        while (end < html.length && html[end] !== ">") {
            end++;
        }
        if (html[end] !== ">") throw Error(`끝 위치 : ~${end} 태그 아님`);
        return [start, end];
    }
    function getTextPos(start) {
        if (html[start] === "<" && html[start] === ">") throw Error(`시작 위치 : ${start}~ 텍스트 아님`);
        let end = start + 1;
        while (end < html.length && html[end] !== "<") {
            end++;
        }
        return [start, end - 1];
    }
    html = html.trim();
    const size = html.length;
    let tokens = new Array();
    for (let i = 0; i < size;) {
        const s_e = (html[i] === '<') ? getTagPos(i) : getTextPos(i);
        const curtoken = tokenize(html.slice(s_e[0], s_e[1] + 1));
        if (curtoken.tag !== 'text' || curtoken.text.length > 0) tokens.push(curtoken);
        i = s_e[1] + 1;
    }
    return tokens;
}

export function parse(html) {
    if (html.length <= 0) return new DomNode('text', "", "");
    const tokens = getTokens(html);
    let stack = [];
    if (tokens.length < 0 || tokens[0].tag === 'text') throw new Error("잘못된 HTML");
    stack.push(tokens[0]);
    for (let i = 1; i < tokens.length; i++) {
        if (tokens[i].tag === 'text') stack[stack.length - 1].childs.push(tokens[i]);
        else if (tokens[i].tag[0] === '/') {
            if (tokens[i].tag === '/' + stack[stack.length - 1].tag) {
                stack.pop();
            } else {
                throw new Error("잘못된 HTML");
            }
        } else {
            stack[stack.length - 1].childs.push(tokens[i]);
            stack.push(tokens[i]);
        }
    }
    return tokens[0];
}
const result = parse(`      <dt class="tit">
						
							
							
							
							
							
<span class="ico_rating_15">15세 관람가</span>




<a href="/movie/bi/mi/basic.naver?code=190320">  보이스  </a>
<!-- N=a:nol.title,r:1,i:190320 -->
</dt>    `);
let a = 0;