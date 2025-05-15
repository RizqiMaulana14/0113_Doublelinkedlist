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

        //step 2 : Assign value to the data field
        newNode->noMhs = nim;

        //step 3 : Insert at beginning if list is empty or nim is smallest
        if (START == NULL || nim <= START->noMhs){
            if (START != NULL && nim == START->noMhs){
                cout << "\nDuplicate number nor allowed" << endl;
                return;
            }
            //step 4 : newNode.next = START
            newNode->next = START;

            //step 5 : START.prev = newNode (if START exists)
            if (START != NULL){
                START->prev = newNode;
            }
        }
    }
};