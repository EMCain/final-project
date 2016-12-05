using namespace std;


class User {
	public:
		string userName;
		int* myBookIDs;
		//Book* myBooks;
		int booksCount;

    User();
    User(string name);
    ~User();
};



class Book
{
	public:
		int ID;
		string Title;
		string Author;
		User* CheckedOutTo;

		Book();
		Book(int IdNo, string title, string author);
		~Book();
		void CheckOutTo(User* usrPtr);
		void CheckInFrom(User* usrPtr);
		string ToRecord();

    void SetBookID();
    void SetBookTitle();
    void SetBookAuthor();
};
