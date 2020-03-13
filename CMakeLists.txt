cmake_minimum_required(VERSION 3.5)

set(IDENTIFIER "bdlbsc")
set(COPYRIGHT "Copyright © 2019-2020 bdlbsc")

project(modules VERSION 1.0.0 LANGUAGES CXX)

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


if (WIN32)
    add_definitions ( -D_UNICODE )
    remove_definitions ( -D_MBCS )
endif (WIN32)

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


        bdlbsc/module/networkserver/DownloadClient.cpp
        bdlbsc/module/networkserver/DownloadClient.h
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

        )


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

if (APPLE)
    # mac 通知使用的库
    target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::MacExtras)
endif (APPLE)