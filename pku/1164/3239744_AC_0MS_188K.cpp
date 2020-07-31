#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define clr(x) memset(x,0,sizeof(x))

// 1 (= wall to the west), 2 (= wall to the north),
// 4 (= wall to the east), 8 (= wall to the south).

const int D[][2]={{0,-1},{-1,0},{0,1},{1,0} };
const char wall[]={ 1,2,4,8 };
int dfn;
const int maxN=51;
char mark[maxN][maxN],M[maxN][maxN];
int h,w;

void dfs(int i,int j)
{
	mark[i][j]=1; dfn++;
	for(int d=0;d<4;d++) {
		int ii=i+D[d][0],jj=j+D[d][1];
		if(ii<h && ii>=0 && jj<w && jj>=0
			&& !mark[ii][jj] && (M[i][j] & wall[d])==0)
			dfs(ii,jj);
	}
}

int main()
{
	//freopen("test.in","r",stdin);
	int i,j,k,ca;
	while(scanf("%d %d",&h,&w)!=EOF) {
		for(i=0;i<h;i++)
			for(j=0;j<w;j++)
				scanf("%d",&M[i][j]);
		int m=0,n=0;
		clr(mark);
		for(i=0;i<h;i++)
			for(j=0;j<w;j++)
				if(!mark[i][j]) {
					n++; dfn=0;
					dfs(i,j);
					if(dfn>m) m=dfn;
				}
		printf("%d\n%d\n",n,m);
	}
}
