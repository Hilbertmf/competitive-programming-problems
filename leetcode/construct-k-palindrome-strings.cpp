bool canConstructKPalidromes(int k, string word) {
  int length = word.size();
  
  int wordMap['z'-'a'] = {0};
  
  for(int i=0; i < length; i++) {
    int currCharIdx = word[i] - 'a';
    wordMap[currCharIdx]++;
  }

// chars which appears an odd number of times
  int charsOddTimes = 0;

  for(int i=0; i < 26; i++) {
    if(wordMap[i] % 2 != 0)
      charsOddTimes++;
  }

  if(charsOddTimes > k)
    return false;
  
  return true;
  
}
