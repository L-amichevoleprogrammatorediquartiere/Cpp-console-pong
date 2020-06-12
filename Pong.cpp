#include <windows.h>
#include <iostream>

using namespace std;

void gotoxy(short x, short y) 
{
	COORD pos = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
bool controll(int player,int x,int y,int choice)
{
	bool pass=false;
	switch (choice)
	{
		case 0:
			if (x==4)
			{
				for (int i=0;i<=4;i++)
				{
					if (player+i==y)
					{
						pass=true;
					}
				}
			}
			break;
		case 1:
			if (x==76)
			{
				for (int i=0;i<=4;i++)
				{
					if (player+i==y)
					{
						pass=true;
					}
				}
			}
			break;
		gotoxy(0,0);
		cout<<player;
	}
	return pass;
}
main()
{
	SetConsoleTitle("Pong");
	int posx=39,posy=19,vx=-1,vy=-1,playery=13,player2=13,run2=0,point=0,pointcp=0;
	while (true)
	{
		gotoxy(30,0);
		cout<<"Player: "<<point<<"  "<<char(186)<<"   Cpu: "<<pointcp;
		gotoxy(0,0);
		cout<<posx;
		gotoxy(posx,posy);
		cout<<char(254);
		for (int i=0;i<=4;i++)
		{
			gotoxy(4,playery+i);
			cout<<char(219);
		}
		for (int i=0;i<=4;i++)
		{
			gotoxy(76,player2+i);
			cout<<char(219);
		}
		Sleep(60);
		gotoxy(posx,posy);
		cout<<" ";
		for (int i=0;i<=4;i++)
		{
			gotoxy(4,playery+i);
			cout<<" ";
		}
		for (int i=0;i<=4;i++)
		{
			gotoxy(76,player2+i);
			cout<<" ";
		}
		posx+=vx;
		posy+=vy;
		if(GetAsyncKeyState(VK_UP))
		{		
			if (playery>=2)
			{
				playery-=1;
			}
		}
		else if(GetAsyncKeyState(VK_DOWN))
		{
			if (playery<=19)
			{
				playery+=1;
			}
		}
		if (posx>69)
		{
			if (player2>posy)
			{ 
				if (player2>=2)
				{
					player2-=1;
				}
			}
			else if(player2<posy)
			{
				if (player2<=19)
				{
					player2+=1;
				}
			}
		}
		if ((posy>=25)||(posy<=0))
		{
			vy=-vy;
			posy+=vy;
		}
		else if((posx>=80)||(posx<=0)||(controll(playery,posx,posy,0))||(controll(player2,posx,posy,1)))
		{
			vx=-vx;
			posx+=vx;
		}
		if (posx==1)
		{
			posx=39;
			posy=19;
			pointcp++;
		}
		else if(posx>=79)
		{
			posx=39;
			posy=19;
			point++;
		}
		gotoxy(0,0);
		cout<<playery;
	}
}
