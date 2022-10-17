%include "std_shared_ptr.i"

 /* note: If you get this compiler error
  *
  * In function ‘PyObject* _wrap_delete_OrbitDataKepler(PyObject*, PyObject*)’:
  * error: ‘smartarg1’ was not declared in this scope
  *
  * That means that you have a derived class from a base smart pointer
  * that needs to be declared in the list below.  In this case,
  * OrbitDataKepler needed to be added to the %shared_ptr declarations
  * below.
  */
%shared_ptr(gnsstk::NavFit)
%shared_ptr(gnsstk::NavData)
%shared_ptr(gnsstk::TimeOffsetData)
%shared_ptr(gnsstk::StdNavTimeOffset)
%shared_ptr(gnsstk::NavHealthData)
%shared_ptr(gnsstk::OrbitData)
%shared_ptr(gnsstk::OrbitDataKepler)
%shared_ptr(gnsstk::OrbitDataBDS)
%shared_ptr(gnsstk::IonoNavData)
%shared_ptr(gnsstk::InterSigCorr)
%shared_ptr(gnsstk::KlobucharIonoNavData)
%shared_ptr(gnsstk::NeQuickIonoNavData)
%shared_ptr(gnsstk::OrbitDataGPS)
%shared_ptr(gnsstk::GPSLNavData)
%shared_ptr(gnsstk::GPSLNavEph)
%shared_ptr(gnsstk::GPSLNavAlm)
%shared_ptr(gnsstk::GPSLNavHealth)
%shared_ptr(gnsstk::GPSLNavTimeOffset)
%shared_ptr(gnsstk::GPSLNavIono)
%shared_ptr(gnsstk::GPSLNavISC)
%shared_ptr(gnsstk::GPSCNavData)
%shared_ptr(gnsstk::GPSCNavEph)
%shared_ptr(gnsstk::GPSCNavAlm)
%shared_ptr(gnsstk::GPSCNavHealth)
%shared_ptr(gnsstk::GPSCNavTimeOffset)
%shared_ptr(gnsstk::GPSCNavRedAlm)
%shared_ptr(gnsstk::GPSCNavIono)
%shared_ptr(gnsstk::GPSCNavISC)
%shared_ptr(gnsstk::GPSCNav2Eph)
%shared_ptr(gnsstk::GPSCNav2Alm)
%shared_ptr(gnsstk::GPSCNav2Health)
%shared_ptr(gnsstk::GPSCNav2TimeOffset)
%shared_ptr(gnsstk::GPSCNav2Iono)
%shared_ptr(gnsstk::GPSCNav2ISC)
%shared_ptr(gnsstk::OrbitDataSP3)
%shared_ptr(gnsstk::RinexTimeOffset)
%shared_ptr(gnsstk::OrbitDataGal)
%shared_ptr(gnsstk::GalINavEph)
%shared_ptr(gnsstk::GalINavAlm)
%shared_ptr(gnsstk::GalINavHealth)
%shared_ptr(gnsstk::GalINavTimeOffset)
%shared_ptr(gnsstk::GalINavIono)
%shared_ptr(gnsstk::GalINavISC)
%shared_ptr(gnsstk::GalFNavEph)
%shared_ptr(gnsstk::GalFNavAlm)
%shared_ptr(gnsstk::GalFNavHealth)
%shared_ptr(gnsstk::GalFNavTimeOffset)
%shared_ptr(gnsstk::GalFNavIono)
%shared_ptr(gnsstk::GalFNavISC)
%shared_ptr(gnsstk::BDSD1NavData)
%shared_ptr(gnsstk::BDSD1NavEph)
%shared_ptr(gnsstk::BDSD1NavAlm)
%shared_ptr(gnsstk::BDSD1NavHealth)
%shared_ptr(gnsstk::BDSD1NavTimeOffset)
%shared_ptr(gnsstk::BDSD1NavIono)
%shared_ptr(gnsstk::BDSD1NavISC)
%shared_ptr(gnsstk::BDSD2NavData)
%shared_ptr(gnsstk::BDSD2NavEph)
%shared_ptr(gnsstk::BDSD2NavAlm)
%shared_ptr(gnsstk::BDSD2NavHealth)
%shared_ptr(gnsstk::BDSD2NavTimeOffset)
%shared_ptr(gnsstk::BDSD2NavIono)
%shared_ptr(gnsstk::BDSD2NavISC)
%shared_ptr(gnsstk::GLOCNavAlm)
%shared_ptr(gnsstk::GLOCNavData)
%shared_ptr(gnsstk::GLOCNavEph)
%shared_ptr(gnsstk::GLOCNavHealth)
%shared_ptr(gnsstk::GLOCNavIono)
%shared_ptr(gnsstk::GLOCNavUT1TimeOffset)
%shared_ptr(gnsstk::GLOFNavAlm)
%shared_ptr(gnsstk::GLOFNavData)
%shared_ptr(gnsstk::GLOFNavEph)
%shared_ptr(gnsstk::GLOFNavHealth)
%shared_ptr(gnsstk::GLOFNavISC)
%shared_ptr(gnsstk::GLOFNavTimeOffset)
%shared_ptr(gnsstk::GLOFNavUT1TimeOffset)

%shared_ptr(gnsstk::NavDataFactory)
%shared_ptr(gnsstk::NavDataFactoryWithStore)
%shared_ptr(gnsstk::NavDataFactoryWithStoreFile)
%shared_ptr(gnsstk::RinexNavDataFactory)
%shared_ptr(gnsstk::SP3NavDataFactory)
%shared_ptr(gnsstk::SEMNavDataFactory)
%shared_ptr(gnsstk::YumaNavDataFactory)
%shared_ptr(gnsstk::MultiFormatNavDataFactory);
%shared_ptr(gnsstk::PNBNavDataFactory)
%shared_ptr(gnsstk::PNBGPSLNavDataFactory)
%shared_ptr(gnsstk::PNBGPSCNavDataFactory)
%shared_ptr(gnsstk::PNBGPSCNav2DataFactory)
%shared_ptr(gnsstk::PNBMultiGNSSNavDataFactory)
%shared_ptr(gnsstk::PNBGalINavDataFactory)
%shared_ptr(gnsstk::PNBGalFNavDataFactory)
%shared_ptr(gnsstk::PNBBDSD1NavDataFactory)
%shared_ptr(gnsstk::PNBBDSD2NavDataFactory)
%shared_ptr(gnsstk::PNBGLOCNavDataFactory)
%shared_ptr(gnsstk::PNBGLOFNavDataFactory)
 // silence warnings from swig
%shared_ptr(gnsstk::TimeSystemCorrection)
