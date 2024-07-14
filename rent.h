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
    	
    	map<int, Rent> customerRentals;
	public:
		void RentVideo(int customerID, int videoID);
		void ReturnVideo(int customerID, int videoID);
		void printRentedVideos(int customerID);
		
		//void NewVideo();
};
