#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};
typedef Node* StackNode;

StackNode newNode(int data) {
    StackNode stackNode = new Node();
    stackNode->data = data;
    stackNode->next = NULL;
    return stackNode;
}

void push(StackNode* root, int new_data) {
    StackNode stackNode = newNode(new_data);
    stackNode->next = *root;
    *root = stackNode;
}

void pop(StackNode* root) {
    if (!(*root))
        return;
    StackNode temp = *root;
    *root = (*root)->next;
    delete temp;
}

void process(StackNode* root)
{
    StackNode temp = NULL;
    if (*root == nullptr) {
        cout << "Stack is empty\n";
        return;
    }
    while ((*root)->data % 2 == 0) {
        pop(&*root);
        if (*root == nullptr)
            return;
    }
    temp = *root;
    while (temp->next != nullptr) {
        if (temp->next->data % 2 == 0) {
            pop(&(temp->next));
        }
        else {
            temp = temp->next;
        }
    }
}

void View(StackNode root)
{
    StackNode temp = root;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    StackNode root = NULL;
    int n, input;

    cout << "Enter amount of elements(int > 0):" << endl;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Element number " << i + 1 << " is: \n";
        cin >> input;
        push(&root, input);
    }

    cout << "The stack was:\n";
    View(root);
    cout << endl;

    process(&root);

    cout << "The stack is:\n";
    View(root);

    while (root != nullptr) {
        pop(&root);
    }

    return 0;
}