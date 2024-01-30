#include <iostream>
#include <string>

using namespace std;

struct Passenger {
    string name;
    Passenger* next;
};

struct Flight {
    string name;
    Passenger* passengers;
    Flight* next;
};

Flight* flights = NULL;

void reserveTicket() {
    string flightName, passengerName;
    cout << "Enter flight name: ";
    cin >> flightName;
    cout << "Enter passenger name: ";
    cin >> passengerName;
    
    Flight* f = flights;
    while (f != NULL && f->name != flightName) {
        f = f->next;
    }
    if (f == NULL) {
        f = new Flight;
        f->name = flightName;
        f->passengers = NULL;
        f->next = flights;
        flights = f;
    }
    
    Passenger* p = new Passenger;
    p->name = passengerName;
    p->next = f->passengers;
    f->passengers = p;
    
    cout << "Reservation successful." << endl;
}

void cancelReservation() {
    string flightName, passengerName;
    cout << "Enter flight name: ";
    cin >> flightName;
    cout << "Enter passenger name: ";
    cin >> passengerName;
    
    Flight* f = flights;
    while (f != NULL && f->name != flightName) {
        f = f->next;
    }
    if (f == NULL) {
        cout << "Flight not found." << endl;
        return;
    }
    
    Passenger* prev = NULL;
    Passenger* p = f->passengers;
    while (p != NULL && p->name != passengerName) {
        prev = p;
        p = p->next;
    }
    if (p == NULL) {
        cout << "Passenger not found." << endl;
        return;
    }
    
    if (prev == NULL) {
        f->passengers = p->next;
    } else {
        prev->next = p->next;
    }
    delete p;
    
    cout << "Reservation cancelled." << endl;
}

void checkReservation() {
    string passengerName;
    cout << "Enter passenger name: ";
    cin >> passengerName;
    
    Flight* f = flights;
    bool found = false;
    while (f != NULL) {
        Passenger* p = f->passengers;
        while (p != NULL) {
            if (p->name == passengerName) {
                cout << "Passenger found on flight " << f->name << "." << endl;
                found = true;
                break;
            }
            p = p->next;
        }
        if (found) {
            break;
        }
        f = f->next;
    }
    if (!found) {
        cout << "Passenger not found on any flight." << endl;
    }
}

void sortList(Passenger* &head) {
    if (!head || !head->next) {
        return;
    }
    
    Passenger *curr = head;
    while (curr) {
        Passenger *min_node = curr;
        Passenger *temp = curr->next;
        while (temp) {
            if (temp->name < min_node->name) {
                min_node = temp;
            }
            temp = temp->next;
        }
        if (min_node != curr) {
            std::swap(curr->name, min_node->name);
        }
        curr = curr->next;
    }
}


void displayPassengers() {
    Flight* f = flights;
    while (f != NULL) {
        cout << "Flight " << f->name << ":" << endl;
        Passenger* p = f->passengers;
		sortList(p);
        while (p != NULL) {
            cout << "- " << p->name << endl;
            p = p->next;
        }
        f = f->next;
    }
}

int main() {
    int choice, option;
    while (true) {
        cout << "1. Reserve a ticket" << endl;
        cout << "2. Cancel a reservation" << endl;
        cout << "3. Check whether a ticket is reserved for a particular person" << endl;
        cout << "4. Display the passengers" << endl;
        
        cin >> option;

        switch (option) {
            case 1:
                reserveTicket();
                break;
            case 2:
            	cancelReservation();
                break;
            case 3:
                checkReservation();
                break;
            case 4:
            	displayPassengers();
                break;
            case 5:
            	return 0;
                break;
            default:
                cout << "Invalid option." << endl;
                break;
        }
	}
	return 0;
}

