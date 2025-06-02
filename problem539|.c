#include <stdio.h>

long long nCr2(long long n) {
    if (n < 2) return 0;
    return n * (n - 1) / 2;
}

long long distributeCandies(int n, int limit) {
    long long T = nCr2(n + 2);
    long long A = nCr2(n - limit + 1);
    long long B = nCr2(n - 2 * limit);
    long long C = nCr2(n - 3 * limit - 1);

    long long result = T - 3 * A + 3 * B - C;
    return result < 0 ? 0 : result;
}

int main() {
    printf("%lld\n", distributeCandies(5, 3));      
    printf("%lld\n", distributeCandies(10, 5));      
    printf("%lld\n", distributeCandies(0, 0));       
    printf("%lld\n", distributeCandies(10003, 20012)); 
    return 0;
}
