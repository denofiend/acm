#include <iostream>
using namespace std;
int fi[30],di[30],ti[30],time[30],ff[30],tt[30];
const int PER = 5;
int n , h;
int main(){
	while(cin >> n)
	{
		if(!n)break;
		cin >> h;
		h = 12 * h;
		for(int i = 1;i <= n;++ i)
			cin >> fi[i];
		for(int j = 1;j <= n;++ j )
			cin >> di[j];
		ti[1] = 0;
		for(int k = 2;k <= n;++ k )
		{
			cin >> ti[k];
			ti[k] += ti[k - 1]; 
		}
		int max_fish = 0;
		for(int lks = n;lks > 0;-- lks)
		{
			for(int pos1 = 1;pos1 <= n; ++ pos1)
			{
				ff[pos1] = fi[pos1];
				time[pos1] = 0;
			}
			int pos, max = 0, t = h - ti[lks];
			while(t > 0)
			{
				pos = 1;
				for(int num1 = 1;num1 <= lks;++ num1)
				{
					if(ff[num1] > ff[pos])
						pos = num1;
				}
				if(ff[pos] == 0)
					break;
				time[pos] += PER;
				max += ff[pos];
				ff[pos] -= di[pos];
				if(ff[pos] <= 0)
					ff[pos] = 0;
				t --;
			}
			time[1] += t * PER;
			if(max > max_fish)
			{
				for(int w = 1;w <= n;++ w)
					tt[w] = time[w];
				max_fish = max;
			}
			else if(max == max_fish)
			{
				int w;
				for(w = 1;w <= n; ++ w)
					if(tt[w] <= time[w])
						break;
				if(w != n + 1)
					for(int r = 1;r <= n; ++ r)
						tt[r] = time[r];
			}
		}
		for(int s = 1;s < n; ++ s)
			cout << tt[s]<< ", " ;
		cout << tt[n] << endl;
		cout << "Number of fish expected: " << max_fish << endl << endl;
	}
	return 0;
}