#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Stack {
protected:
    int length = 0;

public:
    virtual void push(const string& value) = 0;
    virtual string pop() = 0;

    int getLength() const {
        return length;
    }

    virtual ~Stack() = default;
};

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

class DoublyLinkedListStack : public Stack {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedListStack() : head(nullptr), tail(nullptr) {}

    void push(const string& value) override {
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

    string pop() override {
        if (!tail) {
            return "";
        }

        Node* temp = tail;
        string tempValue = temp->getValue();

        tail = tail->getPrevious();

        if (tail) {
            tail->setNext(nullptr);
        } else {
            head = nullptr;
        }

        delete temp;
        length--;
        return tempValue;
    }

    ~DoublyLinkedListStack() {
        while (tail) {
            pop();
        }
    }
};

class ArrayStack : public Stack {
private:
    vector<string> arr;

public:
    void push(const string& value) override {
        arr.push_back(value);
        length++;
    }

    string pop() override {
        if (arr.empty()) {
            return "";
        }

        string val = arr.back();
        arr.pop_back();
        length--;
        return val;
    }
};

bool isParanthesesBalanced(
    const string& expression,
    char opening,
    char closing,
    Stack& stack
) {
    for (char c : expression) {
        if (c == opening) {
            stack.push(string(1, c));
        } else if (c == closing) {
            string popped = stack.pop();
            if (popped.empty()) {
                return false;
            }
        }
    }
    return stack.getLength() == 0;
}

bool areBracketsAndParanthesesBalanced(
    const string& expression,
    Stack& stack
) {
    return isParanthesesBalanced(expression, '[', ']', stack) &&
           isParanthesesBalanced(expression, '(', ')', stack);
}

int main() {
    string test = "[()]";

    DoublyLinkedListStack dllStack;
    cout << areBracketsAndParanthesesBalanced(test, dllStack) << endl;

    ArrayStack arrayStack;
    cout << areBracketsAndParanthesesBalanced(test, arrayStack) << endl;

    return 0;
}
