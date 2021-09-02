#include<bits/stdc++.h>
using namespace std;

void insertionSort(vector<int> &arr, int n) {
	// select element and place it at its correct position
	for(int i=0;i<n;i++){
		int j = i;
		while(j>0 && arr[j]<arr[j-1]){
			swap(arr[j],arr[j-1]);
			j--;
		}
	}
	return ;
}

int main() {
	// cout<<"\t\t\t\t\tInsertion Sort\n\n";
	int n;
	cout<<"Enter number of elements in array: ";
	cin >> n;
	vector<int> arr(n);
	cout<<"\nEnter the elements of array: ";
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}

	cout << "\nUnsorted array is: ";
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}

	insertionSort(arr, n);

	cout << "\nSorted array is: ";
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}

	// cout<<"\n\nShubham Jindal\nCSE-A\n40";

	return 0;
}
