/*
    GIVEN: A STRING 's' AND ANOTHER STRING 'p' OF LENGTH 'n' AND 'm' RESPECTIVELY.
    TO DO: CHECK WHETHER THE PATTERN 'p' IS PRESENT INSIDE THE MAIN STRING 's'.
    SPACE -> O(m) || TIME -> O(n+m)
    Eg:
    INPUT ->
    asdasafasdsdadafa
    asdsda
    OUTPUT -> 
    true
*/

//    >>   PATTERN MATCHING USING KMP

#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<int> patternBuilder(string p){
  vector<int> pi(p.size(),-1);
  int i = 1 , j = 0;
  while(i < p.size()){
    if(pi[i] == pi[j]){
      pi[i] = j;
      i++;
      j++;
    }
    else if(j)
      j = pi[j-1] + 1;
    else
      i++;
  }
  return pi;
}

bool patternMatch(string s,string p){
  vector<int> pi = patternBuilder(p);
  int i = 0 , j = 0;
  while(i + p.size() - j <= s.size()){
    if(s[i] == p[j] ){
      if (j == pi.size()-1)
        return true;
    i++; j++;
    }
    else if(j)
      j = pi[j-1] + 1;
    else
      i++;
  }
  return false;
}

int main(){
  string s,p;
  cin >> s >> p;
  cout << patternMatch(s,p);
}