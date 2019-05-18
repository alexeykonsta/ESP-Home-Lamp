
void printDTSerial(DateTime CurrentDT) {
	if (SERIAL_EXIST==1) {
		Serial.print("DT: ");
		if (CurrentDT.day<10) Serial.print("0");
		Serial.print(CurrentDT.day);
		Serial.print(".");
		if (CurrentDT.month<10) Serial.print("0");
		Serial.print(CurrentDT.month);
		Serial.print(".");
		Serial.print(CurrentDT.year);
		Serial.print(" ");
		if (CurrentDT.hour<10) Serial.print("0");
		Serial.print(CurrentDT.hour);
		Serial.print(":");
		if (CurrentDT.minute<10) Serial.print("0");
		Serial.print(CurrentDT.minute);
		Serial.print(":");
		if (CurrentDT.second<10) Serial.print("0");
		Serial.print(CurrentDT.second);
		Serial.print(" weekday: ");
		Serial.print(CurrentDT.weekday);
	}
}

void printNTPUpdateSerial(DateTime CurrentDT, int TimeError) {
	if (SERIAL_EXIST==1) {
		Serial.println();
		Serial.print("NTP datetime update: ");
		printDTSerial(CurrentDT);
		Serial.print(" Error: ");
		Serial.print(TimeError);
	}
}