/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guyar <guyar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:54:12 by guyar             #+#    #+#             */
/*   Updated: 2023/09/28 20:28:02 by guyar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <exception>

template< typename T >
class Array {
   public:

        Array(void);
        Array(unsigned int n);
        Array<T>(Array<T> const & content);
        Array<T> & operator=(const Array<T>& other);
        T   & operator[](const int idx) const;
        ~Array(void);
        T getData(unsigned i) const;
        void setData(unsigned i, int d);
        size_t size() const;

        class CantAccessToDataException: public std::exception {
            virtual const char * what() const throw();
        };

   private:
        T * _data;
        unsigned int _size;

};

template<typename T>
Array<T>::Array() {
    std::cout << "Constructor for Array called " << std::endl;
    _data = new T[0];
}

template<typename T>
Array<T>::~Array() {
    std::cout << "Destructor for Array called " << std::endl;
    delete[] _data;
}

template<typename T>
Array<T>::Array(unsigned int n) {
    _size = n; 
    _data = new T[n];
    unsigned int i;
    i = 0; 
    while (i < n)
    {
        _data[i] = T();
        i++;
    }
}

template<typename T>
T Array<T>::getData(unsigned i) const {
    if (i < 0 || i >= static_cast<unsigned>(_size))
        throw CantAccessToDataException();
    else
        return _data[i];
}

template<typename T>
Array<T>::Array(Array<T> const & content) {
    this->_size = content._size;
    _data = new T[this->_size];
    
    for (unsigned int i = 0; i < this->_size; i++)
    {
        _data[i] = content.getData(i);
    }
    std::cout << "Copie Constructor for Array called " << std::endl;
}

template<typename T>
void Array<T>::setData(unsigned i, int d) {
    _data[i] = d;
}

template<typename T>
Array<T>& Array<T>::operator=(const Array<T>& other){
    if (this != &other) {
        // delete[] _data;
        unsigned int len  = sizeof(other._data);
        _data = new T[len];
        for (unsigned int i = 0; i < len; i++) {
            _data[i] = &other._data[i];
        }
    }
    return *this;
}

template<typename T>
const char * Array<T>::CantAccessToDataException::what() const throw()
{
    return "cannot access to data";
}

template<typename T>
size_t Array<T>::size() const {
    return _size; 
}

template<typename T>
T & Array<T>::operator[](const int idx) const {
    if (idx < 0 || static_cast<size_t>(idx) >= _size) {
        throw CantAccessToDataException();
    }
    return _data[idx];
}