#include<stdio.h>
#include<math.h>
#include<graphics.h>
void draw_circle(int a, int b, int r){
    int p = 5 / 4 - r, x = 0, y = r;

    while(x <= y){
        putpixel(a + x, b + y, 15);
        putpixel(a - x, b + y, 15);
        putpixel(a + x, b - y, 15);
        putpixel(a - x, b - y, 15);
        putpixel(a - y, b - x, 15);
        putpixel(a - y, b + x, 15);
        putpixel(a + y, b - x, 15);
        putpixel(a + y, b + x, 15);
        if(p >= 0){
            p = p + 2 * (x - y) + 5;
            y --;
        }
        else{
            p = p + 2 * x + 3;
        }
        x ++;
    }
}

int main(){
    int gd = DETECT, gm, r, a, b;
    char path[] = "C:\\TURBOC3\\BGI";
    initgraph(&gd, &gm, path);
    printf("MID-POINT CIRCLE DRAWING ALGO.\n\n");
    printf("center of circle :\n");
    printf("(a, b) :");
    scanf("%d %d", &a, &b);
    printf("radius of circle (r) :\n");
    scanf("%d", &r);
    draw_circle(a, b, r);
    getch();
    return 0;
}