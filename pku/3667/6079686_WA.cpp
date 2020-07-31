//

#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>


using namespace std;

template <class T> void out(T x, int n){    for(int i = 0; i < n; ++i)  cout << x[i] << ' ';    cout << endl;   }
template <class T> void out(T x, int n, int m){ for(int i = 0; i < n; ++i)  out(x[i], m);   cout << endl;   }


#define OUT(x) (cout << #x << " = " << x << endl)
#define FOR(i, a, b)    for(int i = (int)a; i < (int)b; ++i)
#define REP(i, b)   FOR(i, 0, b)
#define FORD(i, a, b)   for(int i = (int)a; i >= (int)b; --i)

#define MAXN 50010


struct Node{
    int lo, mid, ri;
    int cover;
    int flag;
};

Node nd[MAXN*10];

int n, m;


void createTree(int root, int lo, int ri){
    //printf("creatTree[%d %d]\n", lo, ri);
    nd[root].lo = lo;
    nd[root].ri = ri;
    nd[root].mid = (lo + ri) / 2;
    nd[root].cover = nd[root].flag = 0;

    if (lo == ri)   return;

    createTree(root*2, lo, nd[root].mid);
    createTree(root*2+1, nd[root].mid+1, ri);
}


bool query(int root, int lo, int ri){
    //printf("query[%d %d]\n", nd[root].lo, nd[root].ri);
    if (nd[root].flag)
    {
        nd[root].flag = 0;
        nd[root*2].flag = nd[root*2+1].flag = 1;
        nd[root*2].cover = nd[root*2+1].cover = nd[root].cover;
    }
    if (nd[root].lo == lo && nd[root].ri == ri)
    {
        return 1 == nd[root].cover;
    }

    int mid = (nd[root].lo + nd[root].ri) / 2;

    if (mid >= ri)
    {
        return query(root*2, lo, ri);
    }
    else if (lo > mid)
    {
        return query(root*2+1, lo, ri);
    }
    else
    {
        return query(root*2, lo, mid) || query(root*2+1, mid+1, ri);
    }
}


void insert(int root, int lo, int ri){
    //printf("query[%d %d]\n", lo, ri);
    if (nd[root].flag)
    {
        nd[root].flag = 0;
        nd[root*2].flag = nd[root*2+1].flag = 1;
        nd[root*2].cover = nd[root*2+1].cover = nd[root].cover;
    }

    if (nd[root].lo == lo && nd[root].ri == ri)
    {
        nd[root].flag = 1;
        nd[root].cover = 1;
        return;
    }

    int mid = (nd[root].lo + nd[root].ri) / 2;


    if (mid >= ri)
    {
        insert(root*2, lo, ri);
    }
    else if (lo > mid)
    {
        insert(root*2+1, lo, ri);
    }
    else
    {
        insert(root*2, lo, mid);
        insert(root*2+1, mid+1, ri);
    }
    nd[root].cover = nd[root*2].cover || nd[root*2+1].cover;
}

void del(int root, int lo, int ri){
    if (nd[root].flag)
    {
        nd[root].flag = 0;
        nd[root*2].flag = nd[root*2+1].flag = 1;
        nd[root*2].cover = nd[root*2+1].cover = nd[root].cover;
    }

    if (nd[root].lo == lo && nd[root].ri == ri)
    {
        nd[root].flag = 1;
        nd[root].cover--;
        return;
    }

    int mid = (nd[root].lo + nd[root].ri) / 2;

    if (mid >= ri)
    {
        del(root*2, lo, ri);
    }
    else if (lo > mid)
    {
        del(root*2+1, lo, ri);
    }
    else
    {
        del(root*2, lo, mid);
        del(root*2+1, mid+1, ri);
    }
    nd[root].cover = nd[root*2].cover || nd[root*2+1].cover;
}

int main(){
    int f, a, b, lo, hi, mid;
    while (EOF != scanf("%d %d\n", &n, &m))
    {
        //printf("[%d %d]\n", n, m);
        createTree(1, 1, n);
        REP (i, m)
        {
            scanf("%d", &f);
            if (1 == f)
            {
                scanf("%d", &a);
                //printf("<%d %d>\n", f, a);
                lo = 1, hi = n-a+1;
                while (lo < hi)
                {

                    mid = lo + (hi - lo) / 2;

                    if (query(1, mid, mid+a-1))   lo = mid + 1;
                    else hi = mid;
                }

                if (!query(1, lo, lo+a-1))
                {
                    printf("%d\n", lo);
                    //printf("insert[%d %d]\n", lo, lo+a-1);
                    insert(1, lo, lo+a-1);
                }
                else printf("0\n");
            }
            else
            {
                scanf("%d %d", &a, &b);
                del(1, a, a+b-1);
            }
        }
    }
    return 0;
}
