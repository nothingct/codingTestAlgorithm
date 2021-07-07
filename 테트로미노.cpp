#include <iostream>
using namespace std;

int const MAX = 500;
int paper[MAX][MAX];
// (0,0)을 기준점으로, 상대 위치 3지점을 저장
// 회전 과 대칭을 포함하여 5가지의 도형으로 나타낼 수 있는 모든 경우의 수 19가지
// 왜 19 가지?? 직접 그려보면서 확인해야만 알 수 있다. 공식 이 X
// 좌표 [0] :행(x) 좌표 [1] : 열[y]
int polanomino[19][3][2]{
    // 일 자 도형
    {{0, 1}, {0, 2}, {0, 3}},
    {{1, 0}, {2, 0}, {3, 0}},
    // ㄴ자 도형
    {{1, 0}, {1, 1}, {1, 2}},
    {{0, 1}, {1, 0}, {2, 0}},
    {{0, 1}, {0, 2}, {1, 2}},
    {{1, 0}, {2, 0}, {2, -1}},
    //  ㄴ 자 도형 (대칭)
    {{0, 1}, {0, 2}, {-1, 2}},
    {{1, 0}, {2, 0}, {2, 1}},
    {{0, 1}, {0, 2}, {1, 0}},
    {{0, 1}, {1, 1}, {2, 1}},
    // ㅁ자 도형
    {{0, 1}, {1, 0}, {1, 1}},
    //ㄹ자 도형
    {{0, 1}, {-1, 1}, {-1, 2}},
    {{1, 0}, {1, 1}, {2, 1}},
    // ㄹ자 도형(대칭)
    {{0, 1}, {1, 1}, {1, 2}},
    {{1, 0}, {1, -1}, {2, -1}},
    // ㅗ자 도형
    {{0, 1}, {0, 2}, {-1, 1}},
    {{0, 1}, {0, 2}, {1, 1}},
    // ㅗ자 도형(대칭)
    {{1, 0}, {2, 0}, {1, 1}},
    {{1, 0}, {2, 0}, {1, -1}},
};
int main()
{
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> paper[i][j];
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      for (int k = 0; k < 19; k++)
      {
        bool ok = true;
        int sum = paper[i][j];
        for (int l = 0; l < 3; l++)
        {
          int x = i + polanomino[k][l][0];
          int y = j + polanomino[k][l][1];
          if (0 <= x && x < n && 0 <= y && y < m)
          {
            sum += paper[x][y];
          }
          else
          {
            ok = false;
            break;
          }
        }
        if (ok && ans < sum)
        {
          ans = sum;
        }
      }
    }
  }
  cout << ans << '\n';
  return 0;
}