#pragma once
#include <iostream>
#include <memory>
#include <vector>
#include <sstream>
#include <fstream>
#include <map>
#include "QueryResult.h"
using namespace std;
class TextQuery
{
	using line_no = vector<string>::size_type;
public:
	TextQuery();
	~TextQuery();
	//�˹��캯�����������������ݴ洢��һ��vector�У�����ÿ�����ʼ������Ƶ�ʱ�����һ��map��
	TextQuery(ifstream &ifs) :file(new vector<string>())
	{
		string text;
		while (getline(ifs,text))
		{
			file->push_back(text);
			int n = file->size() - 1;
			istringstream line(text, istringstream::in);
			string word;
			while (line>>word)
			{
				//�鿴��word�Ƿ���map��
				auto &lines = wm[word];
				if (!lines)
				{
					lines.reset(new set<line_no>);
				}
				lines->insert(n);
			}

		}
	}

	QueryResult query(string& s) 
	{
		static shared_ptr<set<line_no>> nodata(new set<line_no>);
		auto loc = wm.find(s);
		if (loc==wm.end())
		{
			return QueryResult(s, nodata, file);
		}
		else
		{
			return QueryResult(s, loc->second, file);
		}
	}



private:
	//file��������������ļ���ÿһ��
	shared_ptr<vector<string>> file;

	//wm�������������ļ��е�ÿһ�����ʼ�����ֵ��кŵ�����ָ�루line_no������һ��set<line_no>�У�
	map < string, shared_ptr<set<line_no>>> wm;
};

