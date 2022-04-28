class Solution {
public:
    int uglyNumbersLessThanN(long long n, long long a, long long b, long long c) {
        // AUBUC = a+b+c - A^B - A^C - B^C + A^B^C
        return n/a + n/b + n/c -
        n/lcm(a, b) - n/lcm(a, c) - n/lcm(b, c) +
        n/lcm(a, lcm(b, c));
    }
    
    int nthUglyNumber(int n, int a, int b, int c) {
        int left = 1;
        int right = 2000000000;
        int mid = left + (right - left)/2;
        int curr, prev;
        while(left < right) {
            curr = uglyNumbersLessThanN(mid, a, b, c);
            prev = uglyNumbersLessThanN(mid - 1, a, b, c);
            if(prev < n && curr == n) break;
            
            if(prev < n && curr < n) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
            mid = left + (right - left)/2;
        }
        return mid;
    }
};