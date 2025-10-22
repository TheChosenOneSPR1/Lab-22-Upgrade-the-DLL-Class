#include <iostream>
using namespace std;

const int MIN_NR = 10, MAX_NR = 99, MIN_LS = 5, MAX_LS = 20;

class DoublyLinkedList {
private:
    struct Node {
        int data;
        Node* prev;
        Node* next;
        Node(int val, Node* p = nullptr, Node* n = nullptr) {
            data = val; 
            prev = p;
            next = n;
        }
    };

    Node* head;
    Node* tail;

public:
    // constructor
    DoublyLinkedList() { head = nullptr; tail = nullptr; }
    void delete_pos(int pos) {
        if (pos < 0 || !head) return;
        Node* temp = head;
        int i = 0;
        while (temp && i < pos) {
            temp = temp->next;
            i++;
        }
        if (!temp) return;
        if (temp->prev) {
            temp->prev->next = temp->next;
        } else {
            head = temp->next;
        }
        if (temp->next) {
            temp->next->prev = temp->prev;
        } else {
            tail = temp->prev;
        }
        delete temp;
    }
    void push_back(int value) {
        Node* newNode = new Node(value);
        if (!tail)  // if there's no tail, the list is empty
            head = tail = newNode;
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void push_front(int value) {
        Node* newNode = new Node(value);
        if (!head)  
            head = tail = newNode;
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }
    void pop_front() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        if (head) 
            head->prev = nullptr;
         else 
            tail = nullptr;
        delete temp;
    }
    void pop_back() {
        if (!tail) return;
        Node* temp = tail;
        tail = tail->prev;
        if (tail) 
            tail->next = nullptr;
         else 
            head = nullptr;
        delete temp;
    }


    void insert_after(int value, int position) {
        if (position < 0) {
            cout << "Position must be >= 0." << endl;
            return;
        }

        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
            return;
        }

        Node* temp = head;
        for (int i = 0; i < position && temp; ++i)
            temp = temp->next;

        if (!temp) {
            cout << "Position exceeds list size. Node not inserted.\n";
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next)
            temp->next->prev = newNode;
        else
            tail = newNode; // Inserting at the end
        temp->next = newNode;
    }

    void delete_val(int value) {
        if (!head) return; // Empty list

        Node* temp = head;
        while (temp && temp->data != value)
            temp = temp->next;

        if (!temp) return; 

        if (temp->prev) {
            temp->prev->next = temp->next;
        } else {
            head = temp->next; 
        }

        if (temp->next) {
            temp->next->prev = temp->prev;
        } else { 
            tail = temp->prev; 
        }
        delete temp;
    }

    void print() {
        Node* current = head;
        if (!current) return;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void print_reverse() {
        Node* current = tail;
        if (!current) return;
        while (current) {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }

    ~DoublyLinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
    }
};

// Driver program
int main() {
    DoublyLinkedList list;
    int size = rand() % (MAX_LS-MIN_LS+1) + MIN_LS;

    for (int i = 0; i < size; ++i)
        list.push_back(rand() % (MAX_NR-MIN_NR+1) + MIN_NR);
    cout << "List forward: ";
    list.print();

    cout << "List backward: ";
    list.print_reverse();

    cout << "Deleting list, then trying to print.\n";
    list.~DoublyLinkedList();
    cout << "List forward: ";
    list.print();

    count << "\n--- JUST TESTING ---\n";
    DoublyLinkedList t;
    t.push_back(10);
    t.push_back(10);
    t.push_back(10);
    t.push_back(10);
    t.push_back(10);

    cout << "Start: ";
    t.print();

    t.pop_front();
    cout << "After pop_front: ";
    t.print();

    t.pop_back();
    cout << "After pop_back: ";
    t.print();

    t.delete_val(10);
    cout << "After delete_val(10): ";
    t.print();

    t.delete_pos(10);
    cout << "After delete_val(10) again: ";
    t.print();
      
    return 0;
}
