var debounce = function(fn, t) {

    // Store the ID of the current timer.
    // We need this so that we can cancel it
    // when the function is called again.
    let timer;

    // Return the debounced version of the function.
    return function(...args) {

        // Cancel the previous timer.
        // This prevents the previous call to fn
        // from being executed.
        clearTimeout(timer);

        // Create a new timer.
        // fn will execute only if another call
        // does not happen within t milliseconds.
        timer = setTimeout(() => {

            // Call the original function
            // with all the arguments passed to us.
            fn(...args);

        }, t);
    };
};
/**
 * const log = debounce(console.log, 100);
 * log('Hello'); // cancelled
 * log('Hello'); // cancelled
 * log('Hello'); // Logged at t=100ms
 */