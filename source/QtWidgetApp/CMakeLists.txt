add_executable(QtWidgetApp
    main.cpp
)

target_link_libraries(QtWidgetApp 
    Qt5::Widgets
)

copy_qt5_runtime_files(QtWidgetApp ""
    "bin/Qt5Core"
    "bin/Qt5Gui"
    "bin/Qt5Widgets"
)

copy_qt5_runtime_files(QtWidgetApp "platforms" 
    "plugins/platforms/qwindows"
)
