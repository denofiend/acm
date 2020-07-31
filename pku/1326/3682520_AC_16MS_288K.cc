#include <stdio.h>



int calc(int dis, char lev)

{

	switch(lev)

	{

		case 'F': return dis * 2;

		case 'B': return (int)(dis + (dis+1)/2);

		case 'Y': 

			{

				if(dis<=500) return 500;

				else return dis;	

			}	

	}	

}



int main()

{

	char s1[100], s2[100], lev;

	int dis, all;

	while (1)

	{

		all=0;

		while(1)

		{

			scanf("%s", s1);

			if(s1[0]=='0' || s1[0]=='#') break;

			scanf("%s %d %c", s2, &dis, &lev);

			all += calc(dis, lev);	

		}

		if (s1[0] == '0') printf("%d\n",all);

		else break;

	}

	return 0;

}




