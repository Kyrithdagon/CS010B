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
    }
    head = tail = nullptr;
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

IntList::IntList(const IntList &cpy){
    head = tail = nullptr;
    IntNode *hold = cpy.head;

    while(hold != nullptr){
        push_back(hold->value);
        hold = hold->next;
    }
}

IntList & IntList::operator=(const IntList &rhs){
    if(this != &rhs){
        clear();
        IntNode *hold = rhs.head;

        while(hold != nullptr){
            push_back(hold->value);
            hold = hold->next;
        }
    }
    return *this;
}

void IntList::push_back(int value){
    IntNode *insertNew = new IntNode(value);

    if(head == nullptr){
        head = tail = insertNew;
    }
    else{
        tail = tail->next = insertNew;
    }
}

void IntList::selection_sort(){
    for(IntNode *startPoint = head; startPoint != nullptr; startPoint = startPoint->next){
        int minVal = startPoint->value;
        for(IntNode *pointer = startPoint->next; pointer != nullptr; pointer = pointer->next){
            if(pointer->value < minVal){
                minVal = pointer->value;
                pointer->value = startPoint->value;
                startPoint->value = minVal;
            }
        }
    }
}

void IntList::insert_ordered(int value){
    IntNode *insertNew = new IntNode(value);

    if(head == nullptr){
        head = tail = insertNew;
    }
    else if(insertNew->value <= head->value){
        insertNew->next = head;
        head = insertNew;
    }
    else if(insertNew->value >= tail->value){
        tail = tail->next = insertNew;
    }
    else{
        IntNode *point = head;
        while((point != nullptr) && (point->next->value <= insertNew->value)){
            point = point->next;
            // insertNew->next = point->next;
            // point->next = insertNew;
        }
        insertNew->next = point->next;
        point->next = insertNew;
    }
}

void IntList::remove_duplicates(){
    for(IntNode *startPoint = head; startPoint != nullptr; startPoint = startPoint->next){
        // for(IntNode *pointer = startPoint->next; pointer != nullptr; pointer = pointer->next){
        //     if(pointer->value == startPoint->value){
        //         IntNode *hold = pointer;
        //         pointer = pointer->next;
        //         delete hold;
        //     }
        // } //doesn't work
        IntNode *previous = startPoint;
        for(IntNode *finder = previous->next; finder != nullptr; finder = previous->next){
            if(finder->value == startPoint->value){
                if(finder->next == nullptr){
                    tail = previous;
                }
                previous->next = finder->next;
                delete finder;
            }
            else{ //added this 
                previous = previous->next;
            }
        }
    }
}