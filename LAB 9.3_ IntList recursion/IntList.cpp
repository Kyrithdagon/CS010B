#include "IntList.h"

#include <ostream>

using namespace std;

IntList::IntList() : head(nullptr) {}

void IntList::push_front(int val) {
   if (!head) {
      head = new IntNode(val);
   } 
   else {
      IntNode *temp = new IntNode(val);
      temp->next = head;
      head = temp;
   }
}

ostream & operator<<(ostream &out, const IntList &vals){
   if(vals.head == nullptr){
      return out;
   }
   else{
      return operator<<(out, vals.head);
   }
}

bool IntList::exists(int value) const{
   if(head == nullptr){
      return false;
   }
   if(head->value == value){
      return true;
   }
   return exists(head->next, value);
}

bool IntList::exists(IntNode *nextNode, int value) const{
   if(nextNode == nullptr){
      return false;
   }
   if(nextNode-> value == value){
      return true;
   }
   return exists(nextNode->next, value);
}

ostream & operator<<(ostream &out, IntNode *nextNode){
   if(!nextNode){
      return out;
   }
   else{
      out << nextNode->value;
      if(nextNode->next != nullptr){
         out << " ";
      }
   }
   return operator<<(out, nextNode->next);
}