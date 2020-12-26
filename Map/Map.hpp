#ifndef FT_CONTAINERS_MAPREMAKE_HPP
#define FT_CONTAINERS_MAPREMAKE_HPP

#include "MapIterator.hpp"
#include <cstddef>
#include <iostream>

namespace ft
{
    template<class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key, T> > >
    class map
    {
        public:
            typedef Key key_type;
            typedef T mapped_type;
            typedef std::pair<const key_type, mapped_type> value_type;
            typedef Compare key_compare;
            typedef Alloc allocator_type;

            typedef value_type& reference;
            typedef const value_type& const_reference;
            typedef value_type* pointer;
            typedef const value_type* const_pointer;

            typedef mapIterator <key_type, mapped_type> iterator;
            typedef constMapIterator<key_type, mapped_type> const_iterator;
            typedef reverseMapIterator<key_type, mapped_type> reverse_iterator;
            typedef reverseMapIterator<key_type, mapped_type> const_reverse_iterator;
            typedef size_t size_type;
            typedef std::ptrdiff_t difference_type;
            typedef Node<key_type, mapped_type> node_type;

        private:
            node_type *root;
            key_compare _compare;
            size_type _size;
            allocator_type _allocator;

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

            node_type *search_by_key(const key_type &k) const
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

            void recursive_free(node_type *node)
            {
                if (node == NULL)
                {
                    return;
                }
                this->recursive_free(node->getLeft());
                this->recursive_free(node->getRight());
                delete node;
                node = NULL;
            }

            template<typename Type>
            void swap(Type &l, Type &r)
            {
                Type tmp(l);
                l = r;
                r = tmp;
            }

            node_type* recursive_copy(node_type *node, node_type *dad)
            {
                if (node == NULL) return NULL;
                node_type* newNode = new node_type(node->getPair());

                if (this->root == NULL)
                    newNode->setParent(NULL);
                else
                    newNode->setParent(dad);

                newNode->setLeft(recursive_copy(node->getLeft(), newNode));
                newNode->setRight(recursive_copy(node->getRight(), newNode));
                return newNode;
            }

        public:

            map(const key_compare& comp = key_compare(),
                const allocator_type& alloc = allocator_type())
            {
                root = NULL;
                _size = 0;
                _compare = comp;
                _allocator = alloc;
            }

            template<class InputIterator>
            map (InputIterator first, InputIterator last, const key_compare &comp = key_compare(),
                 const allocator_type &alloc = allocator_type())
            {
                this->_allocator = alloc;
                this->_compare   = comp;
                this->_size = 0;
                this->root = NULL;
                while (first != last)
                {
                    this->insert(*first);
                    first++;
                }
            }

            map(const map& x)
            {
                _size = x._size;
                _compare = x._compare;
                _allocator = x._allocator;
                root = recursive_copy(x.root, this->root);
            }

            ~map()
            {
                this->clear();
            }

            map &operator=(const map &x)
            {
                this->clear();
                this->root = recursive_copy(x.root, this->root);
                return (*this);
            }

            //Iterator
            iterator begin()
            {
                if (root == NULL) return (iterator(root));
                node_type *tmp = root;
                while (tmp->getLeft())
                    tmp = tmp->getLeft();
                return (iterator(tmp));
            }

            const_iterator begin() const
            {
                if (root == NULL) return (const_iterator(root));
                node_type *tmp = root;
                while (tmp->getLeft())
                    tmp = tmp->getLeft();
                return (const_iterator(tmp));
            }

            iterator end()
            {
                if (root == NULL) return (iterator(root));
                return (iterator(root->getParent()));
            }

            const_iterator end() const
            {
                if (root == NULL) return (const_iterator (root));
                return (const_iterator(root->getParent()));
            }

            reverse_iterator rbegin()
            {
                if (root == NULL) return (reverse_iterator(root));
                node_type *tmp = root;
                while (tmp->getRight())
                    tmp = tmp->getRight();
                return (reverse_iterator(tmp));
            }

            reverse_iterator rend()
            {
                if (root == NULL) return (reverse_iterator(root));
                return (reverse_iterator(root->getParent()));
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
                    _size--;
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
                    n->getPair().second = tmp->getPair().second;
                    erase(iterator(tmp));
                }
            }

            size_type erase(const key_type& k)
            {
                node_type *n;
                if ((n = search_by_key(k)))
                    erase(iterator(n));
                return (n == NULL ? 0 : 1);
            }

            void erase(iterator first, iterator last)
            {
                if (first == this->begin() && last == this->end())
                    this->clear();
                else
                {
                    while (first != last)
                        erase((first++)->first);
                }
            }

            void swap(map& x)
            {
                swap(this->root, x.root);
                swap(this->_size, x._size);
            }

            void clear()
            {
                recursive_free(root);
                _size = 0;
                root = NULL;
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

            const_iterator find(const key_type &k) const
            {
                node_type *n;
                if ((n = search_by_key(k)))
                    return (const_iterator(n));
                return (end());
            }

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
                    if (!_compare((*it).first, k))
                        return (it);
                }
                return end();
            }

            const_iterator lower_bound(const key_type& k) const
            {
                for (const_iterator it = begin(); it != end(); it++)
                {
                    if (!_compare((*it).first, k))
                        return (it);
                }
                return end();
            }

            iterator upper_bound(const key_type& k)
            {
                for (iterator it = begin(); it != end(); it++)
                {
                    if (_compare(k, (*it).first))
                        return (it);
                }
                return end();
            }

            const_iterator upper_bound(const key_type& k) const
            {
                for (const_iterator it = begin(); it != end(); it++)
                {
                    if (_compare(k, (*it).first))
                        return (it);
                }
                return end();
            }

            std::pair<iterator, iterator> equal_range(const key_type &k)
            {
                return (std::pair<iterator, iterator>(lower_bound(k), upper_bound(k)));
            }

            std::pair<const_iterator, const_iterator> equal_range(const key_type &k) const
            {
                return (std::pair<const_iterator, const_iterator>(lower_bound(k), upper_bound(k)));
            }

            allocator_type get_allocator() const
            {
                return (_allocator);
            }
    };

    template<class Key, class T, class Compare>
    bool operator== (map<Key, T, Compare> &lhs, map<Key, T, Compare> &rhs)
    {
        if (lhs.size() != rhs.size())
            return (false);
        if (lhs.size() > 0)
        {
            typedef typename map<Key, T, Compare>::iterator iterator;
            iterator rhs_begin = rhs.begin();
            for (iterator lhs_begin = lhs.begin(); lhs_begin != lhs.end(); lhs_begin++)
            {
                if (lhs_begin->first != rhs_begin->first || lhs_begin->second != rhs_begin->second)
                    return (false);
                rhs_begin++;
            }
        }
        return (true);
    }

    template<class Key, class T, class Compare>
    bool operator!= (map<Key, T, Compare> &lhs, map<Key, T, Compare> &rhs)
    {
        return !(lhs == rhs);
    }

    template<class Key, class T, class Compare>
    bool operator< (map<Key, T, Compare> &lhs, map<Key, T, Compare> &rhs)
    {
        if (rhs.empty() || lhs.empty())
            return (lhs.size() < rhs.size());
        typedef typename map<Key, T, Compare>::iterator iterator;
        iterator rhs_begin = rhs.begin();
        for (iterator lhs_begin = lhs.begin(); lhs_begin != lhs.end(); lhs_begin++)
        {
            if (lhs_begin->first != rhs_begin->first || lhs_begin->second != rhs_begin->second)
                return (*lhs_begin < *rhs_begin);
            rhs_begin++;
        }
        return (lhs.size() < rhs.size());
    }

    template<class Key, class T, class Compare> bool operator> (map<Key, T, Compare> &lhs, map<Key, T, Compare> &rhs)
    {
        return (rhs < lhs);
    }

    template<class Key, class T, class Compare>
    bool operator<= (map<Key, T, Compare> &lhs, map<Key, T, Compare> &rhs)
    {
        return !(rhs < lhs);
    }

    template<class Key, class T, class Compare>
    bool operator>= (map<Key, T, Compare> &lhs, map<Key, T, Compare> &rhs)
    {
        return !(lhs < rhs);
    }
}

#endif
