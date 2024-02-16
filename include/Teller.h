#ifndef TELLER_H
#define TELLER_H
#include<string>
using namespace std;

class Teller
{
private:
    Customer currentCustomer;
    string status;
    int transactionTime;
public:
    Teller()
    {
        status = "free";
        transactionTime = 0;
    }

    // Function to check if the Teller is free
    bool isFree() const
    {
        return status == "free";
    }

    // Function to set the teller status to busy
    void setBusy()
    {
        status = "busy";
    }


    // Function to set the teller status to free
    void setFree()
    {
        status = "free";
    }

    // Function to set transaction time
    void setTransactionTime(int t)
    {
        transactionTime = t;
    }

    // Function to set transaction time from current customer's transaction time
    void setTransactionTimeFromCustomer()
    {
        transactionTime = currentCustomer.getTransactionTime();
    }

    // Function to get remaining transaction time
    int getRemainingTransactionTime() const
    {
        return transactionTime;
    }

    // Function to decrease transaction time
    void decreaseTransactionTime()
    {
        if (transactionTime > 0)
        {
            transactionTime--;
        }
    }
    // Function to set current customer information
    void setCurrentCustomer(Customer cCustomer)
    {
        currentCustomer = cCustomer;
    }

    // Function to get current customer number
    int getCurrentCustomerNumber()
    {
        return currentCustomer.getCustomerNumber();
    }

    // Function to get current customer arrival time
    int getCurrentCustomerArrivalTime()
    {
        return currentCustomer.getArrivalTime();
    }
    // Function to get current customer waiting time
    int getCurrentCustomerWaitingTime()
    {
        return currentCustomer.getWaitingTime();
    }

    // Function to get current customer transaction time
    int getCurrentCustomerTransactionTime()
    {
        return currentCustomer.getTransactionTime();
    }
};

#endif // TELLER_H
