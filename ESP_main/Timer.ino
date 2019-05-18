void timer_function() {
	timer_cnt++;
	if (timer_cnt==60) timer_cnt=0;
	
	DateTimeIncrement(CurrentDT);
	if (CurrentDT.second==0) {
		Serial.println();
		printDTSerial(CurrentDT);
	}
	
	if (CurrentDT.weekday==1 and CurrentDT.hour==1 and CurrentDT.minute==2 and CurrentDT.second==12) {
		CurrentDT.ntp_sync=false;
	}
	
	if (CurrentDT.ntp_sync==false and CurrentDT.second%10==0 and WiFi.status() == WL_CONNECTED and wifi_mode==1) {		
		TimeError=getNTPUnixDateTime()-getUnixfromDateTime(CurrentDT);		
		CurrentDT=getNTPDateTime();
		
		printNTPUpdateSerial(CurrentDT, TimeError);
		printDateTime();
	}	
}

void everySecondTrigger() {
	printDots(6, 1, CurrentDT.second);
}	

void everyMinuteTrigger() {
	printMinute(7, 1, CurrentDT.minute);
}

void everyHourTrigger() {
	printHour(0, 1, CurrentDT.hour);
}

void everyDayTrigger() {
	printDay(9, 0, CurrentDT.day);
	printWeekday(5, 0, CurrentDT.weekday);
}

void everyMonthTrigger() {
	printMonth(12, 0, CurrentDT.month);
}

void everyYearTrigger() {
	printYear(15, 0, CurrentDT.year);
}