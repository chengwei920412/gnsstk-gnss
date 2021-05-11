# Testing the swig/python bindings
#
# Since this requires that there be a valid python runtime, these tests are
# be quite different from the C++ library and application tests

add_test(NAME swig_test_import
  COMMAND ${PYTHON_EXECUTABLE} -c "import gpstk; print('gpstk imported successfully')"
  WORKING_DIRECTORY ${MODULE_PATH}
  )
set_property(TEST swig_test_import PROPERTY LABELS swig)


set(td  ${MODULE_PATH}/tests)

add_test(NAME swig_test_constants
  COMMAND ${PYTHON_EXECUTABLE} test_constants.py
  WORKING_DIRECTORY ${td}
  )
set_property(TEST swig_test_constants PROPERTY LABELS swig constants)

add_test(NAME swig_test_rinex3
  COMMAND ${PYTHON_EXECUTABLE} test_rinex3.py -i ${GPSTK_TEST_DATA_DIR} -o ${GPSTK_TEST_OUTPUT_DIR}
  WORKING_DIRECTORY ${td}
  )
set_property(TEST swig_test_rinex3 PROPERTY LABELS swig RINEX3)

add_test(NAME swig_test_prsolve
        COMMAND ${PYTHON_EXECUTABLE} test_prsolve.py -i ${GPSTK_TEST_DATA_DIR} -o ${GPSTK_TEST_OUTPUT_DIR}
        WORKING_DIRECTORY ${td}
        )
set_property(TEST swig_test_prsolve PROPERTY LABELS swig PRSOLVE)

add_test(NAME swig_test_time
  COMMAND ${PYTHON_EXECUTABLE} test_time.py -i ${GPSTK_TEST_DATA_DIR} -o ${GPSTK_TEST_OUTPUT_DIR}
  WORKING_DIRECTORY ${td}
  )
set_property(TEST swig_test_time PROPERTY LABELS swig Time CommonTime)

add_test(NAME swig_test_misc
  COMMAND ${PYTHON_EXECUTABLE} test_misc.py
  WORKING_DIRECTORY ${td}
  )
set_property(TEST swig_test_misc PROPERTY LABELS swig ObsID SatID)

#add_test(NAME swig_test_store
#  COMMAND ${PYTHON_EXECUTABLE} test_store.py
#  WORKING_DIRECTORY ${td}
#  )
#set_property(TEST swig_test_store PROPERTY LABELS swig )

add_test(NAME swig_test_NewNav
  COMMAND ${PYTHON_EXECUTABLE} test_NewNav.py
  WORKING_DIRECTORY ${td}
  )
set_property(TEST swig_test_NewNav PROPERTY LABELS swig NewNav)

add_test(NAME swig_test_NavLibrary
  COMMAND ${PYTHON_EXECUTABLE} test_NavLibrary.py -i ${GPSTK_TEST_DATA_DIR}
  WORKING_DIRECTORY ${td}
  )
set_property(TEST swig_test_NavLibrary PROPERTY LABELS swig NewNav)

add_test(NAME swig_test_RinexNavDataFactory
  COMMAND ${PYTHON_EXECUTABLE} test_RinexNavDataFactory.py -i ${GPSTK_TEST_DATA_DIR}
  WORKING_DIRECTORY ${td}
  )
set_property(TEST swig_test_RinexNavDataFactory PROPERTY LABELS swig NewNav)

add_test(NAME swig_test_SP3NavDataFactory
  COMMAND ${PYTHON_EXECUTABLE} test_SP3NavDataFactory.py -i ${GPSTK_TEST_DATA_DIR}
  WORKING_DIRECTORY ${td}
  )
set_property(TEST swig_test_SP3NavDataFactory PROPERTY LABELS swig NewNav)

add_test(NAME swig_test_SEMNavDataFactory
  COMMAND ${PYTHON_EXECUTABLE} test_SEMNavDataFactory.py -i ${GPSTK_TEST_DATA_DIR}
  WORKING_DIRECTORY ${td}
  )
set_property(TEST swig_test_SEMNavDataFactory PROPERTY LABELS swig NewNav)

add_test(NAME swig_test_YumaNavDataFactory
  COMMAND ${PYTHON_EXECUTABLE} test_YumaNavDataFactory.py -i ${GPSTK_TEST_DATA_DIR}
  WORKING_DIRECTORY ${td}
  )
set_property(TEST swig_test_YumaNavDataFactory PROPERTY LABELS swig NewNav)

add_test(NAME swig_test_MultiFormatNavDataFactory
  COMMAND ${PYTHON_EXECUTABLE} test_MultiFormatNavDataFactory.py -i ${GPSTK_TEST_DATA_DIR}
  WORKING_DIRECTORY ${td}
  )
set_property(TEST swig_test_MultiFormatNavDataFactory PROPERTY LABELS swig NewNav)
