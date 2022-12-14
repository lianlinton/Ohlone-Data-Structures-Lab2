//Header file: stackADT.h

#ifndef H_QueueADT
#define H_QueueADT
#include "nodeType.h"
  
template <class Type>
class QueueADT {
public:
    virtual ~QueueADT() {};
    
    //Function to determine whether the queue is empty.
    //Postcondition: Returns true if the queue is empty,
    //               otherwise returns false.
    virtual bool isEmptyQueue() const = 0;
    
    //Function to determine whether the queue is full.
    //Postcondition: Returns true if the queue is full,
    //               otherwise returns false.
    virtual bool isFullQueue() const = 0;
    
    //Function to initialize the queue to an empty state.
    //Postcondition: The queue is empty.
    virtual void initializeQueue() = 0;
   
    //Function to return the first element of the queue.
    //Precondition: The queue exists and is not empty.
    //Postcondition: If the queue is empty, the program 
    //               terminates; otherwise, the first 
    //               element of the queue is returned.  
    virtual Type& front() const = 0;
   
    //Function to return the last element of the queue.
    //Precondition: The queue exists and is not empty.
    //Postcondition: If the queue is empty, the program 
    //               terminates; otherwise, the last 
    //               element of the queue is returned.
    virtual Type back() const = 0;
    
    //Function to add queueElement to the queue.
    //Precondition: The queue exists and is not full.
    //Postcondition: The queue is changed and queueElement
    //               is added to the queue.
    virtual void addQueue(const Type& queueElement) = 0;
    
    //Function to remove the first element of the queue.
    //Precondition: The queue exists and is not empty.
    //Postcondition: The queue is changed and the first 
    //               element is removed from the queue.
    virtual void deleteQueue() = 0;
};
        
#endif
