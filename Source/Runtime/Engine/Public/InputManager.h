#pragma once

namespace CK
{

enum class InputAxis : UINT32
{
	XAxis = 0,
	YAxis,
	ZAxis,
	WAxis,
	LastAxis
};

enum class InputButton : UINT32
{
	Space = 0,
	Z,
	X,
	F1,
	F2,
	F3,
	LastButton
};

class InputManager
{
public:
	float GetAxis(InputAxis InInputAxis) const;
	bool IsPressed(InputButton InInputButton) const;
	bool IsPressing(InputButton InInputButton) const;
	bool IsReleased(InputButton InInputButton) const;
	bool IsInputSystemReady() const;
	void SetInputAxis(InputAxis InInputAxis, std::function<float()> InAxisFn);
	void SetInputButton(InputButton InInputButton, std::function<bool()> InPressedFn);
	void UpdateInput();

private:
	std::array<std::function<float()>, static_cast<size_t>(InputAxis::LastAxis)> AxisMap;
	std::array<std::function<bool()>, static_cast<size_t>(InputButton::LastButton)> PressedButtonMap;
	std::array<bool, static_cast<size_t>(InputButton::LastButton)> PrevButtonStatus = { 0 };
};

}