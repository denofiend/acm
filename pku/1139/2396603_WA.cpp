// 1139 (pku)
// 位运算符的应运

#include <iostream>
using namespace std ;
#define MASK1 1
#define MASK2 2
int room[101][101], reach[101], t, size, cat, mouse, mousecatched = 0 ;

void init(){
	for( int i = size; i -- ;  ) 
	{
		for( int j = size; j -- ; )
			room[i][j] = 0 ;
		reach[i] = 0 ;
	}
	mousecatched = 0 ;
}


void input( int mask ){
	int i, j ;
	while( cin >> i >> j && - 1 != i )
		room[i][j] |= mask ;
}
void catreach( int start ){
	reach[start] = 1 ;
	for( int j = size; j -- ; )
		if( ( room[start][j] & MASK2 ) && ! reach[j] )
			catreach( j ) ;
}

/*  we are visiting just rooms not visited by cat -> searching for cycle
    The source room don't mark as reachable; if we reach it -> cycle exist.
    If we have any door to cat-reachable room -> cat can catch mouse -> "Y" */

void mousereach( int start ){
	for( int j = size; j -- ; )
		if( ( room[start][j] & MASK1 ) && ! reach[j] )
		{
			reach[j] = 2 ;
			mousereach( j ) ;
		}
		else if( ( room[start][j] & MASK1 ) && ( 1 == reach[j] ) )
			mousecatched = 1 ;
}
int main(){
	cin >> t ;
	while( t -- )
	{
		cin >> size >> cat >> mouse ;
		init() ;
		input(MASK2) ;
		input(MASK1) ;
		catreach( cat ) ;
		mousereach( mouse ) ;
		if( mousecatched || 1 == reach[mouse] )
			cout << "Y " ;
		else
			cout << "N " ;
		if( 2 == reach[mouse] )
			cout << "Y" << endl ;
		else
			cout << "N" << endl ;
	}
	return 0 ;
}