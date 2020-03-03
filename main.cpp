#include "Interface.h"


int main()
{
	ifstream inFile("system.txt");
	System s("ma'arehet hasachar shel noam and arye", inFile);
	inFile.close();

	startSystem(s);
}