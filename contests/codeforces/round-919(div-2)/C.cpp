#include <bits/stdc++.h>
using namespace std;
// #define DEBUG(x) cout << #x << " >>>> " << x << endl
#define MID(l, r) (l + (r - l) / 2)
#define CEILDIVISION(x, y) ((x + y - 1) / y)
#define INF (long long)1e18
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
const int MOD = 1e9 + 7; // 10^9 + 7

unordered_set<int> getDivisors(int n) {
    
    unordered_set<int> divisors;
    divisors.insert(1);
    for(int i = 2; i * i <= n; ++i) {
        if(n % i == 0) {
            divisors.insert(i);
            if(n / i != i)
                divisors.insert(n / i);
        }
    }

    return divisors;
}

int32_t main() {
    FASTIO;
    int t;
    cin >> t;
    
    while(t--){

        int n;
        cin >> n;
        vector<int> nums(n);
        for(int &num : nums) cin >> num;

        int points = 1;
        unordered_set<int> divisors = getDivisors(n);
        bool all_equal = true, all_odd = nums[0] % 2 == 1;
        bool all_even = nums[0] % 2 == 0;

        for(int i = 1; i < n; ++i) {
            if(nums[i] != nums[0])
                all_equal = false;
            if(nums[i] % 2 == 0)
                all_odd = false;
            else
                all_even = false;
        }

        if(n > 1 && (all_equal || all_odd || all_even))
            points = divisors.size() + 1;
        else if(n > 1) {
            for(int divisor : divisors) {

                if(divisor == 1 && (all_equal || all_even || all_odd)) {
                    points++;
                    continue;
                }
                // DEBUG(divisor);

                int gcd = -1;
                for(int i = 0, j = divisor; i < n && j < n; ++i, ++j) {
                    int diff = abs(nums[i] - nums[j]);

                    // DEBUG(i);
                    // DEBUG(j);
                    // DEBUG(diff);
                    
                    if(gcd == -1 && diff > 0)
                        gcd = diff;
                    else if(diff > 0)
                    gcd = __gcd(gcd, diff);
                }


                if(gcd > 1)
                    points++;
                
                // DEBUG(gcd);
                // DEBUG(points);
            }
            // DEBUG(points);
        }
        // DEBUG(points);

        cout << points << "\n";
    }

    return 0;
}




class Solution {
public:
#define MID(l, r) (l + (r - l) / 2)
    string getBinary(long long n) {
        string s;
        while (n) {
            if(n & 1)
                s += '1';
            else
                s += '0';
            n >>= 1;
        }

        reverse(s.begin(), s.end());
        return s;
    }
    
    long long getSetBitsFromOneToN(long long N) {
        long long two = 2, ans = 0;
        long long n = N;
        while (n) {
            ans += (N / two) * (two >> 1);
            if ((N & (two - 1)) > (two >> 1) - 1)
                ans += (N & (two - 1)) - (two >> 1) + 1;
            two <<= 1;
            n >>= 1;
        }
        return ans;
    }
    
    unsigned long long countSetBits(unsigned long long n, long long x) {
        unsigned long long count = 0;

        while (n > 0) {
            count += n & 1;  // Check the rightmost bit and add to the count if it is set
            n /= x;  // Move to the next position multiple of x
        }

        return count;
    }

    unsigned long long countSetBits(unsigned long long n, long long x) {
	    unsigned long long count = 0;
	
	    for (long long i = 0; i <= n; i += x) {
	        unsigned long long num = i;
	        while (num) {
	            count += num & 1;
	            num >>= 1;
	        }
	    }
	
	    return count;
	}

    long long findMaximumNumber(long long k, int x) {
        long long low = 1, high = 1e15;
        long long mid = MID(low, high);

        while (low <= high) {
            
            long long curr = countBits(mid, x);
            if(curr <= k && countBits(mid + 1, x) > k)
                return mid;
            else if(curr > k)
                high = mid - 1;
            else
                low = mid + 1;
            mid = MID(low, high);
        }

        return -1;
    }


};


/*

100 > 011, 010, 001

for x = 1: 2*2 - 1
for x = 2: 2 * 1

1000> 111 110 101 100 011 010 001

111 110 101 100 011 010 001



1: 2*2 

10000> 1111 1110 1101 1100 1011 1010 1001 1000 111 110 101 100 011 010 001
100000

1_ 2_ 2_ 2_ = 8
1_ 2_ 1_ 2_ = 4
12
*/


#include <bits/stdc++.h>
 
// A O(Logn) complexity program to count
// set bits in all numbers from 1 to n
using namespace std;
 
/* Returns position of leftmost set bit.
The rightmost position is considered
as 0 */
unsigned int getLeftmostBit(int n)
{
    int m = 0;
    while (n > 1) {
        n = n >> 1;
        m++;
    }
    return m;
}
 
/* Given the position of previous leftmost
set bit in n (or an upper bound on
leftmost position) returns the new
position of leftmost set bit in n */
unsigned int getNextLeftmostBit(int n, int m)
{
    unsigned int temp = 1 << m;
    while (n < temp) {
        temp = temp >> 1;
        m--;
    }
    return m;
}
 
// The main recursive function used by countSetBits()
unsigned int _countSetBits(unsigned int n, int m);
 
// Returns count of set bits present in
// all numbers from 1 to n
unsigned int countSetBits(unsigned int n)
{
    // Get the position of leftmost set
    // bit in n. This will be used as an
    // upper bound for next set bit function
    int m = getLeftmostBit(n);
 
    // Use the position
    return _countSetBits(n, m);
}
 
unsigned int _countSetBits(unsigned int n, int m)
{
    // Base Case: if n is 0, then set bit
    // count is 0
    if (n == 0)
        return 0;
 
    /* get position of next leftmost set bit */
    m = getNextLeftmostBit(n, m);
 
    // If n is of the form 2^x-1, i.e., if n
    // is like 1, 3, 7, 15, 31, .. etc,
    // then we are done.
    // Since positions are considered starting
    // from 0, 1 is added to m
    if (n == ((unsigned int)1 << (m + 1)) - 1)
        return (unsigned int)(m + 1) * (1 << m);
 
    // update n for next recursive call
    n = n - (1 << m);
    return (n + 1) + countSetBits(n) + m * (1 << (m - 1));
}
 
unsigned long long countSetBits(unsigned long long n, long long x) {
    if (n == 0) {
        return 0;
    }

    // Count set bits in the binary representation of n
    unsigned long long count = __builtin_popcount(n);

    // Calculate the next position multiple of x
    unsigned long long nextPosition = (n / x) * x;

    // If the next position is still within the range and is a multiple of x, recursively count set bits
    if (nextPosition > 0 && nextPosition % x == 0) {
        count += countSetBits(nextPosition, x);
    }

    return count;
}


// Driver code
int main()
{
    int n = 17;
    cin >> n;
    cout << "Total set bit count is " << countSetBits(n);
    return 0;
}
 
// This code is contributed by rathbhupendra

// 5.4717320 = 5 * 10⁷