#include <string>
#include <queue>

using namespace std;

struct Customer{
    int customerID;
    string name;
    string address;
};

class CustomerADT{
private:
    queue<Customer> customers;
    int nextCustomerID = 1;

public:
    void AddCustomer(const string& name, const string& address);
    void CustomerDetails(int customerID);
};

