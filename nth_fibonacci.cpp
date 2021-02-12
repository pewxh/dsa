/*
    GIVEN: A POSITIVE INTEGER 'n'
    TO DO: FIND THE n-th FIBONACCI NUMBER
    SPACE: O(n) | TIME: O(n)
    Eg: 
    INPUT ->
    19
    OUTPUT -> 
    2584
*/

#include<iostream>
#include<map>
using namespace std;

int fibb(int n,map<int,int> &dp){
    if(!dp[n] && n > 0)
        dp[n] = fibb(n-1,dp) + fibb(n-2,dp);
    return dp[n];
}

int main(){
    int n;
    cin >> n;
    map<int,int> dp;
    dp.insert(make_pair(1,0));
    dp.insert(make_pair(2,1));
    cout << fibb(n,dp) ;
}