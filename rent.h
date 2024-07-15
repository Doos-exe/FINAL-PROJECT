#include <string>
#include <stack>
#include <map>

using namespace std;

class RentADT{
	private:
		struct Rent {
        	int customerID;
        	stack<int> rentedVideoIDs;
    	};
    	
	public:
		map<int, Rent> customerRentals;
		
		void RentVideo(int customerID, int videoID);
		void ReturnVideo(int customerID, int videoID);
		void printRentedVideos(int customerID,  const queue<Customer>& customers);
		void saveNewRentalToFile(int customerID, int videoID);
		void saveCustomerRentalToFile();
		void loadRentalsFromFile();
		char again();
		
		const map<int, Rent> getCustomerRentals()const{
			return customerRentals;
		}
};
