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
	string sought; //��ѯ�ĵ���
	shared_ptr<set<line_no>> lines; //���ֵ��кţ�������һ��set<line_no>��
	shared_ptr<vector<string>> file; // ������ļ�
};

