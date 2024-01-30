#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int T;
    cout << "Enter the number of test cases: ";
    cin >> T;

    vector<int> N(T);
    vector<vector<int> > scores(T);
    for (int i = 0; i < T; i++) {
        cout << "Enter the value of N for test case #" << i + 1 << ": ";
        cin >> N[i];

        cout << "Enter the scores of students for test case #" << i + 1 << ": ";
        for (int j = 0; j < N[i]; j++) {
            int val;
            cin >> val;
            scores[i].push_back(val);
        }
    }

    for (int i = 0; i < T; i++) {
        stack<int> st;
        int total_punishment = 0;

        for (int j = 0; j < N[i]; j++) {
            if (scores[i][j] > 33) {
                if (!st.empty() && scores[i][j] < st.top()) {
                    continue;
                } else {
                    st.push(scores[i][j]);
                }
            } else {
                if (!st.empty()) {
                    int top_score = st.top();
                    st.pop();
                    total_punishment += top_score;
                }
            }
        }

        cout << "Total punishment for test case #" << i + 1 << ": " << total_punishment << endl;
    }

    return 0;
}
