cmake_minimum_required(VERSION 3.9.0)

project(GuiExperiment)

set(Qt5_DIR "E:/Qt/5.15.0/msvc2019_64/lib/cmake/Qt5")
cmake_policy(SET CMP0079 NEW)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY, "${CMAKE_BINARY_DIR}/bin")
#set(CMAKE_RUNTIME_LIBRARY_DIRECTORY,"${CMAKE_BINARY_DIR}/lib")
#set(CMAKE_RUNTIME_ARCHIVE_DIRECTORY,"${CMAKE_BINARY_DIR}/lib")

find_package(Qt5 COMPONENTS Widgets Qml Quick REQUIRED)

function(copy_qt5_runtime_files target prefix)
    add_custom_command(
        TARGET ${target} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E make_directory $<TARGET_FILE_DIR:${target}>/${prefix}/
    )
    foreach(arg IN LISTS ARGN)
        add_custom_command(
            TARGET ${target} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${Qt5_DIR}/../../../${arg}$<$<CONFIG:Debug>:d>.dll"
            $<TARGET_FILE_DIR:${target}>/${prefix}/
        )
        add_custom_command(
            TARGET ${target} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${Qt5_DIR}/../../../${arg}$<$<CONFIG:Debug>:d>.pdb"
            $<TARGET_FILE_DIR:${target}>/${prefix}/
        )
    endforeach()
endfunction()

add_subdirectory("source/QtQuickApp")
add_subdirectory("source/QtWidgetApp")

