var TimeLimitedCache = function() {

    // Map stores:
    // key -> { value, timer }
    this.cache = new Map();
};

/**
 * @param {number} key
 * @param {number} value
 * @param {number} duration
 * @return {boolean}
 */
TimeLimitedCache.prototype.set = function(key, value, duration) {

    // Check whether the key already exists
    // and has not expired.
    const existed = this.cache.has(key);

    // If the key already exists, cancel its old timer.
    // Otherwise, the old timer could delete our new value later.
    if (existed) {
        clearTimeout(this.cache.get(key).timer);
    }

    // Create a new timer for the new expiration time.
    const timer = setTimeout(() => {

        // When the duration expires,
        // remove the key from the cache.
        this.cache.delete(key);

    }, duration);

    // Store the new value and its new timer.
    this.cache.set(key, {
        value: value,
        timer: timer
    });

    // Return true if an unexpired key already existed.
    return existed;
};

/**
 * @param {number} key
 * @return {number}
 */
TimeLimitedCache.prototype.get = function(key) {

    // Check if the key is currently in the cache.
    if (this.cache.has(key)) {

        // Return the stored value.
        return this.cache.get(key).value;
    }

    // Key doesn't exist or has expired.
    return -1;
};

/**
 * @return {number}
 */
TimeLimitedCache.prototype.count = function() {

    // Map.size gives the number of currently stored keys.
    return this.cache.size;
};