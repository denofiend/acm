// 1151(pku)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct line
{
    double x, y1, y2;
    int in;
};

struct node
{
    node * pl, * pr;
    int iL, iR;
    double left, right;
    double y_len;
    int in;
}mem[404];

line l[202];
double y[202];
int n;
double sum;
int nodeCnt;

node * newNode()
{
    node * pt=&mem[nodeCnt++];
    memset(pt,0,sizeof(pt));
    return pt;
}

node * buildTree(int il, int ir)
{
    node * root=newNode();
    root->iL=il;
    root->iR=ir;
    root->left=y[il];
    root->right=y[ir];
    if(ir - il > 1)
    {
        int mid = (il + ir)/2;
        root->pl=buildTree(il,mid);
        root->pr=buildTree(mid,ir);
    }
    return root;
}

void length(node * root)
{
    root->y_len=0;
    if(root->in)
    {
        root->y_len= root->right - root->left;
    }else
    {
        if(root->pl)
            root->y_len+=root->pl->y_len;
        if(root->pr)
            root->y_len+=root->pr->y_len;
    }
}

void update(node * root, line ll)
{
    if(root->left==ll.y1 && root->right==ll.y2)
    {
        root->in += ll.in;
        length(root);
        return;
    }

    if(root->iR - root->iL <=1 )
        return;
    if(root->pl->right > ll.y1)
    {
        if(root->pl->right >= ll.y2)
            update(root->pl, ll);
        else
        {
            line temp=ll;
            temp.y2=root->pl->right;
            update(root->pl, temp);
            temp=ll;
            temp.y1=root->pr->left;
            update(root->pr,temp);
        }
    }else
    {
        update(root->pr, ll);
    }
    length(root);

}

int cmp1( const void *a ,const void *b)
{
    return (*(line *)a).x > (*(line *)b).x ? 1 : -1;
}

int cmp2(const void * a, const void * b)
{
    return (*(double *)a) > (*(double *)b) ? 1 : -1;
}

int main()
{ 
    int T=1;
    while(scanf("%d", &n)==1 && n)
    {
        nodeCnt=0;
        memset(l,0,sizeof(l));
        memset(y,0,sizeof(y));
        memset(mem,0,sizeof(mem));
        int i;
        for(i = 0; i < n; i++)
        {
            scanf("%lf%lf%lf%lf", &l[2*i].x, &l[2*i].y1, &l[2*i+1].x, &l[2*i+1].y2);
            l[2*i].y2=l[2*i+1].y2, l[2*i+1].y1=l[2*i].y1;
            l[2*i].in=1, l[2*i+1].in=-1;
            y[2*i]=l[2*i].y1, y[2*i+1]=l[2*i].y2;
        }
        qsort(l, 2*n, sizeof(l[0]), cmp1);
        qsort(y, 2*n, sizeof(y[0]), cmp2);

        node * root= buildTree(0,2*n-1);

        sum=0;

        for(i = 0; i < 2 * n - 1; i++)
        {
            update(root, l[i]);
            sum += (root->y_len) * (l[i+1].x - l[i].x);
        }

        printf("Test case #%d\nTotal explored area: %.2f\n\n",T++,sum);
    }
    return 0;
}