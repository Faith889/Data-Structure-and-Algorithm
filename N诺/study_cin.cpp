#include <string> 
#include <iostream>
using namespace std;

//当cin>>从缓冲区中读取数据时，若缓冲区中第一个字符是空格、tab或换行这些分隔符时，cin>>会将其忽略并清除，继续读取下一个字符，若缓冲区为空，则继续等待。但是如果读取成功，字符后面的分隔符是残留在缓冲区的，cin>>不做处理。
int main()
{
    char a;
    int b;
    float c;
    string str;
    cin>>a>>b>>c>>str;
    cout<<a<<" "<<b<<" "<<c<<" "<<str<<endl;

    string test;
    getline(cin,test);//不阻塞
    cout<<"test:"<<test<<endl;
    system("pause");
    return 0;
}

//cin>>对缓冲区中的第一个换行符视而不见，采取的措施是忽略清除，继续阻塞等待缓冲区有效数据的到来。但是，getline()读取数据时，并非像cin>>那样忽略第一个换行符，getline()发现cin的缓冲区中有一个残留的换行符，不阻塞请求键盘输入，直接读取，送入目标字符串后，再将换行符替换为空字符’\0’
