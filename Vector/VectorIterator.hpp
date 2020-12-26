#ifndef FT_CONTAINERS_VECTORITERATOR_HPP
#define FT_CONTAINERS_VECTORITERATOR_HPP

namespace ft
{
    template<class T>
    class ConstvectorIterator;

    template<class T>
    class vectorIterator
    {
        public:
            T* c;

            typedef T*      pointer;
            typedef T&      reference;

        public:
            vectorIterator() {};
            vectorIterator(pointer current) : c(current) {};
            vectorIterator(const vectorIterator<T> &x) : c(const_cast<pointer>(x.c)) {};
            ~vectorIterator() {};

            operator ConstvectorIterator<T>() { return (ConstvectorIterator<T>(c)); }
            vectorIterator(const ConstvectorIterator<T> &x) { this->c = x.c; }
            vectorIterator<T>& operator=(const ConstvectorIterator<T>& x) { this->c = x.c; return (*this); }
            vectorIterator<T>& operator=(const vectorIterator<T> &rhs) { c = rhs.c; return (*this); }

            vectorIterator<T> &operator++() { c++; return (*this); }
            vectorIterator<T> operator++(int) { vectorIterator<T> temp = *this; c++; return (temp); }
            vectorIterator<T> &operator--() { c--; return (*this); }
            vectorIterator<T> operator--(int) { vectorIterator<T> temp = *this; c--; return (temp); }

            bool operator==(const vectorIterator<T> &rhs) { return (c == rhs.c); }
            bool operator!=(const vectorIterator<T> &rhs) { return (c != rhs.c); }
            bool operator<(const vectorIterator<T> &rhs)  { return (c < rhs.c); }
            bool operator>(const vectorIterator<T> &rhs)  { return (c > rhs.c); }
            bool operator<=(const vectorIterator<T> &rhs) { return (c <= rhs.c); }
            bool operator>=(const vectorIterator<T> &rhs) { return (c >= rhs.c); }

            std::ptrdiff_t operator-(const vectorIterator<T> &rhs) { return (this->c - rhs.c); }
            vectorIterator<T> operator-(int n) { return (vectorIterator<T>(this->c - n)); }
            std::ptrdiff_t operator+(const vectorIterator<T> &rhs) { return (this->c + rhs.c); }
            vectorIterator<T> operator+(int n) { return (vectorIterator<T>(this->c + n)); }

            reference operator[](size_t n) { return *(c + n); }
            T &operator*() { return (*this->c); }
    };

    template<class T>
    class ConstvectorIterator
    {

        public:
            T* c;

            typedef const T* Pointer;
            typedef const T&      reference;

        public:
            ConstvectorIterator() {};
            ConstvectorIterator(T* current) : c(current) {};
            ConstvectorIterator(ConstvectorIterator<T> const &x) : c(x.c) {};
            ~ConstvectorIterator() {};

            operator vectorIterator<T>() { return (vectorIterator<T>(this->c)); }
            ConstvectorIterator(const vectorIterator<T> &x) { this->c = x.c; }
            ConstvectorIterator<T>& operator=(const vectorIterator<T> &x) { this->c = x.c; return (*this); }
            ConstvectorIterator<T>& operator=(const ConstvectorIterator<T> &x) { this->c = x.c; return (*this); }

            ConstvectorIterator<T> &operator++() { c++; return (*this); }
            ConstvectorIterator<T> operator++(int) { ConstvectorIterator<T> temp = *this; c++; return (temp); }
            ConstvectorIterator<T> &operator--() { c--; return (*this); }
            ConstvectorIterator<T> operator--(int) { ConstvectorIterator<T> temp = *this; c--; return (temp); }

            bool operator==(const ConstvectorIterator<T> &rhs) { return (c == rhs.c); }
            bool operator!=(const ConstvectorIterator<T> &rhs) { return (c != rhs.c); }
            bool operator<(const ConstvectorIterator<T> &rhs)  { return (c < rhs.c); }
            bool operator>(const ConstvectorIterator<T> &rhs)  { return (c > rhs.c); }
            bool operator<=(const ConstvectorIterator<T> &rhs) { return (c <= rhs.c); }
            bool operator>=(const ConstvectorIterator<T> &rhs) { return (c >= rhs.c); }

            std::ptrdiff_t operator-(const ConstvectorIterator<T> &rhs) { return (this->c - rhs.c); }
            ConstvectorIterator<T> operator-(int n) { return (ConstvectorIterator<T>(this->c - n)); }
            std::ptrdiff_t operator+(const ConstvectorIterator<T> &rhs) { return (this->c + rhs.c); }
            ConstvectorIterator<T> operator+(int n) { return (ConstvectorIterator<T>(this->c + n)); }

            reference operator[](size_t n) { return *(c + n); }
            reference operator*() { return (*this->c); }
    };

    template<class T>
    class constReverseIterator;

    template<class T>
    class reverseIterator
    {
        public:
            T* c;

            typedef T* Pointer;
            typedef T&      reference;

        public:
            reverseIterator() : c() {};
            reverseIterator(Pointer current) : c(current) {};
            reverseIterator(reverseIterator<T> const &x) : c(const_cast<T*>(x.c)) {};
            ~reverseIterator() {};

            operator reverseIterator<T>() { return (constReverseIterator<T>(this->c)); }
            reverseIterator(const constReverseIterator<T> &x) { this->c = x.c; }
            reverseIterator<T>& operator=(const constReverseIterator<T> &x) { this->c = x.c; return (*this); }
            reverseIterator<T>& operator=(const reverseIterator<T> &x) { this->c = x.c; return (*this); }

            reverseIterator<T> &operator--() { c++; return (*this); }
            reverseIterator<T> operator--(int) { reverseIterator<T> temp = *this; c++; return (temp); }
            reverseIterator<T> &operator++() { c--; return (*this); }
            reverseIterator<T> operator++(int) { reverseIterator<T> temp = *this; c--; return (temp); }

            bool operator==(const reverseIterator<T> &rhs) { return (c == rhs.c); }
            bool operator!=(const reverseIterator<T> &rhs) { return (c != rhs.c); }
            bool operator<(const reverseIterator<T> &rhs)  { return (c < rhs.c); }
            bool operator>(const reverseIterator<T> &rhs)  { return (c > rhs.c); }
            bool operator<=(const reverseIterator<T> &rhs) { return (c <= rhs.c); }
            bool operator>=(const reverseIterator<T> &rhs) { return (c >= rhs.c); }

            std::ptrdiff_t operator-(const reverseIterator<T> &rhs) { return (this->c - rhs.c); }
            reverseIterator<T> operator-(int n) { return (reverseIterator<T>(this->c - n)); }
            std::ptrdiff_t operator+(const reverseIterator<T> &rhs) { return (this->c + rhs.c); }
            reverseIterator<T> operator+(int n) { return (reverseIterator<T>(this->c + n)); }

            reference operator[](size_t n) { return *(c + n); }
            reference operator*() { return (*this->c); }
    };

    template<class T>
    class constReverseIterator
    {
        public:
            T* c;

            typedef const T*        Pointer;
            typedef const T&        reference;

        public:
            constReverseIterator() : c() {};
            constReverseIterator(Pointer current) : c(current) {};
            constReverseIterator(constReverseIterator<T> const &x) : c(const_cast<T*>(x.c)) {};
            ~constReverseIterator() {};

            operator constReverseIterator<T>() { return (reverseIterator<T>(this->c)); }
            constReverseIterator(const reverseIterator<T> &x) { this->c = x.getPtr(); }
            constReverseIterator<T>& operator=(const reverseIterator<T> &x) { this->c = x.c; return (*this); }
            constReverseIterator<T>& operator=(const constReverseIterator<T> &x) { this->c = x.c; return (*this); }

            constReverseIterator<T> &operator--() { c++; return (*this); }
            constReverseIterator<T> operator--(int) { constReverseIterator<T> temp = *this; c++; return (temp); }
            constReverseIterator<T> &operator++() { c--; return (*this); }
            constReverseIterator<T> operator++(int) { constReverseIterator<T> temp = *this; c--; return (temp); }

            bool operator==(const constReverseIterator<T> &rhs) { return (c == rhs.c); }
            bool operator!=(const constReverseIterator<T> &rhs) { return (c != rhs.c); }
            bool operator<(const constReverseIterator<T> &rhs)  { return (c < rhs.c); }
            bool operator>(const constReverseIterator<T> &rhs)  { return (c > rhs.c); }
            bool operator<=(const constReverseIterator<T> &rhs) { return (c <= rhs.c); }
            bool operator>=(const constReverseIterator<T> &rhs) { return (c >= rhs.c); }

            std::ptrdiff_t operator-(const constReverseIterator<T> &rhs) { return (this->c - rhs.c); }
            constReverseIterator<T> operator-(int n) { return (constReverseIterator<T>(this->c - n)); }
            std::ptrdiff_t operator+(const constReverseIterator<T> &rhs) { return (this->c + rhs.c); }
            constReverseIterator<T> operator+(int n) { return (constReverseIterator<T>(this->c + n)); }

            reference operator[](size_t n) { return *(c + n); }
            reference operator*() { return (*this->c); }
    };
}

#endif
