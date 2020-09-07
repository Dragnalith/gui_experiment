set(SOURCES
    main.cpp
)

qt5_add_resources(SOURCES qml.qrc)
add_executable(QtQuickApp ${SOURCES})

target_link_libraries(QtQuickApp 
    Qt5::Qml
    Qt5::Quick
)

deploy_qt5_runtime_dependency(QtQuickApp)

# copy_qt5_runtime_files(QtQuickApp ""
#     "bin/Qt5Core"
#     "bin/Qt5Gui"
#     "bin/Qt5Network"
#     "bin/Qt5Qml"
#     "bin/Qt5Quick"
#     "bin/Qt5QuickControls2"
#     "bin/Qt5QuickTemplates2"
#     "bin/Qt5QuickShapes"
#     "bin/Qt5QuickParticles"
#     "bin/Qt5QuickWidgets"
# )

# copy_qt5_runtime_files(QtQuickApp "platforms" 
#     "plugins/platforms/qwindows"
# )

#copy_qt5_qml_folders(QtQuickApp ""
#    "Qt"
#    "QtQml"
#    "QtQuick"
#    "QtQuick.2"
#)