#include <iostream>
#include "Library.h"

using namespace std;

//Function protocals

char LogInMenu();
char MainMenu();
void MainMenuSelection();
void LogIn();
void Register();
void LoadBookList();
void CheckIn();
void CheckOut();
void DisplayBooks();
void DisplayLibrary();
void DisplayUserInfo();

User* currentUser;
Library myLib;

int main()
{
	myLib = Library();
	currentUser = 0;
	bool terminate = false;
	char selection;

	while (!terminate)
	{
		selection = LogInMenu();

		switch (selection)
		{
			case 'a':
				LogIn();
				// ask for user name and set currentUser to it if exists; otherwise prompt again
				break;
			case 'b':
				Register();
				// create a user and set currentUser to it
				break;
			case 'c':
				terminate=true;
				break;
			default:
				cout << "This is not a valid choice, try again\n\n";
		}

	}
  return 0;
}

void LogIn() {
  cout << "this will log in" << endl;
}

void Register() {
  cout << "this will register a user" << endl;
}

void DisplayUserInfo() {
  cout << "this will display user info" << endl;
}

char LogInMenu()
{
	char selection = '1';

	cout <<"*********MENU**********\n";
	cout <<"Please Make A Selection\n\n";
	cout <<"a) log In\n";
	cout <<"b) Register\n\n";
	cout <<"Your Selection: ";
	cin >> selection;

	return tolower(selection);

}

char MainMenu()
{
	char selection = '1';

	cout <<"*********MENU**********\n";
	cout <<"Please Make A Selection\n\n";
	cout <<"a)Display All Library Books Available\n";
	cout <<"b)Check Out Books\n";
	cout <<"c)Check In Books\n";
	cout <<"d)Display User Information\n\n";
	cout <<"Your Selection: ";
	cin  >> selection;

	return tolower(selection);

}

void MainMenuSelection() // would the LogIn function call this? after a successful log in?
{
	bool terminate = false;
	char selection;

	while (!terminate)
	{
		selection = LogInMenu();

		switch (selection)
		{
			case 'a':
				DisplayBooks();
				break;
			case 'b':
				CheckOut();
				break;
			case 'c':
				CheckIn();
				break;
			case 'd':
				DisplayUserInfo();
			case 'e':
				terminate=true;
				break;
			default:
				cout << "This is not a valid choice, try again\n\n";
		}

	}
}

void DisplayBooks(){
	cout << "Here are the books available for checkout: " << endl;
	myLib.PrintAvailableBooks();
}

void CheckOut(){
	cout << "Enter the ID of the book you want to check out." << endl;
	Book* toCheckOut = 0;
	int id = 0;
	while(!toCheckOut) {
		cin >> id;
		toCheckOut = myLib.LookUpByID(id); // TODO create this function
		if(!toCheckOut) {
			cout << "Title not valid! Try again." << endl;
		} else {
			toCheckOut->CheckOutTo(currentUser);
		}
	}
}

void CheckIn() {
	cout << "Here are your checked out books." << endl;
	int* books = currentUser->myBookIDs;
	for(int i = 0; i < sizeof(currentUser->myBookIDs); i++) {
		cout << myLib.LookUpByID(currentUser->myBookIDs[i])->ToRecord();
	}
	char* checkIn;
	int bookId;
  Book* myBook;

	while(checkIn) {
		cout << "Please enter the ID of the book you wish to check in, or 0 to quit and return to main menu." << endl;
		cin >> checkIn;
		bookId = atoi(checkIn);
		myBook = myLib.LookUpByID(bookId);
		myBook->CheckInFrom(currentUser);
	}
}
