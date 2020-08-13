// 例11-6用ostringstream将数值转换为字符串  
//
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

//函数模板toString可以将各种支持“<<“插入符的类型的对象转换为字符串。
template <class T>
inline string toString(const T &v) {
    ostringstream os;   //创建字符串输出流
    os << v;        //将变量v的值写入字符串流
    return os.str();    //返回输出流生成的字符串
}

int main() {
    string str1 = toString(5);
    cout << str1 << endl;
    string str2 = toString(1.2);
    cout << str2 << endl;
    return 0;
}