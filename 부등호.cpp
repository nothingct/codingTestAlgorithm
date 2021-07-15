#include <string.h>
#include <stdio.h>

int K;
const int MAX=12;
char ops[MAX];
int arr[MAX];
int option[2][10]={
  {9,8,7,6,5,4,3,2,1,0},
  {0,1,2,3,4,5,6,7,8,9}
};

bool check[10];
bool isEnd;

void inEqual(int cur,int op)
{
  if(cur>=2){
    char arrow = ops[cur-1];
    if(arrow=='<'){
      if(arr[cur-1]>=arr[cur])
        return;
    }
    else
      if(arr[cur-1]<=arr[cur])
        return;
  }
  if(cur==K+1){
    for(int i=1; i<=cur; i++){
      printf("%d",arr[i]);
    }
    printf("\n");
    isEnd=true;
    return;
  }
  
  for(int i=0; i<10; i++){
    if(!check[ option[op][i] ] ){
      if(isEnd)
        break;
      check[option[op][i]]=true;
      arr[cur+1]=option[op][i];
      inEqual(cur+1,op);
      check[ option[op][i] ] = false;
    }
  }
}


int main(){
  scanf("%d",&K);
  for(int i=1; i<=K; i++){
    scanf(" %c",&ops[i]);
  }
  inEqual(0,0);
  isEnd=false;
  for(int i=0; i<10;i++){
    check[i]=false;
  }
  inEqual(0,1);
}