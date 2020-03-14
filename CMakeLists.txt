cmake_minimum_required(VERSION 3.5)

set(IDENTIFIER "bdlbsc")
set(COPYRIGHT "Copyright © 2019-2020 bdlbsc")

project(modules VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (UNIX AND NOT APPLE)
    set(LINUX 1)
endif (UNIX AND NOT APPLE)

if (UNIX)
    include_directories(/usr/local/dev/vcpkg/installed/x64-osx/include)
    link_directories(/usr/local/dev/vcpkg/installed/x64-osx/share/lib)

    include_directories(/usr/local/include)
    link_directories(/usr/local/lib)
endif (UNIX)

if (WIN32)

    include_directories(D:/Local/vcpkg/installed/x64-windows/include)
    link_directories(D:/Local/vcpkg/installed/x64-windows/lib)

    include_directories("D:/Local/libs/include")
    link_directories("D:/Local/libs/lib")

endif (WIN32)


if (UNIX)
    SET(CMAKE_INSTALL_PREFIX /usr/local)
endif (UNIX)

if (WIN32)
    SET(CMAKE_INSTALL_PREFIX D:/Local/libs)
endif (WIN32)

if (UNIX)
    SET(LIBRARY_OUTPUT_PATH /usr/local/lib)
endif (UNIX)

if (WIN32)
    SET(LIBRARY_OUTPUT_PATH D:/Local/libs/lib)
endif ()


find_package(Qt5
        COMPONENTS
        Core
        Quick
        qml
        sql
        Network
        Widgets
        WebEngine
        WebChannel
        Multimedia
        LinguistTools
        QuickControls2
        WebSockets
        REQUIRED)


find_package(rxcpp CONFIG REQUIRED)

if (UNIX)
    find_package(Qt5MacExtras REQUIRED)
    find_package(Qt5DBus REQUIRED)
endif (UNIX)

set(SRC

        bdlbsc/module/common/Common.cpp
        bdlbsc/module/common/Common.h
        bdlbsc/module/common/Modules.h

        bdlbsc/module/component/DynamicLoadComponent.cpp
        bdlbsc/module/component/DynamicLoadComponent.h


        bdlbsc/module/data/Data.cpp
        bdlbsc/module/data/Data.h
        bdlbsc/module/data/DataDb.cpp
        bdlbsc/module/data/DataDb.h


        bdlbsc/module/downloadfile/DowmloadFileTaskModel.cpp
        bdlbsc/module/downloadfile/DowmloadFileTaskModel.h
        bdlbsc/module/downloadfile/DownloadClient.cpp
        bdlbsc/module/downloadfile/DownloadClient.h
        bdlbsc/module/downloadfile/DownloadFileManagerModel.cpp
        bdlbsc/module/downloadfile/DownloadFileManagerModel.h
        bdlbsc/module/downloadfile/DownloadProxy.cpp
        bdlbsc/module/downloadfile/DownloadProxy.h
        bdlbsc/module/downloadfile/DOWNLOAD_CONSTANT.h


        bdlbsc/module/image/ImageAsyncImageProvider.h
        bdlbsc/module/image/ImageProvider.cpp
        bdlbsc/module/image/ImageProvider.h
        bdlbsc/module/image/QrCodeImageProvider.h


        bdlbsc/module/logger/Logger.cpp
        bdlbsc/module/logger/Logger.h
        bdlbsc/module/logger/LoggerTemplate.h


        bdlbsc/module/networkserver/HttpClient.cpp
        bdlbsc/module/networkserver/HttpClient.h
        bdlbsc/module/networkserver/HttpRequest.cpp
        bdlbsc/module/networkserver/HttpRequest.h
        bdlbsc/module/networkserver/HttpResponse.cpp
        bdlbsc/module/networkserver/HttpResponse.h
        bdlbsc/module/networkserver/NetworkDownloadFile.cpp
        bdlbsc/module/networkserver/NetworkDownloadFile.h
        bdlbsc/module/networkserver/UdpClient.cpp
        bdlbsc/module/networkserver/UdpClient.h
        bdlbsc/module/networkserver/UdpServer.cpp
        bdlbsc/module/networkserver/UdpServer.h


        bdlbsc/module/plugin/Plugin.cpp
        bdlbsc/module/plugin/Plugin.h
        bdlbsc/module/plugin/AppPluginManager.cpp
        bdlbsc/module/plugin/AppPluginManager.h


        bdlbsc/module/qrcode/QRCodeGenerator.cpp
        bdlbsc/module/qrcode/QRCodeGenerator.h


        bdlbsc/module/supper/IData.h
        bdlbsc/module/supper/IMD5Utils.h
        bdlbsc/module/supper/IModule.h
        bdlbsc/module/supper/IStringUtils.h
        bdlbsc/module/supper/IThreadUtils.h
        bdlbsc/module/supper/IUtils.h
        bdlbsc/module/supper/IUUIDUtils.h
        bdlbsc/module/supper/ISystemUtils.h


        bdlbsc/module/systemfeatures/Clipboard.cpp
        bdlbsc/module/systemfeatures/Clipboard.h
        bdlbsc/module/systemfeatures/ImageClipboard.cpp
        bdlbsc/module/systemfeatures/ImageClipboard.h

        bdlbsc/module/utils/SystemUtils.cpp bdlbsc/module/utils/SystemUtils.h bdlbsc/module/utils/Utils.cpp bdlbsc/module/utils/Utils.h bdlbsc/module/utils/MD5Utils.cpp bdlbsc/module/utils/MD5Utils.h bdlbsc/module/utils/StringUtils.cpp bdlbsc/module/utils/StringUtils.h bdlbsc/module/utils/ThreadUtils.cpp bdlbsc/module/utils/ThreadUtils.h bdlbsc/module/utils/UUIDUtils.cpp bdlbsc/module/utils/UUIDUtils.h bdlbsc/module/common/Modules.cpp)


set(SRC_APPLE


        )


add_library(${PROJECT_NAME}
        ${SRC}
        )

target_compile_definitions(${PROJECT_NAME}
        PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(
        ${PROJECT_NAME}
        PRIVATE
        Qt5::Core
        Qt5::Quick
        Qt5::Sql
        Qt5::Network
        Qt5::Widgets
        Qt5::WebEngine
        Qt5::WebChannel
        Qt5::Multimedia
        Qt5::WebSockets
)

target_link_libraries(${PROJECT_NAME} PRIVATE rxcpp)

if (APPLE)
    # mac 通知使用的库
    target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::MacExtras)
endif (APPLE)


# 如果没有指定安装路径，就安装到当前目录
if (NOT CMAKE_INSTALL_BINDIR)
    set(CMAKE_INSTALL_BINDIR ".")
endif ()


install(TARGETS ${PROJECT_NAME}
        EXPORT ${PROJECT_NAME}
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION bin
        ARCHIVE DESTINATION lib)

install(DIRECTORY bdlbsc DESTINATION include FILES_MATCHING PATTERN "*.h")

configure_file(cmake/Config.cmake.in ${PROJECT_NAME}Config.cmake @ONLY)

if (WIN32)

    install(FILES ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake
            DESTINATION D:/Local/libs/lib/cmake/bdlbsc/module/supper)

    install(EXPORT ${PROJECT_NAME}
            NAMESPACE bdlbsc
            DESTINATION D:/Local/libs/lib/cmake/bdlbsc/module/supper)

endif (WIN32)

if (UNIX)
    install(FILES ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake
            DESTINATION /usr/local/lib/cmake/bdlbsc/module/supper)

    install(EXPORT ${PROJECT_NAME}
            NAMESPACE bdlbsc
            DESTINATION /usr/local/lib/cmake/bdlbsc/module/supper)
endif (UNIX)

