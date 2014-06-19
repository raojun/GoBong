#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

#define N 15

char* CheckWin(int x,int y,char* bWho);

	//���ש�
	//�ǩ��
	//���ߩ�
	// ����
	
char* chess[N][N]={
	"��","��","��","��","��","��","��","��","��","��","��","��","��","��","��",		
	"��","��","��","��","��","��","��","��","��","��","��","��","��","��","��",
	"��","��","��","��","��","��","��","��","��","��","��","��","��","��","��",
	"��","��","��","��","��","��","��","��","��","��","��","��","��","��","��",
	"��","��","��","��","��","��","��","��","��","��","��","��","��","��","��",
	"��","��","��","��","��","��","��","��","��","��","��","��","��","��","��",
	"��","��","��","��","��","��","��","��","��","��","��","��","��","��","��",
	"��","��","��","��","��","��","��","��","��","��","��","��","��","��","��",
	"��","��","��","��","��","��","��","��","��","��","��","��","��","��","��",
	"��","��","��","��","��","��","��","��","��","��","��","��","��","��","��",
	"��","��","��","��","��","��","��","��","��","��","��","��","��","��","��",
	"��","��","��","��","��","��","��","��","��","��","��","��","��","��","��",
	"��","��","��","��","��","��","��","��","��","��","��","��","��","��","��",
	"��","��","��","��","��","��","��","��","��","��","��","��","��","��","��",
	"��","��","��","��","��","��","��","��","��","��","��","��","��","��","��",
};

void ShowChess()
{	
	system("cls");//����
	printf("%s","  ����������������������������������������������������������\n");
	printf("%s","  ��  *********          �� * �� * ��          *********  ��\n");
	printf("%s","  ��  *********                                *********  ��\n");
	printf("%s","  ��  *********           �������Ŀ�           *********  ��\n");
	printf("%s","  ����������������������������������������������������������\n");
	printf("%s","\n");

	for(int m=0;m<N;m++)
	{
		printf("%s","   ");
		printf("%c",m+'A');
	}

	printf("%s","\n");	
	for(int i=0;i<N;i++)
	{
		printf("%s"," ");
		printf("%c",i+'A');
		for(int j=0;j<N;j++)
		{
			printf("%s",chess[i][j]);
			if(j<N-1)
			{
				printf("%s","��");
			}
		}
		printf("%c",i+'A');
		printf("\n");
		if(i<N-1)
		{

			for(int k=0;k<N;k++)
			{
				printf("%s","  ��");
			}	
			printf("\n");
		}
		
	}
	for(m=0;m<N;m++)
	{
		printf("%s","   ");
		printf("%c",m+'A');
	}
	printf("\n\n");
}


//�� ��
void MoveChess()
{
	static bool hWho=false;
	hWho=!hWho;
	char *bWho=hWho?"��":"��";

	int x,y;
	char sPos[3];
	while(1)
	{
		fflush(stdin);//������뻺�棬��Ӱ���������
		clearerr(stdin);//���������
		
		x=-1;
		y=-1;
		memset(sPos,0,sizeof(sPos)*3);

		printf("��%s��������������(0Ͷ��):",bWho);
		gets(sPos);
		_strupr(sPos);

		if(sPos[0]=='0')//Ͷ��
		{
			printf("%s��Ͷ��������һ��?",bWho);
			exit(0);
		}

		if((sPos[0]>='A'&&sPos[0]<='O')&&(sPos[1]>='A'&&sPos[1]<='O'))
		{
			y=sPos[0]-'A';//��������
			x=sPos[1]-'A';
		}
		else
			continue;

		if (chess[x][y] == "��" || chess[x][y] == "��") continue;
				
		break;
	}
	
	chess[x][y]=bWho;

	char *winner=CheckWin(x,y,bWho);
	if(winner==bWho)
	{
		ShowChess();
		printf("%sӮ��!\n",bWho);
		exit(0);
	}
	
}

char* CheckWin(int x,int y,char* bWho)
{
	int num;//���ӵĸ���
	int i,j;

	//1 �ж������������Ƿ�5��
	//1.1 �����ӵ������Ϸ����ж�
	num=0;
	i=x;
	j=y;
	while(chess[i][j]==bWho)
	{
		num++;
		if(num==5)//�Ѿ�5������
			return bWho;
		i--;
		j--;

		if(i<0||j<0)
			break;
	}

	//1.2 �����ӵ������·����ж�
	i=x+1;
	j=y+1;
	while(chess[i][j]==bWho)
	{
		num++;
		if(num==5)
			return bWho;
		i++;
		j++;

		if(i>N-1||j>N-1)
			break;
	}

	//2 �ж������������Ƿ�5��
	//2.1 �����ӵ������Ϸ����ж�
	num=0;
	i=x;
	j=y;
	while(chess[i][j]==bWho)
	{
		num++;
		if(num==5)
			return bWho;
		i++;
		j--;
		if(i>N-1||j<0)
			break;
	}
	//2.2 �����ӵ������·����ж�
	i=x-1;
	j=y+1;
	while(chess[i][j]==bWho)
	{
		num++;
		if(num==5)
			return bWho;
		i--;
		j++;
		if(i<0||j>N-1)
			break;
	}
	
	//3 �����ж��Ƿ�5��
	//3.1 �����ӵ������ж�
	num=0;
	i=x;
	j=y;
	while(chess[i][j]==bWho)
	{
		num++;
		if(num==5)
			return bWho;
		i--;
		if(i<0)
			break;
	}
	//3.2 �����ӵ������ж�
	i=x+1;
	while(chess[i][j]==bWho)
	{
		num++;
		if(num==5)
			return bWho;
		i++;
		if(i>N-1)
			break;
	}

	//4 �����ж��Ƿ�5��
	//4.1 �����ӵ������ж�
	num=0;
	i=x;
	j=y;
	while(chess[i][j]==bWho)
	{
		num++;
		if(num==5)
			return bWho;
		j--;
		if(j<0)
			break;
	}
	//4.2 �����ӵ������ж�
	j=y+1;
	while(chess[i][j]==bWho)
	{
		num++;
		if(num==5)
			return bWho;
		j++;
		if(j>N-1)
			break;
	}
	//5 ƽ��
	return "";
}

int main()
{
	HWND hWnd = ::GetForegroundWindow();
	if (hWnd)
	{
		::SetWindowText(hWnd, "������    �������Ŀ�");
		::ShowWindow(hWnd, SW_MAXIMIZE);
	}
	
	while(1)
	{
		ShowChess();
		MoveChess();
	}
	return 0;
}
