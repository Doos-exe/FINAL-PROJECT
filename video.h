#include <string>
#include <list>

using namespace std;

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
    	void saveAllVideosToFile();
    	void updateNextVideoID();
    	void updateVideoCopies(int videoID, int change);
    	void loadVideoFromFile();
};

