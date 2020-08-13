// 例11-5 向二进制文件输出
// 
#include <fstream>
using namespace std;
struct Date { 
    int mon, day, year;  
};
int main() {
    Date dt = { 6, 10, 92 };
    ofstream file("date.dat", ios_base::binary);
    file.write(reinterpret_cast<char *>(&dt),sizeof(dt));
    file.close();
    return 0;
}