#include <iostream>
#define RED 0
#define BLACK 1
#define FEUILLE NULL

namespace ft {

	template <class T1, class T2>
	struct pair
	{
		typedef T1 first_type;
		typedef T2 second_type;

		T1 first;
		T2	second;

		pair() : first(), second()
		{
			std::cout << "gigabite" << std::endl;
		}

		pair(const first_type& a, const second_type& b) : first(a), second(b)
		{
			std::cout << "ultrabite" << std::endl;
		}
	};

	template <class Key, class T>
	class Node
	{
			typedef Node<Key, T>	node_type;

		private:
			std::pair<Key, T> pair;
			Node *left;
			Node *right;
			Node *parent;
			int color;

		public:
			Node()
			{
				parent = NULL;
				left = NULL;
				right = NULL;
//				pair = NULL;
				color = BLACK;
			}

			Node(const std::pair<Key, T> &val)
			{
				pair = val;
				parent = NULL;
				left = NULL;
				right = NULL;
				color = BLACK;
			}

			Node *getParent()
			{
				return (parent);
			}

			void setParent(node_type *n)
			{
				parent = n;
			}

			Node *getGrandParent()
			{
				if (getParent() != NULL)
					return (parent->getParent());
				else
					return (NULL);
			}

			Node *getBro()
			{
				if (!getParent())
					return NULL;
				if (this == getParent()->left)
					return (getParent()->right);
				else
					return (getParent()->left);
			}

			Node *getUncle()
			{
				if (getGrandParent() == NULL)
					return (NULL);
				return (getParent()->getBro());
			}

			std::pair<Key, T>& getPair()
			{
				return (pair);
			}

			Node *getLeft()
			{
				return (left);
			}

			Node *getRight()
			{
				return (right);
			}

			void setLeft(node_type *n)
			{
				left = n;
			}

			void setRight(node_type *n)
			{
				right = n;
			}

			void black()
			{
				color = BLACK;
			}

			void red()
			{
				color = RED;
			}

			int getColor()
			{
				return (color);
			}

	};

	template<class Key, class T>
	class mapIterator
	{
		private:
			Node<Key, T> *node;
	};


	template<class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<pair<const Key, T> > >
	class map
	{
		public:
			typedef Key 									key_type;
			typedef T										mapped_type;
			typedef std::pair<const key_type, mapped_type>	value_type;
			typedef Compare 								key_compare;
			typedef Alloc									allocator_type;
			typedef mapIterator<key_type, mapped_type>		iterator;
			typedef size_t 									size_type;
			typedef Node<key_type, mapped_type>				node_type;

		public:
			Node<key_type, mapped_type> *root;
			size_type _size;

		public:
			map()
			{
				root = NULL;
				_size = 0;
			}

			void recursive_insert(node_type *curr_node, node_type *n)
			{
				if (root == NULL)
				{
					n->black();
					root = n;
					return;
				}
				if (curr_node != NULL && n->getPair().first < curr_node->getPair().first)
				{
					if (curr_node->getLeft() != FEUILLE)
					{
						recursive_insert(curr_node->getLeft(), n);
						return;
					}
					else
						curr_node->setLeft(n);
				}
				else if (root != NULL && n->getPair().first > curr_node->getPair().first)
				{
					if (curr_node->getRight() != FEUILLE)
					{
						recursive_insert(curr_node->getRight(), n);
						return;
					}
					else
						curr_node->setRight(n);
				}
				n->setParent(curr_node);
			}

			void RotateLeft(node_type *n)
			{
				node_type *nnew = n->getRight();
				node_type *p = n->getParent();

				n->setRight(nnew->getLeft());
				nnew->setLeft(n);
				if (n->getRight() != NULL)
				{
					n->getRight()->setParent(n);
				}

				if (p != NULL)
				{
					if (n == p->getLeft())
					{
						p->setLeft(nnew);
					}
					else if (n == p->getRight())
					{
						p->setRight(nnew);
					}
				}
				nnew->setParent(p);
			}

			void RotateRight(node_type *n)
			{
				node_type *nnew = n->getLeft();
				node_type *p = n->getLeft();

				n->setLeft(nnew->getRight());
				nnew->setRight(n);
				n->setParent(nnew);

				if (n->getLeft() != NULL)
				{
					n->getLeft()->setParent(n);
				}

				if (p != NULL)
				{
					if (n == p->getLeft())
					{
						p->setLeft(nnew);
					}
					else if (n == p->getRight())
					{
						p->setRight(nnew);
					}
				}
				nnew->setParent(p);
			}

			void repair_tree(node_type *n)
			{
				if (n->getParent() == NULL)
					n->black();
				else if (n->getUncle() != NULL && n->getUncle()->getColor() == RED)
				{
					n->getParent()->black();
					n->getUncle()->black();
					n->getGrandParent()->red();
					repair_tree(n->getGrandParent());
				}
				else
				{
					if (n == n->getParent()->getRight() && n->getGrandParent() != NULL && n->getParent() == n->getGrandParent()->getRight())
					{
						RotateLeft(n->getParent());
						n = n->getLeft();
					}
					else if (n == n->getParent()->getLeft() && n->getGrandParent() != NULL && n->getParent() == n->getGrandParent()->getRight())
					{
						RotateRight(n->getParent());
						n = n->getRight();
					}

					node_type *p = n->getParent();
					node_type *g = n->getGrandParent();

//					if (n == p->getLeft())
//					{
//						if (g != NULL)
//							RotateRight(g);
//					}
//					else
//					{
//						RotateLeft(g);
//					}
//					n->getGrandParent()->red();
//					n->getParent()->black();

				}
			}

			void insert(const value_type &val)
			{
				Node<key_type, mapped_type> *new_node = new node_type(val);
				recursive_insert(root, new_node);
				repair_tree(new_node);
				_size++;
//				return NULL;
			}

			size_type size()
			{
				return (_size);
			}

			void clear(node_type *current)
			{
				if (current == NULL)
					return;

				clear(current->getLeft());
				clear(current->getRight());

				std::cout << "delete: " << current->getPair().first << " : " << current->getPair().second << std::endl;
				delete (current);
			}

			void clear()
			{
				clear(root);
			}

			void recursive_print(node_type *current)
			{
				if (current == NULL)
					return;

				recursive_print(current->getLeft());
				recursive_print(current->getRight());

				std::cout << current->getPair().first << " : " << current->getPair().second << std::endl;
			}

			void print()
			{
				recursive_print(root);
			}

	};


}