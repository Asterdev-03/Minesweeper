/*
    Minesweeper 5*5
    Version 1.0
	Supports : TurboCPP
    Written by: Aswin K
*/

#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<stdio.h>

void intro(void)
{
 ll:
 clrscr();
 int a;
 cout<<"Welcome to Minesweeper...";
 cout<<"\n1.Play\n2.Help\n\nYour choice: ";
 cin>>a;
 if(a==1);
 else if(a==2)
 {
 clrscr();
 cout<<"\nHints:";
 cout<<"\n*This is a 5*5 minesweeper game";
 cout<<"\n*There are 25 boxes which may contain a mine.";
 cout<<"\n*Each game contains maximum of 5 mines.The number of mines varies from one game to another.";
 cout<<"\n*There is also a chance to open a lucky box.It helps you to open multiple boxes,when a single box is selelected";
 cout<<"\n\nHow to play:";
 cout<<"\n*Type the respective number to open the box and press ENTER.";
 cout<<"\n*If you open a box without a mine,the box will show 'o'.";
 cout<<"\n*Or else it will show 'X' ,representing a mine.";
 cout<<"\n\nENJOY THE GAME...";
 cout<<"\n\nPress any key.";
 getch();
 }
 else goto ll;
}

void main()
{
intro();
rr:
char a[10][10],comp[10][10],b[10][10];
int user,y=0,i,j,t,x,l=0,ret;
srand(time(NULL));
randomize();

for(i=0;i<5;i++)
   for(j=0;j<5;j++)
   {                               //        ????
       comp[i][j]='Y';
       b[i][j]=2;
   }

for(x=0;x<5;x++)
    {
    i=rand()%5;                   //      Randomising bombs...
    j=rand()%5;
    comp[i][j]='X';
    }

for(x=0;x<5;x++)
{
   ll:
   i=rand()%5;               //       Randomising lucky boxes...
   j=rand()%4;
   if(comp[i][j]!='X')
	b[i][j]=1;
   else
   goto ll;
}

for(i=0;i<5;i++)
   for(j=0;j<5;j++)
       a[i][j]='�';


aa:

clrscr();
cout<<"Enter 0 to Exit\n\n\t\t\t";
for(i=0;i<5;i++)
{  cout<<"|";
   for(j=0;j<5;j++)
      cout<<" "<<a[i][j]<<" ";      //Layer formation
   cout<<"|\n\n\t\t\t";
}

if((l==0)&&(y!=0))
{
for(i=0;i<5;i++)
for(j=0;j<5;j++)
if(comp[i][j]=='X')                 //Exposing bombs
a[i][j]='X';
l++;
goto aa;
}

if(y!=0)
{
cout<<"You have lost!!";
cout<<"\n\t\t     Better luck next time...";      //Checking if u lose
goto bb;
}

for(i=0;i<5;i++)
   for(j=0;j<5;j++)
       if(comp[i][j]!='X')             //Checking if u win
       {if(a[i][j]=='o');
       else
       goto mm;}

cout<<"You Have Won";
goto bb;

mm:

cout<<"\nEnter a number: ";
cc:
cin>>user;

if(user==0) goto ex;

switch(user)
{
case 1: if(b[0][0]==1)
	for(t=0;t<3;t++)
	{if(comp[0][t]!='X')a[0][t]='o';
	if(comp[1][t]!='X')a[1][t]='o';}
	else if(comp[0][0]!='X')a[0][0]='o';else{a[0][0]='X';y++;}break;
case 2: if(b[0][1]==1)
	for(t=0;t<3;t++)
	{if(comp[0][t]!='X')a[0][t]='o';
	if(comp[1][t]!='X')a[1][t]='o';}
	else if(comp[0][1]!='X')a[0][1]='o';else {a[0][1]='X';y++;}break;
case 3: if(b[0][2]==1)
	for(t=0;t<3;t++)
	{if(comp[0][t]!='X')a[0][t]='o';
	if(comp[1][t]!='X')a[1][t]='o';}
	else if(comp[0][2]!='X')a[0][2]='o';else {a[0][2]='X';y++;}break;
case 4: if(b[0][3]==1)
	for(t=0;t<4;t++)
	{if(comp[0][t]!='X')a[0][t]='o';
	if(comp[1][t]!='X')a[1][t]='o';}
	else if(comp[0][3]!='X')a[0][3]='o';else {a[0][3]='X';y++;}break;
case 5: /*if(b[0][4]==1)
	for(t=3;t<1;t--)
	  {if(comp[0][t]!='X')a[0][t]='o';
	  if(comp[1][t]!='X')a[1][t]='o';}
	else */
	if(comp[0][4]!='X')a[0][4]='o';else {a[0][4]='X';y++;}break;
case 6: if(b[1][0]==1)
	for(t=0;t<3;t++)
	{if(comp[1][t]!='X')a[1][t]='o';
	if(comp[2][t]!='X')a[2][t]='o';}
	else if(comp[1][0]!='X')a[1][0]='o';else {a[1][0]='X';y++;}break;
case 7: if(b[1][1]==1)
	for(t=0;t<3;t++)
	{if(comp[1][t]!='X')a[1][t]='o';
	if(comp[2][t]!='X')a[2][t]='o';}
	else if(comp[1][1]!='X')a[1][1]='o';else {a[1][1]='X';y++;}break;
case 8: if(b[1][2]==1)
	for(t=0;t<3;t++)
	{if(comp[1][t]!='X')a[1][t]='o';
	if(comp[2][t]!='X')a[2][t]='o';}
	else if(comp[1][2]!='X')a[1][2]='o';else {a[1][2]='X';y++;}break;
case 9: if(b[1][3]==1)
	for(t=0;t<4;t++)
	{if(comp[1][t]!='X')a[1][t]='o';
	if(comp[2][t]!='X')a[2][t]='o';}
	else if(comp[1][3]!='X')a[1][3]='o';else {a[1][3]='X';y++;}break;
case 10:/*if(b[1][4]==1)
	for(t=4;t<1;t--)
	{if(comp[1][t]!='X')a[1][t]='o';
	if(comp[2][t]!='X')a[2][t]='o';}
	else */if(comp[1][4]!='X')a[1][4]='o';else {a[1][4]='X';y++;}break;
case 11:if(b[2][0]==1)
	for(t=0;t<3;t++)
	{if(comp[2][t]!='X')a[2][t]='o';
	if(comp[3][t]!='X')a[3][t]='o';}
	else if(comp[2][0]!='X')a[2][0]='o';else {a[2][0]='X';y++;}break;
case 12:if(b[2][1]==1)
	for(t=0;t<3;t++)
	{if(comp[2][t]!='X')a[2][t]='o';
	if(comp[3][t]!='X')a[3][t]='o';}
	else if(comp[2][1]!='X')a[2][1]='o';else {a[2][1]='X';y++;}break;
case 13:if(b[2][2]==1)
	for(t=0;t<3;t++)
	{if(comp[2][t]!='X')a[2][t]='o';
	if(comp[3][t]!='X')a[3][t]='o';}
	else if(comp[2][2]!='X')a[2][2]='o';else {a[2][2]='X';y++;}break;
case 14:if(b[2][3]==1)
	for(t=0;t<4;t++)
	{if(comp[2][t]!='X')a[2][t]='o';
	if(comp[3][t]!='X')a[3][t]='o';}
	else if(comp[2][3]!='X')a[2][3]='o';else {a[2][3]='X';y++;}break;
case 15:/*if(b[2][4]==1)
	for(t=4;t<1;t--)
	{if(comp[2][t]!='X')a[2][t]='o';
	if(comp[3][t]!='X')a[3][t]='o';}
	else */if(comp[2][4]!='X')a[2][4]='o';else {a[2][4]='X';y++;}break;
case 16:if(b[3][0]==1)
	for(t=0;t<3;t++)
	{if(comp[3][t]!='X')a[3][t]='o';
	if(comp[4][t]!='X')a[4][t]='o';}
	else if(comp[3][0]!='X')a[3][0]='o';else {a[3][0]='X';y++;}break;
case 17:if(b[3][1]==1)
	for(t=0;t<3;t++)
	{if(comp[3][t]!='X')a[3][t]='o';
	if(comp[4][t]!='X')a[4][t]='o';}
	else if(comp[3][1]!='X')a[3][1]='o';else {a[3][1]='X';y++;}break;
case 18:if(b[3][2]==1)
	for(t=0;t<3;t++)
	{if(comp[3][t]!='X')a[3][t]='o';
	if(comp[4][t]!='X')a[4][t]='o';}
	else if(comp[3][2]!='X')a[3][2]='o';else {a[3][2]='X';y++;}break;
case 19:if(b[3][3]==1)
	for(t=0;t<4;t++)
	{if(comp[3][t]!='X')a[3][t]='o';
	if(comp[4][t]!='X')a[4][t]='o';}
	else if(comp[3][3]!='X')a[3][3]='o';else {a[3][3]='X';y++;}break;
case 20:/*if(b[3][4]==1)
	for(t=4;t<1;t--)
	{if(comp[3][t]!='X')a[3][t]='o';
	if(comp[4][t]!='X')a[4][t]='o';}
	else */if(comp[3][4]!='X')a[3][4]='o';else {a[3][4]='X';y++;}break;
case 21:if(b[4][0]==1)
	for(t=0;t<3;t++)
	{if(comp[4][t]!='X')a[4][t]='o';
	if(comp[3][t]!='X')a[3][t]='o';}
	else if(comp[4][0]!='X')a[4][0]='o';else {a[4][0]='X';y++;}break;
case 22:if(b[4][1]==1)
	for(t=0;t<3;t++)
	{if(comp[4][t]!='X')a[4][t]='o';
	if(comp[3][t]!='X')a[3][t]='o';}
	else if(comp[4][1]!='X')a[4][1]='o';else {a[4][1]='X';y++;}break;
case 23:if(b[4][2]==1)
	for(t=0;t<3;t++)
	{if(comp[4][t]!='X')a[4][t]='o';
	if(comp[3][t]!='X')a[3][t]='o';}
	else if(comp[4][2]!='X')a[4][2]='o';else {a[4][2]='X';y++;}break;
case 24:if(b[4][3]==1)
	for(t=0;t<4;t++)
	{if(comp[4][t]!='X')a[4][t]='o';
	if(comp[3][t]!='X')a[3][t]='o';}
	else if(comp[4][3]!='X')a[4][3]='o';else {a[4][3]='X';y++;}break;
case 25:/*if(b[4][4]==1)
	for(t=4;t<1;t--)
	{if(comp[4][t]!='X')a[4][t]='o';
	if(comp[3][t]!='X')a[3][t]='o';}
	else */if(comp[4][4]!='X')a[4][4]='o';else {a[4][4]='X';y++;}break;
default:cout<<"Enter another number\n"; getch(); goto cc;
}
goto aa;
bb:
cout<<"\n\nIf you want to RETRY press 1: ";
cin>>ret;
if(ret==1)
goto rr;
ex:
}