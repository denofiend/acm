#include <stdio.h>
#include <set>
#include <iterator>
using namespace std;

int p[210][2],x[210],y[210];
set<int,less<int> > st;
int cmp(const void *a,const void *b)
{
    return ((int*)a)[1] - ((int*)b)[1];
}
int main()
{
    int i,j,k,kx,h,n,m,t,t1,t2;
    scanf("%d",&t);
    while(t--)
    {
        k=1;
        st.clear();
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&t1,&t2);
            st.insert(t1);
            if(i==0)p[i][0]=t1,p[i][1]=t2;
            else{
                for(j=0;j<k;j++)
                    if(p[j][0]==t1&&p[j][1]==t2)break;
                if(j==k)p[k][0]=t1,p[k++][1]=t2;
            }
        }
        if(m==1||k<m)
        {
            printf("4\n");continue;
        }
        qsort(p,k,8,cmp);
//        for(h=0;h<k;h++)printf("p %d %d\n",p[h][0],p[h][1]);
        set<int>::iterator itr;
        itr = st.begin();
        kx=0;
        for(;itr!=st.end();itr++)
        {
            x[kx++]=*itr;
        }
//        printf("kx=%d\n",kx);
        int min=2000000000,area;
        for(i=0;i<kx;i++)
        {
            for(j=i+1;j<kx;j++)
            {
                t1=0;
                for(h=0;h<k;h++)
                {
//                    printf("p %d %d\n",p[h][0],p[h][1]);
                    if(p[h][0]>=x[i]&&p[h][0]<=x[j])
                    {
                        y[t1++]=p[h][1];
//                        printf("t1=%d\n",t1);
                        if(t1>=m)
                        {
                            area=(x[j]-x[i]+2)*(y[t1-1]-y[t1-m]+2);
                            if(area<min)min=area;
                        }
                    }
                }
            }
        }
        printf("%d\n",min);
    }
}
