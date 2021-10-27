    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    int *arr = new int[n];
    cout << "Enter " << n*n << " elements in the array: ";

    for (int i=0; i<n; i++)
        cin >> arr[i];