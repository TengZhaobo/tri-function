// ���������sin��������������ȷ��
#include<iostream>
#include<fstream>
#include <cstdlib>
#include <time.h>
#include <typeinfo>
#include"Trifuncs_test.h"
constexpr auto PI = 3.1415926;
using namespace std;

bool Equal(double num1, double num2)
{
    if ((num1 - num2 > -0.0001) && (num1 - num2 < 0.0001))  //���Ǿ���ΪС�����4λ��
        return true;
    else
        return false;
}

int main()
{
    //0 90 -90 1800/20 ���Ա߽�ֵ�ı���
    double input[] = { 0,90,-600,360000 / 20 };
    double result = 0;  //��ʼ��һ���������ڴ����д�����ļ�����
    double accuration = 0;    //�����ȷ���
    double input_aftertrans = 0;  //������ֵ����ת��
    int i;
    int count1 = sizeof(input) / sizeof(input[0]);

    for (i = 0; i < count1; i++)
    {
        input_aftertrans = inputtrans(input[i]);
        cout << "����ֵΪ��" << input[i] << endl;
        accuration = cos(input_aftertrans);
        result = snowcos(input_aftertrans);
        cout << result << endl;
        //cout << "The same result ?" << Equal(result, accuration) << endl;
        if (Equal(result, accuration)) {
            cout << "Test passed��" << endl;           //�������sin����Զ���snowsin����ֵ�����һ����Χ������Ϊ����ͨ��
        }
        else {
            cout << "Test failed��" << endl;            //�������sin����Զ���snowsin����ֵ����һ����Χ������Ϊ����ʧ��
        }
    }


}