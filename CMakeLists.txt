cmake_minimum_required(VERSION 3.16)
project(modules)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


if (UNIX AND NOT APPLE)
    set(LINUX 1)
endif (UNIX AND NOT APPLE)


find_package(Qt5 COMPONENTS Core sql REQUIRED)


set(SRC)


add_library(modules

        bdlbsc/module/supper/IModule.h

        bdlbsc/module/supper/IData.h

        bdlbsc/module/data/Data.cpp

        bdlbsc/module/data/Data.h

        bdlbsc/module/data/DataDb.cpp

        bdlbsc/module/data/DataDb.h

        bdlbsc/module/common/Common.cpp bdlbsc/module/common/Common.h)

target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Core Qt5:sql)