#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> A = {7, 10, 4, 3, 20, 15, 8, 17, 5, 1,5,34,5,65,7,5,7,5,6,5,4,32,54,6,7,8,67,6,5,4,,433,4,6,7,8,6,4,4,3};
    int k = 3;

    priority_queue<int, vector<int>, greater<int>> minHeap(A.begin(), A.end()); 

    for(int i = 0; i < k-1; i++) {
        minHeap.pop();
    }

    cout << minHeap.top() << endl;
}
