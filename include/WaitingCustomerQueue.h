#ifndef WAITINGCUSTOMERQUEUE_H
#define WAITINGCUSTOMERQUEUE_H


#include "MyQueue.h"

class WaitingCustomerQueue:public MyQueue<Customer>
{
public:
    WaitingCustomerQueue(int size):MyQueue<Customer>(size)
    {

    }

    void UpdateWaitingQueue()
    {
        Customer cust;
        cust.setWaitingTime(-1);
        int wTime = 0;
        Add(cust);
        while (wTime !=-1)
        {
            Delete();
            wTime = cust.getWaitingTime();
            if (wTime ==-1)
                break;
            cust.incrementWaitingTime();
            Add(cust);
        }
    }

protected:

private:
};
#endif // WAITINGCUSTOMERQUEUE_H
