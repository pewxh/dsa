/*
    GIVEN: AN ARRAY OF 'n' POSITIVE INTEGERS
    TO DO: PRINT THE MAXIMUM SUM OF SUB-SETS WITH NO ELEMENTS ADJACENT TO EACH OTHER
    Eg:
    INPUT ->
    5 
    12 4 6 7 9
    OUTPUT -> 

*/

#include<iostream>
#include<algorithm>
using namespace std;

int maxSum(int* , int);
int main(){
    int n;
    cin >> n; // INPUT NUMBER OF ELEMENTS
    int *arr = new int[n]; 
    for(int i = 0 ; i < n ; i++)
        cin >> arr[i]; //INPUT ELEMENTS
    cout << maxSum(arr,n);
    delete [] arr;
}
int maxSum(int* arr,int n){
    int mx = max(arr[0],arr[1]); // STORES THE MAX SUM FOR ARR[0:i]
    int smx = arr[0]; // STORES THE MAX SUM FOR ARR[0:i-1]
    for(int i=2;i<n;i++){
        int mx_current = max(mx,smx+arr[i]);// MAXIMUM VALUE, INCLUDING arr[i]
        smx = mx;
        mx = mx_current;
    }
    return mx;
}