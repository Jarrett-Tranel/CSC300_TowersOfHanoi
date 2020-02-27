#include "Node.hpp"
class Stack
{
    private:
        Node* top;
        int elements;

    public:
        Stack();
        void push(int payload);
        int pop();
        int peek();
        bool isWin();
        void moveTo(Stack* to);
        void translateDisk(int payload);
        void displayTextual();
        void display();

};