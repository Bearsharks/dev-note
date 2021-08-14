class Node {
    constructor(val) {
        this.val = val;
        this.prev = null;
        this.next = null;
    }
}

class DoubleLinkedList {
    constructor() {
        this.head = null;
        this.tail = null;
        this.length = 0;
    }

    push(val) {
        const node = new Node(val);
        if (this.length === 0) {
            this.head = node;
            this.tail = node;
        } else {
            this.tail.next = node;
            node.prev = this.tail;
            this.tail = node;
        }
        this.length++;
        return this;
    }

    pop() {
        if (!this.head) {
            return -1;
        }
        const deletedNode = this.tail;
        if (this.length === 1) {
            this.head = null;
            this.tail = null;
        } else {
            this.tail = deletedNode.prev;
            this.tail.next = null;
            deletedNode.prev = null;
        }
        this.length--;
        return deletedNode.val;
    }

    shift() {
        if (!this.head) {
            return -1;
        }
        const deletedNode = this.head;
        if (this.length === 1) {
            this.head = null;
            this.tail = null;
        } else {
            this.head = deletedNode.next;
            this.head.prev = null;
            deletedNode.next = null;
        }
        this.length--;
        return deletedNode.val;
    }

    unshift(val) {
        const node = new Node(val);
        if (this.length === 0) {
            this.head = node;
            this.tail = node;
        } else {
            this.head.prev = node;
            node.next = this.head;
            this.head = node;
        }
    }
    front() {
        if (!this.head) {
            return -1;
        }
        return this.head.val;
    }
    back() {
        if (!this.head) {
            return -1;
        }
        return this.tail.val;
    }
}

let fs = require('fs');
// 5. 첫 번째 줄에 자연수 n을 입력받고, 그 다음줄부터 n개의 줄에 걸쳐 한 줄에 하나의 값을 입력받을 때
const [n, ...arr] = require('fs').readFileSync('./dev/stdin').toString().trim().split('\n');

const sol = (arr) => {
    let queue = new DoubleLinkedList();
    for (let cur of arr) {
        let [q, n] = cur.trim().split(" ");
        if (q === 'push') {
            queue.push(n);
        } else if (q === 'pop') {
            console.log(queue.shift());
        } else if (q === 'size') {
            console.log(queue.length);
        } else if (q === 'empty') {
            console.log(!queue.length ? 1 : 0);
        } else if (q === 'front') {
            console.log(queue.front());
        } else if (q === 'back') {
            console.log(queue.back());
        }
    }
}
sol(arr);