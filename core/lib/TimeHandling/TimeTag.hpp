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

#ifndef GNSSTK_TIMETAG_HPP
#define GNSSTK_TIMETAG_HPP

#include "CommonTime.hpp"
#include "TimeSystem.hpp"
#include "TimeSystemConverter.hpp"
#include "StringUtils.hpp"
#include <map>

namespace gnsstk
{
      /// @ingroup TimeHandling
      //@{

      /** This class is an abstract base class inherited by all the classes
       * that provide a specific time representation.
       * These time representations must ensure or provide a way for the
       * user to verify their own self-consistency.
       */
   class TimeTag
   {
   public:

         /// Default constructor
      TimeTag()
      {}

         /// Constructor
      TimeTag( const TimeSystem& ts )
      { timeSystem = ts; }

         /// Virtual Destructor.
      virtual ~TimeTag()
      {}

         /// @throw InvalidRequest if this TimeTag cannot be correctly
         /// represented by a CommonTime object.
      virtual CommonTime convertToCommonTime() const = 0;

         /// @throw InvalidRequest if \c ct cannot be correctly represented
         /// in this TimeTag object.
      virtual void convertFromCommonTime( const CommonTime& ct ) = 0;

         /// This function formats this time to a string.  The exceptions
         /// thrown would only be due to problems parsing the fmt string.
      virtual std::string printf( const std::string& fmt ) const = 0;

         /// This function works similarly to printf.  Instead of filling
         /// the format with data, it fills with error messages.
      virtual std::string printError( const std::string& fmt ) const = 0;

         /**
          * This function sets this object to the time stored in the given
          * string \a str.
          * @param str the string to parse
          * @param fmt the string containing the time format
          * @throw InvalidRequest if an invalid time is given.
          * @throw StringException on problems parsing the strings.
          */
      virtual void scanf( const std::string& str,
                          const std::string& fmt );

         /// This type maps a character ( from a time format ) to its
         /// corresponding value ( from a time string ).
      typedef std::map< char, std::string> IdToValue;

         /**
          * This is the workhorse for the scanf family of functions.  It parses
          * the given string \a str with the given format \a fmt in order to
          * extract a time or part of a time from \a str.
          * @param str the string from which to cull time information
          * @param fmt the string containing the time format
          * @param info a mapping of all of the character identifier to their
          *  respective culled time information
          * @throw StringException on problems parsing the strings.
          */
      static void getInfo( const std::string& str,
                           const std::string& fmt,
                           IdToValue& info );

         /**
          * Set this object using the information provided in \a info.
          * @param info the IdToValue object to which this object shall be set.
          * @return true if this object was successfully set using the
          *  data in \a info, false if not.
          */
      virtual bool setFromInfo( const IdToValue& info ) = 0;

         /// Return a string containing the characters that this class
         /// understands when printing times.
      virtual std::string getPrintChars() const = 0;

         /// Return a string containing the default format to use in printing.
      virtual std::string getDefaultFormat() const = 0;

         /// Returns true if this object's members are valid, false otherwise.
      virtual bool isValid() const = 0;

         /// Reset this object to the default state.
      virtual void reset() = 0;

         /// Format this time as a string using a format specified by the
         /// inheriting class.
      virtual std::string asString() const
      { return printf( getDefaultFormat() ); }

         /// Hey, it's an implicit casting operator!  Basically just a lazy
         /// way to get at convertToCommonTime().
      virtual operator CommonTime() const
      { return convertToCommonTime(); }

         /// This returns the regular expression prefix that is used when
         /// searching for integer specifiers.
      static inline std::string getFormatPrefixInt()
      { return "%[ 0-]?[[:digit:]]*"; }

         /// This returns the regular expression prefix that is used when
         /// searching for float specifiers.
      static inline std::string getFormatPrefixFloat()
      { return getFormatPrefixInt() + "(\\.[[:digit:]]+)?"; }

         /// This returns the default error string for the TimeTag classes.
      static inline std::string getError()
      { return "ErrorBadTime"; }

         /// Set method for internal variable timeSystem (enum).
      void setTimeSystem( const TimeSystem& timeSys )
      { timeSystem = timeSys; }

         /// Obtain time system info (enum).
      TimeSystem getTimeSystem() const
      { return timeSystem ; }

         /** Modify both the time value and time system to reflect a
          * change in time system.
          * @param[in] timeSystem The time system to convert this time to.
          * @param[in,out] conv The converter object to use to get the
          *   offset between the current time system and the requested
          *   time system.
          * @return true if successful, false if unable to get/apply
          *   the time system offset.
          */
      bool changeTimeSystem(TimeSystem timeSys, TimeSystemConverter* conv);

         /** Modify both the time value and time system to reflect a
          * change in time system.
          * @param[in] timeSystem The time system to convert this time to.
          * @return true if successful, false if the static converter
          *   CommonTime::tsConv has not been set or is unable to
          *   get/apply the time system offset.
          */
      bool changeTimeSystem(TimeSystem timeSys);

         /** Check to see if two time systems are comparable
          * (including "Any" handling).
          * @note This method replicates the standard time system
          *   checking currently in most (all?) TimeTag classes.
          * @param[in] ts1 The first time system.
          * @param[in] ts2 The second time system.
          * @throw InvalidRequest if neither ts1 or ts2 are "Any" and
          *   they are not equal. */
      static void checkTimeSystem(TimeSystem ts1, TimeSystem ts2);

   protected:

      TimeSystem timeSystem; ///< time system (representation) of the data
   };

      //@}

} // namespace

std::ostream& operator<<( std::ostream& s,
                          const gnsstk::TimeTag& t );

#endif // GNSSTK_TIMETAG_HPP
