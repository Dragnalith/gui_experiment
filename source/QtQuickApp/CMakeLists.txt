add_executable(QtQuickApp
    main.cpp
)

target_link_libraries(QtQuickApp 
    Qt5::Qml
    Qt5::Quick
)


add_custom_command(
    TARGET QtQuickApp POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:Qt5::Qml>
        $<TARGET_FILE_DIR:QtQuickApp>
)


add_custom_command(
    TARGET QtQuickApp POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:Qt5::Quick>
        $<TARGET_FILE_DIR:QtQuickApp>
)