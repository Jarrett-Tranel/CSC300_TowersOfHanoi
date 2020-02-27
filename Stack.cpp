#include "Stack.hpp"
#include <iostream>

Stack::Stack()
{
    this->top = 0;
    this->elements = 0;
}

void Stack::push(int payload)
{
    Node* n = new Node(payload);
    if(top)
    {
        n->setNextNode(top);
        this->top = n;
    }
    else
    {
        this->top = n;
    }
    this->elements++;
}

int Stack::pop()
{
    int valueToReturn = this->top->getPayload();
    Node* temp = this->top;
    top = top->getNextNode();
    temp->setNextNode(0);
    delete temp;
    this->elements--;
    return valueToReturn;
}

int Stack::peek()
{
    return this->top->getPayload();
}

void Stack::moveTo(Stack* destination)
{
    int hold =this->pop();
    //this->display();
    //std::cout<<hold;
    destination->push(hold);

}

void Stack::translateDisk(int payload)
{
    if(payload == 1)
    {
        std::cout<<"   $\n";
    }
    else if(payload == 2)
    {
        std::cout<<"  $ $\n";
    }
    else if(payload == 3)
    {
        std::cout<<" $ $ $\n";
    }
    else
    {
        std::cout<<"Payload out of range";
    }
}

bool Stack::isWin()
{
    return false;
}

void Stack::displayTextual()
{
    if(this->elements == 0)
    {
        std::cout<<"\n\n\n********\n\n";
    }
    else if(this->elements == 1)
    {
        std::cout<<"\n\n";
        translateDisk(this->top->getPayload());
        std::cout<<"********\n\n";
    }
    else if(this->elements == 2)
    {
        std::cout<<"\n";
        Node* traverse = this->top;
        translateDisk(traverse->getPayload());
        traverse = traverse->getNextNode();
        translateDisk(traverse->getPayload());
        std::cout<<"********\n\n";
    }
    else
    {
        Node* traverse = this->top;
        translateDisk(traverse->getPayload());
        traverse = traverse->getNextNode();
        translateDisk(traverse->getPayload());
        traverse = traverse->getNextNode();
        translateDisk(traverse->getPayload());
        std::cout<<"********\n\n";
    }
    
}

void Stack::display()
{
    if(this->top)
    {
        Node* currNode = this->top;
        while(currNode)
        {
            std::cout<< currNode->getPayload()<<"\n";
            currNode = currNode->getNextNode();
        }
    }
    else
    {
        std::cout<<"Empty Stack!\n";
    }
    
}