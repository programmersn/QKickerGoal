/**
 * @file Kernel.cpp
 * @author Nouaim Souiki
 * Last modification : 2014, November 16th, by : Nouaim Souiki
 */

#include <typeinfo>
#include <QtWidgets/QApplication>
#include <QTimer>
#include "Kernel.h"
#include "gamestates/GameState.h"

Kernel *
Kernel :: instance = nullptr;

Kernel :: Kernel()
    : //Singleton<Kernel>(),
      m_states()
{
    std::cout << "**Core-Kernel** : starting system ..." << std::endl;
    //<! @todo : add `cout << "activation of engines ..."'
    this->add(GraphicsEngine::getInstance());
    std::cout << "--Kernel::Kernel() done.--" << std::endl;
}

Kernel :: ~Kernel()
{
    std::cout << "**Core-Kernel** : releasing datas for shutdown ... "
              << std::endl;

    std::cout << "**Kernel** : shutodown ...";
    this->clear();
    if (Kernel::instance != nullptr) {
        std::cout << "clear() : Destroying unique instance ge ...";
        delete Kernel::instance;
        Kernel::instance = nullptr;
        std::cout << " Done" << std::endl;
    }
    else std::cout << "Cannot destroy unique instance : ge doesn't exist" << std::cout;
}

Kernel*
Kernel :: getInstance()
{
    if (Kernel::instance == nullptr)
        Kernel::instance = new Kernel();
    return Kernel::instance;
}

void
Kernel :: clear()
{
    while ( ! m_states.empty()) {
        this->popState();
    }
    for (std::list<Observer*>::iterator obs = m_observers.begin();
         obs != m_observers.end();
         obs++)
        m_observers.erase(obs);
}

void
Kernel :: add(Observer * obs)
{
    std::cout << "**Core-Kernel** : Adding new observer \""
              << typeid(*obs).name()
              << "\" ... ";

    m_observers.push_back(obs);

    std::cout << "Done" << std::endl;
    //std::cout << "--Kernel::add() done.--" << std::endl;
}

void
Kernel :: remove(std::string & id)
{
    bool found = false;

    std::cout << "**Core-Kernel** : Searching observer of id \" " << id
              << "\" for removing ... ";
    for (std::list<Observer*>::iterator obs = m_observers.begin();
         obs != m_observers.end();
         obs++) { printf("3\n");
        if (typeid(*obs).name() == id) { //<! @TODO Replace by ... contain(id)
            std::cout << "Found." << std::endl;
            std::cout << "\tRemoving observer \"" << typeid(*obs).name()
                      << "\" ...";
            m_observers.erase(obs);
            std::cout << "Done" << std::endl;
            found = true;
        }
    }

    if ( ! found) std::cout << "Doesn't exist." << std::endl;
}

void
Kernel :: notify()
{
    for (Observer * obs : m_observers) {
        std::cout << "**Core-Kernel** : Delivering notification to observer \""
                  << typeid(*obs).name() << "\" ... " << std::endl;
        obs->update();
        std::cout << "Done" << std::endl;
    }
    // std::cout << "--Kernel::notify() done.--" << std::endl;
}

int
Kernel :: run()
{
    //  std::cout << "--Entering Kernel::run() ...--" << std::endl;
    //this->notify();
    std::cout << "**Core-Kernel** : let's running engines ..." << std::endl;
    for (Observer * obs : m_observers)
        dynamic_cast<Engine*>(obs)->run();

    return this->handleEvents();
}

int
Kernel :: handleEvents()
{
    std::cout << "**Core-Kernel** : Entering in the main event loop ..."
              << std::endl;

    int exitCode = qApp->exec();

    std::cout << "**Core-Kernel** : Quiting the main event loop ..."
              << std::endl;
    return exitCode;
}

void
Kernel :: changeState(GameState * state)
{
    std::cout << "**Core-Kernel**: ";
   /*if (m_states.top() == nullptr)
        std::cout << "first state ";
    else */std::cout << "change current state \""
                   << typeid(m_states.top()).name() << "\" by state ";
    std::cout << "\"" << typeid(*state).name() << "\" ... ";


    this->popState();
    this->pushState(state);
    this->notify();

    //   std::cout << "--Kernel::changeState() done.--" << std::endl;
}

void
Kernel :: pushState(GameState * state)
{
    std::cout << "**Core-Kernel** : pushing new state ... "
              << typeid(*state).name() << "\"" << std::endl;
   //<! TODO m_currentGameState->pause();

    m_states.push(state);
   // m_currentGameState = state;
    this->notify();
}

void
Kernel :: popState()
{
    if (m_states.empty())
        return;


    std::cout << "**Core-Kernel** : poping current state ... "
              << typeid(*m_states.top()).name() << "\"" << std::endl;

    m_states.top()->clear();
    m_states.pop();
    //m_currentGameState = m_states.top();
    this->notify();

    //<! TODO : m_currentGameState->resume();
}

GameState*
Kernel :: getCurrentGameState() const
{
    return m_states.top();
            //m_currentGameState;
}

