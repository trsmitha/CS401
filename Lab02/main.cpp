#include <iostream>
using namespace std;

class Node {
    private:
        string value;
        Node next;
        Node previous;

    public:
        Node(string value){
            this.value = value;
        }

        string getValue(){
            return this.value;
        }

        string setValue(string value){
            // Do any filtering of outside value here
            this.value = value;
        }

        Node getNext(){
            return this.next;
        }

        void setNext(Node newNext){
            this.next = newNext;
        }

        Node getPrevious(){
            return this.previous;
        }

        void setPrevious(Node newPrevious){
            this.next = newPrevious;
        }
}

class DoublyLinkedListStack {
    private:
        Node head;
        Node tail;

        int length = 0;
    
    public:
        void push(string value){
            if (!this.head) {
                this.head = Node(value);
                this.tail = this.head;
                this.head.next = this.tail;
                this.tail.previous = this.head;
            }
            else{
                this.tail.next = Node(value);
                this.tail.next.previous = this.tail;
            }
            this.length += 1;
        }

        Node pop(){
            if (!this.head){
                return
            }
            else{
                this.tail.previous.next = nullptr;
                temp = this.tail;
                this.tail = this.tail.previous;
                this.length -= 1;
                return temp;
            }
        }
}

bool isParanthesesBalanced(char[] beginningParantheses, char[] endingParantheses, string expression){
    DoublyLinkedListStack stack = DoublyLinkedListStack();

    for (char c : expression){
        if (find(begin(beginningParantheses),end(beginningParantheses),c) != end(beginningParantheses)){
            stack.push(string c);
        }
        else if (find(begin(endingParantheses),end(endingParantheses),c) != end(endingParantheses)){
            delete(stack.pop());
        }
    }

    return stack.length == 0;
}

bool areBracketsAndParanthesesBalanced(string expression){
    return isParanthesesBalanced({'['},{']'},expression) && isParanthesesBalanced({'('},{')'},expression);
}