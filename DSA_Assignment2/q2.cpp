#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int max_balls(int N, int K, vector<int>& A) {
    priority_queue<int> pq;
    for (int a : A) {
        pq.push(a);
    }

    int total = 0;
    for (int i = 0; i < K; i++) {
        int balls = pq.top();
        pq.pop();
        total += balls;
        pq.push(balls / 2);
    }

    return total;
}

int main() {
    int T;
    cout << "Enter the number of test cases: ";
    cin >> T;

    vector<int> N(T), K(T);
    vector<vector<int> > A(T);
    for (int i = 0; i < T; i++) {
        cout << "Enter the value of N and K for test case #" << i + 1 << ": ";
        cin >> N[i] >> K[i];

        cout << "Enter the elements of array A for test case #" << i + 1 << ": ";
        for (int j = 0; j < N[i]; j++) {
            int val;
            cin >> val;
            A[i].push_back(val);
        }
    }

    for (int i = 0; i < T; i++) {
        cout << "Maximum number of balls for test case #" << i + 1 << ": " << max_balls(N[i], K[i], A[i]) << endl;
    }

    return 0;
}
