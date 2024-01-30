#include <iostream>
#include <string>
using namespace std;

struct Node {
    string data;
    Node* next;
    Node(string s) : data(s), next(NULL) {}
};

void printLines(Node* head) {
    Node* curr = head;
    while (curr) {
        cout << curr->data << endl;
        curr = curr->next;
    }
}

void addLine(Node*& head, string line, int n) {
    Node* newNode = new Node(line);
    int i = 1;
    if (!head) {
        head = newNode;
    } else {
        Node* curr = head;
    	while (curr && i != n) {
        	curr = curr->next;
        	i++;
    }
    	Node* temp = curr->next;
        curr->next = newNode;
        newNode->next = temp;
    }
}

void deleteLine(Node*& head, int n) {
    if (!head) {
        cout << "Error: list is empty!" << endl;
        return;
    }
    Node* curr = head;
    Node* prev = NULL;
    int i = 1;
    while (curr && i != n) {
        prev = curr;
        curr = curr->next;
        i++;
    }
    if (!curr) {
        cout << "Error: line not found!" << endl;
        return;
    }
    if (!prev) {
        head = curr->next;
    } else {
        prev->next = curr->next;
    }
    delete curr;
}

void editLine(Node* head, int n, string line) {
    Node* curr = head;
    int i = 1;
    while (curr && i != n) {
        curr = curr->next;
        i++;
    }
    if (!curr) {
        cout << "Error: line not found!" << endl;
        return;
    }
    curr->data = line;
}

void swapLines(Node* head, int n, int m) {
    if (n == m) {
        return;
    }
    Node* node1 = head;
    Node* prev1 = NULL;
    int i = 1;
    while (node1 && i != n) {
        prev1 = node1;
        node1 = node1->next;
        i++;
    }
    if (!node1) {
        cout << "Error: line not found!" << endl;
        return;
    }
    Node* node2 = head;
    Node* prev2 = NULL;
    i = 1;
    while (node2 && i != m) {
        prev2 = node2;
        node2 = node2->next;
        i++;
    }
    if (!node2) {
        cout << "Error: line not found!" << endl;
        return;
    }
    if (prev1) {
        prev1->next = node2;
    } else {
        head = node2;
    }
    if (prev2) {
        prev2->next = node1;
    } else {
        head = node1;
    }
    Node* temp = node1->next;
    node1->next = node2->next;
    node2->next = temp;
}

int main() {
    Node* head = NULL;
    int choice, n, m, option, lineNumber;
    string newLine, s;
    while (true) {
        cout << "\nText Editor Menu\n";
        cout << "1. Print all lines\n";
        cout << "2. Add a new line\n";
        cout << "3. Delete a line\n";
        cout << "4. Edit a line\n";
        cout << "5. Swap lines\n";
        cout << "6. Exit\n";
        cout << "Enter your choice\n";
        
        cin >> option;

        switch (option) {
            case 1:
                printLines(head);
                break;
            case 2:
            	cout << "Enter the line number: ";
            	cin >> lineNumber;
                cout << "Enter the new line: ";
                getline(cin, s);
                getline(cin, newLine);
				addLine(head, newLine, lineNumber);
                break;
            case 3:
                cout << "Enter line number to delete: ";
                cin >> lineNumber;
                deleteLine(head, lineNumber);
                break;
            case 4:
            	cout << "Enter the line no. to be modified: ";
            	cin >> lineNumber;
            	cout << "Enter the new line: ";
                getline(cin, s);
                getline(cin, newLine);
            	editLine(head, lineNumber, newLine);
                break;
            case 5:
            	cout << "Enter line numbers to be swapped: ";
            	cin >> n >> m;
            	swapLines(head, n, m);
                break;
            case 6:
            	return 0;
                break;
            default:
                cout << "Invalid option." << endl;
                break;
        }
	}
	return 0;

}
