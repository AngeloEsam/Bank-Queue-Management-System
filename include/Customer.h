#ifndef CUSTOMER_H
#define CUSTOMER_H
using namespace std;

class Customer
{
private:
    int customerNumber;
    int arrivalTime;
    int waitingTime;
    int transactionTime;
public:
    //Constructor
    Customer(int cN = 0, int arrvTime = 0, int wTime = 0, int tTime = 0)
    {
        customerNumber = cN;
        arrivalTime = arrvTime;
        waitingTime = wTime;
        transactionTime = tTime;
    }


    void setWaitingTime(int time)
    {
        waitingTime = time;
    }

    // Increment waiting time
    void incrementWaitingTime()
    {
        waitingTime++;
    }

     // Getters
    int getWaitingTime()
    {
        return waitingTime;
    }

    int getArrivalTime()
    {
        return arrivalTime;
    }

    int getTransactionTime()
    {
        return transactionTime;
    }

    int getCustomerNumber()
    {
        return customerNumber;
    }

};

#endif // CUSTOMER_H
