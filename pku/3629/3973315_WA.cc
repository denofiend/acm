//

#include <iostream>
#include <algorithm>
using namespace std;


template <class T> void out(T x, int n){    for (int i = 0; i < n;  i++)    cout << x[i] << ' ';    cout << endl;   }
template <class T> void out(T x, int n, int m){ for (int i = 0; i < n; i ++)    out(x[i], m);   cout << endl;   }

const int M = 10000001;
struct Node{
    int id;
    Node *next;
};

Node nd[M];
int ans[M];
Node *head, *link, *link1, *tail;

void output(){
    link = head;
    while (link)
    {
        cout << link->id << ' ';
        link = link->next;
    }
    cout << endl;
}

int main(){
    int N, K, P, j, i, k;

    while (EOF != scanf("%d%d%d", &N, &K, &P))
    {
        head = tail = NULL;
        for (i = K; i; i --)
        {
            nd[i].id = i;
            nd[i].next = head;
            head = &nd[i];
        }
        tail = &nd[K];

        //output();
        k = 0;
        while (NULL != head)
        {
            for (i = 0; i < N && head; i ++)
            {
                if (i == N - 1)
                {
                    ans[k++] = head->id;
                }
                head = head->next;

                for (j = 0; j < 2 && head; j ++)
                {
                    link = head;
                    head = head->next;

                    if (NULL == head)
                    {

                        link->next = head;
                        head = link;
                        continue;
                    }

                    link->next = tail->next;
                    tail->next = link;
                    tail = link;
                    //output();
                    //out(ans, j);
                }
            }
        }
        sort(ans, ans + k);
        for (i = 0; i < k; i++)
            printf("%d\n", ans[i]);

    }
    return 0;
}
