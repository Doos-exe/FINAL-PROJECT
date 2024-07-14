//#include <iostream>
//
//using namespace std;
//
//int main(){
//	int CustomerID, MovieID;
//	char opt;
//	
//	//Loop for the checking action
//	do{
//		//Input Customer ID of who to check
//		cout<<"Customer ID: ";
//		cin>>CustomerID;
//	
//		cout<<"Name: [print name]"<<endl;
//		cout<<"Address: [print address]"<<endl;
//		
//		cout<<"\nList of Videos rented...\n";
//		
//		//Prints the list
//		cout<<"Video ID     Movie Title"<<endl;
//		
//		for(int n = 0; n < 5; n++){
//			cout<<n+1<<"  "<<"movie"<<n+1<<endl;
//		}
//	
//		//Loop for the option to run it again
//			do{
//				cout<<endl<<"Check with a different ID? ";
//				cin>>opt;
//				
//				switch(opt){
//				case 'Y':
//				case 'y':
//					system("cls");
//					break;
//				case 'N':
//				case 'n':
//					break;
//				default:
//					cin.ignore();
//					cout<<"That is not an option \nPlease press enter to try again..."<<endl;
//					cin.get();
//					system("cls");
//					opt = 'a';
//					break;	
//				}
//			}while(opt == 'a');
//			
//	}while(opt == 'Y' || opt == 'y');
//	
//	cin.ignore();
//	cout<<"\nPress enter to continue...";
//	cin.get();
//	system("cls");
//}