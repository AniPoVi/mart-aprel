#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <dos.h>

class Point {
public:
    int x, y, cvet;

    Point(int xn, int yn, int color);

    virtual void show();

    virtual void hide();

    virtual
    void locat(int *xl, int *yl);

    void fly(int cost);

    void flyWithColor(int cost, int color2);
};

class Krug : public Point {
public:
    int radius;

    int end;

    int start;

    Krug(int xn, int yn, int r, int color);

    virtual void show();

    virtual void hide();

    void resize(int step);
};

class Ring : public Krug {
public:
    int width;

    Ring(int xn, int yn, int r, int color, int wid);

    virtual void show();
};

Point::Point(int xn, int yn, int color) {
    x = xn;
    y = yn;
    cvet = color;
}

void Point::show() {
}

void Point::hide() {
}

void Point::locat(int *xl, int *yl) {
    *xl = x;
    *yl = y;
}

void Point::fly(int cost) {
    int XX, YY;
    show();
    randomize();
    do {
        locat(&XX, &YY);
        do XX = XX + (int) ((random(2) - 0.5) * cost); //{перемещение1 }
        while ((XX < 0) && (XX > getmaxx()));
        do YY = YY + (int) ((random(2) - 0.5) * cost); //  { перемещение2}
        while ((YY < 0) && (YY > getmaxy()));
        hide();
        x = XX;
        y = YY;
        show();
        delay(300); //   { мелькание кругов }
    } while (!kbhit());
    getch();
}

void Point::flyWithColor(int cost, int color2) {
    int XX, YY;
    int OldColor = cvet;

    show();
    randomize();
    do {
        locat(&XX, &YY);
        do XX = XX + (int) ((random(2) - 0.5) * cost);
        while ((XX < 0) && (XX > getmaxx()));
        do YY = YY + (int) ((random(2) - 0.5) * cost);
        while ((YY < 0) && (YY > getmaxy()));

        hide();
        x = XX;
        y = YY;

        if (cvet == OldColor) cvet = color2;
        else cvet = OldColor;

        show();
        delay(300);
    } while (!kbhit());
    getch();
}

Krug::Krug(int xn, int yn, int r, int color) : Point(xn, yn, color) {
    radius = r;
    start = 0;
    end = 320;
    show();
}

void Krug::show() {
    setcolor(cvet);
    setfillstyle(1, cvet);
    pieslice(x, y, 0, 320, radius);
}

void Krug::hide() {
    setcolor(getbkcolor());
    setfillstyle(1, getbkcolor());
    pieslice(x, y, end, start, radius);
}

void Krug::resize(int step) {
    int dirStart = 1;
    int dirEnd = -1;
    int startOriginal = start;
    int endOriginal = end;

    show();
    do {
        hide();


        start = start + (dirStart * step);
        end = end + (dirEnd * step);
        if (start > 360) {
            dirStart = -1 * dirStart;
            start = 360;
        }
        if (start < 0) {
            dirStart = -1 * dirStart;
            start = 0;
        }
        if (end > 360) {
            dirEnd = -1 * dirEnd;
            end = 360;
        }
        if (end < 0) {
            dirEnd = -1 * dirEnd;
            end = 0;
        }

        show();
        delay(200);
    } while (!kbhit());

    getch();

    hide();
    start = startOriginal;
    end = endOriginal;
    show();
}

Ring::Ring(int xn, int yn, int r, int color, int wid) : Krug(xn, yn, r, color) {
    width = wid;
    start = 90;
    end = 320;
}

void Ring::show() {
    Krug::show();
    setfillstyle(10, getbkcolor());
    pieslice(x, y, end, start, radius - width);
}

void main() {
    int gdriver = DETECT, gmode, errorcode;
    initgraph(&gdriver, &gmode, "c:\\turboc3\\bgi");
    errorcode = graphresult();
    if (errorcode != grOk) /* an error occurred */
    {
        printf("Graphics error: %s\n", grapherrormsg(errorcode));
        printf("Press any key to halt:");
        getch();
        exit(1); /* return with error code */
    }

    //   Krug TestKrug();
    //   Ring TestRing();
    setbkcolor(80);
    Krug TestKrug(150, 40, 50, 1);
    Ring TestRing(450, 80, 90, 50, 10);
    TestKrug.fly(100);
    TestRing.fly(60);
    TestKrug.fly(60);
    getch();
    TestKrug.hide();
    TestRing.hide();
    getch();
    TestKrug.resize(10);
    TestRing.resize(10);
    getch();
    TestKrug.flyWithColor(100, 200);
    TestRing.flyWithColor(60, 100);
    getch();
}
