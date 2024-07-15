#include "customer.h"
#include "rent.h"
#include <iostream>
#include <string>
#include <limits>
#include <windows.h>

using namespace std;

int main(){
	CustomerADT customerADT;
    RentADT rentADT;
    string name, address;
    int customerID, videoID;
    int opta, ans;
	char opt;
	
	do{
		do{
			cout << "Welcome to [insert name]!" << endl;
			cout << "\n--*--*--*--*--*--MAIN MENU--*--*--*--*--*--\n";
	
			cout << "[1] New Video" << endl;
			cout << "[2] Rent a Video" << endl;
			cout << "[3] Return a Video" << endl;
			cout << "[4] Show Video Details" << endl;
			cout << "[5] List of All Videos" << endl;
			cout << "[6] Check Video Availability" << endl;
			cout << "[7] Customer Maintenance" << endl;
			cout << "[8] Exit"<<endl;
		
		
			cout<<endl<<"Enter your option: ";
			cin>>opta;
	
			switch(opta){
				case 1:
					//1
					cout << "\n1";
					break;
				case 2:
					system("cls");
					cout << "Enter Customer ID: ";
    				cin >> customerID;
    				ans = customerADT.CustomerDetails(customerID);
					rentADT.RentVideo(customerID, ans);
					break;
				case 3:
					//3
					cout << "\n3";
					break;
				case 4:
					//4
					cout << "\n4";
					break;
				case 5:
					//5
					cout << "\n5";
					break;
				case 6:
					//6
					cout<<"\n6";
					break;
				case 7:
					//7
					cin.clear();
					cout << "[1] Add New Customer" << endl;
					cout << "[2] Show Customer Details" << endl;
					cout << "[3] Videos Rented by a Customer" << endl;
					
					cout << endl << "Enter your option: ";
					cin >> opta;
					
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
                			ans = customerADT.CustomerDetails(customerID);
                			rentADT.printRentedVideos(customerID, ans);
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
					//8
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
			cout << endl << "Do you want to go back to the Main Menu: ";
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
