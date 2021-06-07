/*
    GIVEN: AN ARRAY OF SIZE 'n'
    NOTE: ARRAY CAN HAVE ONLY 3 DISTINCT VALUES (0,1,2)
    TO DO: SEGREGATE ALL THE NUMBERS TOGETHER , HERE SORT IN ASSCENDING
    SPACE -> O(1)  || TIME -> O(n)
    Eg:
    INPUT -> 
    6
    [ 1 , 1 , 2 , 1 , 0 , 0]
    OUTPUT -> 
    [ 0 , 0 , 1 , 1 , 1 , 2]
*/

#include<iostream>
using namespace std;

void swap(int arr[],int x , int y){
    int t = arr[x];
    arr[x] = arr[y];
    arr[y] = t;
}

void dfa(int arr[],int n){
    int first = 0 , second = 1 , third = 2; // Order to segregate . i.e [ 0..., 0 , 1 ... , 1 , 2 ,... , 2]
    int low = 0 , high = n - 1;
    int p = low;
    while(p <= high){
        if(arr[p] == first){
            swap(arr,low,p);
            low++; p++;
        }
        else if(arr[p] == second){
            p++;
        }
        else{                                                   // arr[p] == third.
            swap(arr,p,high);
            high--;
        }
    }
}

int main(){
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i = 0;i < n;i++)
        cin >> arr[i];
    dfa(arr,n);
    cout << "After DFA \n";
    for(int i=0;i<n;i++)
        cout << arr[i] << " ";
    delete arr;
    return 0;
}