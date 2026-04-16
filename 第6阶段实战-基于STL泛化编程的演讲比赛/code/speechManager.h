#pragma once 
#include <iostream>
using namespace std;
#include <vector>
#include <map>
#include "speaker.h"
#include <algorithm>
#include <deque>
#include <functional>
#include <numeric>
#include <string>
#include <fstream>


//演讲管理类
class SpeechManager
{
public:

	//构造函数
	SpeechManager();

	//菜单功能
	void show_Menu();

	//退出系统
	void exitSystem();

	//析构函数
	~SpeechManager();

	//初始化演讲比赛
	void initSpeech();

	//创建12个选手
	void createSpeaker();

	//开始比赛 整个比赛流程控制
	void startSpeech();

	//抽签
	void speechDraw();

	//比赛
	void speechContest();

	//显示分数
	void showScore();

	//保存记录
	void saveRecord();

	//获取记录
	void loadRecord();

	//显示往届记录
	void showRecord();

	//清空文件
	void clearRecord();


	//判断文件是否为空
	bool fileIsEmpty;

	//往届记录容器
	map<int, vector<string>>m_Record;

	//成员属性
	//第一轮比赛选手编号容器
	vector<int>v1;

	//第二轮比赛选手编号容器
	vector<int>v2;

	//胜利前三名选手编号容器
	vector<int>vVictory;

	//存放编号以及对应的具体选手
	map<int, Speaker>m_Speaker;

	//比赛轮数 
	int m_Index;

};