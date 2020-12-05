#include <iostream>
#include <cstddef>
#include <limits>
#define LEAVES NULL

//TODO : const iterator; reverse iterator; value_comp; and all iterator operator

namespace ft {

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
			    if (left != NULL)
                {
                    Node *tmp = left;
                    while (tmp->getRight())
                        tmp = tmp->getRight();
                    return (tmp);
                }
			    else
                {
                    Node *tmp = right;
                    while (tmp->getLeft())
                        tmp = tmp->getLeft();
                    return (tmp);
                }
            }

	};

	template<class Key, class T, class value_type>
	class mapIterator
	{
		public:
			typedef Node<Key, T> node_type;

	    private:
			node_type *node;

		public:
			mapIterator() : node() {}
			mapIterator(node_type *n) : node(n) {}
			mapIterator(const mapIterator &i) {
			    this->node = i.node;
			}

			mapIterator& operator=(const mapIterator &copy)
            {
                this->node = copy.node;
                return *this;
            }

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
			    mapIterator<Key, T, value_type>tmp = *this;
			    operator++();
			    return (tmp);
            }

            mapIterator& operator--()
            {
			    if (node->getLeft())
                {
			        node = node->getLeft();
			        while (node && node->getRight())
			            node = node->getRight();
                }
			    else
                {
                    node_type *tmp;
                    do
                    {
                        tmp = node;
                        node = node->getParent();
                    }
                    while (node && tmp == node->getLeft());
                }
			    return (*this);
            }

            mapIterator operator--(int)
            {
                mapIterator<Key, T, value_type>tmp = *this;
                operator--();
                return (tmp);
            }

            bool operator!=(mapIterator<Key, T, value_type> const &rhs)
            {
                return (this->node != rhs.node);
            }

            bool operator==(mapIterator<Key, T, value_type> const &rhs)
            {
                return (this->node == rhs.node);
            }

            value_type operator*()
            {
                return (node->getPair());
            }

            value_type* operator->()
            {
                return (&node->getPair());
            }
	};


	template<class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key, T> > >
	class map
	{
		public:
			typedef Key 									key_type;
			typedef T										mapped_type;
			typedef std::pair<const key_type, mapped_type>	value_type;
			typedef Compare 								key_compare;
			typedef Alloc									allocator_type;
			typedef mapIterator<key_type, mapped_type, value_type>		iterator;
			typedef size_t 									size_type;
			typedef Node<key_type, mapped_type>				node_type;

		private:
			Node<key_type, mapped_type> *root;
			key_compare comp;
			size_type _size;
			allocator_type alloc;

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

            node_type *search_by_key(const key_type &k)
            {
                node_type *tmp = root;
                while (tmp)
                {
                    if (tmp->getPair().first == k)
                        return (tmp);
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
                return (NULL);
            }

            template<typename Type>
            void swap(Type &l, Type &r)
            {
                Type tmp(l);
                l = r;
                r = tmp;
            }

		public:
			map()
			{
				root = NULL;
				_size = 0;
				comp = Compare();
				alloc = Alloc();
			}

			//Iterator
			iterator begin()
			{
				node_type *tmp = root;
				while (tmp->getLeft())
					tmp = tmp->getLeft();
				return (iterator(tmp));
			}

			/*const iterator begin() const*/

			iterator end()
            {
			    return (iterator(root->getParent()));
            }

            /*const iterator end() const*/


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
				return (std::numeric_limits<ptrdiff_t>::max() / sizeof(value_type));
			}

			//Element access

			mapped_type& operator[] (const key_type& k)
			{
				node_type *tmp = root;
				while (tmp)
				{
					if (tmp->getPair().first == k)
						return (tmp->getPair().second);
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

			std::pair<iterator, bool> insert(const value_type &val)
			{
                if (search_by_key(val.first))
                    return (std::pair<iterator, bool>(iterator(search_by_key(val.first)), false));
				Node<key_type, mapped_type> *new_node = new node_type(val);
				recursive_insert(root, new_node);
				_size++;
				return (std::pair<iterator, bool>(iterator(search_by_key(val.first)), true));
			}

			iterator insert(iterator position, const value_type &val)
            {
                (void)position;
                std::pair<iterator, bool> ret = insert(val);
                return (ret.first);
            }

            template<class InputIterator>
            void insert (InputIterator first, InputIterator last)
            {
                while (first != last)
                    insert(*first++);
            }

			void erase (iterator position)
            {

                node_type *n = search_by_key((*position).first);
                if (n == NULL)
                    return ;
                else if (_size == 1 && position == iterator(root))
                {
                    delete (n);
                    root = NULL;
                }
                else if (n->getRight() == NULL && n->getLeft() == NULL)
                {
                    node_type *p = n->getParent();
                    if (p->getRight() == n)
                        p->setRight(NULL);
                    else
                        p->setLeft(NULL);
                    _size--;
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
                    if (n != root)
                    {
                        if (p->getRight() == n)
                            p->setRight(c);
                        else
                            p->setLeft(c);
                        c->setParent(p);
                    }
                    else
                    {
                        root = c;
                        root->setParent(NULL);
                    }
                    _size--;
                    delete (n);
                }
                else if (n->getLeft() && n->getRight())
                {
                    node_type *tmp = n->getSuccessor();
                    n->getPair() = tmp->getPair();
                    erase(iterator(tmp));
                }
            }

            size_type erase(const key_type& k)
            {
                node_type *n;
                if ((n = search_by_key(k)))
                    erase(iterator(n));
                return (0);
            }

            void erase(iterator first, iterator last)
            {
                while (first != last)
                    erase(first++);
            }

            void swap(map& x)
            {
                swap(*this, x);
            }

			void clear()
			{
				erase(begin(), end());
			}


            //Observers

            key_compare key_comp() const
            {
                return (key_compare());
            }

            //value_comp()

            //Operations

            iterator find(const key_type &k)
            {
                node_type *n;
                if ((n = search_by_key(k)))
                    return (iterator(n));
                return (end());
            }

            //const iterator find(const key_type &k)

            size_type count(const key_type &k) const
            {
                if (search_by_key(k))
                    return (1);
                return (0);
            }

            iterator lower_bound(const key_type& k)
            {
                for (iterator it = begin(); it != end(); it++)
                {
                    if (!comp((*it).first, k))
                        return (it);
                }
                return end();
            }

            iterator upper_bound(const key_type& k)
            {
                for (iterator it = begin(); it != end(); it++)
                {
                    if (comp(k, (*it).first))
                        return (it);
                }
                return end();
            }

            std::pair<iterator, iterator> equal_range(const key_type &k)
            {
                return (std::pair<iterator, iterator>(lower_bound(k), upper_bound(k)));
            }

            allocator_type get_allocator() const
            {
                return (alloc);
            }


			void print2D(node_type *n, int space)
            {
			    int COUNT = 7;

			    if (n == NULL)
                    return;

			    space+= COUNT;

			    print2D(n->getRight(), space);

			    std::cout << '\n';
			    for (int i = COUNT; i < space; i++)
			        std::cout << " ";
			    std::cout << n->getPair().first << "->" << n->getPair().second << std::endl;

			    print2D(n->getLeft(), space);
            }

            void print()
            {
			    print2D(root, 0);
            }

	};


}