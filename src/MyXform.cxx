// MyXform.cxx

#include "./MyXform.h"
#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

MyXform::MyXform(float scale) : m_scale(scale) {
  const string myname = "MyXform::ctor: ";
  cout << myname << "Scale is " << scale << endl;
}

float MyXform::transform(float x) {
  return m_scale*x;
}
