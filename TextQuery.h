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
	//此构造函数负责将输入流的内容存储到一个vector中，并将每个单词及其出现频率保存在一个map中
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
				//查看此word是否在map中
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
	//file用来保存输入的文件的每一行
	shared_ptr<vector<string>> file;

	//wm用来保存输入文件中的每一个单词及其出现的行号的智能指针（line_no保存在一个set<line_no>中）
	map < string, shared_ptr<set<line_no>>> wm;
};

