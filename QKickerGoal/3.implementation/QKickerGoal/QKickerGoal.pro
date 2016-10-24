CONFIG += c++11

TARGET    = QKickerGoal
TEMPLATES = app

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
qtHaveModule(opengl): QT += opengl

SOURCES += \
    src/main.cpp \
    src/engine/Kernel.cpp \
    src/engine/graphicsengine/GraphicsEngine.cpp \
    src/engine/graphicsengine/GraphicsEntity.cpp \
    src/engine/graphicsengine/GraphicsScene.cpp \
    src/gameplay/Field.cpp \
    src/gameplay/Ball.cpp \
    src/gameplay/Avatar.cpp \
    src/gameplay/Team.cpp \
    src/gameplay/PlayingGameState.cpp \
    src/gameplay/IntroGameState.cpp \
    src/gameplay/Footballer.cpp \
    src/gameplay/GoalKeeper.cpp \
    src/engine/MovableEntity.cpp \
    src/gameplay/MenuGameState.cpp

HEADERS += \
    src/engine/Kernel.h \
    src/patterns/Singleton.h \
    src/patterns/Observer.h \
    src/patterns/Subject.h \
    src/engine/Engine.h \
    src/engine/gamestates/GameState.h \
    src/engine/graphicsengine/GraphicsEngine.h \
    src/engine/graphicsengine/GraphicsEntity.h \
    src/engine/graphicsengine/GraphicsScene.h \
    src/gameplay/Field.h \
    src/gameplay/MovableEntity.h \
    src/gameplay/Ball.h \
    src/gameplay/Avatar.h \
    src/gameplay/Team.h \
    src/gameplay/PlayingGameState.h \
    src/gameplay/IntroGameState.h \
    src/gameplay/Footballer.h \
    src/gameplay/GoalKeeper.h \
    src/engine/MovableEntity.h \
    src/gameplay/MenuGameState.h

RESOURCES += \
    resources.qrc
