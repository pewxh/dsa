/*
    GIVEN: AN INTEGER 'n' DENOTING NUMBER OF ROWS IN THE PASCAL TRIANGLE
    TO DO: GENERATE A PASCAL TRIANGLE
    SPACE -> O(n^2)  || TIME -> O(n^2)
    Eg:
    INPUT -> 
    5
    OUTPUT -> 
    1
    1,1
    1,2,1
    1,3,3,1
    1,4,6,4,1
    REF -> https://leetcode.com/problems/pascals-triangle/
*/

#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> pascal(int n){
    vector<vector<int>> res;

    for(int i=1;i<=n;i++){
        vector<int> row(i);
        row[0] = row[i-1] = 1;
        res.push_back(row);
    } // WRITE THE CORNER ELEMENTS (1) IN THE MATRIX 

    for(int i=2;i<n;i++){
        for(int j=1;j<i;j++)
            res[i][j] = res[i-1][j-1] + res[i-1][j];
    }
    return res;
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> res = pascal(n);
    for(auto i:res){
        for(auto j:i)
            cout << j << " ";
        cout << "\n";
    }
    return 0;
}