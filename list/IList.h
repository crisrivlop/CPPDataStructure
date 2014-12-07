#include "IIterator.h"
#ifndef ILIST_H
#define ILIST_H

template <class E>
/**
 * @brief
 *
 */
class IList
{
protected:
    int lenght; /**< TODO */ /**< TODO */
public:

    /**
     * @brief addi
     *
     * @param E
     */
    virtual void addi(E) = 0;

    /**
     * @brief add
     *
     * @param E
     */
    virtual void add(E) = 0;

    /**
     * @brief add
     *
     * @param E
     * @param int
     * @return bool
     */
    virtual bool add(E,int) = 0;

    /**
     * @brief remove
     *
     * @param int
     * @return bool
     */
    virtual bool remove(int) = 0;

    /**
     * @brief set
     *
     * @param int
     * @param E
     */
    virtual void set(int,E) = 0;

    /**
     * @brief get
     * @param int
     * @return
     */
    virtual E get(int) = 0;

    /**
     * @brief getLenght
     * @return
     */
    int getLenght() const;
    /**
     * @brief getIterator
     * @return
     */
    virtual IIterator<E>* getIterator() = 0;

    /**
     * @brief
     *
     * @return bool
     */
    bool isEmpty() const;

    /**
     * @brief print
     */
    virtual void print() const = 0;
    /**
     * @brief ~IList
     */
    virtual ~IList(){}
};


template <class E> int IList<E>:: getLenght() const{return lenght;}

template <class E> bool IList<E>:: isEmpty() const {return lenght == 0;}
#endif // ILIST_H
