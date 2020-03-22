// test_MyTool.cxx
//
// David Adams
// Marach 2020
//
// Test MyTool.

#include "MyToolInterface.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "dune/ArtSupport/DuneToolManager.h"
#include "TH1F.h"

#undef NDEBUG
#include <cassert>

using std::string;
using std::cout;
using std::endl;
using std::ofstream;
using std::istringstream;
using fhicl::ParameterSet;
using Index = unsigned int;

//**********************************************************************

int test_MyTool(bool useExistingFcl =false) {
  const string myname = "test_MyTool: ";
#ifdef NDEBUG
  cout << myname << "NDEBUG must be off." << endl;
  abort();
#endif
  string line = "-----------------------------";

  cout << myname << line << endl;
  string fclfile = "test_MyTool.fcl";
  float scale = 100.0;
  if ( ! useExistingFcl ) {
    cout << myname << "Creating top-level FCL." << endl;
    ofstream fout(fclfile.c_str());
    fout << "tools: {" << endl;
    fout << "  mytool: {" << endl;
    fout << "       tool_type: MyTool" << endl;
    fout << "     LogLevel: 2" << endl;
    fout << "        Scale: " << scale << endl;
    fout << "  }" << endl;
    fout << "}" << endl;
    fout.close();
  } else {
    cout << myname << "Using existing top-level FCL." << endl;
  }

  cout << myname << line << endl;
  cout << myname << "Fetching tool manager." << endl;
  DuneToolManager* ptm = DuneToolManager::instance(fclfile);
  assert ( ptm != nullptr );
  DuneToolManager& tm = *ptm;
  tm.print();
  assert( tm.toolNames().size() >= 1 );

  cout << myname << line << endl;
  cout << myname << "Fetching tool." << endl;
  auto pto = tm.getPrivate<MyToolInterface>("mytool");
  assert( pto != nullptr );

  cout << myname << line << endl;
  cout << myname << "Check transform." << endl;
  std::vector<float> vals = {0.0, 1.0, 3.0, 99};
  for ( float val : vals ) {
    float newval = pto->transform(val);
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
  bool useExistingFcl = false;
  if ( argc > 1 ) {
    string sarg(argv[1]);
    if ( sarg == "-h" ) {
      cout << "Usage: " << argv[0] << " [keepFCL] [RUN]" << endl;
      cout << "  If keepFCL = true, existing FCL file is used." << endl;
      cout << "  If RUN is nonzero, the data for that run are displayed." << endl;
      return 0;
    }
    useExistingFcl = sarg == "true" || sarg == "1";
  }
  return test_MyTool(useExistingFcl);
}

//**********************************************************************
