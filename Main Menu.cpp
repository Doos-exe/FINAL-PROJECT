#include <iostream>
using namespace std;

int main(){
	char opt;
	int opta;
	
	do{
		do{
			cout<<"Welcome to [insert name]!"<<endl;
			cout<<"\n--*--*--*--*--*--MAIN MENU--*--*--*--*--*--\n";
	
			cout<<"[1] New Video"<<endl;
			cout<<"[2] Rent a Video"<<endl;
			cout<<"[3] Return a Video"<<endl;
			cout<<"[4] Show Video Details"<<endl;
			cout<<"[5] List of All Videos"<<endl;
			cout<<"[6] Check Video Availability"<<endl;
			cout<<"[7] Customer Maintenance"<<endl;
			cout<<"[8] Exit"<<endl;
		
		
			cout<<endl<<"Enter your option: ";
			cin>>opta;
	
			switch(opta){
				case 1:
					1
					cout<<"\n1";
					break;
				case 2:
					2
					cout<<"\n2";
					break;
				case 3:
					3
					cout<<"\n3";
					break;
				case 4:
					4
					cout<<"\n4";
					break;
				case 5:
					5
					cout<<"\n5";
					break;
				case 6:
					6
					cout<<"\n6";
					break;
				case 7:
					7
					cin.clear();
					cout<<"[1] Add New Customer"<<endl;
					cout<<"[2] Show Customer Details"<<endl;
					cout<<"[3] Videos Rented by a Customer"<<endl;
					
					cout<<endl<<"Enter your option: ";
					cin>>opta;
					
					//For the options of Customer Maintenance
					switch(opta){
						case 1:
							7.1
							cout<<"\n7.1";
							break;
						case 2:
							7.2
							cout<<"\n7.2";
							break;
						case 3:
							cout<<"\n7.3";
							7.3
							break;
						default:
							cin.ignore();
							cout<<"That is not an option \nPlease press enter to try again..."<<endl;
							cin.get();
							opta = 0;
							system("cls");
							break;
					}	
					break;
				case 8:
					8
					cout<<"Thank you for using our program! <3";
					return 0;
					break;
				default:
					cin.ignore();
					cout<<"That is not an option \nPlease press enter to try again..."<<endl;
					cin.get();
					opta = 0;
					system("cls");
					break;
			}
			
		}while(opta == 0);
		
		////Loop for the option to run it again
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
				cin.ignore();
				cout<<"That is not an option \nPlease press enter to try again..."<<endl;
				cin.get();
				system("cls");
				opt = 'a';
				break;	
			}
		}while(opt == 'a');
		
	}while(opt == 'Y' || opt == 'y');
	
	cout<<"Thank you for using our program! <3";
	
}