#include <iostream>
#include <string>
using namespace std;

class Node{
    public:
        int noMhs;
        Node *next;
        Node *prev;    
};

class DoubleLinkedLis{
    private:
        Node *START;
    
    public:
        DoubleLinkedLis(){
            START = NULL;
        }
    void addNode(){
        int nim;
        cout << "\nEnter the roll number of the student : ";
        cin >> nim;

        //step 1 : Allocate memorty for new node
        Node *newNode = new Node();
    }
};