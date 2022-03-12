#include<stdio.h>
#include<math.h>
#include<graphics.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void draw_line(int x1, int y1, int x2, int y2){
    int dy = (y2 - y1), dx = (x2 - x1), p = 2 * dy - dx;

    while(x1 <= x2){
        putpixel(x1, y1, 15);
        x1 ++;
        if(p >= 0){
            p = p + 2 * dy - 2 * dx;
            y1 ++;
        }
        else if(p < 0){
            p = p + 2 * dy;
        }
    }
}

int main(){
    int gd = DETECT, gm, x1, x2, y1, y2;
    char path[] = "C:\\TURBOC3\\BGI";
    initgraph(&gd, &gm, path);
    
    printf("MID POINT LINE DRAWING ALGO.\n\n");
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