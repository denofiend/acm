//

#include <iostream>
#include <map>

using namespace std;

int main(){
    int n, m;
    map<long long, int> hash;
    while (EOF != scanf("%d%d", &n, &m))
    {
        hash.clear();
        int i;
        long long nn;
        for (i = 0; i < n; i ++)
        {
            scanf("%I64d", &nn);
            if (hash.end() == hash.find(nn))
            {
                hash[nn] = 1;
            }
        }
        for (i = 0; i < m; i ++)
        {
            scanf("%I64d", &nn);
            if (hash.end() == hash.find(nn))
            {
                printf("no\n");
            }
            else
            {
                printf("yes\n");
            }
        }
    }
    return 0;
}
