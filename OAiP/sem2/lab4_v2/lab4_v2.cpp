#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

struct Queue {
    Node* head;
    Node* tail;
};

//в конец
void push_end(Queue *que, int data){
    Node* NewNode = new Node;
    NewNode->data = data;
    NewNode->next = NULL;
    if (que->head != NULL) {         //если очередь не пуста
        NewNode->prev = que->tail;
        que->tail->next = NewNode;
        que->tail = NewNode;
    } 
    else {                         //если очередь пуста
        NewNode->prev = NULL;
        que->head = que->tail = NewNode;
    }
}
//в начало
void push_start(Queue* que, int data) {
    Node* NewNode = new Node;
    NewNode->data = data;
    NewNode->prev = NULL;
    if (que->head != NULL) {         //если очередь не пуста
        NewNode->next = que->head;
        que->head->prev = NewNode;
        que->head = NewNode;
    }
    else {                         //если очередь пуста
        NewNode->next = NULL;
        que->head = que->tail = NewNode;
    }
}

void pop(Node** head) {
    if (!(*head)) {
        return ;
    }
    Node* temp = (*head);
    (*head) = (*head)->next;
    delete temp;
}

void process(Queue *que) {
    if (!que->head) {
        cout << "Queue is empty" << endl;
        return;
    }
    while (que->head->data % 2 == 0) {
        pop(&que->head);
        if (!que->head) return;
    }
    Node* temp = new Node;
    temp = que->head;
    while (temp->next != NULL) {
        if (temp->next->data % 2 == 0) {
            pop(&temp->next);
        }
        else {
            temp = temp->next;
        }
    }
}

void View(Node* head) {
    Node* node = head;
    while (node != nullptr) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

void Delete(Queue *que) {
    Node* temp;
    while (que->head) {
        temp = que->head->next;
        delete que->head;
        que->head = temp;
    }
}

void check(int& n) {
    while (!(cin >> n) || (cin.peek() != '\n') || n < 0) {
        cin.clear();
        while (cin.get() != '\n');
        cout << "Vvedi normal'no!" << "\n";
    }
}

int main()
{
    Queue Que = {NULL, NULL};
    int size = 0, el = 0;
    cout << "input size of queue (n > 0):\n";
    check(size);
    for (int i = 0; i < size; i++) {
        cout << "\ninput element number" << i+1 << ": ";
        check(el); 
        push_end(&Que, el);
    }
 
    View(Que.head);
    process(&Que);
    View(Que.head);
    Delete(&Que);
}


