var cancellable = function(fn, args, t) {

    // Schedule fn to execute after t milliseconds.
    // setTimeout returns an ID representing this timer.
    const timer = setTimeout(() => {

        // Spread args so that the array elements
        // are passed as individual arguments to fn.
        fn(...args);

    }, t);

    // Return a function that can cancel the timer.
    return function() {

        // Cancel the scheduled execution of fn.
        clearTimeout(timer);
    };
};
