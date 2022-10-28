// https://blockdmask.tistory.com/338
// https://cplusplus.com/reference/string/string/insert/
// https://codingdog.tistory.com/entry/c-string-cstr-함수-string을-char-로-바꿔봅시다

#include <iostream>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <fstream>
using namespace std;
int n, k, m, r, t;
string f(int i, int len)
{
    string ans = "";
    while(len--)
    {
        ans.insert(0, 1, i%2 + 48);
        i = i / 2;
    }
    return ans;
}
int main()
{
    char cmd0[1000], cmd[1000];
    cout << "numofboxes: ";
    cin >> m;
    cout << "blocksize: ";
    cin >> n;
    cout << "keysize: ";
    cin >> k;
    cout << "rounds: ";
    cin >> r;
    cout << "testcase: ";
    cin >> t;
    // printf("%d %d %d %d %d ", n, m, k, r, t);
    sprintf(cmd0, "../automate/edit_lowmc.sh %d %d %d %d", m, n, k, r);
    system(cmd0);
    int M[200][200] = {0,}, C[200][200] = {0,};
    for(int j = 0; j < t; j++)
    {
        cout << "message" << j + 1 << ": ";
        for(int i = n - 1; i >= 0; i--)
        {
            scanf("%1d", &M[j][i]);
        }
        cout << "ciphertext" << j + 1 << ": ";
        for(int i = n - 1; i >= 0; i--)
        {
            scanf("%1d", &C[j][i]);
        }
    }

    printf("\n");
    time_t start = time(NULL);
    int j = 1;
    string cip, mes = "";
    for(int i = 1; i <= k; i++)
    {
        j *= 2;
    }
    int k_count;
    for(int i = 0; i < j; i++)
    {
        k_count = 0;
        for(int me = 0; me < t; me++)
        {
            mes = "";
            for(int y = n-1; y >= 0; y--)
            {
                mes.push_back(48 + M[me][y]);
            }
            cip = "";
            for(int y = n-1; y >= 0; y--)
            {
                cip.push_back(48 + C[me][y]);
            }
            // printf("%s %s\n", f(i, k).c_str(), mes.c_str());
            sprintf(cmd, "{ echo %s; echo %s; } | ../lowmc/LowMC > ciphertext.txt", f(i, k).c_str(), mes.c_str());
            system(cmd);
            ifstream input("ciphertext.txt");
            string cipher = "";
            input >> cipher;
            if(cipher != cip)
            {
                me = t;
            } else {
                k_count += 1;
            }
            if(k_count == t)
            {
                printf("%s\n", f(i, k).c_str());
                break;
            }
        }
    }
    time_t end1 = time(NULL);
    printf("소요시간: %lfmms\n", (double)(end1 - start));
    /**/
    return 0;
}