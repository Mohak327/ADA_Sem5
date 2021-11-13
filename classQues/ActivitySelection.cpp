#include<bits/stdc++.h>
using namespace std;
#define int long long

bool compare(pair<int,int> t1, pair<int,int> t2) {
    if(t1.second == t2.second) {
        t1.first < t2.first;
    }

    return t1.second < t2.second;
}

signed main() {
    int n; cin >> n;

    vector<pair<int,int>> times;
    for(int i=0; i<n; i++) {
        int st, fn;
        cin >> st >> fn;

        times.push_back({st,fn});
    }

    sort(times.begin(), times.end(), compare);

    int ans = 1;
    int previousEndTime = times[0].second;

    for(int i=1; i<n; i++) {
        if(times[i].first >= previousEndTime) {
            ans++;
            previousEndTime = times[i].second;
        }
    }

    cout << ans << endl;
    return 0;
}
