/*
 *   file: md5.hpp
 *   author: Els-y
 *   time: 2017-10-16 21:08:21
*/
#ifndef _MD5_H
#define _MD5_H

#include <string>
#include <vector>
#include <cstring>
#include <cmath>
#include <iostream>
#include <bitset>
using std::string;
using std::vector;
using std::bitset;
using std::cout;
using std::endl;
using std::sin;
using std::abs;

// default little-endian
class MD5 {
public:
    MD5();
    ~MD5();
    string encrypt(string plain);
    // �����չ�����Ϣ
    void print_buff();

private:
    // 128 λ MD ��������md[0...3] = {A, B, C, D}
    vector<unsigned int> md;
    // �洢��չ�����Ϣ
    unsigned char* buffer;
    // ��չ�����Ϣ���ȣ����ֽ�Ϊ��λ
    unsigned int buffer_len;
    // ��� 4 ���ֺ���������
    unsigned int (MD5::* round_funcs[4])(unsigned int, unsigned int, unsigned int);

    // ��ʼ�� MD ������
    void init_md();
    // ��� padding �� length
    void padding(string plain);
    void clear();
    void h_md5(int groupid);
    // 4 ���ֺ���
    unsigned int f_rf(unsigned int x, unsigned int y, unsigned int z);
    unsigned int g_rf(unsigned int x, unsigned int y, unsigned int z);
    unsigned int h_rf(unsigned int x, unsigned int y, unsigned int z);
    unsigned int i_rf(unsigned int x, unsigned int y, unsigned int z);
    // ���� MD ������ת����� string ��ʽ���� 
    string md2str();
    // ���� buffer �� [pos, pos + 3] �ĸ��ֽڰ��� little-endian ��ɵ� X
    unsigned int uchar2uint(int pos);
    // ���� unsigned char ��Ӧ��ʮ������ string
    string uchar2hex(unsigned char uch);
    // ���� val ѭ�����ơ�bits λ��ֵ
    unsigned int cycle_left_shift(unsigned int val, int bits);
    // ���ص� round �ֵ����У��� step������ X ��Ӧ�±�
    int get_x_index(int round, int step);
};

#endif
