cmake_minimum_required (VERSION 3.8)

if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("GroundControlStation")

find_package(Qt6 CONFIG COMPONENTS 
    Core
    Gui
    Widgets
    Multimedia
    Location
    Concurrent
    Positioning
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

qt_add_resources(GENERATED_QRC ${QRC_FILE})

add_executable(GroundControlStation ${SOURCES} ${HEADERS} ${GENERATED_QRC})

set_target_properties(${PROJECT_NAME} PROPERTIES
    AUTOMOC ON
    AUTOUIC ON
    AUTORCC ON
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
    Qt6::Multimedia
    Qt6::Location
    Qt6::Concurrent
    Qt6::Positioning
    Qt6::Quick
    Qt6::Qml
    Qt6::QuickWidgets
    Qt6::Network
    Qt6::Multimedia
    Qt6::MultimediaWidgets
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET GroundControlStation PROPERTY CXX_STANDARD 20)
endif()