/*
    GIVEN: AN ARRAY OF SIZE 'n' 
           1 <= a[i] <= n
    TO DO: 1 NUMBER IS 'MISSING' AND 1 NUMBER IS DUPLICATED , FIND BOTH OF THEM
    Eg:
    INPUT ->
    5  
    3 1 5 4 3
    OUTPUT -> 
    2 , 3 { 2 IS MISSING , 3 IS REPEATED TWICE }
    REF -> https://www.geeksforgeeks.org/find-a-repeating-and-a-missing-number
*/

#include<iostream>
#include<vector>
using namespace std;

pair<int,int> solve(int *arr,int n){
    int x = 0 , y = 0; // one of them is the missing number and other is the repeating number.
    int x_xor_y; // x_xor_y = {arr[0] ^ arr[1] ^ ... } ^ { 1 ^ 2 ^ 3 ^ 4 } = x ^ y
    
    x_xor_y = arr[0];
    for(int i = 1; i < n ; i++)
        x_xor_y ^= arr[i]; // x_xor_y = arr[0] ^ arr[1] ^ arr[2] .... ^ arr[n-1]
    for(int i=1;i <= n ; i++)
        x_xor_y ^= i; //  x_xor_y = x_xor_y ^ { 1 ^ 2 ^ 3 ^ 4 ... ^ n}
    
    int set_bit_helper; // stores binary number containing x_xor_y's rightmost set bit as 1
    set_bit_helper = x_xor_y & ~(x_xor_y - 1); // (x^y) bitwise and (2's Complement (x^y))

    // for simplicity , I'm using vector to divide and store numbers. which uses extra space.

    vector<int> set_bucket , unset_bucket;
    // set_bucket is used to store numbers containing SAME set bit as that of (x^y)'s rightmost set bit. and vice versa

    for(int i = 1 ; i <= n ; i++){

        if(arr[i-1] & set_bit_helper)
            set_bucket.push_back(arr[i-1]);
        else
            unset_bucket.push_back(arr[i-1]);

        if(i & set_bit_helper)
            set_bucket.push_back(i);
        else 
            unset_bucket.push_back(i);

    }

    for(auto &i:set_bucket)
        x ^= i;
    
    for(auto &i:unset_bucket)
        y ^= i;
    
    return make_pair(x,y);
}

int main(){
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i=0;i<n;i++)
        cin >> arr[i];
    pair<int,int> res = solve(arr,n);
    
    for(int i=0;i<n;i++){
        if(arr[i] == res.second){
            cout << res.first << " " << res.second;
            break;
        }
        if(arr[i] == res.first){
            cout << res.second << " " << res.first;
            break;
        }
    } // prints missing number followed by the duplicate number.
    return 0;
}
