#include <iostream>
using namespace std;

template <class T>
class List
{
	struct node
	{
		T data_;
		node *next_;
		node *prev_;

		node(T data)
			: data_(data), next_(NULL), prev_(NULL)
		{}
	};

	node *head_;
	node *tail_;
public:
	List();
	~List();

	bool isEmpty();
	void push_back(T val);
	void pop_back();

	void print();
};

template <class T>
List<T>::List()
: head_(new node(0)), tail_(new node(0))
{
	head_->next_ = tail_;
	head_->prev_ = head_;
	tail_->next_ = tail_;
	tail_->prev_ = head_;
}

template <class T>
List<T>::~List()
{
	while (!isEmpty())
	{
		pop_back();
	}

	delete head_;
	delete tail_;
}

template <class T>
bool List<T>::isEmpty()
{
	return head_->next_ == tail_;
}

template <class T>
void List<T>::push_back(T val)
{
	node* newNode = new node(val);
	newNode->prev_ = tail_->prev_;
	newNode->next_ = tail_;

	tail_->prev_->next_ = newNode;
	tail_->prev_ = newNode;
}

template <class T>
void List<T>::pop_back()
{
	if (!isEmpty())
	{
		node* last = tail_->prev_;
		tail_->prev_ = last->prev_;
		tail_->prev_->next_ = tail_;

		delete last;
	}
}

template <class T>
void List<T>::print()
{
	node* cur = head_->next_;
	while (cur != tail_)
	{
		cout << cur->data_ << endl;
		cur = cur->next_;
	}
}

int main()
{
	List<int> l;
	l.print();

	l.push_back(3);
	l.push_back(4);
	l.print();
	l.pop_back();
	l.print();

	return 0;
}