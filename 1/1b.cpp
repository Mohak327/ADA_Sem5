#include<bits/stdc++.h>
using namespace std;

int minElement(vector<int> &arr,int n,int i){
	int idx = i;
	int minE = arr[i];
	for(int j=i+1;j<n;j++){
		if(arr[j]<minE){
			minE = arr[j];
			idx = j;
		}
	}
	return idx;
}

void selectionSort(vector<int> &arr, int n) {
	// select min element and swap
	for(int i=0;i<n;i++){
		int idx = minElement(arr,n,i);
		swap(arr[i],arr[idx]);
	}
	return ;
}

int main() {
	cout<<"\t\t\t\t\t\tSelection Sort\n\n";
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
	
	selectionSort(arr, n);

	cout << "\nSorted array is: ";
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	
	cout<<"\n\nShubham Jindal\nCSE-A\n40";

	return 0;
}
