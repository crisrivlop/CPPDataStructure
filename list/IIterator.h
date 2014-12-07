#include "Node.h"
#ifndef IITERATOR_H
#define IITERATOR_H
template <class E>

/**
 * @brief
 *
 */
class IIterator{
public:

    /**
     * @brief
     *
     * @return E
     */
    virtual E getNext()=0;

    /**
     * @brief
     *
     * @return E
     */
    virtual E getCurrent() const =0;

    /**
     * @brief
     *
     * @return bool
     */
    virtual bool hasNext() const =0;

    virtual ~IIterator(){}

};
#endif // IITERATOR_H
