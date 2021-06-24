#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

const int MAX =51;
int n;
char board[MAX][MAX];
int ans; 

void findMax(){
//가로(열) 부터 시작 
  for(int i=1; i<=n; i++){
    int cnt =1;
    for(int j=1; j<=n-1 ;j++){
      if(board[i][j] == board[i][j+1]) cnt++;
      else cnt = 1; 
      ans = max(ans,cnt);
    }
  }
  //세로(행) 부터 시작
  for (int i = 1; i <= n; i++)
  {
    int cnt = 1;
    for (int j = 1; j <= n - 1; j++)
    {
      if (board[j][i] == board[j+1][i])
        cnt++;
      else
        cnt = 1;
      ans = max(ans, cnt);
    }
  }
}

void solve(){
  // 열(col) swap 후 count 해보기
  for(int i=1; i<=n; i++){
    for(int j=1; j<=n-1; j++){
      swap(board[i][j], board[i][j+1]);
      findMax();
      swap(board[i][j], board[i][j + 1]);
    }
  }
  // 행(row) swap후 count 해보기
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n - 1; j++)
    {
      swap(board[j][i], board[j+1][i]);
      findMax();
      swap(board[j][i], board[j+1][i]);
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); 

  cin>>n;
  for(int i=1; i<=n; i++){
    string s;
    cin>>s;
    for(int j=1; j<=n; j++){
      board[i][j] = s[j-1];
    }
  }
  solve();
  cout<<ans; 
  return 0;
}