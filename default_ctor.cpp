class ClassA {
 private:
  int val;
 public:
  // If any constructor is defined, the default constructor will not create.
  ClassA(int x) { val = x; }
  // ClassA(int x) : val(x) {  }  // alternative as above

  // Default constructor will create
  // even though any other constructor was defined
  // ClassA() = default; 
};

class ClassB : public ClassA {
 private:
  int val2;
 public:
  // Error, for ClassA don't have default constructor
  // ClassB() { cout << "ClassB()" << endl; }  // Error
  ClassB() = default; // Alternative, but this is correct
  
  // ClassB(int x) : val2(x) {  }  // Error
  ClassB(int x) : val2(x), ClassA(x) {  }

  //ClassB(int x, int y) : ClassA(y) { val2 = x; }  // Error
  ClassB(int x, int y) : val2(x), ClassA(y) {  }
};

 
int main() {
  return 0;
}
