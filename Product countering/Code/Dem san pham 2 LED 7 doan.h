#include <16F877A.h> // dinh kem thu vien dinh nghia cua PIC 16F877A
#device ADC=8 // dat ADC o che do 8 bit 
#FUSES HS // su dung thach anh ngoai lam bo giao d�ng
#use delay(clock=4000000) // su dung thach anh 20M
int8 so_dem; // khai bao bien gia tri so dem duoc 
int8 ty_le_cb; // ty le cam bien dan 
int1 muc=0; // muc xac dinh cua cam bien
int1 co_vat=0; // bao co vat can hay khong
int8 cham=0xff; // dau cham hien thi tren LED 7 doan bao c� vat hay khong 
const char ma7doan[]={0xC0,0xF9,0xA4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90}; //khai bao ma 7 doan tich cuc muc thap ( ki tu 8 bit )
//                       0    1    2    3    4    5    6    7    8    9


