#include <iostream>
using namespace std;

/**
 * @brief Node for the stack
 * 
 */
struct Node{

    int val;
    Node *next = nullptr;

    Node(int val){
        this->val = val;
    }
};

/**
 * @brief Stack containing nodes with modules
 * 
 */
class Stack{

    public:
        void push(int);
        void pop();
        void clear();
        int peek_top();
        int peek_bottom();
        int getLength();
        bool isEmpty();
    private:
        //Size of the stack
        int length = 0;
        //Points at the top of the stack
        Node *top = nullptr;
        //Points at the bottom of the stack
        Node *bottom = nullptr;
};



/**
 * @brief Pushes data to the stack;
 * 
 * @param val: data to push to the stack
 */
void Stack::push(int val){
    
    if(!bottom){
        bottom = new Node(val);
        top = bottom;
    } else {

        //Current Node
        Node *temp = top;
        //New Node
        Node *newNode = new Node(val);

        newNode->next = temp;
        top = newNode;
    }

    length++;
}



/**
 * @brief Pops data out of the stack
 * 
 */
void Stack::pop(){
    if(length == 1){
        top = nullptr;
        bottom = nullptr;
    } else {
        Node *temp = top;
        top = temp->next;
        delete temp;
    }

    length--;
}



/**
 * @brief Empties out the stack
 * 
 */
void Stack::clear(){
    while(!isEmpty()){
        pop();
    }
}



/**
 * @brief Returns the value that is at the top of the stack
 * 
 * @return top: value of the top
 */
int Stack::peek_top(){

    if(isEmpty()){
        cout << "Stack is empty\n";
        return -1;
    }

    return top->val;
}


/**
 * @brief Returns the value that is at the bottom of the stack
 * 
 * @return top: value of the bottom
 */
int Stack::peek_bottom(){

    if(isEmpty()){
        cout << "Stack is empty\n";
        return -1;
    }

    return bottom->val;
}


/**
 * @brief Checks if the stack is empty or not
 * 
 * @return true: stack is not empty,
 * @return false: stack is empty
 */
bool Stack::isEmpty(){

    if(length == 0){
        return true;
    }

    return false;
}