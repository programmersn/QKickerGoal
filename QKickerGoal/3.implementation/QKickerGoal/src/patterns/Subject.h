/**
 * @file Subject.cpp
 * @author Nouaim Souiki
 * @date 2014, November 08th
 * Last modification : 2014, November 11th, by : Nouaim Souiki
 */

#ifndef SUBJECT_H
#define SUBJECT_H

#include <map>
#include <list>
#include "Observer.h"

/**
 * @author Nouaim Souiki
 * @brief The Subject class is an abstraction of a Subject instance (from
 * the Observer pattern) which notify a change of state to all its observers.
 */
class Subject
{
protected:
   /**
    * @brief List of observers of the current instance of Subject.
    */
   std::list<Observer*> m_observers;

public:
    /**
     * @brief Constructor
     */
    Subject();
    /**
     * @brief Destructor
     */
    virtual ~Subject();
    /**
     * @brief Add the observer pointed by obs into the observer's list.
     * @param obs The observer to add
     */
    virtual void add (Observer * obs) = 0;
    /**
     * @brief Remove the observer of identifier id from the list of
     * observers
     * @param The identifier of the observer to remove
     */
    virtual void remove (std::string & id) = 0;
    /**
     * @brief Notify to all observers a changement of occuried in the system.
     */
    virtual void notify () = 0;
};

inline
Subject :: Subject()
{
}

inline
Subject :: ~Subject()
{
}



#endif // SUBJECT_H
