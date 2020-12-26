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

        private:
            node_type *node;

        public:
            mapIterator() : node() {}
            mapIterator(node_type *n) : node(n) {}
            mapIterator(const mapIterator &i) { this->node = i.node; }

            mapIterator(const constMapIterator<Key, T> &x)
            {
                this->node = x.node;
            }

            mapIterator &operator=(const constMapIterator<Key, T> &x)
            {
                this->node = x.node;
                return (*this);
            }

            operator constMapIterator<Key, T>()
            {
                return (ConstIterator(this->node));
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
                mapIterator<Key, T>tmp = *this;
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
                mapIterator<Key, T>tmp = *this;
                operator--();
                return (tmp);
            }

            value_type operator*() { return (node->getPair()); }
            value_type* operator->() { return (&node->getPair()); }

            bool operator!=(mapIterator<Key, T> const &rhs) { return (this->node != rhs.node); }
            bool operator==(mapIterator<Key, T> const &rhs) { return (this->node == rhs.node); }
            bool operator<(const mapIterator &rhs) const { return node < rhs.node; }
            bool operator>(const mapIterator &rhs) const { return node > rhs.node; }
            bool operator<=(const mapIterator &rhs) const { return node >= rhs.node; }
            bool operator>=(const mapIterator &rhs) const { return node <= rhs.node; }
    };


    template<class Key, class T>
    class constMapIterator
    {
        public:
            typedef Node<Key, T> node_type;
            typedef std::pair<const Key, T> value_type;

        private:
            node_type *node;

        public:
            constMapIterator() : node() {}
            constMapIterator(node_type *n) : node(n) {}
            constMapIterator(const constMapIterator &i) { this->node = i.node; }

            constMapIterator(const mapIterator<Key, T> &x) { this->node = x.node; }
            operator mapIterator<Key, T>() { return (mapIterator<Key, T>(this->node)); }
            constMapIterator &operator=(const mapIterator<Key, T> &x) { this->node = x.node; return (*this); }

            constMapIterator& operator=(const constMapIterator &copy) { this->node = copy.node; return (*this); }

            constMapIterator& operator++()
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

            constMapIterator operator++(int)
            {
                mapIterator<Key, T>tmp = *this;
                operator++();
                return (tmp);
            }

            constMapIterator& operator--()
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

            constMapIterator operator--(int)
            {
                mapIterator<Key, T>tmp = *this;
                operator--();
                return (tmp);
            }

            const value_type operator*() { return (node->getPair()); }
            const value_type* operator->() { return (&node->getPair()); }

            bool operator!=(constMapIterator<Key, T> const &rhs) { return (this->node != rhs.node); }
            bool operator==(constMapIterator<Key, T> const &rhs) { return (this->node == rhs.node); }
            bool operator<(const constMapIterator &rhs) const { return node < rhs.node; }
            bool operator>(const constMapIterator &rhs) const { return node > rhs.node; }
            bool operator<=(const constMapIterator &rhs) const { return node >= rhs.node; }
            bool operator>=(const constMapIterator &rhs) const { return node <= rhs.node; }
    };


}


#endif
