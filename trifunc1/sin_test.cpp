// ���������sin��������������ȷ��
#include<iostream>
#include <cstdlib>
#include <time.h>
#include <typeinfo>
#include"Trifuncs_test.h"
constexpr auto PI = 3.1415926;
using namespace std;

bool Equal(double num1, double num2)
{
    if ((num1 - num2 > -0.0000001) && (num1 - num2 < 0.0000001))
        return true;
    else
        return false;
}

int main()
{
    double result = 0;  //��ʼ��һ���������ڴ����д�����ļ�����
    double accuration = 0;    //�����ȷ���
    double r2 = 0;
    double a[5];
    int j=0;
    cout << snowsin(30* 0.0174533) << endl;
    cout << "RAND_MAX:" << RAND_MAX << endl;
    srand(static_cast <signed> (time(0)));
    //rand((unsigned)time(NULL));
    for (int i = 0; i < 5; i++)
    {
        j = i;

        a[j] = rand();
        //result = snowsin(9550.266);
        //randmath = (double)rand();
        //accuration = sin(rand());
        //cout << (double)rand()<< endl;
        while (a[j] >= 360.0)//����x�ķ�Χ
        {
            a[j] -= 360.0;
        }
        return (a[j] * PI / 180.0);//�Ƕ�or����


        //cout << static_cast <double> (rand()) / (static_cast <double> (RAND_MAX / 1000)) << endl;
        //result = snowsin(static_cast <double> (rand()) / (static_cast <double> (RAND_MAX / 1000)));
        cout << "�������" << a[j] << endl;
        cout << sin(a[j]*0.0174533) << endl;
        cout << static_cast <double> (a[j]) << endl;
        //cout << "The show of aj is " << typeid(a[j]).name() << endl;
        result = snowsin(a[j]);


        //cout << "The show of result is " << typeid(result).name() << endl;
        //cout << snowsin(static_cast <double> (a[j])) << endl;
    
        cout << result << endl;
        //printf(Equal(result, accuration));
        //cout << Equal(result, accuration) << endl;
    }

}