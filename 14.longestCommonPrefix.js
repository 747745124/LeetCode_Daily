/**
 * @param {string[]} strs
 * @return {string}
 */
var longestCommonPrefix = function (strs) {
    if (strs.length <= 0)
        return "";
    if (strs.length === 1)
        return strs[0];

    lens = strs.map((str) => str.length);
    min_len = Math.min(...lens);
    if (min_len === 0)
        return "";
    var res = "";
    var i = 0;

    while (i < min_len) {
        var letter = strs[0][i];
        for (var str of strs) {
            if (str[i] != letter)
                return res;
        }
        res += letter;
        i++;
    }

    return res;

};

longestCommonPrefix(["ab", "a"])