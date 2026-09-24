var map = function(arr, fn) {

    // Create an empty array to store the transformed values.
    const result = [];

    // Loop through every element of arr.
    for (let i = 0; i < arr.length; i++) {

        // Apply fn to the current value and its index.
        // Store the returned value in result.
        result.push(fn(arr[i], i));
    }

    // Return the new transformed array.
    return result;
};