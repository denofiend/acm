// 1159(pku)

#include <stdio.h>


int main(){
    int a[2][5002] = {0} ;
    char p[5002] ;
    char ch[5002] ;
    int i, j, n, t ;
    int current ;
    int before ;

    scanf("%d%s", &n, p + 1) ;

    current = 1 ;
    before = 0 ;

    for ( i = 1; i <= n; i ++)
       ch[i] = p[ n - i + 1 ];
	ch[i] = '\0';

    for (i = 1; i <= n; i ++)
    {
		for (j = 1; j <= n; j ++)
        {
            if (ch[i] == p[j])
               a[ current ][j] = a[ before ][ j - 1 ] + 1 ;
            else if (a[ current ][j - 1] >= a[ before ][j])
				a[current][j] = a[current][j - 1];
			else
				a[current][j] = a[before][j];
        }
		t = current ;
		current = before ;
		before = t ;
    }

    printf("%d\n", n - a[t][n]) ;
    return 0;
}
