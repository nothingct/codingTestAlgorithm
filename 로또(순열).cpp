#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
  while (true){
    int k;
    cin>>k;
    if(k==0) break;
    vector<vector<int>> ans;
    vector<int> arr(k);
    for(int i=0; i<k; i++){
      cin>>arr[i];
    }
    vector<int> s;
    for(int i=0; i<k-6; i++){
      s.push_back(0);
    }
    for(int i=0; i<6; i++){
      s.push_back(1);
    }
    do{
      vector<int> cur;
      for(int i=0; i<k; i++){
        if(s[i]==1) cur.push_back(arr[i]);
      }
      ans.push_back(cur);
    }while(next_permutation(s.begin(),s.end()));
    sort(ans.begin(),ans.end());
    for (auto &v : ans){
      for(int i=0; i<v.size(); i++){
        cout<<v[i]<<' ';
      }
      cout<<'\n';
    }
    cout<<'\n';
  }
  return 0;
}