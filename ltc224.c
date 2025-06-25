int calculate(char * s){
    int stack[1000];
    int top = -1;
    int result = 0;
    int sign = 1;
    int num = 0;
    
    for (int i = 0; s[i]; i++) {
        char c = s[i];
        
        if (c >= '0' && c <= '9') {
            num = num * 10 + (c - '0');
        } else if (c == '+') {
            result += sign * num;
            num = 0;
            sign = 1;
        } else if (c == '-') {
            result += sign * num;
            num = 0;
            sign = -1;
        } else if (c == '(') {
            // push current result and sign to stack
            stack[++top] = result;
            stack[++top] = sign;
            result = 0;
            sign = 1;
        } else if (c == ')') {
            result += sign * num;
            num = 0;
            int prevSign = stack[top--];
            int prevResult = stack[top--];
            result = prevResult + prevSign * result;
        }
        // space or others ignored
    }
    
    result += sign * num;
    return result;
}
