#include <iostream>
#include <conio.h>
using namespace std;

#define N 4

void floyds(int b[][N])
{
    int i, j, k;
    for (k = 0; k < N; k++)
    {
        for (i = 0; i < N; i++)
        {
            for (j = 0; j < N; j++)
            {
                if ((b[i][k] * b[k][j] != 0) && (i != j))
                {
                    if ((b[i][k] + b[k][j] < b[i][j]) || (b[i][j] == 0))
                    {
                        b[i][j] = b[i][k] + b[k][j];
                    }
                }
            }
        }
    }
    for (i = 0; i < N; i++)
    {
        cout << "\nMinimum Cost With Respect to Node:" << i << endl;
        for (j = 0; j < N; j++)
        {
            cout << b[i][j] << "\t";
        }
    }
}
int main()
{
    int b[N][N];
    cout << "ENTER VALUES OF ADJACENCY MATRIX\n\n";
    for (int i = 0; i < N; i++)
    {
        cout << "enter values for " << (i + 1) << " row: " ;
        for (int j = 0; j < N; j++)
        {
            cin >> b[i][j];
        }
    }
    floyds(b);
    getch();
}