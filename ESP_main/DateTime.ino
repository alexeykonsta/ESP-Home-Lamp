/*Initial*/
void initNTPTime(DateTime& CurrentDT) {
	int timestamp=0;
	int i=0;
	
	if (WiFi.status() == WL_CONNECTED) {
		
		printNTPStart ();
		
		sntp_setservername(0,"ru.pool.ntp.org");
		sntp_setservername(1,"pool.ntp.org");
		sntp_set_timezone(readConfigArgument("TimeZone").toInt());
		sntp_init();
		
		while (timestamp<1000000000 && i<10) {
			timestamp=sntp_get_current_timestamp();
			i++;
			delay(1000);
		}
		
		CurrentDT=getNTPDateTime();
		
		if (timestamp>=1000000000) {
			printNTPStatusOK();
			Serial.print("	");
			printDTSerial(CurrentDT);
		} else {
			printNTPStatusWR();
		}
		
	}
}

/*NTP*/
int getNTPUnixDateTime() {
	return sntp_get_current_timestamp();
}

DateTime getNTPDateTime () {
	return getDateTimefromUnix(sntp_get_current_timestamp());
}

/*date time increment*/
void DateTimeIncrement (DateTime& CurrentDT) {
	uint8_t max_day;
	CurrentDT.second++;
	everySecondTrigger();
	if (CurrentDT.second>59) {
		CurrentDT.second=0;
		CurrentDT.minute++;
		if (CurrentDT.minute>59) {
			CurrentDT.minute=0;
			CurrentDT.hour++;
			if (CurrentDT.hour>23) {
				CurrentDT.hour=0;
				max_day=monthDays[CurrentDT.month+1];
				if (CurrentDT.month==2 and CurrentDT.year%4==0) 
					max_day=29;				
				CurrentDT.day++;
				if (CurrentDT.day>max_day) {
					CurrentDT.day=1;
					CurrentDT.month++;
					if (CurrentDT.month>12) {
						CurrentDT.month=1;
						CurrentDT.year++;
						everyYearTrigger();
					}
					everyMonthTrigger();
				}
				everyDayTrigger();
			}
			everyHourTrigger();
		}
		everyMinuteTrigger();
	}
}

/*convert*/
int getUnixfromDateTime (DateTime CurrentDT) {
	int UnixSec=0, UnixDay=0;
	UnixSec=CurrentDT.second+CurrentDT.minute*60+CurrentDT.hour*3600;
	for (int i=CurrentDT.month-1; i>0; i--) {
		UnixDay=UnixDay+monthDays[i-1];
	}
	UnixDay=(UnixDay+CurrentDT.day-1)+(CurrentDT.year-1970)*365+int((CurrentDT.year-1969)/4);
	
	return (UnixDay*86400+UnixSec);
}

DateTime getDateTimefromUnix (int UnixDateTime) {
	int UnixDay, UnixSec;
	DateTime CurrentDT;
	
	if (UnixDateTime>=1000000000) {CurrentDT.ntp_sync=true;} 
		else {CurrentDT.ntp_sync=false;}
	
	CurrentDT.year=int(UnixDateTime/31436000)+1970;
	UnixDay=(int(UnixDateTime/86400)-int((CurrentDT.year-1969)/4))%365+1;
	CurrentDT.month=1;
	while (UnixDay>monthDays[CurrentDT.month-1] || CurrentDT.month>12) {
		UnixDay=UnixDay-monthDays[CurrentDT.month-1];
		CurrentDT.month++;
	}
	CurrentDT.day=UnixDay;
	
	UnixSec=UnixDateTime-int(UnixDateTime/86400)*86400;	
	CurrentDT.second=UnixSec%60;
	CurrentDT.minute=int(UnixSec/60)%60;
	CurrentDT.hour=int(UnixSec/3600);

	CurrentDT.weekday=int(UnixDateTime/86400+4)%7;

	return CurrentDT;	
}	