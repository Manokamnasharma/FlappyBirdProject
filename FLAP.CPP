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

    int h; /*   height and depth parameters */
    int l, k, m, r1, r2, r3;
    int a1, a2, a3; /* base slab coordinates  */
    char msg[20];
    int score;
    int i1;

    FILE * fp;
    diff * rd, * temp1;
    scor * stack, * temp2;

    int gd = DETECT, gm;
    initgraph( & gd, & gm, "C:\\TurboC3\\BGI");

    cleardevice();

    r1 = 0, r2 = 0, r3 = 0;
    h = 0;

    ht = 23;
    i = 605, j = 795, k = 985;

    a1 = 0, a2 = 640, a3 = 1280;

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

    while (ch == 'y') /*   GAME  REPEAT   LOOOOOOP     */ {

	f = 1;
	c = 0;
	r1 = 0, r2 = 0, r3 = 0;
	h = 0;

	ht = 23;
	i = 605, j = 795, k = 985;

	a1 = 0, a2 = 640, a3 = 1280;

	while (r1 < 50) /*   1st   pillar   randomness  */ {
	    r1 = rand() % 110;
	}

	m = rand() % 2;

	if (m % 2 == 0)
	    r1 = 1 * r1;
	else
	    r1 = -1 * r1;

	while (r2 < 50) /*   2nd  pillar randomness  */ {
	    r2 = rand() % 110;
	}

	m = rand() % 2;

	if (m % 2 == 0)
	    r2 = 1 * r2;
	else
	    r2 = -1 * r2;

	while (r3 < 50) /*  3rd  pillar  randomness   */ {
	    r3 = rand() % 110;
	}

	m = rand() % 2;

	if (m % 2 == 0)
	    r3 = 1 * r3;
	else
	    r3 = -1 * r3;

     color = 1;
      //	color = rand() % 2; /*   background  and   pillar  color coding   */
    //	color = color + 8;

     //	if (color == 8) /*  if  background gray then pillar r green  */ /*   NIGHT */
	    //colorpil = 2;

     //	if (color == 9) /*  if  background is lightblue then pillars r  light green  */ /*   DAY   */
	//    colorpil = 12;

	setbkcolor(color);

	/*   START   SCREEN   */

	for (l = 0;; l++) {


		setfillstyle(SOLID_FILL, WHITE);
		circle(40, 250, 10);
		circle(37, 203, 5);
		circle(130, 120, 12);
		circle(134, 200, 13);
		circle(225, 160, 9);
		circle(360, 200, 5);
		circle(317, 150, 7);
		circle(400, 120, 8);
		circle(415, 160, 10);
		circle(510, 120, 5);
		circle(510, 200, 5);
		circle(600, 160, 6);
		circle(490, 470, 6);
		circle(550, 420, 7);
		circle(40, 400, 6);
		circle(60, 450, 5);
		circle(270, 455, 6);
		circle(420, 400, 6);
		circle(360, 448, 8);

	    if (f > 18)
		f = 1;

	    if (hgt > 40)
		hgt = 0;

	    if (hgt <= 20)
		h--;

	    if (hgt >= 20)
		h++;

	  //  ellipse(300, 210 + h, 0, 360, 25, 20); /*    bird  structure   */
	  //  arc(325, 185 + h, 190, 270, 25); /*    eye    */
	 //   ellipse(325, 210 + h, 0, 360, 6, 4); /*   beak    */
	    // floodfill(300,240+h,4);  cannot be used to fill color , it fills the whole screen
	    circle(325,210+h,3);
	    arc(300, 230+h, 30, 150,40)   ;
	    arc(300, 190+h, 210, 330, 40) ;
	    arc(284, 210+h, 340,20,25);
	    arc(279, 210+h, 340,20,25);
	    arc(289, 210+h, 340,20,25);
	    arc(240,210+h,318,45,25) ;
	    line(258,193+h,258,227+h);
	    setfillstyle(SOLID_FILL,GREEN);
	    floodfill(325,210+h,WHITE);


	    if (f <= 9) {

	    /*	arc(300, 185 + h, 180, 270, 25);  // flap  up
		arc(275, 210 + h, 0, 90, 25);

		 floodfill(287,227,WHITE);
		floodfill(279,219,WHITE);	*/
		line(300,210+h,298,203+h);
		line(298,203+h,292,215+h);
		line(292,215+h,300,210+h);

	    }

	    if (f > 9) /*    flap   down     */ {
	     /*	arc(300, 235 + h, 90, 180, 25);
		arc(275, 210 + h, 270, 0, 25);
		/*   floodfill(287,252,WHITE);
		floodfill(279,261,WHITE); */
		line(300,210+h,287,202+h);
		line(287,202+h,284,218+h);
		line(284,218+h,300,210+h);
	    }

	    f++;
	    hgt++;

	    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 7);
	    outtextxy(150, 20, "Fishy Fish");

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

	 setfillstyle(SOLID_FILL, WHITE);
		circle(40, 250, 10);
		circle(37, 203, 5);
		circle(130, 120, 12);
		circle(134, 200, 13);
		circle(225, 160, 9);
		circle(360, 200, 5);
		circle(317, 150, 7);
		circle(400, 120, 8);
		circle(415, 160, 10);
		circle(510, 120, 5);
		circle(510, 200, 5);
		circle(600, 160, 6);
      /*	    if (a1 <= -639) /*   slash filled  slab  condition
		a1 = 1280;

	    if (a2 <= -639)
		a2 = 1280;

	    if (a3 <= -639)
		a3 = 1280;   */

	    setfillstyle(SLASH_FILL,10);
	    bar(0, 420, 640, 440);

	    setfillstyle(SOLID_FILL, 10); /*  base  yellow  ground   */
	    bar(0, 440, 640, 480);

	    a1--;
	    a2--;
	    a3--;

	    if (f > 22)
		f = 1;

	/*    ellipse(300, 240+h, 0, 360, 25, 20);    bird  structure
	    arc(325, 215 + h, 190, 270, 25);
	    ellipse(325, 240 + h, 0, 360, 6, 4);
	    /* floodfill(300,240+h,4);  */
	    circle(325,210+h,3);
	    arc(300, 230+h, 30, 150,40)   ;
	    arc(300, 190+h, 210, 330, 40) ;
	    arc(284, 210+h, 340,20,25);
	    arc(279, 210+h, 340,20,25);
	    arc(289, 210+h, 340,20,25);
	    arc(240,210+h,318,45,25) ;
	    line(258,193+h,258,227+h);
	    setfillstyle(SOLID_FILL,GREEN);
	    floodfill(325,210+h,WHITE);

	    if (f <= 11) {

	    /*	arc(300, 215 + h, 180, 270, 25);
		arc(275, 240 + h, 0, 90, 25);

		 floodfill(287,227,WHITE);
		floodfill(279,219,WHITE);	*/
		line(300,210+h,298,203+h);
		line(298,203+h,292,215+h);
		line(292,215+h,300,210+h);

	    }

	    if (f > 11) {
	      /*  arc(300, 265 + h, 90, 180, 25);
		arc(275, 240 + h, 270, 0, 25);
		  floodfill(287,252,WHITE);
		floodfill(279,261,WHITE); */
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

	    if ((i <= 334 && i >= 266) || ((i + 50) <= 334 && (i + 50) >= 266)) /* collision with 1st pillar top  or  base */ {
		if ((190 + h) <= (180 + r1) || (230 + h) >= (180 + r1 + 115))
		    break;
	    }

	    if ((j <= 334 && j >= 266) || ((j + 50) <= 334 && (j + 50) >= 266)) /* collision with 1st pillar top  or  base */ {
		if ((190 + h) <= (180 + r2) || (230 + h) >= (180 + r2 + 115))
		    break;
	    }

	    if ((k <= 334 && k >= 266) || ((k + 50) <= 334 && (k + 50) >= 266)) /* collision with 1st pillar top  or  base */ {
		if ((190 + h) <= (180 + r3) || (230 + h) >= (180 + r3 + 115))
		    break;
	    }

	    /*  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++                   */

	    if ((190 + h) <= (180 + r1) || (230 + h) >= (180 + r1 + 115)) /* collision with 1st pillar sides  */ {
		if (i == 325)
		    break;
	    }

	    if ((190 + h) <= (180 + r2) || (230 + h) >= (180 + r2 + 115)) /* collision with 2nd pillar sides */ {
		if (j == 325)
		    break;
	    }

	    if ((190 + h) <= (180 + r3) || (230 + h) >= (180 + r3 + 115)) /* collision with 3rd  pillar sides  */ {
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

	    /* 1st pillar */

	    if (i < 555) {

		setfillstyle(SOLID_FILL, colorpil);
		bar(i, 0, i + 50, 180 + r1);
		setfillstyle(SOLID_FILL, colorpil);
		bar(i - 5, 170 + r1, i + 55, 180 + r1);

		rectangle(i, 0, i + 50, 170 + r1);

		rectangle(i - 5, 170 + r1, i + 55, 180 + r1);

		setfillstyle(SOLID_FILL, colorpil);
		bar(i, 180 + r1 + 115, i + 50, 419);
		setfillstyle(SOLID_FILL, colorpil);
		bar(i - 5, 180 + r1 + 115, i + 55, 190 + r1 + 115);

		rectangle(i - 5, 180 + r1 + 115, i + 55, 190 + r1 + 115);

		rectangle(i, 190 + r1 + 115, i + 50, 419);

		i--;

		if (i == 35) {
		    i = 605;

		    while (r1 < 50) {
			r1 = rand() % 110;
		    }

		    m = rand() % 2;

		    if (m % 2 == 0)
			r1 = 1 * r1;
		    else
			r1 = -1 * r1;
		}

	    } else
		i--;

	    /*  2nd pillar  */

	    if (j < 555) {

		setfillstyle(SOLID_FILL, colorpil);
		bar(j, 0, j + 50, 180 + r2);
		setfillstyle(SOLID_FILL, colorpil);
		bar(j - 5, 170 + r2, j + 55, 180 + r2);

		rectangle(j, 0, j + 50, 170 + r2);

		rectangle(j - 5, 170 + r2, j + 55, 180 + r2);

		setfillstyle(SOLID_FILL, colorpil);
		bar(j, 180 + r2 + 115, j + 50, 419);
		setfillstyle(SOLID_FILL, colorpil);
		bar(j - 5, 180 + r2 + 115, j + 55, 190 + r2 + 115);

		rectangle(j - 5, 180 + r2 + 115, j + 55, 190 + r2 + 115);

		rectangle(j, 190 + r2 + 115, j + 50, 419);

		j--;

		if (j == 35) {
		    j = 605;

		    while (r2 < 50) {
			r2 = rand() % 110;
		    }

		    m = rand() % 2;

		    if (m % 2 == 0)
			r2 = 1 * r2;
		    else
			r2 = -1 * r2;
		}
	    } else
		j--;

	    /* 3rd pillar */

	    if (k < 555) {

		setfillstyle(SOLID_FILL, colorpil);
		bar(k, 0, k + 50, 180 + r3);
		setfillstyle(SOLID_FILL, colorpil);
                bar(k - 5, 170 + r3, k + 55, 180 + r3);

                rectangle(k, 0, k + 50, 170 + r3);

                rectangle(k - 5, 170 + r3, k + 55, 180 + r3);

                setfillstyle(SOLID_FILL, colorpil);
		bar(k, 180 + r3 + 115, k + 50, 419);
		setfillstyle(SOLID_FILL, colorpil);
                bar(k - 5, 180 + r3 + 115, k + 55, 190 + r3 + 115);

                rectangle(k - 5, 180 + r3 + 115, k + 55, 190 + r3 + 115);

                rectangle(k, 190 + r3 + 115, k + 50, 419);

                k--;

                if (k == 35) {
                    k = 605;

		    while (r3 < 50) {
                        r3 = rand() % 110;
                    }

		    m = rand() % 2;

		    if (m % 2 == 0)
			r3 = 1 * r3;
		    else
			r3 = -1 * r3;
		}

	    } else
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

      /*	if (c > score) {
	    fp = fopen("flappymaxscore.txt", "w");
	    putw(c, fp);
	    fclose(fp);
	}    */

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