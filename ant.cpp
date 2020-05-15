#include <iostream>
using namespace std;
int m=60,n=188,t=20000;//变量代替，方便改动大小 
char room[60][188];  //设定区域高和宽 
int before[2]={94,30};//设定初始位置 
int now[2]={94,31};	  //与初始方向 

void change0()//转变函数0 
{
	room[now[1]][now[0]]='B';
	before[0]=now[0];
 	before[1]=now[1];
}

void change1()//转变函数1 
{
	room[now[1]][now[0]]=' ';
	before[0]=now[0];
 	before[1]=now[1];
}

void move()//蚂蚁移动一步情况 
{

 	if(before[0]>now[0]&&before[1]==now[1])//朝左 
 	{
 		if(room[now[1]][now[0]]==' ')//空白 左转 
 		{
 			change0();
 			now[1]++;
		 }
		 else if(room[now[1]][now[0]]=='B')//黑色 右转 
 		{
 			change1();
 			now[1]--;
		 }
	 }
	else if(before[0]<now[0]&&before[1]==now[1])//朝右
	 {
	 	if(room[now[1]][now[0]]==' ')//空白 左转 
 		{
 			change0();
 			now[1]--;
		 }
		else if(room[now[1]][now[0]]=='B')//黑色 右转 
 		{
 			change1();
 			now[1]++;
		 }
	  }
	else if(before[0]==now[0]&&before[1]<now[1])//朝下 
 	{
 		if(room[now[1]][now[0]]==' ')//空白 左转 
 		{
 			change0();
 			now[0]++;
		 }
		else if(room[now[1]][now[0]]=='B')//黑色 右转 
 		{
 			change1();
 			now[0]--;
		 }
	 }
 	else if(before[0]==now[0]&&before[1]>now[1])//朝上 
 	{
 		if(room[now[1]][now[0]]==' ')//空白 左转 
 		{
 			change0();
 			now[0]--;
		 }
		else if(room[now[1]][now[0]]=='B')//黑色 右转 
 		{
 			change1();
 			now[0]++;
		 }
	 }
 }

int main()
{
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		room[i][j]=' ';//设定空白填充符 
	}
	
	//新增功能，设定初始地图
	cout<<"填充一些黑块，输入要加的个数。" <<endl;
	int e;
	cin>>e;
	if(e!=0)
	for(int c=0;c<=e-1;c++)//循环 d 次 
	{
		cout<<"格式为 横坐标加空格加纵坐。"<<endl;
		int a,b;
		cin>>a>>b;
		if(a<=n&&b<=m)
		{
			room[b][a]='B';
		} 
	}
	
	//room[30][90]='B';//???直接换了个方向 
	
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
			cout<<room[i][j];
		cout<<endl;
	}//以上为初始化区域并输出空白区域
	cout<<endl;//换行，免得连在一起 
	for(int k=1;k<=t;k++)//蚂蚁行动 t 次 
	{
		move();
	}
	for(int i=1;i<=m;i++)//以下为输出运动结果 
	{
		for(int j=1;j<=n;j++)
		{
			cout<<room[i][j];
		}
		cout<<endl;
	}
	return 0; 
}
