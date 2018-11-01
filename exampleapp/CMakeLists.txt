cmake_minimum_required(VERSION 3.12)
project(mpcexampleapp)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CONFIGURATION_TYPES "Debug;Release")
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# VTK
find_package(VTK REQUIRED)
include(${VTK_USE_FILE})
include_directories(${VTK_INCLUDE_DIRS})

# QT5
# https://github.com/Homebrew/homebrew-core/issues/8392
if(APPLE AND EXISTS /usr/local/opt/qt5)
    # Homebrew installs Qt5 (up to at least 5.9.1) in
    # /usr/local/qt5, ensure it can be found by CMake since
    # it is not in the default /usr/local prefix.
    list(APPEND CMAKE_PREFIX_PATH "/usr/local/opt/qt5")
endif()
find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5OpenGL REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
#qt5_add_resources(Resources ${Resources})

# BLITZ
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
)

# EIGEN
find_package(Eigen3 3.3 REQUIRED NO_MODULE)

# MPC
include_directories(/Users/atorlucci/projectsCLion/mpc/src)

set(HEADER_FILES
        mainwindow.h
        homepage.h
        fluidphaseview2.h
        solidphaseview2.h
        mixinglawsview.h
        mineralvelsview.h
        # misc
        transformationview.h
        greenchristoffelnormalvectorview.h
        )

set(SOURCE_FILES
        main.cpp
        mainwindow.cpp
        homepage.cpp
        fluidphaseview2.cpp
        solidphaseview2.cpp
        mixinglawsview.cpp
        mineralvelsview.cpp
        # misc
        transformationview.cpp
        greenchristoffelnormalvectorview.cpp
        )




add_executable(mpcexampleapp MACOSX_BUNDLE ${HEADER_FILES} ${SOURCE_FILES})

target_link_libraries(mpcexampleapp Qt5::Widgets Qt5::OpenGL ${VTK_LIBRARIES} ${BLITZ_LIBRARIES} Eigen3::Eigen)

#install(TARGETS qtvtktest RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/bin)

