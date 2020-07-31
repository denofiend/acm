//

#include <iostream>
#include <map>
#define MAXN 10000001
using namespace std;

int dir[9][4] = {{1, 3, -1, -1}, {0, 2, 4, -1}, {1, 5, -1, -1}, {0, 4, 6, -1}, {1, 3, 5, 7}, {2, 4, 8, - 1}, {3, 7, -1, -1}, {4, 6, 8, -1}, {5, 7, -1, -1}};
char path[9][5] = {"rdnn", "lrdn", "ldnn", "urdn", "ulrd", "uldn", "urnn", "ulrn", "ulnn"};

char target[] = "12345678x";
struct Node{
	char eight[10];
	int posx;
};
bool operator <(const Node &a, const Node &b){
	return strcmp(a.eight, b.eight);
}

Node nd[MAXN];
int cnt, queue[MAXN];
char ans[MAXN];
int n;
bool inMaze(const int x){
	return 0 <=x && x < 9;
}

void bfs(){
	int head, tail, i, tmp, newpos, pos;
	map<Node, bool> hash;
	hash[nd[0]] = true;
	head = tail = 0;
	queue[tail++] = 0;
	cnt = 1;
	n = 0;
	while (head < tail)
	{
		tmp = nd[ queue[head] ].posx;
		pos = queue[head];

		head++;
		for (i = 0; i < 4; i ++)
		{
			newpos = dir[tmp][i];
			if (-1 == newpos)	continue;
			strcpy(nd[cnt].eight, nd[pos].eight);
			swap(nd[cnt].eight[newpos], nd[cnt].eight[tmp]);
			nd[cnt].posx = newpos;

			if ( hash.end() != hash.find( nd[cnt] ))	continue;
			//printf("%s -> %s %c\n", nd[pos].eight, nd[cnt].eight, path[tmp][i]);
			if (0 == strcmp(target, nd[cnt ].eight))
			{
				ans[n] = '\0';
				printf("%s\n", ans);
				return;
			}
			hash[ nd[cnt] ] = true;
			cnt++;
			ans[n++] = path[tmp][i];
			queue[tail++] = cnt;
		}
	}
	printf("unsolvable\n");
}

int main(){
	int i;
	for (i = 0; i < 9; i ++)
	{
		scanf("%c ", &nd[0].eight[i]);
		if ('x' == nd[0].eight[i])
		{
			nd[0].posx = i;
		}
	}
	bfs();
	return 0;
}
