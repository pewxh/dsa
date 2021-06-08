/*
    GIVEN: AN ARRAY OF SIZE 'n + 1' 
           1 <= a[i] <= n
    TO DO: 1 NUMBER IS DUPLICATED , FIND THE MISSING NUMBER
    Eg:
    INPUT ->
    5  
    3 1 5 4 3
    OUTPUT -> 
    2 
    REF -> https://leetcode.com/problems/find-the-duplicate-number/
*/

//    >>   FLOYD CYCLE DETECTION METHOD

#include<iostream>
#include<vector>
using namespace std;


int duplicate(vector<int>&arr){
    int slow_p = arr[0] , fast_p = arr[0]; // slow and fast pointer pointing to first element (idx 0)
    while(1){
        slow_p = arr[slow_p]; // slow pointer moves 1 step at a time
        fast_p = arr[arr[fast_p]]; // fast pointer moves 2 steps at a time
        if(slow_p == fast_p){ 
            fast_p = arr[0];
            break;
        } // when both the pointers have same value, assign fast pointer to first element again
    }
    while(fast_p != slow_p){
        fast_p = arr[fast_p]; // fast pointer moves 1 step at a time
        slow_p = arr[slow_p]; // slow pointer moves 1 step at a time
    } // when both the pointers have same value, thats the duplicate element we were looking for
    return slow_p;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(auto &i:arr)
        cin >> i;
    cout << duplicate(arr);
}