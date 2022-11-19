function is_match(s1, s2) {
    pairs = ["()", "[]", "{}"];
    return pairs.some((value) => { return value === (s1 + s2) });
};

/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function (s) {
    if (s.length % 2 != 0)
        return false;

    var stk = [s[0]];
    var i = 1;
    while (i < s.length) {
        if (is_match(stk[stk.length - 1], s[i])) { stk.pop(); i++; }
        else {
            stk.push(s[i]);
            i++;
        }
    }

    return (stk.length == 0);
};

isValid("()[]")