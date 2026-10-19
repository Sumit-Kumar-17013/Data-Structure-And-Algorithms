class MyLinkedList {
private:
    struct Node {
        int val;
        Node* next;

        Node(int x) {
            val = x;
            next = nullptr;
        }
    };

    Node* head;
    int length;

public:
    MyLinkedList() {
        head = nullptr;
        length = 0;
    }

    int get(int index) {
        if (index < 0 || index >= length)
            return -1;

        Node* curr = head;

        for (int i = 0; i < index; i++) {
            curr = curr->next;
        }

        return curr->val;
    }

    void addAtHead(int val) {
        Node* newNode = new Node(val);

        newNode->next = head;
        head = newNode;

        length++;
    }

    void addAtTail(int val) {
        Node* newNode = new Node(val);

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* curr = head;

            while (curr->next != nullptr) {
                curr = curr->next;
            }

            curr->next = newNode;
        }

        length++;
    }

    void addAtIndex(int index, int val) {
        if (index < 0 || index > length)
            return;

        if (index == 0) {
            addAtHead(val);
            return;
        }

        Node* curr = head;

        for (int i = 0; i < index - 1; i++) {
            curr = curr->next;
        }

        Node* newNode = new Node(val);

        newNode->next = curr->next;
        curr->next = newNode;

        length++;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= length)
            return;

        if (index == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;

            length--;
            return;
        }

        Node* curr = head;

        for (int i = 0; i < index - 1; i++) {
            curr = curr->next;
        }

        Node* temp = curr->next;
        curr->next = temp->next;

        delete temp;
        length--;
    }
};


/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */