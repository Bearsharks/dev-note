function singleton() {
    let solo = {
        name: 'kcm',
        greeting: () => {
            console.log(`hi! my name is ${solo.name}`);
        },
        append: (str) => {
            solo.name += str;
        },
        doSomething: () => {
            solo.append(1);
        }
    }
    let instance;
    function init() {
        instance = {
            greeting: solo.greeting,
            doSomething: solo.doSomething
        }
    }
    return function () {
        if (!instance) init();
        return instance;
    }
};
const getSingletonObject = singleton();

let a = getSingletonObject();
a.greeting();
a.doSomething();
let b = getSingletonObject();
b.greeting();
b.doSomething();
a.greeting();


