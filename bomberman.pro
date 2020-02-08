######################################################################
# Automatically generated by qmake (3.1) Sat Feb 8 01:50:01 2020
######################################################################

TEMPLATE = app
TARGET = bomberman
INCLUDEPATH += .

# You can make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# Please consult the documentation of the deprecated API in order to know
# how to port your code away from it.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Input
HEADERS += basics/bloc.hpp \
           basics/bomb.hpp \
           basics/display.hpp \
           basics/game.hpp \
           basics/item.hpp \
           basics/map.hpp \
           basics/player.hpp \
           fck/bloc.hpp \
           fck/bomb.hpp \
           fck/map.hpp \
           fck/player.hpp \
           affichage/Headers/Bloc.hpp \
           affichage/Headers/Bomb.hpp \
           affichage/Headers/Button.hpp \
           affichage/Headers/Game.hpp \
           affichage/Headers/Map.hpp \
           affichage/Headers/Player.hpp
SOURCES += qrc_res.cpp \
           affichage/qrc_res.cpp \
           basics/bloc.cpp \
           basics/bomb.cpp \
           basics/display.cpp \
           basics/game.cpp \
           basics/item.cpp \
           basics/main.cpp \
           basics/map.cpp \
           basics/player.cpp \
           basics/test.cpp \
           fck/bloc.cpp \
           fck/bomb.cpp \
           fck/main.cpp \
           fck/map.cpp \
           fck/player.cpp \
           affichage/Sources/Bloc.cpp \
           affichage/Sources/Bomb.cpp \
           affichage/Sources/Button.cpp \
           affichage/Sources/Game.cpp \
           affichage/Sources/main.cpp \
           affichage/Sources/Map.cpp \
           affichage/Sources/Player.cpp
RESOURCES += affichage/res.qrc