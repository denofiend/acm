// 3691(pku)
// 
//
#include <iostream>
using namespace std;

template <class T> void out(T x, int n){	for (int i = 0; i < n; ++i)	cout << x[i] << ' ';	cout << endl;	}
template <class T> void out(T x, int n, int m){	for (int i = 0; i < n; ++i)	out(x[i], m);	cout << endl;	}


#define FOR(i, a, b)	for (int i = (int)a; i < (int)b; ++i)
#define REP(i, b)	FOR (i, 0, b)
#define OUT(x) (cout << #x << " = " << x << endl)

const int maxn=1000;
const int maxnodes=480;
const int maxchar=4;

int child[maxnodes][maxchar];
bool danger[maxnodes];
int suffix[maxnodes],q[maxnodes];
int nodes,f,r,p;
int dp[maxn][maxnodes];
char str[maxn];

inline int getwordid(char c) {
    switch(c) {
        case 'A':return 0;
        case 'G':return 1;
        case 'C':return 2;
        case 'T':return 3;
    }
}

bool build_trie(){
    char words[30];
    int m;
    nodes = 1;
    scanf("%d", &m);
    if (0 == m) return false;
    
	memset(child, 0, sizeof(child));
    memset(danger, 0, sizeof(danger));
    memset(suffix, 0, sizeof(suffix));
    memset(q, 0, sizeof(q));
    
	REP (i, m)
	{
        scanf("%s", words);
        int len = strlen(words);
        p = 1;
		REP(j, len)
		{
            int d = getwordid(words[j]);
            if (0 == child[p][d])
			{
                nodes++;
                child[p][d] = nodes;
            }
            p = child[p][d];
            if (danger[p]) break;
        }
        danger[p] = true;
    }
    return true;
}

void build_graph(){
    f = r = 0;
	REP(i, maxchar)
	{
        if (0 == child[1][i])
		{
			child[1][i] = 1;
		}
	    else 
		{
            r++;
            q[r] = child[1][i];
            suffix[child[1][i]] = 1;
        }
    }
    while (f<r) 
	{
        f++;
        danger[q[f]] = danger[q[f]] || danger[suffix[q[f]]];
        if(!danger[q[f]]) 
		{
			REP(i, maxchar)
			{
                if (child[q[f]][i]==0) 
                    child[q[f]][i] = child[suffix[q[f]]][i];
                else 
				{
                    r++;
                    q[r] = child[q[f]][i];
                    suffix[q[r]] = child[suffix[q[f]]][i];
                }
            }
        }
    }
}

void checkmin(int& a, int b) {
    if (a == -1) a = b;
    else if (a > b) a = b;
}

int main() {
    int cases = 0;
    while (build_trie()) 
	{
		cases++;
		printf("Case %d: ",cases);
        build_graph();
        scanf("%s",str);
        int len = strlen(str);
        
        memset(dp, 0xff, sizeof(dp));
        if (!danger[child[1][getwordid(str[0])]])
            dp[0][child[1][getwordid(str[0])]] = 0;
        REP (i, maxchar)
            if (getwordid(str[0])!=i&&!danger[child[1][i]])
                dp[0][child[1][i]]=1;
        FOR (i, 1, len)
		{
			FOR (j, 1, nodes+1)
			{
                if(dp[i-1][j]!=-1) {
                    if(!danger[child[j][getwordid(str[i])]])
                        checkmin(dp[i][child[j][getwordid(str[i])]],dp[i-1][j]);                 
                    for(int k=0;k<maxchar;k++)
                        if (getwordid(str[i])!=k&&!danger[child[j][k]])
                            checkmin(dp[i][child[j][k]],dp[i-1][j]+1);
                }
            }
        }
        int ans = 1<<20;
		FOR(i, 1, nodes+1)
                if (!danger[i] && dp[len-1][i] != -1 && dp[len-1][i] < ans)
                    ans = dp[len-1][i];
        if (ans == 1<<20) ans = -1;
        printf("%d\n",ans);
    }
    return 0;
}
