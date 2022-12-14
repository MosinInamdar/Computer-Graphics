//#include <conio.h>
#include <iostream>
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
#define ScreenWidth getmaxx()
#define ScreenHeight getmaxy()
#define GroundY ScreenHeight*0.75
void Rain(int x)
{
int i,rx,ry;
for(i=0;i<400;i++)
{
    //generate random value of x and y
 rx=rand() % ScreenWidth;
 ry=rand() % ScreenHeight;
 if(ry<GroundY-4)
 {
  if(ry<GroundY-120 || (ry>GroundY-120 && (rx<x-20 || rx>x+60)))
  line(rx,ry,rx+5,ry+4);
 }
}
}
int main()
{
int gd=DETECT,gm;
	//initgraph(&gd,&gm,NULL);
    initwindow(700,600);
    cleardevice();
    line(0,500,getmaxx(),500);
    line(0,500,20,450);
    line(80,500,60,450);

    rectangle(0,330,80,450);

    circle(40,300,30);
    int flag=0,gapflag=0;
    for(int i=0;i<getmaxx()-50;i=i+10)
    {
        cleardevice();
        line(0,500,getmaxx(),500);      //road
            Rain(0);
        rectangle(0+i,330,80+i,450);    //body

        circle(40+i,300,30);            //head
        if(flag==0)
        {
            line(0+i,500,20+i,450);       //leg1
            line(80+i,500,60+i,450);      //leg2
            line(40+i,345,120+i,425);         //Left hand
            flag=1;
        }
        else{
            line(80+i,500,20+i,450);        //leg1
            line(i,500,60+i,450);           //leg2
            line(40+i,345,-40+i,425);         //left hand
            flag=0;
        }
        line(80+i,385,120+i,345);        //Right hand
        line(120+i,345,80+i,240);       //Handle hand
        line(-40+i,240,200+i,240);      //horizontal line
        arc(80+i,240,180,360,120);
        delay(1000);
    }
    delay(10000);
    closegraph();
}
