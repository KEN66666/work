#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <windows.h>
using namespace std;


int ball[5][6]={
    0,1,0,3,0,1,
    1,5,0,1,2,2,
    2,4,2,3,0,3,
    5,3,4,4,2,4,
    4,5,1,5,5,3
};
int ball_num[6]={0};
int ball_cnum[6]={0};


void ball_count(){
    memset(ball_num,0,sizeof(ball_num));
    for(int i=0;i<5;i++){
        for(int j=0;j<6;j++){
            ball_num[ball[i][j]]++;
        }
    }
}
void SetColor(int color = 7){
  HANDLE hConsole;
  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole,color);
}
void col_ball(int b){
    SetColor();
    switch(b){
        case 0:
            SetColor(240);
            break;
        case 1:
            SetColor(192);
            break;
        case 2:
            SetColor(176);
            break;
        case 3:
            SetColor(160);
            break;
        case 4:
            SetColor(224);
            break;
        case 5:
            SetColor(80);
            break;
        default:
            SetColor();
            break;
    }

}
void print_ball(){
    memset(ball_num,0,sizeof(ball_num));
    for(int i=0;i<5;i++){

        for(int j=0;j<6;j++){
            ball_num[ball[i][j]]++;
            col_ball(ball[i][j]);
            //printf(" ");
            printf("%2d",ball[i][j]);
        }
        SetColor();
        printf("-\n");
    }


}
int maxcc(){
    int sum=0;
    for(int i=0;i<6;i++){
        ball_cnum[i]=ball_num[i]/3;
        sum+=ball_cnum[i];

    }
    return sum;

}
struct point{
    int x,y;
};
point set_point(int x,int y){
    point P;
    P.x=x;
    P.y=y;
    return P;
}
bool  check_range(int x,int y){
    return x<6&&x>=0&&y<5&&y>=0;
}
void point_move(point* A,int k){
    int cx=0,cy=0;
    switch(k){
        case 1:
            cx=1;
            cy=0;
            break;

        case 2:
            cx=0;
            cy=1;
            break;

        case 3:
            cx=-1;
            cy=0;
            break;

        case 4:
            cx=0;
            cy=-1;
            break;

        default:
            break;
    }

    if(check_range(A->x+cx,A->y+cy)){
        swap(ball[A->y][A->x],ball[A->y+cy][A->x+cx]);
        A->x=A->x+cx;
        A->y=A->y+cy;
    }
}

void  gotoxy( SHORT x , SHORT y )
{
    HANDLE  out = GetStdHandle( STD_OUTPUT_HANDLE );
    COORD     coordinate;
    CONSOLE_SCREEN_BUFFER_INFO  csbi;  // 新增的程式碼

    GetConsoleScreenBufferInfo( out , &csbi );     // 新增的程式碼
    coordinate.X = csbi.srWindow.Left + x;           // 修改的程式碼
    coordinate.Y = csbi.srWindow.Top + y;            // 修改的程式碼

    SetConsoleCursorPosition( out , coordinate );
}
int main()
{


    print_ball();
    //cout<<"max combo :"<<maxcc()<<endl;
    point A=set_point(0,0);
    cout<<A.x<<" "<<A.y<<endl;
    int k;
    while(cin>>k){
        gotoxy(0,0);
        point_move(&A,k);
        print_ball();
        cout<<A.x<<" "<<A.y<<endl;


    }







    //ball_count();





}
