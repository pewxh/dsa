/*  GIVEN: AN ARRAY OF INTERVALS (2D ARRAY / LIST OF LISTS / VECTOR OF VECTORS / VECTOR OF PAIR etc DATASTRUCTURE CAN BE USED)
    TO DO: MERGE ALL THE OVERLAPING INTERVALS
    SPACE -> O(n) | TIME -> O(log n) {sort} + O(n) { travel }
    EG:
    INPUT  -> 
    4
    1 3
    2 6
    8 10
    15 18
    OUTPUT ->
    1 6
    8 10
    15 18
    REF -> 
*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>arr){
    vector<vector<int>> res;
    sort(arr.begin(),arr.end()); // sort the intervals
    auto temp = arr[0];
    for(int i=0;i<arr.size();i++){
        if(temp[1] >= arr[i][0]){
            temp[1] = max(temp[1],arr[i][1]);
        }
        else{
            res.push_back(temp);
            temp = arr[i];
        }
    } 
    res.push_back(temp);
    return res;
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> arr(n);
    for(auto &ivl:arr){
        int x , y;
        cin >> x >> y;
        ivl.push_back(x);
        ivl.push_back(y);
    }
    arr = merge(arr);
    for(auto &i:arr)
        cout << i[0] << " " << i[1] << "\n";
    arr.clear();
    return 0;
}