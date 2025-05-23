#include <iostream>
#include <string>
using namespace std;

class Node{
    public:
        int noMhs;
        Node *next;
        Node *prev;    
};

class DoubleLinkedList{
    private:
        Node *START;
    
    public:
        DoubleLinkedList(){
            START = NULL;
        }
    
    void addNode(){
        int nim;
        cout << "\nEnter the roll number of the student : ";
        cin >> nim;

        //step 1 : Allocate memory for new node
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
            if (START != NULL)
                START->prev = newNode;

                //step 6 : newNode.prev = NULL
                newNode->prev = NULL;

                //step 7 : START = newNode
                START = newNode;
                return;
        }

        //insert in between node
        //step 8 : locate psisition for insertion
        Node *current = START;
        while(current->next != NULL && current->next->noMhs <nim){
            current = current->next;
        }

        if (current->next != NULL && nim == current->next->noMhs){
            cout << "\nDuplicate roll numbers not allowed" << endl;
            return;
        }

        //step 9 : Insert between current and current->next
        newNode->next = current->next;  // Step 9a : newNode.next = current.next
        newNode->prev = current;        // step 9b : newNode.prev = current

        //insert last node
        if (current->next != NULL)
            current->next->prev = newNode;  //step 9c : current.next.prev = newNode
            current->next = newNode;        //step 9d : current.next = newNode
    }

    void hapus(){
        if (START == NULL){
            cout << "\nList is empty" << endl;
            return;
        }

        cout << "\nMasukkan NIM yang akan didelete : ";
        int rollNo;
        cin >> rollNo;

        Node *current = START;

        //Step 1 : Traverse the list to find the node
        while (current != NULL && current->noMhs != rollNo){
            current = current->next;
        }

        if (current == NULL){
            cout << "Record not found" << endl;
            return;
        }

        //step 2 : If node is at the beginning
        if (current == START){
            START = current->next;      //step 2a : START = START.next
            if (START != NULL){
                START->prev = NULL;     //step 2b : START.prev = NULL
            }
        }
        else{
            // Step 3 : Link Previous node to next of current
            current->prev->next = current->next;

            // Step 4 : If current is not the last node
            if (current->next != NULL)
                current->next->prev = current->prev;
        }

        //step 5 : Delete the node
        delete current;
        cout << "Record with roll number" << rollNo << "deleted" << endl;
    }

    void traverse(){
        if (START == NULL){
            cout << "\nList is empty" << endl;
            return;
        }

        //step 1 : Mark first node as currentNode
        Node *currentNode = START;

        //step 2 : Repeat untill curentNode == NULL
        cout << "\nRecord in ascending order of roll number are : \n";
        int i = 0;
        while (currentNode != NULL){
            cout << i + 1 << " . " << currentNode->noMhs << " " << endl;

            //step 3 : Move to next node
            currentNode = currentNode->next;
            i++;
        }
    }

    void revtraverse(){
        if (START == NULL){
            cout << "\nList is Empty" << endl;
            return;
        }

        //step 1 : Move to last node
        Node *currentNode = START;
        int i = 0;
        while (currentNode->next != NULL){
            currentNode = currentNode->next;
            i++;
        }

        //step 2 : Traverse backward
        cout << "\nRecords in descending order of roll number are : \n";
        while (currentNode != NULL){
            cout << i + 1 << " . " << currentNode->noMhs << " " << endl;

            //step 3 : Move to previous node
            currentNode = currentNode->prev;
            i--;
        }
    }

    void searchData(){
        if (START == NULL){
            cout << "\nList is Empty" << endl;
            return;
        }

        int rollNo;
        cout << "\nEnter the roll number to search : ";
        cin >> rollNo;

        Node *current = START;

        //step 1 : Traverse to find matching roll number
        while (current != NULL && current->noMhs != rollNo)
            current = current->next;

        //step 2 : Output Result
        if ( current == NULL){
            cout << "Record not found\n";
        }
        else{
            cout << "Record found\n";
            cout << "Roll Number : " << current->noMhs << endl;
        }
    }
};

int main(){
    DoubleLinkedList list;
    char choice;

}