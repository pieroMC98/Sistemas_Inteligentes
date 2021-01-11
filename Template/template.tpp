template <class T> bool operator>(const T &r1, const T &r2) {
  return r1.value > r2.value ? true : false;
}

template <class T> bool operator<(const T &r1, const T &r2) {
  return r1.value < r2.value ? true : false;
}
