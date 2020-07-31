#include<stdio.h>
#include<string>
#define l(A) (A<<1)
#define r(B) (B<<1)+1
struct edge{
	int v;
	edge* next;
}pool[8000000],*adj[2100],*ddj[2100],*pp=pool;
int sc[2100];
inline void Insert(int s,int t){
    //printf("%d->%d\n",s,t);
	pp->v=t;
	pp->next=adj[s];
	adj[s]=pp++;
	pp->v=s;
	pp->next=ddj[t];
	ddj[t]=pp++;
}
bool sat();
int get(char * a){
    return ((a[0]&0xf)*10+(a[1]&0xf))*60+(a[3]&0xf)*10+(a[4]&0xf);
}
void out(int x){
    printf("%02d:%02d",x/60,x%60);
}
int max(int a,int b){return a>b?a:b;}
int n,S,T,s[1100],t[1100],d[1100];
int main(){
    char ss[10],tt[10];
    int last,flag,i,j,s1,s2,t1,t2;
    scanf("%d",&n);
    for(i=0;i<n;++i){
        scanf("%s%s%d",ss,tt,d+i);
        s[i]=get(ss);
        t[i]=get(tt);
    }
    for(i=0;i<n;++i)
        for(j=0;j<n;++j){
            if(i==j)continue;
            //printf("++%d %d:\n",i,j);
            s1=s[i],t1=s[i]+d[i];
                s2=s[j],t2=s[j]+d[j];
                //printf("%d %d %d %d\n",s1,t1,s2,t2);
                if(s1<t2&&s2<t1){
                    Insert(l(i),r(j));
                }
                s2=t[j]-d[j],t2=t[j];
                //printf("%d %d %d %d\n",s1,t1,s2,t2);
                if(s1<t2&&s2<t1){
                    Insert(l(i),l(j));
                }
            s1=t[i]-d[i],t1=t[i];
                s2=s[j],t2=s[j]+d[j];
                //printf("%d %d %d %d\n",s1,t1,s2,t2);
                if(s1<t2&&s2<t1){
                    Insert(r(i),r(j));
                }
                s2=t[j]-d[j],t2=t[j];
                //printf("%d %d %d %d\n",s1,t1,s2,t2);
                if(s1<t2&&s2<t1){
                    Insert(r(i),l(j));
                }
        }
    sat();
    return 0;
}
int pos[2100],tim=0,color[2100];
bool vis[2100];
void dfs1(int i){
    vis[i]=true;
	for(edge* p=adj[i];p;p=p->next)
		if(!vis[p->v])
				dfs1(p->v);
    pos[tim++]=i;
}
void dfs2(int i,int id){
    vis[i]=false;
    sc[i]=id;
	for(edge* p=ddj[i];p;p=p->next)
		if(vis[p->v])
			dfs2(p->v,id);
}

void dfs(int i){
    vis[i]=true;
    for(edge* p=adj[i];p;p=p->next){
        if(!vis[sc[p->v]])
            dfs(sc[p->v]);
    }
    pos[tim++]=i;
}

void test(){
    int i;
    for(i=0;i<8;++i)printf("%d ",sc[i]);puts("");
    for(i=0;i<8;++i)printf("%d ",color[i]);puts("");
}



bool sat(){
    memset(vis,0,sizeof(vis));
    tim=0;
    int i;
    for(i=0;i<(n<<1);++i)
        if(!vis[i])
            dfs1(i);
    for(i=pos[--tim];tim>=0;i=pos[--tim]){
        if(vis[i])
            dfs2(i,i);
        }
    bool flag=0;
    for(i=0;i<(n<<1)&&!flag;i+=2){
        if(sc[i]==sc[i+1]){
            printf("NO\n");
            flag=1;
        }
    }//到这里为止都是标准的判断过程
    //test();
    if(flag)return false;
    printf("YES\n");

    for(i=0;i<(n<<1);++i){//缩图
        if(sc[i]!=i){
            for(edge* p=adj[i];p;p=p->next){
                Insert(sc[i],sc[p->v]);
            }
        }
    }

    tim=0;
    for(i=0;i<(n<<1);++i){//盖戳
        if(sc[i]==i){
            dfs(i);
        }
    }

    memset(color,0,sizeof(color));
    int ttim=0;
    for(i=pos[ttim++];ttim<=tim;i=pos[ttim++]){
        if(!color[i]){
            //printf("%d %d\n",sc[i],sc[i^1]);
            color[sc[i]]=1;//选定
            color[sc[i^1]]=2;//删除
        }
    }
    //test();
    for(i=0;i<n;++i){
        if(color[sc[l(i)]]==1){
            out(s[i]),printf(" ");
            out(s[i]+d[i]),printf("\n");
        }
        else{
            out(t[i]-d[i]),printf(" ");
            out(t[i]),printf("\n");
        }
    }
    return true;
}
