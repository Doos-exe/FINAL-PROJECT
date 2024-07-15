#include "video.h"
#include "customer.h"
#include "rent.h"
#include <string>
#include <iostream>
#include <limits>
#include <windows.h>

using namespace std;

// function for adding customers
void CustomerADT::AddCustomer(const string& name, const string& address){
	
	Customer newCustomer = {nextCustomerID++, name, address};
    customers.push(newCustomer);
    
    cout << endl;
	cout << "Customer added successfully!\n";
    cout << "Customer ID: " << newCustomer.customerID << endl;
    cout << "Name       : " << newCustomer.name << endl;
    cout << "Address    : " << newCustomer.address << '\n' << endl;

}

// function for customer details
int CustomerADT::CustomerDetails(int customerID){
	    queue<Customer> tempQueue = customers;
	    int ans;
	    bool found = false;

        while (!tempQueue.empty()) {
            Customer current = tempQueue.front();
            tempQueue.pop();
            if (current.customerID == customerID) {
                system("cls");
                cout << "Customer Details\n";
                cout << "Customer ID: " << current.customerID << "\n";
                cout << "Name: " << current.name << "\n";
                cout << "Address: " << current.address << "\n";
                cout << "\n";
                found = true;
                break;
            }
        }

        if (!found) {
            system("cls");
            cout << "\nCustomer not found!\n\n";
            Sleep(500);
            ans = 0;
        }
        
        return ans;
}

// function for renting videos
void RentADT::RentVideo(int customerID, int ans){
	int videoID;
	char opt;
	
	if(ans == 0){
		return;
	}
	do{
		cout << "Video ID: ";
		cin >> videoID;
	
		//file handling
	
		customerRentals[customerID].customerID = customerID;
    	customerRentals[customerID].rentedVideoIDs.push(videoID);
    	cout << "Video rented successfully!\n";
    	
    	do{
    		cout << endl << "Rent another Video as Customer ID " << customerID << "? ";
			cin>>opt;
			
			switch(opt){
			case 'Y':
			case 'y':
				system("cls");
				break;
			case 'N':
			case 'n':
				break;
			default:
				cin.ignore();
				cout<<"That is not an option \nPlease press enter to try again..."<<endl;
				cin.get();
				system("cls");
				opt = 'a';
				break;	
			}
		}while(opt == 'a');
	
	}while(opt == 'Y' || opt == 'y');
}

// function for returning videos
void RentADT::ReturnVideo(int customerID, int videoID) {
        if (customerRentals.find(customerID) != customerRentals.end()) {
            stack<int> tempStack;
            while (!customerRentals[customerID].rentedVideoIDs.empty()) {
                int top = customerRentals[customerID].rentedVideoIDs.top();
                customerRentals[customerID].rentedVideoIDs.pop();
                if (top != videoID) {
                    tempStack.push(top);
                }
            }
            while (!tempStack.empty()) {
                customerRentals[customerID].rentedVideoIDs.push(tempStack.top());
                tempStack.pop();
            }
            cout << "Video returned successfully!\n";
        } else {
            cout << "Customer not found!\n";
        }
}

// function for rented videos of a customer
void RentADT::printRentedVideos(int customerID) {
    if (customerRentals.find(customerID) != customerRentals.end()) {
        stack<int> tempStack = customerRentals[customerID].rentedVideoIDs;
        cout << "List of Videos Rented by Customer ID: " << customerID << "\n";
        
		while (!tempStack.empty()) {
            cout << "Video ID: " << tempStack.top() << "\n";
            tempStack.pop();
            }
        } 
			
	else {
		system("cls");
        cout << "Customer not found!\n";
        Sleep(500);
    }
}
