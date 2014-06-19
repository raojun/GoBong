#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

#define N 15

char* CheckWin(int x,int y,char* bWho);

	//┏┳┓
	//┣╋┫
	//┗┻┛
	// ━┃
	
char* chess[N][N]={
	"┏","┳","┳","┳","┳","┳","┳","┳","┳","┳","┳","┳","┳","┳","┓",		
	"┣","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","┫",
	"┣","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","┫",
	"┣","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","┫",
	"┣","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","┫",
	"┣","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","┫",
	"┣","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","┫",
	"┣","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","┫",
	"┣","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","┫",
	"┣","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","┫",
	"┣","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","┫",
	"┣","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","┫",
	"┣","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","┫",
	"┣","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","┫",
	"┗","┻","┻","┻","┻","┻","┻","┻","┻","┻","┻","┻","┻","┻","┛",
};

void ShowChess()
{	
	system("cls");//清屏
	printf("%s","  ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("%s","  ┃  *********          五 * 子 * 棋          *********  ┃\n");
	printf("%s","  ┃  *********                                *********  ┃\n");
	printf("%s","  ┃  *********           制作：饶俊           *********  ┃\n");
	printf("%s","  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
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
				printf("%s","━");
			}
		}
		printf("%c",i+'A');
		printf("\n");
		if(i<N-1)
		{

			for(int k=0;k<N;k++)
			{
				printf("%s","  ┃");
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


//○ ●
void MoveChess()
{
	static bool hWho=false;
	hWho=!hWho;
	char *bWho=hWho?"●":"○";

	int x,y;
	char sPos[3];
	while(1)
	{
		fflush(stdin);//清空输入缓存，不影响后面输入
		clearerr(stdin);//清楚错误标记
		
		x=-1;
		y=-1;
		memset(sPos,0,sizeof(sPos)*3);

		printf("请%s方输入落子坐标(0投降):",bWho);
		gets(sPos);
		_strupr(sPos);

		if(sPos[0]=='0')//投降
		{
			printf("%s方投降，在玩一局?",bWho);
			exit(0);
		}

		if((sPos[0]>='A'&&sPos[0]<='O')&&(sPos[1]>='A'&&sPos[1]<='O'))
		{
			y=sPos[0]-'A';//落子坐标
			x=sPos[1]-'A';
		}
		else
			continue;

		if (chess[x][y] == "●" || chess[x][y] == "○") continue;
				
		break;
	}
	
	chess[x][y]=bWho;

	char *winner=CheckWin(x,y,bWho);
	if(winner==bWho)
	{
		ShowChess();
		printf("%s赢了!\n",bWho);
		exit(0);
	}
	
}

char* CheckWin(int x,int y,char* bWho)
{
	int num;//连子的个数
	int i,j;

	//1 判断左上至右下是否5连
	//1.1 从落子点向左上方向判断
	num=0;
	i=x;
	j=y;
	while(chess[i][j]==bWho)
	{
		num++;
		if(num==5)//已经5子相连
			return bWho;
		i--;
		j--;

		if(i<0||j<0)
			break;
	}

	//1.2 从落子点向右下方向判断
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

	//2 判断右上至左下是否5连
	//2.1 从落子点向右上方向判断
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
	//2.2 从落子点向左下方向判断
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
	
	//3 横向判断是否5连
	//3.1 从落子点向左判断
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
	//3.2 从落子点向右判断
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

	//4 竖向判断是否5连
	//4.1 从落子点向上判断
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
	//4.2 从落子点向下判断
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
	//5 平局
	return "";
}

int main()
{
	HWND hWnd = ::GetForegroundWindow();
	if (hWnd)
	{
		::SetWindowText(hWnd, "五子棋    制作：饶俊");
		::ShowWindow(hWnd, SW_MAXIMIZE);
	}
	
	while(1)
	{
		ShowChess();
		MoveChess();
	}
	return 0;
}
