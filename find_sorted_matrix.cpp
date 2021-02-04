/*
    GIVEN: A SORTED 2-D MATRIX(n X m) AND A KEY
    NOTE: SORTED -> ALL ELEMENTS IN A PARTICULAR ROW/COLUMN ARE SORTED
    TO DO: FIND LOCATION OF THE KEY (if present, else [-1 , -1])
    SPACE -> O(1)  || TIME -> O(n+m)
    Eg:
    INPUT -> 
    4 4
    1  2  3  4  
    5  6  7  9 
    8  10 12 13 
    14 15 16 17 
    5
    OUTPUT -> 
    [ 1 , 0]
*/

#include<iostream>
#include<vector>
using namespace std;

pair<int,int> findKey(vector<vector<int>>arr,int key){
    int rw = 0 , cl = (arr[0].size() - 1); // rw = 0 AND cl = m-1
    while(rw < arr.size() && cl > -1){
        if(arr[rw][cl] == key) 
            return make_pair(rw,cl); // KEY FOUND, RETURN [rw,cl]
        else if(arr[rw][cl] < key)
            rw++; 
        else 
            cl--;
    }
    return make_pair(-1,-1); // KEY NOT FOUND, RETURN [-1,-1]
}

int main(){
    int n , m , key;
    cin >> n >> m ; // INPUT NUMBER OF ROWS AND COLUMNS RESPT.
    vector< vector<int> > arr(n,vector<int>(m)); // 2D VECTOR OF n ROWS AND m COLUMNS
    for(auto &i:arr) // FOR EACH ROW (CALL BY REFERENCE)
        for(auto &j:i) // FOR EACH ELEMENT OF A ROW (CALL BY REFERENCE)
            cin >> j; // ANY CHANGE IN j IS AUTOMATICALLY REFLECTED BACK TO i[j] (where, i = arr[0:n])
    cin >> key; // INPUT KEY TO BE SEARCHED
    pair<int,int> res = findKey(arr,key); 
    cout << "[ " << res.first << " , " << res.second << " ]";  
    return 0;
}