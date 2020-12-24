#ifndef FT_CONTAINERS_LISTITERATOR_HPP
#define FT_CONTAINERS_LISTITERATOR_HPP

namespace ft
{
    template<typename T>
    class NodeList
    {
        public:
            T c;
            NodeList *prev;
            NodeList *next;

            NodeList() : prev(0), next(0) { c = T(); }
            NodeList(const T &content) : c(content), prev(0), next(0) {}
    };

    template<typename T>
    class constListIterator;

    template<typename T>
    class listIterator
    {
        public:
            NodeList<T>* _M_node;

            listIterator() {}
            listIterator(NodeList<T> *current) : _M_node(current) {}
            listIterator(listIterator const *copy) : _M_node(copy->_M_node) {}
            ~listIterator() {}

            operator constListIterator<T>() { return (constListIterator<T>(_M_node)); }
            listIterator<T>(const constListIterator<T> &x) { this->_M_node = x._M_node; }
            listIterator<T>& operator=(const constListIterator<T>& x) { this->_M_node = x._M_node; return (*this); }
            listIterator<T>& operator=(const listIterator<T> &rhs) { _M_node = rhs._M_node; return (*this); }

            listIterator& operator++() { _M_node = _M_node->next; return (*this); }
            listIterator operator++(int) { NodeList<T>* temp = _M_node; _M_node = _M_node->next; return (listIterator<T>(temp)); }
            listIterator& operator--() { _M_node = _M_node->prev; return (*this); }
            listIterator operator--(int) { NodeList<T>* temp = _M_node; _M_node = _M_node->prev; return (listIterator<T>(temp)); }

            bool operator==(listIterator<T> const &rhs) { return (this->_M_node == rhs._M_node); }
            bool operator!=(listIterator<T> const &rhs) { return (this->_M_node != rhs._M_node); }
            T* operator->() { return (_M_node); }
            T& operator*() { return (_M_node->c); }
    };

    template<typename T>
    class constListIterator
    {
        public:
            NodeList<T>* _M_node;

            constListIterator() {}
            constListIterator(NodeList<T> *current) : _M_node(current) {}
            constListIterator(constListIterator const *copy) : _M_node(copy->_M_node) {}
            ~constListIterator() {}

            operator listIterator<T>() { return (listIterator<T>(_M_node)); }
            constListIterator<T>(const listIterator<T> &x) { this->_M_node = x._M_node; }
            constListIterator<T>& operator=(const listIterator<T>& x) { this->_M_node = x._M_node; return (*this); }
            constListIterator<T>& operator=(const constListIterator<T> &rhs) { _M_node = rhs._M_node; return (*this); }

            constListIterator& operator++() { _M_node = _M_node->next; return (*this); }
            constListIterator operator++(int) { NodeList<T>* temp = _M_node; _M_node = _M_node->next; return (constListIterator<T>(temp)); }
            constListIterator& operator--() { _M_node = _M_node->prev; return (*this); }
            constListIterator operator--(int) { NodeList<T>* temp = _M_node; _M_node = _M_node->prev; return (constListIterator<T>(temp)); }

            bool operator==(constListIterator<T> const &rhs) { return (this->_M_node == rhs._M_node); }
            bool operator!=(constListIterator<T> const &rhs) { return (this->_M_node != rhs._M_node); }
            const T* operator->() { return (_M_node); }
            const T& operator*() { return (_M_node->c); }
    };

    template<typename T>
    class constReverseListIterator;

    template<typename T>
    class reverseListIterator
    {
        public:
            NodeList<T>* _M_node;

            reverseListIterator() {}
            reverseListIterator(NodeList<T> *current) : _M_node(current) {}
            reverseListIterator(reverseListIterator const *copy) : _M_node(copy->_M_node) {}
            ~reverseListIterator() {}

            operator constReverseListIterator<T>() { return (constReverseListIterator<T>(_M_node)); }
            reverseListIterator<T>(const constReverseListIterator<T> &x) { this->_M_node = x._M_node; }
            reverseListIterator<T>& operator=(const constReverseListIterator<T>& x) { this->_M_node = x._M_node; return (*this); }
            reverseListIterator<T>& operator=(const reverseListIterator<T> &rhs) { _M_node = rhs._M_node; return (*this); }

            reverseListIterator& operator++() { _M_node = _M_node->prev; return (*this); }
            reverseListIterator operator++(int) { NodeList<T>* temp = _M_node; _M_node = _M_node->prev; return (reverseListIterator<T>(temp)); }
            reverseListIterator& operator--() { _M_node = _M_node->next; return (*this); }
            reverseListIterator operator--(int) { NodeList<T>* temp = _M_node; _M_node = _M_node->next ; return (reverseListIterator<T>(temp)); }

            bool operator==(reverseListIterator<T> const &rhs) { return (this->_M_node == rhs._M_node); }
            bool operator!=(reverseListIterator<T> const &rhs) { return (this->_M_node != rhs._M_node); }
            T* operator->() { return (_M_node); }
            T& operator*() { return (_M_node->c); }
    };

    template<typename T>
    class constReverseListIterator
    {
        public:
            NodeList<T>* _M_node;

            constReverseListIterator() {}
            constReverseListIterator(NodeList<T> *current) : _M_node(current) {}
            constReverseListIterator(constReverseListIterator const *copy) : _M_node(copy->_M_node) {}
            ~constReverseListIterator() {}

            operator reverseListIterator<T>() { return (reverseListIterator<T>(_M_node)); }
            constReverseListIterator<T>(const reverseListIterator<T> &x) { this->_M_node = x._M_node; }
            constReverseListIterator<T>& operator=(const reverseListIterator<T>& x) { this->_M_node = x._M_node; return (*this); }
            constReverseListIterator<T>& operator=(const constReverseListIterator<T> &rhs) { _M_node = rhs._M_node; return (*this); }

            constReverseListIterator& operator++() { _M_node = _M_node->prev; return (*this); }
            constReverseListIterator operator++(int) { NodeList<T>* temp = _M_node; _M_node = _M_node->prev; return (constReverseListIterator<T>(temp)); }
            constReverseListIterator& operator--() { _M_node = _M_node->next; return (*this); }
            constReverseListIterator operator--(int) { NodeList<T>* temp = _M_node; _M_node = _M_node->next ; return (constReverseListIterator<T>(temp)); }

            bool operator==(constReverseListIterator<T> const &rhs) { return (this->_M_node == rhs._M_node); }
            bool operator!=(constReverseListIterator<T> const &rhs) { return (this->_M_node != rhs._M_node); }
            const T* operator->() { return (_M_node); }
            const T& operator*() { return (_M_node->c); }
    };
}

#endif
