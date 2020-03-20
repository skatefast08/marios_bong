#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <WinUser.h>
#include <thread>
#include <stdlib.h>
#include <vector>

#pragma comment(lib, "Winmm.lib")

void mypixel(HDC mariodc, int a, int b, COLORREF color);
void mario(HDC mariodc, int a, int b, int x, int y, int s, int t, int step);
void move_mario(HDC mariodc, int a, int b, int x, int y, int s, int step);
void move_sound();
void bong(HDC mariodc, int a, int b, int x, int y, int bs);
void bongpixel(HDC bongdc, int c, int d, COLORREF color);
void red_eyes(HDC mariodc, int a, int b, int x, int y, int s);
void normal_eyes(HDC mariodc, int a, int b, int x, int y, int s);
void right_shoe(HDC mariodc, int a, int b, int x, int y, int s);
void left_shoe(HDC mariodc, int a, int b, int x, int y, int s);
void right_shoe_up(HDC mariodc, int a, int b, int x, int y, int s);
void left_shoe_up(HDC mariodc, int a, int b, int x, int y, int s);


using namespace std;

int bs = 2;
int s = 3;
int spaces = s * 20;

int bongx = 100;
int bongy = 100;

int t = 0;

int main()
{
	
	//Get a console handle
	HWND marioconsole = GetConsoleWindow();
	//Get a handle to device context
	HDC mariodc = GetDC(marioconsole);

	HWND bongconsole = GetConsoleWindow();
	//Get a handle to device context
	HDC bongdc = GetDC(bongconsole);

	int b = s * 2;
	int a = s * 12;
	int x = s * 12;
	int y = s * 2;
	int c = s * 2;
	int d = s * 50;
	int step = 1;


	thread first(move_mario, mariodc, a, b, x, y, s, step);
	thread second(bong, bongdc, c, d, x, y, bs);

    first.join();
	second.join();
	

}

void move_sound()
{
	waveOutSetVolume(NULL, 0x1500);
	PlaySound("C:\\WINDOWS\\MEDIA\\smb_stomp.wav", NULL, SND_SYNC);


}

void mypixel(HDC mariodc, int a, int b, COLORREF color)
{

	for (int i = 0; i <= s; i++)
	{
		for (int j = 0; j <= s; j++)
		{
			SetPixel(mariodc, a + j, b + i, color);
		}
	}
}

void bongpixel(HDC bongdc, int c, int d, COLORREF color)
{

	for (int i = 0; i <= bs; i++)
	{
		for (int j = 0; j <= bs; j++)
		{
			SetPixel(bongdc, c + j, d + i, color);
		}
	}
}

void move_mario(HDC mariodc, int a, int b, int x, int y, int s, int step)
{
	cout << "            Mario has been very stressed out today" << endl;
	cout << "            can you please help him find his bong to smoke some mario kush?" << endl;
	cout << "            Press any key to continue" << endl;
	cout << endl;
	cout << "            i = up, k = down, l = right, j = left" << endl;
	mario(mariodc, a, b, x, y, s, t, step);
	_getch();
	system("CLS");

	char l = 'l';
	char k = 'k';
	char j = 'j';
	char i = 'i';

	while (1)
	{
		
		mario(mariodc, a, b, x, y, s, t, step);

		while (_getch() == l)
		{
			
			

			/*cout << "x = " << x << ", y = " << y << endl;
			Sleep(1000);*/

			move_sound();

			x = x + spaces;

		
			if (x == 156 && y == 186)
			{
				t = 1;
				waveOutSetVolume(NULL, 0xFFFF);
				PlaySound("C:\\WINDOWS\\MEDIA\\bong_hit.wav", NULL, SND_SYNC);
				x = x - spaces;
				mario(mariodc, a, b, x, y, s, t, step);
				cout << " ahhh yes! I am feelin pretty good!" << endl;
				Sleep(5000);
			}

			
			system("CLS");
			t = 0;
			mario(mariodc, a, b, x, y, s, t, step);

			step++;

		}



		while (_getch() == j)
		{

			move_sound();

			x = x - spaces;

			if (x == 156 && y == 186)
			{
				t = 1;
				waveOutSetVolume(NULL, 0xFFFF);
				PlaySound("C:\\WINDOWS\\MEDIA\\bong_hit.wav", NULL, SND_SYNC);
				x = x + spaces;
				mario(mariodc, a, b, x, y, s, t, step);
				cout << " ahhh yes! I am feelin pretty good!" << endl;
				Sleep(5000);
			}

			system("CLS");
			t = 0;
			mario(mariodc, a, b, x, y, s, t, step);

			step--;
		}

		while (_getch() == k)
		{
			/*cout << "x = " << x << ", y = " << y << endl;
			Sleep(1000);*/

			move_sound();

			y = y + spaces;

			if (x == 156 && y == 186)
			{
				t = 1;
				waveOutSetVolume(NULL, 0xFFFF);
				PlaySound("C:\\WINDOWS\\MEDIA\\bong_hit.wav", NULL, SND_SYNC);
				y = y - spaces;
				mario(mariodc, a, b, x, y, s, t, step);
				cout << " ahhh yes! I am feelin pretty good!" << endl;
				Sleep(5000);
			}

			system("CLS");
			t = 0;
			mario(mariodc, a, b, x, y, s, t, step);

			step++;
		}

		while (_getch() == i)
		{

			move_sound();

			y = y - spaces;

			if (x == 156 && y == 186)
			{
				t = 1;
				waveOutSetVolume(NULL, 0xFFFF);
				PlaySound("C:\\WINDOWS\\MEDIA\\bong_hit.wav", NULL, SND_SYNC);
				y = y + spaces;
				mario(mariodc, a, b, x, y, s, t, step);
				cout << " ahhh yes! I am feelin pretty good!" << endl;
				Sleep(5000);
			}

			system("CLS");
			t = 0;
			mario(mariodc, a, b, x, y, s, t, step);

			step--;
		}

	}
}

void bong(HDC bongdc, int c, int d, int x, int y, int bs)
{
	while(1)
	{ 
	COLORREF RED = RGB(255, 0, 0);
	COLORREF DRED = RGB(200, 0, 0);
	COLORREF VDRED = RGB(150, 0, 0);
	COLORREF PEACH = RGB(255, 100, 100);
	COLORREF LPEACH = RGB(255, 200, 150);
	COLORREF DBLUE = RGB(0, 0, 170);
	COLORREF BLUE = RGB(0, 100, 255);
	COLORREF LBLUE = RGB(0, 200, 255);
	COLORREF WHITE = RGB(255, 255, 255);
	COLORREF YELLOW = RGB(255, 255, 0);
	COLORREF GRAY = RGB(100, 100, 100);
	COLORREF GREEN = RGB(0, 255, 0);

// top 
	c = bs * (bongx + 1);
	d = bs * (bongy + 4);
	bongpixel(bongdc, c, d, GRAY);

	c = bs * bongx;
	d = bs * (bongy + 5);
	bongpixel(bongdc, c, d, GRAY);

	for (int i = bongx + 1; i < bongx + 8; i++)
	{
		c = bs * i;
		d = bs * (bongy + 6);
		bongpixel(bongdc, c, d, GRAY);
	}
	
	c = bs * (bongx + 8);
	d = bs * (bongy + 5);
	bongpixel(bongdc, c, d, GRAY);

	for (int i = bongx + 1; i < bongx + 8; i++)
	{
		c = bs * i;
		d = bs * (bongy + 4);
		bongpixel(bongdc, c, d, GRAY);
	}

	//neck

	for (int i = 6; i < 25; i++)
	{
		c = bs * bongx;
		d = bs * (bongy + i);
		bongpixel(bongdc, c, d, GRAY);
	}
	
	for (int i = 6; i < 25; i++)
	{
		c = bs * (bongx + 8);
		d = bs * (bongy + i);
		bongpixel(bongdc, c, d, GRAY);
	}

// pot

	for (int i = 9; i < 13; i++)
	{
		c = bs * (bongx + i);
		d = bs * (bongy + (16 + i));
		bongpixel(bongdc, c, d, GRAY);
	}

	for (int i = 13; i < 19; i++)
	{
		c = bs * (bongx + 12);
		d = bs * (bongy + (16 + i));
		bongpixel(bongdc, c, d, GRAY);
	}

	for (int i = 0; i < 3; i++)
	{
		c = bs * (bongx + 11 - i);
		d = bs * (bongy + 35 + i);
		bongpixel(bongdc, c, d, GRAY);
	}

	for (int i = 3; i < 11; i++)
	{
		c = bs * (bongx + 11 - i);
		d = bs * (bongy + 38);
		bongpixel(bongdc, c, d, GRAY);
	}

	for (int i = 1; i < 5; i++)
	{
		c = bs * (bongx - i);
		d = bs * (bongy + (24 + i));
		bongpixel(bongdc, c, d, GRAY);
	}

	for (int i = 1; i < 6; i++)
	{
		c = bs * (bongx - 4);
		d = bs * (bongy + (28 + i));
		bongpixel(bongdc, c, d, GRAY);
	}

	for (int i = 0; i < 5; i++)
	{
		c = bs * (bongx - (4 - i));
		d = bs * (bongy + (34 + i));
		bongpixel(bongdc, c, d, GRAY);
	}

	// bowl pipe


	for (int i = -9; i < 7; i++)
	{
		c = bs * (bongx + 12 + i);
		d = bs * (bongy + 27 - i);
		bongpixel(bongdc, c, d, GRAY);
	}

	for (int i = -9; i < 7; i++)
	{
		c = bs * (bongx + 10 + i);
		d = bs * (bongy + 25 - i);
		bongpixel(bongdc, c, d, GRAY);
	}

	// bowl

	c = bs * (bongx + 19);
	d = bs * (bongy + 21);
	bongpixel(bongdc, c, d, GRAY);

	c = bs * (bongx + 20);
	d = bs * (bongy + 21);
	bongpixel(bongdc, c, d, GRAY);

	c = bs * (bongx + 21);
	d = bs * (bongy + 20);
	bongpixel(bongdc, c, d, GRAY);

	c = bs * (bongx + 16);
	d = bs * (bongy + 18);
	bongpixel(bongdc, c, d, GRAY);

	c = bs * (bongx + 16);
	d = bs * (bongy + 19);
	bongpixel(bongdc, c, d, GRAY);

	c = bs * (bongx + 16);
	d = bs * (bongy + 18);
	bongpixel(bongdc, c, d, GRAY);

	c = bs * (bongx + 17);
	d = bs * (bongy + 17);
	bongpixel(bongdc, c, d, GRAY);

	//weed

	c = bs * (bongx + 18);
	d = bs * (bongy + 18);
	bongpixel(bongdc, c, d, GREEN);

	c = bs * (bongx + 19);
	d = bs * (bongy + 19);
	bongpixel(bongdc, c, d, GREEN);

	c = bs * (bongx + 19);
	d = bs * (bongy + 18);
	bongpixel(bongdc, c, d, GREEN);

  }
	
}

void mario(HDC mariodc, int a, int b, int x, int y, int s, int t, int step)
{
	COLORREF RED = RGB(255, 0, 0);
	COLORREF DRED = RGB(200, 0, 0);
	COLORREF VDRED = RGB(150, 0, 0);
	COLORREF PEACH = RGB(255, 100, 100);
	COLORREF LPEACH = RGB(255, 200, 150);
	COLORREF DBLUE = RGB(0, 0, 170);
	COLORREF BLUE = RGB(0, 100, 255);
	COLORREF LBLUE = RGB(0, 200, 255);
	COLORREF WHITE = RGB(255, 255, 255);
	COLORREF YELLOW = RGB(255, 255, 0);
	COLORREF GRAY = RGB(100, 100, 100);

	for (int i = s; i <= s * 4; i += s)
	{
		b = y + s * 2;
		a = x + i;
		mypixel(mariodc, a, b, VDRED);
	}

	b = y + s * 3;
	a = x - s * 4;
	mypixel(mariodc, a, b, WHITE);

	b = y + s * 3;
	a = x - s;
	mypixel(mariodc, a, b, VDRED);

	b = y + s * 3;
	a = x;
	mypixel(mariodc, a, b, RED);

	b = y + s * 3;
	a = x + s;
	mypixel(mariodc, a, b, GRAY);

	b = y + s * 3;
	a = x + s * 2;
	mypixel(mariodc, a, b, YELLOW);

	b = y + s * 3;
	a = x + s * 3;
	mypixel(mariodc, a, b, RED);

	b = y + s * 3;
	a = x + s * 4;
	mypixel(mariodc, a, b, VDRED);

	b = y + s * 3;
	a = x + s * 5;
	mypixel(mariodc, a, b, VDRED);

	b = y + s * 3;
	a = x + s * 6;
	mypixel(mariodc, a, b, VDRED);

	b = y + s * 4;
	a = x - s * 5;
	mypixel(mariodc, a, b, WHITE);

	b = y + s * 4;
	a = x - s * 3;
	mypixel(mariodc, a, b, WHITE);

	b = y + s * 4;
	a = x - s;
	mypixel(mariodc, a, b, RED);

	b = y + s * 4;
	a = x;
	mypixel(mariodc, a, b, GRAY);

	b = y + s * 4;
	a = x + s;
	mypixel(mariodc, a, b, WHITE);

	b = y + s * 4;
	a = x + s * 2;
	mypixel(mariodc, a, b, WHITE);

	b = y + s * 4;
	a = x + s * 3;
	mypixel(mariodc, a, b, GRAY);

	b = y + s * 4;
	a = x + s * 4;
	mypixel(mariodc, a, b, RED);

	b = y + s * 4;
	a = x + s * 5;
	mypixel(mariodc, a, b, RED);

	b = y + s * 4;
	a = x + s * 6;
	mypixel(mariodc, a, b, VDRED);

	b = y + s * 5;
	a = x + s * 6;
	mypixel(mariodc, a, b, DRED);

	b = y + s * 5;
	a = x + s * 5;
	mypixel(mariodc, a, b, RED);

	b = y + s * 5;
	a = x - s * 3;
	mypixel(mariodc, a, b, WHITE);

	b = y + s * 5;
	a = x - s * 4;
	mypixel(mariodc, a, b, WHITE);

	b = y + s * 6;
	a = x + s * 6;
	mypixel(mariodc, a, b, DRED);

	b = y + s * 5;
	a = x + s * 7;
	mypixel(mariodc, a, b, VDRED);

	b = y + s * 6;
	a = x + s * 7;
	mypixel(mariodc, a, b, VDRED);

	b = y + s * 7;
	a = x + s * 7;
	mypixel(mariodc, a, b, VDRED);

	b = y + s * 8;
	a = x + s * 7;
	mypixel(mariodc, a, b, VDRED);

	b = y + s * 8;
	a = x + s * 2;
	mypixel(mariodc, a, b, PEACH);

	b = y + s * 8;
	a = x + s;
	mypixel(mariodc, a, b, PEACH);

	for (int i = y + s * 9; i <= y + s * 11; i += s)
	{
		b = i;
		a = x + s;
		mypixel(mariodc, a, b, LPEACH);
	}

	for (int i = y + s * 9; i <= y + s * 11; i += s)
	{
		b = i;
		a = x + s * 2;
		mypixel(mariodc, a, b, LPEACH);
	}

	b = y + s * 11;
	a = x + s * 3;
	mypixel(mariodc, a, b, LPEACH);

	b = y + s * 11;
	a = x;
	mypixel(mariodc, a, b, LPEACH);

	b = y + s * 11;
	a = x - s;
	mypixel(mariodc, a, b, PEACH);

	b = y + s * 11;
	a = x - s * 2;
	mypixel(mariodc, a, b, LPEACH);

	for (int i = 0; i <= s * 3; i += s)
	{
		b = y + s * 12;
		a = x + i;
		mypixel(mariodc, a, b, PEACH);
	}

	for (int i = s * 12; i <= s * 13; i += s)
	{
		b = y + i;
		a = x + s * 6;
		mypixel(mariodc, a, b, LPEACH);
	}

	b = y + s * 14;
	a = x + s * 5;
	mypixel(mariodc, a, b, LPEACH);

	for (int i = s * 9; i <= s * 11; i += s)
	{
		b = y + i;
		a = x + s * 5;
		mypixel(mariodc, a, b, LPEACH);
	}

	b = y + s * 10;
	a = x + s * 6;
	mypixel(mariodc, a, b, LPEACH);

	b = y + s * 9;
	a = x + s * 6;
	mypixel(mariodc, a, b, PEACH);

	for (int i = -s; i <= s * 3; i += s)
	{
		b = y + s * 15;
		a = x + i;
		mypixel(mariodc, a, b, PEACH);
	}

	b = y + s * 14;
	a = x - s * 2;
	mypixel(mariodc, a, b, LPEACH);

	b = y + s * 11;
	a = x + s * 4;
	mypixel(mariodc, a, b, PEACH);
	// scarf
	for (int i = -s * 2; i <= s * 3; i += s)
	{
		b = y + s * 16;
		a = x + i;
		mypixel(mariodc, a, b, GRAY);
	}

	for (int i = s * 4; i <= s * 5; i += s)
	{
		b = y + s * 15;
		a = x + i;
		mypixel(mariodc, a, b, GRAY);
	}

	b = y + s * 14;
	a = x + s * 6;
	mypixel(mariodc, a, b, GRAY);

	b = y + s * 13;
	a = x + s * 7;
	mypixel(mariodc, a, b, GRAY);
	//ear
	for (int i = s * 9; i <= s * 12; i += s)
	{
		b = y + i;
		a = x + s * 8;
		mypixel(mariodc, a, b, PEACH);
	}
	// right arm
	for (int i = s * 3; i <= s * 6; i += s)
	{
		b = y + s * 11;
		a = x - i;
		mypixel(mariodc, a, b, VDRED);
	}

	for (int i = y + s * 12; i <= y + s * 14; i += s)
	{
		b = i;
		a = x - s * 3;
		mypixel(mariodc, a, b, VDRED);
	}

	for (int i = y + s * 15; i <= y + s * 16; i += s)
	{
		b = i;
		a = x - s * 3;
		mypixel(mariodc, a, b, DRED);
	}

	b = y + s * 15;
	a = x - s * 2;
	mypixel(mariodc, a, b, VDRED);

	for (int i = y + s * 17; i <= y + s * 18; i += s)
	{
		b = i;
		a = x - s * 3;
		mypixel(mariodc, a, b, RED);
	}

	for (int i = y + s * 17; i <= y + s * 18; i += s)
	{
		b = i;
		a = x - s * 2;
		mypixel(mariodc, a, b, RED);
	}

	for (int i = y + s * 12; i <= y + s * 15; i += s)
	{
		b = i;
		a = x - s * 6;
		mypixel(mariodc, a, b, VDRED);
	}

	for (int i = y + s * 12; i <= y + s * 15; i += s)
	{
		b = i;
		a = x - s * 5;
		mypixel(mariodc, a, b, RED);
	}

	for (int i = y + s * 16; i <= y + s * 18; i += s)
	{
		b = i;
		a = x - s * 5;
		mypixel(mariodc, a, b, VDRED);
	}

	for (int i = y + s * 12; i <= y + s * 15; i += s)
	{
		b = i;
		a = x - s * 4;
		mypixel(mariodc, a, b, DRED);
	}

	for (int i = y + s * 16; i <= y + s * 17; i += s)
	{
		b = i;
		a = x - s * 4;
		mypixel(mariodc, a, b, RED);
	}

	for (int i = y + s * 18; i <= y + s * 19; i += s)
	{
		b = i;
		a = x - s * 4;
		mypixel(mariodc, a, b, DRED);
	}

	// blue pants

	for (int i = y + s * 20; i <= y + s * 22; i += s)
	{
		b = i;
		a = x - s * 4;
		mypixel(mariodc, a, b, DBLUE);
	}

	for (int i = y + s * 23; i <= y + s * 24; i += s)
	{
		b = i;
		a = x - s * 4;
		mypixel(mariodc, a, b, BLUE);
	}

	for (int i = s * 3; i <= s * 5; i += s)
	{
		b = y + s * 24;
		a = x - i;
		mypixel(mariodc, a, b, BLUE);
	}

	for (int i = y + s * 20; i <= y + s * 23; i += s)
	{
		b = i;
		a = x - s * 3;
		mypixel(mariodc, a, b, LBLUE);
	}

	for (int i = y + s * 23; i <= y + s * 26; i += s)
	{
		b = i;
		a = x - s * 5;
		mypixel(mariodc, a, b, DBLUE);
	}

	for (int i = s * 2; i <= s * 4; i += s)
	{
		b = y + s * 26;
		a = x - i;
		mypixel(mariodc, a, b, DBLUE);
	}

	b = y + s * 24;
	a = x - s;
	mypixel(mariodc, a, b, DBLUE);

	for (int i = 0; i <= s * 3; i += s)
	{
		b = y + s * 23;
		a = x + i;
		mypixel(mariodc, a, b, DBLUE);
	}

	for (int i = s * 24; i <= s * 26; i += s)
	{
		b = y + i;
		a = x + s * 3;
		mypixel(mariodc, a, b, DBLUE);
	}

	for (int i = s * 4; i <= s * 7; i += s)
	{
		b = y + s * 26;
		a = x + i;
		mypixel(mariodc, a, b, DBLUE);
	}

	for (int i = s * 23; i <= s * 26; i += s)
	{
		b = y + i;
		a = x + s * 7;
		mypixel(mariodc, a, b, DBLUE);
	}

	for (int i = s * 20; i <= s * 22; i += s)
	{
		b = y + i;
		a = x + s * 6;
		mypixel(mariodc, a, b, DBLUE);
	}

	for (int i = y + s * 23; i <= y + s * 24; i += s)
	{
		b = i;
		a = x + s * 6;
		mypixel(mariodc, a, b, BLUE);
	}

	for (int i = s * 4; i <= s * 5; i += s)
	{
		b = y + s * 25;
		a = x + i;
		mypixel(mariodc, a, b, BLUE);
	}

	b = y + s * 24;
	a = x - s;
	mypixel(mariodc, a, b, BLUE);

	b = y + s * 23;
	a = x - s * 2;
	mypixel(mariodc, a, b, BLUE);

	b = y + s * 23;
	a = x + s * 4;
	mypixel(mariodc, a, b, BLUE);

	b = y + s * 24;
	a = x + s * 5;
	mypixel(mariodc, a, b, LBLUE);

	b = y + s * 23;
	a = x + s * 5;
	mypixel(mariodc, a, b, LBLUE);

	b = y + s * 22;
	a = x + s * 5;
	mypixel(mariodc, a, b, BLUE);

	b = y + s * 22;
	a = x + s * 4;
	mypixel(mariodc, a, b, LBLUE);

	for (int i = -s * 3; i <= s * 4; i += s)
	{
		b = y + s * 23;
		a = x + i;
		mypixel(mariodc, a, b, LBLUE);
	}

	for (int i = -s * 3; i <= -s * 2; i += s)
	{
		b = y + s * 23;
		a = x + i;
		mypixel(mariodc, a, b, LBLUE);
	}

	for (int i = -s * 3; i <= s * 3; i += s)
	{
		b = y + s * 22;
		a = x + i;
		mypixel(mariodc, a, b, LBLUE);
	}

	for (int i = -s * 3; i <= s * 3; i += s)
	{
		b = y + s * 22;
		a = x + i;
		mypixel(mariodc, a, b, LBLUE);
	}

	for (int i = -s * 2; i <= s; i += s)
	{
		b = y + s * 21;
		a = x + i;
		mypixel(mariodc, a, b, WHITE);
	}

	for (int i = 0; i <= s * 3; i += s)
	{
		b = y + s * 21;
		a = x + i;
		mypixel(mariodc, a, b, LBLUE);
	}

	for (int i = s * 4; i <= s * 5; i += s)
	{
		b = y + s * 21;
		a = x + i;
		mypixel(mariodc, a, b, WHITE);
	}

	for (int i = -s * 2; i <= -s; i += s)
	{
		b = y + s * 20;
		a = x + i;
		mypixel(mariodc, a, b, WHITE);
	}

	for (int i = 0; i <= s * 3; i += s)
	{
		b = y + s * 20;
		a = x + i;
		mypixel(mariodc, a, b, LBLUE);
	}

	for (int i = s * 4; i <= s * 5; i += s)
	{
		b = y + s * 20;
		a = x + i;
		mypixel(mariodc, a, b, WHITE);
	}

	for (int i = -s; i <= s * 4; i += s)
	{
		b = y + s * 19;
		a = x + i;
		mypixel(mariodc, a, b, LBLUE);
	}

	b = y + s * 19;
	a = x + s * 4;
	mypixel(mariodc, a, b, BLUE);

	b = y + s * 18;
	a = x + s * 5;
	mypixel(mariodc, a, b, DRED);

	b = y + s * 19;
	a = x + s * 5;
	mypixel(mariodc, a, b, BLUE);

	b = y + s * 18;
	a = x + s * 5;
	mypixel(mariodc, a, b, DRED);

	b = y + s * 17;
	a = x + s * 5;
	mypixel(mariodc, a, b, RED);

	b = y + s * 17;
	a = x + s * 6;
	mypixel(mariodc, a, b, VDRED);

	b = y + s * 16;
	a = x + s * 5;
	mypixel(mariodc, a, b, VDRED);

	b = y + s * 16;
	a = x + s * 4;
	mypixel(mariodc, a, b, RED);

	b = y + s * 17;
	a = x + s * 3;
	mypixel(mariodc, a, b, BLUE);

	b = y + s * 17;
	a = x;
	mypixel(mariodc, a, b, BLUE);

	b = y + s * 17;
	a = x - s;
	mypixel(mariodc, a, b, BLUE);

	b = y + s * 18;
	a = x - s;
	mypixel(mariodc, a, b, BLUE);

	b = y + s * 17;
	a = x + s * 4;
	mypixel(mariodc, a, b, BLUE);

	b = y + s * 18;
	a = x + s * 4;
	mypixel(mariodc, a, b, BLUE);

	b = y + s * 19;
	a = x + s * 6;
	mypixel(mariodc, a, b, WHITE);

	b = y + s * 19;
	a = x + s * 7;
	mypixel(mariodc, a, b, WHITE);

	b = y + s * 20;
	a = x + s * 7;
	mypixel(mariodc, a, b, WHITE);

	b = y + s * 21;
	a = x + s * 7;
	mypixel(mariodc, a, b, WHITE);

	b = y + s * 19;
	a = x - s * 2;
	mypixel(mariodc, a, b, BLUE);

	for (int i = s; i <= s * 2; i += s)
	{
		b = y + s * 18;
		a = x + i;
		mypixel(mariodc, a, b, VDRED);
	}

	b = y + s * 18;
	a = x + s * 3;
	mypixel(mariodc, a, b, LBLUE);

	b = y + s * 18;
	a = x;
	mypixel(mariodc, a, b, LBLUE);

	b = y + s * 18;
	a = x - s;
	mypixel(mariodc, a, b, BLUE);

	for (int i = s; i <= s * 2; i += s)
	{
		b = y + s * 17;
		a = x + i;
		mypixel(mariodc, a, b, DRED);
	}

	b = y + s * 19;
	a = x - s * 2;
	mypixel(mariodc, a, b, BLUE);

	b = y + s * 19;
	a = x - s * 3;
	mypixel(mariodc, a, b, DBLUE);

	// right shoe

	if (step % 2 == 0)
	{
		right_shoe(mariodc, a, b, x, y, s);
		left_shoe_up(mariodc, a, b, x, y, s);
		
	}

	// left shoe
	else if (step % 2 != 0)
	{
		left_shoe(mariodc, a, b, x, y, s);
		right_shoe_up(mariodc, a, b, x, y, s);
	}
	// right glove

	for (int i = y + s * 8; i <= y + s * 10; i += s)
	{
		b = i;
		a = x - s * 3;
		mypixel(mariodc, a, b, WHITE);
	}

	b = y + s * 8;
	a = x - s * 4;
	mypixel(mariodc, a, b, WHITE);

	b = y + s * 8;
	a = x - s * 6;
	mypixel(mariodc, a, b, WHITE);

	for (int i = s * 3; i <= s * 6; i += s)
	{
		b = y + s * 7;
		a = x - i;
		mypixel(mariodc, a, b, WHITE);
	}

//eyes

	for (int i = s * 3; i <= s * 6; i += s)
	{
		b = y + s * 10;
		a = x - i;
		mypixel(mariodc, a, b, WHITE);
	}

	if (t == 1)
	{
		red_eyes(mariodc, a, b, x, y, s);
	}
	else if (t != 1)
	{
		normal_eyes(mariodc, a, b, x, y, s);
	}

	b = y + s * 24;
	a = x - s * 2;
	mypixel(mariodc, a, b, BLUE);
}

void right_shoe_up(HDC mariodc, int a, int b, int x, int y, int s)
{
	COLORREF RED = RGB(255, 0, 0);
	COLORREF DRED = RGB(200, 0, 0);
	COLORREF VDRED = RGB(150, 0, 0);
	COLORREF PEACH = RGB(255, 100, 100);
	COLORREF LPEACH = RGB(255, 200, 150);
	COLORREF DBLUE = RGB(0, 0, 170);
	COLORREF BLUE = RGB(0, 100, 255);
	COLORREF LBLUE = RGB(0, 200, 255);
	COLORREF WHITE = RGB(255, 255, 255);
	COLORREF YELLOW = RGB(255, 255, 0);
	COLORREF GRAY = RGB(100, 100, 100);

	for (int i = s * 3; i <= s * 6; i += s)
	{
		b = y + s * 27;
		a = x - i;
		mypixel(mariodc, a, b, GRAY);
	}
}

void right_shoe(HDC mariodc, int a, int b, int x, int y, int s)
{
	COLORREF RED = RGB(255, 0, 0);
	COLORREF DRED = RGB(200, 0, 0);
	COLORREF VDRED = RGB(150, 0, 0);
	COLORREF PEACH = RGB(255, 100, 100);
	COLORREF LPEACH = RGB(255, 200, 150);
	COLORREF DBLUE = RGB(0, 0, 170);
	COLORREF BLUE = RGB(0, 100, 255);
	COLORREF LBLUE = RGB(0, 200, 255);
	COLORREF WHITE = RGB(255, 255, 255);
	COLORREF YELLOW = RGB(255, 255, 0);
	COLORREF GRAY = RGB(100, 100, 100);

	for (int i = s * 3; i <= s * 5; i += s)
	{
		b = y + s * 27;
		a = x - i;
		mypixel(mariodc, a, b, GRAY);
	}

	for (int i = s * 3; i <= s * 6; i += s)
	{
		b = y + s * 28;
		a = x - i;
		mypixel(mariodc, a, b, GRAY);
	}
}

void left_shoe_up(HDC mariodc, int a, int b, int x, int y, int s)
{
	COLORREF RED = RGB(255, 0, 0);
	COLORREF DRED = RGB(200, 0, 0);
	COLORREF VDRED = RGB(150, 0, 0);
	COLORREF PEACH = RGB(255, 100, 100);
	COLORREF LPEACH = RGB(255, 200, 150);
	COLORREF DBLUE = RGB(0, 0, 170);
	COLORREF BLUE = RGB(0, 100, 255);
	COLORREF LBLUE = RGB(0, 200, 255);
	COLORREF WHITE = RGB(255, 255, 255);
	COLORREF YELLOW = RGB(255, 255, 0);
	COLORREF GRAY = RGB(100, 100, 100);

	for (int i = s * 4; i <= s * 7; i += s)
	{
		b = y + s * 27;
		a = x + i;
		mypixel(mariodc, a, b, GRAY);
	}

}

void left_shoe(HDC mariodc, int a, int b, int x, int y, int s)
{
	COLORREF RED = RGB(255, 0, 0);
	COLORREF DRED = RGB(200, 0, 0);
	COLORREF VDRED = RGB(150, 0, 0);
	COLORREF PEACH = RGB(255, 100, 100);
	COLORREF LPEACH = RGB(255, 200, 150);
	COLORREF DBLUE = RGB(0, 0, 170);
	COLORREF BLUE = RGB(0, 100, 255);
	COLORREF LBLUE = RGB(0, 200, 255);
	COLORREF WHITE = RGB(255, 255, 255);
	COLORREF YELLOW = RGB(255, 255, 0);
	COLORREF GRAY = RGB(100, 100, 100);

	for (int i = s * 4; i <= s * 6; i += s)
	{
		b = y + s * 27;
		a = x + i;
		mypixel(mariodc, a, b, GRAY);
	}

	for (int i = s * 4; i <= s * 7; i += s)
	{
		b = y + s * 28;
		a = x + i;
		mypixel(mariodc, a, b, GRAY);
	}
}

void red_eyes(HDC mariodc, int a, int b, int x, int y, int s)
{
	COLORREF RED = RGB(255, 0, 0);
	COLORREF DRED = RGB(200, 0, 0);
	COLORREF VDRED = RGB(150, 0, 0);
	COLORREF PEACH = RGB(255, 100, 100);
	COLORREF LPEACH = RGB(255, 200, 150);
	COLORREF DBLUE = RGB(0, 0, 170);
	COLORREF BLUE = RGB(0, 100, 255);
	COLORREF LBLUE = RGB(0, 200, 255);
	COLORREF WHITE = RGB(255, 255, 255);
	COLORREF YELLOW = RGB(255, 255, 0);
	COLORREF GRAY = RGB(100, 100, 100);

	for (int i = s * 3; i <= s * 6; i += s)
	{
		b = y + s * 10;
		a = x - i;
		mypixel(mariodc, a, b, RED);
	}

	b = y + s * 9;
	a = x + s * 4;
	mypixel(mariodc, a, b, RED);

	b = y + s * 10;
	a = x + s * 4;
	mypixel(mariodc, a, b, RED);

	b = y + s * 8;
	a = x;
	mypixel(mariodc, a, b, RED);

    b = y + s * 8;
    a = x + s * 4;
    mypixel(mariodc, a, b, RED);

    b = y + s * 8;
    a = x + s * 3;
    mypixel(mariodc, a, b, RED);
}

void normal_eyes(HDC mariodc, int a, int b, int x, int y, int s)
{
	COLORREF RED = RGB(255, 0, 0);
	COLORREF DRED = RGB(200, 0, 0);
	COLORREF VDRED = RGB(150, 0, 0);
	COLORREF PEACH = RGB(255, 100, 100);
	COLORREF LPEACH = RGB(255, 200, 150);
	COLORREF DBLUE = RGB(0, 0, 170);
	COLORREF BLUE = RGB(0, 100, 255);
	COLORREF LBLUE = RGB(0, 200, 255);
	COLORREF WHITE = RGB(255, 255, 255);
	COLORREF YELLOW = RGB(255, 255, 0);
	COLORREF GRAY = RGB(100, 100, 100);

	b = y + s * 9;
	a = x + s * 4;
	mypixel(mariodc, a, b, WHITE);

	b = y + s * 10;
	a = x + s * 4;
	mypixel(mariodc, a, b, WHITE);

	b = y + s * 8;
	a = x;
	mypixel(mariodc, a, b, WHITE);

	for (int i = y + s * 8; i <= y + s * 10; i += s)
	{
		b = i;
		a = x - s;
		mypixel(mariodc, a, b, WHITE);
	}

	b = y + s * 8;
	a = x + s * 4;
	mypixel(mariodc, a, b, WHITE);

	b = y + s * 8;
	a = x + s * 3;
	mypixel(mariodc, a, b, WHITE);
}

