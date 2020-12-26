#ifndef FT_CONTAINERS_MAPITERATOR_HPP
#define FT_CONTAINERS_MAPITERATOR_HPP

#include <cstddef>
#include <iostream>
#include <limits>

namespace ft
{
    template<class Key, class T>
    class Node
    {
            typedef Node<Key, T> node_type;
            typedef std::pair<const Key, T> value_type;

        private:
            value_type pair;
            Node *left;
            Node *right;
            Node *parent;

        public:
            Node() : pair()
            {
                parent = NULL;
                left = NULL;
                right = NULL;
            }

            Node(const value_type &val) : pair(val)
            {
                parent = NULL;
                left = NULL;
                right = NULL;
            }

            value_type &getPair() { return (pair); }
            void setParent(node_type *n) { parent = n; }
            void setLeft(node_type *n) { left = n; }
            void setRight(node_type *n) { right = n; }
            Node *getParent() { return (parent); }
            Node *getLeft() { return (left); }
            Node *getRight() { return (right); }

            Node *getGrandParent()
            {
                if (getParent() != NULL) return (parent->getParent());
                else return (NULL);
            }

            Node *getBro()
            {
                if (!getParent()) return NULL;
                if (this == getParent()->left) return (getParent()->right);
                else return (getParent()->left);
            }

            Node *getUncle()
            {
                if (getGrandParent() == NULL) return (NULL);
                return (getParent()->getBro());
            }

            Node *getSuccessor()
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

    template<class Key, class T>
    class constMapIterator;

    template<class Key, class T>
    class mapIterator
    {
        public:
            typedef Node<Key, T> node_type;
            typedef std::pair<const Key, T> value_type;

            node_type *_M_node;

        public:
            mapIterator() : _M_node() {}
            mapIterator(node_type *n) : _M_node(n) {}
            mapIterator(const mapIterator &i) { this->_M_node = i._M_node; }

            mapIterator(const constMapIterator<Key, T> &x) { this->_M_node = x._M_node; }
            operator constMapIterator<Key, T>() { return (constMapIterator<Key, T>(this->_M_node)); }
            mapIterator &operator=(const constMapIterator<Key, T> &x) { this->_M_node = x._M_node; return (*this); }


            mapIterator& operator=(const mapIterator &copy) { this->_M_node = copy._M_node; return *this; }

            mapIterator& operator++()
            {
                if (_M_node->getRight())
                {
                    _M_node = _M_node->getRight();
                    while (_M_node->getLeft())
                        _M_node = _M_node->getLeft();
                }
                else
                {
                    node_type *tmp;
                    do
                    {
                        tmp = _M_node;
                        _M_node = _M_node->getParent();
                    }
                    while (_M_node && tmp == _M_node->getRight());
                }
                return (*this);
            }

            mapIterator operator++(int)
            {
                mapIterator<Key, T>tmp = *this;
                operator++();
                return (tmp);
            }

            mapIterator& operator--()
            {
                if (_M_node->getLeft())
                {
                    _M_node = _M_node->getLeft();
                    while (_M_node && _M_node->getRight())
                        _M_node = _M_node->getRight();
                }
                else
                {
                    node_type *tmp;
                    do
                    {
                        tmp = _M_node;
                        _M_node = _M_node->getParent();
                    }
                    while (_M_node && tmp == _M_node->getLeft());
                }
                return (*this);
            }

            mapIterator operator--(int)
            {
                mapIterator<Key, T>tmp = *this;
                operator--();
                return (tmp);
            }

            value_type operator*() { return (_M_node->getPair()); }
            value_type* operator->() { return (&_M_node->getPair()); }

            bool operator!=(mapIterator<Key, T> const &rhs) { return (this->_M_node != rhs._M_node); }
            bool operator==(mapIterator<Key, T> const &rhs) { return (this->_M_node == rhs._M_node); }
            bool operator<(const mapIterator &rhs) const { return _M_node < rhs._M_node; }
            bool operator>(const mapIterator &rhs) const { return _M_node > rhs._M_node; }
            bool operator<=(const mapIterator &rhs) const { return _M_node >= rhs._M_node; }
            bool operator>=(const mapIterator &rhs) const { return _M_node <= rhs._M_node; }
    };


    template<class Key, class T>
    class constMapIterator
    {
        public:
            typedef Node<Key, T> node_type;
            typedef std::pair<const Key, T> value_type;

            node_type *_M_node;

        public:
            constMapIterator() : _M_node() {}
            constMapIterator(node_type *n) : _M_node(n) {}
            constMapIterator(const constMapIterator &i) { this->_M_node = i._M_node; }

            constMapIterator(const mapIterator<Key, T> &x) { this->_M_node = x._M_node; }
            operator mapIterator<Key, T>() { return (mapIterator<Key, T>(this->_M_node)); }
            constMapIterator& operator=(const mapIterator<Key, T> &x) { this->_M_node = x._M_node; return (*this); }
            constMapIterator& operator=(const constMapIterator &x) { this->_M_node = x._M_node; return (*this); }

            constMapIterator& operator++()
            {
                if (_M_node->getRight())
                {
                    _M_node = _M_node->getRight();
                    while (_M_node->getLeft())
                        _M_node = _M_node->getLeft();
                }
                else
                {
                    node_type *tmp;
                    do
                    {
                        tmp = _M_node;
                        _M_node = _M_node->getParent();
                    }
                    while (_M_node && tmp == _M_node->getRight());
                }
                return (*this);
            }

            constMapIterator operator++(int)
            {
                mapIterator<Key, T>tmp = *this;
                operator++();
                return (tmp);
            }

            constMapIterator& operator--()
            {
                if (_M_node->getLeft())
                {
                    _M_node = _M_node->getLeft();
                    while (_M_node && _M_node->getRight())
                        _M_node = _M_node->getRight();
                }
                else
                {
                    node_type *tmp;
                    do
                    {
                        tmp = _M_node;
                        _M_node = _M_node->getParent();
                    }
                    while (_M_node && tmp == _M_node->getLeft());
                }
                return (*this);
            }

            constMapIterator operator--(int)
            {
                mapIterator<Key, T>tmp = *this;
                operator--();
                return (tmp);
            }

            const value_type operator*() { return (_M_node->getPair()); }
            const value_type* operator->() { return (&_M_node->getPair()); }

            bool operator!=(constMapIterator<Key, T> const &rhs) { return (this->_M_node != rhs._M_node); }
            bool operator==(constMapIterator<Key, T> const &rhs) { return (this->_M_node == rhs._M_node); }
            bool operator<(const constMapIterator &rhs) const { return _M_node < rhs._M_node; }
            bool operator>(const constMapIterator &rhs) const { return _M_node > rhs._M_node; }
            bool operator<=(const constMapIterator &rhs) const { return _M_node >= rhs._M_node; }
            bool operator>=(const constMapIterator &rhs) const { return _M_node <= rhs._M_node; }
    };

    template<class Key, class T>
    class constReverseMapIterator;

    template<class Key, class T>
    class reverseMapIterator
    {
        public:
            typedef Node<Key, T> node_type;
            typedef std::pair<const Key, T> value_type;

            node_type *_M_node;

        public:
            reverseMapIterator() : _M_node() {}
            reverseMapIterator(node_type *n) : _M_node(n) {}
            reverseMapIterator(const reverseMapIterator &i) { this->_M_node = i._M_node; }

            reverseMapIterator(const constReverseMapIterator<Key, T> &x) { this->_M_node = x._M_node; }
            operator constReverseMapIterator<Key, T>() { return (constReverseMapIterator<Key, T>(this->_M_node)); }
            reverseMapIterator& operator=(const constReverseMapIterator<Key, T> &x) { this->_M_node = x._M_node; return (*this); }
            reverseMapIterator& operator=(const reverseMapIterator &copy) { this->_M_node = copy._M_node; return *this; }

            reverseMapIterator& operator--()
            {
                if (_M_node->getRight())
                {
                    _M_node = _M_node->getRight();
                    while (_M_node->getLeft())
                        _M_node = _M_node->getLeft();
                }
                else
                {
                    node_type *tmp;
                    do
                    {
                        tmp = _M_node;
                        _M_node = _M_node->getParent();
                    }
                    while (_M_node && tmp == _M_node->getRight());
                }
                return (*this);
            }

            reverseMapIterator operator--(int)
            {
                mapIterator<Key, T>tmp = *this;
                operator--();
                return (tmp);
            }

            reverseMapIterator& operator++()
            {
                if (_M_node->getLeft())
                {
                    _M_node = _M_node->getLeft();
                    while (_M_node && _M_node->getRight())
                        _M_node = _M_node->getRight();
                }
                else
                {
                    node_type *tmp;
                    do
                    {
                        tmp = _M_node;
                        _M_node = _M_node->getParent();
                    }
                    while (_M_node && tmp == _M_node->getLeft());
                }
                return (*this);
            }

            reverseMapIterator operator++(int)
            {
                reverseMapIterator<Key, T>tmp = *this;
                operator++();
                return (tmp);
            }

            value_type operator*() { return (_M_node->getPair()); }
            value_type* operator->() { return (&_M_node->getPair()); }

            bool operator!=(reverseMapIterator<Key, T> const &rhs) { return (this->_M_node != rhs._M_node); }
            bool operator==(reverseMapIterator<Key, T> const &rhs) { return (this->_M_node == rhs._M_node); }
            bool operator<(const reverseMapIterator &rhs) const { return _M_node < rhs._M_node; }
            bool operator>(const reverseMapIterator &rhs) const { return _M_node > rhs._M_node; }
            bool operator<=(const reverseMapIterator &rhs) const { return _M_node >= rhs._M_node; }
            bool operator>=(const reverseMapIterator &rhs) const { return _M_node <= rhs._M_node; }
    };

    template<class Key, class T>
    class constReverseMapIterator
    {
        public:
            typedef Node<Key, T> node_type;
            typedef std::pair<const Key, T> value_type;

            node_type *_M_node;

        public:
            constReverseMapIterator() : _M_node() {}
            constReverseMapIterator(node_type *n) : _M_node(n) {}
            constReverseMapIterator(const constReverseMapIterator &i) { this->_M_node = i._M_node; }

            constReverseMapIterator(const reverseMapIterator<Key, T> &x) { this->_M_node = x._M_node; }
            operator reverseMapIterator<Key, T>() { return (reverseMapIterator<Key, T>(this->_M_node)); }
            constReverseMapIterator &operator=(const reverseMapIterator<Key, T> &x) { this->_M_node = x._M_node; return (*this); }
            constReverseMapIterator& operator=(const constReverseMapIterator &copy) { this->_M_node = copy._M_node; return *this; }

            constReverseMapIterator& operator--()
            {
                if (_M_node->getRight())
                {
                    _M_node = _M_node->getRight();
                    while (_M_node->getLeft())
                        _M_node = _M_node->getLeft();
                }
                else
                {
                    node_type *tmp;
                    do
                    {
                        tmp = _M_node;
                        _M_node = _M_node->getParent();
                    }
                    while (_M_node && tmp == _M_node->getRight());
                }
                return (*this);
            }

            constReverseMapIterator operator--(int)
            {
                mapIterator<Key, T>tmp = *this;
                operator--();
                return (tmp);
            }

            constReverseMapIterator& operator++()
            {
                if (_M_node->getLeft())
                {
                    _M_node = _M_node->getLeft();
                    while (_M_node && _M_node->getRight())
                        _M_node = _M_node->getRight();
                }
                else
                {
                    node_type *tmp;
                    do
                    {
                        tmp = _M_node;
                        _M_node = _M_node->getParent();
                    }
                    while (_M_node && tmp == _M_node->getLeft());
                }
                return (*this);
            }

            constReverseMapIterator operator++(int)
            {
                constReverseMapIterator<Key, T>tmp = *this;
                operator++();
                return (tmp);
            }

            const value_type operator*() { return (_M_node->getPair()); }
            const value_type* operator->() { return (&_M_node->getPair()); }

            bool operator!=(constReverseMapIterator<Key, T> const &rhs) { return (this->_M_node != rhs._M_node); }
            bool operator==(constReverseMapIterator<Key, T> const &rhs) { return (this->_M_node == rhs._M_node); }
            bool operator<(const constReverseMapIterator &rhs) const { return _M_node < rhs._M_node; }
            bool operator>(const constReverseMapIterator &rhs) const { return _M_node > rhs._M_node; }
            bool operator<=(const constReverseMapIterator &rhs) const { return _M_node >= rhs._M_node; }
            bool operator>=(const constReverseMapIterator &rhs) const { return _M_node <= rhs._M_node; }
    };
}


#endif
