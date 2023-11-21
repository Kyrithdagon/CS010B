#include <iostream>

using namespace std;

#include "IntList.h"

IntList::IntList(){
    head = tail = nullptr;
}

IntList::~IntList(){
    clear();
}

void IntList::clear(){
    if(!empty()){
        while(head != nullptr){
            IntNode *hold = head;
            head = head->next;
            delete hold;
        }
        head = tail = nullptr;
    }
}

void IntList::push_front(int dataVal){
    IntNode *insertNew =  new IntNode(dataVal);

    if(head == nullptr){
        head = tail = insertNew;
    }
    else{
        insertNew->next = head;
        head = insertNew;
    }
}

void IntList::pop_front(){
    if(!empty()){
        IntNode *hold = head->next;
        delete head;
        head = hold;

        if(empty()){
            head = tail = nullptr;
        }
    }
}

bool IntList::empty() const{
    return head == nullptr;
}

const int & IntList::front() const{
    return head->value;
}

const int & IntList::back() const{
    return tail->value;
}

ostream & operator<<(ostream &out, const IntList &dataVals){
    IntNode *hold = dataVals.head;
    
    if(hold != nullptr){
        out << hold->value;
        hold = hold->next;

        while(hold != nullptr){
            out << " " << hold->value;
            hold = hold->next;
        }
    }
    return out;
}
