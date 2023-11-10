#include <iostream>
using namespace std;

/**
 * @brief 
 * Node is constructed by the following => {
 *      next: pointer that points to the next node
 *      prev: pointer that points to the previous node
 *      val: value contained inside the node
 * }
 * 
 */
struct Node{
    
    Node *next = nullptr;
    Node *prev = nullptr;
    int val;

    //For inserting first node
    Node(int val){
        this->val = val;
    }

    //For inserting other nodes
    Node(int val, Node *prev){
        this->val = val;
        this->prev = prev;
    }
};



/**
 * @brief Linked List with modules
 * 
 */
class LinkedList{

    public:
        void insertNode(int);
        void insertNodeAtPosition(int, int);
        void deleteNode(int);
        void printNodes();
        void reversePrintNodes();
        int getHead();
        int getLength();
    private:
        //Head of the linked list
        Node *head = nullptr;
        //Size of the linked list
        int length = 0;
};

/**
 * @brief 
 * 
 * @return head: value contained in the head 
 */
int LinkedList::getHead(){
    return head->val;
}

/**
 * @brief Inserts node at the end of the linked list
 * 
 * @param val: number to insert to the linked list
 */
void LinkedList::insertNode(int val){
    
    if(!head){
        head = new Node(val);
    } else {

        //Current and previous nodes
        Node *temp = head, *prev = nullptr;

        //Traverses to the last node
        while(temp->next){
            prev = temp;
            temp = temp->next;
        }

        temp->next = new Node(val, temp);
    }

    length++;
}




/**
 * @brief Prints all values from the linked list
 * 
 */
void LinkedList::printNodes(){

    Node *temp = head;
    while(temp){
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}



/**
 * @brief Gets the size of the linked list
 * 
 * @return length: linked list size
 */
int LinkedList::getLength(){
    return length;
}



/**
 * @brief Deletes node in a specified position
 * 
 * @param pos: index of the node to remove [from 0 to list.size()-1]
 */
void LinkedList::deleteNode(int pos){

    if(length == 0){
        cout << "There are no nodes in the linked list\n";
        return;
    }

    //Invalid position value
    if(pos < 0 || pos >= length){
        cout << "Invalid position value\n";
        return;
    }

    //Current node
    Node *temp = head;

    /* Removes the first node */
    if(pos == 0){
        if(temp->next){
            head = temp->next;
        } else {
            head = nullptr; //There's only 1 node in the list
        }

    } else {

        //Previous node
        Node *prev = nullptr;

        for(int i = 0; temp; i++){
            
            if(i == pos){

                //Previous node point to the next node
                if(prev){
                    prev->next = temp->next;
                }

                delete temp;

                break;
            } 

            prev = temp;
            temp = temp->next;
        }
    }
    
    length--;
}



/**
 * @brief inserts node at a certain position value EXCEPT at the last index (FIX)
 * 
 * @param val: number to insert to the linked list
 * @param pos: index of the node to remove [from 0 to list.size()-1]
 */
void LinkedList::insertNodeAtPosition(int val, int pos){

    /* Invalid position value */
    if(pos < 0 || pos >= length){
        return;
    }

    //Current node
    Node *temp = head;

    /* Inserts node at the first position */
    if(pos == 0){

        if(temp->next){ //There is a second node
            Node *newNode = new Node(val);
            newNode->next = temp;
            head = newNode;
        } else {
            head = new Node(val);
        }

        return;
    }

    //Previous node
    Node *prev = nullptr;

    for(int i = 0; temp; i++){
        

        if(i == pos){
            
            /* New node points to the current node */
            Node *newNode = new Node(val, prev);
            newNode->next = temp;

            break;
        }

        prev = temp;
        temp = temp->next;
    }

    cout << "Invalid position number. Out of range\n";
}


/**
 * @brief prints nodes in reverse order
 *
 * 
 */
void LinkedList::reversePrintNodes(){

    Node *temp = head;

    //Traverses to the last node
    while(temp->next){
        temp = temp->next;
    }

    //Traverses to the first node
    while(temp){
        cout << temp->val << " ";
        temp = temp->prev;
    }
}