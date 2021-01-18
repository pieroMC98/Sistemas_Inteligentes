#include "./operator.h"
std::vector<float> operator+(const std::vector<float> i, std::vector<float> j) {
	if (i.size() != j.size()) return std::vector<float>();
	std::vector<float> rt(i.size());
	for (size_t k = 0; k < i.size(); k++) rt[k] = i[k] + j[k];
	return rt;
}

std::vector<float> operator*(const std::vector<float> i, std::vector<float> j) {
	if (i.size() != j.size()) return std::vector<float>();
	std::vector<float> rt(i.size());
	for (size_t k = 0; k < i.size(); k++) rt[k] = i[k] * j[k];
	return rt;
}

std::vector<float> operator-(const std::vector<float> i, std::vector<float> j) {
	if (i.size() != j.size()) return std::vector<float>();
	std::vector<float> rt(i.size());
	for (size_t k = 0; k < i.size(); k++) rt[k] = i[k] - j[k];
	return rt;
}
