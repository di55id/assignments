#include <iostream>
#include <queue>
#include <stack>
using namespace std;

bool checkSorted(int n, queue<int>& q)
{
    stack<int> stck;
    queue<int> q2;
    int required_front = 1;
    int frnt_elem;
 
    while (!q.empty()) {
        frnt_elem = q.front();
        q.pop();
 
        if (frnt_elem == required_front) {
        	required_front++;
            q2.push(frnt_elem);
		}
 
        else {
            if (stck.empty()) {
                stck.push(frnt_elem);
            }
            
            else if (!stck.empty() && stck.top() < frnt_elem) {
                return false;
            }
 
            else
                stck.push(frnt_elem);
        }
 
        while (!stck.empty() && stck.top() == required_front) {
            q2.push(stck.top());
            stck.pop();
            required_front++;
        }
    }
 
    if (required_front - 1 == n && stck.empty()) {
        cout << "Sorted queue: ";
        while(q2.front()) {
        	cout << q2.front() << " ";
        	q2.pop();
		}
		cout << endl;
		
		return true;
	}
 
    return false;
}

int main()
{
    int T;
    cout << "Enter sample cases: \n";
    cin >> T;
    while (T--) {
        int N;
        cout << "Enter number of elements: \n";
        cin >> N;
        queue<int> q;
        for (int i = 0; i < N; i++) {
            cout << "Enter element " << i+1 << endl;
            int x;
            cin >> x;
            q.push(x);
        }
        cout << (checkSorted(N, q) ? "YES" : "NO") << endl;
    }
    return 0;
}
