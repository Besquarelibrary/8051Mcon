#include<REGX51.H>
#include"lcd.h"
int lcddata(unsigned char val)//here val is input parameter
	{
	P2=val;//passing _data to be written to port2
	rs=1;// register_select pin should be high when passing read/write_data 
	rw=0;//read/write should be low when passing read/write_data
	en=1;//enable should be high while performing any action 
	delay(30000);//provides delay 
	en=0;//enable should be low once the action is finished
	return 0;
}
void lcdcmd(unsigned char val)//here val is a input parameter 
{
	
	P2=val;//passing _command to port2
	rs=0;// register_select pin should be low when passing command
	rw=0;;//read/write should be low when passing command
	en=1;//enable should be high while performing any action
	delay(30000);//provides delay 
	en=0;//enable should be low once the action is finished
}
void lcd_string_in(unsigned char *p)//here pointer p is a input parameter
{
	int i=0;
	for(i=0;p[i]!='\0';i++)
	{
		lcddata(p[i]);//calling lcddata and passing each and every element in the string as array
	}
	mov_cursor_to_sec_ln();//calling move to second line command
}
void clear()
{
	lcdcmd(0x01);//calling lcdcmd to pass the clear command
	mov_cursor_to_fir_ln();//calling movtofirln to move the cursor to the first line's first character's position
}
void lcd_character_in(unsigned char val)
{
	lcddata(val);//calling lcddata to pass the value 
	mov_cursor_to_sec_ln();// calling mov_cursor_to_sec_ln to move the cursor to second line's first character's position
}

void lcd_init()
{
	lcdcmd(0x38);// activate 5*7 dot matrix crystal
	lcdcmd(0x0c);// to make the display on and crsor off
}
void lcd_mid_char_in_fir_ln(unsigned char val)
{
	lcdcmd(0x87);// To move the cursor to the middle of the first line
	lcd_character_in(val);//calling lcd_character_in to write the read/write_data 
	mov_cursor_to_sec_ln();//calling move to second line command
}
void delay(unsigned int delay)
{
	int k;
	for(k=0;k<delay;k++);//provide delay 
}
void mov_cursor_to_sec_ln()
{
	lcdcmd(0xc0);//To move the cursor to second line's first character 
}
void lcd_mid_char_in_sec_ln(unsigned char val)
{
	lcdcmd(0xc7);//To move the cursor to the middle of the second line
	lcd_character_in(val);//calling lcd_character_in to write the read/write_data
}
void mov_cursor_to_fir_ln()
{
	lcdcmd(0x80);//To move the cursor to the first line's first character's position
}