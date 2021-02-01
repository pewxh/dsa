/*
    GIVEN: 2 ARRAYS OF SIZE 'n' AND 'm'
    TO DO: FORM A PAIR USING BOTH THE ARRAYS SUCH THAT THEIR DIFFERENCE IS MINIMUM
    Eg:
    INPUT ->
    5 6 
    12 4 6 7 9
    1 2 34 5 3 1
    OUTPUT -> 
    4 , 3
*/

#include<iostream>
#include<algorithm>
//#include<utility> // (OPTIONAL) std::pair
using namespace std;

pair<int,int> minDiff(int *arr1,int *arr2,int n,int m){
    int i = 0, j = 0; // i AND j ARE INDEX POINTERS FOR arr1 AND arr2 RESP.
    int min_d = INT_MAX; // TO STORE THE MINIMUM DIFFERENCE
    pair<int,int> res; // RESULT PAIR
    while(i < n && j < m){
        if(arr1[i] == arr2[j])
            return make_pair(arr1[i],arr2[j]); // DIFFERENCE WILL BE ZERO, BEST POSSIBLE RESULT
        int curr_d = abs(arr1[i] - arr2[j]); // DIFFERENCE OF THE CURRENT PAIR
        if(curr_d < min_d){
            min_d = curr_d; //NEW UPDATED MIN DIFFERENCE
            res = make_pair(arr1[i],arr2[j]); // MINIMUM PAIR  
        }
        if(arr1[i] < arr2[j])
            i += 1; // UPDATE INDEX POINTER OF FIRST ARRAY
        else 
            j += 1; // UPDATE INDEX POINTER OF SECOND ARRAY
    }
    return res;
}


int main(){
    int n , m;
    cin >> n >> m; //SIZE OF ARRAY 1 AND ARRAY 2 RESPCT.
    int *arr1 = new int[n], *arr2 = new int[m];
    for(int i=0;i<n;i++)
        cin >> arr1[i]; //INPUT FIRST ARRAY
    for(int i=0;i<m;i++)
        cin >> arr2[i]; // INPUT SECOND ARRAY 
    sort(arr1,arr1 + n); // SORT FIRST ARRAY
    sort(arr2,arr2+m); // SORT SECOND ARRAY
    pair<int,int> res = minDiff(arr1,arr2,n,m);
    cout << res.first << " , " << res.second;
}
