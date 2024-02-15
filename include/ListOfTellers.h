#ifndef LISTOFTELLERS_H
#define LISTOFTELLERS_H


class ListOfTellers
{
private:
    int numOfTellers;
    Teller *tellers;
public:
    ListOfTellers(int num=1)
    {
        numOfTellers = num;
        tellers = new Teller[numOfTellers];
    }
    ~ListOfTellers()
    {
        delete[] tellers;   //free allocated memory
    }

    // Function to get ID of a free server
    int getFreeServerID() const
    {
        for (int i = 0; i < numOfTellers; ++i)
        {
            if (tellers[i].isFree())
            {
                return i; // Return ID of first free server found
            }
        }
        return -1; // Return -1 if no free server found
    }

    // Function to get number of busy servers
    int getNumberOfBusyServers() const
    {
        int count = 0;
        for (int i = 0; i < numOfTellers; ++i)
        {
            if (!tellers[i].isFree())
            {
                count++; // Increment count for each busy server
            }
        }
        return count;
    }
    // Function to set a server busy with given customer and transaction time
    void setServerBusy(int tellerID, Customer cCustomer, int tTime)
    {
        tellers[tellerID].setBusy();
        tellers[tellerID].setCurrentCustomer(cCustomer);
        tellers[tellerID].setTransactionTime(tTime);
    }
    // Function to set a server busy with given customer (transaction time from customer)
    void setServerBusy(int tellerID, Customer cCustomer)
    {
        tellers[tellerID].setBusy();
        tellers[tellerID].setCurrentCustomer(cCustomer);
        tellers[tellerID].setTransactionTimeFromCustomer();
    }

    // Function to update server statuses and decrement transaction times
    void updateServers(ostream& outFile) {
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



};

#endif // LISTOFTELLERS_H
