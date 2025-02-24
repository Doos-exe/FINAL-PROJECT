#include "renting.h"
#include <iostream>
#include <string>
#include <limits>
#include <windows.h>

using namespace std;

int main(){
	CustomerADT customerADT;
    RentADT rentADT;
    VideoADT videoADT;
    string name, address, title, genre, production;
    int customerID, videoID, numberOfCopies, duration, latefee;
    int opta, ans;
	char opt;
	
	customerADT.loadCustomerFromFile();
	rentADT.loadRentalsFromFile();
	videoADT.loadVideoFromFile();
	
	do{
		do{
			cout << "Welcome to WL Renting Store!" << endl;
			cout << "\n--*--*--*--*--*--MAIN MENU--*--*--*--*--*--\n";
	
			cout << "[1] New Video" << endl;
			cout << "[2] Rent a Video" << endl;
			cout << "[3] Return a Video" << endl;
			cout << "[4] Show Video Details" << endl;
			cout << "[5] List of All Videos" << endl;
			cout << "[6] Check Video Availability" << endl;
			cout << "[7] Customer Maintenance" << endl;
			cout << "[8] Exit"<<endl;
		
			while (true){
					cout << "Enter your option: ";
					cin >> opta;
					if (!cin){
						cout << "\nThat is not an option" << endl;
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						continue;	
					}
					else break;
			}
			
			// Main Menu options
			switch(opta){
				case 1:
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
           		 	cout << "Enter video title: ";
            		getline(cin, title);
            		cout << "Enter video genre: ";
            		getline(cin, genre);
            		cout << "Enter video production: ";
            		getline(cin, production);
            		cout << "Enter number of copies: ";
            		cin >> numberOfCopies;
            		videoADT.addVideo(title, genre, production, numberOfCopies);
            		videoADT.saveAllVideosToFile();
					break;
				case 2:
            		cout << "Enter customer ID: ";
            		cin >> customerID;
            		do{
            			cout << "Enter video ID: ";
            			cin >> videoID;
            			rentADT.RentVideo(customerID, videoID, videoADT);
            			videoADT.saveAllVideosToFile();
            			rentADT.saveCustomerRentalToFile();
            			opt = rentADT.again(opta);
					}while (opt == 'Y');
            		
					break;
				case 3:
					do{
            			cout << "Enter customer ID: ";
            			cin >> customerID;
            			cout << "Enter video ID: ";
            			cin >> videoID;
            			rentADT.ReturnVideo(customerID, videoID, videoADT);
            			videoADT.saveAllVideosToFile();
            			rentADT.saveCustomerRentalToFile();
            			opt = rentADT.again(opta);
					}while(opt == 'Y' || opt == 'y');
					break;
				case 4:
            		cout << "Enter video ID: ";
            		cin >> videoID;
            		videoADT.showVideoDetails(videoID);
					break;
				case 5:
					system("cls");
					videoADT.displayAllVideos();
					break;
				case 6:
					cout << "Enter video ID: ";
					cin >> videoID;
					videoADT.checkVideoAvailability(videoID);
					break;
				case 7:
					cin.clear();
					cout << "[1] Add New Customer" << endl;
					cout << "[2] Show Customer Details" << endl;
					cout << "[3] Videos Rented by a Customer" << endl;
					
					while (true){
					cout << "Enter your option: ";
					cin >> opta;
					if (!cin){
						cout << "\nThat is not an option" << endl;
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						continue;	
					}
					else break;
			}
					
					// For the options of Customer Maintenance
					switch(opta){
						case 1:
							cin.ignore();
							system("cls");
                			cout << "Enter Name: ";
                			getline(cin ,name);
                			cout << "Enter Address: ";
                			getline(cin ,address);
                			customerADT.AddCustomer(name, address);
							break;
						case 2:
                			cout << "Enter Customer ID: ";
                			cin >> customerID;
                			cin.clear();
                			cin.ignore(numeric_limits<streamsize>::max(), '\n');
                			customerADT.CustomerDetails(customerID);
							break;
						case 3:
                			cout << "Enter Customer ID: ";
                			cin >> customerID;
                			rentADT.printRentedVideos(customerID, customerADT.customers);
							break;
						default:
							Sleep(500);
							cout<<"That is not an option"<<endl;
							opta = 0;
							system("pause");
							system("cls");
							break;
					}	
					break;
				case 8:
					cout << "Thank you for using our program! <3";
					return 0;
					break;
				default:
					Sleep(500);
					cout << "That is not an option" << endl;
					system("pause");
					opta = 0;
					system("cls");
					break;
			}
			
			
		}while(opta == 0);
		
		// Loop for the option to run it again
		do{
			cout << endl << "Do you want to go back to the Main Menu (Y/N): ";
			cin >> opt;
			
			switch(opt){
			case 'Y':
			case 'y':
				system("cls");
				break;
			case 'N':
			case 'n':
				break;
			default:
				Sleep(500);
				cout << "That is not an option" << endl;
				system("pause");
				system("cls");
				opt = 'a';
				break;	
			}
		}while(opt == 'a');
		
	}while(opt == 'Y' || opt == 'y');
	
	cout << "Thank you for using our program! <3";
	
}
