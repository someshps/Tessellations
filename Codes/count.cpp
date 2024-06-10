#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
	
	ifstream file("facetex3.csv");
	string data = "";
	int c=0;
	char ch = ',';
	while(getline(file, data,'\n'))
	{
	  // cout << data << endl;
		// c=0;
		// while(getline(file, data, '\n')){
		// 	c++;

		// }

		cout<<data.size()<<endl;
		c=0;
		for(int j=0;j<data.size();j++){
			if(data[j]==','){
				c++;	
			}
		}
		
		cout<<"hello there "<<c<<endl;
	}
	
	file.close();/* code */
	return 0;
}
