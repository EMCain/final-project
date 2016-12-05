#include "LinkedList.h"
#include "Book.h"

#include <string>

class Library
{

private:
	LinkedList Booklist;
	LinkedList Users;
	string FilePath;

public:
	//constructors
  Library();
  ~Library();
	void LoadBooksFromFile();
	void SaveBooksToFile();
	void PrintAllBooks(Book* bookPtr ); // total list
	void PrintAvailableBooks(); // all books wiht null checkedOutTo
	void AddUser();
	void LookUpUser(string userName);
  Book* LookUpByID(int id);
};
