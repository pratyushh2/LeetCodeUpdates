var removeKdigits = function(num, k) {

    // Stack will store the digits that remain.
    const stack = [];

    // Process every digit from left to right.
    for (const digit of num) {

        // If the last digit in our stack is bigger than
        // the current digit, removing that bigger digit
        // will make the number smaller.
        //
        // Keep removing while we still have deletions available.
        while (
            k > 0 &&
            stack.length > 0 &&
            stack[stack.length - 1] > digit
        ) {
            stack.pop();
            k--;
        }

        // Add the current digit to the stack.
        stack.push(digit);
    }

    // If we still need to remove digits,
    // remove them from the end.
    while (k > 0) {
        stack.pop();
        k--;
    }

    // Convert the stack into a string.
    let result = stack.join('');

    // Remove leading zeroes.
    result = result.replace(/^0+/, '');

    // If nothing remains, the number is 0.
    return result === '' ? '0' : result;
};