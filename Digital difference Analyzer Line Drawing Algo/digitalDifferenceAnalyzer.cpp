#include<stdio.h>
#include<math.h>
#include<graphics.h>

void draw_line(float x1, float y1, float x2, float y2){
    float dy = (y2 - y1), dx = (x2 - x1), m = dy /dx;

    while(x1 <= x2){
        putpixel((int)x1,(int)y1, 15);
        x1 += 1;
        y1 += m;
    }

}

int main(){
    int gd = DETECT, gm, x1, x2, y1, y2;
    char path[] = "C:\\TURBOC3\\BGI";
    initgraph(&gd, &gm, path);
    
    printf("DIGITAL DIFF ANALYZER LINE DRAWING ALGO.\n\n");
    printf("enter co-ordinates for 1st octant :\n");

    printf("(x1, y1) :");
    scanf("%d %d", &x1, &y1);
    printf("(x2, y2) :");
    scanf("%d %d", &x2, &y2);

    float m = (y2 - y1) / (x2 - x1);

    if(m <= 1){
        draw_line(x1, y1, x2, y2);
    }
    else{
        printf("enter correct co-ordinates !!\n");
        return 0;
    }
    getch();
    return 0;
}
