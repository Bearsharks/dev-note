{
    const abc = () => {
        a();
        console.log("bc");
    }

    const a = () => {
        console.log('a');
    }
    abc();
}

