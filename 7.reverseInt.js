/**
 * @param {number} x
 * @return {number}
 */
var reverse = function (x) {
    list = []

    if (x >= 2147483647 || x <= -2147483648)
        return 0;
    while (x != 0) {
        list.push((x % 10));
        x = ~~(x / 10);
    }

    Array.prototype.reverse(list);

    res = 0
    for (num of list) {
        res += num;
        res *= 10;
    }


    return res / 10;
};

reverse(123);