//WiFi  connect or create
bool WiFiInitMode() {
	main_config wifi_config;
	
	wifi_config=readConfig(true);
  
  if (connectToWiFi(wifi_config.ssid, wifi_config.password)==true) {
		return WIFI_NORM_MODE;
  } else {
    createWiFiAP(wifi_config.defconfig, wifi_config.ssidAP, wifi_config.passwordAP);
    return WIFI_AP_MODE;
  }  
}

byte connectToWiFi (String _ssid, String _password) {
	int wifi_connect_tries=WIFI_CONNECT_TRIES;
  if (_ssid.length()>0) {
    WiFi.mode(WIFI_STA);
    WiFi.begin(_ssid.c_str(), _password.c_str());

		printWiFiTryToConnectLcd (_ssid);


    while (--wifi_connect_tries && WiFi.status() != WL_CONNECTED) {
      printWiFiTryToConnectSerial (_ssid, wifi_connect_tries);
      delay(1000);      
    }
    if (WiFi.status() == WL_CONNECTED) {
      /*Connected to _ssid*/
			printWiFiConnected(_ssid);
      return true;
    } else {
			/*No connection to _ssid*/
			printWiFiNoConnection(_ssid);
      return false;
    }
  } else {
    /*no saved connaction*/
		printWiFiNoConnectionName ();
		return false;
  }
}

void createWiFiAP (bool defconfig, String _ssid, String _password) {
  WiFi.disconnect();
  WiFi.mode(WIFI_AP);
  WiFi.softAPConfig(IPAddress(192, 168, 1, 1), IPAddress(192, 168, 1, 1), IPAddress(255, 255, 255, 0));
  WiFi.softAP(_ssid.c_str(), _password.c_str());
	
	printWiFiStartAP(defconfig, _ssid, _password);
}