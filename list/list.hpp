#include <iostream>
#include <cstddef>

namespace ft
{

	template<typename T>
	class Node
	{
		public:
			T c;
			Node *prev;
			Node *next;

			Node() {}
			Node(const T &content) : c(content), next(NULL), prev(NULL) {}
	};

	template<typename T>
	class listIterator
	{
		private:
			Node<T>* n;

		public:

			listIterator() {}
			listIterator(Node<T> *current) : n(current) {}
			listIterator(listIterator const *copy) : n(copy->n) {}
			~listIterator() {}

			listIterator& operator++()
			{
				n = n->next;
				return (*this);
			}

			listIterator operator++(int)
			{
				Node<T>* temp = n;
				n = n->next;
				return (temp);
			}

			listIterator& operator--()
			{
				n = n->prev;
				return (*this);
			}

			listIterator operator--(int)
			{
				Node<T>* temp = n;
				n = n->prev;
				return (temp);
			}

			bool operator!=(listIterator<T> const &rhs)
			{
				return (this->n != rhs.n);
			}

			T& operator*()
			{
				return (n->c);
			}
	};

	template<class T, class Alloc = std::allocator<T> >
	class list
	{
		public:
			typedef T value_type;
			typedef T *pointer;
			typedef const T *const_pointer;
			typedef T &reference;

			typedef const T &const_reference;
			typedef Alloc allocator_type;
			typedef std::ptrdiff_t difference_type;

			typedef listIterator<T> iterator;
			typedef listIterator<const T> const_iterator;

			typedef size_t size_type;

		private:
			typedef struct	s_list
			{
				Node<T> *first;
				Node<T> *last;
			}				t_list;

			t_list _list;
			allocator_type _allocator;
			size_type _length;

			void init()
			{
				_list.last = NULL;
				_list.first = NULL;
			}

		public:

			list(const allocator_type &alloc = allocator_type())
			{
				_allocator = alloc;
				_length = 0;
				init();
			}

			list(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type())
			{
				_allocator = alloc;
				_length = n;
				init();
			}

			~list()
			{
				Node<T> *remove;
				Node<T> *tmp;

				remove = _list.first;
				while (remove != NULL)
				{
					tmp = remove->next;
					delete remove;
					remove = tmp;
				}
				init();
			}

			//Iterator
			iterator begin()
			{
				return (iterator(_list.first));
			}

			iterator end()
			{
				if (_length == 0)
					return (iterator(_list.first));
				else
					return (iterator(_list.last->next));
			}

			//Capacity
			bool empty() const
			{
				return (_length == 0);
			}

			size_type size() const
			{
				return (_length);
			}

			size_type max_size() const
			{
				//to_do;
				return (0);
			}

			//Element access
			reference front()
			{
				return (_list.first->c);
			}

			const_reference front() const
			{
				return (_list.first->c);
			}

			reference back()
			{
				return (_list.last->c);
			}

			const_reference back() const
			{
				return (_list.last->c);
			}

			//Modifiers
			void push_back(const value_type &val)
			{
				Node<T> *node = new Node<T>(val);
				node->next = NULL;
				node->prev = _list.last;

				if (_list.last != NULL)
					_list.last->next = node;
				else
					_list.first = node;
				_list.last = node;
				_length++;
			}

			void push_front(const value_type &val)
			{
				Node<T> *node = new Node<T>(val);
				node->next = _list.first;
				node->prev = NULL;

				if (_list.first != NULL)
					_list.first->prev = node;
				else
					_list.last = node;
				_list.first = node;
				_length++;
			}

			void pop_back()
			{
				Node<T> *tmp = _list.last->prev;
				delete _list.last;
				_list.last = tmp;
				_length--;
			}

			void pop_front()
			{
				Node<T> *tmp = _list.first->next;
				delete _list.first;
				_list.first = tmp;
				_length--;
			}


	};
}