#include "video.h"
#include "customer.h"
#include "rent.h"
#include <string>
#include <iostream>
#include <limits>
#include <list>
#include <windows.h>
#include <fstream>

using namespace std;

// function for adding customers
void CustomerADT::AddCustomer(const string& name, const string& address){
	Customer newCustomer = {nextCustomerID++, name, address};
    customers.push(newCustomer);
    saveNewCustomerToFile(newCustomer);
    
    cout << endl;
	cout << "Customer added successfully!\n";
    cout << "Customer ID: " << newCustomer.customerID << endl;
    cout << "Name       : " << newCustomer.name << endl;
    cout << "Address    : " << newCustomer.address << '\n' << endl;

}

// function for customer details
void CustomerADT::CustomerDetails(int customerID){
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
}

// function to update the next customer
void CustomerADT::updateNextCustomerID(){
	int maxID = 0;
    queue<Customer> tempQueue = customers;
        
	while (!tempQueue.empty()) {
        Customer current = tempQueue.front();
        tempQueue.pop();
        
		if (current.customerID > maxID) {
            maxID = current.customerID;
        }
    }
    
	nextCustomerID = maxID + 1;
}

// fuction for file handling of customer
void CustomerADT::saveNewCustomerToFile(const Customer& customer) {
    ofstream outfile("customers.txt");
    if (outfile.is_open()) {
        queue<Customer> tempQueue = customers;
        
		while (!tempQueue.empty()) {
            Customer current = tempQueue.front();
            tempQueue.pop();
            outfile << current.customerID << " " << current.name << "," << current.address << endl;
        }
    outfile.close();
    }
}

// function for adding video
void VideoADT::addVideo(const string& title, const string& genre, const string& production, int numberOfCopies) {
        Video newVideo = {nextVideoID++, title, genre, production, numberOfCopies};
        videos.push_back(newVideo);
        system("cls");

        cout << "Video added successfully!\n";
        cout << "Video ID      : " << newVideo.videoID << endl;
        cout << "Title         : " << newVideo.title << endl;
        cout << "Genre         : " << newVideo.genre << endl;
        cout << "Production    : " << newVideo.production << endl;
        cout << "No. of Copies : " << newVideo.numberOfCopies << '\n' << endl;
}

// function for showing video details
void VideoADT::showVideoDetails(int videoID) {
    bool found = false;
    for (const auto& video : videos) {
        if (video.videoID == videoID) {
            system("cls");
            cout << "Video Details\n";
            cout << "Video ID      : " << video.videoID << "\n";
            cout << "Title         : " << video.title << "\n";
            cout << "Genre         : " << video.genre << "\n";
            cout << "Production    : " << video.production << "\n";
            cout << "No. of Copies : " << video.numberOfCopies << "\n";
            system("pause");
            cout << "\n";
            found = true;
            break;
        }
    }
        
	if (!found) {
        system("cls");
        cout << "\nVideo not found!\n\n";
        Sleep(500);
	}
}

// function for displaying all videos
void VideoADT::displayAllVideos() {
    cout << "All Videos:" << endl;
    for (const auto& video : videos) {
        cout << "Video ID: " << video.videoID << endl;
        cout << "Title: " << video.title << endl;
        cout << "Genre: " << video.genre << endl;
        cout << "Production: " << video.production << endl;
        cout << "-----------------------------" << endl;
    }
}

// function for checking video availability
void VideoADT::checkVideoAvailability(int videoID) {
    bool found = false;
    for (const auto& video : videos) {
        if (video.videoID == videoID) {
            system("cls");
            cout << "Video Details\n";
            cout << "Video ID      : " << video.videoID << "\n";
            cout << "Title         : " << video.title << "\n";
            cout << "Genre         : " << video.genre << "\n";
            cout << "Production    : " << video.production << "\n";
            cout << "No. of Copies : " << video.numberOfCopies << "\n";
            
            if (video.numberOfCopies > 0) {
                cout << "Availability  : Available\n";
            } else {
                cout << "Availability  : Not Available\n";
            }
            
            system("pause");
            cout << "\n";
            found = true;
            break;
        }
    }
        
	if (!found) {
        system("cls");
        cout << "\nVideo not found!\n\n";
        Sleep(500);
	}
}

// function for file handling of videos
void VideoADT::saveNewVideoToFile(const Video& video) {
	ofstream outfile("videos.txt", ios::app);
    if (outfile.is_open()) {
        outfile << video.videoID << " " << video.title << "," << video.genre << endl;
        outfile.close();
    }
}

// function to update the next video
void VideoADT::updateNextVideoID() {
    int maxID = 0;
    for (const auto& video : videos) {
        if (video.videoID > maxID) {
            maxID = video.videoID;
        }
    }
    
	nextVideoID = maxID + 1;
}

// function for copies of videos
void VideoADT::updateVideoCopies(int videoID, int change) {
    for (auto& video : videos) {
        if (video.videoID == videoID) {
        	video.numberOfCopies += change;
            break;
        }
    }
}

// function to save videos as txt file
void VideoADT::saveAllVideosToFile() {
    ofstream outfile("videos.txt");
    if (outfile.is_open()) {
        for (const auto& video : videos) {
            outfile << video.videoID << " " << video.title << "," << video.genre << "," << video.production << "," << video.numberOfCopies << endl;
        }
    	outfile.close();
    }
}

// function for renting videos
void RentADT::RentVideo(int customerID, int videoID){
	VideoADT videoADT;
	for (auto& video : videoADT.videos) {
        if (video.videoID == videoID && video.numberOfCopies > 0) {
            customerRentals[customerID].customerID = customerID;
            customerRentals[customerID].rentedVideoIDs.push(videoID);
            video.numberOfCopies--;
            cout << "Video rented successfully!\n";
            return;
        }
    }
    
	cout << "No copies available for rent!\n";
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
        } 
		
		else {
            cout << "Customer not found!\n";
        }
}

// function for rented videos of a customer
void RentADT::printRentedVideos(int customerID, const queue<Customer>& customers) {
	bool customerExists = false;
    queue<Customer> tempQueue = customers;
    
	while (!tempQueue.empty()) {
        if (tempQueue.front().customerID == customerID) {
            customerExists = true;
            break;
        }
    
		tempQueue.pop();
    }

    if (customerExists) {
        if (customerRentals.find(customerID) != customerRentals.end() && !customerRentals[customerID].rentedVideoIDs.empty()) {
            map<int, int> videoCount;
            stack<int> tempStack = customerRentals[customerID].rentedVideoIDs;
            while (!tempStack.empty()) {
                int videoID = tempStack.top();
                tempStack.pop();
                videoCount[videoID]++;
            }

        	system("cls");
            cout << "List of Videos Rented by Customer ID: " << customerID << "\n";
            
			for (const auto& pair : videoCount) {
                cout << "Video ID: " << pair.first << ", " << pair.second << " copies rented\n";
            }
            system("pause");
        } 
		
		else {
            system("cls");
            cout << "\nNo rented videos found for this customer.\n\n";
            Sleep(500);
        }
    } 
	
	else {
        system("cls");
        cout << "\nCustomer not found!\n\n";
        Sleep(500);
    }
}

// function for file handling of rents
void RentADT::saveNewRentalToFile(int customerID, int videoID){
	ofstream outfile("rentals.txt", ios::app);
	
    if (outfile.is_open()) {
        outfile << customerID << " " << videoID << endl;
        outfile.close();
    }
}

// function for file handling of rents
void RentADT::saveCustomerRentalToFile() {
    ofstream outfile("customer_rent.txt");
    if (outfile.is_open()) {
        for (const auto& pair : customerRentals) {
            outfile << pair.first << " ";
            stack<int> tempStack = pair.second.rentedVideoIDs;
            while (!tempStack.empty()) {
                outfile << tempStack.top() << " ";
                tempStack.pop();
            }
            
			outfile << endl;
        }
        outfile.close();
    }
}

// functions for load files of each ADT

void CustomerADT::loadCustomerFromFile(){
	ifstream infile("customers.txt");
    if (infile.is_open()) {
        int id;
        string name, address;
        
		while (infile >> id >> ws && getline(infile, name, ',') && getline(infile, address)) {
            customers.push({id, name, address});
        }
        
		infile.close();
        updateNextCustomerID();
    }
}

void VideoADT::loadVideoFromFile(){
	ifstream infile("videos.txt");
    if (infile.is_open()) {
        int id, copies;
        string title, genre, production;
        
		while (infile >> id >> ws && getline(infile, title, ',') && getline(infile, genre, ',') && getline(infile, production, ',') && infile >> copies) {
            videos.push_back({id, title, genre, production, copies});
        }
            
		infile.close();
        updateNextVideoID();
    }
}

void RentADT::loadRentalsFromFile(){
	ifstream infile("customer_rent.txt");
    if (infile.is_open()) {
        int customerID, videoID;
        while (infile >> customerID) {
            Rent rent;
            rent.customerID = customerID;
            while (infile >> videoID && videoID != -1) {
                rent.rentedVideoIDs.push(videoID);
            }
            
			customerRentals[customerID] = rent;
        }
    
	infile.close();
    }
}


// function for again option
char RentADT::again(){
	char opt;
	do{
		cout<<endl<<"Do you want to try again? ";
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
				cout<<"That is not an option"<<endl;
				system("pause");
				system("cls");
				opt = 'a';
				break;	
			}
	}while(opt == 'a');
	
	return opt;
}
