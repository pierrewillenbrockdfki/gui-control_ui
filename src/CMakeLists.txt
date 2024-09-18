rock_find_qt4(OPTIONAL)
rock_find_qt5(OPTIONAL Widgets)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

pkg_check_modules(SDFORMAT QUIET sdformat)
pkg_check_modules(SDFORMAT9 QUIET sdformat9)
pkg_check_modules(SDFORMAT12 QUIET sdformat12)

if(${SDFORMAT_FOUND})
  set(SDFORMAT_PKGCONFIG_NAME "sdformat")
elseif(${SDFORMAT9_FOUND})
  set(SDFORMAT_PKGCONFIG_NAME "sdformat9")
  set(CMAKE_CXX_STANDARD 17)
  set(CMAKE_CXX_STANDARD_REQUIRED ON)
elseif(${SDFORMAT12_FOUND})
  set(SDFORMAT_PKGCONFIG_NAME "sdformat12")
  set(CMAKE_CXX_STANDARD 17)
  set(CMAKE_CXX_STANDARD_REQUIRED ON)
else()
  message(SEND_ERROR "Could not find sdformat, sdformat9 or sdformat12 with pkg-config")
endif()

SET(MOC_HDRS
    ControlUi.h
    ControlUiPlugin.h
    jointform.h
)

SET(HDRS
    ControlUi.h
    jointform.h
)

FILE(GLOB SRCS
    *.cc
    *.cpp
)

SET(QtApp_RCCS resources.qrc)

if(ROCK_QT_VERSION_4)
    QT4_ADD_RESOURCES(Qt4App_RCC_SRCS ${QtApp_RCCS})

    rock_vizkit_widget(control_ui
        SOURCES ${SRCS} ${Qt4App_RCC_SRCS}
        HEADERS ${HDRS}
        MOC ${MOC_HDRS}
        UI jointform.ui
        DEPS_PKGCONFIG base-types base-lib urdfdom yaml-cpp base-logging ${SDFORMAT_PKGCONFIG_NAME}
        LIBS Qt4::QtGui
    )
endif(ROCK_QT_VERSION_4)

if(ROCK_QT_VERSION_5)
    QT5_ADD_RESOURCES(Qt5App_RCC_SRCS ${QtApp_RCCS})

    rock_vizkit_widget(control_ui-qt5
        SOURCES ${SRCS} ${Qt5App_RCC_SRCS}
        HEADERS ${HDRS}
        MOC5 ${MOC_HDRS}
        UI5 jointform.ui
        DEPS_PKGCONFIG base-types base-lib urdfdom yaml-cpp base-logging ${SDFORMAT_PKGCONFIG_NAME}
        LIBS Qt5::Widgets
    )
endif(ROCK_QT_VERSION_5)
