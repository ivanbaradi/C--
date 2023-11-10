#include <vector>
#include <iostream>
using namespace std;

/**
 * @brief Queue with a set of methods and properties using vectors
 * 
 */
class Queue{

public:
    void enqueue(int val);
    void dequeue();
    bool isFull();
    bool isEmpty();
    int peek();
    int getLength();
    void print();

private:
    int length = 0;
    int max_length = 10;
    vector <int> queue;
};


/**
 * @brief Pushes the value to the queue
 * 
 * @param val: number to add to the queue (int)
 */
void Queue::enqueue(int val){
    if(!isFull()){
        queue.push_back(val);
        length++;
    }
}

/**
 * @brief Pops the first value from the queue
 * 
 */
void Queue::dequeue(){
    if(!isEmpty()){
        queue.erase(queue.begin());
        length--;
    }
}

/**
 * @brief Checks if the queue is full
 * 
 * @return true: queue is full
 * @return false: queue is not full
 */
bool Queue::isFull(){
    if(length == max_length){
        cout << "Queue is full!\n";
        return true;
    }

    return false;
}

/**
 * @brief Checks if the queue is empty
 * 
 * @return true: queue is empty
 * @return false: queue is not empty
 */
bool Queue::isEmpty(){
    if(length == 0){
        cout << "Queue is empty!\n";
        return true;
    }

    return false;
}

/**
 * @brief 
 * 
 * @return int: the value at the front of the queue
 */
int Queue::peek(){
    return queue[0];
}

/**
 * @brief prints all values from the queue
 * 
 */
void Queue::print(){
    for(int i = 0; i < length; i++){
        cout << queue[i] << " ";
    }
    cout << endl;
}

/**
 * @brief Gets the current length of the queue
 * 
 * @return int: length of the queue
 */
int Queue::getLength(){
    return length;
}