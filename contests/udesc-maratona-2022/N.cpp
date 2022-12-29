// wrong answer
#include <bits/stdc++.h> 
using namespace std; 
#define DEBUG(x) cout << #x << " >>>> " << x << endl 
#define MID(l, r) (l + (r - l) / 2) 
#define CEILDIVISION(x, y) ((x + y - 1) / y) 
#define INF (long long)1e9 
#define LONGINF (long long)1e18 
#define MEM(arr, val) memset(arr, (val), sizeof(arr)) 
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
const long long MOD = 1000000007; // 10^9 - 7 


long long knapSack(long long numItems, long long capacity, vector<long long>& weight,
vector<long long>& value) {
    long long result, includeIth, excludeIth, currWeight, currValue;
    long long cache[numItems+1][capacity+1];
    // initialize cache
    memset(cache, 0, sizeof(cache));

    if(weight.size() == 0) return 0;

    for(long long i = 0; i <= numItems; i++) {
        for(long long w = 0; w <= capacity; w++) {
            if(i == 0)
                cache[i][w] = 0;
            else {
                currWeight = weight[i-1];
                currValue = value[i-1];
            }
            // base cases
            if (i == 0 || w == 0)
                cache[i][w] = 0;
            // if it weighs more than capacity we cannot use the item
            else if (currWeight > w)
                cache[i][w] = cache[i-1][w];
            else {
                includeIth = currValue + cache[i-1][w - currWeight];
                excludeIth = cache[i-1][w];
                cache[i][w] = max(includeIth, excludeIth);
            }
        }
    }

    result = cache[numItems][capacity];
    return result;
}

int main() { 
    FASTIO;
    long long numContainers, numGoods, weightShip;
    cin >> numContainers >> numGoods >> weightShip;

    vector<long long> goodWeight(numGoods);
    vector<long long> goodVal(numGoods);
    vector<long long> goodLabel(numGoods);
    vector<long long> containers(numContainers+1);
    for(long long i = 0; i < numContainers; ++i) cin >> containers[i];

    vector<vector<long long>> goodsValForeachContainer(numContainers + 1);
    vector<vector<long long>> goodsWeightForeachContainer(numContainers + 1);

    for(long long i = 0; i < numGoods; ++i) {
        cin >> goodWeight[i] >> goodVal[i] >> goodLabel[i];
        goodLabel[i]--;
        goodsValForeachContainer[goodLabel[i]].push_back(goodVal[i]);
        goodsWeightForeachContainer[goodLabel[i]].push_back(goodWeight[i]);
    }

    vector<long long> optimalContainers(numContainers);
    
    for(long long i = 0; i < numContainers; ++i) {
        long long optimalVal = knapSack(goodsValForeachContainer.size(), containers[i],
        goodsWeightForeachContainer[i], goodsValForeachContainer[i]);
        optimalContainers[i] = optimalVal;
    }
    
    cout << knapSack(numContainers, weightShip, containers, optimalContainers) << "\n";
    return 0; 
}
