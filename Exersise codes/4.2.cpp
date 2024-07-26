#include <iostream>
#include <graphics.h>

 // measurment are refrenced to the origin (0.0) located at the top left corner of the window
 // positive x axis to the right, positive y axis to the bottom

class Shape 
{
	public:
	int color;
	int linewidth;	
	
	Shape(){color=15; linewidth=5;};
	Shape(int clr, int lw){color=clr; linewidth=5;};
};

class Point 
{
	public:
		int x;  // x coorednate
		int y;  // y coordinate

		Point(){x=0; y=0;};
		Point(int px, int py){x= px; y=py;};
};

class Line : public Shape
{
	private:
		Point p1;  // point 1
		Point p2;  // point 2
				
	public:	
		Line():Shape()
		{p1.x=0; p1.y=0; p2.x=0; p2.y=0;};
		
		Line(Point tp1, Point tp2, int clr, int lw):Shape(clr,lw)
		{p1.x=tp1.x; p1.y=tp1.y; p2.x=tp2.x; p2.y=tp2.y;};
		
		Line(int p1_x, int p1_y, int p2_x, int p2_y, int clr, int lw):Shape(clr,lw)
		{p1.x=p1_x; p1.y=p1_y; p2.x=p2_x; p2.y=p2_y;};
		
		void draw()
		{
			setcolor(color);
			setlinestyle (0, 0, linewidth); // setlinestyle (style, pattern, thickness);
			line(p1.x, p1.y, p2.x, p2.y);  // (point_1_x_axis, point_1_y_axis, point_2_x_axis, point_2_y_axis)
		}
};

class Circle : public Shape
{
	private:
		Point c; // center
		int r;   // radius
				
	public:	
		Circle():Shape()
		{c.x=0; c.y=0; r=0;};
		
		Circle(Point tp, int tr, int clr, int lw):Shape(clr,lw)
		{c.x=tp.x; c.y=tp.y; r=tr; };
		
		Circle(int p_x, int p_y, int tr, int clr, int lw):Shape(clr,lw)
		{c.x=p_x; c.y=p_y; r=tr; };
		
		void draw()
		{
			setcolor(color);
			setlinestyle (0, 0, linewidth); // setlinestyle (style, pattern, thickness);
			circle(c.x, c.y, r);  // (center_x_axis, center_y_axis, radius)
		}
};

class Rect : public Shape
{
	private:
		Point p1;  // point 1
		Point p2;  // point 2
				
	public:	
		Rect():Shape()
		{p1.x=0; p1.y=0; p2.x=0; p2.y=0;};
		
		Rect(Point tp1, Point tp2, int clr, int lw):Shape(clr,lw)
		{p1.x=tp1.x; p1.y=tp1.y; p2.x=tp2.x; p2.y=tp2.y;};
		
		Rect(int p1_x, int p1_y, int p2_x, int p2_y, int clr, int lw):Shape(clr,lw)
		{p1.x=p1_x; p1.y=p1_y; p2.x=p2_x; p2.y=p2_y;};
		
		void draw()
		{
			setcolor(color);
			setlinestyle (0, 0, linewidth); // setlinestyle (style, pattern, thickness);
			line(p1.x, p1.y, p1.x, p2.y);  // (point_1_x_axis, point_1_y_axis, point_2_x_axis, point_2_y_axis)
			line(p1.x, p1.y, p2.x, p1.y); 
			line(p2.x, p1.y, p2.x, p2.y); 
			line(p1.x, p2.y, p2.x, p2.y); 
		}
};

class Picture
{
  private :
	int cNum ;
	int rNum ;
	int lNum ;

	Circle *pCircles;
	Rect *pRects;
	Line *pLines;

  public :
	Picture()
	{
		cNum=0;
		rNum=0;
		lNum=0;
		pCircles = NULL ;
		pRects = NULL ;
		pLines = NULL ;
	}

	Picture(int cn, int rn, int ln, Circle *pC, Rect *pR, Line *pL)
	{
		cNum = cn;
		rNum = rn;
		lNum = ln;
		pCircles = pC ;
		pRects = pR ;
		pLines = pL ;
	}

	void setCircles(int, Circle *);
	void setRects(int, Rect *);
	void setLines(int, Line *);
	void paint();
};

void Picture::setCircles(int cn, Circle * cptr)
{
	cNum = cn ;
	pCircles = cptr ;
}

void Picture::setRects(int rn, Rect * rptr)
{
	rNum = rn ;
	pRects = rptr ;
}

void Picture::setLines(int ln, Line * lptr)
{
	lNum = ln ;
	pLines = lptr ;
}

void Picture::paint()
{
	int i;
	for(i=0; i<cNum ; i++)
	{
		pCircles[i].draw();
	}

	for(i=0 ; i<rNum ; i++)
	{
		pRects[i].draw();
	}

	for(i=0 ; i<lNum; i++)
	{
		pLines[i].draw();
	}
}

 int main()
 {
    int gd = DETECT, gm;
    initgraph(&gd, &gm,"C:\\TC\\BGI");
	
    Line lines[4]={Line(325,225,325,375,11,2),Line(260,250,390,250,11,2),Line(325,375,375,425,9,2),Line(325,375,275,425,9,2)};

    Rect recs[1]={Rect(290,135,360,165,12,2)};

    Circle circs[3]={Circle(290,85,20,11,1),Circle(360,85,20,11,1),Circle(325,125,100,14,3)};
    
    Picture pic1(3,1,4,circs,recs,lines);
    pic1.paint();
    
	getch();
    closegraph();
    return 0;
 }
