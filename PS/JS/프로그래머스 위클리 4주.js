function solution(table, languages, preference) {

    table = table.map((str) => {
        let arr = str.split(" ");
        let res = { id: arr[0] };
        res[arr[1]] = 5;
        res[arr[2]] = 4;
        res[arr[3]] = 3;
        res[arr[4]] = 2;
        res[arr[5]] = 1;
        return res;
    });

    languages = languages.map((lang, idx) => [lang, preference[idx]]);
    let answer = 'ZZZZZZZZZZZZZ';
    let mx = -1;

    for (let m of table) {
        let point = 0;
        for (let lang of languages) {
            point += m[lang[0]] ? m[lang[0]] * lang[1] : 0;
        }

        if (mx < point || (mx == point && answer > m.id)) {
            mx = point;
            answer = m.id;
        }
    }

    return answer;
}