#include<stdio.h>
#include<math.h>
#include<graphics.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void draw_line(int x1, int y1, int x2, int y2, int oc){
    int dy = abs(y2 - y1), dx = abs(x2 - x1), p = 2 * dy - dx;

    if(oc == 4 || oc == 8){
        swap(&x1, &x2);
    }

    while(x1 <= x2){
        if(oc == 1 || oc == 5){
            putpixel(x1, y1, 15);
            x1 ++;
        } 
        //swap
        else if(oc == 2 || oc == 3 || oc == 6 || oc == 7){
            putpixel(y1, x1, 15);
            x1 ++;
        }
        else if(oc == 4 || oc == 8){
            putpixel(x2, y1, 15);
            x2 --;
        }
        if(p >= 0){
            p = p + 2 * dy - 2 * dx;
            if(oc == 1 || oc == 2 || oc == 4 || oc == 5 || oc == 6 || oc == 8){
                y1 ++;
            }
            else if(oc == 3 || oc == 7){
                y1 --;
            }
        }
        else if(p < 0){
            p = p + 2 * dy;
        }
    }
}

int main(){
    int gd = DETECT, gm, x1, x2, y1, y2, dx, dy;
    float m;
    char path[] = "C:\\TURBOC3\\BGI";
    initgraph(&gd, &gm, path);
    printf("(x1, y1) :");
    scanf("%d %d", &x1, &y1);
    printf("(x2, y2) :");
    scanf("%d %d", &x2, &y2);

    dx = x2 - x1;
    dy = y2 - y1;

    m = dy / dx;

    //FIRST
    if(m < 1 && x2 > 0 && y2 > 0){
        draw_line(x1, y1, x2, y2, 1);
    }
    //SECOND
    else if(m >= 1 && x2 > 0 && y2 > 0){
        draw_line(y1, x1, y2, x2, 2);
    }
    //THIRD
    else if(m < -1 && x2 < 0 && y2 > 0){
        draw_line(y1, abs(x2), y2, abs(x1), 3);
    }
    //FOURTH
    else if(m >= -1 && x2 < 0 && y2 > 0){
        draw_line(abs(x2), y1, abs(x1), y2, 4);
    }
    //FIFTH
    else if(m < 1 && x2 < 0 && y2 < 0){
        draw_line(-x1, -y1, -x2, -y2, 5);
    }
    //SIXTH
    else if(m >= 1 && x2 < 0 && y2 < 0){
        draw_line(-y1, -x1, -y2, -x2, 6);
    }
    //SEVENTH
    else if(m < -1 && x2 > 0 && y2 < 0){
        draw_line(-y1, x2, -y2, x1, 7);
    }
    //EIGHT
    else if(m >= -1 && x2 > 0 && y2 < 0){
        draw_line(x2, -y1, x1, -y2, 8);
    }


    getch();
    return 0;
}