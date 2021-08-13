/*
    GIVEN: AN ARRAY OF SIZE 'n' 
    TO DO: FIND THE LENGTH OF MAXIMUM SUBARRAY THAT SUMS UP TO ZERO
    Eg:
    INPUT ->
    5
    -9 9 0 3 3
    OUTPUT -> 
    3
    REF -> https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1
*/

#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

int maxLen(int A[], int n){
    map<int,int> mp; // stores the last index of prefix sums
    int presum = 0; // stores prefix sum till ith index
    int res = 0;
    mp.insert({0,-1}); // no elements included( sum of elements till -1rst index ) can also sum up to zero
    for(int i = 0 ; i < n ; i++){
        presum += A[i];
        if(mp.find(presum) == mp.end()) 
            mp.insert({presum,i});
        else 
            res = max(res,i - mp[presum]);
    } 
    return res;
}
int main(){
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << maxLen(arr, n);
    return 0;
}
