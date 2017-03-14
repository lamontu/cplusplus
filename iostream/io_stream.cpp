#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;


int main(int argc, char* argv[]) {
  ifstream ifs("test.txt");
  istream_iterator<string> ibeg(ifs);
  istream_iterator<string> iend;
  vector<string> vec(ibeg, iend);
  // vector<string> vec(istream_iterator<string>(ifs),
  //                    istream_iterator<string>())
  copy(vec.begin(), vec.end(), ostream_iterator<string>(cout, "\n"));
  cout << endl;

  ifstream infile("infile.txt");
  ofstream outfile("outfile.txt");
  istream_iterator<string> is(infile);
  istream_iterator<string> eof;

  vector<string> text;
  copy(is, eof, back_inserter(text));
  ostream_iterator<string> os1(cout, " ");
  copy(text.begin(), text.end(), os1);

  ostream_iterator<string> os2(outfile, " ");
  copy(text.begin(), text.end(), os2);
  cout << endl;
  
  return 0;
}
