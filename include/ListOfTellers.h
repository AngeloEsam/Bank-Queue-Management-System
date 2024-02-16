#ifndef LISTOFTELLERS_H
#define LISTOFTELLERS_H


class ListOfTellers
{
private:
    int numOfTellers;
    Teller *tellers;
public:
    ListOfTellers(int num=3)
    {
        numOfTellers = num;
        tellers = new Teller[numOfTellers];
    }
    ~ListOfTellers()
    {
        delete[] tellers;   //free allocated memory
    }

    // Function to get ID of a free teller
    int getFreeTellerID() const
    {
        for (int i = 0; i < numOfTellers; ++i)
        {
            if (tellers[i].isFree())
            {
                return i; // Return ID of first free teller found
            }
        }
        return -1; // Return -1 if no free teller found
    }

    // Function to get number of busy teller
    int getNumberOfBusyTellers() const
    {
        int count = 0;
        for (int i = 0; i < numOfTellers; ++i)
        {
            if (!tellers[i].isFree())
            {
                count++; // Increment count for each busy teller
            }
        }
        return count;
    }
    // Function to set a teller busy with given customer and transaction time
    void setTellerBusy(int tellerID, Customer cCustomer, int tTime)
    {
        tellers[tellerID].setBusy();
        tellers[tellerID].setCurrentCustomer(cCustomer);
        tellers[tellerID].setTransactionTime(tTime);
    }
    // Function to set a teller busy with given customer (transaction time from customer)
    void setTellerBusy(int tellerID, Customer cCustomer)
    {
        tellers[tellerID].setBusy();
        tellers[tellerID].setCurrentCustomer(cCustomer);
        tellers[tellerID].setTransactionTimeFromCustomer();
    }

    // Function to update teller statuses and decrement transaction times
    /*
    void updateTellers(ostream& outFile) {
        for (int i = 0; i < numOfTellers; ++i) {
            if (!tellers[i].isFree()) {
                tellers[i].decreaseTransactionTime();
                if (tellers[i].getRemainingTransactionTime() == 0) {
                    tellers[i].setFree();
                    if (&outFile == &cout) {
                        cout << "Customer " << tellers[i].getCurrentCustomerNumber()
                                  << " served. Departure time: " << tellers[i].getCurrentCustomerArrivalTime()
                                  << endl;
                    } else {
                        outFile << "Customer " << tellers[i].getCurrentCustomerNumber()
                                << " served. Departure time: " << tellers[i].getCurrentCustomerArrivalTime()
                                << endl;
                    }
                }
            }
        }
    }
    */
    void updateTellers(ostream& outF)
    {
        for (int i = 0; i < numOfTellers; i++)
            if (!tellers[i].isFree())
            {
                tellers[i].decreaseTransactionTime();
                if (tellers[i].getRemainingTransactionTime() == 0)
                {
                    outF << "From server number " << (i + 1)
                         << " customer number "
                         << tellers[i].getCurrentCustomerNumber()
                         << "\n departed at clock unit "
                         << tellers[i].getCurrentCustomerArrivalTime()
                         + tellers[i].getCurrentCustomerWaitingTime()
                         + tellers[i].getCurrentCustomerTransactionTime()
                         << endl;
                    tellers[i].setFree();
                }
            }
    }


};

#endif // LISTOFTELLERS_H
