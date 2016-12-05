#include <iostream>
#include "Book.h"

using namespace std;

int MAX_BOOKS = 10;

User::User() {
		userName = "unknown name";
		myBookIDs = new int[MAX_BOOKS];
		booksCount = 0;
	}

User::User(string name) {
		userName = name;
		myBookIDs = new int[MAX_BOOKS];
		booksCount = 0;
	}

User::~User(){
		//int* curBooksPtr = myBookIDs;
    delete myBookIDs;
/*		while (curBooksPtr) {
			//myBookIDs[*curBooksPtr].CheckedOutTo = 0;
			// TODO find a way to avoid import loops and access the books of a given number here. Will probably call on the Library class.
			curBooksPtr++;
		}
*/
		// delete myBookIDs;
	}


Book::Book(){
	Title = "untitled";
	Author = "Anonymous";
	CheckedOutTo = 0;
	ID = -1; // should be immedately updated on creation
}

Book::Book(int idNo, string title, string author){
	Title = title;
	Author = author;
	CheckedOutTo = 0;
	ID = idNo;
}

Book::~Book(){
	// currently do nothing because there are no dynamic pointers in Book
}

void Book::CheckOutTo(User* userPtr){
	// determine if book is already checked out
	if (CheckedOutTo) {
		cout << "The book is already checked out to " << CheckedOutTo->userName << endl;
	} else if (userPtr->booksCount >= MAX_BOOKS) {
		cout << "This user has too many books out." << endl;
	} else {
		CheckedOutTo = userPtr;
		userPtr->booksCount++;
	}
}

void Book::CheckInFrom(User* userPtr){
	if (CheckedOutTo == userPtr) {
		CheckedOutTo = 0;
		userPtr->booksCount--;
	} else {
		cout << "Could not check in because " << Title << " is not checked out to " << userPtr->userName << endl;
	}
}
string Book::ToRecord() {
	return ID + ", " + Title + ", " + Author;
}

void Book::SetBookID() {
  cout << "This will set the book ID.";
}

void Book::SetBookTitle() {
  cout << "This will set the book title.";
}

void Book::SetBookAuthor() {
  cout << "This will set the book author.";
}
