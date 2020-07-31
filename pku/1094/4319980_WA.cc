//

#include <iostream>

using namespace std;

template <class T> void out(T x, int n){    for (int i = 0; i < n; ++i) cout << x[i] << ' ';    cout << endl;   }
template <class T> void out(T x, int n, int m){ for (int i = 0; i < n; ++i) out(x[i], m);   cout << endl;   }

#define OUT(x) (cout << #x << " = " << x << endl)
#define FOR(i, a, b)    for (int i = (int)a; i < (int)b; ++i)
#define REP(i, b)   FOR(i, 0, b)
#define FORD(i, a, b)   for (int i = (int)a; i >= (int)b; --i)


// 1094(pku)

#include <iostream>
#define VMAX 27
#define MAPPING 64

using namespace std;

int  les[VMAX][VMAX], vTp[VMAX], vInDo[VMAX], sorted[VMAX][VMAX], vIn[VMAX], stack[VMAX], visited[VMAX];
/* the number of vertix and the number of edge */
int n, m;
/* use DFS to cheack if there exit a circle */
bool isCircle(){
	int i, top, j;
	for (i = 0; i < n; ++i)
	{
	    memset(visited, 0, sizeof(visited));
	    top = 1;
	    stack[top] = i;
	    while (top)
	    {
	        int v = stack[top];
	        for (j = 0; j < n; ++j)
	        {
	            if (les[v][j] && !visited[j])
	            {
	                visited[j] = 1;
	                stack[++top] = j;
	                if (i == j) return true;
	                break;
	            }
	        }
	        if (j == n)   top--;
	    }
	}
	return false;
}
/* check if there exit a circle
   if there exit return -1
   if there is a TopoSort seq return 1
   else return 0
*/
int checkDo(){
	int i, j = 0, flag = 0, top;
	/* copy the les[][] to sorted[][] */
	for (i = 0; i < n; ++i)
        for (j = 0; j < n; ++j)
            sorted[i][j] = les[i][j];

    /* copy the vInDo[] to vIn[] */

    for (i = 0; i < n; ++i)
        vIn[i] = vInDo[i];

    for (i = 0; i < n; ++i)
    {
        if (0 == vIn[i])
        {
            flag++;
            top = i;
        }
    }

    if (0 == flag)  return -1;
    else if (isCircle()) return -1;
    else if (1 < flag)  return 0;

	/* tmp used to record the top */
	int tmp;
	j = 0;

	/* TopoSort */
	while (1 == flag)
	{
	    tmp = top;
	    vTp[j++] = tmp;
	    flag = 0;
	    for (i = 0; i < n; ++i)
	    {
	        if (top != i)
	        {
	            if (sorted[tmp][i])
	            {
	                vIn[sorted[tmp][i]]--;
                    if (0 == vIn[sorted[tmp][i]])
                    {
                        top = sorted[tmp][i];
                        flag++;
                    }
	            }

	        }
	    }

	}

    if (j == n && 0 == flag)    return 1;
    else if (0 == flag) return -1;
    else return 0;
}
int main(){
    while (EOF != scanf("%d%d\n", &n, &m))
    {
        if (0 == n && 0 == m)   break;
        memset(les, 0, sizeof(les));
        memset(vTp, 0, sizeof(vTp));
        memset(vInDo, 0, sizeof(vInDo));

        int e_ids, circle, spos = 0, cpos = 0, isCircle = 0, ok = 0;
        char from, to;
        for (e_ids = 1; e_ids <= m; ++e_ids)
        {
            scanf("%c%c%c\n", &from, &to, &to);

            les[from-'A'][to-'A'] = to-'A';
            vInDo[to-'A']++;
			circle = checkDo();
			if (1 == circle && !ok)
			{
			    spos = e_ids;
			    ok = true;
			}
			else if (-1 == circle && !isCircle && !ok)
			{
			    cpos = e_ids;
			    isCircle = true;
			}
		}
		if (isCircle)
		{
		    printf("Inconsistency found after %d relations.\n", cpos);
		}
		else
		{
		    if (ok)
		    {
		        printf("Sorted sequence determined after %d relations: ", spos);
		        for (int i = 0; i < n; ++i) printf("%c", (char)(vTp[i] + 'A'));
		        printf(".\n");
		    }
		    else
		    {
		        printf("Sorted sequence cannot be determined.\n");
		    }
		}
    }
	return 0;
}
