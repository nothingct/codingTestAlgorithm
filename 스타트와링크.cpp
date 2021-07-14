#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
const int MAX = 22;
int n;
int stat[MAX][MAX];

int go(int index, vector<int>&first, vector<int>& second){
  if(first.size()>n/2) return -1;
  if(second.size() > n/2) return -1;
  if(index == n){
    int totalStat1 = 0;
    int totalStat2 = 0; 
    for(int i=0;i < n/2; i++){
      for(int j =0; j<n/2; j++){
        if(i==j) continue;
        totalStat1+= stat[first[i]][first[j]];
        totalStat2+= stat[second[i]][second[j]];
      }
    }
    int diff = abs(totalStat1-totalStat2);
    return diff;
  }
  //first 팀에 해당 index 넣기 
  int ret = -1;
  first.push_back(index);
  int totalStat1 = go(index+1,first,second);
  if(ret==-1 || (totalStat1!=-1 && ret > totalStat1)){
    ret = totalStat1;
  }
  first.pop_back();
  //second 팀에 해당 index 넣기
 
  second.push_back(index);
  int totalStat2 = go(index+1,first,second);
  if(ret==-1 || (totalStat2!=-1 && ret > totalStat2)){
    ret = totalStat2;
  }
  second.pop_back();
  return ret;
}

int main(){
  cin>>n;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      cin>>stat[i][j];
    }
  }
  vector<int>first,second;
  cout<<go(0,first,second)<<'\n';  
}