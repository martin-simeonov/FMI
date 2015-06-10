#ifndef _LIST
#define _LIST

template<class T> class List {
	struct Elem {
		T data_;
		Elem* next_;
		Elem* prev_;

		Elem(T val)
			: data_(val),
			next_(0),
			prev_(0)
		{}
		Elem()
			: next_(0),
			prev_(0)
		{}
	};

	Elem* head_;
	Elem* tail_;
public:
	List();
	~List();

	void push_back(const T& val);
	void pop_back();

	T& back();
	T& front();

	int size() const;
	bool empty() const;
	void clear();

	List(const List& other);
	List& operator=(const List& other);
	T& operator[](int index);

	class iterator {
		friend class List;

		Elem* current_;

		iterator(Elem* elem)
			: current_(elem)
		{}
	public:
		iterator& operator++() {
			current_ = current_->next_;
			return *this;
		}

		iterator& operator++(int) {
			current_ = current_->next_;
			return *this;
		}

		bool operator==(const iterator& other) const {
			return current_ == other.current_;
		}

		bool operator!=(const iterator& other) const {
			return !operator==(other);
		}

		T& operator*() {
			return current_->data_;
		}

		T* operator->() {
			return &current_->data_;
		}
	};

	class const_iterator {
		friend class List;

		Elem* current_;

		const_iterator(Elem* elem)
			: current_(elem)
		{}
	public:
		const_iterator& operator++() {
			current_ = current_->next_;
			return *this;
		}

		const_iterator& operator++(int) {
			current_ = current_->next_;
			return *this;
		}

		bool operator==(const const_iterator& other) const {
			return current_ == other.current_;
		}

		bool operator!=(const const_iterator& other) const {
			return !operator==(other);
		}

		const T& operator*() {
			return current_->data_;
		}

		const T* operator->() {
			return &current_->data_;
		}
	};

	iterator begin();
	iterator end();

	const_iterator begin() const;
	const_iterator end() const;

	iterator erase(iterator pos);
};

template<class T>
List<T>::List()
: head_(new Elem),
tail_(new Elem)
{
	head_->next_ = tail_;
	tail_->prev_ = head_;
}

template<class T>
List<T>::~List() {
	while (!empty()) {
		pop_back();
	}

	delete head_;
	delete tail_;
}

template<class T>
void List<T>::push_back(const T& val) {
	Elem* newElem = new Elem(val);

	newElem->prev_ = tail_->prev_;
	newElem->next_ = tail_;

	tail_->prev_->next_ = newElem;
	tail_->prev_ = newElem;
}

template<class T>
void List<T>::pop_back() {
	if (empty()) {
		return;
	}
	else {
		Elem* back = tail_->prev_;
		tail_->prev_ = back->prev_;
		tail_->prev_->next_ = tail_;

		delete back;
	}
}

template<class T>
T& List<T>::back() {
	return tail_->prev_->data_;
}

template<class T>
T& List<T>::front() {
	return head_->next_->data_;
}

template<class T>
int List<T>::size() const {
	int size = 0;

	for (List::const_iterator it = begin(); it != end(); it++) {
		size++;
	}

	return size;
}

template<class T>
bool List<T>::empty() const {
	return head_->next_ == tail_;
}

template<class T>
void List<T>::clear() {
	while (!empty()) {
		pop_back();
	}
}

template<class T>
List<T>::List(const List& other)
: head_(new Elem(0)),
tail_(new Elem(0))
{
	head_->next_ = tail_;
	tail_->prev_ = head_;

	for (List::const_iterator it = other.begin(); it != other.end(); it++) {
		push_back(*it);
	}
}

template<class T>
List<T>& List<T>::operator=(const List& other) {
	if (this != &other) {
		clear();

		for (List::const_iterator it = other.begin(); it != other.end(); it++) {
			push_back(*it);
		}

		return *this;
	}
}

template<class T>
typename List<T>::iterator
List<T>::begin() {
	return iterator(head_->next_);
}

template<class T>
typename List<T>::iterator
List<T>::end() {
	return iterator(tail_);
}

template<class T>
typename List<T>::const_iterator
List<T>::begin() const {
	return const_iterator(head_->next_);
}

template<class T>
typename List<T>::const_iterator
List<T>::end() const {
	return const_iterator(tail_);
}

template<class T>
typename List<T>::iterator
List<T>::erase(iterator pos) {
	Elem* ptr = pos.current_;
	Elem* prev = pos.current_->prev_;
	Elem* next = pos.current_->next_;

	prev->next_ = next;
	next->prev_ = prev;

	delete pos.current_;

	return pos++;
}

template<class T>
T& List<T>::operator[](int index)
{
	if (index >= size() || index < 0)
	{
		std::cout << "Invalid index" << std::endl;
		exit(1);
	}
	else {
		List::iterator it = begin();
		for (int i = 0; i < index; it++, ++i);
		return *it;
	}
}

#endif _LIST