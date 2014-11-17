#include <X11/Xlib.h> // pour utiliser X11
#include <unistd.h> //pour fonction d'attente sleep
#define LARGEUR 200
#define HAUTEUR 200

// Variables Globales de X11
XEvent xevent;
Display *xdisplay;
Window xwindow;
GC xgc;
int black, white;

// Prototypes
void initX11();
void displayImage(unsigned char* image);
void  fillImage(unsigned char * image, char val);
char getImagePixel(unsigned char* image,int x,int y);
void setImagePixel(unsigned char* image,int x,int y,char val);

int main (){
	initX11();
	unsigned char image[LARGEUR * HAUTEUR];
	fillImage(image,1);
	displayImage(image);


	sleep(2); //on attend 10s avant de quitter
	return 0;
}

void displayImage(unsigned char* image){
	int i,j;
	XSetForeground(xdisplay, xgc, white);
	for ( i=0; i < LARGEUR ; i++ ) {
		for ( j=0;j < HAUTEUR; j++ ) {
			if(getImagePixel(image,i,j))
				printf("coucou, x%d   y%d \n ", i,j);
				//sleep(1);
				XDrawPoint(xdisplay, xwindow, xgc, i, j);
				//XFlush(xdisplay);
				//sleep(4);
		}
	}	
	printf("fin\n");
	XFlush(xdisplay);
}

void initX11() {
	xdisplay = XOpenDisplay(NULL);
	black = BlackPixel(xdisplay, DefaultScreen(xdisplay));
	white = WhitePixel(xdisplay, DefaultScreen(xdisplay));
	Window xwindow = XCreateSimpleWindow(xdisplay, DefaultRootWindow(xdisplay), 100, 100,LARGEUR,HAUTEUR, 0, black, black);
	XMapWindow(xdisplay, xwindow); 
	xgc = XCreateGC(xdisplay,xwindow,0,NULL);
	XSelectInput(xdisplay, xwindow, StructureNotifyMask);
	while (xevent.type != MapNotify) XNextEvent(xdisplay, &xevent);
}
void setImagePixel(unsigned char* image,int x,int y,char val) {
	image[x +(y*LARGEUR)] = val;
}
char getImagePixel(unsigned char* image,int x,int y) {
	return image[x +(y*LARGEUR)];
}
void  fillImage(unsigned char * image, char val) {
	int i, j;
	for ( i=0; i < LARGEUR ; i++ ) {
		for ( j=0;j < HAUTEUR; j++ ) {
			setImagePixel(image,i,j,val);
		}
	}
}