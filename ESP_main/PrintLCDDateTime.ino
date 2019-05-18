/*LCD Date Time Print*/
void printLcdCustomNumber(uint8_t x, uint8_t y, uint8_t num) {
	lcd.setCursor(x, y);
	if (num==0) {
		lcd.write(4);
		lcd.write(6);
		lcd.write(5);
		lcd.setCursor(x, y+1);
		lcd.print((char)255);
		lcd.print(" ");
		lcd.print((char)255);
		lcd.setCursor(x, y+2);
		lcd.write(3);
		lcd.write(6);
		lcd.write(2);		
	} else if (num==1) {
		lcd.write(0);
		lcd.print((char)255);
		lcd.print(" ");
		lcd.setCursor(x, y+1);
		lcd.print(" ");
		lcd.print((char)255);
		lcd.print(" ");
		lcd.setCursor(x, y+2);
		lcd.write(6);
		lcd.write(6);
		lcd.write(6);
	} else if (num==2) {
		lcd.write(0);
		lcd.write(6);
		lcd.write(5);
		lcd.setCursor(x, y+1);
		lcd.write(4);
		lcd.write(6);
		lcd.write(2);
		lcd.setCursor(x, y+2);
		lcd.write(3);
		lcd.write(6);
		lcd.write(2);
	} else if (num==3) {
		lcd.write(0);
		lcd.write(6);
		lcd.write(5);
		lcd.setCursor(x, y+1);
		lcd.print(" ");
		lcd.write(6);
		lcd.print((char)255);
		lcd.setCursor(x, y+2);
		lcd.write(3);
		lcd.write(6);
		lcd.write(2);		
	} else if (num==4) {
		lcd.print((char)255);
		lcd.print(" ");
		lcd.print((char)255);
		lcd.setCursor(x, y+1);
		lcd.write(3);
		lcd.write(6);
		lcd.print((char)255);
		lcd.setCursor(x, y+2);
		lcd.print(" ");
		lcd.print(" ");
		lcd.write(6);		
	} else if (num==5) {
		lcd.print((char)255);
		lcd.write(6);
		lcd.write(2);
		lcd.setCursor(x, y+1);
		lcd.write(6);
		lcd.write(6);
		lcd.write(5);
		lcd.setCursor(x, y+2);
		lcd.write(3);
		lcd.write(6);
		lcd.write(2);		
	} else if (num==6) {
		lcd.write(4);
		lcd.write(6);
		lcd.write(1);
		lcd.setCursor(x, y+1);
		lcd.print((char)255);
		lcd.write(6);
		lcd.write(5);
		lcd.setCursor(x, y+2);
		lcd.write(3);
		lcd.write(6);
		lcd.write(2);		
	} else if (num==7) {
		lcd.write(3);
		lcd.write(6);
		lcd.print((char)255);
		lcd.setCursor(x, y+1);
		lcd.print(" ");
		lcd.write(4);
		lcd.write(2);
		lcd.setCursor(x, y+2);
		lcd.print(" ");
		lcd.write(6);
		lcd.print(" ");
	} else if (num==8) {
		lcd.write(4);
		lcd.write(6);
		lcd.write(5);
		lcd.setCursor(x, y+1);
		lcd.print((char)255);
		lcd.write(6);
		lcd.print((char)255);
		lcd.setCursor(x, y+2);
		lcd.write(3);
		lcd.write(6);
		lcd.write(2);		
	} else if (num==9) {
		lcd.write(4);
		lcd.write(6);
		lcd.write(5);
		lcd.setCursor(x, y+1);
		lcd.write(3);
		lcd.write(6);
		lcd.print((char)255);
		lcd.setCursor(x, y+2);
		lcd.write(3);
		lcd.write(6);
		lcd.write(2);		
	}
}

void printYear (int x, int y, short year) {
	if (LCD_EXIST==1) {
		lcd.setCursor(16, 0);
		if (year<10) {
			lcd.print("0");
		}
		lcd.print(year);				
	}	
}

void printMonth (int x, int y, uint8_t month) {
	if (LCD_EXIST==1) {
		lcd.setCursor(13, 0);
		if (month<10) {
			lcd.print("0");
		}
		lcd.print(month);				
	}	
}

void printDay (int x, int y, uint8_t day) {
	if (LCD_EXIST==1) {
		lcd.setCursor(10, 0);
		if (day<10) {
			lcd.print("0");
		}
		lcd.print(day);		
	}	
}

void printWeekday (int x, int y, uint8_t weekday) {
	if (LCD_EXIST==1) {
		lcd.setCursor(6, 0);
		if (weekday==1) {lcd.print("Mon");}
		else if (weekday==2) {lcd.print("Tue");}
		else if (weekday==3) {lcd.print("Wen");}
		else if (weekday==4) {lcd.print("Thu");}
		else if (weekday==5) {lcd.print("Fri");}
		else if (weekday==6) {lcd.print("Sat");}
		else if (weekday==7) {lcd.print("Sun");}
	}
}	

void printHour (int x, int y, uint8_t hour) {
	
	if (LCD_EXIST==1) {
		if (hour<10) {
			printLcdCustomNumber(x, y, 0);
			printLcdCustomNumber(x+3, y, hour);
		} else {
			printLcdCustomNumber(x, y, String(hour).charAt(0)-'0');
			printLcdCustomNumber(x+3, y, String(hour).charAt(1)-'0');
		}
	}
}

void printMinute (int x, int y, uint8_t minute) {
	if (LCD_EXIST==1) {
		if (minute<10) {
			printLcdCustomNumber(x, y, 0);
			printLcdCustomNumber(x+3, y, minute);
		} else {
			printLcdCustomNumber(x, y, String(minute).charAt(0)-'0');
			printLcdCustomNumber(x+3, y, String(minute).charAt(1)-'0');
		}
	}
}

void printDots (int x, int y, uint8_t seconds) {
	if (LCD_EXIST==1) {
		lcd.setCursor(x, y);
		if (seconds%2==0) {
			lcd.write(7);
			lcd.setCursor(x, y+1);
			lcd.write(7);
		} else {
			lcd.print(" ");
			lcd.setCursor(x, y+1);
			lcd.print(" ");
		}
	}
}

void printDate () {
	printWeekday(5, 0, CurrentDT.weekday);
	printDay(9, 0, CurrentDT.day);
	lcd.print(".");
	printMonth(12, 0, CurrentDT.month);
	lcd.print(".");
	printYear(15, 0, CurrentDT.year);	
}

void printTime () {
	printHour(0, 1, CurrentDT.hour);
	printDots(6, 1, CurrentDT.second);
	printMinute(7, 1, CurrentDT.minute);	
}

void printDateTime () {
	printDate();
	printTime();
}