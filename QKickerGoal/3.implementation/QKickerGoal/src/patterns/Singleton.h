/**
 * @file Singleton.h
 * @author Nouaim Souiki
 * @date 2014, November 08th
 * Last modification :
 *   - 2014, November 24th, by : Nouaim Souiki : method kill() removed.
 */

#ifndef SINGLETON_H
#define SINGLETON_H

#include <iostream>
#include <typeinfo>

/**
 * @author Nouaim Souiki
 * @date 2014, November 08th
 * @brief Template class of the pattern design `Singleton'
 * @tparam Type of the object to be instancied as Singleton
 */
template <typename T>
class Singleton
{
protected :
    /**
     * @brief Pointer on the unique instance of the object singleton.
     */
    static T * m_instance;

public :
    /**
     *  @brief Destructor : kill the unique instance of this object.
     */
    virtual ~Singleton();
    /**
     *  @brief Make and return the unique instance of the object.
     *  If the object hasn't been created yet, then create it.
     *  @return Pointer to the unique instance.
     */
    static T * getInstance();
    /**
     * @brief Destroy the unique instance of the object singleton.
     */
    //static void kill();
protected :
    /**
     *  @brief Constructor (protected to ensure unicity of the object).
     */
    Singleton();
};

template <typename T>
Singleton<T> :: Singleton()
{
}

template <typename T>
Singleton<T> :: ~Singleton()
{

}

template <typename T>
inline T *
Singleton<T> :: getInstance()
{
    if (m_instance == nullptr) {
        std::cout << "Making unique instance of object \"" << typeid(T).name()
                  << "\" ... ";
        m_instance = new T();
        std::cout << " Done." << std::endl;
    }
    else std::cout << "\"" << typeid(T).name()
                   << "\"'s unique instance already exist" << std::endl;
    return m_instance;
}
/*
template <typename T>
inline void
Singleton<T> :: kill()
{
    if (m_instance != nullptr) {
        std::cout << "Destroying unique instance of \"" << typeid(T).name() <<
                     "\" ... ";
        delete m_instance;
        m_instance = nullptr;
        std::cout << " Done" << std::endl;
    }
    else std::cout << "Cannot destroy unique instance of \""
                   << typeid(T).name() << "\" : doesn't exist" << std::cout;
}
*/
template <typename T>
T*
Singleton<T> :: m_instance = nullptr;

#endif // SINGLETON_H
