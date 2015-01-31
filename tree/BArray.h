#include <iostream>
#define Null 0
#ifndef BARRAY_H
#define BARRAY_H


using namespace std;


template <class E>

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

    bool setValue(E data);

    void print();

    /**
     * @brief ~BArray
     */
    ~BArray();
};

template <class E>
BArray<E>::BArray(int maxlenght):_maximunLenght(maxlenght),_currentLenght(0)
{
    _array = new E[maxlenght];
}

template <class E>
int BArray<E>::getCurrentLenght() const{return _currentLenght;}

template <class E>int BArray<E>::getMaximunLenght() const{return _maximunLenght;}

template <class E>bool BArray<E>::isFull() const{return _maximunLenght == _currentLenght;}




template <class E>bool BArray<E>::add(E pValue)
{
    if (isFull())return false;
    int x;
    for(x = 0; x < _currentLenght;x++)if (pValue < _array[x])break;
    _currentLenght++;
    E tmp = _array[x];
    E tmp2 = _array[x+1];
    _array[x]=pValue;
    for(;x < _currentLenght-1;x++){
        tmp2 = _array[x+1];
        _array[x+1] = tmp;
        tmp = tmp2;
    }
    return true;
}

template <class E>bool BArray<E>::addi(E pValue)
{
    //realizar un corrimiento de datos
    //de derecha a izquierda de toda la lista y el valor inicia
    //es pValue
    //aumentar _currentLenght en uno si se inserto el dato
}

template <class E>bool BArray<E>::addf(E pValue)
{
    //insertar en el dato al final del arreglo
    //aumentar _currentLenght en uno si se inserto el dato
    if (isFull())return false;
    else if (_currentLenght > 0){
        _array[_currentLenght-1] = pValue;
        return true;
    }
    return addi(pValue);
}

template <class E> E BArray<E>::getValue(int pIndex)
{
    // busca el valor en el indice indicado en el caso de que el indice sea incorrecto
    //arroja un error
}

template <class E> bool BArray<E>::setValue(E data)
{
    //setea el valor nuevo en el indice indicado retorna true si el indice es correcto
    //false si el indice es incorrecto

}

template <class E>
BArray<E>::~BArray()
{
    // libera la memoria de si misma y del puntero que esta misma tiene
}

template <class E> bool BArray<E>::remove(int pIndex){
    // borra el dato en la posicion indicada y realiza el corrimiento de datos de
    // derecha a izquierda
}


template <class E> void BArray<E>::print(){
    cout << "largo:" << _currentLenght <<"[";
    for (int x=0;x < _maximunLenght-1; x++){
        cout << _array[x] << ",";
    }
    cout << _array[_maximunLenght-1] << "]" << endl;
}

#endif // BARRAY_H
