char* minWindow(char* s, char* t) {
    int need[128] = {0};
    int window[128] = {0};
    
    int tLen = strlen(t);
    int sLen = strlen(s);

    for (int i = 0; i < tLen; i++) {
        need[t[i]]++;
    }

    int left = 0, right = 0;
    int count = 0;
    int minLen = sLen + 1;
    int start = 0;

    while (right < sLen) {
        char c = s[right];
        window[c]++;
        if (need[c] > 0 && window[c] <= need[c]) {
            count++;
        }

        while (count == tLen) {
            if (right - left + 1 < minLen) {
                minLen = right - left + 1;
                start = left;
            }
            char lChar = s[left];
            window[lChar]--;
            if (need[lChar] > 0 && window[lChar] < need[lChar]) {
                count--;
            }
            left++;
        }
        right++;
    }

    if (minLen == sLen + 1) return strdup("");
    
    char* result = (char*)malloc(minLen + 1);
    strncpy(result, s + start, minLen);
    result[minLen] = '\0';
    return result;
}
