/*
    GIVEN: N ,ARRAY OF INTEGERS OF SIZE N, KEY
    TO DO: PRINT A PAIR, IF IT HAS SUM EQUAL TO KEY
    EG: 
    IP ->   5
            1 5 4 3 2
            4
    OP ->   1 + 3 = 4
*/

#include<bits/stdc++.h>
using namespace std;
void solve(vector<int>,int,int);
int main(){
    int n,key;
    cin >> n; // NUMBER OF ELEMENTS
    vector<int> arr(n);
    for(auto &i:arr) //INPUT 'n' ELEMENTS
        cin >> i;
    cin >> key;
    sort(arr.begin(),arr.end()); // SORT THE ABOVE ARRAY IN ASCENDING ORDER
    solve(arr,n,key);
}
void solve(vector<int> arr , int n, int key){
    int left = 0 , right = n-1; // INDEX OF FIRST AND LAST ELEMENTS RESP.
    while(left < right){
        int pair_sum = arr[left] + arr[right]; //SUM OF THE SELECTED INDEX
        if(pair_sum == key){
            cout << arr[left] << " + " << arr[right] << " = " << key <<  "\n";
            break;
        }
        else if(pair_sum > key) // IF SUM IS GREATER, WE NEED TO REDUCE THE SUM WHICH IS ONLY POSSIBLE IF WE SHIFT THE RIGHT INDEX
            right--;
        else // SUM IS SMALLER, VICE VERSA
            left++;
    }
}