////////////////////////////////////////////////////////////////////////
// Class:       MySvc
// Plugin Type: service (art v3_04_00)
// File:        MySvc_service.cc
//
// Generated at Wed Mar 11 09:48:33 2020 by David Adams using cetskelgen
// from cetlib version v3_09_00.
////////////////////////////////////////////////////////////////////////

#include "art/Framework/Services/Registry/ActivityRegistry.h"
#include "art/Framework/Services/Registry/ServiceMacros.h"
#include "fhiclcpp/ParameterSet.h"

class MySvc;


class MySvc {
public:
  explicit MySvc(fhicl::ParameterSet const& p, art::ActivityRegistry& areg);
  // The compiler-generated destructor is fine for non-base
  // classes without bare pointers or other resource use.

private:

  // Declare member data here.

};


MySvc::MySvc(fhicl::ParameterSet const& p, art::ActivityRegistry& areg)
// :
// Initialize member data here.
{
}

DECLARE_ART_SERVICE(MySvc, LEGACY)
DEFINE_ART_SERVICE(MySvc)
