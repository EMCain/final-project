#include <iostream>
#include <fstream>


using namespace std;




int main()
{

	const int sz = 20;
	int booksCount = 0;
	ofstream inFile;

	inFile.open("booklist.txt");

	while (inFile.eof())
	{
		booksCount++;
	}

	cout << "there are " << booksCount << " in this file";

	inFile.close();
	inFile.clear(std::ios_base::goodbit);
}
