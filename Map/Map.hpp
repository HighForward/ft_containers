#include <iostream>
#define LEAVES NULL

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

		public:
			Node()
			{
				parent = NULL;
				left = NULL;
				right = NULL;
			}

			Node(const std::pair<Key, T> &val)
			{
				pair = val;
				parent = NULL;
				left = NULL;
				right = NULL;
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

			Node* getSuccessor()
            {
			    Node *tmp = left;
			    while (tmp->getRight())
			        tmp = tmp->getRight();
			    return (tmp);
            }

	};

	template<class Key, class T>
	class mapIterator
	{
		public:
			typedef Node<Key, T> node_type;

	    private:
			node_type *node;

		public:
			mapIterator() : node() {}
			mapIterator(node_type *n) : node(n) {}

			mapIterator& operator++()
			{
				if (node->getRight())
				{
					node = node->getRight();
					while (node->getLeft())
						node = node->getLeft();
				}
				else
				{
					node_type *tmp;
					do
					{
						tmp = node;
						node = node->getParent();
					}
					while (node && tmp == node->getRight());
				}
				return (*this);
			}

			mapIterator operator++(int)
            {
			    mapIterator<Key, T>tmp = *this;
			    operator++();
			    return (tmp);
            }

            bool operator!=(mapIterator<Key, T> const &rhs)
            {
                return (this->node != rhs.node);
            }

            node_type *getNode()
            {
			    return (node);
            }

			void print()
			{
				std::cout << node->getPair().first << " : " << node->getPair().second << std::endl;
			}

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

		private:
			Node<key_type, mapped_type> *root;
			size_type _size;

            void recursive_insert(node_type *curr_node, node_type *n)
            {
                if (root == NULL)
                {
                    root = n;
                    return;
                }
                if (curr_node != NULL && n->getPair().first < curr_node->getPair().first)
                {
                    if (curr_node->getLeft() != NULL)
                    {
                        recursive_insert(curr_node->getLeft(), n);
                        return;
                    }
                    else
                        curr_node->setLeft(n);
                }
                else if (root != NULL && n->getPair().first > curr_node->getPair().first)
                {
                    if (curr_node->getRight() != NULL)
                    {
                        recursive_insert(curr_node->getRight(), n);
                        return;
                    }
                    else
                        curr_node->setRight(n);
                }
                n->setParent(curr_node);
            }

		public:
			map()
			{
				root = NULL;
				_size = 0;
			}

			//Iterator
			iterator begin()
			{
				node_type *tmp = root;
				while (tmp->getLeft())
					tmp = tmp->getLeft();
				return (iterator(tmp));
			}

			iterator end()
            {
			    return (iterator(root->getParent()));
            }

			//Capacity

			bool empty() const
			{
				return (_size == 0);
			}

			size_type size()
			{
				return (_size);
			}

			size_type max_size()
			{
				return (0);
			}

			//Element access

			mapped_type& operator[] (const key_type& k)
			{
				node_type *tmp = root;
				while (tmp)
				{
					if (tmp->getPair().first == k)
					{
						return (tmp->getPair().second);
					}
					else if (k < tmp->getPair().first)
					{
						tmp = tmp->getLeft();
						continue;
					}
					else if (k > tmp->getPair().first)
					{
						tmp = tmp->getRight();
						continue;
					}
				}
				value_type n(k, mapped_type());
				insert(n);
				return (operator[](k));
			}

			//Modifiers

			void insert(const value_type &val)
			{
				Node<key_type, mapped_type> *new_node = new node_type(val);
				recursive_insert(root, new_node);
				_size++;
//				return NULL;
			}

			void erase (iterator position)
            {
                node_type *n = position.getNode();
                if (n == NULL)
                    return ;
                else if (n->getRight() == NULL && n->getLeft() == NULL)
                {
                    node_type *p = n->getParent();
                    if (p->getRight() == n)
                        p->setRight(NULL);
                    else
                        p->setLeft(NULL);
                    delete (n);
                }
                else if ((n->getRight() == NULL && n->getLeft() != NULL) || (n->getRight() != NULL && n->getLeft() == NULL))
                {
                    node_type *p = n->getParent();
                    node_type *c;
                    if (n->getRight() != NULL)
                        c = n->getRight();
                    else
                        c = n->getLeft();
                    if (p->getRight() == n)
                        p->setRight(c);
                    else
                        p->setLeft(c);
                    c->setParent(p);
                    delete n;
                }
                else if (n->getLeft() && n->getRight())
                {
                    node_type *tmp = n->getSuccessor();
                    n->getPair() = tmp->getPair();
                    erase(iterator(tmp));
                }

            }





			void recursive_clear(node_type *current)
			{
				if (current == NULL)
					return;
				recursive_clear(current->getLeft());
				recursive_clear(current->getRight());
				delete (current);
			}

			void clear()
			{
				recursive_clear(root);
			}

			void print2D(node_type *root, int space)
            {
			    int COUNT = 7;

			    if (root == NULL)
                    return;

			    space+= COUNT;

			    print2D(root->getRight(), space);

			    std::cout << '\n';
			    for (int i = COUNT; i < space; i++)
			        std::cout << " ";
			    std::cout << root->getPair().first << "->" << root->getPair().second << std::endl;

			    print2D(root->getLeft(), space);
            }

            void print()
            {
			    print2D(root, 0);
            }

	};


}