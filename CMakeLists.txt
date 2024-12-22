cmake_minimum_required(VERSION 3.10)
project(DeribitTradingSystem)

set(CMAKE_CXX_STANDARD 17)

# Include directories
include_directories(include)
include_directories(lib/libcurl/include)
include_directories(lib/jsoncpp/include)
include_directories(lib/websocketpp/include)

# Find OpenSSL, Zlib, and libpsl
find_package(OpenSSL REQUIRED)
find_package(ZLIB REQUIRED)

# Specify the path to libpsl if it's not in the default location
find_library(LIBPSL psl REQUIRED)

# Source files
set(SOURCES
    src/main.cpp
    src/DeribitClient.cpp
    src/WebSocketServer.cpp
    src/DeribitWebSocketClient.cpp
)

# Link directories
link_directories(lib/libcurl/lib)
link_directories(lib/jsoncpp/lib)

# Libraries to link
set(LIBRARIES
    libcurl.a
    libjsoncpp.a
    OpenSSL::Crypto
    OpenSSL::SSL
    ZLIB::ZLIB
    ${LIBPSL}
)

# Target executable
add_executable(DeribitTradingSystem ${SOURCES})
target_link_libraries(DeribitTradingSystem ${LIBRARIES})
