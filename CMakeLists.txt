cmake_minimum_required(VERSION 3.5)
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


include_directories(D:/Local/vcpkg/installed/x64-windows/include)
link_directories(D:/Local/vcpkg/installed/x64-windows/lib)

include_directories("D:/Local/libs/include")
link_directories("D:/Local/libs/lib")


find_package(Qt5 COMPONENTS
        Core
        sql
        REQUIRED)

set(SRC

        bdlbsc/module/supper/IData.h
        bdlbsc/module/supper/IMD5Utils.h
        bdlbsc/module/supper/IModule.h
        bdlbsc/module/supper/IStringUtils.h
        bdlbsc/module/supper/IThreadUtils.h
        bdlbsc/module/supper/IUtils.h
        bdlbsc/module/supper/IUUIDUtils.h





        bdlbsc/module/data/Data.cpp
        bdlbsc/module/data/Data.h
        bdlbsc/module/data/DataDb.cpp
        bdlbsc/module/data/DataDb.h
        bdlbsc/module/common/Common.cpp
        bdlbsc/module/common/Common.h
        bdlbsc/module/common/Modules.h

        bdlbsc/module/supper/ISystemUtils.h)

add_library(${PROJECT_NAME}
        ${SRC}
        )

target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Core Qt5:sql)