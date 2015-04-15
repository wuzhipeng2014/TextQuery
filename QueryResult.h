#pragma once
#include <string>
#include <vector>
#include <set>
#include <map>
#include <memory>

using namespace std;
class QueryResult
{
	using line_no = vector<string>::size_type;
public:
	QueryResult();
	~QueryResult();
	QueryResult(string s, shared_ptr<set<line_no>> p, shared_ptr<vector<string>> f) :sought(s), lines(p), file(f)
	{}
public:
	string sought; //查询的单词
	shared_ptr<set<line_no>> lines; //出现的行号，保存在一个set<line_no>中
	shared_ptr<vector<string>> file; // 输入的文件
};

