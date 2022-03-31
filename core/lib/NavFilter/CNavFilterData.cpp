//==============================================================================
//
//  This file is part of GNSSTk, the ARL:UT GNSS Toolkit.
//
//  The GNSSTk is free software; you can redistribute it and/or modify
//  it under the terms of the GNU Lesser General Public License as published
//  by the Free Software Foundation; either version 3.0 of the License, or
//  any later version.
//
//  The GNSSTk is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU Lesser General Public License for more details.
//
//  You should have received a copy of the GNU Lesser General Public
//  License along with GNSSTk; if not, write to the Free Software Foundation,
//  Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110, USA
//
//  This software was developed by Applied Research Laboratories at the
//  University of Texas at Austin.
//  Copyright 2004-2022, The Board of Regents of The University of Texas System
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

/*
* CNavFilterData.cpp
*/
#include "CNavFilterData.hpp"

namespace gnsstk
{
   CNavFilterData::CNavFilterData():
       NavFilterKey()
       {}

   CNavFilterData::CNavFilterData(gnsstk::PackedNavBits* pnbArg):
      NavFilterKey()
   {
      loadData(pnbArg);
   }

   void CNavFilterData::loadData(PackedNavBits* pnbArg)
   {
      timeStamp = pnbArg->getTransmitTime();
      rxID = pnbArg->getRxID();
      stationID = "unk";
      prn = pnbArg->getsatSys().id;
      carrier = pnbArg->getobsID().band;
      code    = pnbArg->getobsID().code;

      pnb = pnbArg;
   }

   void CNavFilterData::
   dump(std::ostream& s) const
   {
         // This outputs the "common" information
      NavFilterKey::dump(s);

         // Dump bits as 32 bit words
      pnb->outputPackedBits(s,10);
   }

   std::ostream& operator<<(std::ostream& s, const CNavFilterData& nfd)
   {
      nfd.dump(s);
      return s;
   }
}
