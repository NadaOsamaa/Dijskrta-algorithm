#ifndef WEIGHTEDGRAPH_H_INCLUDED
#define WEIGHTEDGRAPH_H_INCLUDED
#include <iostream>
#include <fstream>
#include<climits>
using namespace std;

class WeightedGraph:public MinHeap
{
    int** g;
    int nVertices;

public:
    int getNVertices()
    {
       return nVertices;
    }
    int getWeight(char x,char y)
    {
       int cntr=0;
       cntr=g[x-'a'][y-'a'];
       return cntr;
    }

    int* returnNeighbors(int v)
    {
        int arr[nVertices];
        int cntr=0;
        for (int i=0;i < nVertices;i++)
        {
            if (g[v][i]!=0)
            {
                arr[cntr]=i;
                     cntr++;
            }
        }
    }


    int numNeighbors(int v)
    {
        int cntr=0;
        for (int i = 0; i < nVertices; i++)
            {
               if(g[v][i]!=0)
               {
                  cntr++;
               }

             }
        return cntr;
    }

    void loadGraphFromFile(ifstream& ifile )
    {
        char ver1;
        char ver2;
        int weight ;
        int nEdges;

        ifile>>nVertices;
        ifile>>nEdges;

        g = new int *[nVertices];
        for(int i=0; i<nVertices; i++)
        {
            g[i] = new int [nVertices];
        }

        for(int i=0; i<nVertices; i++)
        {
            for(int j=0; j<nVertices; j++)
            {
                g[i][j] =0;
            }
        }

        for(int i=0; i<nEdges; i++)
        {
            ifile >> ver1;
            ifile >> ver2;
            ifile >> weight;
            g[ver1-'a'][ver2-'a'] = weight;
        }
    }

     int miniDist(bool check[], Node distances[])
       {
            int minimum=INT_MAX;
            int indx;

            for(int i=0;i<nVertices;i++)
            {
               if(check[i]==false && distances[i].cost<=minimum)
               {
                  minimum=distances[i].cost;
                  indx=i;
               }
            }
           return indx;
      }


    void dijkstra(char startVertex, char* prev, Node distances[])
   {
       int x = startVertex - 'a';

       bool check[nVertices];
       for (int i = 0; i < nVertices; i++)
       {
          distances[i].cost = INT_MAX;
          check[i] = false;
      }
       distances[x].cost= 0;
       prev[x] = x + 'a';
       for (int i = 0; i < nVertices; i++)
       {
        int mini= miniDist(check,distances);
        check[mini] = true;

        for (int j= 0; j < nVertices; j++)
        {
            if (!check[j]&& g[mini][j] && distances[mini].cost!= INT_MAX &&distances[mini].cost+ g[mini][j] < distances[j].cost)
                {
                    distances[j].cost=distances[mini].cost + g[mini][j];
                     prev[j]=mini+'a';

                }
        }
        distances[i].label = i + 'a';
    }

  }

};

#endif // WEIGHTEDGRAPH_H_INCLUDED
