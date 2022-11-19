var res = []
/**
 * @param {number} n
 * @return {string[]}
 */
var generateParenthesis = function (n) {
    if (n === 1)
        return ["()"];
    for (var i = 0; i < 3; i++) {
        solve(n - 1, "", i);
    }
    return [...new Set(res)];
};



function solve(n, current_s, rule) {
    switch (rule) {

        case 0:
            {
                if (n === 0) {
                    res.push(current_s + "()");
                    res.push("(" + current_s + ")");
                    res.push("()" + current_s);
                }

                for (var i = 0; i < n; i++) {
                    solve(n - 1, '(' + current_s + ')', i);
                }
                return;
            }
        case 1:
            {
                if (n === 0) {
                    res.push(current_s + "()");
                    res.push("(" + current_s + ")");
                    res.push("()" + current_s);
                }
                for (var i = 0; i < n; i++) {
                    solve(n - 1, '()' + current_s, i);
                }
                return;
            }
        case 2:
            {
                if (n === 0) {
                    res.push(current_s + "()");
                    res.push("(" + current_s + ")");
                    res.push("()" + current_s);
                }
                for (var i = 0; i < n; i++) {
                    solve(n - 1, current_s + '()', i);
                }
                return;
            }
        default:
            return current_s + '()';
    }

};

generateParenthesis(2);