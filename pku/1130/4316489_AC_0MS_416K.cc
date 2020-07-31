#include<iostream>
using namespace std;
const int base=200000;
int u,n;
int map[30][30];
int q[base],front,rear;
struct node{
    int c;
    int sign;
}visit[30];
bool flag[30],ok;
void bfs(){
     front=-1,rear=0; visit[u].c=1;
     q[rear]=u;
     while(front!=rear){
          front=(front+1)%base;
          int k=q[front];
          for(int i=1;i<=map[k][0];i++){
                 if(visit[map[k][i]].c==0){
                        visit[map[k][i]].c=visit[k].c+1;
                        rear=(rear+1)%base;
                        q[rear]=map[k][i];
                 }
          }
     }
}
void dfs(int k){
     if(ok || flag[k]) return;
     if(k==0){ ok=true; return; }
     flag[k]=true;
     for(int i=1;i<=map[k][0];i++) dfs(map[k][i]);
}
int cmp(const void *a,const void *b){
    return (*(node *)a).c-(*(node *)b).c;
}
void solve(){
     int x,y;
    memset(map,0,sizeof(map));
    memset(visit,0,sizeof(visit));
    while(scanf("%d%d",&x,&y)!=EOF){
          if(x<0 || y<0) break;
          map[y][++map[y][0]]=x;
    }
    for(int i=0;i<n;i++) visit[i].sign=i;
    bfs(); visit[u].c=0;
    qsort(visit,n,sizeof(visit[0]),cmp);
    int j=0;
    while(visit[j].c==0) j++;
    for(int i=j;i<n;i++){
         memset(flag,0,sizeof(flag));
         ok=false;
         int k=visit[i].sign;
         if(k==0){ printf("Put guards in room %d.\n",k); break; }
         int temp=map[k][0]; map[k][0]=0;
         dfs(u);
         if(!ok){ printf("Put guards in room %d.\n",k); break; }
         else map[k][0]=temp;
    }
}
int main(){
    while(scanf("%d%d",&n,&u)!=EOF) solve();
    return 0;
}
