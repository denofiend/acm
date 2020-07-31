// 1118(pku)

#include <stdio.h>
#include <stdlib.h>
#define MAXN 701


struct Point{
    int x, y;
};
Point point[MAXN], dir[MAXN];


int det(const Point *a, const Point *b){
    return a->x * b->y - a->y * b->x;
}

int cmp(const void *a, const void * b){
    Point * aa = (Point *)a;
    Point * bb = (Point *)b;
    return det(aa, bb);
}

int main(){
    int n;
    while (1 == scanf("%d", &n) && n)
    {
        for (int i = 0; i < n; i ++)
        {
            scanf("%d%d", &point[i].x, &point[i].y);
        }

        int cnt = 0;
        for (int i = 0, max = 2; i < n; i ++)
        {
            int tmax = 2;
            for (int j = 0; j < n; j ++)
            {
                if (i == j) continue;

                if (point[i].x == point[j].x)
                {
                    dir[j].x = 0;
                    dir[j].y = 1;
                }
                else if (point[i].y == point[j].y)
                {
                    dir[j].x = 1;
                    dir[j].y = 0;
                }
                else
                {
                    dir[j].x = point[i].x - point[j].x;
                    dir[j].y = point[i].y - point[j].y;
                }
            }
            dir[i].x = dir[0].x;
            dir[i].y = dir[0].y;

            qsort(dir + 1, n - 1, sizeof(dir[0]), cmp);

            for (int j = 1; j < n - 1; j ++)
            {
                if (0 == det(dir + j, dir + j + 1))
                {
                    tmax ++;
                }
                else
                {
                    if (max < tmax) max = tmax;
                    tmax = 2;
                }
            }

            if (max < tmax) max = tmax;
            if (cnt < max)  cnt = max;

        }
        printf("%d\n", cnt);
    }
    return 0;
}
