//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


int main(){
    string input;
    int t = 1;
    for (;cin >> input;)
    {
        vector<string> decode;
        if ('9' == input[0])    continue;
        decode.push_back(input);
        while (cin >> input)
        {
            if ('9' == input[0])    break;
            decode.push_back(input);
        }
        sort(decode.begin(), decode.end());
        int n = decode.size(), flag = 1;
        for (int i = 0; i < n - 1 && flag; i ++)
        {
            int k;
            for (k = 0; k < decode[i].size(); k++)
                if (decode[i][k] != decode[i + 1][k])
                {
                    break;
                }

            if (k == decode[i].size())    flag = 0;
        }
        if (flag)   cout << "Set " << t++ << " is immediately decodable" << endl;
        else cout << "Set " << t++ << " is not immediately decodable" << endl;
    }
    return 0;
}
