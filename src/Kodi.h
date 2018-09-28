#include <ESP8266HTTPClient.h>

#ifndef Kodi_h
#define Kodi_h

#define IPKODI "192.168.1.123"
#define PORTKODI 8080
unsigned const ACTIVE_btn = 0xE17A48B7;
unsigned const play_pause_btn = 0xE17A6C93;
unsigned const stop_btn = 0xE17A4CB3;
unsigned const forward_btn = 0xE17AAC53;
unsigned const backward_btn = 0xE17A2CD3;
unsigned const BACK_btn = 0xE17A8877;
unsigned const EXIT_btn = 0xE17A50AF;
unsigned const OK_btn = 0xE17AA857;
unsigned const OK_btn2 = 0x20DF22DD;
unsigned const UP_btn = 0xE17AD02F;
unsigned const DOWN_btn = 0xE17A30CF;
unsigned const LEFT_btn = 0xE17AD827;
unsigned const RIGHT_btn = 0xE17A38C7;
unsigned const INFO_btn = 0xE174C837;
unsigned const CAPTION_btn = 0xE17A24DB;
unsigned const VOLp_btn = 0xE17AB04F;
unsigned const VOLm_btn = 0xE17A708F;
unsigned const MUTE_btn = 0xE17A8073;
unsigned const GREEN_Audio_btn = 0xE17AE817;
unsigned const RED_iTv_btn = 0xE17A6897;
unsigned const Nulo = 0xffffffff;

class Kodi {
	bool kodi_active;
	String kodiIP = IPKODI;
private:
	
	String Command(unsigned IRDecode);
	void Post(String post);
public :
	void ActiveKodi(bool active);
	void HandlerKodi(unsigned IRDecode);
};


#endif
