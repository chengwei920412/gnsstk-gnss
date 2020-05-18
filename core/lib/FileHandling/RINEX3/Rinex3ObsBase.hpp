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
//  Copyright 2004-2019, The University of Texas at Austin
//
//==============================================================================

//==============================================================================
//
//  This software developed by Applied Research Laboratories at the University of
//  Texas at Austin, under contract to an agency or agencies within the U.S. 
//  Department of Defense. The U.S. Government retains all rights to use,
//  duplicate, distribute, disclose, or release this software. 
//
//  Pursuant to DoD Directive 523024 
//
//  DISTRIBUTION STATEMENT A: This software has been approved for public 
//                            release, distribution is unlimited.
//
//==============================================================================

/**
 * @file Rinex3ObsBase.hpp
 * Base class for RINEX observation file data
 */

#ifndef GPSTK_RINEX3OBSBASE_HPP
#define GPSTK_RINEX3OBSBASE_HPP

#include "FFData.hpp"

namespace gpstk
{
      /// @ingroup FileHandling
      //@{

      /** This level isn't serving any purpose other than to make
       * the class diagram look nice...
       */

   class Rinex3ObsBase : public FFData
   {
   public:

         /// Destructor
      virtual ~Rinex3ObsBase() {}

         /** Current gpstk supported version.
          * @note this is declared here and not in header to avoid
          *   issues with cross-dependent code, e.g. ObsID depending
          *   on Rinex3ObsHeader and vice-versa. */
      static const double currentVersion;
   };

      //@}

}  // namespace

#endif
