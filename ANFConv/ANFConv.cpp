#include <iostream>
#include <stdio.h>
#include <vector>
// #include <process.h>
#include <fstream>

using namespace std;

int n, k, m, r, t;
int Lmatrix[24][256][256], roundconstant[24][256], Kmatrix[25][256][256];

struct Clause
{
    int var1;
    int var2;
    int sign;
};

vector <Clause> xr[100001], fka[100001];

void FirstKeyAddition()
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= k; j++)
        {
            if(Kmatrix[0][i][j])
            {
                fka[i].push_back({-j, -1, 1});
            }
        }
    }
}
void Sbox(int round)
{
    int i;
    for(i = round*n + 1; i <= round*n + m*3; i++)
    {
        if((i-round*n) % 3 == 1)
        {
            xr[i].push_back({i+2, -1, 1});
            xr[i].push_back({i+1, -1, 1});
            xr[i].push_back({i, -1, 1});
            xr[i].push_back({i+1, i+2, 1});
        }
        else if((i-round*n) % 3 == 2)
        {
            xr[i].push_back({i, -1, 1});
            xr[i].push_back({i+1, -1, 1});
            xr[i].push_back({i-1, i+1, 1});
        }
        else
        {
            xr[i].push_back({i, -1, 1});
            xr[i].push_back({i-2, i-1, 1});
        }
    }
    for(int j = i; j <= n*(round+1); j++)
    {
        xr[j].push_back({j, -1, 1});
    }
}

void LinearLayer(int round)
{
    int vsize[10001] = {0,}, check[10001] = {0,};
    for(int i = round*n + 1; i <= n*(round+1); i++)
    {
        vsize[i] = xr[i].size();
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(i == j)
            {
                if(!Lmatrix[round][i][j])
                {
                    ++check[round*n + i];
                }
                continue;
            }
            if(Lmatrix[round][i][j])
            {
                xr[round*n + i].insert(xr[round*n + i].end(), xr[round*n + j].begin(), xr[round*n + j].begin() + vsize[round*n + j]);
            }
        }
    }
    for(int i = round*n + 1; i <= n*(round+1); i++)
    {
        if(check[i])
        {
            while(vsize[i]--)
            {
                xr[i].erase(xr[i].begin());
            }
        }
    }
}

void ConstantAddition(int round)
{
    for(int i = 1; i <= n; i++)
    {
        if(roundconstant[round][i])
        {
            xr[round*n + i].push_back({0, 0, 0});
        }
    }
}

void KeyAddition(int round)
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= k; j++)
        {
            if(Kmatrix[round + 1][i][j])
            {
                xr[round*n + i].push_back({-j, -1, 1});
            }
        }
    }
}

void Equate(int round)
{
    if(round > 0)
    {
        for(int i = (round-1)*n + 1; i <= round*n; i++)
        {
            xr[i].push_back({i + n, -1, 1});
            //xr[i].push_back({0, 0, 0});
        }
    }
    if(round == (r - 1))
    {
        for(int i = round*n + 1; i <= (round + 1)*n; i++)
        {
            xr[i].push_back({i - round*n, -1, -1});
            //xr[i].push_back({0, 0, 0});
        }
    }
}

void LowMC()
{
    FirstKeyAddition();
    for(int i = 0; i < r; i++)
    {
        Sbox(i);
        LinearLayer(i);
        ConstantAddition(i);
        KeyAddition(i);
        Equate(i);
    }
}

FILE *fp = fopen("ANF.txt", "w");

void print_helper(int var1, int var2, int sign, int flag, int con)
{
    if(flag)
    {
        if(!var1 && !var2 && !sign)
        {
            fprintf(fp, "1 + ");
        }
        else if(sign == -1)
        {
            fprintf(fp, "x(%d) + ", con + var1 + n*r); // It was C
        }
        else if(var2 < 0)
        {
            if(var1 > 0)
            {
                fprintf(fp, "x(%d) + ", con + var1);
            }
            else
            {
                fprintf(fp, "x(%d) + ", -var1 + (n*r + n*2)*t); // It was K
            }
        }
        else
        {
            fprintf(fp, "x(%d)*x(%d) + ", con + var1, con + var2);
        }
    }
    else
    {
        if(!var1 && !var2 && !sign)
        {
            fprintf(fp, "1");
        }
        else if(sign == -1)
        {
            fprintf(fp, "x(%d)", con + var1 + n*r); // It was C
        }
        else if(var2 < 0)
        {
            if(var1 > 0)
            {
                fprintf(fp, "x(%d)", con + var1);
            }
            else
            {
                fprintf(fp, "x(%d)", -var1 + (n*r + n*2)*t); // It was K
            }
        }
        else
        {
            fprintf(fp, "%d*%d", con + var1, con + var2);
        }
    }
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
    sprintf(cmd, "python ../ANFConv/Matrix_generator.py %d %d %d", n, k, r);
    system(cmd);
    ifstream inputfile1("Lmatrix.txt");
    for(int i = 0; i < r; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            for(int x = 1; x <= n; x++)
            {
                inputfile1 >> Lmatrix[i][j][x];
            }
        }
    }
    ifstream inputfile2("roundconstant.txt");
    for(int i = 0; i < r; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            inputfile2 >> roundconstant[i][j];
        }
    }
    ifstream inputfile3("Kmatrix.txt");
    for(int i = 0; i <= r; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            for(int x = 1; x <= k; x++)
            {
                inputfile3 >> Kmatrix[i][j][x];
            }
        }
    }
    LowMC();
    //fprintf(fp, "p %d\n", n*(r + 1) + k);
    for(int i = 1; i <= n*r; i++)
    {
        //printf("ANF %d\n", i);
        //printf("===========================================================================================\n");
        //fprintf(fp, "0|");
        for(int rec = 0; rec < t; rec++)
        {
            int con = rec*(r + 2)*n + n;
            for(int j = 0; j < xr[i].size(); j++)
            {
                if(j != xr[i].size() - 1)
                {
                    print_helper(xr[i][j].var1, xr[i][j].var2, xr[i][j].sign, 1, con);
                }
                else
                {
                    print_helper(xr[i][j].var1, xr[i][j].var2, xr[i][j].sign, 0, con);
                }
            }
            fprintf(fp, "\n");
        }
    }
    for(int i = 1; i <= n; i++)
    {
        //printf("ANF %d\n", i);
        //printf("===========================================================================================\n");
        //fprintf(fp, "0|");
        for(int rec = 0; rec < t; rec++)
        {
            int con = rec*(r + 2)*n + n;
            fprintf(fp, "x(%d) + ", i + con - n);
            for(int j = 0; j < fka[i].size(); j++)
            {
                fprintf(fp, "x(%d) + ", -fka[i][j].var1 + (n*r + n*2)*t);
            }
            fprintf(fp, "x(%d)\n", i + con);
        }
    }
    for(int j = 0; j < t; j++)
    {
        int con = j*(r + 2)*n + n;
        for(int i = 0; i < n; i++)
        {
            if(M[j][i] == 0)
            {
                fprintf(fp, "x(%d)\n", con + i + 1 - n);
            }
            else
            {
                fprintf(fp, "x(%d) + 1\n", con + i + 1 - n);
            }
            if(C[j][i] == 0)
            {
                fprintf(fp, "x(%d)\n", con + n*r + i + 1);
            }
            else
            {
                fprintf(fp, "x(%d) + 1\n", con + n*r + i + 1);
            }
        }
    }
    return 0;
}
