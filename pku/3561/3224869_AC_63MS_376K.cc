//

#include <iostream>
#include <math.h>
using namespace std;


char matrix[11][11];

int n, m;
int one;

int dir[8][2] = { {1, 0,}, {-1, 0}, {1, -1}, {-1, 1}, {1, 1}, {-1, -1}, {0, 1}, {0, -1} };
void input(){
    memset(matrix, 0, sizeof(matrix));
    int i, j;
    scanf("%d %d\n", &n, &m);
    one = 0;
    char c = '.';
    for (i = 1; i <= n; i ++)
    {
        for (j = 1; j <= m; j ++)
       {
            scanf("%c", &matrix[i][j]);
            if (('.' != matrix[i][j] && c != matrix[i][j]) && 1 >= one)
            {
                c = matrix[i][j];
                one ++;
            }
       }
        scanf("\n");
    }
}

bool ok(int i, int j, int posx, int posy, int product){
    if (0 != product && 2 != product)
    {
        if ((i - posx) * (j - posy) == product)    return true;
        else return false;
    }
    else
    {
        if (1 == fabs(i - posx) && j == posy && 2 == product || 1 == fabs(j - posy) && i == posx && 0 == product) return true;
        else return false;
    }
}
bool  haveSegment(){
    int i, j;
    int posx = 0, posy = 0, product = 0;
    char c;
    bool flag = false;
    for (i = 1; i <= n; i ++)
    {
        for (j = 1; j <= m; j ++)
        {
            if ('.' != matrix[i][j])
            {
                posx = i, posy = j;
                c = matrix[i][j];
                if ('\\' == matrix[i][j])  product = 1;
                else if ('/' == matrix[i][j])   product = -1;
                else if ('|' == matrix[i][j]) product = 2;
                flag = true;
                break;
            }
        }
        if (flag) break;
    }
    for (i = 1; i <= n; i ++)
    {
        for (j = 1; j <= m; j ++)
        {
            if (!(i == posx && j == posy))
            {
                if (ok(i, j, posx, posy, product))
                {
                    if (!(c == matrix[i][j] || '.' == matrix[i][j])) return false;
                    else if (c == matrix[i][j]) posx = i, posy = j;
                }
                else if ('.' != matrix[i][j]) return false;
            }
        }
    }
    return true;
}
int main(){
    int t;
    scanf("%d", &t);
    while (t--)
    {
        input();
        if (haveSegment() && 1 == one)  printf("CORRECT\n");
        else printf("INCORRECT\n");
    }
    return 0;
}
