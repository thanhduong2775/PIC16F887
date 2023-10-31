#include <Dem san pham 2 LED 7 doan.h>
void main() // chuong trinh chinh 
{
   so_dem=read_eeprom(0); // doc so dem cu duoc luu trong eeprom tai dia chi 0           
   setup_adc_ports(AN0); // thiêt lap kenh ADC AN0 lam ngo vao ADC dung de doc tin hieu tu mat thu hong ngoai
   setup_adc(ADC_CLOCK_INTERNAL); // thiet lap xung cap cho ADC là xung noi                                                                
   set_adc_channel(0); // dat kenh  cho ADC là kenh 0 (AN0)                                                           
   while(TRUE)  // vong lap vo han
   {                  
      output_b(ma7doan[so_dem/10%10]&cham); // xuât ma LED 7 doan hang chuc ra port B                   
      output_c(ma7doan[so_dem%10]); // xuât ma LED 7 doan hang don vi ra port C     
      delay_us(25); // tao thoi gian tre us                                         
      ty_le_cb=read_adc()*0.39; // doc ty lê % tín hieu tu mat thu hông ngoai (0-100); gia tri adc max=255; 0,39=100/255;   
      if(ty_le_cb>70) // khi ty le dan cua mat thu lon hon nguong (70) thì do là muc 1, tuc khong co vat can            
      {                             
         muc=1; // xac dinh muc 1;
         cham=0xff; // tat LED bao co vat can
      }                        
      if(ty_le_cb<30) // khi ty le dan cua mat thu nho hon nguong (30) thì do là muc 0, tuc co vat can 
      {
         muc=0; // xac dinh muc 0; 
         cham=0x7f; // bat led bao co vat can
         co_vat=1; // bao co vat can 
      }
      if(muc==1&&co_vat==1) // neu muc = 1 và co vat can // tuc vat can da di qua cam bien
      {                     
         co_vat=0; // bao khong co vat          
         so_dem++; // tang so dem                                     
         if(so_dem>99) // gioi han so dem den 99
         {
            so_dem=0; // dat lai so dem = 0 khi so dem > 99
         }
         write_eeprom(0, so_dem); // ghi so dem vao EEPROM tai dia chi 0  
      } 
      //---------------------------------------- 
      if(input(pin_d2)==0) // khi nút reset so dem duoc nhan
      {                   
         while(input(pin_d2)==0); // tao vong lap chowf nut duoc nha  
         so_dem=0; // dat so dem ve 0;
         write_eeprom(0, so_dem); // ghi so dem vao EEPROM tai dia chi 0  
      }                        
      if(input(pin_d0)==0) // khi nut giam duoc nhan 
      {                      
         while(input(pin_d0)==0); // tao vong lap chowf nut duoc nha  
         so_dem--; // giam gia tri so dem
         if(so_dem>99) // neu so dem > 99
         {
            so_dem=99; // nap lai so dem = 99
         }
         write_eeprom(0, so_dem); // ghi so dem vao EEPROM tai dia chi 0  
      } 
      if(input(pin_d1)==0)
      {                        
         while(input(pin_d1)==0); // tao vong lap chowf nut duoc nha  
         so_dem++; // tang gia tri so dem
         if(so_dem>99) // neu so dem > 99                             
         {
            so_dem=0; // nap lai so dem = 0
         }
         write_eeprom(0, so_dem); // ghi so dem vao EEPROM tai dia chi 0  
      }
   }         
}
