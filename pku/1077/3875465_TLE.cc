//

#include <iostream>
#include <string>
#include <map>
#define MAXN 100001
using namespace std;

int dir[9][4] = {{1, 3, -1, -1}, {0, 2, 4, -1}, {1, 5, -1, -1}, {0, 4, 6, -1}, {1, 3, 5, 7}, {2, 4, 8, - 1}, {3, 7, -1, -1}, {4, 6, 8, -1}, {5, 7, -1, -1}};
char path[9][5] = {"rdnn", "lrdn", "ldnn", "urdn", "ulrd", "uldn", "urnn", "ulrn", "ulnn"};

char target[] = "12345678x";
struct Node{
	string eight;
	int posx;
};


Node nd[MAXN];
int cnt, queue[MAXN];
char ans[MAXN];
int n;
bool inMaze(const int x){
	return 0 <=x && x < 9;
}

void bfs(){
	int head, tail, i, tmp, newpos, pos;
	map<string, bool> hash;
	hash[nd[0].eight] = true;
	head = tail = 0;
	queue[tail++] = 0;
	cnt = 1;
	n = 0;
	while (head < tail)
	{
		tmp = nd[ queue[head] ].posx;
		pos = queue[head];
		if (target == nd[pos].eight)
		{
			ans[n] = '\0';
			printf("%s\n", ans);
			return;
		}
		head++;
		for (i = 0; i < 4; i ++)
		{
			newpos = dir[tmp][i];
			if (-1 == newpos)	continue;
			nd[cnt].eight = nd[pos].eight;
			swap(nd[cnt].eight[newpos], nd[cnt].eight[tmp]);
			nd[cnt].posx = newpos;

			if (hash[ nd[cnt].eight ])	continue;
			//printf("%s -> %s %c\n", nd[pos].eight, nd[cnt].eight, path[tmp][i]);
			if (target == nd[cnt ].eight)
			{
				ans[n] = '\0';
				printf("%s\n", ans);
				return;
			}
			hash[ nd[cnt].eight ] = true;
			cnt++;
			ans[n++] = path[tmp][i];
			queue[tail++] = cnt;
		}
	}
	printf("unsolvable\n");
}

int main(){
	int i;
	char c;
	for (i = 0; i < 9; i ++)
	{
		scanf("%c ", &c);
		nd[0].eight.push_back(c);
		if ('x' == c)
		{
			nd[0].posx = i;
		}
	}
	bfs();
	return 0;
}
