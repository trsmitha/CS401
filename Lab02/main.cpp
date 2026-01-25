#include <iostream>
#include <string>

using namespace std;

class Node {
private:
    string value;
    Node* next;
    Node* previous;

public:
    Node(string value) : value(value), next(nullptr), previous(nullptr) {}

    string getValue() {
        return value;
    }

    void setValue(string value) {
        this->value = value;
    }

    Node* getNext() {
        return next;
    }

    void setNext(Node* newNext) {
        next = newNext;
    }

    Node* getPrevious() {
        return previous;
    }

    void setPrevious(Node* newPrevious) {
        previous = newPrevious;
    }
};

class DoublyLinkedListStack {
private:
    Node* head;
    Node* tail;
    int length;

public:
    DoublyLinkedListStack() : head(nullptr), tail(nullptr), length(0) {}

    void push(string value) {
        Node* newNode = new Node(value);

        if (!head) {
            head = tail = newNode;
        } else {
            tail->setNext(newNode);
            newNode->setPrevious(tail);
            tail = newNode;
        }
        length++;
    }

    Node* pop() {
        if (!tail) {
            return nullptr;
        }

        Node* temp = tail;
        tail = tail->getPrevious();

        if (tail) {
            tail->setNext(nullptr);
        } else {
            head = nullptr;
        }

        length--;
        return temp;
    }

    int getLength() {
        return length;
    }
};

bool isParanthesesBalanced(string expression, char opening, char closing) {
    DoublyLinkedListStack stack;

    for (char c : expression) {
        if (c == opening) {
            stack.push(string(1, c));
        } else if (c == closing) {
            Node* popped = stack.pop();
            if (!popped) {
                return false;
            }
            delete popped;
        }
    }

    return stack.getLength() == 0;
}

bool areBracketsAndParanthesesBalanced(string expression) {
    return isParanthesesBalanced(expression, '[', ']') &&
           isParanthesesBalanced(expression, '(', ')');
}

int main() {
    string test = "[()]";
    cout << areBracketsAndParanthesesBalanced(test) << endl;
    return 0;
}
