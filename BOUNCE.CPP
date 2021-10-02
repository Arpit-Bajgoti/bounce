#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<process.h>
#include<stdlib.h>
#include<time.h>
#define spacebar     32
#define leftarrowkey  75
#define rightarrowkey  77



int i,q;
// for ball
int xprevious,
    yprevious,
    xcurrent,
    ycurrent;
    const int radius=10;
int xvariable,
    yvariable,
      score,
     ballhits;
// fo hammer
int oldx1,
    oldx2,
    hammerx1,
    hammerx2;
   const int hammery1=400;
   const int hammery2=420;
// for bricks
   int brickx1[]={230+45,170+45,110+45,85+45,170+45,230+45,295+45,380+45,355+45,290+45,525,13/*,30,*/};
   int bricky1[]={20,  50, 80,130,160,190,160,130,80,50,150,150/*,10*/};
   int brickx2[]={280+45,220+45,160+45,135+45,220+45,280+45,345+45,430+45,405+45,340+45,625,113/*,80*/};
   int bricky2[]={45,  75,105,155,185,215,185,155,105,75,170,170/*,35*/};
   int x[]={0,0,0,0,0,0,0,0,0,0,0,0,0,0};

/*/////////////////////////////////////////////////////////////////////*/

class game{ public : void screen_no1();
		     void ball();
		     void hammer(char);
		     void generate();
		     void initialise();
		     void edittedscreen_no1();
		     void screen_no2();
		     void bricks();
		     void striker();	 };

game c1,c2;



void game::screen_no1()
{
  for(i=3;i<459;i++)
  {  delay(2);
  outtextxy(0,i,"Ü");
  }
  for(i=0;i<632;i++)
{
  delay(2);
  outtextxy(i,459,"Ü");}
  for(i=3;i<459;i++)
{ delay(2);
outtextxy(632,i,"Ü"); }


  for(i=0;i<632;i++)
  {  delay(2);
  outtextxy(i,1,"Ü");
  }
setcolor(3);
settextstyle(7,HORIZ_DIR,4);
outtextxy(200,210,"SMASH IT ¹\n");
setcolor(9);
settextstyle(7,0,2);
outtextxy(335,400,"press any key to continue:");
getch();
clrscr();
}
////////////////////////////////////////////////////////

void game::edittedscreen_no1()
{

  for(i=3;i<459;i++)
 outtextxy(0,i,"Ü");

  for(i=0;i<632;i++)
 outtextxy(i,459,"Ü");

  for(i=3;i<459;i++)
 outtextxy(632,i,"Ü");


  for(i=0;i<632;i++)
 outtextxy(i,1,"Ü");

//bricks///////////////////////////////////////////////////////////
////brick 1
setfillstyle(1,5);
bar(brickx1[0],bricky1[0],brickx2[0],bricky2[0]);

//brick 2
setfillstyle(1,5);
bar(brickx1[1],bricky1[1],brickx2[1],bricky2[1]);

setfillstyle(1,5);
bar(brickx1[2],bricky1[2],brickx2[2],bricky2[2]);

setfillstyle(1,5);
bar(brickx1[3],bricky1[3],brickx2[3],bricky2[3]);

setfillstyle(1,5);
bar(brickx1[4],bricky1[4],brickx2[4],bricky2[4]);

setfillstyle(1,5);
bar(brickx1[5],bricky1[5],brickx2[5],bricky2[5]);

setfillstyle(1,5);
bar(brickx1[6],bricky1[6],brickx2[6],bricky2[6]);

setfillstyle(1,5);
bar(brickx1[7],bricky1[7],brickx2[7],bricky2[7]);

setfillstyle(1,10);
bar(brickx1[8],bricky1[8],brickx2[8],bricky2[8]);

setfillstyle(1,5);
bar(brickx1[9],bricky1[9],brickx2[9],bricky2[9]);

setfillstyle(1,5);
bar(brickx1[10],bricky1[10],brickx2[10],bricky2[10]);

setfillstyle(1,5);
bar(brickx1[11],bricky1[11],brickx2[11],bricky2[11]);

/*setfillstyle(1,5);
bar(brickx1[12],bricky1[12],brickx2[12],bricky2[12]);
    */
xcurrent=220 ;
ycurrent=340 ;
setcolor(0);
setfillstyle(1,4);
fillellipse(xcurrent,ycurrent,radius,radius);

setfillstyle(1,6);
bar(175,400,325,420);
}
////////////////////////////////////////////////////////////////////////////

void game::screen_no2()
{  delay(1000);
  for(i=3;i<459;i++)
  {   outtextxy(0,i,"Ü");
  }
  for(i=0;i<632;i++)
{  outtextxy(i,459,"Ü");}

  for(i=3;i<459;i++)
{ outtextxy(632,i,"Ü"); }


  for(i=0;i<632;i++)
  { outtextxy(i,1,"Ü");}

setcolor(3);
settextstyle(7,0,4);
outtextxy(200,20,"INSTRUCTIONS");
setcolor(3);
settextstyle(8,0,3);
{outtextxy(20,80,"1: THE GAME IS SIMPLE AND HANDY TO PLAY");
outtextxy(20,130,"2: (NOTE)- JUST BALANCE THE BALL");
outtextxy(20,180,"3: SMASH THE BRICKS -");
outtextxy(20,230,"4: PINK(ONCE) AND GREEN(TWICE)");
outtextxy(20,280,"5: PRESS 'A' TO MOVE LEFT ");
outtextxy(20,330,"6: PRESS 'S' TO MOVE RIGHT");
outtextxy(20,380,"7: PRESS ESCAPE BUTTON TO QUIT");}
getch();
clrscr();
}

////////////////////////////////////////////////////////////////////////////
void game::bricks()
{
if((ycurrent-radius<=bricky2[0]) && (ycurrent+radius>=bricky1[0]))
    if(xcurrent>=brickx1[0] && xcurrent<=brickx2[0]+2)
      if(x[0]==0)
     {  setfillstyle(1,0);
	bar(brickx1[0],bricky1[0],brickx2[0],bricky2[0]);
	yvariable=-yvariable;
	x[0]=1;}


 if((ycurrent-radius<=bricky2[1]) && (ycurrent+radius>=bricky1[1]))
    if(xcurrent>=brickx1[1] && xcurrent<=brickx2[1]+2)
      if(x[1]==0)
     {  setfillstyle(1,0);
	bar(brickx1[1],bricky1[1],brickx2[1],bricky2[1]);
	yvariable=-yvariable;
	x[1]=1;}

 if((ycurrent-radius<=bricky2[2]) && (ycurrent+radius>=bricky1[2]))
    if(xcurrent>=brickx1[2] && xcurrent<=brickx2[2])
      if(x[2]==0)
     {  setfillstyle(1,0);
	bar(brickx1[2],bricky1[2],brickx2[2],bricky2[2]);
	yvariable=-yvariable;
	x[2]=1;}


  if((ycurrent-radius<=bricky2[3]) && (ycurrent+radius>=bricky1[3]))
    if(xcurrent>=brickx1[3] && xcurrent<=brickx2[3])
      if(x[3]==0)
     {  setfillstyle(1,0);
	bar(brickx1[3],bricky1[3],brickx2[3],bricky2[3]);
	yvariable=-yvariable;
	x[3]=1;}


  if((ycurrent-radius<=bricky2[4]) && (ycurrent+radius>=bricky1[4]))
    if(xcurrent>=brickx1[4] && xcurrent<=brickx2[4])
      if(x[4]==0)
     {  setfillstyle(1,0);
	bar(brickx1[4],bricky1[4],brickx2[4],bricky2[4]);
	yvariable=-yvariable;
	x[4]=1;}



   if((ycurrent-radius<=bricky2[5]) && (ycurrent+radius>=bricky1[5]))
    if(xcurrent>=brickx1[5]-2 && xcurrent<=brickx2[5]+2)
      if(x[5]==0)
     {  setfillstyle(1,0);
	bar(brickx1[5],bricky1[5],brickx2[5],bricky2[5]);
	yvariable=-yvariable;
	x[5]=1;}

      if((ycurrent-radius<=bricky2[6]) && (ycurrent+radius>=bricky1[6]))
    if(xcurrent>=brickx1[6] && xcurrent<=brickx2[6])
      if(x[6]==0)
     {  setfillstyle(1,0);
	bar(brickx1[6],bricky1[6],brickx2[6],bricky2[6]);
	yvariable=-yvariable;
	x[6]=1;}



       if((ycurrent-radius<=bricky2[7]) && (ycurrent+radius>=bricky1[7]))
    if(xcurrent>=brickx1[7] && xcurrent<=brickx2[7])
      if(x[7]==0)
     {  setfillstyle(1,0);
	bar(brickx1[7],bricky1[7],brickx2[7],bricky2[7]);
	yvariable=-yvariable;
	x[7]=1;}


	if((ycurrent-radius<=bricky2[8]) && (ycurrent+radius>=bricky1[8]))
    if(xcurrent>=brickx1[8] && xcurrent<=brickx2[8])
   { if(x[8]==0)
     {  setfillstyle(1,5);
	bar(brickx1[8],bricky1[8],brickx2[8],bricky2[8]);
	yvariable=-yvariable;
	x[8]=1;}
       else if(x[8]==1)
     {  setfillstyle(1,0);
	bar(brickx1[8],bricky1[8],brickx2[8],bricky2[8]);
	yvariable=-yvariable;
	x[8]=2;
	}
      }




	if((ycurrent-radius<=bricky2[9]) && (ycurrent+radius>=bricky1[9]))
    if(xcurrent>=brickx1[9] && xcurrent<=brickx2[9])
      if(x[9]==0)
     {  setfillstyle(1,0);
	bar(brickx1[9],bricky1[9],brickx2[9],bricky2[9]);
	yvariable=-yvariable;
	x[9]=1;}


	if((ycurrent-radius<=bricky2[10]) && (ycurrent+radius>=bricky1[10]))
    if(xcurrent>=brickx1[10] && xcurrent<=brickx2[10])
     if(x[10]==0)
     {  setfillstyle(1,0);
	bar(brickx1[10],bricky1[10],brickx2[10],bricky2[10]);
	yvariable=-yvariable;
	x[10]=1;}



	if((ycurrent-radius<=bricky2[11]) && (ycurrent+radius>=bricky1[11]))
    if(xcurrent>=brickx1[11] && xcurrent<=brickx2[11])
      if(x[11]==0)
     {  setfillstyle(1,0);
	bar(brickx1[11],bricky1[11],brickx2[11],bricky2[11]);
	yvariable=-yvariable;
	x[11]=1;}
  /*

	if((ycurrent-radius<=bricky2[12]) && (ycurrent+radius>=bricky1[12]))
    if(xcurrent>=brickx1[12] && xcurrent<=brickx2[12])
      if(x[12]==0)
     {  setfillstyle(1,0);
	bar(brickx1[12],bricky1[12],brickx2[12],bricky2[12]);
	yvariable=-yvariable;
	x[12]=1;} */

	      }




void game::ball()
{
  delay(15);
  xprevious=xcurrent;
  yprevious=ycurrent;
  setcolor(0);
  setfillstyle(1,0);
  fillellipse(xprevious,yprevious,radius,radius);
  xcurrent+=xvariable;
  ycurrent+=yvariable;
  setfillstyle(1,4);
  fillellipse(xcurrent,ycurrent,radius,radius);

  //conditions
  if(xcurrent-radius<12)
  xvariable=-xvariable;
  if(xcurrent+radius>625)
  xvariable=-xvariable;
  if(ycurrent-radius<12)
  yvariable=-yvariable;
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

bricks();  //INITIALISING WALLS FUNCTION

//////////////////////////////////////////////////////////////////////////////
  // for hitting the ball
  if(ycurrent+radius>390)
  {    if(xcurrent+radius>=hammerx1-4 && xcurrent+radius<=hammerx2+4)
       {        yvariable=-yvariable;
		ballhits++;
		score=5*ballhits;}

       else {
       cleardevice();
       gotoxy(200,150);
       cout<<"GAME OVER\n";
       cout<<"\nSCORE : "<<score<<"\n";
       gotoxy(200,160);
       cout<<"BALL HITS : "<<ballhits;
       cout<<"\nPRESS ESCAPE TO END";
       getch();	}
  delay(15);    } //if main close

}
////////////////END BALL()/////////////////////////////////

void game::hammer(char ch)
{
  switch(ch)
  {  case 'a' :  if(hammerx1>12)
			{oldx1=hammerx1;
			oldx2=hammerx2;
			setfillstyle(1,0);
			bar(oldx1,hammery1,oldx2,hammery2);
			hammerx1=hammerx1-5;
			hammerx2=hammerx2-5;
			setfillstyle(1,6);
			bar(hammerx1,hammery1,hammerx2,hammery2);  }
			break;

   case 's' : if(hammerx2<625)
			{oldx1=hammerx1;
			oldx2=hammerx2;
			setfillstyle(1,0);
			bar(oldx1,hammery1,oldx2,hammery2);
			hammerx1=hammerx1+5;
			hammerx2=hammerx2+5;
			setfillstyle(1,6);
			bar(hammerx1,hammery1,hammerx2,hammery2);  }
			break;

    case  'f'      : exit(0);
			break;

	    } // end switch

 }
/*//////////////END HAMMER//////////////////////////////////////////////////////////*/

void game::generate()
{  {while(inportb(0x60)!=1)
   {
   if(inportb(0x60)==31)hammer('s');
  else if(inportb(0x60)==30)hammer('a');
 ball(); } }
   }

////////////////////////////////////////////////////////////////////////////


void game::initialise()
{
    xcurrent=220;
    ycurrent=340;
    score=0;
    hammerx1=175;
    hammerx2=325;
    xvariable=3.5;
    yvariable=3.5;
    generate();
}
////////////FOR INITIALIZING THE GRAPHICS///////////////////////////////////

void graph()
{ int gd=0,gm;
  initgraph(&gd,&gm,"c:\\turboc3\\bgi");
}
///////////////CLOSE GRAPH()//MAIN DECLARATION///////////////////////////////////////////////
void main()
{
clrscr();
graph();
c1.screen_no1();
closegraph();
graph();
c1.screen_no2();
closegraph();
graph();
c2.edittedscreen_no1();
getch();
c2.initialise();
cleardevice();
//getch();
}