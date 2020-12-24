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

            Node *getParent() { return (parent); }
            void setParent(node_type *n) { parent = n; }
            value_type &getPair() { return (pair); }
            Node *getLeft() { return (left); }
            Node *getRight() { return (right); }
            void setLeft(node_type *n) { left = n; }
            void setRight(node_type *n) { right = n; }

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

            bool operator!=(mapIterator<Key, T> const &rhs)
            {
                return (this->node != rhs.node);
            }

            bool operator==(mapIterator<Key, T> const &rhs)
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

}

#endif
