// test_MyXform.cxx
//
// David Adams
// Marach 2020
//
// Test MyXform.

#include "../MyXform.h"
#include <string>
#include <iostream>
#include <vector>
#include <cmath>

#undef NDEBUG
#include <cassert>

using std::string;
using std::cout;
using std::endl;
using std::ofstream;
using std::istringstream;
using std::vector;

//**********************************************************************

int test_MyXform() {
  const string myname = "test_MyXform: ";
#ifdef NDEBUG
  cout << myname << "NDEBUG must be off." << endl;
  abort();
#endif
  string line = "-----------------------------";

  cout << myname << line << endl;
  float scale = 100.0;
  cout << myname << "Create object." << endl;
  MyXform myo(scale);

  cout << myname << line << endl;
  cout << myname << "Check transform." << endl;
  std::vector<float> vals = {0.0, 1.0, 3.0, 99};
  for ( float val : vals ) {
    float newval = myo.transform(val);
    float expval = scale*val;
    cout << myname << "  " << val << " --> " << newval << endl;
    assert( fabs(newval - expval) < 0.001 );
  }

  cout << myname << line << endl;
  cout << myname << "Done." << endl;
  return 0;
}

//**********************************************************************

int main(int argc, char* argv[]) {
  return test_MyXform();
}

//**********************************************************************
