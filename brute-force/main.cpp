<<<<<<< HEAD
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <process.h>
#include <fstream>
using namespace std;
int n, k, m, r, t;
int f(int i);
{
    string ans = "";
    while(i > 0)
    {
        ans = strcat((char)(i % 2), ans);
        i = i / 2;
    }
    return ans;
}
int main()
{
    char cmd[1000];
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
    time_t start = time(NULL);
    int j = 1, k=0;
    string cip, mes = "";
    for(int i = 1; i <= n; i++)
    {
        j *= 2;
    }
    for(int i = 0; i < j; i++)
    {
        k = 0;
        for(int me = 0; me < t; me++)
        {
            mes = "";
            for(int y = 0; y < m; y++)
            {
                mes = strcat(mes, (char)(M[me][y]));
            }
            cip = "";
            for(int y = 0; y < m; y++)
            {
                cip = strcat(cip, (char)(C[me][y]));
            }
            sprintf(cmd, "c:\\Users\\user\\Desktop\\RnE\\ANFConv\\.cpp %d %s", mes, f(i));
            system(cmd);
            ifstream input(".txt");
            string cipher = "";
            input >> cipher;
            if(cipher != cip)
            {
                me = t;
                k += 1;
            }
            if(k == t)
            {
                print("%s\n", f(i));
                break;
            }
        }
    }
    time_t end1 = time(NULL);
    printf("�ҿ�ð�: %lfmms\n", (double)(end1 - start));
    return 0;
}
=======
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <process.h>
#include <fstream>
using namespace std;
int n, k, m, r, t;
int f(int i);
{
    string ans = "";
    while(i > 0)
    {
        ans = strcat((char)(i % 2), ans);
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
    time_t start = time(NULL);
    int j = 1, k=0;
    string cip, mes = "";
    for(int i = 1; i <= n; i++)
    {
        j *= 2;
    }
    for(int i = 0; i < j; i++)
    {
        k = 0;
        for(int me = 0; me < t; me++)
        {
            mes = "";
            for(int y = 0; y < m; y++)
            {
                mes = strcat(mes, (char)(M[me][y]));
            }
            cip = "";
            for(int y = 0; y < m; y++)
            {
                cip = strcat(cip, (char)(C[me][y]));
            }
            sprintf(cmd, "{ echo %s; echo %s; } | ../lowmc/LowMC > ciphertext.txt", f(i), mes);
            system(cmd);
            ifstream input("ciphertext.txt");
            string cipher = "";
            input >> cipher;
            if(cipher != cip)
            {
                me = t;
                k += 1;
            }
            if(k == t)
            {
                print("%s\n", f(i));
                break;
            }
        }
    }
    time_t end1 = time(NULL);
    printf("소요시간: %lfmms\n", (double)(end1 - start));
    return 0;
}
>>>>>>> Add brute-force cpp code Yuseong sent me via KakaoTalk
