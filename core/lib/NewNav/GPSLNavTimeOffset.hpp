#ifndef GPSTK_GPSLNAVTIMEOFFSET_HPP
#define GPSTK_GPSLNAVTIMEOFFSET_HPP

#include "TimeOffsetData.hpp"
#include "TimeSystem.hpp"

namespace gpstk
{
      /** Defines the interface for classes that provide the ability
       * to convert between time systems, using data extracted from
       * GPS navigation messages. */
   class GPSLNavTimeOffset : public TimeOffsetData
   {
   public:
         /// Initialize all data to 0.
      GPSLNavTimeOffset();

         /** Checks the contents of this message against known
          * validity rules as defined in the appropriate ICD.
          * @todo implement some checking.
          * @return true if this message is valid according to ICD criteria.
          */
      bool validate() const override
      { return true; }

         /** Returns the time when the navigation message would have
          * first been available to the user equipment, i.e. the time
          * at which the final bit of a given broadcast navigation
          * message is received.  This is used by
          * NavDataFactoryWithStore::find() in User mode.
          * @return transmit time + 6s, which is the time required for sf1.
          */
      CommonTime getUserTime() const override
      { return timeStamp + 6.0; }

         /** Get the offset, in seconds, to apply to times when
          * converting them from fromSys to toSys.
          * @param[in] fromSys The time system to convert from.
          * @param[in] toSys The time system to convert to.
          * @param[in] when The time being converted, in the GPS time
          *   system, "as estimated by the user after correcting
          *   t<sub>SV</sub> for factors described in paragraph
          *   20.3.3.3.3 as well as for SA effects"
          * @param[out] offset The offset when converting fromSys->toSys.
          * @return true if an offset is available, false if not. */
      bool getOffset(TimeSystem fromSys, TimeSystem toSys,
                     const CommonTime& when, double& offset)
         override;

         // these terms are defined in IS-GPS-200, 20.3.3.5.2.4

      double deltatLS; ///< &Delta;t<sub>LS</sub> term
      double a0;       ///< A<sub>0</sub> term
      double a1;       ///< A<sub>1</sub> term
      double tot;      ///< t<sub>ot</sub> term
      unsigned wnt;    ///< UTC reference week
   };
}

#endif // GPSTK_GPSLNAVTIMEOFFSET_HPP
