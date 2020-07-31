

#include <iostream>
using namespace std;

const unsigned int M = 490001; 
#define NIL -1
#define SWAP(x,y)  (x)^=(y)^=(x)^=(y)

int dir[4][2] = {
  1, 0, // D
 -1, 0, // U
  0,-1, // L
  0, 1  // R  
};

int  revDir[4] = { 1, 0, 3, 2 };
char dirStr[] = {"dulr"};
char solution[M];

typedef struct Node{
	 int v;		// 状态原值 
	int r;		// 到下一状态值的变化方向
}Node;

Node Hash_s[M], Hash_e[M];
Node Q_s[M], Q_e[M];
int  Qs_h, Qs_t, Qe_h, Qe_t;
Node ns, ne;
int  cnt[100];

inline int hashcode(int v){
 return v % M;
}

bool Insert(Node hash[], const Node &nod){
	int key = hashcode(nod.v);
	if (0 == hash[key].v)
	{
		hash[key] = nod;
		return true;
	}
	else
	{
		if (hash[key].v == nod.v)
			return false;
		while (hash[ hashcode(++key) ].v);
			hash[ hashcode(key)] = nod;
		return true;
	}
}

// false / true : Not / Yes exist in the hash table
// if Yes, theNod return the existed Node
Node * Query(Node hash[], const Node &nod){
	int key = hashcode(nod.v);
	if (0 == hash[key].v)
	{
		return NULL;
	}
	else
	{
		if (hash[key].v == nod.v)
		{
			return &hash[key];
		}
		while( hash[ hashcode(++key) ].v ) 
		{
			if( hash[ hashcode(key)].v == nod.v )
			{
				return &hash[key];
			}
		}
		return NULL;
	}
}

int ToArry(int v, int (*p)[3]){ 
	int i, pos;
	for (i = 8; i >= 0; i--) 
	{
		p[ i / 3 ][ i % 3 ] = v % 10;
		v /= 10;
		if (p[ i / 3 ][ i % 3 ] == 0)
		pos = i;
	} 
	return pos; // 'x' 的位置
}

int ToValue(int (*p)[3]){
	int v = 0;
	for(int i=0; i<=8; i++) 
	{
		v = v * 10 + p[ i / 3 ][ i % 3 ];
	} 
	return v;
}

void GetOptimPath(int arr[], Node hash[], Node curNod, bool starToEnd, int &nIndex)
{
 Node *pNod; 
 int curArr[3][3];
 for( ; curNod.r != NIL; )
 {
  cnt[nIndex++] = starToEnd ? curNod.r : revDir[curNod.r];
  const int loca = ToArry(curNod.v, curArr); 
  int row = loca / 3;
  int col = loca % 3;
  int nxtrow = row + dir[revDir[curNod.r]][0];
  int nxtcol = col + dir[revDir[curNod.r]][1];
  SWAP(curArr[row][col], curArr[nxtrow][nxtcol]);
  int nxtv = ToValue(curArr);
  curNod.v = nxtv;
  pNod = Query(hash, curNod);
  curNod.r = pNod->r;  
 }
}

void bfs(){
	Qs_h = Qs_t = 0;
	Qe_h = Qe_t = 0;
	Q_s[Qs_t++] = ns;
	Q_e[Qe_t++] = ne;
	Insert(Hash_s, ns);
	Insert(Hash_e, ne);

	int nIndex = 0;
	int now;
	Node curNod, nxtNod;
	int  curArr[3][3], nxtArr[3][3];
	while (1)
	{
		if ((Qs_h == Qs_t || Qe_h == Qe_t))
			break;
		now = Qs_t;
		while (Qs_h < now)
		{
			curNod = Q_s[Qs_h++];
			const int loca = ToArry(curNod.v, curArr);
			int row = loca / 3;
			int col = loca % 3;
			for(int i=0; i<4; i++)
			{
				memcpy(nxtArr, curArr, sizeof(curArr));
				int nxtrow = row + dir[i][0];
				int nxtcol = col + dir[i][1];
				if( !( nxtrow >= 0 && nxtrow < 3 && nxtcol >= 0 && nxtcol < 3 ) ) continue;
				   SWAP(nxtArr[row][col], nxtArr[nxtrow][nxtcol]);
				int nxtv = ToValue(nxtArr);
				nxtNod.v = nxtv;
				nxtNod.r = i;
				if( Query( Hash_e, nxtNod) != NULL ){ // find the solution
				 Node commNod(nxtNod); 
				 GetOptimPath(cnt, Hash_s, commNod, true, nIndex);
				 for( int i=0; i < nIndex / 2; i++ )
				  SWAP(cnt[i], cnt[nIndex-1-i]);
				 commNod = *Query(Hash_e, nxtNod); 
				 GetOptimPath(cnt, Hash_e, commNod, false, nIndex);
				 goto Solved;
				}
				if( Insert( Hash_s, nxtNod) )
				{
				 Q_s[Qs_t++] = nxtNod;
				}
			}
		}
		now = Qe_t;
		while( Qe_h < now ){
		curNod = Q_e[Qe_h++];
		const int loca = ToArry(curNod.v, curArr); 
		int row = loca / 3;
		int col = loca % 3;
		for(int i=0; i<4; i++){
		memcpy(nxtArr, curArr, sizeof(curArr));
		int nxtrow = row + dir[i][0];
		int nxtcol = col + dir[i][1];
		if( !( nxtrow >= 0 && nxtrow < 3 && nxtcol >= 0 && nxtcol < 3 ) ) continue;
		SWAP(nxtArr[row][col], nxtArr[nxtrow][nxtcol]);
		int nxtv = ToValue(nxtArr);
		nxtNod.v = nxtv;
		nxtNod.r = i;
		if( Query( Hash_s, nxtNod) != NULL ){ 
		 Node commNod(nxtNod); 
		 GetOptimPath(cnt, Hash_e, commNod, false, nIndex);
		 for( int i = 0; i < nIndex / 2; i++ )
		  SWAP(cnt[i], cnt[nIndex-1-i]);
		 commNod = *Query(Hash_s, nxtNod); 
		 GetOptimPath(cnt, Hash_s, commNod, true, nIndex);
		 for( i = 0; i < nIndex / 2; i++ )
		  SWAP(cnt[i], cnt[nIndex-1-i]);
		 goto Solved;  
	}
	if( Insert( Hash_e, nxtNod) ){
	 Q_e[Qe_t++] = nxtNod;
	}
	}
	}
	}
	Solved: 
	int i=0;
	for (i =0; i <nIndex; i++) 
	{
		solution[i] = dirStr[cnt[i]];
	}
	solution[i] = '\0';
	return; 
}

void Input(){
	char ch;
	int i = 0, arr[3][3] = {1,2,3,4,5,6,7,8,0};
	ne.v = ToValue(arr);
	ne.r = NIL;
	for (i = 0; i < 9; i++)
	{
		do
		{
			scanf("%c", &ch); 
		}
		while( !( ( ch >= '1' && ch <= '8' ) || ( ch == 'x' ) ) ) ;  
		if (ch == 'x') 
			arr[ i / 3 ][ i % 3 ] = 0;
		else 
			arr[ i / 3 ][ i % 3 ] = ch - '0';
	}
	ns.v = ToValue(arr);
	ns.r = NIL;
}

int main(){
	Input();
	bfs();
	printf("%s\n", solution);
	return 0;
}