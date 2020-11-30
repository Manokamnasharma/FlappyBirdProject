#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>
#include<math.h>
    typedef struct diff {
	int r;
	struct diff *next;
    }
diff;

typedef struct scor {
    int sc;
    struct scor * next;
}
scor;

void circ(int x, int y, int r) {
	  if (y <= 0) {
	    y *= (-1);
	    y = y % 480;
	    y = 480 - y;
	  }
	   circle(x, y, r);
}

void pop(struct scor *stack)  {
    struct scor *temp;
    temp = stack;
    temp = temp -> next;
    stack = temp;
    free(temp);
}

void push(int score, struct scor * stack) {
    struct scor * temp;
    temp = (scor * ) malloc(sizeof(struct scor));
    temp -> sc = score;
    temp -> next = stack;
    stack = temp;
    free(temp);
}

int pillar_randomess(int r) {
	int m;
	while (r < 50) {
	    r = rand() % 110;
	}
	m = rand() % 2;
	return m % 2 == 0 ? r : -r;
}

void make_fish(int h) {
	    circle(325, 210 + h, 3);
	    arc(300, 230 + h, 30, 150, 40);
	    arc(300, 190 + h, 210, 330, 40);
	    arc(284, 210 + h, 340, 20, 25);
	    arc(279, 210 + h, 340, 20, 25);
	    arc(289, 210 + h, 340, 20, 25);
	    arc(240, 210 + h, 318, 45, 25);
	    line(258, 193 + h, 258, 227 + h);
	    setfillstyle(SOLID_FILL, GREEN);
	    floodfill(325, 210 + h, WHITE);
}

int is_going_to_collide(int i, int r, int h) {
	if ((i <= 334 && i >= 266) || ((i + 50) <= 334 && (i + 50) >= 266)) {
		if ((190 + h) <= (180 + r) || (230 + h) >= (180 + r + 120))
			return 1;
	}
	return 0;
}

void make_pillar(int i, int r, int colorpil) {
		setfillstyle(SOLID_FILL, colorpil);
		bar(i, 0, i + 50, 180 + r);
		setfillstyle(SOLID_FILL, colorpil);
		bar(i - 5, 170 + r, i + 55, 180 + r);

		rectangle(i, 0, i + 50, 170 + r);

		rectangle(i - 5, 170 + r, i + 55, 180 + r);

		setfillstyle(SOLID_FILL, colorpil);
		bar(i, 180 + r + 120, i + 50, 419);
		setfillstyle(SOLID_FILL, colorpil);
		bar(i - 5, 180 + r + 120, i + 55, 190 + r + 120);

		rectangle(i - 5, 180 + r + 120, i + 55, 190 + r + 120);

		rectangle(i, 190 + r + 120, i + 50, 419);
}

void make_bubbles(int hb) {
	setfillstyle(SOLID_FILL, WHITE);
	circ(40, 250 + hb, 10);
	circ(37, 203 + hb, 5);
	circ(130, 120 + hb, 12);
	circ(134, 200 + hb, 13);
	circ(225, 160 + hb, 9);
	circ(360, 200 + hb, 5);
	circ(317, 150 + hb, 7);
	circ(400, 120 + hb, 8);
	circ(415, 160 + hb, 10);
	circ(510, 120 + hb, 5);
	circ(510, 200 + hb, 5);
	circ(600, 160 + hb, 6);
	circ(490, 470 + hb, 6);
	circ(550, 420 + hb, 7);
	circ(40, 400 + hb, 6);
	circ(60, 450 + hb, 5);
	circ(270, 455 + hb, 6);
	circ(420, 400 + hb, 6);
	circ(360, 448 + hb, 8);
}
void main() {
    int i, j; // coordinates
    int c = 0; // score counter
    int f = 1; //  flap counter
    char ch = 'y';
    int t;
    int ht = 23;
    int hgt = 0;
    int color = 0;
    int colorpil = 4;
    int h, hb; /*   height and depth parameters */
    int l, k, m, r1, r2, r3;
    char msg[20];
    int score;
    int i1;

    FILE * fp;
    diff * rd, * temp1;
    scor * stack, * temp2;

    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TurboC3\\BGI");

    cleardevice();

    r1 = 0, r2 = 0, r3 = 0;
    h = 0;

    ht = 23;
    i = 605, j = 795, k = 985;

    for (i1 = 0; i1 < 3; i1++) {

	temp1 = (diff * ) malloc(sizeof(struct diff));
	temp1 -> r = 0;
	if (rd == NULL)
		rd = temp1;
	else {
	    temp1 -> next = rd;
	    rd = temp1;
	}
    }

    /*  GAME BEGINS   */

    while (ch == 'y') /*   GAME  REPEAT   LOOP  */ {
	f = 1;
	c = 0;
	r1 = 0, r2 = 0, r3 = 0;
	h = 0;
	hb = 0;

	ht = 23;
	i = 605, j = 810, k = 1015;


	r1 = pillar_randomess(r1);
	r2 = pillar_randomess(r2);
	r3 = pillar_randomess(r3);
	color = 1;

	setbkcolor(color);

	/*   START   SCREEN   */

	for (l = 0;; l++) {
		make_bubbles(hb);
		hb = hb - 2;

	    if (f > 18)
		f = 1;

	    if (hgt > 40)
		hgt = 0;

	    if (hgt <= 20)
		h--;

	    if (hgt >= 20)
		h++;

	    make_fish(h);

	    if (f <= 9) {

		line(300, 210 + h, 298, 203 + h);
		line(298, 203 + h, 292, 215 + h);
		line(292, 215 + h, 300, 210 + h);

	    }

	    if (f > 9) {
		line(300, 210 + h, 287, 202 + h);
		line(287, 202 + h, 284, 218 + h);
		line(284, 218 + h, 300, 210 + h);
	    }

	    f++;
	    hgt++;

	    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 7);
	    outtextxy(150, 20, "F Fish");

	    settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
	    outtextxy(490, 80, "C");
	    circle(493, 83, 7);

	    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
	    outtextxy(80, 280, "PRESS ANY KEY TO START THE GAME");
	    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
	    outtextxy(40, 330, "BETTER USE SAME KEY TO PLAY THE GAME !!!");

	    if (kbhit()) { /*   keyboard hit  to start the  game */
		getch();
		break;
	    }

	    delay(6);
	    cleardevice();

	}      //start screen loop ends here

	/* +++++++++++++++++++++  GAME BEGINS  AFTER   HITTING  THE   KEY ++++++++++++++++++++++++++   */

	h = 0;
	f = 1;

	for (l = 0;; l++) /*    the beginning of the game's loop  */ {
	make_bubbles(hb);

	    setfillstyle(SLASH_FILL,10);
	    bar(0, 420, 640, 440);

	    setfillstyle(SOLID_FILL, 10); /*  base  yellow  ground   */
	    bar(0, 440, 640, 480);

	    if (f > 22)
		f = 1;

		make_fish(h);

	    if (f <= 11) {
		line(300,210+h,298,203+h);
		line(298,203+h,292,215+h);
		line(292,215+h,300,210+h);

	    }

	    if (f > 11) {
		line(300,210+h,287,202+h);
		line(287,202+h,284,218+h);
		line(284,218+h,300,210+h);
	    }

	    f++;

	    if ((190 + h) <= 0) /*  roof collision  */ {
		ht = 50;
	    }

	    if ((230 + h) >= 420) /* floor collision*/ {
		break;
	    }

		if (is_going_to_collide(i, r1, h))
			break;

		if (is_going_to_collide(j, r2, h))
			break;

		if (is_going_to_collide(k, r3, h))
			break;

	    /*  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++                   */

	    if ((190 + h) <= (180 + r1) || (230 + h) >= (180 + r1 + 120)) /* collision with 1st pillar sides  */ {
		if (i == 325)
		    break;
	    }

	    if ((190 + h) <= (180 + r2) || (230 + h) >= (180 + r2 + 120)) /* collision with 2nd pillar sides */ {
		if (j == 325)
		    break;
	    }

	    if ((190 + h) <= (180 + r3) || (230 + h) >= (180 + r3 + 120)) /* collision with 3rd  pillar sides  */ {
		if (k == 325)
		    break;
	    }

	    if (kbhit()) /*   keyboard hit */ {
		getch();
		ht = 0;
	    }

	    if (ht < 23) /*  going  up  */ {

		if (ht == 0)
		    h = h - 3;

		else
		    h = h - 2;

	    }

	    if (ht >= 23) /*  falling down  */ {
		h = h + 2;

	    }

	    ht++;
	    hb--;

	    /* 1st pillar */

	    if (i < 555) {

		make_pillar(i, r1, colorpil);

		i--;

		if (i == 35) {
		    i = 645;
			r1 = pillar_randomess(r1);

		}
		} else
		i--;

	    /*  2nd pillar  */

	    if (j < 555) {
		make_pillar(j, r2, colorpil);
		j--;

		if (j == 35) {
		    j = 645;
			r2 = pillar_randomess(r2);
		}
	    } else
		j--;

	    /* 3rd pillar */

	    if (k < 555) {
		make_pillar(k, r3, colorpil);

		k--;

		if (k == 35) {
		    k = 645;
			r3 = pillar_randomess(r3);
	    }
		}
		else
		k--;

	    if (i == 300 || j == 300 || k == 300) {
		c++;
		sound(3000);
		delay(13);
		nosound();
		cleardevice();
		continue;
	    }

	    sprintf(msg, "%d", c);
	    settextstyle(DEFAULT_FONT, HORIZ_DIR, 5);
	    outtextxy(320, 80, msg);

	    delay(9);
	    cleardevice();
	} /*   end of game loop  */

	cleardevice();

	sound(500);
	delay(200);
	sound(400);
	delay(200);
	sound(150);
	delay(100);
	nosound();

	delay(700);
	cleardevice();

	settextstyle(DEFAULT_FONT, HORIZ_DIR, 5);
	outtextxy(150, 100, "GAME OVER");

	settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
	outtextxy(150, 180, "YOUR SCORE ->");

	sprintf(msg, "%d", c);
	settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
	outtextxy(470, 180, msg);

	fp = fopen("flappymxscore.txt", "r");

	score = getw(fp);

	fclose(fp);
	settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
	outtextxy(150, 250, "HIGHEST SCORE->");


	if (c > score) {
	    fp = fopen("flappymxscore.txt", "w");
	    putw(c, fp);
	    fclose(fp);

	    pop(stack); /*   stack  pop and push   */
	    push(c, stack);

	    fp = fopen("flappymxscore.txt", "r");

	    score = getw(fp);

	    fclose(fp);


	}

	sprintf(msg, "%d", score);
	settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
	outtextxy(470, 250, msg);

    if (c > score) {
	    fp = fopen("flappymxscore.txt", "w");
	    putw(c, fp);
	    fclose(fp);
	}

	settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
	outtextxy(40, 320, "PRESS 'Y' KEY TO PLAY THE GAME AGAIN");

	settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
	outtextxy(200, 380, "PRESS 'N' TO QUIT");

	KEYPRESS: /*  prevention from other keypress except 'y' or 'n'  */
	    ch = getche();
	if (ch == 'n')
	    break;
	if (ch != 'y')
	    goto KEYPRESS;

	cleardevice();

    }

    closegraph();

}