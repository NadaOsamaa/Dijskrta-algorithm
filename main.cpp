/***********************************
 *  Nada Osama Ahmed     20207026  *
 *  Zeina Ayman Abass    20207006  *
 *  Group:  SG2                    *
 ***********************************/

#include <iostream>
#include <fstream>
#include "MinHeap.h"
#include "WeightedGraph.h"
using namespace std;

int main()
{
    WeightedGraph wg;
    ifstream ifile("graph.txt");
    wg.loadGraphFromFile(ifile);

    char* p;
    p = new char[wg.getNVertices()];

    Node* n;
    n=new Node[wg.getNVertices()];

    wg.dijkstra('g',p,n);

    cout<<endl<<"Node\tCost\tPrevious";

    for(int i=0;i<wg.getNVertices();i++)
    {
        cout<<endl<<n[i].label<<"\t"<<n[i].cost<<"\t"<<p[i];
    }

    ifile.close();
    return 0;
}

