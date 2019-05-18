#include <ESP8266WiFi.h>        
#include <ESP8266WebServer.h>   
#include <FS.h>                 //файловая система
#include <Ticker.h>             //таймер ESP

//переферия
#include <Wire.h>               //I2C
#include <LiquidCrystal_I2C.h>  //LCD 1602/2004
#include <ArduinoJson.h>

#include <sntp.h>

#include "lcdCustomChars.h" //lcdCustomChars

const byte pinSCL PROGMEM = D1;
const byte pinSDA PROGMEM = D2;

LiquidCrystal_I2C lcd(0x27, 20, 4); //I2C 1602 (0x3F)/2004 (0x27) LCD
ESP8266WebServer HTTP(80); //WebServer interfece
File fsUploadFile; //WebServer File System
Ticker esp_timer; //timer

#define LCD_EXIST (1)
#define SERIAL_EXIST (1)

#define WIFI_AP_MODE (0)
#define WIFI_NORM_MODE (1)
#define WIFI_CONNECT_TRIES (10)

uint8_t monthDays[12]={31,28,31,30,31,30,31,31,30,31,30,31};
struct DateTime {
	short year;
	uint8_t month, day, weekday, hour, minute, second;
	bool ntp_sync;
};

struct main_config {
	bool   defconfig;
	String ssid;
	String password;
	String ssidAP;
	String passwordAP;
	String timezone;
};

bool wifi_mode; /*1-normal 0-ap*/
int light[50];
int light_avr=0;
byte light_counter=0;
byte timer_cnt=0;
/*bool ntp_sync=false;*/
DateTime CurrentDT;
int TimeError;

void setup() {
	//Serial init
  if (SERIAL_EXIST==1) {
    Serial.begin(115200);
		Serial.println();
  };
  
	//lcd init
  if (LCD_EXIST==1) {
    lcd.begin();
    lcd.clear();
    lcd.backlight();		
		
		lcd.createChar(0, customChar1);
		lcd.createChar(1, customChar2);
		lcd.createChar(2, customChar3);
		lcd.createChar(3, customChar4);
		lcd.createChar(4, customChar5);
		lcd.createChar(5, customChar6);
		lcd.createChar(6, customChar7);
		lcd.createChar(7, customChar8);
  };
	
	//FileSystem and HTTP init
	WebServerInit();
	wifi_mode=WiFiInitMode();
	
	if (wifi_mode == WIFI_NORM_MODE) {
		initNTPTime(CurrentDT);
	} else {
		CurrentDT=getDateTimefromUnix(0);
	}
	
	if (LCD_EXIST==1) {
    lcd.clear();
		printDateTime();
  };
	
	esp_timer.attach_ms(1000, timer_function); //start timer
	
}	

void loop() {	
	HTTP.handleClient();
}

