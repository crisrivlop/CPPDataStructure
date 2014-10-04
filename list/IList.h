#ifndef ILIST_H
#define ILIST_H

template <class E>
/**
 * @brief
 *
 */
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
     * @brief
     *
     * @param E
     */
    /**
     * @brief
     *
     * @param E
     */
    virtual void addi(E) = 0;
    /**
     * @brief
     *
     * @param E
     */
    /**
     * @brief
     *
     * @param E
     */
    virtual void add(E) = 0;
    /**
     * @brief
     *
     * @param E
     * @param int
     * @return bool
     */
    /**
     * @brief
     *
     * @param E
     * @param int
     * @return bool
     */
    virtual bool add(E,int) = 0;
    /**
     * @brief
     *
     * @param int
     * @return bool
     */
    /**
     * @brief
     *
     * @param int
     * @return bool
     */
    virtual bool remove(int) = 0;
    /**
     * @brief
     *
     * @param int
     * @param E
     */
    /**
     * @brief
     *
     * @param int
     * @param E
     */
    virtual void set(int,E) = 0;
    /**
     * @brief
     *
     * @param int
     * @return E
     */
    /**
     * @brief
     *
     * @param int
     * @return E
     */
    virtual E get(int) = 0;
    /**
     * @brief
     *
     * @return int
     */
    /**
     * @brief
     *
     * @return int
     */
    int getLenght() const;
    //virtual Iterator getIterator() = 0;
    //virtual setComparator(IComparator) = 0;
    //virtual IComparator getComparator() = 0;
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
    bool isEmpty() const;
    /**
     * @brief
     *
     */
    /**
     * @brief
     *
     */
    virtual void print() const = 0;
};

/**
 * @brief
 *
 * @return int IList<E>
 */
/**
 * @brief
 *
 * @return int IList<E>
 */
template <class E> int IList<E>:: getLenght() const{return lenght;}
/**
 * @brief
 *
 * @return bool IList<E>
 */
/**
 * @brief
 *
 * @return bool IList<E>
 */
template <class E> bool IList<E>:: isEmpty() const {return lenght == 0;}
#endif // ILIST_H
