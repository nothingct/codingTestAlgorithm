#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
int N,M;
bool visited[100][100];

int dx[] ={-1,0,1,0};
int dy[] ={0,-1,0,1};
//x 가 m(행) y가 n(열)
int dfs(const vector<vector<int>> & picture,int x,int y, int color){
    visited[x][y]= true;
    int cnt=1; 
    for(int i=0; i<4; i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(nx<0||ny<0||nx>=M||ny>=N||visited[nx][ny]) continue;
        if(picture[nx][ny]!=color) continue;
        
        cnt+=dfs(picture,nx,ny,color);
    }
    return cnt;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    //초기화 코드 
    M=m,N=n;
    memset(visited,false,sizeof(visited));
    //구하고자 하는 대상
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(!visited[i][j] && picture[i][j]!=0){
                number_of_area+=1;
                max_size_of_one_area = max(max_size_of_one_area,dfs(picture,i,j,picture[i][j]));
            }
        }
    }
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}