
#include<stdio.h>
#define llong long long

llong f(llong i,llong j){
	return i * i + 100000 * i + j * j - 100000 * j + i * j;
}

int main(){
	llong t, n, m, i, j, mid, flag, tmp;
	llong t1, t2, k, mt;

	scanf("%I64d", &t);
	while(t--)
	{
		scanf("%I64d%I64d", &n, &m);

		t1 = f(1,n);
		t2 = f(n,1);
		for (i = 1; i <= n; i++)
		{
			if(f(1, i) < t1) t1 = f(1, i);
			if(f(n, i) > t2) t2 = f(n, i);
		}
		//printf("%I64d %I64d\n",t1,t2);
		while (t1 + 1 < t2)
		{
			mt = (t1 + t2) / 2;
			tmp = 0;
			for (k = 1; k <= n; k++)
			{
				i = 1;
				j = n;
				if(f(i, k) <= mt)
				{
                    while (i < j)
                    {
                        mid = (i + j) / 2;
                        if(f(mid, k) <= mt) i = mid;
                        else j = mid;
                        if (i == j - 1)
                        {
                            if (f(j, k) <= mt) i = j;
                            break;
                        }

                    }
                    tmp += i;
				}
			}
			if (tmp >= m) t2 = mt;
			else t1 = mt;

		}
		if (t1 == t2 - 1)
		{
            tmp = 0;
            mt = t2;
            flag = 0;
			for (k = 1; k <= n; k++)
			{
				i = 1;
				j = n;
				if (f(i, k) <= mt)
				{
                    while (i < j)
                    {
                        mid = (i + j) / 2;
                        if (f(mid, k) <= mt) i = mid;
                        else j = mid;
                        if (i == j-1)
                        {
                            if(f(j, k) <= mt) i = j;
                            break;
                        }
                    }
                    if (f(i, k) == mt)  flag = 1;
                    tmp += i;
				}
			}
            if (tmp <=m && flag) t1 = t2;

		}
		printf("%I64d\n",t1);
	}
	return 0;
}
