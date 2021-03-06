#pragma once
#include <Windows.h>
#include <Xinput.h>
#include <array>

class XboxController {
public:
	enum class TapState {
		ButtonUp,
		ButtonDown,
		Tapped
	};

	enum XboxButtons {
		DpadUp,
		DpadDown,
		DpadLeft,
		DpadRight,
		Start,
		Back,
		LeftThumb,
		RightThumb,
		LeftShoulder,
		RightShoulder,
		A,
		B,
		X,
		Y,
		LeftTrigger,
		RightTrigger,
		LeftThumbLeft,
		LeftThumbRight,
		RightThumbLeft,
		RightThumbRight,
		LeftThumbUp,
		LeftThumbDown,
		RightThumbUp,
		RightThumbDown,
		UNKNOWN,
		SIZEOF_XboxButtons
	};

	std::array<int, SIZEOF_XboxButtons> XboxButtonMasks = {
		XINPUT_GAMEPAD_DPAD_UP,
		XINPUT_GAMEPAD_DPAD_DOWN,
		XINPUT_GAMEPAD_DPAD_LEFT,
		XINPUT_GAMEPAD_DPAD_RIGHT,
		XINPUT_GAMEPAD_START,
		XINPUT_GAMEPAD_BACK,
		XINPUT_GAMEPAD_LEFT_THUMB,
		XINPUT_GAMEPAD_RIGHT_THUMB,
		XINPUT_GAMEPAD_LEFT_SHOULDER,
		XINPUT_GAMEPAD_RIGHT_SHOULDER,
		XINPUT_GAMEPAD_A,
		XINPUT_GAMEPAD_B,
		XINPUT_GAMEPAD_X,
		XINPUT_GAMEPAD_Y,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0
	};

	std::array<std::string, SIZEOF_XboxButtons> XboxButtonsHelper = {
		"DpadUp",
		"DpadDown",
		"DpadLeft",
		"DpadRight",
		"Start",
		"Back",
		"LeftThumb",
		"RightThumb",
		"LeftShoulder",
		"RightShoulder",
		"A",
		"B",
		"X",
		"Y",
		"LeftTrigger",
		"RightTrigger",
		"LeftThumbLeft",
		"LeftThumbRight",
		"RightThumbLeft",
		"RightThumbRight",
		"LeftThumbUp",
		"LeftThumbDown",
		"RightThumbUp",
		"RightThumbDown",
		"UNKNOWN"
	};

	float TriggerValue = 0.75f;

private:
	XINPUT_STATE controllerState;
	int controllerNum;
	std::array<__int64, SIZEOF_XboxButtons> pressTime;
	std::array<__int64, SIZEOF_XboxButtons> releaseTime;

	std::array<__int64, SIZEOF_XboxButtons> tapPressTime;
	std::array<__int64, SIZEOF_XboxButtons> tapReleaseTime;

	float filterDeadzone(XboxButtons buttonType, int input);
	std::array<bool, SIZEOF_XboxButtons> xboxButtonCurr;
	std::array<bool, SIZEOF_XboxButtons> xboxButtonPrev;

public:
	explicit XboxController(int playerNumber);
	XINPUT_STATE GetState();
	bool IsConnected();
	void Vibrate(int leftval = 0, int rightval = 0) const;

	bool IsButtonPressed(XboxButtons buttonType, WORD buttonState);
	bool IsButtonJustPressed(XboxButtons buttonType, WORD buttonState);
	bool IsButtonJustReleased(XboxButtons buttonType, WORD buttonState);
	bool WasButtonHeldForMs(XboxButtons buttonType, WORD buttonState, int milliseconds);
	TapState WasButtonTapped(XboxButtons buttonType, WORD buttonState, int milliseconds);
	void UpdateButtonChangeStates();


	XboxButtons StringToButton(std::string& buttonString);

	// Returns a 0.0 to 1.0 value for any button
	float GetAnalogValue(XboxButtons buttonType, WORD buttonState);
};
