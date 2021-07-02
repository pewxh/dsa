/*
    GIVEN: A STRING CONSISTING OF ENGLISH LETTERS , DIGITS , SYMBOLS AND SPACES.
    TO DO: PRINT THE SIZE OF MAXIMUM SUBSTRING POSSIBLE WITHOUT DUPLICATION OF ELEMENTS
    SPACE -> O(1)  || TIME -> O(n)
    PROBLEM -> https://leetcode.com/problems/longest-substring-without-repeating-characters/
    Eg:
    INPUT -> 
    aabAbsxnas ihkkh 
    OUTPUT -> 
    8
*/
#include<algorithm>
#include<iostream>
#include<string>
#include<map>
using namespace std;

int lengthOfLongestSubstring(string s){
	int maxLength = 1 , startIndex = 0;
	map<char,int> pos; // stores the last position where the element was encountered.
	for(int i = 0; i < s.size(); i++){
		if(pos[s[i]])
			startIndex = max(startIndex,pos[s[i]]); // if any duplicate element occurs, starting index is re positioned accordingly.
		pos[s[i]] = i+1; // position of the current element is stored/overwritten using 1 based indexing
		maxLength = max(maxLength,i-startIndex+1);
	}
	return maxLength;
}

int main(){
	string s;
	getline(cin,s);
	cout << lengthOfLongestSubstring(s);
	return 0;
}