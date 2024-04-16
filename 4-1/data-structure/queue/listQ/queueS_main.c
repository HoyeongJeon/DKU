#include "queueS.h"

int main(void) {
    QueueType* Q1 = createQueue();
    element data;
    
    enQueue(Q1, 'A');
    enQueue(Q1, 'B');
    enQueue(Q1, 'C');
    printQ(Q1);
    
    data = deQueue(Q1);
    printQ(Q1);
    
    data = deQueue(Q1);
    printQ(Q1);
    
    data = deQueue(Q1);
    printQ(Q1);
    
    return 0;
    }