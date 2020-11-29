#include <stdio.h>
#include <stdlib.h>
void swap(int *x, int *y)
{
    int t;
    t=*x;
    *x=*y;
    *y=t;
}
void bs(int *p,int n,int *s,int *c)
{

  for (int i = 0; i < n - 1; i++)
  {
    for (int j = (n - 1); j > i; j--)
    { *c+=1;
      if (p[j - 1] > p[j])
      {
       swap(&p[j-1],&p[j]);
       *s+=1;
      }
    }
  }
}
void qs(int *p,int l,int r,int* s, int* c)
{
if (l<r)
{
int mdl = (l+r)/2;
int first = l;
int last = r;
while (l<r)
 {
    while ((l<r) && (p[mdl] > p[l])){l++; *c += 1;}
    while ((l<r) && (p[mdl] < p[r])){r--; *c += 1;}
    *c+=2; // дополнительно +2 сравнения, при которых циклы завершились
    if (l < r)
    {
        swap(&p[l], &p[r]);
        r--;
        l++;
        *s += 1;
    }
    if (l == r); // Проверка, чтобы один элемент не менялся сам с собой
    {
        r--;
        l++;
    }
 }
qs(p,first,r,c,s);
qs(p,l,last,c,s);
}
}
void Is(int *p,int n, int* s, int* c)
{
    int j;
    for (int i=1;i<n;i++)
    { *c+=1;
        if (p[i-1]>p[i])
        { swap(&p[i-1],&p[i]);
          *s+=1;
          *c+=1;//за сравнение, при котором for прерывается
          j=i-1;
          while ((j > 0)&&(p[j]<p[j-1]))
          {
              swap(&p[j],&p[j-1]);
              *s+=1;
              j--;
          }
        }
    }
}

int main()
{
    int *p,swp=0,cmp=0,n,f; //cwp cmp - счетчики для перестановок и сравнений соотв.
printf("Enter array size: \n");
    scanf("%d", &n);
    p = malloc(sizeof(int)*n);
    printf("Enter array: \n");
    for (int i = 0; i<n; i++) scanf("%d", &p[i]);
    printf("Choose sorting type: \n 1. Bubble sort \n 2. Quick sort \n 3. Insertion sort \n");
    scanf("%d",&f);
    switch (f)
    {
    case 1:
    bs(p, n, &swp, &cmp);
    break;
    case 2:
    qs(p,0,n-1,&swp,&cmp);
    break;
    case 3:
    Is(p,n,&swp,&cmp);
    break;
    }
    for(int i=0;i<n;i++) printf("%d ",p[i]);
    printf("\n Swaps:%d \n Comparsions:%d",swp,cmp);
    return 0;


}
