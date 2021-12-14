def restoreIpAddresses(s):
    res = []
    # if s contains non-numeric characters, then return empty list
    if not s.isdigit():
        return res
    # if s is less than 4 digits, then return empty list
    if len(s) < 4:
        return res
    # if s is more than 12 digits, then return empty list
    if len(s) > 12:
        return res
    # if s is 4 digits, then return s
    if len(s) == 4:
        res.append(s[0] + '.' + s[1] +
                   '.' + s[2] + '.' + s[3])
        return res

    # the position of the first segment
    for i in range(1, 4):
        # if not enough digits to split
        if len(s)-i < 3:
            continue
        for j in range(i+1, i+4):
            if len(s)-j < 2:
                continue
            for k in range(j+1, j+4):
                if len(s)-k < 1:
                    continue
                # bigger than 255
                if(int(s[0:i]) > 255 or int(s[i:j]) > 255 or int(s[j:k]) > 255 or int(s[k:]) > 255):
                    continue
                # initial 0
                if((s[0:i] != '0' and s[0] == '0') or (s[i:j] != '0' and s[i] == '0') or (s[j:k] != '0' and s[j] == '0') or (s[k:] != '0' and s[k] == '0')):
                    continue
                res.append(s[0:i] + '.' + s[i:j] +
                           '.' + s[j:k] + '.' + s[k:])
    return res


if __name__ == "__main__":
    s = "101023"
    # print(s[0:3])
    print(restoreIpAddresses(s))
