//==============================================================================
//
//  This file is part of GPSTk, the GPS Toolkit.
//
//  The GPSTk is free software; you can redistribute it and/or modify
//  it under the terms of the GNU Lesser General Public License as published
//  by the Free Software Foundation; either version 3.0 of the License, or
//  any later version.
//
//  The GPSTk is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU Lesser General Public License for more details.
//
//  You should have received a copy of the GNU Lesser General Public
//  License along with GPSTk; if not, write to the Free Software Foundation,
//  Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110, USA
//  
//  This software was developed by Applied Research Laboratories at the 
//  University of Texas at Austin.
//  Copyright 2004-2021, The Board of Regents of The University of Texas System
//
//==============================================================================


//==============================================================================
//
//  This software was developed by Applied Research Laboratories at the 
//  University of Texas at Austin, under contract to an agency or agencies 
//  within the U.S. Department of Defense. The U.S. Government retains all 
//  rights to use, duplicate, distribute, disclose, or release this software. 
//
//  Pursuant to DoD Directive 523024 
//
//  DISTRIBUTION STATEMENT A: This software has been approved for public 
//                            release, distribution is unlimited.
//
//==============================================================================
#include "GalINavEph.hpp"
#include "TestUtil.hpp"
#include "GALWeekSecond.hpp"

namespace gpstk
{
   std::ostream& operator<<(std::ostream& s, gpstk::NavMessageType e)
   {
      s << StringUtils::asString(e);
      return s;
   }

   std::ostream& operator<<(std::ostream& s, gpstk::GalHealthStatus e)
   {
      s << StringUtils::asString(e);
      return s;
   }

   std::ostream& operator<<(std::ostream& s, gpstk::GalDataValid e)
   {
      s << StringUtils::asString(e);
      return s;
   }
}

class GalINavEph_T
{
public:
      /// Make sure constructor initializes data members correctly.
   unsigned constructorTest();
   unsigned getUserTimeTest();
   unsigned fixFitTest();
};


unsigned GalINavEph_T ::
constructorTest()
{
   TUDEF("GalINavEph", "GalINavEph");
   gpstk::GalINavEph uut;
   TUASSERTFE(0.0, uut.bgdE5aE1);
   TUASSERTFE(0.0, uut.bgdE5bE1);
   TUASSERTE(unsigned, 255, uut.sisaIndex);
   TUASSERTE(unsigned, 0, uut.svid);
   TUASSERTE(gpstk::CommonTime, gpstk::CommonTime(), uut.xmit2);
   TUASSERTE(gpstk::CommonTime, gpstk::CommonTime(), uut.xmit3);
   TUASSERTE(gpstk::CommonTime, gpstk::CommonTime(), uut.xmit4);
   TUASSERTE(gpstk::CommonTime, gpstk::CommonTime(), uut.xmit5);
   TUASSERTE(uint16_t, 0, uut.iodnav1);
   TUASSERTE(uint16_t, 0, uut.iodnav2);
   TUASSERTE(uint16_t, 0, uut.iodnav3);
   TUASSERTE(uint16_t, 0, uut.iodnav4);
   TUASSERTE(gpstk::GalHealthStatus,gpstk::GalHealthStatus::Unknown,uut.hsE5b);
   TUASSERTE(gpstk::GalHealthStatus,gpstk::GalHealthStatus::Unknown,uut.hsE1B);
   TUASSERTE(gpstk::GalDataValid,gpstk::GalDataValid::Unknown,uut.dvsE5b);
   TUASSERTE(gpstk::GalDataValid,gpstk::GalDataValid::Unknown,uut.dvsE1B);
   TUASSERTE(gpstk::NavMessageType, gpstk::NavMessageType::Ephemeris,
             uut.signal.messageType);
   TURETURN();
}


unsigned GalINavEph_T ::
getUserTimeTest()
{
   TUDEF("GalINavEph", "getUserTime");
   gpstk::GalINavEph uut;
      // just using made-up numbers
   uut.timeStamp = gpstk::GALWeekSecond(2100,135.0);
   uut.xmitTime = gpstk::GALWeekSecond(2100,139.0);
   uut.xmit2 = gpstk::GALWeekSecond(2100,200.0);
   uut.xmit3 = gpstk::GALWeekSecond(2100,1.0);
   uut.xmit4 = gpstk::GALWeekSecond(2100,7.0);
   uut.xmit5 = gpstk::GALWeekSecond(2100,11.0);
   gpstk::CommonTime exp(gpstk::GALWeekSecond(2100,202.0));
   TUASSERTE(gpstk::CommonTime, exp, uut.getUserTime());
   TURETURN();
}


unsigned GalINavEph_T ::
fixFitTest()
{
   TUDEF("GalINavEph", "fixFit");
   gpstk::GalINavEph uut;
   gpstk::GALWeekSecond beginExpWS2(2059, 597600), endExpWS2(2060, 12600);
   gpstk::CommonTime beginExp2(beginExpWS2), endExp2(endExpWS2);
   uut.Toe = gpstk::GALWeekSecond(2059, 603000);
   uut.xmitTime = gpstk::GALWeekSecond(2059,597600);
   TUCATCH(uut.fixFit());
   TUASSERTE(gpstk::CommonTime, beginExp2, uut.beginFit);
   TUASSERTE(gpstk::CommonTime, endExp2, uut.endFit);
      //uut.dump(std::cerr, gpstk::OrbitDataKepler::Detail::Full);
   TURETURN();
}


int main()
{
   GalINavEph_T testClass;
   unsigned errorTotal = 0;

   errorTotal += testClass.constructorTest();
   errorTotal += testClass.getUserTimeTest();
   errorTotal += testClass.fixFitTest();

   std::cout << "Total Failures for " << __FILE__ << ": " << errorTotal
             << std::endl;

   return errorTotal;
}
