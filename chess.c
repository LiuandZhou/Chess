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
	system("color 06"); //������ɫ
	UI();//������Ϸǰ�Ľ��� 
	system("pause");
	system("cls");
	menu();
	again=getch();
	while(again!='y'&&again!='n'){//���� 
		printf("						�������!\n");
		again=getch();
	}
	if(again=='y')system("cls");
	while(again=='y'){
		play();//������Ϸ 
		printf("\n����һ�Σ�[y/n]\n");
		again=getch();
		while(again!='y'&&again!='n'){
			printf("���������ѡ���Ƿ�����һ��[y/n]\n");
			again=getch();
		}
		if(again=='y')system("cls");
	}
    printf("��Ϸ������"); 
}
void UI(){//������� 
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
	printf("   ******************                  *************                 **        **     **             **           **                            **\n");//�ڶ��� 
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
	printf("						|                   ���������               |\n");
	printf("						|         ��Ϸ�淨:                          |\n");
	printf("						|         1.ʹ�á����������ƶ�����           |\n");
	printf("						|         2.���ո��ȷ������                 |\n");
	printf("						|         3.��B�����壬����þ�������ͬ��    |\n");
	printf("						|         ��ʼ��Ϸ[y]    �˳���Ϸ[n]         |\n");
	printf("						----------------------------------------------\n");
}
void play(){//������Ϸ����
    int x=7,y=7,jud=0,last=0,next=1,ch,i,j,map[15][15],x1=7,x2=7,y1=7,y2=7,ju=1;//x����y��,jud=0��ʾδ��������1��ʾ���һ��ʤ��2��ʾ��Ҷ���ʤ��ju���ڷ�ֹ���һ���ͻ��� 
    char b='n';
    for(i=0;i<15;i++){
    	for(j=0;j<15;j++)
    		if(i==7&&j==7) map[i][j]=1; 
			else map[i][j]=0;//��0��1��2��ʾ���̴���ĳ�ӻ򲻴������ӣ�0��ʾ��1��ʾ���壬2��ʾ���� 
	}
    printf("��Ϸ��ʼ!\n");
    showmap(map);
    while(jud==0){//�ж�˭ʤ�� 
        while(jud==0){//���һ���������ƶ����ո�����
            if(b=='y')b='n';//�Ѿ�����ɹ����˲�Ϊ�˷�����һ�����Ӳ���Ӱ�� 
			ch=getch();
            if(ch==224)ch=getch();
            system("cls");
            if(ch==72&&x!=0){//����
                map[x][y]=last;//lastΪǰһ��λ�õ�״̬������Ϊ�ָ�ǰһ����λ��״̬ 
                x--;
                last=map[x][y];
                map[x][y]=next;//next��¼�������ӵ�״̬�����ڷ�ֹ���Ӹ����Լ����� 
            }
            else if(ch==80&&x!=14){//����
                map[x][y]=last;
                x++;
                last=map[x][y];
                map[x][y]=next;
            }
            else if(ch==75&&y!=0){//����
                map[x][y]=last;
                y--;
                last=map[x][y];
				map[x][y]=next;
            }
            else if(ch==77&&y!=14){//����
                map[x][y]=last;
                y++;
                last=map[x][y];
				map[x][y]=next;
            }
            else if(ch==32) {
                if(last!=0) printf("�˴���������\n");//��ֹ�������� 
                else{
                	if(ju==1) ju++;
                    jud=Judge(map,x,y,1);
                    if(jud==1) printf("���һ(��)ʤ����\n");
                    else if(jud==3) printf("ƽ�֣�\n");
                    break;
                }
            }
            else if(ch==98) {//���� 
            	if(ju==1) printf("�㻹δ���ӣ��޷�����\n"); 
            	else{
            		printf("���һ(��)�Ƿ�ͬ����Ҷ�(��)����[y/n]?\n");
            		showmap(map);
					b=getch();
					while(b!='y'&&b!='n'){
						printf("\n�������������[y/n]");
						b=getch();
					}
					system("cls");
            		if(b=='y'){
            			map[x][y]=last;//�ָ�����λ��ԭʼ״̬ 
            			x=x2;//�ص�֮ǰ���ӵĵ� 
            			y=y2;
						break;
					}
				}
			}
            else printf("�������(���������ƶ����ո�����)���ѵ����̱߽�\n");
            x1=x;//��¼���һ�ĵ�λ�����ڻ��� 
            y1=y;
            showmap(map);
        }
        if(jud==0) showmap(map);
        if(b=='n') last=next; 
        else last=0;
		next=2;//��һ��
        while(jud==0){//��Ҷ����������ƶ����ո�����
        	if(b=='y')b='n';
            ch=getch();
            if(ch==224)ch=getch();
            system("cls");
            if(ch==72&&x!=0){//����
                map[x][y]=last;
                x--;
                last=map[x][y];
                map[x][y]=next;
            }
            else if(ch==80&&x!=14){//����
                map[x][y]=last;
                x++;
                last=map[x][y];
                map[x][y]=next;
            }
            else if(ch==75&&y!=0){//����
                map[x][y]=last;
                y--;
                last=map[x][y];
				map[x][y]=next;
            }
            else if(ch==77&&y!=14){//����
                map[x][y]=last;
                y++;
                last=map[x][y];
				map[x][y]=next;
            }
            else if(ch==32) {
                if(last!=0) printf("�˴���������\n");
                else{
                    jud=Judge(map,x,y,2);
                    if(jud==2) printf("��Ҷ�(��)ʤ����\n");
                    else if(jud==3) printf("ƽ�֣�\n");
                    break;
                }
            }
            else if(ch==98) {//���� 
            	printf("��Ҷ�(��)�Ƿ�ͬ�����һ(��)����[y/n]?\n");
            	showmap(map);
				b=getch();
				while(b!='y'&&b!='n'){
					printf("\n�������������[y/n]");
					b=getch();
				}
				system("cls");
            	if(b=='y'){
            		map[x][y]=last;//�ָ�����λ��ԭʼ״̬ 
            		x=x1;//�ص�֮ǰ���ӵĵ� 
            		y=y1;
					break;
				}
			}
            else printf("���������ѵ����̱߽�\n");
            x2=x;//��¼��Ҷ��ĵ�λ�����ڻ���
			y2=y; 
            showmap(map);
        }
        if(b=='n') last=next; 
        else last=0;
		next=1;//��һ�� 
		showmap(map);
    }
}
int Judge(int map[][15],int x,int y,int turn){//�����ж��Ƿ�ʤ�� 
	int count=1,x1,y1,i=0,j;//count�����ж��Ƿ���������� 
	x1=x;
	y1=y;
	while(y1>0&&count<5){//�����ж� 
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
	while(x1>0&&count<5){//�����ж� 
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
	while(x1>0&&y1>0&&count<5){//��б�ж� 
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
	while(x1>0&&y1<15&&count<5){//��б�ж� 
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
	while(i<15&&count==0){//�ж��Ƿ�ƽ�� 
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
void showmap(int map[][15]){//������� 
	int i,j;
	for(i=0;i<15;i++){
   		if(i==0){//��һ�� 
   			if(map[i][0]==0)printf("�� ");
   			if(map[i][0]==1)printf("��");
   			if(map[i][0]==2)printf("��");
   			for(j=1;j<14;j++){//��2-14�� 
   				if(map[i][j]==0)printf("�� ");
   				if(map[i][j]==1)printf("��");
   				if(map[i][j]==2)printf("��");
			} 
			if(map[i][14]==0)printf("��");
			if(map[i][14]==1)printf("��");
   			if(map[i][14]==2)printf("��"); 
   			printf("\n");
		}
		if(i>0&&i<14){//��2-14�� 
			if(map[i][0]==0)printf("�� ");
   			if(map[i][0]==1)printf("��");
   			if(map[i][0]==2)printf("��");
   			for(j=1;j<14;j++){//��2-14�� 
   				if(map[i][j]==0)printf("�� ");
   				if(map[i][j]==1)printf("��");
   				if(map[i][j]==2)printf("��");
			} 
			if(map[i][14]==0)printf("��");
			if(map[i][14]==1)printf("��");
   			if(map[i][14]==2)printf("��");
   			printf("\n");
		}
		if(i==14){//��15�� 
			if(map[i][0]==0)printf("�� ");
   			if(map[i][0]==1)printf("��");
   			if(map[i][0]==2)printf("��");
   			for(j=1;j<14;j++){//��2-14�� 
   				if(map[i][j]==0)printf("�� ");
   				if(map[i][j]==1)printf("��");
   				if(map[i][j]==2)printf("��");
			} 
			if(map[i][14]==0)printf("��");
			if(map[i][14]==1)printf("��");
   			if(map[i][14]==2)printf("��");
		}
	}
}
