#include<bits/stdc++.h>

using namespace std;

void TPM(vector<vector<bool>> &arr, vector<vector<bool>> &visited, string s, vector<string> &ans, int i, int j,int di[], int dj[]) {

    int N = arr.size();

 

    if (i == N - 1 && j == N - 1) {

        ans.push_back(s);

        return;

    }

    string dir = "DLRU";

 

      for (int ind = 0; ind < 4; ind++) {

      int nexti = i + di[ind];

      int nextj = j + dj[ind];

      if (nexti >= 0 && nextj >= 0 && nexti < N && nextj < N && !visited[nexti][nextj] && arr[nexti][nextj] == 1) {

        visited[i][j] = 1;

        TPM(arr,visited,s + dir[ind],ans, nexti, nextj,di, dj);

        visited[i][j] = 0;

      }

    }

}

 

vector<string> findAllPaths(vector<vector<bool>> &arr) {

    int N = arr.size();

    vector<string> ans;

    string s;

    if (arr[0][0] == false || arr[N-1][N-1] == false) return ans;

    vector<vector<bool>> visited(N, vector<bool>(N, false));

     int di[] = {+1,0,0,-1};

     int dj[] = {0,-1,1,0};

    TPM(arr, visited, s, ans, 0, 0,di,dj);

    return ans;

}

 