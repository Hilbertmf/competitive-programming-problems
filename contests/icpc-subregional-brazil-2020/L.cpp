#include <iostream> 
#include <bits/stdc++.h>
 
using namespace std;

void normalize(int table[40][40], int rows, int cols) {
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if(table[i][j] > 0)
				table[i][j] = 1;
		}
	}
}

void merge(int table[40][40], int wordTable[40][40], int rows, int cols) {
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
		 table[i][j] += wordTable[i][j];
		}
	}
}

bool isAnagram(string word1, string word2) {
	int length = word1.size();
	if(word1.size() != word2.size())
		return false;

	int asciiTable1[256] = {0};
	int asciiTable2[256] = {0};
	for (int i = 0; i < length; i++) {
		asciiTable1[word1[i]]++;
		asciiTable2[word2[i]]++;
	}

	for (int i = 0; i < 256; i++)
	{
		if (asciiTable1[i] != asciiTable2[i])
			return false;
	}
	return true;
}

void init(int table[40][40], int rows, int cols, int value) {
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			table[i][j] = value;
	}
}

void checkRows(string word, string words[], int noWords, int table[40][40]) {
	
	int rows = noWords;
	int cols = words[0].size();
	
	for (int i = 0; i < rows; i++) {
		string anagram;
		int horizontalWindow = 0;
		int noAnagrams = 0;
		for (int j = 0; j < cols && horizontalWindow + word.size() <= cols + 1; j++) {
			anagram += words[i][j];
			if(anagram.size() == word.size()) {
				if(isAnagram(word, anagram)) {
					int anagramLength = anagram.size();
					for (int k = j - (anagramLength - 1); k <= j; k++)
							table[i][k]++;
					j = horizontalWindow;
					horizontalWindow++;
					noAnagrams++;
				}
				else {
					j = horizontalWindow;
					horizontalWindow++;
				}
				// empty anagram
				anagram = "";
			}
		}	
	}
}

void checkCols(string word, string words[], int noWords, int table[40][40]) {
	
	int rows = noWords;
	int cols = words[0].size();

	for (int i = 0; i < cols; i++)
	{
		string anagram;	
		int verticalWindow = 0;
		int noAnagrams = 0;
		for (int j = 0; j < rows && verticalWindow + word.size() <= rows + 1; j++)
		{
			anagram += words[j][i]; // append to anagram
			
			if (anagram.size() == word.size()) { // we check if its an anagram
				if(isAnagram(word, anagram)) {
					int anagramLength = anagram.size();

					for (int k = j - (anagramLength - 1); k <= j; k++)
						table[k][i]++;

					j = verticalWindow;
					verticalWindow++;
					noAnagrams++;		
				}
				else {
					j = verticalWindow;
					verticalWindow++;
				}
				// empty anagram
				anagram = "";
			}
		}
	}	
}

void traverseDiagonal(string word, string words[], int table[40][40], int x, int y, int rows, int cols, string sideString) {
	string anagram;
	int diagonalWindow = 0;
	int noAnagrams = 0;
	int side;

	if (sideString == "right") {
		side = 1;
		for (int i = x, j = y;
			i < rows && j < cols;
			i += 1*side, j += 1*side)
		{
			anagram += words[i][j];

			if(anagram.size() == word.size()) {
				if(isAnagram(word, anagram)) {
					
					int anagramLength = anagram.size();
					
					for (int w = i - (anagramLength - 1), k = j - (anagramLength - 1);
							w <= i && k <= j;
							w++, k++) {
							table[w][k]++;
						}
					j = diagonalWindow;
					i = diagonalWindow;
					diagonalWindow++;
					noAnagrams++;
				}
				else {
					j = diagonalWindow;
					i = diagonalWindow;
					diagonalWindow++;
				}
				// empty anagram
				anagram = "";
			}
		}
	}
	else if (sideString == "left") {
		side = -1;

		for (int i = x, j = y;
			i < rows && j >= 0;
			i++ , j--)
		{
			anagram += words[i][j];

			if(anagram.size() == word.size()) {
				if(isAnagram(word, anagram)) {
					
					// cout << "is anagram!" << endl;
					int anagramLength = anagram.size();
					
					for (int w = i - (anagramLength - 1), k = j + (anagramLength - 1);
							w <= i && k >= j;
							w++, k--) {
							table[w][k]++;
						}
					j = diagonalWindow;
					i = diagonalWindow;
					diagonalWindow++;
					noAnagrams++;
				}
				else {
					j = diagonalWindow;
					i = diagonalWindow;
					diagonalWindow++;
				}
				// empty anagram
				anagram = "";
			}
		}
	}
	return;
}

void checkDiagonals(string word, string words[], int noWords, int table[40][40]) {
	int rows = noWords;
	int cols = words[0].size();
	
	for (int i = 0; i < rows; i++) {
		string anagram;
		int diagonalWindow = 0;
		int noAnagrams = 0;
		for (int j = 0; j < cols; j++) {
			if(word.find(words[i][j]) != string::npos) { // if current char is inside word
				traverseDiagonal(word, words, table, i, j, rows, cols, "right");
				traverseDiagonal(word, words, table, i, j, rows, cols, "left");
			}
		}
	}
}

int getSpecialCells(int table[40][40]) {
	int res = 0;

	for (int i = 0; i < 40; i++)
	{
		for (int j = 0; j < 40; j++)
		{
			if(table[i][j] > 1)
				res++;
		}	
	}
	return res;
}

int main() 
{

	int rows, cols, noSpecialCells;
	
	cin >> rows >> cols;
	
	string words[rows];
	for (int i = 0; i < rows; i++)
	{
		cin >> words[i];
	}
	int noWordsInCollection;
	cin >> noWordsInCollection;
	string wordsInCol[noWordsInCollection];
	for (int i = 0; i < noWordsInCollection; i++)
	{
		cin >> wordsInCol[i];
	}

	int table[40][40];
	init(table, rows, cols, 0);

	for (int i = 0; i < noWordsInCollection; i++) {
		int wordTable[40][40];
		
		init(wordTable, rows, cols, 0);
		checkRows(wordsInCol[i], words, rows, wordTable);
		checkCols(wordsInCol[i], words, rows, wordTable);
		checkDiagonals(wordsInCol[i], words, rows, wordTable);
		normalize(wordTable, rows, cols);
		merge(table, wordTable, rows, cols);
	}

	cout << getSpecialCells(table) << endl;


	return 0; 
}
