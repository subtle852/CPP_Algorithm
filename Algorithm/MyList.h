#pragma once

template<typename T>
class NodeForList
{
public:
	NodeForList() : _prev(nullptr), _next(nullptr), _data(T())
	{

	}

	NodeForList(const T& value) : _prev(nullptr), _next(nullptr), _data(value)
	{

	}

public:
	NodeForList* _prev;
	NodeForList* _next;
	T		_data;
};

template<typename T>
class Iterator
{
public:
	Iterator() : _node(nullptr)
	{

	}

	Iterator(NodeForList<T>* node) : _node(node)
	{

	}

	// ++it
	Iterator& operator++()
	{
		_node = _node->_next;
		return *this;
	}

	// it++
	Iterator operator++(int)
	{
		Iterator<T> temp = *this;
		_node = _node->_next;
		return temp;
	}

	// --it
	Iterator& operator--()
	{
		_node = _node->_prev;
		return *this;
	}

	// it--
	Iterator operator--(int)
	{
		Iterator<T> temp = *this;
		_node = _node->_prev;
		return temp;
	}

	// *it
	T& operator*()
	{
		return _node->_data;
	}

	bool operator==(const Iterator& other)
	{
		return _node == other._node;
	}

	bool operator!=(const Iterator& other)
	{
		return _node != other._node;
	}

public:
	NodeForList<T>* _node;
};

template<typename T>
class MyList
{
public:
	MyList() : _size(0)
	{
		// [head] <-> ... <-> [tail]
		_head = new NodeForList<T>();
		_tail = new NodeForList<T>();
		_head->_next = _tail;
		_tail->_prev = _head;
	}

	~MyList()
	{
		while (_size > 0)
			pop_back();

		delete _head;
		delete _tail;
	}

	void push_back(const T& value)
	{
		AddNode(_tail, value);
	}

	void pop_back()
	{
		RemoveNode(_tail->_prev);
	}

private:

	// [head] <-> [1] <-> [prevNode] <-> [before] <-> [tail]
	// [head] <-> [1] <-> [prevNode] <-> [newNode] <-> [before] <-> [tail]
	NodeForList<T>* AddNode(NodeForList<T>* before, const T& value)
	{
		NodeForList<T>* newNode = new NodeForList<T>(value);
		NodeForList<T>* prevNode = before->_prev;

		prevNode->_next = newNode;
		newNode->_prev = prevNode;

		newNode->_next = before;
		before->_prev = newNode;

		_size++;

		return newNode;
	}

	// [head] <-> [prevNode] <-> [node] <-> [nextNode] <-> [tail]
	// [head] <-> [prevNode] <-> [nextNode] <-> [tail]
	NodeForList<T>* RemoveNode(NodeForList<T>* node)
	{
		NodeForList<T>* prevNode = node->_prev;
		NodeForList<T>* nextNode = node->_next;

		prevNode->_next = nextNode;
		nextNode->_prev = prevNode;

		delete node;

		_size--;

		return nextNode;
	}

	int size() { return _size; }

public:
	using iterator = Iterator<T>;

	iterator begin() { return iterator(_head->_next); }
	iterator end() { return iterator(_tail); }

	iterator insert(iterator it, const T& value)// it '�տ�' �߰�
	{
		NodeForList<T>* node = AddNode(it._node, value);
		return iterator(node);
	}

	iterator erase(iterator it)
	{
		NodeForList<T>* node = RemoveNode(it._node);
		return iterator(node);
	}

private:
	NodeForList<T>* _head;
	NodeForList<T>* _tail;
	int			_size;
};
