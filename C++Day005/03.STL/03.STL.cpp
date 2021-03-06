// 03.STL.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <map>
using std::map;
void VecTest() {
	vector<int> obj;
	// 从后端添加新元素
	obj.push_back(10);
	// 指定位置插入1个元素
	obj.insert(obj.begin(), 20);
	// 指定位置插入10个相同元素
	obj.insert(obj.begin(), 10, 100);
	// 指定位置插入另一个vector中的元素
	vector<int> obj2;
	obj2.insert(obj2.begin(), obj.begin(), obj.begin() + 10);
	// 删
	// 删除最后一个元素
	obj.pop_back();
	// 删除下标为1的元素
	obj.erase(obj.begin() + 1);
	// 删除下标2~4 3个元素
	obj.erase(obj.begin() + 2, obj.begin() + 5);
	// 改
	obj[3] = 200;
	// 查
	// 数组元素个数
	int nCount = obj.size();
	for (int i = 0; i < nCount; i++) {
		if (obj[i] == 100) {
			obj[i] += 100;
		}
	}
}

void StringTest() {
	string obj;
	// 增
	obj += "12345";
	obj.insert(obj.begin(), 'a');
	// 在0这个位置插入字符串1111
	obj.insert(0, "1111");
	// 删
	// 删除下标从0开始的两个元素
	obj.erase(0, 2);
	// 只删除1个
	obj.erase(obj.begin());
	// 全部删除
	obj.erase();
	// 改
	obj[1] = '0';
	// 查
	// 查找字符
	obj.find('0');
	// 查找字符串
	obj.find("1111");
	// 字符串比较
	obj == "1111";
	obj.compare("1111");
}

void MapTest() {
	map<const char*, int> score;
	// 增
	score["班长"] = 100;
	score["学习委员"] = 0;
	// 查
	if (score.find("班长") != score.end())
		printf("班长的成绩=%d", score["班长"]);
	// 删
	score.erase("班长");
	// 改
	score["学习委员"] = 60;
}

int main() {
	MapTest();
	return 0;
}

