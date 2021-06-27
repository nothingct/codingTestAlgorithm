#include <string>
#include <vector>
#include <queue>
using namespace std;
// IDEA : 큐가 빌 때까지,
//  큐에있는 모든원소들을 현재진척도+speed[i]로 갱신한다.
//  그리고 다시 큐에 갱신된 진척도를 넣는다.
//  이 과정 이후 완료된 작업 이 있는지 내부를 검사한다.초기 개수는 0.
//  큐가 비어있지 않은 상태에서 맨 앞이 100보다 크거나 같으면 작업을 완료한 것이므로 큐에서 꺼내고 개수를 +1 한다.이 때 vector의 맨 앞 스피드 요소도 같이 제거한다.<- 그래야 큐의 size== speed배열의 개수 가 되어 계속 진행도 갱신가능.
//이 과정을 더 완료할 작업이 없을 때까지 한다.
//이후 하나라도 count가 있다면 정답에 해당 개수를 추가한다.
//이 과정을 계속 반복한다.

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
  vector<int> answer;
  //진행중인 작업-> 순서대로 큐에 넣는다.
  queue<int> q;
  for (int i : progresses)
    q.push(i);
  //큐가 빌 때까지 시작.
  while (!q.empty())
  {
    //진행도 갱신
    for (int i = 0; i < q.size(); i++)
    {
      int p = q.front();
      q.pop();
      q.push(p + speeds.at(i));
    }
    //갱신 후 완료된 작업의 개수 확인하기.
    int cnt = 0;
    //앞에서부터 작업이 완료된 요소들 모두 꺼내기.
    while (true)
    {
      //큐가 비어있지 않고, 100%이상을 달성한 작업이 있다면 , 앞에서부터 큐에서 제거하고 카운트 증가 및 speeds배열에도 해당 정보 삭제
      if (q.size() > 0 && q.front() >= 100)
      {
        q.pop();                      //빼고
        speeds.erase(speeds.begin()); //스피드 정보도 제거->idx 매칭 을 위해 빠지는건 맨 앞작업이니까
        cnt++;                        //작업 완료개수 증가시키고
        continue;                     //반복
      }
      //큐가 비었거나, 맨 앞 작업이 아직 100%미만인경우 는 완료할 수 없다.
      break;
    }
    //cnt 가 0이 아니라면 정답에 추가
    if (cnt > 0)
      answer.push_back(cnt);
  }

  return answer;
}