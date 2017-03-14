
#ifndef _AUTO_PTR_H_
#define _AUTO_PTR_H_

template<typename T>
class auto_ptr {
 private:
  T* pointee;

 public:
  explicit auto_ptr(T* p=nullptr);

  ~auto_ptr();

  template<typename U>
  auto_ptr(auto_ptr<U>& rhs);

  template<typename U>
  auto_ptr<T>& operator=(auto_ptr<U>& rhs);

  T& operator*() const;
  T* operator->() const;

  T* get() const;
  T* release();
  void reset(T* p=nullptr);
};

template<typename T>
auto_ptr<T>::auto_ptr(T* p) : pointee(p) {  }

template<typename T>
template<typename U>
auto_ptr<T>::auto_ptr(auto_ptr<U>& rhs) : pointee(rhs.release()) {  }

template<typename T>
auto_ptr<T>::~auto_ptr() {
  delete pointee;
}

template<typename T>
template<typename U>
auto_ptr<T>& auto_ptr<T>::operator=(auto_ptr<U>& rhs) {
  if (this != rhs) {
    reset(rhs.release());
  }
  return *this;
}

template<typename T>
T& auto_ptr<T>::operator*() const {
  return *pointee;
}

template<typename T>
T* auto_ptr<T>::operator->() const {
  return pointee;
}

template<typename T>
T* auto_ptr<T>::get() const {
  return pointee;
}

template<typename T>
T* auto_ptr<T>::release() {
  T* oldpointee = pointee;
  pointee = nullptr;
  return oldpointee;
}

template<typename T>
void auto_ptr<T>::reset(T* p) {
  if (pointee != p) {
    delete pointee;
    pointee = p;
  }
}

#endif


