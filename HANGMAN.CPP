#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<time.h>
#include<dos.h>
#include<stdio.h>
#include<string.h>
char b[11],word[11];
int d=0;
void movies();
void sports();
void countries();
void dash();
void hangman(int);
int show(int);
void main()
{
	char w,e,ch;
	char used[30];
	int i,count,pr,flag,f1,x,y,j,x1,x2;
	for(i=0;i<30;i++)
		used[i]='*';
	clrscr();
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"c:\\tc\\bgi\\");
	settextstyle(4,0,5);
	setcolor(YELLOW);
	setbkcolor(BLUE);
	outtextxy(200,100,"WELCOME");
	outtextxy(280,200,"TO");
	outtextxy(200,300,"HANGMAN");
	delay(5000);
	cleardevice();
	settextstyle(7,0,3);
	setcolor(YELLOW);
	outtextxy(200,10,"INSTRUCTIONS");
	settextstyle(0,0,1);
	outtextxy(1,80,"1. The object of this game is to correctly fill in all of the blank spaces");
	outtextxy(25,90,"before the stick man is hung.");
	outtextxy(1,120,"2. The word to guess is represented by a row of dashes, giving the number of");
	outtextxy(25,130,"letters.");
	outtextxy(1,160,"3. Enter letters in CAPITALS by typing them on keyboard.");
	outtextxy(1,180,"4. Correct letters are written to all corresponding blank marks.");
	outtextxy(1,210,"5. If a letter does not match with any of the blank marks then part of a");
	outtextxy(25,220,"stick man figure is drawn.");
	outtextxy(1,250,"6. After six unmatched letters stick man figure is completed and hung.");
	outtextxy(25,260,"You lose and correct word appears on the screen.");
	outtextxy(1,290,"7. If you fill in all the blank marks before stick man is completed then");
	outtextxy(25,300,"you win and stick man is rescued.");
	outtextxy(1,330,"8. Only 26 alphabets are allowed.");
	outtextxy(1,360,"9. Repetition of alphabets while guessing is not allowed.");
	settextstyle(7,0,4);
	setcolor(GREEN);
	outtextxy(200,400,"GOOD LUCK!!");
	settextstyle(7,0,2);
	setcolor(RED);
	outtextxy(150,450,"PRESS ANY KEY TO CONTINUE");
	getch();
first:	do
	{
	cleardevice();
	settextstyle(7,0,3);
	setcolor(YELLOW);
	outtextxy(200,50,"SELECT THE CATEGORY");
	outtextxy(200,100,"1. MOVIES");
	outtextxy(200,150,"2. SPORTS");
	outtextxy(200,200,"3. COUNTRIES");
	outtextxy(200,250,"4. QUIT");
	ch=getch();
	cleardevice();
	switch(ch)
	{
		case '1': outtextxy(200,10,"CATEGORY: MOVIES");
			  movies();
			  break;
		case '2': outtextxy(200,10,"CATEGORY: SPORTS");
			  sports();
			  break;
		case '3': outtextxy(200,10,"CATEGORY: COUNTRIES");
			  countries();
			  break;
		case '4': goto end;
		default:  cleardevice();
			  outtextxy(100,220,"ENTER A CORRECT CHOICE");
			  delay(1500);
			  goto first;
	}
	for(i=0;i<11;i++)
		word[i]=b[i];
	x=100;
	y=330;
	pr=0;
	count=0;
	settextstyle(7,0,2);
	outtextxy(90,260,"ENTER A CHARACTER");
	outtextxy(110,290,"IN CAPITALS");
	for(j=1;j<=26;j++)
	{
		if(j%8==0)
		{
			y=y+30;
			x=100;
		}
		if(pr<d && count<6)
		{
			f1=0;
			flag=0;
			w=getch();
			for(i=1;i<j;i++)
			{
				if(w==used[i])
				{
					f1=1;
					j--;
					break;
				}
			}
			if(f1!=1)
			{
				outtextxy(x,y,&w);
				used[j]=w;
				x=x+25;
				for(i=0;i<11;i++)
				{
					if(b[i]!='*')
					{
						if(w==b[i])
						{
							flag=1;
							pr++;
							x1=show(i+1);
							outtextxy(x1,70,&w);
							b[i]='+';
						}
					}
					else
						break;
				}
				if(flag==0)
				{
					count++;
					hangman(count);
				}
			}
		}
		else
			break;
	}
	delay(2000);
	cleardevice();
	if(count==6 || j>26)
	{
		settextstyle(0,0,5);
		setcolor(RED);
		outtextxy(75,75,"YOU LOSE!!:P");
		settextstyle(7,0,4);
		setcolor(YELLOW);
		outtextxy(100,230,"CORRECT WORD:");
		settextstyle(7,0,3);
		x2=150;
		for(i=0;i<11;i++)
		{
			w=word[i];
			if(word[i]!='*')
			{
				if(word[i]!=' ')
				{
					outtextxy(x2,280,&w);
					delay(500);
				}
			}
			x2=x2+30;
		}
		settextstyle(7,0,1);
		outtextxy(100,400,"ENTER ANY KEY TO CONTINUE");
		getch();
	}
	if(pr==d)
	{
		settextstyle(0,0,6);
		setcolor(GREEN);
		outtextxy(75,220,"YOU WIN!!:)");
		delay(1000);
	}
	}
	while(ch!='4');
end:    cleardevice();
	outtextxy(100,230,"DO YOU REALLY WANT TO QUIT? (Y/N)");
	e=getch();
	if(e=='N')
		goto first;
	else
	{
		cleardevice();
		settextstyle(7,0,4);
		outtextxy(75,100,"THANK YOU FOR PLAYING");
		delay(500);
		setcolor(CYAN);
		settextstyle(7,0,3);
		outtextxy(200,250,"PROJECT BY");
		outtextxy(200,300,"PRAJAKTA SHINDE");
		outtextxy(200,350,"HIRAL SHAH");
		outtextxy(200,400,"ABHIJIT CHAUDHARI");
		delay(2000);
	}
}
int show(int i)
{
	int k,x;
	x=150;
	k=2*(i-1)*15;
	x=x+k;
	return x;
}
void movies()
{
	int i,j,n;
	char a[10][11]={{'T','H','E',' ','S','M','U','R','F','S','*'},{'I','N','C','E','P','T','I','O','N','*','*'},{'I','S','H','Q','H','I','Y','A','*','*','*'},{'N','E','W',' ','Y','O','R','K','*','*','*'},{'N','E','H','A',' ','D','H','U','P','I','A'},{'A','M','Y',' ','J','A','C','K','S','O','N'},{'T','O','M',' ','C','R','U','I','S','E','*'},{'H','E','L','E','N','*','*','*','*','*','*'},{'K','I','T','E','S','*','*','*','*','*','*'},{'R','A','G','I','N','I',' ','M','M','S','*'}};
	randomize();
	n=random(10);
	for(i=0;i<11;i++)
		b[i]=a[n][i];
	dash();
}
void sports()
{
	int i,j,n;
	char a[10][11]={{'K','A','P','I','L',' ','D','E','V','*','*'},{'A','T','H','L','E','T','I','C','S','*','*'},{'K','A','B','A','D','D','I','*','*','*','*'},{'H','O','C','K','E','Y','*','*','*','*','*'},{'B','R','I','A','N',' ','L','A','R','A','*'},{'C','H','E','L','S','E','A','*','*','*','*'},{'R','U','G','B','Y','*','*','*','*','*','*'},{'B','J','O','R','N',' ','B','O','R','G','*'},{'U','S','A','I','N',' ','B','O','L','T','*'},{'M','A','R','K',' ','W','E','B','B','E','R'}};
	randomize();
	n=random(10);
	for(i=0;i<11;i++)
		b[i]=a[n][i];
	dash();
}
void countries()
{
	int i,j,n;
	char a[10][11]={{'M','A','U','R','I','T','A','N','I','A','*'},{'U','K','R','A','I','N','E','*','*','*','*'},{'B','O','L','I','V','I','A','*','*','*','*'},{'M','A','L','D','I','V','E','S','*','*','*'},{'S','I','N','G','A','P','O','R','E','*','*'},{'P','O','R','T','U','G','A','L','*','*','*'},{'B','E','L','G','I','U','M','*','*','*','*'},{'C','A','L','I','F','O','R','N','I','A','*'},{'A','R','G','E','N','T','I','N','A','*','*'},{'B','R','A','Z','I','L','*','*','*','*','*'}};
	randomize();
	n=random(10);
	for(i=0;i<11;i++)
		b[i]=a[n][i];
	dash();
}
void dash()
{
	int i,x,y,k;
	x=150;
	y=100;
	k=15;
	d=0;
	setcolor(YELLOW);
	for(i=0;i<11;i++)
	{
		if(b[i]!='*')
		{
			if(b[i]!=' ')
			{
				d++;
				line(x,y,x+k,y);
				line(x,y+1,x+k,y+1);
			}
		}
		else
			break;
		x=x+2*k;
	}
}
void hangman(int ch)
{
	setcolor(YELLOW);
	switch(ch)
	{
		case 1:	circle(450,200,20);
			circle(450,200,21);
			circle(443,192,1);
			circle(457,192,1);
			line(443,210,457,210); //mouth
			break;
		case 2:	line(450,220,450,300); //body
			line(451,220,451,300);
			break;
		case 3:	line(450,240,430,255);  //hand1
			line(451,240,431,255);
			break;
		case 4:	line(450,240,470,255); //hand2
			line(451,240,471,255);
			break;
		case 5: line(450,300,430,315); //leg1
			line(451,300,431,315);
			break;
		case 6: line(450,300,470,315); //leg2
			line(451,300,471,315);
			delay(500);
			line(450,180,450,150); //hang
			line(451,180,451,150);
			line(450,150,530,150);
			line(450,149,530,149);
			line(530,150,530,350);
			line(531,150,531,350);
			line(420,350,530,350);
			line(420,351,530,351);
			setcolor(BLUE);          //sad  face
			circle(443,192,1);
			circle(457,192,1);
			line(443,210,457,210);
			setcolor(YELLOW);
			outtextxy(440,187,"*");
			outtextxy(457,187,"*");
			arc(450,215,0,180,7);
			break;
	}
}



