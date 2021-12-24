#include <bits/stdc++.h>
// #include <string.h>
// #include <iostream>
using namespace std;

void naive_algorithm(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();
    int i, j;

    for (i = 0; i <= n - m; i++) {
        for (j = 0; j < m; j++) {
            if (text[i + j] != pattern[j])
                break;
        }
        if (j == m)
            cout << "Found at index " << i << endl;
    }
}

int main() {
    string pattern, text;
    cout << "Enter text: ";
    cin >> text;
    cout << "Entern pattern to be searched: ";
    cin >> pattern;
    naive_algorithm(text, pattern);
    return 0;
}