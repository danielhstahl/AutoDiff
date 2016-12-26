#ifndef AUTODIFF_H
#define AUTODIFF_H
#include <cmath>

template<class T>
class AutoDiff {
    private:
        T standard;
        T dual;

    public:
        template<typename U, typename W, typename Z>
        friend AutoDiff<U> operator+(const AutoDiff<W>&, const AutoDiff<Z>&);
        template<typename U, typename W, typename Z>
        friend AutoDiff<U> operator+(const AutoDiff<W>&, const Z&);
        template<typename U, typename W>
        friend AutoDiff<U> operator+(const W&, const AutoDiff<U>&);
        template<typename U, typename W, typename Z>
        friend AutoDiff<U> operator-(const AutoDiff<W>&, const AutoDiff<Z>&);
        template<typename U, typename W>
        friend AutoDiff<U> operator-(const AutoDiff<W>&);
        template<typename U, typename W, typename Z>
        friend AutoDiff<U> operator-(const AutoDiff<W>&, const Z&);

        template<typename U, typename W, typename Z>
        friend AutoDiff<U> operator-(const W&, const AutoDiff<Z>&);
        template<typename U, typename W, typename Z>
        friend AutoDiff<U> operator*(const AutoDiff<W>&, const AutoDiff<Z>&);
        template<typename U, typename W, typename Z>
        friend AutoDiff<U> operator*(const AutoDiff<W>&, const Z&);
        template<typename U, typename W, typename Z>
        friend AutoDiff<U> operator*(const W&, const AutoDiff<Z>&);
        template<typename U, typename W, typename Z>
        friend AutoDiff<U> operator/(const AutoDiff<W>&, const AutoDiff<Z>&);
        template<typename U, typename W, typename Z>
        friend AutoDiff<U> operator/(const AutoDiff<W>&, const Z&);
        template<typename U, typename W, typename Z>
        friend AutoDiff<U> operator/(const W&, const AutoDiff<Z>&);
        template<typename U, typename W>
        friend bool operator==(const AutoDiff<U>&, const AutoDiff<W>&);
        template<typename U, typename W>
        friend bool operator==(const U&, const AutoDiff<W>&);
        template<typename U, typename W>
        friend bool operator==(const AutoDiff<U>&, const W&);
        template<typename U, typename W>
        friend bool operator!=(const AutoDiff<U>&, const AutoDiff<W>&);
        template<typename U, typename W>
        friend bool operator!=(const U&, const AutoDiff<W>&);
        template<typename U, typename W>
        friend bool operator!=(const AutoDiff<U>&, const W&);
        template<typename U, typename W>
        friend bool operator>(const AutoDiff<U>&, const AutoDiff<W>&); //compares "standard" only!
        template<typename U, typename W>
        friend bool operator>(const AutoDiff<U>&, const W&);
        template<typename U, typename W>
        friend bool operator>(const U&, const AutoDiff<W>&);
        template<typename U, typename W>
        friend bool operator<(const AutoDiff<U>&, const AutoDiff<W>&);//compares "standard" only!
        template<typename U, typename W>
        friend bool operator<(const AutoDiff<U>&, const W&);
        template<typename U, typename W>
        friend bool operator<(const U&, const AutoDiff<W>&);
        //template<typename U>
        AutoDiff<T> operator=(const AutoDiff<T>&);
        //template<typename U, typename W>
        AutoDiff<T> operator=(const T&);
        template<typename U>
        AutoDiff<T> operator+=(const AutoDiff<U> &right);
        
        
        AutoDiff<T>(const T&, const T&);
        AutoDiff<T>(const T&);
        AutoDiff<T>();
        template<typename U>
        AutoDiff<T> add(const AutoDiff<U>&) const;
        template<typename U>
        AutoDiff<T> add(const U&) const;
        template<typename U>
        AutoDiff<T> subtract(const AutoDiff<U>&) const;
        template<typename U>
        AutoDiff<T> subtract(const U&) const;
        template<typename U>
        AutoDiff<T> multiply(const AutoDiff<U>&) const;
        
        template<typename U>
        AutoDiff<T> multiply(const U&) const;
        template<typename U>
        AutoDiff<T> divide(const AutoDiff<U>&) const;
        template<typename U>
        AutoDiff<T> divide(const U&) const;
        void setDual(const T&);
        void setStandard(const T&);
        AutoDiff<T> recipricol() const;
        T getStandard() const;
        T getDual() const;
};
template<typename U, typename W>
AutoDiff<U> sin(const AutoDiff<W>&);
template<typename U, typename W>
AutoDiff<U> cos(const AutoDiff<W>&);
template<typename U, typename W>
AutoDiff<U> exp(const AutoDiff<W>&);
template<typename U, typename W>
AutoDiff<U> log(const AutoDiff<W>&);
template<typename U, typename W>
AutoDiff<U> sqrt(const AutoDiff<W>&);
template<typename U, typename W>
AutoDiff<U> erf(const AutoDiff<W>&);
#include "AutoDiff.hpp"
#endif
