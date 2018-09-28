#include <Kodi.h>
void Kodi::HandlerKodi(unsigned IRDecode) {
	if(!kodi_active) return;
	Post(Command(IRDecode));
}

void Kodi::ActiveKodi(bool active) {
	kodi_active = active;
	if (active) {
		Post("{\"jsonrpc\": \"2.0\", \"method\": \"GUI.ShowNotification\", \"params\": { \"title\": \"ESP ATIVADO\", \"message\":\"Controle Ativado\", \"image\":\"special://profile/ico/smarthouse.png\" }, \"id\": 1}");
	}
}

void Kodi::Post(String post){
	if (post == NULL) return;
	HTTPClient kodiHTTP;
	kodiHTTP.begin(kodiIP, PORTKODI, "/jsonrpc");
	kodiHTTP.addHeader("Content-Type", "application/json");
	kodiHTTP.addHeader("Authorization", "Basic a29kaToxMjM0");
	kodiHTTP.setTimeout(1000);
	auto httpCode = kodiHTTP.POST(post);
}

String Kodi::Command(unsigned IRDecode) {
	String methods;
	switch (IRDecode) {
	case play_pause_btn:
		methods = "Player.PlayPause\", \"params\": { \"playerid\": 1 }";
		break;
	case stop_btn:
		methods = "Player.Stop\", \"params\": { \"playerid\": 1 }";
		break;
	case forward_btn:
		methods = "Player.SetSpeed\", \"params\": { \"playerid\": 1, \"speed\":4 }";
		break;
	case backward_btn:
		methods = "Player.SetSpeed\", \"params\": { \"playerid\": 1, \"speed\":-4 }";
		break;
	case BACK_btn:
		methods = "Input.Back\"";
		break;
	case EXIT_btn:
		methods = "Input.Home\"";
		break;
	case OK_btn:
		methods = "Input.Select\"";
		break;
	case OK_btn2:
		methods = "Input.Select\"";
		break;
	case UP_btn:
		methods = "Input.Up\"";
		break;
	case DOWN_btn:
		methods = "Input.Down\"";
		break;
	case LEFT_btn:
		methods = "Input.Left\"";
		break;
	case RIGHT_btn:
		methods = "Input.Right\"";
		break;
	case INFO_btn:
		methods = "Input.Info\"";
		break;
	case CAPTION_btn:
		methods = "Input.ShowOSD\"";
		break;
	case VOLp_btn:
		methods = "Application.SetVolume\", \"params\": { \"volume\":\"increment\"}";
		break;
	case VOLm_btn:
		methods = "Application.SetVolume\", \"params\": { \"volume\":\"decrement\"}";
		break;
	case MUTE_btn:
		methods = "Application.SetMute\", \"params\": { \"mute\":\"toggle\"}";
		break;

	case GREEN_Audio_btn:
		methods = "Player.SetAudioStream\", \"params\": { \"playerid\": 1, \"stream\":\"next\"}";
		break;
	}

	return String("{\"jsonrpc\": \"2.0\", \"method\":\"" + methods + ", \"id\": 1}");
}
