#include <iostream>
#define Null 0
#ifndef BARRAY_H
#define BARRAY_H


using namespace std;


template <typename E>

/**
 * @brief Clase BArray, esta clase da soporte al arbol b volviendolo menos complejo, mas
 * facil de leer y sin asignarle al arbol b tareas como agregar los datos en orden en el
 * array.
 */
class BArray
{
    int _maximunLenght,_currentLenght;
    E *_array;

public:

    /**
     * @brief BArray, Es el constructor de la clase, inicializa el largo de la lista. La lista
     * se inicializa
     * @param maxlenght
     */
    BArray(int maxlenght);
    BArray(const BArray&);

    /**
     * @brief getCurrentLenght
     * @return
     */
    int getCurrentLenght() const;

    /**
     * @brief getMaximunLenght
     * @return
     */
    int getMaximunLenght() const;

    /**
     * @brief isFull
     * @return
     */
    bool isFull() const;

    /**
     * @brief verificar si la lista esta llena si no lo esta, si esta llena retornar false,
     * agrega en orden el valor deseado y luego realizar el corrimiento de datos de izquierda a derecha
     * aumenta el largo en uno si se inserta el dato retornar true
     * @param pValue es el valor a insertar
     * @return true si el dato se inserta, false si la lista esta llena por consiguiente no se inserta
     * el dato
     */
    bool add(E pValue);

    /**
     * @brief addi agregar al inicio
     * @param pValue
     */
    bool addi(E pValue);

    /**
     * @brief addf agrega al final
     * @param pValue
     */
    bool addf(E pValue);


    /**
     * @brief add
     * @param pIndex
     * @param pValue
     * @return
     */
    bool add(int pIndex, E pValue);


    /**
     * @brief remove
     * @param pIndex
     * @return true si el indice era correcto
     */
    bool remove(int pIndex);

    /**
     * @brief getValue
     * @param pIndex
     * @return
     */
    E getValue(int pIndex);

    E &getValueReference(int pIndex);

    bool setValue(E pData,int pIndex);


    void reset();

    void print();

    /**
     * @brief ~BArray
     */
    ~BArray();
};

template <typename E>
BArray<E>::BArray(int maxlenght):_maximunLenght(maxlenght),_currentLenght(0)
{
    _array = new E[maxlenght];
}


template <typename E>
BArray<E>::BArray(const BArray &bArray):
    _maximunLenght(bArray._maximunLenght),_currentLenght(bArray._currentLenght)
{
    _array = new E[_maximunLenght];
    for (int x = 0; x < _currentLenght;x++)_array[x] = bArray.getValue(x);
    cout << "copy called!" << endl;
}


template <typename E>
int BArray<E>::getCurrentLenght() const{return _currentLenght;}

template <typename E>int BArray<E>::getMaximunLenght() const{return _maximunLenght;}

template <typename E>bool BArray<E>::isFull() const{return _maximunLenght == _currentLenght;}




template <typename E>bool BArray<E>::add(E pValue)
{
    if (isFull())return false;
    int x;
    for(x = 0; x < _currentLenght;x++)if (pValue < _array[x])break;
    _currentLenght++;
    E data = _array[x];
    E tmp = pValue;
    for(;x < _currentLenght;x++){
        data = _array[x];
        _array[x] = tmp;
        tmp = data;
    }
    return true;
}



template <typename E>bool BArray<E>::addi(E pValue)
{
    //realizar un corrimiento de datos
    //de derecha a izquierda de toda la lista y el valor inicia
    //es pValue
    //aumentar _currentLenght en uno si se inserto el dato
    if (isFull())return false;
    int x = 0;
    _currentLenght++;
    E data = _array[x];
    E tmp = pValue;
    for(;x < _currentLenght;x++){
        data = _array[x];
        _array[x] = tmp;
        tmp = data;
    }
    return true;
}

template <typename E>bool BArray<E>::addf(E pValue)
{
    //insertar en el dato al final del arreglo
    //aumentar _currentLenght en uno si se inserto el dato
    if (isFull())return false;
    _array[_currentLenght] = pValue;
    _currentLenght++;
    return true;
}

template <typename E>bool BArray<E>::add(int pIndex, E pValue)
{
    if (_currentLenght <= _maximunLenght-1){
        if (pIndex < 0 || pIndex > _currentLenght)return false;
        _currentLenght++;
        int x = pIndex;
        E data = _array[x];
        E tmp = pValue;
        for(;x < _currentLenght;x++){
            data = _array[x];
            _array[x] = tmp;
            tmp = data;
        }
        return true;
    }
    return false;
}

template <typename E> E BArray<E>::getValue(int pIndex)
{
    // busca el valor en el indice indicado en el caso de que el indice sea incorrecto
    //arroja un error
    //if (pIndex < 0 || pIndex >= this->_currentLenght)throw this;
    return this->_array[pIndex];
}

template <typename E> E& BArray<E>::getValueReference(int pIndex)
{
    // busca el valor en el indice indicado en el caso de que el indice sea incorrecto
    //arroja un error
    if (pIndex < 0 || pIndex >= _currentLenght)throw this;
    return _array[pIndex];
}

template <typename E> bool BArray<E>::setValue(E pData,int pIndex)
{
    //setea el valor nuevo en el indice indicado retorna true si el indice es correcto
    //false si el indice es incorrecto
    if (0> pIndex || pIndex >= _currentLenght)return false;
    _array[pIndex] = pData;
    return true;

}

template <typename E> void BArray<E>::reset(){
    delete [] _array;
    _array = new E[_maximunLenght];
    _currentLenght = 0;
}

template <typename E>
BArray<E>::~BArray()
{
    // libera la memoria de si misma y del puntero que esta misma tiene
    delete [] _array;
}

template <typename E> bool BArray<E>::remove(int pIndex){
    // borra el dato en la posicion indicada y realiza el corrimiento de datos de
    // derecha a izquierda
    if (0> pIndex || pIndex >= _currentLenght)return false;
    int x = pIndex;
    _currentLenght--;
    for(;x < _currentLenght;x++){
        _array[x] = _array[x+1];
    }
    return true;
}


template <typename E> void BArray<E>::print(){
    cout << "maxlenght " << _maximunLenght << " largo:" << _currentLenght <<"[";
    int x;
    for (x=0;x < _currentLenght; x++)cout << _array[x] << ",";
    for (;x < _maximunLenght-1; x++)cout << "0,";
    cout << "0]" << endl;
}

#endif // BARRAY_H
