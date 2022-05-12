// https://neps.academy/br/competition/1034
#include <bits/stdc++.h> 
using namespace std; 
#define INF (int)1e9 
#define LONGINF (long)1e18 
#define MEM(arr, val) memset(arr, (val), sizeof(arr)) 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
const int MOD = 1000000007; // 10^9 - 7 
void initArray(int arr[], int length, int val) { 
	for (int i = 0; i < length; i++) 
		arr[i] = val; 
	return; 
} 

class Friend {
    public:
		int num;
		int startTime;
		int endTime;
		int totalTime;

		Friend(int num) {
			this->num = num;
			startTime = -1;
			endTime = -1;
			totalTime = 0;
		}
		void receiveMsg(int time) {
			startTime = time;
			endTime = -1;
		}

		void sentMsg(int time) {
			endTime = time;
			totalTime += abs(endTime - startTime);
		}
};

bool containsFriend(vector<Friend>& friends, Friend f) {
	for (auto it = friends.begin(); it != friends.end(); it++)
		if(it->num == f.num)
			return true;
	
	return false;
}

int findFriend(vector<Friend>& friends, int numFriend) {
	int i = 0;
	for (auto it = friends.begin(); it != friends.end(); it++, i++)
		if(it->num == numFriend)
			return i;
	
	return -1;
}

bool compare(const Friend& f1, const Friend& f2) {
	return f1.num < f2.num;
}

int main() { 
	fastio; 
	// ifstream cin("in.txt"); 
	// ofstream cout("out.txt"); // cout to file 
	//freopen("out.txt","w",stdout); // use this one for printf to file 

	int numLines; 
	cin >> numLines;
	int time = 0;
	vector <pair<char, int>> lines;
	vector<Friend> friends;

	for(int i = 0; i < numLines; i++) { 
		char c;
		int num;
		cin >> c >> num;
		lines.push_back(make_pair(c, num));
		if(c != 'W') {
			Friend f = Friend(num);
			// check if contains and add
			if(!containsFriend(friends, f)) { // if does not contain
				friends.push_back(f);
			}
		}
	}

	int linesLength = lines.size();

	for (int i = 0; i < linesLength; i++)
	{
		// find curr friend position and run receivemsg
		int currFriend = lines[i].second;
		int currFriendPos = findFriend(friends, currFriend);
		
		if(lines[i].first == 'R' && currFriendPos >= 0) 
			friends[currFriendPos].receiveMsg(time);
		if(lines[i].first == 'S' && currFriendPos >= 0) 
			friends[currFriendPos].sentMsg(time);
		if(i < linesLength - 1 && lines[i+1].first == 'W') {
			time += lines[i+1].second;
			i++;
		}
		else {
			time++;
		}
	}
	
	// sort friends:
	sort(friends.begin(), friends.end(), &compare);
	
	for (auto it = friends.begin(); it != friends.end(); it++)
	{
		if(it->endTime == -1)
			it->totalTime = -1;
		// num friend and its time
		cout << it->num << " " << it->totalTime << endl;
	}

	return 0; 
}
