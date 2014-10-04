#include "Node.h"
#ifndef IITERATOR_H
#define IITERATOR_H
template <class E>
/**
 * @brief
 *
 */
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
    /**
     * @brief
     *
     * @return E
     */
    virtual E getNext() =0;
    /**
     * @brief
     *
     * @return E
     */
    /**
     * @brief
     *
     * @return E
     */
    virtual E getCurrent()=0;
    /**
     * @brief
     *
     * @return bool
     */
    /**
     * @brief
     *
     * @return bool
     */
    virtual bool hasNext()=0;
};
#endif // IITERATOR_H
