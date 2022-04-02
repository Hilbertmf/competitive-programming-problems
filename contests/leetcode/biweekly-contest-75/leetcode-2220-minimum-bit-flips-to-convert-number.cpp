class Solution {
public:
  string toBinary(int num) {
    string binary;
    int pos = 1;
    while(num/pos >= 1) {
      int digit = (num/pos) % 2;
      binary += digit + '0';
      pos *= 2;
    }
    reverse(binary.begin(), binary.end());
    return binary;
  }
	
  int minBitFlips(int start, int goal) {
    string binary = toBinary(start^goal);

    int count = 0;
    for(char &c : binary) {
      if(c == '1') count++;
    }
    return count;
  }
};