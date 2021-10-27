#include<bits/stdc++.h>
using namespace std;

class Array {
  public:
    int binarysearch(int arr[], int item, int l, int r) {
        if (r >= l) {
            int mid = l + (r - l) / 2;

            // Item in middle
            if (arr[mid] == item)
                return mid;

            // Item in left sub-array
            if (arr[mid] > item)
                return binarysearch(arr, item, l, mid - 1);

            // Item in right sub-array
            return binarysearch(arr, item, mid + 1, r);
        }
        return -1;
    }
};

int main() {
    Array obj;

    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    int *arr = new int[n];
    cout << "Enter " << n << " elements in the array: ";

    for (int i=0; i<n; i++)
        cin >> arr[i];

    int item;
    cout << "Enter the element to be searched: ";
    cin >> item;

    int pos = obj.binarysearch(arr, item, 0, n-1);

    if(pos == -1)
     {   cout << "Element is not present in the array.";}
    else
    {    cout << "Element "<< item <<" is present at position " << pos;}
    return 0;
}