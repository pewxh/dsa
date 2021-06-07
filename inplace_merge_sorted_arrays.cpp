/*  GIVEN: 2 INDIVIDUAL SORTED ARRAYS OF SIZE 'n' AND 'm'
    TO DO: MERGE AND SORT BOTH ARRAYS TOGETHER IN CONSTANT SPACE
           a1[0] SHOULD CONTAIN THE MINIMUM NUMBER WHEREAS a2[m-1] SHOULD CONTAIN THE MAXIMUM
    SPACE -> O(1) | TIME -> O(n * m)
    EG:
    INPUT  -> 
    3 5
    1 2 9 -> { a1 }
    1 2 4 4 8 -> { a2 }
    OUTPUT ->
    1 1 2 -> { a1 }
    2 4 4 8 9 -> { a2 }
*/
#include<iostream>
#include<algorithm>
using namespace std;

void sortArray(int *a1,int *a2,int n,int m){
    for(int i = 0 ; i < min(n,m) ; i++){
        if(a1[i] > a2[0]){
            // swap the numbers.
            int t = a1[i]; // temp
            a1[i] = a2[0];

            // sort the second array
            // NOTE: SINCE THE ARRAY IS ALREADY SORTED WE JUST NEED TO PUT 't' IN ITS CORRECT PLACE REST
            int j = 1;
            while(j < m and t > a2[j]){
                a2[j-1] = a2[j];
                j++;
            }
            a2[j-1] = t;
        }
    }
}

int main(){
    int n , m;
    cin >> n >> m;
    int *a1 = new int[n] , *a2 = new int[m];
    for(int i=0;i<n;i++)
        cin >> a1[i];
    for(int i=0;i<m;i++)
        cin >> a2[i];
    sortArray(a1,a2,n,m);
    for(int i=0;i<n;i++)
        cout << a1[i] << " ";
    cout << "\n";
    for(int i=0;i<m;i++)
        cout << a2[i] << " ";
    delete a1;
    delete a2;
    return 0;
}
