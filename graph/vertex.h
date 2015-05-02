#include "iostream"
#include "edge.h"
#include "ordinateList/doublelist.h"
#ifndef VERTEX_H
#define VERTEX_H

using namespace std;

template <class E>
class Vertex
{
    string _tag;
    E _data;
    DoubleList< Edge<E> > edges;
public:
    Vertex(E pData, string pTag);
    //addConnection(Edge<E> pVertex);
    //removeConnection();
};

#endif // VERTEX_H
