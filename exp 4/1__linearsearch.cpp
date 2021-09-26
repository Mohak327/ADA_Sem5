#include<bits/stdc++.h>
using namespace std;

class Array {
    public:
        int linearsearch(int arr[], int size, int item) {
            for (int i=0; i<size; i++) {
                if (arr[i]==item) {
                    int pos = i+1;
                    return (pos);
                }
            }
            return (-1);
        }
};

int main() {
    int item, n;
    Array obj;

    cout << "Enter the size of array: ";
    cin >> n;

    int *arr = new int[n];

    cout << "Enter the elements of array: ";
    for (int i=0; i<n; i++)
        cin >> arr[i];

    cout << "Enter the element to be searched: ";
    cin >> item;

    int pos = obj.linearsearch(arr, n, item);
    (pos == -1)
        ? cout << "Element is not present in the array."
        : cout << "Element "<< item <<" is present at position " << pos;

    return 0;
}