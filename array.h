#ifndef __ARRAY_H__
#define __ARRAY_H__

#include <cstdio>
#include <new>
#include <iostream>

#include "exception.h"

#define CHECK_IND

using namespace std;

template <typename T>
class Array {
public:
	T* value_;        // array of values with pointer on first element
	size_t size_;     // current size
	size_t maxsize_;  // max size, desirable call for (2 * size_)
	bool TestInd(size_t i) const { return i < size_; }

	explicit Array (size_t s = 0): value_(nullptr), size_(0), maxsize_(0){ SetSize(s, s); }
	Array (size_t s, size_t maxs): value_(nullptr), size_(s), maxsize_(maxs) { SetSize(s, maxs); } // size = current size, copying (size) elements
	Array (const Array<T>& other) {
		value_ = nullptr;
		SetSize(other.size_, other.maxsize_);
		for (size_t i = 0; i < size_; ++i) {
			value_[i] = other[i];
		}
	}
	~Array() { delete [] value_; }

	void PushBack(const T &x);
	void Insert(size_t position, const T &x); // position starting from 0
	void Remove(size_t position);             // position starting from 0
	void SetSize(size_t s, size_t maxs); // change size of array

	T& operator[] (size_t i);							// lvalue
	const T& operator[] (size_t i) const; // rvalue

	size_t Size() const { return size_; }
	size_t MaxSize() const { return maxsize_; } // capacity
};

template <typename T>
T& Array<T>::operator[] (size_t i) {
#ifdef CHECK_IND
	if (!TestInd(i)) {
		cerr << "[] : bad index: ind, size";
		throw Exception(EC_RANGE, "[] : bad index: ind, size");
	}
#endif
	return value_[i];
}

template <typename T>
const T& Array<T>::operator[] (size_t i) const {
#ifdef CHECK_IND
	if (!TestInd(i)) {
		cerr << "[] : bad index: ind, size";
		throw Exception(EC_RANGE, "[] : bad index: ind, size");
	}
#endif
	return value_[i];
}

template <typename T>
void Array<T>::SetSize(size_t s, size_t maxs) {
	if (s > maxs) {
		throw Exception(EC_RANGE, "SetSize: size > maxsize");
	}
	//if (value_) { delete [] value_; } // all old is gone
	try {
		T* tmp = new T[maxs];
		if (value_ != nullptr) {
			for (size_t i = 0; i < size_; ++i) {
				tmp[i] = value_[i];
			}
			delete [] value_;
		}
		value_ = tmp;
		maxsize_ = maxs;
		size_ = s;
	} catch (std::bad_alloc &e) {
		throw Exception(EC_MEMORY, "SetSize: allocation error: size, maxsize");
	}
}

template <typename T>
void Array<T>::PushBack(const T &x) {
	if (size_ == maxsize_) {
		SetSize(size_, 2 * maxsize_);
	}
	value_[size_++] = x; // postfix because numeration starts from 0
}

template <typename T>
void Array<T>::Insert(const size_t position, const T& x) {
	if (size_ == maxsize_) { // need new array
		SetSize(size_, 2 * maxsize_);
	}
	T prev = x;
	T next = this->value_[position];
	for (size_t i = position; i < size_ + 1; ++i) { // + 1 -- need to move last character
		next = this->value_[i];
		this->value_[i] = prev;
		prev = next;
	}
	++size_;
}

template <typename T>
void Array<T>::Remove(size_t position) {
	for (size_t i = position; i < size_; ++i) {
		T next = this->value_[i + 1];
		this->value_[i] = next;
	}
	--size_;
}
#endif
