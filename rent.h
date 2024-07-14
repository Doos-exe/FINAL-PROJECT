#include <string>
#include <stack>

using namespace std;

class Rent
{
	private:
		stack<string> movie;
	public:
		void push(char m);
		void pop();
		char top();
		int pushpop(string movie);
		bool empty();
		
		void NewVideo();
		void RentVideo();
		void ReturnVideo();
};