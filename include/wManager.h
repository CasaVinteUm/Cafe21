extern char wmLNBitsServer[100];// = "legend.lnbits.com";
extern char wmDeviceId[23];// = "BESNK";
extern char wmLNApiKey[33];// = "Z4GbwoXMzHEBhfoDP6Dt4Z";
extern char wmLNApiKeyWS[35];// = "e76b9317648145058af55d49b16c831f";
extern char wmESPMAC[18]; // = "bc:dd:c2:47:20:d0";
extern float wmValue;// = 10.00;
extern int wmValueSats;// = 0;
extern float wmValueC;// = 10.00;
extern int wmValueSatsC;// = 0;
extern int wmVolume;// = 400;
const char wmSSID[] = "Cafe21";
const char wmPASSWD[] = "Cafeina21";

void init_WifiManager();
void wifiManagerProcess();
void reset_configurations();