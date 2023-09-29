if(a == b) return a;
    if(a > b)
        return findLCM(a, a+b);
    else if (a < b)
        return findLCM(a+b, b);