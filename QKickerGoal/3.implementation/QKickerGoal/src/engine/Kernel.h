/**
 * @file Kernl.h
 * @author Nouaim Souiki
 * @date 2014, November 08th
 * Last modification : 2014, November 16th, by : Nouaim Souiki
 */

#ifndef KERNEL_H
#define KERNEL_H

#include <stack>
#include <QObject>
#include "../patterns/Singleton.h"
#include "../patterns/Subject.h"
#include "graphicsengine/GraphicsEngine.h"

class QApplication;
class GameState;

/**
 * @author Nouaim Souiki
 * @modif 2014 November, 11
 *
 * @brief The Kernel class.
 * Core-kernel of the system.
 * Provides methods of managing game states, handling events and user's inputs,
 * and synchronisation between game engines.
 */
class Kernel final:
    //    public Singleton<Kernel>,
        public Subject
{
  //  friend class Singleton<Kernel>;
    // TODO : add Engine and GameState as friend classes, and change all
    // managing game states methods on private

private:
    static Kernel * instance;
    /**
     * @brief Pointer on the stack which provide pointers to the activated
     * states of the game.
     */
    std::stack<GameState*> m_states;

public:
    static Kernel * getInstance();
    /**
     * @brief Destructor.
     */
    virtual ~Kernel();
    /**
     * @brief Run the kernel.
     * @return Value returned by Kernel::handleEvents().
     */
    int run();

    void clear();
    /**
     *
     * @see Reimplement Subject::notify().
     */
    virtual void notify() override;
    /**
     * @brief Handle the input envents of the game.
     * @return Exit code of the application's main event loop.
     */
    int handleEvents();
    /**
     * @brief Replace current state by new state `state'.
     * @param The new state.
     */
    void changeState(GameState * state);
    /**
     * @brief Push the state `state' (without killing current state)
     * on the states stack `m_states'.
     * @param The state to push.
     */
    void pushState(GameState * state);
    /**
     * @brief Pop the current state (actually the head of the states
     * stack).
     */
    void popState();
    /**
     * @brief Get pointer on the current game state.
     * @return Pointer to get.
     */
    GameState * getCurrentGameState() const; // Modificate to private, such that
    // only friends classes can call it and get m_currentGameState
private:
    /**
     * @brief Constructor.
     */
    Kernel();
    /**
     * @see Reimplement Subject::add().
     */
    virtual void add(Observer *obs) override;
    /**
     * @see Reimplement Subject::remove().
     */
    virtual void remove(std::string &id) override;
};

#endif // KERNEL_H
