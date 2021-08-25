/*
    GIVEN: AN INTEGER 'n' DENOTING NUMBER OF MEETINGS THAT ARE SCHEDULED IN A ROOM
           2 ARRAYS OF SIZE 'n' STORING THE START TIME AND END TIME OF EACH MEETING
    TO DO: PRINT THE MAXIMUM NUMBER OF MEETINGS THAT CAN BE ARRANGED IN THAT ROOM
    Eg:
    INPUT ->
    6
    1 3 0 5 8 5 
    2 4 6 7 9 9
    OUTPUT -> 
    4
    REF -> https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1#
*/

#include <bits/stdc++.h>
using namespace std;

bool comparator(vector<int> m1, vector<int> m2)
{
  return m1[1] < m2[1];
}

int maxMeetings(int start[], int end[], int n)
{
  vector<vector<int>> meets(n, vector<int>(2));
  for (int i = 0; i < n; i++)
  {
    meets[i][0] = start[i];
    meets[i][1] = end[i];
  }
  sort(meets.begin(), meets.end(), comparator);
  int count = 1;                  // we can always arrange room for the first meeting
  vector<int> current = meets[0]; // on going meeting
  for (int i = 1; i < n; i++)
  {
    if (meets[i][0] > current[1])
    {
      current = meets[i];
      count++;
    }
  }
  return count;
}
int main()
{
  int n;
  cin >> n; // number of meetings
  int *start = new int[n];
  int *end = new int[n];
  for (int i = 0; i < n; i++)
    cin >> start[i]; //  starting times of the meeting
  for (int i = 0; i < n; i++)
    cin >> end[i]; //  ending times of the meeting
  cout << maxMeetings(start, end, n);
  return 0;
}