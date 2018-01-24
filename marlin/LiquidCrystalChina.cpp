#include "LiquidCrystalChina.h"
extern "C" 
{
#include "Arduino.h"
#include <wiring.h> 
#include <inttypes.h>
#include <stdio.h>  //not needed yet
#include <string.h> //needed for strlen()
#include <avr/pgmspace.h>
}

void LiquidCrystalChina::WriteByte(int dat)
{
    digitalWrite(latchPin, HIGH);
    delayns();
    shiftOut(dataPin, clockPin, MSBFIRST, dat);
    digitalWrite(latchPin, LOW);
}

void LiquidCrystalChina::delayns(void)
{   
	delayMicroseconds(300);
 }

void LiquidCrystalChina::WriteCommand(int CMD)
{
   int H_data,L_data;
   H_data = CMD;
   H_data &= 0xf0;           //���ε�4λ������
   L_data = CMD;             //xxxx0000��ʽ
   L_data &= 0x0f;           //���θ�4λ������
   L_data <<= 4;             //xxxx0000��ʽ
   WriteByte(0xf8);          //RS=0��д�����ָ�
   WriteByte(H_data);
   WriteByte(L_data);
}


void LiquidCrystalChina::WriteData(int CMD)
{
   int H_data,L_data;
   H_data = CMD;
   H_data &= 0xf0;           //���ε�4λ������
   L_data = CMD;             //xxxx0000��ʽ
   L_data &= 0x0f;           //���θ�4λ������
   L_data <<= 4;             //xxxx0000��ʽ
   WriteByte(0xfa);          //RS=1��д���������
   WriteByte(H_data);
   WriteByte(L_data);
}


void LiquidCrystalChina::clear(void)
{  
    WriteCommand(0x30);
    WriteCommand(0x01);
}


void LiquidCrystalChina::DisplayString(int X,int Y,uchar *ptr)
{
  int i;

  switch(X)
   {
     case 0:  Y|=0x80;break;

     case 1:  Y|=0x90;break;

     case 2:  Y|=0x88;break;

     case 3:  Y|=0x98;break;

     default: break;
   }
  WriteCommand(Y); // ��λ��ʾ��ʼ��ַ

  i=0;
  while(ptr[i]!='\0'){ 
      WriteData(ptr[i]);
      i++;
  }

}

void LiquidCrystalChina::DisplaySig(int M,int N,int sig)
{
  switch(M)
   {
     case 0:  N|=0x80;break;

     case 1:  N|=0x90;break;

     case 2:  N|=0x88;break;

     case 3:  N|=0x98;break;

     default: break;
   }
  WriteCommand(N); // ��λ��ʾ��ʼ��ַ
  WriteData(sig); //��������ַ�
 }


void LiquidCrystalChina::print(char *ptr)
{
  int i;
  unsigned char *ptr2;
  ptr2=(unsigned char*)ptr;
  i=0;
  while(ptr2[i]!='\0')
    { 
      WriteData(ptr2[i]);
      i++;
      if (i>15) break;
    }
}

void LiquidCrystalChina::print(unsigned char  *ptr)
{
  int i;
  i=0;
  while(ptr[i]!='\0')
    { 
      WriteData(ptr[i]);
      i++;
      if (i>15) break;
    }
}

void LiquidCrystalChina::write(char ptr)
{
   WriteData((unsigned char)ptr);
}

void LiquidCrystalChina::print(char ptr)
{
   WriteData((unsigned char)ptr);
}

void LiquidCrystalChina::write(uchar ptr)
{
   WriteData(ptr);
}

void LiquidCrystalChina::print(uchar ptr)
{
   WriteData(ptr);
}

LiquidCrystalChina::LiquidCrystalChina(uint8_t di,  uint8_t e,uint8_t rw)
{
  init(di,e, rw);
}

void LiquidCrystalChina::init( uint8_t di, uint8_t e,uint8_t rw)
{
    latchPin = di;
    clockPin = e;
    dataPin = rw;
    begin(8, 4); 
}

void LiquidCrystalChina::begin(uint8_t cols, uint8_t lines) {

    pinMode(latchPin, OUTPUT);     
    pinMode(clockPin, OUTPUT);    
    pinMode(dataPin, OUTPUT);
    digitalWrite(latchPin, LOW);
    delayns();

    WriteCommand(0x30);        //�����趨������
    WriteCommand(0x0c);        //��ʾ���ؿ�����
    WriteCommand(0x01);        //�����Ļ������
    WriteCommand(0x06);        //�����趨�������
}


void LiquidCrystalChina::setCursor(uint8_t N, uint8_t M)
{
  switch(M)
   {
     case 0:  N|=0x80;break;

     case 1:  N|=0x90;break;

     case 2:  N|=0x88;break;

     case 3:  N|=0x98;break;

     default: break;
   }
  WriteCommand(N); 
}


