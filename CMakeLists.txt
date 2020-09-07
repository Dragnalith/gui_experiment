cmake_minimum_required(VERSION 3.9.0)

project(GuiExperiment)

set(Qt5_DIR "E:/Qt/5.15.0/msvc2019_64/lib/cmake/Qt5")
set(Qt5_SDK "${Qt5_DIR}/../../..")

cmake_policy(SET CMP0079 NEW)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Gui Widgets Qml Quick REQUIRED)

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

function(copy_qt5_qml_folders target prefix)
    add_custom_command(
        TARGET ${target} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E make_directory $<TARGET_FILE_DIR:${target}>/${prefix}/
    )
    foreach(arg IN LISTS ARGN)
        add_custom_command(
            TARGET ${target} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${Qt5_DIR}/../../../qml/${arg}/"
            $<TARGET_FILE_DIR:${target}>/${prefix}/${arg}
        )
    endforeach()
endfunction()

function(deploy_qt5_runtime_dependency target)
    add_custom_command(
        TARGET ${target} POST_BUILD
        COMMAND "${Qt5_SDK}/bin/windeployqt.exe" $<TARGET_FILE:${target}> --pdb --qmldir ${CMAKE_CURRENT_SOURCE_DIR}
    )
endfunction()

add_subdirectory("source/QtQuickApp")
add_subdirectory("source/QtWidgetApp")

