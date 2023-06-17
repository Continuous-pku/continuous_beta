QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QT       +=core gui multimedia multimediawidgets

CONFIG += c++17


RC_ICONS = icon.ico

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    b_upgrade.cpp \
    build_info.cpp \
    buildings.cpp \
    class.cpp \
    event_.cpp \
    main.cpp \
    mainw.cpp \
    menu.cpp \
    note.cpp \
    pchoice.cpp \
    policy.cpp \
    video.cpp \
    widget.cpp

HEADERS += \
    b_upgrade.h \
    build_info.h \
    buildings.h \
    class.h \
    event_.h \
    mainw.h \
    menu.h \
    note.h \
    pchoice.h \
    policy.h \
    video.h \
    widget.h

FORMS += \
    b_upgrade.ui \
    build_info.ui \
    buildings.ui \
    event_.ui \
    mainw.ui \
    menu.ui \
    note.ui \
    pchoice.ui \
    policy.ui \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    pictures.qrc
