#define NOMINMAX
#include "../../../ScriptHookV_SDK/inc/natives.h"
#include "../../../ScriptHookV_SDK/inc/enums.h"
#include "Util.hpp"
#include <algorithm>

void showText(float x, float y, float scale, const char* text, int font, const Color &rgba, bool outline) {
	UI::SET_TEXT_FONT(font);
	UI::SET_TEXT_SCALE(scale, scale);
	UI::SET_TEXT_COLOUR(rgba.R, rgba.G, rgba.B, rgba.A);
	UI::SET_TEXT_WRAP(0.0, 1.0);
	UI::SET_TEXT_CENTRE(0);
	if (outline) UI::SET_TEXT_OUTLINE();
	UI::BEGIN_TEXT_COMMAND_DISPLAY_TEXT("STRING");
	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(CharAdapter(text));
	UI::END_TEXT_COMMAND_DISPLAY_TEXT(x, y);
}

void showNotification(const char* message, int *prevNotification) {
	if (prevNotification != nullptr && *prevNotification != 0) {
		UI::_REMOVE_NOTIFICATION(*prevNotification);
	}
	UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");

	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(CharAdapter(message));
	
	int id = UI::_DRAW_NOTIFICATION(false, false);
	if (prevNotification != nullptr) {
		*prevNotification = id;
	}
}

// gracefully borrowed from FiveM <3
void showSubtitle(std::string message, int duration) {
	UI::BEGIN_TEXT_COMMAND_PRINT("CELL_EMAIL_BCON");

	const int maxStringLength = 99;

	for (int i = 0; i < message.size(); i += maxStringLength) {
		int npos = std::min(maxStringLength, static_cast<int>(message.size()) - i);
		UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(CharAdapter(message.substr(i, npos).c_str()));
	}

	UI::END_TEXT_COMMAND_PRINT(duration, 1);
}

GameSound::GameSound(char *sound, char *soundSet): m_prevNotification(0) {
	Active = false;
	m_sound = sound;
	m_soundSet = soundSet;
	m_soundID = -1;
}

GameSound::~GameSound() {
	if (m_soundID == -1 || !Active) return;
	AUDIO::RELEASE_SOUND_ID(m_soundID);
}

void GameSound::Load(char *audioBank) {
	AUDIO::REQUEST_SCRIPT_AUDIO_BANK(audioBank, false);
}

void GameSound::Play(Entity ent) {
	if (Active) return;
	m_soundID = AUDIO::GET_SOUND_ID();
	//showNotification(("New soundID: " + std::to_string(m_soundID)).c_str(), nullptr);
	AUDIO::PLAY_SOUND_FROM_ENTITY(m_soundID, m_sound, ent, m_soundSet, 0, 0);
	Active = true;
}

void GameSound::Stop() {
	if (m_soundID == -1 || !Active) return;
	AUDIO::STOP_SOUND(m_soundID);
	Active = false;
}

void DisableActionControlsStart() {
	CAM::SET_CINEMATIC_BUTTON_ACTIVE(0);
}

void DisableActionControlsStop() {
	CAM::SET_CINEMATIC_BUTTON_ACTIVE(1);
}

void DisableActionControlsTick() {
	CONTROLS::DISABLE_CONTROL_ACTION(2, ControlNextCamera, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, ControlVehicleCinCam, true);

	CONTROLS::DISABLE_CONTROL_ACTION(2, ControlPhone, true);

	CONTROLS::DISABLE_CONTROL_ACTION(2, ControlSelectCharacterMichael, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, ControlSelectCharacterFranklin, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, ControlSelectCharacterTrevor, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, ControlSelectCharacterMultiplayer, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, ControlCharacterWheel, true);

	CONTROLS::DISABLE_CONTROL_ACTION(2, ControlMeleeAttackLight, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, ControlMeleeAttackHeavy, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, ControlMeleeAttackAlternate, true);

	CONTROLS::DISABLE_CONTROL_ACTION(2, ControlMultiplayerInfo, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, ControlMapPointOfInterest, true);

	CONTROLS::DISABLE_CONTROL_ACTION(2, ControlRadioWheelLeftRight, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, ControlVehicleNextRadio, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, ControlVehiclePrevRadio, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, ControlRadioWheelUpDown, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, ControlVehicleNextRadioTrack, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, ControlVehiclePrevRadioTrack, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, ControlVehicleRadioWheel, true);

	CONTROLS::DISABLE_CONTROL_ACTION(2, ControlVehicleDuck, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, ControlVehicleSelectNextWeapon, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, ControlVehicleSelectPrevWeapon, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, ControlVehicleAttack, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, ControlVehicleAttack2, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, ControlVehicleExit, true);

	CONTROLS::DISABLE_CONTROL_ACTION(2, ControlContext, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, ControlSelectWeapon, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, ControlVehicleHeadlight, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, ControlVehicleRoof, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, ControlVehicleHorn, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, ControlVehicleHandbrake, true);

	CONTROLS::DISABLE_CONTROL_ACTION(2, ControlVehicleAim, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, ControlVehiclePassengerAim, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, ControlFrontendSocialClub, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, ControlFrontendSocialClubSecondary, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, ControlReplayStartStopRecording, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, ControlInteractionMenu, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, ControlSaveReplayClip, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, ControlNextCamera, true);
}