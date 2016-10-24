/**
 * @file Engine.h
 * @author Nouaim Souiki
 * @date 2014, November 08th
 * Last modification : 2014, November 16th, by : Nouaim Souiki
 */
#ifndef ENGINE_H
#define ENGINE_H

#include "../patterns/Observer.h"

class Kernel;

/**
 * @author Nouaim Souiki
 * @brief The Engine class is a `runnable' engine interface.
 * Provider of two pure virtual methods, to reimplement by reimplement by
 * concretes game engines.
 */
class Engine : public Observer
{
public:
    /**
     * @brief Destructor.
     */
    virtual ~Engine();
    /**
     * @brief run Run the engine.
     */
    virtual void run() = 0;
    /**
     * @brief update Update the engine.
     */
    virtual void update() = 0;
    /**
     * @brief Clear this engine by releasing all allocated datas.
     */
    virtual void clear() = 0;
protected:
    /**
     * @brief Constructor.
     */
    Engine();
};

inline Engine :: Engine()
{
}

inline Engine :: ~Engine()
{
}

#endif // ENGINE_H
