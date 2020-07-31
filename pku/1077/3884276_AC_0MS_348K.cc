#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 200000

typedef struct{
    int f;
    int pos;
}Node;

typedef struct{
    char s[10];
    int par, left, right;
    int h, pos;
	char dir;
}Tsta;

Tsta open[MAX];
Node heap[5000], res;
char tar[] = "12345678x";
char dir[] = "udlr";
char path[MAX];
int st, ed, hp;

bool IsOK(char s[]){
    int i, j, sum;
    sum = 0;
    for (i = 0; i < 9; i++)
	{
        if (s[i] == 'x') continue;
        for(j = 0; j < i; j++)
		{
            if(s[j] == 'x') sum += (abs(j / 3 - 2) + abs(j % 3 - 2));
			if(s[j] > s[i]) sum++;
		}
    }
	//printf("sum = %d\n", sum);
    if(sum % 2) return false;
    else return true;
}

int Get_p(char s[]){
    int i, j, p;
    int r1, r2, c1, c2;
    for(p = 0, i = 0; i < 9; i++)
	{
        if(s[i] == 'x') continue;
        if(s[i] != tar[i])
		{
            j = s[i] - '1';
            p += abs(i/3 - j/3) + abs(i%3 - j%3);
        }
    }
    return p;
}

void Init(char s[]){
    int i;
    strcpy(open[0].s, s);
    for(i = 0; i < 9; i++)
        if(s[i] == 'x') break;
    open[0].pos = i;
    open[0].h = 0;
    open[0].left = open[0].right = -1;
    open[0].par = 0;
    hp =0; ed = 1;
}

bool find(char s[]){
    int i, t, j;
    i = 0;
    while(i != -1){
  j = i;
        t = strcmp(open[i].s, s);
        if(t == 0) return true;
        else if(t > 0) i = open[i].right;
        else i = open[i].left;
    }
    open[ed].right = -1;
    open[ed].left = -1;
    if(t > 0) open[j].right = ed;
    else open[j].left = ed;
    return false;
}

void move(int i, int pp){
    char ch, s[10];
    int r, c, p, j, pos;
    pos = open[pp].pos;
    strcpy(s, open[pp].s);
    r = pos / 3; 
	c = pos % 3;
	
    if (i == 0)	//u
	{
        if (r - 1 < 0) return;
        p = (r - 1) * 3; p += c;
    }
    else if (i == 1)	//d
	{
        if(r + 1 >= 3) return;
        p = (r + 1) * 3; p += c;
        
	}
    else if (i == 2)	//l
	{
        if(c - 1 < 0) return;
        p = r  * 3; p += c - 1;    
	}
    else if(i == 3)	//r
    {    
		if(c + 1 >= 3) return;
        p = r * 3; p += c + 1;    
	}
    ch = s[p]; s[p] = s[pos]; s[pos] = ch;
    if(!find(s))
	{
        //Inset to Tree and Heap
        strcpy(open[ed].s, s);
        open[ed].pos = p;
        open[ed].dir = dir[i];
        open[ed].h = open[pp].h+1;
        open[ed].par = pp;

        heap[hp].f = 10 * Get_p(s) + open[ed].h;
        heap[hp].pos = ed;
        ed++; hp++;    
	}
    return ;
}

////////////////////////////////
void CreateHeap(int n, int rt){
    int i, j, flag;
    Node temp;
    i = rt;
    j = 2 * i + 1;
    temp = heap[i];
    flag = 0;
    while(j < n && !flag){
        if(j < n - 1 && heap[j].f > heap[j+1].f) j++;
        if(temp.f <= heap[j].f) flag = 1;
        else {
            heap[i] = heap[j];
            i = j;
            j = 2 * i + 1;
            }
        }
    heap[i] = temp;
    }

void HeapSort(){
    int i;
    Node temp;
    for(i = (hp - 1)/2; i >= 0; i--)
        CreateHeap(hp, i);
    for(i = hp - 1; i > 0; i--){
        temp = heap[0];
        heap[0] = heap[i];
        heap[i] = temp;
        CreateHeap(i, 0);
        }
    }
////////////////////////////

void output(int pos){
    int i, j;
    i = pos; j = 0;
    while(i > 0)
	{
        path[j++] = open[i].dir;
        i = open[i].par;
    }
    j--;
    while (j >= 0) printf("%c", path[j--]);
    printf("\n");
}

void Astar(){
    int i, j, r, c;
    int p;
    char temp[10];
    p = 0;
    while (strcmp(open[p].s, tar))
	{
        for (i = 0; i < 4; i++)
		{
			move(i, p);
		}
        HeapSort();
        p = heap[hp - 1].pos;
        hp--;
    }
    output(p);
}

int main(){
    char s[10], c, str[1000];
    int i, j;
    while(gets(str))
	{
		memset(s, 0, sizeof(s));
		for(j = 0, i = 0; i < strlen(str); i++)
			if((str[i] > '0' && str[i] < '9') || str[i] == 'x') s[j++] = str[i];
		 if(IsOK(s))
		 {
            Init(s);
            Astar();
        }
        else printf("unsolvable\n");
    }
    return 0;
}