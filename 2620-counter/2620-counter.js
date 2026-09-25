var createCounter = function(n) {

    // Store the current value of the counter.
    let count = n;

    // Return a function that remembers 'count'.
    return function() {

        // Return the current value,
        // then increase it by 1.
        return count++;
    };
};