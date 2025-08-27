#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> A = {7, 10, 4, 3, 20, 15, 8, 17, 5, 1};
    int k = 3;

    priority_queue<int, vector<int>, greater<int>> minHeap(A.begin(), A.end()); 

    for(int i = 0; i < k-1; i++) {
        minHeap.pop();
    }

    cout << minHeap.top() << endl;
}

