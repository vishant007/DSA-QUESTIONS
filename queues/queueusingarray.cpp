#include<iostream>
using namespace std;


struct Queue{
    int rear , capacity;
    int* queue;
    Queue(int c){
        rear = 0;
        capacity = c;
        queue = new int;

    }
    ~Queue() {delete [] queue;}


    void enqueue(int data){
        if (capacity==rear){
            cout<<"\nQueue is Full\n";
            return;
        }
        else{
            queue[rear] = data;
            rear++;
        }
        return;
    }
    

    void dequeue(){
        if (rear == -1){
            cout<<"Queue is empty";
            return;
        }
        else{
            for (int i=0; i<rear-1; i++){
                queue[i]=queue[i+1];
            }
            rear --;
        }
        return;
    }
       void queueDisplay()
    {
        int i;
        if (rear==-1) {
            printf("\nQueue is Empty\n");
            return;
        }
 
        // traverse front to rear and print elements
        for (i = 0; i < rear; i++) {
            printf(" %d <-- ", queue[i]);
        }
        return;
    }
 
    // print front of queue
    void queueFront()
    {
        if (rear==-1) {
            printf("\nQueue is Empty\n");
            return;
        }
        printf("\nFront Element is: %d");
        return;
    }
    
};
int main(void)
{
    
    Queue q(4);
 
   
    q.queueDisplay();
 
    
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
 
    // print Queue elements
    q.queueDisplay();
 
    // insert element in the queue
    q.enqueue(60);
 
    // print Queue elements
    q.queueDisplay();
 
    q.dequeue();
    q.dequeue();
 
    printf("\n\nafter two node deletion\n\n");
 
    // print Queue elements
    q.queueDisplay();
 
    // print front of the queue
    q.queueFront();
 
    return 0;
}