//#include <iostream>
//
//using namespace std;
//
//int main(){
//	int CustomerID, MovieID;
//	char opt;
//	
//	//Loop for the renting action
//	do{
//		//Input the customer ID before renting a movie
//		cout<<"Customer ID: ";
//		cin>>CustomerID;
//		cout<<"\nsample name 1";
//		cout<<"\nsample address 1"<<endl;
//	
//		cout<<"\nVideos to rent..."<<endl; //Display the movies available
//	
//		//Input the movie ID to rent 1 disc
//		cout<<"\nVideo ID: ";
//		cin>>MovieID;
//		cout<<"\nsample movie 1";
//		cout<<"\nsample copies 1"<<endl;	
//		
//		//Loop for the option to run it again
//		do{
//			cout<<endl<<"Rent another Video? ";
//			cin>>opt;
//			
//			switch(opt){
//			case 'Y':
//			case 'y':
//				system("cls");
//				break;
//			case 'N':
//			case 'n':
//				break;
//			default:
//				cin.ignore();
//				cout<<"That is not an option \nPlease press enter to try again..."<<endl;
//				cin.get();
//				system("cls");
//				opt = 'a';
//				break;	
//			}
//		}while(opt == 'a');
//		
//	}while(opt == 'Y' || opt == 'y');
//	
//	cin.ignore();
//	cout<<"\nPress enter to continue...";
//	cin.get();
//	system("cls");
//	
//}
