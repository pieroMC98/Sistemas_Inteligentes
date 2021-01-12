#ifndef _TEMPLATE_H
#define _TEMPLATE_H
#include <iostream>
#include <vector>
template <class T> bool operator>(const T &, const T &);
template <class T> bool operator<(const T &, const T &);
#include "./template.tpp"
#endif
