cmake_minimum_required(VERSION 3.12)
project(mpcexamples)

set(CMAKE_CXX_STANDARD 17)

# VTK
find_package(VTK REQUIRED)
include(${VTK_USE_FILE})
include_directories(${VTK_INCLUDE_DIRS})

# blitz++
#-------
# https://github.com/bkclark/pimcpp/blob/master/CMake/FindBlitz%2B%2B.cmake
# this module look for blitz++ (http://www.oonumerics.org/blitz) support
# it will define the following values
#
# BLITZ_INCLUDE_DIR = where blitz/blitz.h can be found
#
# May want to define this but seldom required
# BLITZ_LIBRARY = where blitz library can be found (reserved)
#
#IF(EXISTS ${PROJECT_CMAKE}/BlitzppConfig.cmake)
#  INCLUDE(${PROJECT_CMAKE}/BlitzppConfig.cmake)
#ENDIF(EXISTS ${PROJECT_CMAKE}/BlitzppConfig.cmake)

SET(Libblitz blitz)
IF(QMC_BUILD_STATIC)
    SET(Libblitz libblitz.a)
ENDIF(QMC_BUILD_STATIC)

SET(TRIAL_LIBRARY_PATHS
        /usr/local/lib
        /sw/lib
        ${CMAKE_SOURCE_DIR}/lib
        $ENV{BLITZ_HOME}/lib
        )

SET(TRIAL_INCLUDE_PATHS
        /usr/local/include
        /sw/include
        ${CMAKE_SOURCE_DIR}/include
        $ENV{BLITZ_HOME}/include
        )

FIND_PATH(BLITZ_INCLUDE_DIR blitz/blitz.h ${TRIAL_INCLUDE_PATHS})
FIND_LIBRARY(BLITZ_LIBRARIES ${Libblitz} ${TRIAL_LIBRARY_PATHS})

IF(BLITZ_INCLUDE_DIR)
    SET(BLITZ_FOUND 1 CACHE BOOL "Found blitz++ library")
    MESSAGE(STATUS "BLITZ_INCLUDE_DIR=${BLITZ_INCLUDE_DIR}")
    MESSAGE(STATUS "BLITZ_LIBRARIES=${BLITZ_LIBRARIES}")
ELSE(BLITZ_INCLUDE_DIR)
    SET(BLITZ_FOUND 0 CACHE BOOL "Found blitz++ library")
ENDIF(BLITZ_INCLUDE_DIR)

MARK_AS_ADVANCED(
        BLITZ_INCLUDE_DIR
        BLITZ_FOUND
)
#-------
include_directories(
        ${BLITZ_INCLUDE_DIR}
        /Users/atorlucci/projectsCLion/mpc/src
)

# eigen ----------------------------------------
find_package(Eigen3 3.3 REQUIRED NO_MODULE)

set(ALL_LIBS
        ${VTK_LIBRARIES}
        ${BLITZ_LIBRARIES}
        Eigen3::Eigen
        )

set(HEADER_FILES
        parametervaluetest.hpp
        arraysandtensors.hpp
        # utilities
        mpcx_constants.hpp
        mpcx_printtensorcomponents.hpp
        mpcx_accumulator.hpp
        mpcx_innerproductor.hpp
        mpcx_arithmeticaverage.hpp
        mpcx_harmonicaverage.hpp
        mpcx_kdeltaidentitytensor.hpp
        mpcx_magandnorm.hpp
        mpcx_coordinatemapping.hpp
        # core
        mpcx_tensorrank2componentindex.hpp
        mpcx_tensorrank4componentindex.hpp
        mpcx_tensorrank2component.hpp
        mpcx_tensorrank4component.hpp
        mpcx_symmetrytypes.hpp
        mpcx_stiffnesscompliance_csrelationship.hpp
        # data
        mpcx_mineraldata.hpp
        mpcx_symmetrymatrixrepresentation.hpp
        # rockphysics
        mpcx_rockphysicstransforms.hpp
        mpcx_tensorinvariants.hpp
        mpcx_fluidphase.hpp
        mpcx_solidphase.hpp
        mpcx_mixinglaws.hpp
        # transformation
        mpcx_eulerangles.hpp
        mpcx_transformation.hpp
        # mechanics
        mpcx_greenchristoffel.hpp
        mpcx_quartzvelsinX0X1plane.hpp
        mpcx_orientationdistribution.hpp
        )

set(SOURCE_FILES
        main.cpp
        # utilities
        mpcx_constants.cpp
        mpcx_printtensorcomponents.cpp
        mpcx_accumulator.cpp
        mpcx_innerproductor.cpp
        mpcx_arithmeticaverage.cpp
        mpcx_harmonicaverage.cpp
        mpcx_kdeltaidentitytensor.cpp
        mpcx_magandnorm.cpp
        mpcx_coordinatemapping.cpp
        # core
        mpcx_tensorrank2componentindex.cpp
        mpcx_tensorrank4componentindex.cpp
        mpcx_tensorrank2component.cpp
        mpcx_tensorrank4component.cpp
        mpcx_symmetrytypes.cpp
        mpcx_stiffnesscompliance_csrelationship.cpp
        # data
        mpcx_mineraldata.cpp
        mpcx_symmetrymatrixrepresentation.cpp
        # rockphysics
        mpcx_rockphysicstransforms.cpp
        mpcx_tensorinvariants.cpp
        mpcx_fluidphase.cpp
        mpcx_solidphase.cpp
        mpcx_mixinglaws.cpp
        # transformation
        mpcx_eulerangles.cpp
        mpcx_transformation.cpp
        # mechanics
        mpcx_greenchristoffel.cpp
        mpcx_quartzvelsinX0X1plane.cpp
        mpcx_orientationdistribution.cpp
        )
add_executable(mpcexamples ${HEADER_FILES} ${SOURCE_FILES} )

target_link_libraries(mpcexamples ${ALL_LIBS})

