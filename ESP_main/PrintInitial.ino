
void printWebServerInit () {
	if (SERIAL_EXIST==1) {
		Serial.println("Web Server........OK");
	};
	if (LCD_EXIST==1) {
		lcd.setCursor(0, 0);
		lcd.print("Web Server........OK");
		delay(1500);
	};
};

void printConfigNotFound () {
	if (SERIAL_EXIST==1) {
		Serial.println("Config file not found");	
		Serial.println("Initialization stopped");
	};
	if (LCD_EXIST==1) {
		lcd.setCursor(0, 1);
		lcd.print("Config read.......ER");
		lcd.setCursor(0, 2);
		lcd.print("Init stopped");
	};
};

void printConfigTooLarge () {
	if (SERIAL_EXIST==1) {
		Serial.println("Config file size is too large");	
	};
	if (LCD_EXIST==1) {
		lcd.setCursor(0, 1);
		lcd.print("Config read.......ER");
		lcd.setCursor(0, 2);
		lcd.print("Init stopped");
	};
};

void printConfigReadOk () {
	if (SERIAL_EXIST==1) {
		Serial.println("Config read.......OK");	
	};
	if (LCD_EXIST==1) {
		lcd.setCursor(0, 1);
		lcd.print("Config read.......OK");
		delay(1500);
	};
};

void printConfigValidationError () {
	if (SERIAL_EXIST==1) {
		Serial.println("Config valid......ER");	
	};
	if (LCD_EXIST==1) {
		lcd.setCursor(0, 1);
		lcd.print("Config valid......ER");
		delay(1500);
	};	
}

void printDefaultConfigReadOk () {
	if (SERIAL_EXIST==1) {
		Serial.println("DefConfig read.......OK");	
	};
	if (LCD_EXIST==1) {
		lcd.setCursor(0, 1);
		lcd.print("DefConfig read....OK");
		delay(1500);
	};
};	

void printWiFiTryToConnectLcd (String _ssid) {
	if (LCD_EXIST==1) {      
		lcd.setCursor(0, 2);        
		lcd.print("Tring to connect");
		lcd.setCursor(0, 3);
		lcd.print("to: ");
		lcd.print(_ssid);
		delay(1000);
	}	
}	

void printWiFiTryToConnectSerial (String _ssid, int wifi_connect_tries) {
	if (SERIAL_EXIST==1) {
		Serial.print("	Try ");
		Serial.print(wifi_connect_tries);
		Serial.print(" to connect to ");
		Serial.println(_ssid);
	}
}

void printWiFiConnected(String _ssid) {
	if (SERIAL_EXIST==1) {
		Serial.println("WiFi connect......OK");
		Serial.print("	Connect to: ");
		Serial.println(_ssid);
		Serial.print("	IP Adress: ");
		Serial.println(WiFi.localIP());
	}
	
	if (LCD_EXIST==1) {
		lcd.clear();
		lcd.setCursor(0, 0);
		lcd.print("Connected to:");
		lcd.setCursor(0, 1);
		lcd.print(_ssid);
		lcd.setCursor(0, 2);
		lcd.print("IP adress:");
		lcd.setCursor(0, 3);
		lcd.print(WiFi.localIP());
		delay (5000);
		lcd.clear();
		lcd.setCursor(0, 0);
		lcd.print("File system.......OK");
		lcd.setCursor(0, 1);
		lcd.print("Config read.......OK");
		lcd.setCursor(0, 2);
		lcd.print("WiFi connect......OK");
		delay(1500);
	}	
}

void printWiFiNoConnection(String _ssid) {
	if (SERIAL_EXIST==1) {
		Serial.print("	Failed to connect to ");
		Serial.println(_ssid);
	}	

	if (LCD_EXIST==1) {
		lcd.setCursor(0, 2);
		lcd.print("No connection to");
		lcd.setCursor(0, 3);
		lcd.print(_ssid);
		delay (3000);	
		lcd.setCursor(0, 2);
		lcd.print("WiFi connect......ER");
		lcd.setCursor(0, 3);
		lcd.print("                     ");
		delay(1000);
	}
}	

void printWiFiNoConnectionName () {
	if (SERIAL_EXIST==1) {
		Serial.print("Wrong WiFi connection name");
	} 		
	
	if (LCD_EXIST==1) {
		lcd.setCursor(0, 2);
		lcd.print("Wrong WiFi name");
		delay (2000);
		lcd.setCursor(0, 2);
		lcd.print("WiFi connect......ER");		
	}
}

void printWiFiStartAP(bool defconfig, String _ssid, String _password) {
  if (SERIAL_EXIST==1) {
		Serial.println("WiFi AP started...OK");
    Serial.print("	SSID: ");
    Serial.println(_ssid);
    Serial.print("	Passowrd: ");
    Serial.println(_password);		
  }	
	
  if (LCD_EXIST==1) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("WiFi AP started");
    lcd.setCursor(0, 1);
    lcd.print ("SSID:");
    lcd.print(_ssid);
    lcd.setCursor(0, 2);
    lcd.print("Pass:");
    lcd.print(_password);
		lcd.setCursor(0, 3);
    lcd.print("IP: 192.168.1.1");
		delay (5000);
		lcd.clear();
		lcd.setCursor(0, 0);
		lcd.print("File system.......OK");
		lcd.setCursor(0, 1);
		if (defconfig==true) {
			lcd.print("DefConfig read....OK");
		} else {
			lcd.print("Config read.......OK");
		}
		lcd.setCursor(0, 2);
		lcd.print("WiFi AP start.....OK");
		delay(1500);
		
  }
}

void printNTPStart () {
	if (SERIAL_EXIST==1) {
		Serial.print("NTP connect");
	} 		
	
	if (LCD_EXIST==1) {
		lcd.setCursor(0, 3);
		lcd.print("NTP connect");
	}
}

void printNTPStatusOK () {
	if (SERIAL_EXIST==1) {
		Serial.println(".......OK");
	} 		
	
	if (LCD_EXIST==1) {
		lcd.setCursor(0, 3);
		lcd.print("NTP connect.......OK");
		delay(1000);
	}
}

void printNTPStatusWR () {
	if (SERIAL_EXIST==1) {
		Serial.println(".......WR");
	} 		
	
	if (LCD_EXIST==1) {
		lcd.setCursor(0, 3);
		lcd.print("NTP connect.......WR");
		delay(1000);
	}
}