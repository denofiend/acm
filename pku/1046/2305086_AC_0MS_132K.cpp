#include <iostream>
using namespace std ;
int main(){
	double target[16][3] ;
	for( int i = 0 ; i < 16 ; i ++ )
		for( int j = 0 ; j < 3 ; j ++ )
			cin >> target[i][j] ;
	double R, G, B ;
	while( cin >> R >> G >> B )
	{
		if( R == - 1 && G == - 1 && B == - 1 )
			break ;
		double min = 0.0 ;
		min += ( target[0][0] - R ) * ( target[0][0] - R ) ;
		min += ( target[0][1] - G ) * ( target[0][1] - G ) ;
		min += ( target[0][2] - B ) * ( target[0][2] - B ) ;
		double dm = 0.0 , TargetR = target[0][0], TargetG = target[0][1] , TargetB = target[0][2] ;
		for( int i1 = 0 ;i1 < 16 ;i1 ++ )
		{
			dm = 0.0 ;
			dm += ( target[i1][0] - R ) * ( target[i1][0] - R ) ;
			dm += ( target[i1][1] - G ) * ( target[i1][1] - G ) ;
			dm += ( target[i1][2] - B ) * ( target[i1][2] - B ) ;
			if( dm < min )
			{
				TargetR = target[i1][0] , TargetG = target[i1][1] , TargetB = target[i1][2] ;
				min = dm ;
			}
		}
		cout << "(" << R << "," << G << "," << B << ") maps to (" << TargetR << "," << TargetG << "," << TargetB << ")" << endl  ;
	}
	return 0 ;
}