/*
    GIVEN: 2 ARRAYS(or strings) OF SIZE 'n' AND 'm'
    TO DO: PRINT THE LONGEST COMMON SUBSEQUENCE 
    Eg:
    INPUT ->
    5 6
    1 2 3 4 1
    3 4 1 2 1 3
    OUTPUT -> 
    1 2 3
    REF -> https://www.hackerrank.com/challenges/dynamic-programming-classics-the-longest-common-subsequence/problem
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> lcsTable(vector<int> a, vector<int> b, int n, int m)
{
  vector<vector<int>> table(n + 1, vector<int>(m + 1, 0));
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      if (a[i - 1] == b[j - 1])
        table[i][j] = 1 + table[i - 1][j - 1];
      else
        table[i][j] = max(table[i - 1][j], table[i][j - 1]);
    }
  }
  return table;
}

vector<int> longestCommonSubsequence(vector<int> a, vector<int> b)
{
  vector<int> lcs;
  int n = a.size(), m = b.size();
  auto table = lcsTable(a, b, n, m);
  int i = n, j = m;
  while (i and j)
  {
    if (a[i - 1] == b[j - 1])
    {
      lcs.push_back(a[i - 1]);
      i--;
      j--;
    }
    else
    {
      if (table[i - 1][j] > table[i][j - 1])
        i--;
      else
        j--;
    }
  }
  reverse(lcs.begin(), lcs.end());
  return lcs;
}

int main()
{
  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(m);
  for (auto &i : a)
    cin >> i;
  for (auto &i : b)
    cin >> i;
  vector<int> lcs = longestCommonSubsequence(a, b);
  for (auto i : lcs)
    cout << i << " ";
}