#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "node.h"
#include "iterator.h"

using namespace std;

template <typename T>
class List {
    private:
        Node<T>* start;

    public:
        List();

        T front(){
            if(empty()){
            cout<<"lista vacia"<<endl;   
            }else{
                return start->prev->data;
            }
        };
        T back(){
          if(empty()){
            cout<<"lista vacia"<<endl;   
            }else{
                
                return start->data;
            }  
        };
        void push_front(T value){
            Node<T> *temp = new Node<T>;
            temp->data=value;
            if (empty())
            {
                temp->next=temp;
                temp->prev=temp;
                start  = temp;
            }else{
                temp->next=start;
                temp->prev=start->prev;
                start->prev=temp;
                start=temp;
            }

        };
        void push_back(T value);
        void pop_front();
        void pop_back();
        T get(int position);
        void concat(List<T> &other);
        bool empty(){
            return (start->next==nullptr && start->prev==nullptr);
        };
        int size();
        void clear();
        Iterator<T> begin();
        Iterator<T> end();

        ~List();
};

#endif