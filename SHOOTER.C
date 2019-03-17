#include<graphics.h >
#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<dos.h>
int u=0;
int p1;
int score=0;
int y1,tmpx;
typedef struct Lead
{
char name[30];
int sc;
}Lead;
Lead abc[10];
int a[10][50];
void Boundry()
{
rectangle(1,1,637,477);
rectangle(2,2,636,476);
}
void display()
{   int p=5,q=8,i,j,xc;
for(i=0;i<10;i++)
{
for(j=0;j<50;j++)
{
a[i][j]=rand()%2;

}
}
   for(i=0;i<10;i++)
   {p=71;
    for(j=0;j<50;j++)
    {
     if(a[i][j]!=0)
     {  setcolor(WHITE);
      setfillstyle(1,GREEN);
      pieslice(p,q,0,360,5);
      }
      p=p+10;
     }
     q=q+20;
    }


}
int chk(int a1)
{ int i,mn=0;
  p1=((a1-70)/10)%50;
  p1=p1+1;
 for(i=9;i>=0;i--)
 { if(a[i][p1]!=0)
  {sound(8000);
  delay(2);
  nosound();
   a[i][p1]=0;
   score=score+1;
   mn=(i*20)+8;

   return mn;
  }
}
}
void Shuttle(i,j)
{
	line(i,j,i-50,j+50);
	line(i,j,i+50,j+50);
	line(i-50,j+50,i,j+20);
	line(i+50,j+50,i,j+20);
}
void sort(Lead x[],int n)
{
int i,j;
Lead temp;
for(i=0;i<n;i++)
{
for(j=i;j<n;j++)
{
if(x[j].sc<x[j+1].sc)
{
temp=x[j];
x[j]=x[j+1];
x[j+1]=temp;
}
}
}

}
void Fire(i,j)
{
int b,tmpy;
tmpx=i;
tmpy=j;
b=chk(tmpx);
sound(1250);
  delay(20);
  nosound();
while(j>b)
{
//setcolor(WHITE);
setfillstyle(1,WHITE);
pieslice(i+2,j+5,0,360,5);
delay(2);
setcolor(BLACK);
setfillstyle(1,BLACK);
pieslice(i+2,j+5,0,360,5);
setcolor(WHITE);
j=j-10;
delay(10);

}
 setcolor(BLACK);
      setfillstyle(1,BLACK);
      pieslice(tmpx+2,b,0,360,5);
      setcolor(WHITE);
}

void main()
{
int i,j,inc=10,xc,yc,p,q,m,n,l,r;
char ch,restart;
int gdriver = DETECT, gmode, errorcode;
time_t start,end;
double elapsed;
char bfr[30];
printf("    ***ASTEROID SHOOTER***\n");
printf("Enter The Name of Player:");
scanf("%s",abc[u].name);

initgraph(&gdriver, &gmode, "C:\\TURBOC3\\BGI");
errorcode = graphresult();
if (errorcode != grOk)
{
   printf("Graphics error: %s\n", grapherrormsg(errorcode));
   printf("Press any key to halt:");
   getch();
   exit(1);
}


Boundry();
display();
i=getmaxx()/2;
j=getmaxy()/2;
xc= getmaxx()-70;
yc= getmaxy()-70;
q=3;


   m=getmaxx()/2 -50;
   n= getmaxy()-60;
   start=time(NULL);
while(1)
{

    end=time(NULL);
    elapsed=difftime(end,start);
    Shuttle(m-20,n);
    l=m -20;
    r=n;
    setcolor(WHITE);
    ch=getch();

    if(ch==75)         //move left
    {
	Fire(m-20,n-22);
	setcolor(BLACK);
	 Shuttle(l,r);
	if(m>70)
	    m-=inc;
      // display();
	      setcolor(WHITE);
    }

    if(ch==77)         //move right
    {
	Fire(m-20,n-22);
	setcolor(BLACK);
	 Shuttle(l,r);
	if(m<getmaxx()-65)
	    m+=inc;
	  //  display();
	      setcolor(WHITE);
    }

    if(ch==27)        //exit when esc pressed
	exit(0);
    if(elapsed>=20.00)
   {
    break;
    }
}
outtextxy(250,250,"GAME OVER");
sprintf(bfr,"Your score is %d",score);
outtextxy(250,260,bfr);
outtextxy(250,270,"PRESS ENTER TO CONTINUE");
fflush(stdin);
scanf("%c",&ch);
closegraph();

printf("press p to continue playing\n");
printf("press L to Exit \n");
fflush(stdin);
scanf("%c",&restart);
if(restart=='p')
{
abc[u].sc=score;
score=0;
u++;
main();
}
if(restart=='l')
{
abc[u].sc=score;
u=u+1;
printf("                 LEADERBOARD\n");
sort(abc,u);
for(i=0;i<u;i++)
{
printf("RANK %d : %s = %d\n",i+1,abc[i].name,abc[i].sc);
}
}
fflush(stdin);
scanf("%c",&restart);
clrscr();
}
