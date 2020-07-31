#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cctype>
using namespace std;

bool mycompare(char a, char b){
	char c, d;
	c = tolower(a);
	d = tolower(b);

	if (c == d)
		return (a < b);
    else
        return (c < d);
}

int main(){
    //freopen("a.in", "r", stdin);
	int n;
	scanf("%d", &n);
	while (n --)
	{
        char s[16];
        scanf("%s",s);
        int len = strlen(s);
        sort(s, s + len, mycompare);
        do
        {
            printf("%s\n", s);
        }
        while(next_permutation(s,s+len, mycompare));

	}
    return 0;
}
