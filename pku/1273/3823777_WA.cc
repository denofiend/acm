//

#include <iostream>
#define inf 0xfffffff
#define MAXN 220

using namespace std;

int n, m, g[MAXN][MAXN];
int flow[MAXN][MAXN];

template <class T> void out(T x, int n){	for (int i = 0; i < n; i ++)	cout << x[i] << ' ';	cout << endl;	}
template <class T> void out(T x, int n, int m){	for (int i = 0; i < n; i ++)	out(x[i], m);	cout << endl;	}

//求网络最大流,邻接阵形式

//返回最大流量,flow返回每条边的流量

//传入网络节点数n,容量mat,源点source,汇点sink







int max_flow(int n, int mat[][MAXN], int source, int sink, int flow[][MAXN]){

	int pre[MAXN], que[MAXN], d[MAXN], p, q, t, i, j;



	if (source == sink) return inf;



	for (i = 0; i < n; i++)

		for (j = 0; j < n; j++)

            flow[i][j] = 0;



	for (;;)

	{

		for (i = 0; i < n; i++)pre[i] = 0;

        t = source;

        pre[t] = source + 1;

        d[t] = inf;



        for (p = q = 0; p <= q && !pre[sink]; t = que[p], p++)

        {

            for (i = 0; i < n; i ++)

            {

                j = mat[t][i] - flow[t][i]; //残留网络中cf(t, i);

                if (!pre[i] && j)

                {

                    que[q++] = i;

                    pre[i] = t + 1;

                    d[i] = d[t] < j ? d[t] : j;

                }

                else

                {

                    j = flow[i][t];

                    if (!pre[i] && j)

                    {

                        que[q++] = i;

                        pre[i] = - t - 1;

                        d[i] = d[t] < j ? d[t] : j;

                    }

                }

            }

        }

       // out(d, sink + 1);

      //  out(pre, sink + 1);

		if (!pre[sink]) break;

		for (i = sink; i != source;)

		{

            if (pre[i] > 0)

				flow[pre[i] - 1 ][i] += d[sink], i = pre[i] - 1;

			else

				flow[i][- pre[i] - 1] -= d[sink], i = - pre[i] - 1;

		}

	}

	for (j = i = 0; i < n; i ++)

        j += flow[source][i];

	return j;

}
void input(){
	int i, s, e, c;
	memset(g, 0, sizeof(g));
	for (i = 0; i < m; i ++)
	{
		scanf("%d %d %d\n", &s, &e, &c);
		g[s - 1][e - 1] = c;
	}
	//out(g, n, n);
}

int main(){
	while (EOF != scanf("%d %d", &m, &n))
	{
		input();
		printf("%d\n",  max_flow(n, g, 0, n - 1, flow));
	}
	return 0;
}