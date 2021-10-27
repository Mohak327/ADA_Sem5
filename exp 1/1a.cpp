#include<bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int> &arr, int n) {
	for (int i = 0; i < n - 1; i++) {
		bool swaps = false;
		int j = 0;
		for (int j = 0; j < n - 1 - i; j++) {
			while (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
				swaps = true;
			}
		}
		if (!swaps)
			return ;
	}
	return ;
}

int main() {
	cout << "\t\t\t\t\t\t\tBubble Sort\n\n";
	int n;
	cout << "\nEnter number of elements in array: ";
	cin >> n;
	vector<int> arr(n);
	cout << "Enter the elements of array: ";
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	cout << "\nUnsorted array is: ";
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	bubbleSort(arr, n);

	cout << "\nSorted array is: ";
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << "\n\nShubham Jindal\nCSE-A\n40";

	return 0;
}
