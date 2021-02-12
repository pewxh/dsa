/*  GIVEN: AN ARRAY OF 'n' INTEGERS
    TO DO: PRINT THE MAXIMUM SUBARRAY SUM POSSIBLE
    SPACE -> O(1) | TIME -> O(n)
    EG:
    INPUT  -> 
    16                
    3 5 -9 1 3 -2 3 4 7 2 -9 6 3 1 -5 4
    OUTPUT ->
    19
*/

//-------> KADANE'S ALGORITHM <-------
#include<iostream>
#include<algorithm>
using namespace std;

int maxSubArraySum(int *arr,int n){
    int curr_max = arr[0]; // STORES MAX TILL THE i-th ELEMENT
    int maxx = arr[0]; // MAXIMUM OVERALL
    for(int i=1;i<n;i++){
        curr_max = max(curr_max + arr[i] , arr[i]); // MAX TILL i-th INDEX
        maxx = max(maxx,curr_max);
    }
    return maxx;
}

int main(){
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i=0;i<n;i++)
        cin >> arr[i];
    cout << maxSubArraySum(arr,n);
}