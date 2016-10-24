/**
 * @file Observer.h
 * @author Nouaim Souiki
 * @date 2014, November 08th
 * Last modification : 2014, November 11th, by : Nouaim Souiki
 */

#ifndef OBSERVER_H
#define OBSERVER_H

#include <string>

/**
 * @author Nouaim Souiki
 * @brief The Observer class implements an abstract observer (from Observer
 * pattern), which update itself every time that the Subject's instance
 * notify it.
 */
class Observer
{
public:
    /**
     * @brief Observer
     */
    Observer();
    /**
     * @brief ~Destructor
     */
    virtual ~Observer();
    /**
     * @brief Update the observer's datas and behavior, when the Subject
     * instance notify.
     */
    virtual void update() = 0;
};

inline
Observer :: Observer()
{
}

inline
Observer :: ~Observer()
{
}

#endif // OBSERVER_H
