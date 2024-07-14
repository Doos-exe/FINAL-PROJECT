#include "video.h"
#include "customer.h"
#include "rent.h"
#include <string>
#include <iostream>
#include <limits>
#include <windows.h>

using namespace std;

void CustomerADT::AddCustomer(const string& name, const string& address){
	
	Customer newCustomer = {nextCustomerID++, name, address};
    customers.push(newCustomer);
    
    cout << endl;
	cout << "Customer added successfully!\n";
    cout << "Customer ID: " << newCustomer.customerID << endl;
    cout << "Name       : " << newCustomer.name << endl;
    cout << "Address    : " << newCustomer.address << '\n' << endl;

}

void CustomerADT::CustomerDetails(int customerID){
	    queue<Customer> tempQueue = customers;
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
        }
}

void RentADT::RentVideo(int customerID, int videoID){
	customerRentals[customerID].customerID = customerID;
    customerRentals[customerID].rentedVideoIDs.push(videoID);
    cout << "Video rented successfully!\n";
}

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