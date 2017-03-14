
#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;


class Student {
 private:
  string name;
  string gender;
  int age;

 public:
  Student(const string name="Andrew", string gender="M", int age=6) {
    this->name = name;
    this->gender = gender;
    this->age = age;
  }
  void printStudentInfo() {
    cout << "Name: " << name << " ";
    cout << "Gender: " << gender << " ";
    cout << "Age: " << age << endl;
    throw runtime_error("Throw an exception deliberately...");
  }
  ~Student() {
    cout << "The destructor of class Student is called." << endl;
  }
};


template<typename T>
class Resource {
 private:
  T* res;

 public:
  Resource(T* p) {
    res = p;
  }
  ~Resource() {
    if (res) {
      delete res;
      res = nullptr;
      cout << "Resource are deallocated here." << endl;
    }
  }
  T* operator->() const {
    if (res == nullptr) {
      cout << "The underlying object is empty." << endl;
    }
    return res;
  }
};


int main() {
  Student* stu = new Student("Andrew", "M", 6);
  Resource<Student> res(stu);
  try {
    // stu->printStudentInfo();
    res->printStudentInfo();
  }
  catch(const exception &e) {
    cout << e.what() << endl;
  }
  // delete stu;
  return 0;
}


