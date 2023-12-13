#include <iostream>

using namespace std;

#include "SortedSet.h"

SortedSet::SortedSet() : IntList() {}

SortedSet::SortedSet(const SortedSet &makeCopy) : IntList(makeCopy) {}

SortedSet::SortedSet(const IntList &listCopy) : IntList(listCopy) {
    IntList::remove_duplicates();
    IntList::selection_sort();
}

SortedSet::~SortedSet() {}

bool SortedSet::in(int value) const{
    for(IntNode *curr = head; curr != nullptr; curr = curr->next){
        if(curr->value == value){
            return true;
        }
    }
    return false;
}

SortedSet & SortedSet::operator|(SortedSet &sset){
    SortedSet *sset1 = new SortedSet();

    if(head == nullptr){
        sset1 = &sset;
    }
    else if(sset.head == nullptr){
        sset1 = this;
    }
    else{
        IntNode *sset2 = head;
        IntNode *sset3 = sset.head;
//for inconsistent merging between two set lists
        if(sset2->value < sset3->value){
            sset1->push_back(sset2->value);
            sset2 = sset2->next;
            }
        else{
            sset1->push_back(sset3->value);
            sset3 = sset3->next;
        }
//for a consistent back and forth merging of two set lists
        while((sset2 != nullptr) && (sset3 != nullptr)){
            if(sset2->value < sset3->value){
                sset1->push_back(sset2->value);
                sset2 = sset2->next;
            }
            else{
                sset1->push_back(sset3->value);
                sset3 = sset3->next;
            }
        }
//in case all of one set decides to be smaller than the other
        if(sset2 != nullptr){
            while(sset2 != nullptr){
                sset1->push_back(sset2->value);
                sset2 = sset2->next;
            }
        }
        else{
            while(sset3 != nullptr){
                sset1->push_back(sset3->value);
                sset3 = sset3->next;
            }
        }
    }
    return *sset1;
}

SortedSet & SortedSet::operator&(SortedSet &sset){
    SortedSet *sset1 = new SortedSet();
    IntNode *sset2 = head;

    while(sset2 != nullptr){
        if(in(sset2->value) && sset.in(sset2->value)){
            sset1->push_back(sset2->value);
        }
        sset2 = sset2->next;
    }
    return *sset1;
}

void SortedSet::add(int value){
    if(!in(value)){
        IntList::insert_ordered(value);
    }
}

void SortedSet::push_front(int value){
    add(value);
}

void SortedSet::push_back(int value){
    add(value);
}

void SortedSet::insert_ordered(int value){
    add(value);
}

SortedSet & SortedSet::operator|=(SortedSet &rhs){
    SortedSet *sset1 = &(*this |rhs);
    if(head == nullptr){
        sset1 = &rhs;
    }
    else if(rhs.head == nullptr){
        sset1 = this;
    }
    else{
        for(IntNode *curr = rhs.head; curr != nullptr; curr = curr->next){
            this->push_back(curr->value);
        }
    }
    return *sset1;
}

SortedSet & SortedSet::operator&=(SortedSet &rhs){
    SortedSet *sset1 = &(*this &rhs);
    if(head == nullptr){
        sset1 = &rhs;
    }
    else if(rhs.head == nullptr){
        sset1 = this;
    }
    else{
        for(IntNode *curr = rhs.head; curr != nullptr; curr = curr->next){
            this->push_back(curr->value);
        }
    }
    return *sset1;
}