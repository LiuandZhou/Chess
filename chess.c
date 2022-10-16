#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>
void play();
int Judge(int map[][15],int x,int y,int turn);
void showmap(int map[][15]);
void UI();
void menu();
int main()
{
	char again;
	system("color 06"); //文字颜色
	UI();//进入游戏前的界面 
	system("pause");
	system("cls");
	menu();
	again=getch();
	while(again!='y'&&again!='n'){//防误触 
		printf("						输入错误!\n");
		again=getch();
	}
	if(again=='y')system("cls");
	while(again=='y'){
		play();//进入游戏 
		printf("\n再玩一次？[y/n]\n");
		again=getch();
		while(again!='y'&&again!='n'){
			printf("输入错误，请选择是否再玩一次[y/n]\n");
			again=getch();
		}
		if(again=='y')system("cls");
	}
    printf("游戏结束！"); 
}
void UI(){//界面输出 
	printf("             **                   **          **  ********               **   **                    \n");
	Sleep(300);
	printf("**********  ***************        **       **    **    **              **   **************         \n");
	Sleep(300);
	printf(" **    **  **     **    **        ****    **      ** ** **             ***  **    **    **          \n");
	Sleep(300);
	printf("  **  **         **                 **    **      **   ***            ****     ** ** **             \n");
	Sleep(300);
	printf("   ****         ****                **    **  **  **                 ** **    **  **  **            \n");
	Sleep(300);
	printf("   ****        **  **               **    ****    **                    **        **                \n");
	Sleep(300);
	printf("  **  **      **    **             ***            **                    **     ** **                \n");
	Sleep(300);
	printf("**     **    **      **           **  **************************        **       ***                \n");
	Sleep(400);
	system("cls");
	printf("   ******************                  *************                 **        **     **             **           **                            **\n");//第二波 
	Sleep(200);
	printf("        **                                       **                  **      *************            **          **                           **\n"); 
	Sleep(200);
	printf("        **                                      **                   **        **     **           *****   ****************                   ** \n"); 
	Sleep(200);
	printf("        **                                     **                  ******      *********              **          **                         ****\n"); 
	Sleep(200);
	printf("        **                                    **                     **        **     **              **          **                        **  **\n");
	Sleep(200);
	printf("   *******************                       **                     ****       *********              **         ****                      **    **\n"); 
	Sleep(200);
	printf("        **          **             ************************        * ** *      **     **              **        **  **                    **      **\n"); 
	Sleep(200);
	printf("        **          **                       **                   *  **  *     *********              **       **    **                  **        **\n"); 
	Sleep(200);
	printf("        **          **                       **                  *   **   *    **     **              **      **      **                **          **\n"); 
	Sleep(200);
	printf("        **          **                       **                      **      *************         ** **     **        **              **            **\n"); 
	Sleep(200);
	printf("        **          **                    ** **                      **       **       **            **     **          **            **              **\n"); 
	Sleep(200);
	printf(" **************************                 ***                      **      **         **          ** ************************      **                **\n"); 
	Sleep(200);
}
void menu(){
	printf("\n\n\n\n\n\n\n");
	printf("						----------------------------------------------\n");
	printf("						|                   五子棋达人               |\n");
	printf("						|         游戏玩法:                          |\n");
	printf("						|         1.使用↑↓←→键移动棋子           |\n");
	printf("						|         2.按空格键确定落子                 |\n");
	printf("						|         3.按B键悔棋，悔棋得经过对手同意    |\n");
	printf("						|         开始游戏[y]    退出游戏[n]         |\n");
	printf("						----------------------------------------------\n");
}
void play(){//进入游戏部分
    int x=7,y=7,jud=0,last=0,next=1,ch,i,j,map[15][15],x1=7,x2=7,y1=7,y2=7,ju=1;//x轴与y轴,jud=0表示未评定出，1表示玩家一获胜，2表示玩家二获胜。ju用于防止玩家一来就悔棋 
    char b='n';
    for(i=0;i<15;i++){
    	for(j=0;j<15;j++)
    		if(i==7&&j==7) map[i][j]=1; 
			else map[i][j]=0;//用0，1，2表示棋盘存在某子或不存在棋子，0表示否，1表示黑棋，2表示白棋 
	}
    printf("游戏开始!\n");
    showmap(map);
    while(jud==0){//判断谁胜负 
        while(jud==0){//玩家一上下左右移动，空格落子
            if(b=='y')b='n';//已经悔棋成功，此步为了方便下一步落子不受影响 
			ch=getch();
            if(ch==224)ch=getch();
            system("cls");
            if(ch==72&&x!=0){//上移
                map[x][y]=last;//last为前一步位置的状态，此行为恢复前一步的位置状态 
                x--;
                last=map[x][y];
                map[x][y]=next;//next记录本轮棋子的状态，便于防止落子覆盖自己的棋 
            }
            else if(ch==80&&x!=14){//下移
                map[x][y]=last;
                x++;
                last=map[x][y];
                map[x][y]=next;
            }
            else if(ch==75&&y!=0){//左移
                map[x][y]=last;
                y--;
                last=map[x][y];
				map[x][y]=next;
            }
            else if(ch==77&&y!=14){//右移
                map[x][y]=last;
                y++;
                last=map[x][y];
				map[x][y]=next;
            }
            else if(ch==32) {
                if(last!=0) printf("此处已有棋子\n");//防止覆盖棋子 
                else{
                	if(ju==1) ju++;
                    jud=Judge(map,x,y,1);
                    if(jud==1) printf("玩家一(●)胜利！\n");
                    else if(jud==3) printf("平局！\n");
                    break;
                }
            }
            else if(ch==98) {//悔棋 
            	if(ju==1) printf("你还未落子，无法悔棋\n"); 
            	else{
            		printf("玩家一(●)是否同意玩家二(○)悔棋[y/n]?\n");
            		showmap(map);
					b=getch();
					while(b!='y'&&b!='n'){
						printf("\n输入错误，请输入[y/n]");
						b=getch();
					}
					system("cls");
            		if(b=='y'){
            			map[x][y]=last;//恢复现在位置原始状态 
            			x=x2;//回到之前下子的点 
            			y=y2;
						break;
					}
				}
			}
            else printf("输入错误(上下左右移动，空格落子)或已到棋盘边界\n");
            x1=x;//记录玩家一的点位，便于悔棋 
            y1=y;
            showmap(map);
        }
        if(jud==0) showmap(map);
        if(b=='n') last=next; 
        else last=0;
		next=2;//下一轮
        while(jud==0){//玩家二上下左右移动，空格落子
        	if(b=='y')b='n';
            ch=getch();
            if(ch==224)ch=getch();
            system("cls");
            if(ch==72&&x!=0){//上移
                map[x][y]=last;
                x--;
                last=map[x][y];
                map[x][y]=next;
            }
            else if(ch==80&&x!=14){//下移
                map[x][y]=last;
                x++;
                last=map[x][y];
                map[x][y]=next;
            }
            else if(ch==75&&y!=0){//左移
                map[x][y]=last;
                y--;
                last=map[x][y];
				map[x][y]=next;
            }
            else if(ch==77&&y!=14){//右移
                map[x][y]=last;
                y++;
                last=map[x][y];
				map[x][y]=next;
            }
            else if(ch==32) {
                if(last!=0) printf("此处已有棋子\n");
                else{
                    jud=Judge(map,x,y,2);
                    if(jud==2) printf("玩家二(○)胜利！\n");
                    else if(jud==3) printf("平局！\n");
                    break;
                }
            }
            else if(ch==98) {//悔棋 
            	printf("玩家二(○)是否同意玩家一(●)悔棋[y/n]?\n");
            	showmap(map);
				b=getch();
				while(b!='y'&&b!='n'){
					printf("\n输入错误，请输入[y/n]");
					b=getch();
				}
				system("cls");
            	if(b=='y'){
            		map[x][y]=last;//恢复现在位置原始状态 
            		x=x1;//回到之前下子的点 
            		y=y1;
					break;
				}
			}
            else printf("输入错误或已到棋盘边界\n");
            x2=x;//记录玩家二的点位，便于悔棋
			y2=y; 
            showmap(map);
        }
        if(b=='n') last=next; 
        else last=0;
		next=1;//下一轮 
		showmap(map);
    }
}
int Judge(int map[][15],int x,int y,int turn){//用于判断是否胜利 
	int count=1,x1,y1,i=0,j;//count用于判断是否有连续五个 
	x1=x;
	y1=y;
	while(y1>0&&count<5){//横向判断 
		y1--;
		if(map[x1][y1]==turn) count++;
		else break;
	}
	if(count==5) return turn;
	y1=y;
	while(y1<15&&count<5){
		y1++;
		if(map[x1][y1]==turn) count++;
		else break;
	}
	if(count==5) return turn;
	y1=y;
	count=1;
	while(x1>0&&count<5){//纵向判断 
		x1--;
		if(map[x1][y1]==turn) count++;
		else break;
	}
	if(count==5) return turn;
	x1=x;
	while(x1<15&&count<5){
		x1++;
		if(map[x1][y1]==turn) count++;
		else break;
	}
	if(count==5) return turn;
	x1=x;
	count=1;
	while(x1>0&&y1>0&&count<5){//左斜判断 
		x1--;
		y1--;
		if(map[x1][y1]==turn) count++;
		else break;
	}
	if(count==5) return turn;
	x1=x;
	y1=y;
	while(x1<15&&y1<15&&count<5){
		x1++;
		y1++;
		if(map[x1][y1]==turn) count++;
		else break;
	}
	if(count==5) return turn;
	x1=x;
	y1=y;
	count=1;
	while(x1>0&&y1<15&&count<5){//右斜判断 
		x1--;
		y1++;
		if(map[x1][y1]==turn) count++;
		else break;
	}
	if(count==5) return turn;
	x1=x;
	y1=y;
	while(x1<15&&y1>0&&count<5){
		x1++;
		y1--;
		if(map[x1][y1]==turn) count++;
		else break;
	}
	if(count==5) return turn;
	count=0;
	while(i<15&&count==0){//判断是否平局 
		for(j=0;j<15;j++){
			if(map[i][j]==0){
				count++;
				break;
			}
		}
		i++;
	}
	if(count!=0) return 0;
	else return 3;
}
void showmap(int map[][15]){//输出棋盘 
	int i,j;
	for(i=0;i<15;i++){
   		if(i==0){//第一行 
   			if(map[i][0]==0)printf("┌ ");
   			if(map[i][0]==1)printf("●");
   			if(map[i][0]==2)printf("○");
   			for(j=1;j<14;j++){//第2-14列 
   				if(map[i][j]==0)printf("┬ ");
   				if(map[i][j]==1)printf("●");
   				if(map[i][j]==2)printf("○");
			} 
			if(map[i][14]==0)printf("┐");
			if(map[i][14]==1)printf("●");
   			if(map[i][14]==2)printf("○"); 
   			printf("\n");
		}
		if(i>0&&i<14){//第2-14行 
			if(map[i][0]==0)printf("├ ");
   			if(map[i][0]==1)printf("●");
   			if(map[i][0]==2)printf("○");
   			for(j=1;j<14;j++){//第2-14列 
   				if(map[i][j]==0)printf("┼ ");
   				if(map[i][j]==1)printf("●");
   				if(map[i][j]==2)printf("○");
			} 
			if(map[i][14]==0)printf("┤");
			if(map[i][14]==1)printf("●");
   			if(map[i][14]==2)printf("○");
   			printf("\n");
		}
		if(i==14){//第15行 
			if(map[i][0]==0)printf("└ ");
   			if(map[i][0]==1)printf("●");
   			if(map[i][0]==2)printf("○");
   			for(j=1;j<14;j++){//第2-14列 
   				if(map[i][j]==0)printf("┴ ");
   				if(map[i][j]==1)printf("●");
   				if(map[i][j]==2)printf("○");
			} 
			if(map[i][14]==0)printf("┘");
			if(map[i][14]==1)printf("●");
   			if(map[i][14]==2)printf("○");
		}
	}
}
