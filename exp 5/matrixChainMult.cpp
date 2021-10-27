//Given the sequence {4, 10, 3, 12, 20, and 7}.

//The matrices have size
    // 4 x 10,
    // 10 x 3,
    // 3 x 12,
    // 12 x 20,
    // 20 x 7

// Find the optimal parenthesization of a chain of 5 matrices to be multiplied such that the number of scalar multiplication is minimized.


// #include<stdio.h>
// #include<limits.h>

// int m[10][10]={0},s[10][10]={0},l,k,i,j,q,p[8],n,min,d;

// void mat_ch(int);
// void optimal(int ,int);

//     void mat_ch(int n) {
//     for(d=1;d<n;d++) {
//         for(i=1;i<=n-d;i++){
//             j=i+d;
//             min=INT_MAX;
//             for(k=i;k<=j-1;k++) {
//                 q=m[i][k]+m[k+1][j]+ p[i-1] * p[k] * p[j];
//                 if(q<min) {
//                     min=q;
//                     s[i][j]=k;
//                 }
//                 m[i][j]=min;
//             }
//         }
//     }
// }

// void optimal(int i,int j) {
//     if(i==j) {
//         printf("A%d",i);
//     }
//     else {
//         printf("(");
//         optimal(i,s[i][j]);
//         optimal((s[i][j]+1),j);
//         printf(")");
//     }
// }

// int main() {
//     printf("enter the matrix size: ");
//     scanf("%d",&n);
//     printf("enter the matrix elements: ");
//     for(i=0;i<n;i++)
//         scanf("%d",&p[i]);
//     for(i=1;i<n;i++)
//         printf("A%d   %d * %d\n",i,p[i-1],p[i]);
//     mat_ch(n);
//     printf(" the M matrix\n");
//     for(i=0;i<=n;i++) {
//         for(j=0;j<=n;j++) {
//             if(i>j)
//                 printf("-\t ");
//             else
//                 printf("%d\t ",m[i][j]);
//         }
//         printf("\n");
//     }
//     printf(" the S matrix\n");
//     for(i=0;i<=n;i++) {
//         for(j=0;j<=n;j++) {
//             if(i>j)
//                 printf("-\t ");
//             else
//                 printf("%d\t ",s[i][j]);
//         }
//         printf("\n");
//     }
//     optimal(1,n);
//     printf(" \n Minimum Product = %d",m[1][n]);
//     return 0;
// }


#include<iostream>
#include<vector>
using namespace std;

vector < vector<int>> dp(100, vector<int>(100, 0));
int matrixChain(int arr[], int i, int j) {
	if (i == j)
		return 0;
	if (dp[i][j] != 0)
		return dp[i][j];
	int ans = 2147483647;
	for (int k = i; k < j; k++) {
		int a = matrixChain(arr, i, k) + matrixChain(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j];
		ans = min(ans, a);
	}
	dp[i][j] = ans;
	return ans;
}


int main() {
	int n = 6;
	int arr[] = {4, 10, 3, 12, 20, 7};
	cout << "Sizes of matrices are: \n";
	for(int i=0;i<n-1;i++){
		cout << '(' << arr[i] << ',' << arr[i+1] << ") ";
	}

	for(int i=0;i<n-1;i++){
		cout << '(' << arr[i] << ',' << arr[i+1] << ") ";
	}
	cout << "\n\nMinimum cost to multiply the given matrices: ";
	cout << matrixChain(arr, 1, n - 1);
	return 0;
}