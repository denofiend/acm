#include<stdio.h>

int a[7];

bool find( int average, int sum, int index )
{
if( average == sum )
    return true;
if( average < sum )
    return false;
int i;
for( i = index; i > 0; i -- )
{
    if( a[i] > 0 )
    {
     a[i] --;
     if( find( average, sum + i , i) )
      return true;
     a[i] ++;
    }
}
return false;
}

int main()
{
int i, sum, t = 1;
while( scanf("%d %d %d %d %d %d",&a[1],&a[2],&a[3],&a[4],&a[5],&a[6]) )
{
    sum = 0;
    for( i = 1; i < 7; i ++ )
    {
     if( a[i] > 6 )
      a[i] = 6 + a[i]%2;
     sum += a[i]*i;
    }
    if( sum == 0 )
     break;
    printf("Collection #%d:\n",t++);
    if( sum%2 == 1 )
     puts("Can't be divided.\n");
    else
    {
     if( find( sum/2, 0 , 6) )
      puts("Can be divided.\n");
     else
      puts("Can't be divided.\n");
    }
}
return 0;
}
