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
        List(){
        start=nullptr;
        };

        T front(){
            if(!start){
            cout<<"lista vacia"<<endl;    // Es mejor una excepción
            }else{                
                return start->data;
            }
        };
        T back(){
          if(!start){
            cout<<"lista vacia"<<endl;    // Es mejor una excepción
            }else{
                
                return start->prev->data;
            }  
        };
        void push_front(T value){
            Node<T> *temp = new Node<T>;
            temp->data=value;
            if (start)
            {
                temp->next=start;
                temp->prev=start->prev;
                temp->prev->next=temp;
                temp->next->prev=temp;
                start=temp;
            }else{
                start=temp;
                temp->next=start;
                temp->prev=start;
            }

        };
        void push_back(T value){
            Node<T> *temp = new Node<T>;
            temp->data=value;
            if (start)
            {
                temp->next=start;
                temp->prev=start->prev;
                temp->prev->next=temp;
                temp->next->prev=temp;
            }else{
                start=temp;
                temp->next=start;
                temp->prev=start;   
            }            
        };
        void pop_front(){ 
            if (start)
            { 
                Node<T> *temp_start;
                start->next->prev=start->prev;
                start->prev->next=start->next;
                temp_start=start->next;
                delete start;
                
                if(start==temp_start){ // Ya borraste start
                    start=nullptr;
                    temp_start=nullptr;
                }else{    
                    start= temp_start;
                    temp_start=nullptr;
                }

            }else{
                cout<<"lista vacia"<<endl;
            }
        };
        void pop_back(){ 
        if (start)
        {
            if(start == start->prev){
                delete start;
                start= nullptr;
            }else{
            Node<T>* temp_prev;
            temp_prev = start->prev;

            start->prev->prev->next=start;
            start->prev=start->prev->prev;
            delete temp_prev;
            temp_prev=nullptr; // No es necesario
            
            }
        }else{
                cout<<"lista vacia"<<endl;
        }  
        };
        bool empty(){
            return(!start);
        };
        
        T get(int position){
            
            if (!start)
            {
                cout<<"lista vacia"<<endl; // Deberías tener un throw
            }else{
                if (position<1)
                {
                    cout<<start<<endl;
                }else{    
                    Node<T>* actual;
                    actual=start;
                    for (int i = 0; i < position; ++i)
                    {
                        actual=actual->next;
                    }
                    
                    return actual->data;
       
                }
            }
        };
        
        int size(){
            if (start)
            {
                Node<T>* actual;
                actual=start;
                int i=0;
                do{
                    actual=actual->next;
                    i++;
                }while(actual->next!=start->next);
                return i;

            }else{
                return 0;
            }
        };
        
        Iterator<T> begin(){
            return Iterator<T>(start) ;

        };
        Iterator<T> end(){
            return Iterator<T> (start->prev);
        };
        void print_list(){
            if (start)
            {
                Node<T>* actual;
                actual=start;
                do{
                    cout<<actual->data<<endl;
                    actual=actual->next;
                }while(actual->next!=start->next);
            }else{
                cout<<"lista vacia"<<endl;
            }
        };
        
        void clear(){
            
            while(start!=nullptr){
                pop_front();
            }
        };
        ~List(){
            clear();
    };
        /*FUNCIONES FALTANTES*/
        void concat(List<T> &other);
};

#endif