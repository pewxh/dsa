/*
    GIVEN: TWO INTEGERS 'x' AND 'y'
    TO DO: FIND x RAISED TO y POWER.
    SPACE -> O(logn)  || TIME -> O(logn)
    Eg:
    INPUT -> 
    2 4
    OUTPUT -> 
    16
*/

#include<iostream>
using namespace std;

int POW(int x,int y){
    if(y == 0)
        return 1;
    if(y == 1)
        return x;
    int x_raised_to_y_by_2 = POW(x,y/2);
    if(y % 2)
        return x_raised_to_y_by_2 * x_raised_to_y_by_2 * x; 
    return x_raised_to_y_by_2 * x_raised_to_y_by_2; 
}

int main(){
    int x,y;
    cin >> x >> y;
    cout << POW(x,y);
    return 0;
}