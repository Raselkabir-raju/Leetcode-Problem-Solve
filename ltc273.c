char *ones[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
char *teens[] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen",
                 "Seventeen", "Eighteen", "Nineteen"};
char *tens[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
char *thousands[] = {"", "Thousand", "Million", "Billion"};

void helper(int num, char *res) {
    if (num == 0) return;

    if (num >= 100) {
        strcat(res, ones[num / 100]);
        strcat(res, " Hundred ");
        num %= 100;
    }
    if (num >= 20) {
        strcat(res, tens[num / 10]);
        strcat(res, " ");
        num %= 10;
    }
    else if (num >= 10) {
        strcat(res, teens[num - 10]);
        strcat(res, " ");
        return;
    }
    if (num > 0) {
        strcat(res, ones[num]);
        strcat(res, " ");
    }
}

char* numberToWords(int num) {
    if (num == 0) {
        char *zero = (char *)malloc(5);
        strcpy(zero, "Zero");
        return zero;
    }
    
    char *res = (char *)malloc(512);
    res[0] = '\0';
    
    int i = 0;
    while (num > 0) {
        int part = num % 1000;
        if (part != 0) {
            char chunk[128] = "";
            helper(part, chunk);
            if (thousands[i][0] != '\0') {
                strcat(chunk, thousands[i]);
                strcat(chunk, " ");
            }
           
            char temp[512];
            strcpy(temp, chunk);
            strcat(temp, res);
            strcpy(res, temp);
        }
        num /= 1000;
        i++;
    }
    
    
    int len = strlen(res);
    while(len > 0 && res[len-1] == ' ') {
        res[len-1] = '\0';
        len--;
    }
    
    return res;
}
