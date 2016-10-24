/**
 * @file main.cpp
 * @author Nouaim Souiki
 * Last modification : 2014, November 13th, by : Nouaim Souiki
 */

#include <iostream>
#include <exception>
#include <QtWidgets/QApplication>
#include "engine/Kernel.h"
#include "engine/gamestates/GameState.h"
#include "gameplay/IntroGameState.h"

int
main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    int exitCode = EXIT_FAILURE;
    Kernel * ker = nullptr;
    IntroGameState * introState = nullptr;

    try {
        ker = Kernel::getInstance();
        introState = IntroGameState::getInstance();
        ker->changeState(introState);
        exitCode = ker->run();
    } catch (const std::exception& e) {
        std::cout << "**main** : exception catched: " << e.what() << std::endl;
    }

    return exitCode;
}
