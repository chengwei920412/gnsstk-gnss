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

/**
 *  @file LoopedFramework.hpp
 *  Basic framework for programs processing loops in the GPS toolkit
 */

#ifndef GNSSTK_LOOPEDFRAMEWORK_HPP
#define GNSSTK_LOOPEDFRAMEWORK_HPP

#include "BasicFramework.hpp"

namespace gnsstk
{
      /// @ingroup AppFrame
      //@{

      /**
       * This is a basic framework for programs processing in loops in
       * the GNSSTK.
       *
       * The end user should define subclasses of this class,
       * implementing those methods described as being meant to be
       * overridden; initialize(), additionalSetup(), spinUp(), process(), and
       * shutDown().
       * In the process() method, simply set variable timeToDie true prior to
       * returning for the program to call shutDown() and then terminate.
       *
       * In use, the user will construct an object of the class
       * derived from this, then call the initialize() and run()
       * methods in that order.
       */
   class LoopedFramework : public BasicFramework
   {
   public:
         /**
          * Constructor for LoopedFramework.
          * @param[in] applName name of the program (argv[0]).
          * @param[in] applDesc text description of program's function
          *   (used by CommandOption help).
          */
      LoopedFramework(const std::string& applName,
                      const std::string& applDesc)
            noexcept
            : BasicFramework(applName, applDesc), timeToDie(false)
      { }

         /// Destructor.
      virtual ~LoopedFramework() {}

   protected:
      bool timeToDie;   ///< if set to true, the loop will terminate

         /**
          * Called by the run() method, calls additionalSetup(),
          * spinUp(), and process(), in that order. Generally should not be
          * overridden.
          */
      virtual void completeProcessing();

   private:
         // Do not allow the use of the default constructor.
      LoopedFramework();
   }; // class LoopedFramework

      //@}

} // namespace gnsstk

#endif
