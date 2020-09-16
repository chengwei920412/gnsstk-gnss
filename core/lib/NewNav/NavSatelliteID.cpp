#include "NavSatelliteID.hpp"

namespace gpstk
{
   NavSatelliteID ::
   NavSatelliteID()
         : sat(0,SatelliteSystem::Unknown), xmitSat(0,SatelliteSystem::Unknown)
   {}


   NavSatelliteID ::
   NavSatelliteID(unsigned long subj, unsigned long xmit,
                  SatelliteSystem sys, CarrierBand car, TrackingCode track,
                  NavType nmt)
         : NavSignalID(sys,car,track,nmt), sat(subj,sys), xmitSat(xmit,sys)
   {}


   NavSatelliteID ::
   NavSatelliteID(const WildSatID& subj)
         : NavSignalID(subj.system, gpstk::CarrierBand::Any,
                       gpstk::TrackingCode::Any, gpstk::NavType::Any),
           sat(subj)
   {}


   bool NavSatelliteID ::
   operator<(const NavSatelliteID& right) const
   {
         // Use the order() method so we don't have to compare
         // everything in the parent class twice.
      int o = NavSignalID::order(right);
      if (o < 0) return true;
      if (o > 0) return false;
      if (sat < right.sat) return true;
      if (sat > right.sat) return false;
      if (xmitSat < right.xmitSat) return true;
      return false;
   }
}
