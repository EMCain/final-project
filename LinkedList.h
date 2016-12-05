

struct Node
{
	void* data_;
	Node* next_;

	Node()
	{
		data_ = 0;
		next_ = 0;
	}
};

class LinkedList
{
private:
	Node* first;
	Node* last;
	Node* curNode;
	long listLen;

public:
	LinkedList();
	~LinkedList();
	void AddLinkToBack(void* ptr);
	void* RemoveLinkFromFront();
	void* GetFirstNode();
	void* GetNextNode();
	long GetListLength();
};

