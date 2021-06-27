#include <string>
#include <vector>

using namespace std;

string solution(int n)
{
  string answer = "";
  string digit = "412";
  while (n != 0)
  {
    int mod = n % 3;
    n /= 3;
    if (mod == 0)
      n -= 1;
    answer = digit[mod] + answer;
  }
  return answer;
}
