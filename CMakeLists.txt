cmake_minimum_required (VERSION 3.8)

if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("GroundControlStation")

find_package(Qt5 CONFIG COMPONENTS 
    Core
    Widgets
    Multimedia
    Location
    Concurrent
    #WebEngine
    #WebEngineWidgets
    #Positioning
    QuickWidgets
    Quick 
    Qml 
    Network
    Multimedia 
    MultimediaWidgets
    REQUIRED
)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/**/*.cpp"
)

file(GLOB_RECURSE HEADERS CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/**/*.h"
)

set(QRC_FILE resources/resources.qrc)

qt5_add_resources(GENERATED_QRC ${QRC_FILE})

add_executable(GroundControlStation ${SOURCES} ${HEADERS} ${GENERATED_QRC})

set_target_properties(${PROJECT_NAME} PROPERTIES
    AUTOMOC ON
    AUTOUIC ON
    AUTORCC ON
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt5::Core
    Qt5::Widgets
    Qt5::Multimedia
    Qt5::Location
    Qt5::Concurrent
    #Qt5::WebEngine
    #Qt5::WebEngineWidgets
    #Qt5::Positioning
    Qt5::Quick
    Qt5::Qml
    Qt5::QuickWidgets
    Qt5::Network
    Qt5::Multimedia
    Qt5::MultimediaWidgets
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET GroundControlStation PROPERTY CXX_STANDARD 20)
endif()
