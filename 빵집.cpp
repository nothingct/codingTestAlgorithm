#include <iostream>
#include <string>
using namespace std;

const int MAX_ROW=10000;
const int MAX_COL=500;
int dx[]={-1,0,1};
int dy[]={1,1,1};

int R,C;
string graph[MAX_ROW];
bool visited[MAX_ROW][MAX_COL];

bool dfs(int x, int y){
  //방문 기록 체크 
  visited[x][y] = true;
  //종료조건 : 마지막 열 C-1 에 도달하였는지 확인 
  if(y==C-1) return true;
  //아니라면 탐색을 시작: 우상단, 오른쪽, 우하단
  for(int i=0; i<3; i++){
    int nx= x+dx[i];
    int ny= y+dy[i];
    //탐색 가능 여부 확인 
    if(0>nx ||  R<=nx || 0>ny || C<=ny) continue;
    if( visited[nx][ny]) continue;
    if(graph[nx][ny] == 'X') continue;
    return dfs(nx,ny);
  }
  return false;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin>>R>>C;

  for(int i=0; i<R; i++)
    cin>>graph[i];
  
  int ans = 0; 
  for(int i=0; i<R; i++){
    if(dfs(i,0)) ans+=1;
  }
  cout<<ans<<'\n';
  return 0;
}