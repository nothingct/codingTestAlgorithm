#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(string s) { 
    int answer=s.size();

    for(int i=1;i<=s.size()/2;i++){
        string compressed,parsed;

        int count=1;
        parsed = s.substr(0, i);

        for(int j=i;j<s.size();j+=i){
        if(parsed==s.substr(j,i)) count++;
        else{
            if(count>1) compressed+=to_string(count);
            compressed+=parsed;
            parsed=s.substr(j,i);
            count=1;
            }
        }

        if(count>1) compressed+=to_string(count);
 
        compressed+=parsed;
        if(answer >compressed.size()) answer= compressed.size();
    }
    return answer;
}