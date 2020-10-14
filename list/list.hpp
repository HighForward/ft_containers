#include <iostream>
#include <cstddef>

namespace ft
{

	template<class T, class Alloc = std::allocator<T> >
	class list
	{
		private:

			class Node
			{
				public:
					T c;
					Node *prev;
					Node *next;

					Node() {}
					Node(const T &content) : c(content), next(NULL), prev(NULL) {}
			};

			typedef struct	s_list
			{
				Node *first;
				Node *last;
			}				t_list;

			class listIterator
			{
				private:
					Node* n;

				public:

					listIterator() {}
					listIterator(Node *current) : n(current) {}
					listIterator(listIterator *copy) : n(copy->n) {}
					~listIterator() {}

					listIterator& operator++()
					{
						n = n->next;
						return (*this);
					}

					listIterator operator++(int)
					{
						Node* temp = n;
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
						Node* temp = n;
						n = n->prev;
						return (temp);
					}

					T& operator*()
					{
						return (n->c);
					}
			};

		public:
			typedef T value_type;
			typedef T *pointer;
			typedef const T *const_pointer;
			typedef T &reference;

			typedef const T &const_reference;
			typedef Alloc allocator_type;
			typedef std::ptrdiff_t difference_type;

			typedef listIterator iterator;

			typedef size_t size_type;

		private:
			t_list _list;
			allocator_type _allocator;
			size_type _length;
			size_type _capacity;


			void init()
			{
				_list.first = NULL;
				_list.last = NULL;
			}

		public:

			list(const allocator_type &alloc = allocator_type())
			{
				Node *tmp = new Node;
				_allocator = alloc;
				_length = 0;
				_capacity = 0;
//				init(); - check ici -
				_list.first = tmp;
				_list.last = tmp;
			}

			list(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type())
			{
				_allocator = alloc;
				_length = n;
				_capacity = n;
				init();
			}

			~list()
			{
				Node *remove;
				Node *tmp;

				remove = _list.first;
				while (remove != NULL)
				{
					tmp = remove->next;
					delete remove;
					remove = tmp;
				}
				init();
			}

			void push_back(const value_type &val)
			{
				Node *node = new Node(val);
				node->next = NULL;
				node->prev = _list.last;

				if (_list.last != NULL)
					_list.last->next = node;
				else
					_list.first = node;
				_list.last = node;

			}

			void push_front(const value_type &val)
			{
				Node *node = new Node(val);
				node->next = _list.first;
				node->prev = NULL;

				if (_list.first != NULL)
					_list.first->prev = node;
				else
					_list.last = node;
				_list.first = node;
			}

			iterator begin()
			{
				return (iterator(_list.first));
			}

			iterator end()
			{
				return (iterator(_list.last->next));
			}

	};
}