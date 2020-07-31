// 1118(pku)

#include <stdio.h>
#include <stdlib.h>
#define MAXN 701
#define ZERO 1e-8

struct Point{
    int x, y;
};
Point point[MAXN];

int cmp(const void *a, const void * b){
    Point * aa = (Point *)a;
    Point * bb = (Point *)b;
    if (0 != aa->x && 0 != bb->x)   return aa->x * bb->y - aa->y * bb->x;
    else return aa->y - bb->y;
}
int main(){
    int n;
    while (1 == scanf("%d", &n) && n)
    {
        for (int i = 0; i < n; i ++)
        {
            scanf("%d%d", &point[i].x, &point[i].y);
        }
        qsort(point, n, sizeof(point[0]), cmp);

        int cnt = 0;
        for (int i = 0; i < n;)
        {
            int num = 1, j;

            for (j = i + 1; j < n && (point[j].x * point[i].y == point[j].y * point[i].x); j ++)
            {
                num ++;
            }
            if (cnt < num)  cnt = num;
            i = j;
        }
        printf("%d\n", cnt);
    }
    return 0;
}
