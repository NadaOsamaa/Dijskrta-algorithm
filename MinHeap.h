#ifndef MINHEAP_H_INCLUDED
#define MINHEAP_H_INCLUDED
#include <iostream>
#include <fstream>
using namespace std;

struct Node
{
   char label;
   int cost;
};
class MinHeap
{
    public:
    Node* heap; //an array of nodes
    int _size;  //size of array

    Node extractMin()
    {
       if (_size<=0)
       {
           return *heap;
       }

       else if (_size==1)
       {
           _size--;
           return heap[0];
       }
       else
       {
           Node minn=heap[0];
           heap[0]=heap[_size--];
           _size--;
           minHeapify(0,_size);
           return minn;
       }

    }
    void buildMinHeap(Node arr [],int n)
    {
        for (int i=(i - 1) / 2;i>=0;i--)
        {
            heap[i].cost=arr[i].cost;
            heap[i].label=arr[i].label;
            minHeapify(i,n);
        }

    }
    void minHeapify(int i, int n)
    {
        int minn=i;
        int L=2*i;
        int R=2*i+1;
        if (L<n&& (heap[L].cost < heap[minn].cost && heap[L].label < heap[minn].label) )
            minn=L;
        if (R<n&& (heap[R].cost < heap[minn].cost&& heap[R].label < heap[minn].label))
            minn=R;
        if (minn!=i)
        {
            swap (heap[i],heap[minn]);
            minHeapify(i,n);
        }
    }
    void decreaseKey(char l,int newCost)
    {
        for (int i=0;i<_size;i++)
        {
            if (heap->label>l)
            {
               cout<<"wrong label "<<endl ;
            }
            else
            {
               heap->cost=newCost;
               minHeapify(i,_size);
            }
        }
    }
    int parent(int i)
    {
        return (i - 1) / 2;
    }
    int getSize()
    {
        return _size;
    }
    bool inHeap(char l)
    {
      int flag=0;
        if (_size<=0)
       {
            cout<<"Empty array "<<endl;
            return false ;
       }
       else
       {
          for (int i=0;i<_size;i++)
          {
             if (heap[i].label==l)
             {
              flag=1;
             }
             else
             {
                 flag=0;
             }
          }

          if (flag==1)
          {
              return true ;
          }
          else
          {
              return false ;
          }


       }

    }
};


#endif // MINHEAP_H_INCLUDED
