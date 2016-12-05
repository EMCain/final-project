#include <iostream>
#include "Library.h"
#include <fstream>
#include <string.h>

using namespace std;

//LinkedList BookList;

Library::Library(){
  Booklist = LinkedList();
  Users = LinkedList();
  FilePath = "";
}

Library::~Library(){

}


void Library::LoadBooksFromFile()
{

	const int sz = 20;
	int booksCount = 0;
	ifstream inFile;
	char* buff;

  buff = new char[sz];


	inFile.open("booklist.txt");

	//TODO freelinkedlist function to allocate memory

	while (!inFile.eof())
	{
    Book* newBook;
    newBook = new Book;

		inFile >> buff;
		if (buff[0] == 0)
		{
			break;
		}
		buff[strlen(buff) - 1]= 0;


		//set book id
		inFile >> buff;
		buff[strlen(buff) - 1] = 0;
		newBook->SetBookID();

		//set book title
		inFile >> buff;
		buff[strlen(buff) - 1] = 0;
		newBook -> SetBookTitle();

		//set book author
		inFile >> buff;
		buff[strlen(buff) - 1] = 0;
		newBook->SetBookAuthor();

		//add book object to linked list
		Booklist.AddLinkToBack(newBook);


		booksCount++;

    delete newBook;
	}

	inFile.close();
	inFile.clear(std::ios_base::goodbit);
	delete[] buff;




}

void Library::AddUser()
{
	string userName, passWord;
	cout << "\n\nPlease Enter Desired UserName: ";
	cin >> userName;
	cout << "Please Enter Desired Password: ";
	cin >> passWord;

  User u;
  u = User(userName);

	Users.AddLinkToBack(&u);

}

void Library::LookUpUser(string userName)
{

	//ToDo.... how to search for users in the users linked list.
}

void Library::PrintAllBooks(Book* temp)
{


}

void Library::PrintAvailableBooks()
{
	// while (User* checkedOutTo = NULL)
	// {
	// 	cout << temp->ID << "\n";
	// 	cout << temp->Title << "\n";
	// 	cout << temp->Author << "\n";
	// }
  cout << "this will print all the available books." << endl;
}

Book* Library::LookUpByID(int id)
{
  cout << "this will look up the book with id " << endl;
	// int searchID;
  //
	// cout << "\nEnter BookID: ";
	// cin >> searchID;
  //
	// while (temp != NULL)
	// {
	// 	if (searchID == temp->Book::ID)
	// 	{
	// 		cout << temp->ID << "\n";
	// 		cout << temp->Title << "\n";
	// 		cout << temp->Author << "\n";
	// 	}
	// 	else
	// 	{
	// 		cout << "Book Not Found\n\n";
	// 	}
  //
  //
	// }
  return 0;
}
