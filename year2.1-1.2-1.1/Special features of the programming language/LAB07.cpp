#include<iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;

struct node
{
  int Key;
  int Count;
  node *Left;
  node *Right;
};

class TREE
{
  private:
    node *duk; //Корень дерева.
  public:
    TREE() { duk = NULL; }
    node **GetDuk() { return &duk; }
    node *Tree (int, node **);
    void Vyvod (node **, int);
};


node *TREE::Tree (int n,node **p)
// Построение идеально сбалансированного
//           дерева с n вершинами.
// *p - указатель на корень дерева.
{
  node *now;
  int x,nl,nr;

  now = *p;
  if  (n==0) *p = NULL;
  else
  {
    nl = n/2; nr = n - nl - 1;
    cin>>x;
    now = new(node);
    (*now).Key = x;
    Tree (nl,&((*now).Left));
    Tree (nr,&((*now).Right));
    *p = now;
  }
}

void TREE::Vyvod (node **w,int l)
// Изображение бинарного дерева, заданного
// указателем *w на экране дисплея.
{
  if  (*w!=NULL)
  {
    Vyvod (&((**w).Right),l+1);
    for  (int i=1; i<=l; i++) cout<<"   ";
    cout<<(**w).Key<<endl;
    Vyvod (&((**w).Left),l+1);
  }
}


int main ()
{
  TREE A;
  int n;

  cout<<"Enter number of summits -...\n";
  cin>>n;
  cout<<"Enter keys...\n";
  A.Tree (n,A.GetDuk());
  A.Vyvod (A.GetDuk(),0);
  return 0;
}
