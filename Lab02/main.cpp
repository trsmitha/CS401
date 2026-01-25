#include <iostream>
using namespace std;

class Node {
    private:
        string value;
        Node next;
        Node previous;

    public:

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

class LinkedListStack {
    private:
        Node head;
        Node tail;

        int length = 0;
    
    public:
        void push(string value){
            
        }
}