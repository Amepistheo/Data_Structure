#ifndef RECTANGLE_H
#define RECTANGLE_H
class Rectangle {
private:
	int width=0;
	int height=0;
public:
	 Rectangle(int w, int h) {
			width = w;
			 height = h;
			 if (width < 0) {
				 width = 0; 
			 }
			 if (height < 0)
				 height = 0;
	}
	
	int area() {
		return width * height;
	}
	int perimeter() {
		return (width * 2) + (height * 2);
	}
};
#endif