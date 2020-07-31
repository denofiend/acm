
#define OUT(x) (cout << #x << " = " << x << endl)
#include <iostream>
#include <queue>
#include <vector>
#include <map>
using namespace std;

template <class T> void out(T x, int n){	for (int i = 0; i < n; i++)	cout << x[i] << ' ';	cout << endl;	}
template <class T> void out(T x, int n, int m){	for (int i = 0; i < n; i++)	out(x[i], m);	cout << endl;	}

struct Instruction{
    int p1, len, p2;
    Instruction(){  p1 = len = p2 = 0; }
    Instruction(int _p1, int _len, int _p2){    p1 = _p1, len = _len, p2 = _p2; }
};

Instruction ins[1000001];

int n;

void bfs(){
    int step = 0, i, j, k, k0, j0, head, tail, taill;
    queue<vector<int> > queue;
    map<vector<int>, bool> hash;
    map<vector<int>, Instruction> path;
    map<vector<int>, vector<int> > fa;
    vector<int> target, begin, tmp, newTmp;

    for (i = 1; i <= n; i++)
    {
        begin.push_back(i);
        target.push_back(n-i+1);
    }

    queue.push(begin);
    hash[begin] = true;
    newTmp = begin;
    head = tail = 0;
    tail++;

    while (head < tail)
    {
        taill = tail;
        step++;
        for (; head < tail; head++)
        {
            tmp = queue.front();

            queue.pop();

            for (i = 1; i <= n; i++)
            {
                for (j = 1; j <= n + 1 - i; j++)
                {
                    for (k = 0; k <= n - j; k++)
                    {
                        if (k == i - 1) continue;
                        for (k0 = 0; k0 < j; k0++)  newTmp[k+k0] = tmp[i+k0-1];

                        for (k0 = j0 = 0; k0 < n; k0++)
                        {
                            if (k <= k0 && k0 < k + j)  continue;
                            while (i - 1 <= j0 && j0 < i + j - 1)   j0++;
                            newTmp[k0] = tmp[j0];
                            j0++;
                        }


                        if (!hash[newTmp])
                        {
                            fa[newTmp] = tmp;
                            path[newTmp] = Instruction(i, j, k);

                            if (newTmp == target)
                            {
                                printf("%d\n", step);
                                k0 = 0;
                                while (begin != fa[newTmp])
                                {
                                    ins[k0++] = path[newTmp];
                                    newTmp = fa[newTmp];
                                }

                                ins[k0++] = path[newTmp];
                                for (k0--; k0 >= 0; k0--)
                                {
                                    printf("%d %d %d\n", ins[k0].p1, ins[k0].len, ins[k0].p2);
                                }
                                return;
                            }

                            hash[newTmp] = true;
                            queue.push(newTmp);
                            taill++;
                        }
                    }
                }
            }
        }
        head = tail;
        tail = taill;
    }
}


int main(){
    while (EOF != scanf("%d\n", &n))
    {
        bfs();
    }
	return 0;
}
