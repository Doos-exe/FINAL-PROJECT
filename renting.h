#include <string>
#include <queue>
#include <map>
#include <list>
#include <stack>

using namespace std;

struct Customer{
    int customerID;
    string name;
    string address;
};

class CustomerADT{
public:
    queue<Customer> customers;
    int nextCustomerID;

public:
	CustomerADT():
		nextCustomerID(1) {}
		
    void AddCustomer(const string& name, const string& address);
    void CustomerDetails(int customerID);
    void updateNextCustomerID();
    void saveNewCustomerToFile(const Customer& customer);
    void loadCustomerFromFile();
};
struct Video{
    int videoID;
    string title;
    string genre;
    string production;
    int numberOfCopies;
};

class VideoADT {
	public:
    	list<Video> videos;
    	int nextVideoID;
	
    	VideoADT() : nextVideoID(1) {}
    	
    	void addVideo(const string& title, const string& genre, const string& production, int numberOfCopies);
    	void showVideoDetails(int videoID);
    	void saveNewVideoToFile(const Video& video);
    	void displayAllVideos();
    	void checkVideoAvailability(int videoID);
    	void saveAllVideosToFile();
    	void updateNextVideoID();
    	void updateVideoCopies(int videoID, int change);
    	void loadVideoFromFile();
};

class RentADT{
	private:
		struct Rent {
        	int customerID;
        	stack<int> rentedVideoIDs;
    	};
    	
	public:
		map<int, Rent> customerRentals;
		
		void RentVideo(int customerID, int videoID, VideoADT& videoADT);
		void ReturnVideo(int customerID, int videoID, VideoADT& videoADT);
		void printRentedVideos(int customerID,  const queue<Customer>& customers);
		void saveNewRentalToFile(int customerID, int videoID);
		void saveCustomerRentalToFile();
		void loadRentalsFromFile();
		char again();
		
		const map<int, Rent> getCustomerRentals()const{
			return customerRentals;
		}
};