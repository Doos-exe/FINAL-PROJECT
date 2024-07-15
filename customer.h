#include <string>
#include <queue>

using namespace std;

struct Customer{
    int customerID;
    string name;
    string address;
};

class CustomerADT{
public:
    queue<Customer> customers;
    int nextCustomerID;

public:
	CustomerADT():
		nextCustomerID(1) {}
		
    void AddCustomer(const string& name, const string& address);
    void CustomerDetails(int customerID);
    void updateNextCustomerID();
    void saveNewCustomerToFile(const Customer& customer);
    void loadCustomerFromFile();
};

