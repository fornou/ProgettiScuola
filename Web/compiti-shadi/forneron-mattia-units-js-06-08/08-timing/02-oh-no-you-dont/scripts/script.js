function useful() {
    console.log("This function does something useful.");
}

const timeoutId = setTimeout(useful, 10000);

function cancelUseful() {
    clearTimeout(timeoutId);
    console.log('Function cancelled');
}

setTimeout(cancelUseful, 5000);
