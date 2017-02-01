//
//  main.cpp
//  LinkList
//
//  Created by Zezhou Li on 1/29/17.
//  Copyright © 2017 Zezhou Li. All rights reserved.
//

#include <iostream>

using namespace std;

template <typename T>
class DLNode {
public:
    T data;
    DLNode *left;
    DLNode *right;
    
    DLNode(){
        this->data = NULL;
        this->left = nullptr;
        this->right = nullptr;
    };
    DLNode(T ob, DLNode *lp, DLNode *rp) {
        this->data = ob;
        this->left = lp;
        this->right = rp;
    }
};

template <typename T>
class DoubleLinkList {
private:
    DLNode<T> *head;
    DLNode<T> *tail;
    int size;
    
public:
    // Contructor
    DoubleLinkList() {
        CreatList();
    }
    
    // Deconstructor
    ~DoubleLinkList() {
        ClearList();
    }
    
    // Insert element
    void InsertAtBeginning(T Elem) {
        Insertatbeginning(Elem);
    }
    
    void InsertAtEnd(T Elem) {
        Insertatend(Elem);
    }
    
    void InsertAfter(T Elem, int Pos) {
        Insertafter(Elem, Pos);
    }
    
    void InsertBefore(T Elem, int Pos) {
        Insertbefore(Elem, Pos);
    }
    
    void RemoveNode(int Pos) {
        Removenode(Pos);
    }
    
    void PrintList() {
        printList();
    }
    
private:
    void ClearList() {
        head->data = tail->data = NULL;
        head->left = tail->right = nullptr;
        head->right = tail;
        tail->left = head;
        size = 0;
    }
    
    void CreatList() {
        // Init head
        head = new DLNode<T>();
        tail = new DLNode<T>();
        head->right = tail;
        tail->left = head;
        // Init list size
        size = 0;
        
    }
    
    DLNode<T>* Getelement(int pos) {
        if (pos<0 || pos>size) {
            cout << "Out of range!" << endl;
            exit(EXIT_FAILURE);
        }
        
        DLNode<T> *ptr = head;
        for (int i = 0; i<pos; ++i) {
            ptr = ptr->right;
        }
        return ptr;
    }
    
    void Insertatbeginning(T elem) {
        DLNode<T> *newDLNode = new DLNode<T>(elem, head, head->right);
        head->right->left = newDLNode;
        head->right = newDLNode;
        ++size;
    }
    
    void Insertatend(T elem) {
        DLNode<T> *newDLNode = new DLNode<T>(elem, tail->left, tail);
        tail->left->right = newDLNode;
        tail->left = newDLNode;
        ++size;
    }
    
    void Insertafter(T elem, int pos) {
        DLNode<T> *ptr = Getelement(pos);
        DLNode<T> *newDLNode = new DLNode<T>(elem, ptr, ptr->right);
        ptr->right->left = newDLNode;
        ptr->right = newDLNode;
        ++size;
    }
    
    void Insertbefore(T elem, int pos) {
        DLNode<T> *ptr = Getelement(pos);
        DLNode<T> *newDLNode = new DLNode<T>(elem, ptr->left, ptr);
        ptr->left->right = newDLNode;
        ptr->left = newDLNode;
        ++size;
    }
    
    void Removenode(int pos) {
        DLNode<T> *ptr = Getelement(pos);
        DLNode<T> *temp = ptr;
        ptr->right->left = temp->left;
        temp->left->right = temp->right;
    }
    
    void printList() {
        DLNode<T> *ptr = head->right;
        while (ptr != tail) {
            cout << ptr->data << ' ';
            ptr = ptr->right;
        }
        cout << endl;
    }
    
};


int main(int argc, const char * argv[]) {
    DoubleLinkList<int> *list = new DoubleLinkList<int>();
    list->InsertAtEnd(0);
    list->InsertAtBeginning(1);
    list->InsertAfter(2, 1);
    list->InsertBefore(3, 2);
    list->InsertAtEnd(4);
    list->RemoveNode(4);
    list->RemoveNode(4);
    list->PrintList();
    return 0;
}
