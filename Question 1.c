#include<stdio.h>
#include<stdlib.h>
//#include<unilib.h>
int n,n1;//process counter
struct process
{
int p,bt,at;
int nbt;
int et;
}Pro[20];
int wl[20];
int t = 0;

void initialize()
{
 printf("\nEnter pid in numerics: ");
 printf("\nWith respedtive BT and AT: \n");
 for(int i= 0; i<n; i++)
 {
  printf("Enter pid of process %d: ", i+1);
  scanf("%d",&Pro[i].p);
  printf("Enter AT of process %d: ", i+1);
  scanf("%d",&Pro[i].at);
  printf("Enter BT of process %d: ", i+1);
  scanf("%d",&Pro[i].bt);
 }
 for(int i=0; i<n; i++)
 {
  Pro[i].nbt=Pro[i].bt;
  wl[i] = i;
 }
int a;
 for(int i=0; i<n-1; i++)
 {
  for(int j=i+1; j<n; j++)
  {
   if(Pro[wl[i]].at>Pro[wl[j]].at)//compares at of 2 process
    {
      a = wl[i];
      wl[i] = wl[j];
      wl[j] = a;
    }
   else if(Pro[wl[i]].at==Pro[wl[j]].at)
    {
        if(Pro[wl[i]].p>Pro[wl[j]].p)//compares at of 2 process
         {
           a = wl[i];
           wl[i] = wl[j];
           wl[j] = a;
         }
    }
   else
    {}
  } 
 }
}

void updatewl(int c)
{
 if(c==0)
 {
  wl[0]=NULL;
  for(int i=1; i<n; i++)
  {
    wl[i-1] = wl[i];
  }
  wl[n-1]=NULL;
  n--;
 } 
 if(c==1)
 {
  int a = wl[0];
  for(int i=1; i<n; i++)
  {
    wl[i-1] = wl[i];
  }
  wl[n-1]=a;
 }
}

void run(int tq)
{
 for(int i=0; i<n; i++)
 {
  if (Pro[wl[0]].nbt <= tq)
   {
     t = t + Pro[i].nbt;
     Pro[i].et = t;
     Pro[i].nbt = 0;
     updatewl(0);
   }
  else if(Pro[wl[0]].nbt> tq)
   {
    t = t+tq;
    Pro[i].nbt = Pro[i].nbt - tq;
    updatewl(1);
   }
 }
}

void sjfwl()
{
  int a;
 for(int i=0; i<n-1; i++)
 {
  for(int j=i+1; j<n; j++)
  {
   if(Pro[wl[i]].bt>Pro[wl[j]].bt)//compares at of 2 process
    {
      a = wl[i];
      wl[i] = wl[j];
      wl[j] = a;
    }
   else if(Pro[wl[i]].at==Pro[wl[j]].at)
    {
        if(Pro[wl[i]].p>Pro[wl[j]].p)//compares at of 2 process
         {
           a = wl[i];
           wl[i] = wl[j];
           wl[j] = a;
         }
    }
   else
    {}
  } 
 }
}

void runsjf()
{
 sjfwl();
 for(int i=0; i<n; i++)
 {
   t = t + Pro[wl[i]].nbt;
   Pro[wl[i]].nbt = 0;
   Pro[wl[i]].et = t;
 }
}


void show()
{
 for(int i=0; i<n1; i++)
 {
  printf("\n\nPID %d",Pro[i].p);
  printf("\nAT %d",Pro[i].at);
  printf("\nBT %d",Pro[i].bt);
  //printf("\nNBT %d",Pro[i].nbt);
  printf("\nET %d",Pro[i].et);
  printf("\nWT %d",Pro[i].et-(Pro[i].at+Pro[i].bt));
  printf("\nTAT %d",Pro[i].et-Pro[i].at);
 }
}


void main()
{
 printf("\nEnter number of processes: \n");
 scanf("%d",&n);
 n1 = n;
 initialize();
 run(3);
 run(6);
 runsjf();
 show();

}
