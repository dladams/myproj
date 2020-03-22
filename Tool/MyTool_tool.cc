//  MyTool_tool.cc

#include "MyToolInterface.h"
#include "fhiclcpp/ParameterSet.h"
#include "art/Utilities/ToolMacros.h"
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std:: string;

class MyTool : public MyToolInterface {
public:
  using Index = unsigned int;
  explicit MyTool(fhicl::ParameterSet const& ps);
  float transform(float x) const;
private:
  // Configuration parameters.
  Index m_LogLevel;
  float m_Scale;
};

MyTool::MyTool(const fhicl::ParameterSet& ps)
: m_LogLevel(ps.get<Index>("LogLevel")),
  m_Scale(ps.get<float>("Scale")) {
  const string myname = "MyTool::ctor: ";
  cout << myname << "  LogLevel: " << m_LogLevel << endl;
  cout << myname << "     Scale: " << m_Scale << endl;
}

float MyTool::transform(float x) const {
  return m_Scale*x;
}

DEFINE_ART_CLASS_TOOL(MyTool)

