void test_MyXform() {
  //gROOT->ProcessLine(".class MyXform");
  string myname = "test_MyXform.C: ";
  string className = "MyXform";
  cout << myname << "Fetching class " << className << endl;
  TClass tc(className.c_str());
  if ( tc.GetClassInfo() == nullptr ) {
    cout << myname << "Info no not found for class " << className << endl;
    exit(1);
  }
  cout << myname << "Done." << endl;
  exit(0);
}
