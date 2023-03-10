bool isMatch(char * s, char * p){
    char * sTmp = NULL, * pTmp = NULL;
    while (*s != '\0') {
        if (*p == '?' || *p == *s) {
            s++;
            p++;
        } else if (*p == '*') {
            sTmp = s;
            pTmp = p++;
        } else if (pTmp == NULL) {
            return false;
        } else {
            s = ++sTmp;
            p = pTmp + 1;
        }
    }
    while (*p == '*') p++;
    return (*p == '\0');
}