/*
#include <iostream>
#include <random>

using namespace std;

int main() {
  int numCustomers, minServiceTime, maxServiceTime;


  cout << "Enter customers number: ";
  cin >> numCustomers;


  cout << "min TIME IN SECOND: ";
  cin >> minServiceTime;
  cout << "mAX TIME IN SECOND: ";
  cin >> maxServiceTime;


  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<> dist(minServiceTime, maxServiceTime);


  for (int i = 1; i <= numCustomers; i++) {
    int serviceTime = dist(gen);
    cout << "customer " << i << ": " << serviceTime << " second" << endl;
  }

  return 0;
}

*/

/*
#include<iostream>
#include<iomanip>
#include<fstream>
#include<cctype>

using namespace std;

class Bank_Account{
    int account_number;
    char name[50];
    char type;
    int money_Deposit;

public:
    void create_account();
    void display_account();
};
void Bank_Account::create_account(){
    system("cls");
    cout<<"ّّّّ\t Enter the account number:";
    cin>>account_number;
    cout<<"ّّّّ\t Enter the name of account holder:";
    cin.getline(name,50);
    cout<<"ّّّّ\t Enter the type of account (C/S):";
    type=toupper(type);
    cout<<"ّّّّ\t Ener the initial amount
}
*/








/*
#include<iostream>
#include<iomanip>
#include <random>
#include<fstream>
#include<cctype>

using namespace std;
struct Customer{
    string name;
    int arrivalTime;
    Customer(string name, int arrivalTime):name(name),arrivalTime(arrivalTime){}
};

class customerQueue{
    struct Node{
        Customer data;
        Node * next;
        Node(Customer data) : data(data), next(nullptr) {}
    };
    Node *front=nullptr;
     Node *rear=nullptr;
 public:
     bool isEmpty(){
         if(front==nullptr && rear==nullptr){
            return true;
         }else{
             return false;
         }
     }

    void enqueue(Customer customer){
        Node * newNode=new Node(customer);
        if(isEmpty()){
            front=rear=newNode;
        }else{
            rear->next=newNode;
            rear=newNode;
        }
    }

    void dequeue(){
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue.\n";
        }if(front==rear){
            front=rear=NULL;
        }
         else {
            Node *temp=front;
            front=front->next;
            delete temp;

        }
    }

    void display() {
            if (isEmpty()) {
                cout << "Queue is empty." << endl;
                return;
            }

            Node* temp = front;
            while (temp != nullptr) {
                cout << "Customer: " << temp->data.name << ", Arrival Time: " << temp->data.arrivalTime << endl;
                temp = temp->next;
            }
        }
};
int main(){
    customerQueue queue;
    queue.enqueue(Customer("angelo",15));
    queue.enqueue(Customer("rezk",10));
    queue.enqueue(Customer("hesham",20));
    queue.display();
    queue.dequeue();
    queue.display();
    return 0;
}
*/








/*

#include<iostream>
#include<iomanip>
#include <random>
#include<fstream>
#include<cctype>
#include<cassert>
#include<queue>
#include<vector>


using namespace std;
struct Customer{
    string name;
    int arr_dep_time;
    string type;
    int wat_time;
    int serv_time;
};
struct compareEventTime{
    bool operator()(const Customer& lhs, const Customer& rhs) const{
        return lhs.arr_dep_time > rhs.arr_dep_time;
    }
};
class customerQueue{
private:
    priority_queue<Customer,vector<Customer>,compareEventTime>q;
    queue<Customer> bankQueue;
    int teller_num=3;
    int currentTime=0;
public:
    void enqueue(Customer& customer){
        q.push(customer);
    }

    void addBankQueueCustomer(Customer & customer){
        bankQueue.push(customer);
        customer.wat_time=currentTime;
    }


    void run_simulation(){
        while(!q.empty()){
            Customer nex_current=q.front();
            currentTime=nex_current.arr_dep_time;
            if(nex_current.type=="Arrival"){
                if(teller_num!=0){
                    cout<<"customer: "<<nex_current.name<<" Waiting:"<<0<<"serv_wait: "<<nex_current.arr_dep_time+nex_current.serv_time;
                    nex_current.arr_dep_time=(nex_current.arr_dep_time+nex_current.serv_time);
                    nex_current.arr_dep_time="departual";
                    teller_num--;
                }else{
                    addBankQueueCustomer(nex_current);
                }
            }else if(nex_current.type=="departual"){
                if(!bankQueue.empty()){
                    Customer next_cust=bankQueue.front();
                }
            }
        }
    }

};
int main(){
    Customer c1;

    c1.name="Angelo";
    c1.arr_dep_time=32;
    c1.type="Arrival";
    c1.serv_time=60;

    customerQueue B1;
    B1.enqueue(c1);
    return 0;
}


*/








/*
#include <iostream>
#include <iomanip>
#include <random>
#include <fstream>
#include <cctype>
#include <cassert>
#include <queue>
#include <vector>

using namespace std;

struct Customer {
    string name;
    int arr_dep_time;
    string type;
    int wait_time;
    int serv_time;
};

struct compareEventTime {
    bool operator()(const Customer& lhs, const Customer& rhs) const {
        return lhs.arr_dep_time > rhs.arr_dep_time;
    }
};

class CustomerQueue {
private:
    priority_queue<Customer, vector<Customer>, compareEventTime> q;
    queue<Customer> bankQueue;
    int teller_num = 3;
    int currentTime = 0;

public:
    void enqueue(Customer& customer) {
        q.push(customer);
    }

    void addBankQueueCustomer(Customer& customer) {
        bankQueue.push(customer);
        customer.wait_time = currentTime;
    }

    void run_simulation() {
        while (!q.empty()) {
            Customer next_customer = q.top();
            q.pop();
            currentTime = next_customer.arr_dep_time;

            if (next_customer.type == "Arrival") {
                if (teller_num != 0) {
                    cout << "Customer: " << setw(10) << next_customer.name << " Waiting: " << setw(5) << 0 << " Serv_wait: " << next_customer.arr_dep_time + next_customer.serv_time << endl;
                    next_customer.arr_dep_time += next_customer.serv_time;
                    next_customer.type = "departual";
                    teller_num--;
                } else {
                    addBankQueueCustomer(next_customer);
                }
            } else if (next_customer.type == "departual") {
                if (!bankQueue.empty()) {
                    Customer next_cust = bankQueue.front();
                    bankQueue.pop();
                    cout << "Customer: " << setw(10) << next_cust.name << " Waiting: " << setw(5) << (currentTime - next_cust.wait_time) << " Serv_wait: " << currentTime + next_cust.serv_time << endl;
                }
                teller_num++;
            }
        }
    }
};

int main() {
    Customer c1;
    c1.name = "Angelo";
    c1.arr_dep_time = 32;
    c1.type = "Arrival";
    c1.serv_time = 60;

    CustomerQueue B1;
    B1.enqueue(c1);
    B1.run_simulation();

    return 0;
}

*/







#include <iostream>
#include <iomanip>
#include <random>
#include <fstream>
#include <cctype>
#include <cassert>
#include <queue>
#include <vector>

class Customer{
private:
    int customerNumber;
    int arrivalTime;
    int waitingTime;
    int transactionTime;
public:
    Customer(int cN = 0, int arrvTime = 0, int wTime = 0, int tTime = 0) {
        customerNumber = cN;
        arrivalTime = arrvTime;
        waitingTime = wTime;
        transactionTime = tTime;
    }


    void setWaitingTime(int time) {
        waitingTime = time;
    }


    void incrementWaitingTime() {
        waitingTime++;
    }


    int getWaitingTime()  {
        return waitingTime;
    }

    int getArrivalTime()  {
        return arrivalTime;
    }

    int getTransactionTime() {
        return transactionTime;
    }

    int getCustomerNumber() {
        return customerNumber;
    }

};

using namespace std;
int main(){

    return 0;
}

