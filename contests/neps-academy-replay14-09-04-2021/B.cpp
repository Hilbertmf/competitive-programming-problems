// C++ program to find
// minimum number of prefix reversals
// to sort permutation of first N numbers
// Only works for first set of test cases: N < 6
#include <bits/stdc++.h>
using namespace std;
 
// Function to return the minimum prefix reversals
int minimumPrefixReversals(int arr[], int n)
{
    string start = "";
    string destination = "", t, r;
    for (int i = 0; i < n; i++) {
        // converts the number to a character
        // and add  to string
        start += to_string(arr[i]);
        // printf("converting to string...\n");
    }
    sort(arr, arr + n);
    for (int i = 0; i < n; i++) {
        destination += to_string(arr[i]);
        // printf("converting to string...\n");
    }
 
    // Queue to store the pairs
    // of string and number of reversals
    queue<pair<string, int> > qu;
    pair<string, int> p;
 
    // Initially push the original string
    qu.push(make_pair(start, 0));
    // cout << "log1" << endl;
    // if original string is the destination string
    if (start == destination) {
        // cout << "log2" << endl;
        return 0;
    }
 
    // iterate till queue is empty
    while (!qu.empty()) {
 
        // cout << "log3" << endl;
        // cout << "qu front: " << qu.front().first << " " << qu.front().second << endl;
        // pair at the top
        p = qu.front();
 
        // string
        t = p.first;
        
        // pop the top-most element
        qu.pop();
 
        // perform prefix reversals for all index and push
        // in the queue and check for the minimal
        for (int j = 2; j <= n; j++) {
            // cout << "log4" << endl;
            r = t;

            // reverse the string till prefix j
            reverse(r.begin(), r.begin() + j);
 
            // if after reversing the string from first i index
            // it is the destination
            if (r == destination) {
                // cout << "log5" << endl;
                return p.second + 1;
            }
 
            // push the number of reversals for string r
            qu.push(make_pair(r, p.second + 1));
        }
    }
}
 
// Driver Code
int main()
{
  int length, num_towers, count;
	scanf("%d %d", &length, &num_towers);
  char towers[100010][length];
  int arr[length] = {0};
  for (int i = 0; i < num_towers; i++)
  {
    int n = sizeof(arr) / sizeof(arr[0]);
    count = 0;
    cin >> towers[i];
    for (int j = 0; j < length; j++)
    {
      arr[j] = towers[i][j] - 'A' + 1;
    }
    // printf("\n");
    cout << minimumPrefixReversals(arr, n) << endl;
  }

  return 0;
}