#ifndef NAVDATAFACTORY_HPP
#define NAVDATAFACTORY_HPP

#include <memory>
#include <map>
#include "NavSignalID.hpp"
#include "CommonTime.hpp"
#include "NavData.hpp"
#include "NavValidityType.hpp"
#include "NavMessageID.hpp"
#include "NavSearchOrder.hpp"

namespace gpstk
{
      /** Abstract base class that defines the interface for searching
       * for navigation data. */
   class NavDataFactory
   {
   public:
         /** Initialize navValidity to All and procNavTypes to all
          * known message types. */
      NavDataFactory()
            : navValidity(NavValidityType::All),
              procNavTypes(allNavMessageTypes)
      {}

         /** Search the store as defined by each child class of
          * NavDataFactory to find the navigation message that meets
          * the specified criteria.
          * @param[in] nmid Specify the message type, satellite and
          *   codes to match.
          * @param[in] when The time of interest to search for data.
          * @param[out] navData The resulting navigation message.
          * @param[in] valid Specify whether to search only for valid
          *   or invalid messages, or both.
          * @param[in] order Specify whether to search by receiver
          *   behavior or by nearest to when in time. 
          * @return true if successful.  If false, navData will be untouched. */
      virtual bool find(const NavMessageID& nmid, const CommonTime& when,
                        NavDataPtr& navData, NavValidityType valid,
                        NavSearchOrder order) = 0;

         /** Set the factory's handling of valid and invalid
          * navigation data.  This should be called before any find()
          * calls.
          * @param[in] nvt The new nav data loading filter method. */
      virtual void setValidityFilter(NavValidityType nvt)
      { navValidity = nvt; }

         /** Indicate what nav message types the factories should be
          * loading.  This should be called before the factories
          * acquire any data.
          * @param[in] nmts The set of nav message types to be
          *   processed by the factories. */
      virtual void setTypeFilter(const NavMessageTypeSet& nmts)
      { procNavTypes = nmts; }

         /** Add a data source for this factory.  This could be a file
          * name, an IP address and port, or something else entirely,
          * depending on the factory implementation.  This method is
          * declared here so that NavDataFactoryPtr objects can be set
          * up without having to do any casting of pointers.
          * @param[in] source A string describing the source of data for the factory.
          * @return true If the factory was able to process the data in source. */
      virtual bool addDataSource(const std::string& source) = 0;

         /** Define which signals this factory supports.  This will be
          * empty by default, which means that NavLibrary would not
          * use this factory, so it is up to the derived classes to
          * fill out the signals as appropriate. */
      NavSignalSet supportedSignals;

   protected:
         /** Determines how the factory should load nav data from the store.
          * @note There's nothing to prevent someone from doing
          *   something silly like setting this to "InvalidOnly" then
          *   doing a find for "ValidOnly" which of course will result
          *   in no results. */
      NavValidityType navValidity;

         /** Determines which types of navigation message data the
          * factory should be processing. */
      NavMessageTypeSet procNavTypes;
   };

      /// Managed pointer to NavDataFactory.
   using NavDataFactoryPtr = std::shared_ptr<NavDataFactory>;
      /// Map signal to a factory.
   using NavDataFactoryMap = std::multimap<NavSignalID, NavDataFactoryPtr>;
}

#endif // NAVDATAFACTORY_HPP
