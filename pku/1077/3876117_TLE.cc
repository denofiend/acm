//

#include <iostream>
#define MAXN 10000001
using namespace std;

int dir[9][4] = {{1, 3, -1, -1}, {0, 2, 4, -1}, {1, 5, -1, -1}, {0, 4, 6, -1}, {1, 3, 5, 7}, {2, 4, 8, - 1}, {3, 7, -1, -1}, {4, 6, 8, -1}, {5, 7, -1, -1}};
char path[9][5] = {"rdnn", "lrdn", "ldnn", "urdn", "ulrd", "uldn", "urnn", "ulrn", "ulnn"};

char target[] = "12345678x";
struct Node{
	char eight[10];
	int posx;
};
Node nd[MAXN];
int cnt, queue[MAXN];
char ans[MAXN];
int n;

const int MAX = 99730; //哈希表长度
const int len = 30; //字符串的最大长度
int Htable[MAX];
int dist[MAX];

unsigned long Hash(char * key){
	unsigned long h = 0;
	while(*key)
	{
		h = (h << 4) + *key++;
		unsigned long g = h & 0xf0000000L;
		if(g)
		    h ^= g >> 24;
		h &= ~g;
	}
	return h % MAX;
}

int search(char * key){
	unsigned long i = Hash(key);
	//printf("search key = %s, i = %u\n\n", key, i);
	while(Htable[i])
	{
		if(strcmp(nd[Htable[i]].eight, key) == 0)
		    return i;
		i = (i + 1) % MAX;
	}
	return -1;
}

 //j为关键字在ch中的位置，即索引
int insert(char * key, int j){
	unsigned long i = Hash(key);
	//printf("key = %s, i = %u\n\n", key, i);
	while(Htable[i])
		i = (i + 1) % MAX;
	Htable[i] = j;
	//printf("%s -> Htable[%d] = %d\n", key, i, Htable[i]);
	return i;
}



void bfs(){
	int head, tail, i, tmp, newpos, pos, j = 1, m, m0;
	head = tail = 0;
	queue[tail++] =1;
	m = insert(nd[1].eight, 1);
	memset(dist, 0xff, sizeof(dist));
	dist[m] = 0;
	//printf("nd[%d].eight = %s\n", m, nd[Htable[m]].eight);
	cnt = 2;
	n = 0;
	while (head < tail)
	{
		tmp = nd[ queue[head] ].posx;
		pos = queue[head];
		m0 = search(nd[pos].eight);
		//printf("nd[%d].eight = %s\n", pos, nd[pos].eight);
		if (0 == strcmp(target, nd[pos].eight))
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
			strcpy(nd[cnt].eight, nd[pos].eight);
			swap(nd[cnt].eight[newpos], nd[cnt].eight[tmp]);
			nd[cnt].posx = newpos;
			m = search(nd[cnt].eight);
			//printf("%s -> m = %d\n", nd[cnt].eight, m);
			if (-1 == m)
			{
				insert(nd[cnt].eight, cnt);
				dist[m] = dist[m0] + 1;
			}
			else 
			{
				
				if (dist[m] > dist[m0] + 1)
				{
					dist[m] = dist[m0] + 1;
				}
				else	continue;
			}
			if (0 == strcmp(target, nd[cnt ].eight))
			{
				//printf("target = %s, nd[%d].eight = %s\n", target, cnt, nd[cnt].eight);
				ans[n] = '\0';
				printf("%s\n", ans);
				return;
			}
	
			ans[n++] = path[tmp][i];
			queue[tail++] = cnt;
			cnt++;
		}
	}
	printf("unsolvable\n");
}

int main(){
	int i;
	for (i = 0; i < 9; i ++)
	{
		scanf("%c ", &nd[1].eight[i]);
		if ('x' == nd[1].eight[i])
		{
			nd[1].posx = i;
		}
	}
	bfs();
	return 0;
}
