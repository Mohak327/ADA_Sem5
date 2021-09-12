#include <bits/stdc++.h>
using namespace std;

void swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
}

int partition (vector<int> &arr, int low, int high) {
    int pivot = arr[high]; // pivot
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// arr[] --> Array to be sorted,
// low --> Starting index,
// high --> Ending index

void quickSort(vector<int> &arr, int low, int high) {
    if (low < high) {
        // pi - partitioning index
        int pi = partition(arr, low, high);

        // Separately sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(vector<int> &arr, int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int n;
	cout<<"\n";
	cout<<"Enter number of elements in array: ";
	cin >> n;
	vector<int> arr(n);
	cout<<"Enter the elements of array: ";
	for(int i=0;i<n;i++) {
		cin>>arr[i];
	}

	cout << "Unorted array: ";
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    printArray(arr, n);

	cout<<"\n\n";
    return 0;
}