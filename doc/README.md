[comment]: # (User README.md)

Manual Transmission & Steering Wheel Support
===========
Version 4.3.2

<sub> <sub>
If you ended up here for version 4.1 to version 4.1.3, use 
[this](https://github.com/E66666666/GTAVManualTransmission/blob/v4.1.3-b944.2/doc/README.md)
guide :)
</sub> </sub>

![Gameplay](Gameplay.jpg)

# Manual Transmission for GTA V
This mod will enable manual transmission for vehicles, using the games' real
gear box. This means real gears - not speed capping. There are plenty of
features to emulate how real transmissions work.

It’s highly recommended to play with this mod using a controller or a wheel.

# Steering Wheel Support for GTA V
With manual transmission enabled, you'll want to be able to properly control
your vehicle. By default, GTA V doesn't support steering wheels. Solutions like
x360ce only emulate a controller, and the game will miss definition and force
feedback for wheels. For this, a large part of this mod is made to support wheels,
natively! A few features:

* all DirectInput compatible steering wheels supported (since 4.0)
* force feedback is fully supported
* multiple input devices supported (since 4.2.0)
* 1:1 mapping of steering wheel to vehicle front wheels

# Downloads
* [GTA5-Mods.com](https://www.gta5-mods.com/scripts/manual-transmission-ikt)
* [GitHub release (older versions)](https://github.com/E66666666/GTAVManualTransmission/releases)
* [Latest automated builds (unstable, probably)](https://ci.appveyor.com/project/E66666666/gtavmanualtransmission/build/artifacts)

# Table of Contents
<!-- TOC depthFrom:1 depthTo:2 orderedList:false updateOnSave:true withLinks:true -->

- [Manual Transmission for GTA V](#manual-transmission-for-gta-v)
- [Steering Wheel Support for GTA V](#steering-wheel-support-for-gta-v)
- [Downloads](#downloads)
- [Table of Contents](#table-of-contents)
- [Requirements](#requirements)
- [Installation](#installation)
    - [Additional steps for wheel users](#additional-steps-for-wheel-users)
- [FiveM installation](#fivem-installation)
- [Updating](#updating)
- [Recommended mods](#recommended-mods)
- [Basic usage and controls](#basic-usage-and-controls)
    - [Controls](#controls)
    - [Usage](#usage)
- [Configuration files](#configuration-files)
    - [`settings_general.ini`](#settings_generalini)
    - [`[OPTIONS]`](#options)
    - [`[HUD]`](#hud)
    - [`[CONTROLLER]`](#controller)
    - [`[CONTROLLER_LEGACY]`](#controller_legacy)
    - [`[KEYBOARD]`](#keyboard)
    - [`[DEBUG]`](#debug)
    - [`settings_wheel.ini`](#settings_wheelini)
    - [`[OPTIONS]` (Wheel)](#options-wheel)
    - [`[FORCE_FEEDBACK]`](#force_feedback)
    - [`[INPUT_DEVICES]`](#input_devices)
    - [Most controls](#most-controls)
    - [`[STEER]`, `[THROTTLE]`, `[BRAKES]`, `[CLUTCH]` and `[HANDBRAKE_ANALOG]`](#steer-throttle-brakes-clutch-and-handbrake_analog)
    - [`[TO_KEYBOARD]`](#to_keyboard)
    - [`settings_menu.ini`](#settings_menuini)
- [Troubleshooting](#troubleshooting)
    - [Installation dependencies](#installation-dependencies)
    - [Non-conflicting software](#non-conflicting-software)
    - [Conflicting software](#conflicting-software)
    - [Steering wheel reports strange values](#steering-wheel-reports-strange-values)
    - [Steering wheel not detected](#steering-wheel-not-detected)
- [Credits](#credits)
- [Source code](#source-code)

<!-- /TOC -->

# Requirements
* Grand Theft Auto V
* [ScriptHookV](http://www.dev-c.com/gtav/scripthookv/)

# Installation
1.	Put `Gears.asi` and the folder `ManualTransmission` in your GTA V folder (overwrite when asked)
2.	Read this README

## Additional steps for wheel users
3.	Remove or disable any XInput or DirectInput DLL files for your wheel for GTA V
4.  Configure your wheel in-game with the menu
5.  Toggle the mod off-on to activate force feedback

When reloading the mod by toggling it off and on, the settings are read again
and the steering wheel (if connected) is reset again. You can use this to fine-
tune your settings and change things on-the-fly, without restarting the game.

# FiveM installation
1. Create a plugins folder in FiveM Application Data 
2. Put `Gears.asi` and the folder `ManualTransmission` in plugins

# Updating
Replace `Gears.asi` and the folder `ManualTransmission` in your GTA V folder.
If the changelog indicated settings version numbers changed, you might want to
check the options. Otherwise it should be fine to keep `settings_wheel.ini`,
 `settings_general.ini` and `settings_menu.ini`.

# Recommended mods
You might want to install some additional mods to enhance your experience.

Any speedometer supporting RPM/Gear reading from memory
* [NFS Speedo](https://www.gta5-mods.com/scripts/nfsgauge-rpm-gear-speedometer)
* [LeFix Speedometer](https://www.gta5-mods.com/scripts/speedometer-improvedalexbladeversion)

Any handling mod that aims to improve handling accuracy
* [Realistic Driving V](https://www.gta5-mods.com/vehicles/realistic-driving-v)
* [Sim-cade Handling](https://www.gta5-mods.com/vehicles/sim-cade-handling)

Mods that counter the power loss when sliding sideways
* [InversePower](https://www.gta5-mods.com/scripts/inversepower)
* [Drift Assist](https://www.gta5-mods.com/scripts/drift-assist)

# Basic usage and controls
It's useful to know how to drive stick. Alternatively you can also turn
off features like stalling, clutch grabbing, or just using sequential or
automatic mode.

Read this README to see what the different switches do. You
WILL need to configure it correctly, otherwise some features will not work.
You can also mess around in the menu, but the intentions of options might not
be clear.

## Controls
For both keyboard and controller inputs, refer to `settings_general.ini` for 
keys. Refer to `Keyboard_Keys.txt` for usable keys.

### Menu
In `settings_menu.ini`, the keys are stored. Default for US layouts:

* Press `[{` to access the menu
* Up/Down/Left/Right arrow keys to navigate
* `RETURN` to select
* `BACKSPACE` to go back

The menu supports controller input fully too, but you'll need to assign
controller buttons to if if you want to.

![Menu main](MenuMain0.jpg)

![Menu setup](MenuOptions.jpg)

### Keyboard defaults (US-ANSI)
By default, `W` and `S` are assigned to throttle and brake respectively.

* Press `\|` to disable or enable manual transmission
* Press `]}` to switch between sequential, H-pattern or automatic
* Press `Z` for Clutch
* Press `X` for Engine

Sequential and Automatic:

* Press `LSHIFT` to shift up
* Press `LCTRL` to shift down

H-shifter mode:

* Press `Numpad 0` for Reverse
* Press `Numpad 1-7` for H-shifter gears 1-7
* Press `Numpad 9` for Neutral


### Controller defaults
By default, `RightTrigger` and `LeftTrigger` are assigned to throttle and brake respectively.

* Hold `Dpad Right` to disable or enable manual transmission (disabled at the moment)
* Hold `B` to switch between sequential, H-pattern or automatic
* Press `A` to shift up
* Press `X` to shift down
* Use `LeftThumbUp` to control the clutch
* Press `DpadDown` for Engine



## Usage
This mod features dynamic input detection. To switch between inputs, be it wheel,
keyboard or controller, you only need to tap the throttle on that device. The mod 
will automatically switch between these inputs.

Specifically for wheel users, you might need to fully depress the throttle
pedal or clutch pedal (once) if the mod keeps swapping away from the
 keyboard/controller.

### Driving with Manual Transmission
To drive forward, ensure that
* the vehicle is not in neutral
* the vehicle is not in reverse

and press the accelerator key, button or
pedal. Depending on your settings, you might or might not
need to operate the clutch to make a smooth start. Like a real vehicle, remember
to not let the RPM dip too low for the current gear. It might stall otherwise.

To brake, press the brake/reverse key, button or pedal. When coming to a halt,
the vehicle will not reverse.

To reverse, shift into the reverse gear. Press the accelerator key, button or
pedal. Depending on your settings, you might or might not need to operate the
clutch to get moving.

All of this can feel unnatural if done on a controller or keyboard, but should
feel perfectly normal like a normal car when you use a wheel.

#### Wheel-specific
Additional functionality is available for vehicles, like operating the lights,
horn, blinkers et cetera from the wheel. Refer to the `settings_wheel.ini` section for
details.

#### Wheel usage without Manual Transmission
The throttle and the brake work like the accelerator and brake/reverse inputs.
A clutch pedal won't have any action. The rest of the functions still work.

# Configuration files

Warning: This section is just for reference! Please use the in-game menu for configuration!
--------------------

This guide will explain the usage of the ini files and what the options mean. 

Generally, if only `0` or `1` the following holds for that feature:
* `0`: Disabled
* `1`: Enabled

From version 4.2.0, you will see `true` or `false` in the real .ini.

## `settings_general.ini`
This file contains most general settings. Configuring only this is sufficient if
no steering wheel is used.

## `[OPTIONS]`
The `[OPTIONS]` section is where you can configure how the mod behaves globally
and turn off and on features you want.

### `Enable` : `0` or `1`
This option is whether to enable or disable the mod. Toggling the mod in-game
will write the new value to this option, so your preference will be stored
between sessions.
* `0`: The mod is disabled and the original automatic transmission from GTA V
is fully restored.
* `1`: The mod is active and this mod will take over the transmission with
manual control.

### `ShiftMode` : `0`, `1` or `2`
This option switched between the sequential gearbox, H-pattern gearbox and
automatic gearbox. For the steering wheel and the keyboard this option can be
enabled and shifting happens with the numpad or with the H-shifter. Toggling the
mod in-game will write the new value to this option, so your preferences will be
stored between sessions.

__If controller input is detected, this option automatic reverts to sequential.__

* `0`: Sequential
* `1`: H-pattern
* `2`: Automatic

### `SimpleBike` : `0` or `1`
Disable stalling and clutch catching for bikes regardless of regular settings.
Useful for making bikes easier to operate.

* `0`: Clutch grabbing and stalling enabled
* `1`: Clutch grabbing and stalling disabled

### `EngineDamage` : `0` or `1`
This option turns on or off the engine damage when overrevving or shifting
without pressing the clutch. The damage values can be configured:
__RPMDamage__ and __MisshiftDamage__.

* `0`: Engine damage disabled
* `1`: Engine damage on over revving and shifting with the H-pattern gearbox
without using the clutch

### `EngineStalling` : `0` or `1`
This option turns on or off the engine stalling when releasing the clutch with
a low RPM at very low speeds. The point it shuts down is configured with
__ClutchCatchpoint__.

* `0`: Engine stalling disabled
* `1`: Engine stalls at low RPM with engaged clutch

### `EngineBraking` : `0` or `1`
This options controls engine braking. If driving at speed and downshifting to a
lower gear, the car will be slowed down accordingly.

* `0`: Engine braking disabled
* `1`: Engine braking active when over max gear speed

### `ClutchCatching` : `0` or `1`
This option will make the vehicle drive slowly if clutch is released gently,
and keeps the vehicle rolling at a speed depending on the gear.

* `0`: Clutch catching disabled
* `1`: Clutch catches/grabs/bites at specified point

### `ClutchShiftingH` : `0` or `1`
This option controls the requirement to hold the clutch for H-shifting.

* `0`: No need to hold the clutch while shifting
* `1`: Need to hold the clutch while shifting. Gearbox pops into neutral when
not holding the clutch.

### `ClutchShiftingS` : `0` or `1`
This option controls the requirement to hold the clutch for sequential shifting.
This feature is available from 4.2.0 on.

* `0`: No need to hold the clutch while shifting
* `1`: Need to hold the clutch while shifting. Gearbox pops into neutral when
not holding the clutch.

### `DefaultNeutral` : `0` or `1`
This option controls whether new vehicles start in neutral or not when you enter
 them. This is useful to turn on when you have __ClutchCatching__ and
__EngineStalling__ turned on.

* `0`: Vehicle starts in gear 1
* `1`: Vehicle starts in neutral gear

### `ClutchCatchpoint` : `0` to `100`
This specifies the point where the clutch starts making your vehicle roll. The
higher this value, the higher you need to lift the clutch pedal to get going.

### `StallingThreshold` : `0` to `100`
This specifies the point where your engine stalls with regard to the clutch
point. If you’re going too slowly and your clutch is lifted higher than this
point, your engine will stall. Keep this higher than __ClutchCatchpoint__ to get
both working together nicely.

### `RPMDamage` : `0` to any value
* Requires: `EngineDamage = 1`

This specifies how much damage your engine receives while overrevving.
Every tick, the engine gets damaged with __RPMDamage/100__.

### `MisshiftDamage` : `0` to any value
* Requires: `EnableH = 1`
* Requires: `EngineDamage = 1`
* Requires: `ClutchShifting = 1`

This specifies how much damage your engine receives when you shift. Every time
you shift into a gear without pressing the clutch past __ClutchCatchpoint__,
your engine will be damaged by __MisshiftDamage__. When you shift into Neutral
with an insufficiently pressed clutch, your engine will be damaged by
__MisshiftDamage/10__.

### `HillBrakeWorkaround` : `0` or `1`
Turn this on to emulate a hill start and car roll on a hill. It gives your car
a little push. Idea and implementation by XMOD.

* `0`: No change
* `1`: Workaround enabled. A force will push the car down a slope.

### `AutoGear1` : `0` or `1`
Turn this on to automatically shift into first gear when stopped, with a
sequential gearbox.

* `0`: No change
* `1`: Shift into first gear on stop while using the sequential gear box.

### `AutoLookBack` : `0` or `1`
Turn this on to automatically look back while in the reverse gear.

* `0`: No change
* `1`: Look back automatically

### `ThrottleStart` : `0` or `1`
Turn this on to be able to start the engine by pressing clutch + throttle,
like in some other games. This works alongside the usual button to start
the engine.

* `0`: Can only start engine with button
* `1`: Can start engine with button and clutch + throttle

### `CrossScript` : `0` or `1`
Turn this off to disable communication (shift indicators and neutral gear) to
other mods. This functionality is automatically disabled when running FiveM or any executable with version 1.0.505.2!

* `0`: No mod info available for other mods
* `1`: Mod info available for other mods

## `[HUD]`
Some info you can enable or disable at will. It's pretty self-explanatory.

* Gear: Current gear
* GearTopColor: Color for when the top gear is reached
* ShiftMode: Displays gearbox mode
* Speedo: Custom speedometer matching the needle on the dashboard
* RPM Indicator: Linear indicator. Colors can be adjusted
* Redline: When the bar should turn another color
* Revlimit: Absolute rev limit color. (yeah these two are different)

## `[CONTROLLER]`
The controller can only be used for a sequential gearbox or automatic gearbox.
Upon having switched to this input, sequential shifting mode will automatically
engage if in H-Shifter mode.

The default settings are laid out so they conflict least with regular gameplay.
The controller assumes an Xbox 360 controller, the following buttons and
options are available.

    DpadUp
    DpadDown
    DpadLeft
    DpadRight
    Start
    Back
    LeftThumb
    RightThumb
    LeftShoulder
    RightShoulder
    A
    B
    X
    Y
    LeftTrigger
    RightTrigger
    LeftThumbLeft
    LeftThumbRight
    RightThumbLeft
    RightThumbRight
    LeftThumbUp
    LeftThumbDown
    RightThumbUp
    RightThumbDown

### `Toggle`
Hold this button to toggle Manual Transmission on or off

### `ToggleShift`
Hold this button to toggle between Automatic and Sequential Transmission

### `ToggleTime` : Any (milliseconds)
How long it takes for a button hold to register. Example, `ToggleTime = 500`
means you need to hold it half a second to trigger.

### `TriggerValue` : `0` to `100`
How many % the analog axis needs to be pressed in or pushed to, to register as
a button press.


### `ShiftUp` : Any button
### `ShiftDown` : Any button
### `Clutch` : Any button
Gearbox controls. Self-explanatory.

### `Engine` : Any button
Turn on or off engine.

### `ToggleEngine` : `0` or `1`
* `0`: On pressing `Engine`, engine only turns on when off
* `1`: On pressing `Engine`, engine can also turn off when on

### `Throttle` and `Brake`
You __need__ to correctly set these to get braking and a standstill and
reversing with the throttle to work.

## `[CONTROLLER_LEGACY]`
For if you're using a not-Xbox controller. Same stuff applies as in `[CONTROLLER]`.

|Control name				|Xbox equivalent	|Control ID|
|---------------------------|-------------------|----------|
|ControlFrontendDown		|Dpad Down			|187       |	
|ControlFrontendUp			|Dpad Up			|188       |
|ControlFrontendLeft		|Dpad Left			|189       |
|ControlFrontendRight		|Dpad Right			|190       |
|ControlFrontendRdown		|??????????			|191       |
|ControlFrontendRup			|??????????			|192       |
|ControlFrontendRleft		|??????????			|193       |
|ControlFrontendRright		|??????????			|194       |
|ControlFrontendAxisX		|Left stick X		|195       |
|ControlFrontendAxisY		|Left stick Y		|196       |
|ControlFrontendRightAxisX	|Right stick X		|197       |
|ControlFrontendRightAxisY	|Right stick Y		|198       |
|ControlFrontendPause		|Start				|199       |
|ControlFrontendAccept		|A					|201       |
|ControlFrontendCancel		|B					|202       |
|ControlFrontendX			|X					|203       |
|ControlFrontendY			|Y					|204       |
|ControlFrontendLb			|Left shoulder		|205       |
|ControlFrontendRb			|Right shoulder		|206       |
|ControlFrontendLt			|Left trigger		|207       |
|ControlFrontendRt			|Right trigger		|208       |
|ControlFrontendLs			|Left stick click	|209       |
|ControlFrontendRs			|Right stick click	|210       |
|ControlFrontendDelete		|???????????		|214       |
|ControlFrontendSelect		|Back				|217       |


## `[KEYBOARD]`
This section assumes a regular ANSI keyboard with the US/QWERTY layout.

Look up available keys in `Keys.txt`.

### `Toggle`
Key to toggle mod on or off.

### `ToggleH`
Key to toggle between shifting modes.

### `Throttle` and `Brake`
You __need__ to correctly set these to get braking and a standstill and
reversing with the throttle to work.

## `[DEBUG]`

### `DisplayInfo` : `0` or `1`
* `0`: No debug info onscreen
* `1`: Debug info onscreen with transmission info, input info and force feedback info

### `LogCar` : `0` or `1`
* `0`: No car address logged
* `1`: Car address is logged to Gears.log when changing cars. Just something for me to debug things.

## `settings_wheel.ini`
Warning: This section is just for reference! Please use the in-game menu for configuration!
--------------------

This file contains all settings for the wheel controls. I recommend using
the in-game menu to configure the axis-inputs and H-shifter.

DirectInput steering wheels are fully supported! Every axis, button and 8
directions on the D-pad are supported for inputs. Additionally, steering wheel
input has been built in even if you don’t want to drive with any gearbox and
just want the default behavior. __Force Feedback is fully present and active in
all modes.__

When assigning axes and buttons, __DO THIS IN-GAME!__ This mod will resolve the
correct values. 

![Wheel setup](MenuWheel0.jpg)

![Wheel setup](MenuWheel1.jpg)


## `[OPTIONS]` (Wheel)

### `EnableWheel` : `0` or `1`
Enable detection and usage of a DirectInput wheel. Turn this on if you want to
use your racing wheel with GTA V and this mod.

### `WheelWithoutManual` : `0` or `1`
Enable usage of a wheel without using Manual Transmission features.

### `WheelBoatPlanes` : `0` or `1`
__EXPERIMENTAL__
Support for wheel input for boats and airplanes. Control boats like how you
 control cars. For plane, the layout is a bit different and requires a H-pattern
 shifter.
| Control | Effect |
|---------|--------|
| Throttle | Yaw right |
| Clutch | Yaw left |
| Wheel | Roll left / right |
| Shift up paddle | Pitch up |
| Shift down paddle | Pitch down |
| Gear 1| 33% power |
| Gear 3| 66% power |
| Gear 5| 100% power |
| Gear 2| 33% brake / reverse |
| Gear 4| 66% brake / reverse |
| Gear 6| 100% brake / reverse |

### `PatchSteering` : `0` or `1`
Patch steering correction. Credits to InfamousSabre's original
[CustomSteering](https://www.gta5-mods.com/scripts/custom-steering). This is
essential for 1:1 steering wheel and vehicle wheel mapping. Only works on anything
that isn't flying, a boat or some sort of bike.

Patching/unpatching happens automatically depending on input, so this option
can be safely left on if there's playing with controllers or keyboard and mouse.

### `PatchSteeringAlways` : `0` or `1`
Override the automatic unpatching, so the steering is still mapped 1:1 to your controller
or keyboard input. Recommended to leaving this off, for gameplay purposes.

### `LogitechLEDs` : `0` or `1`
Enable the RPM LEDs on Logitech wheels

## `[FORCE_FEEDBACK]`
### `Enable` : `0` or `1`
Disable or enable force feedback.

### `GlobalMult` : Any
Multiplier in percentage of how strong all forces are.
This feature is available from 4.2.0 on.

### `DamperMax` : `0` to `100`
Controls the friction feel when the vehicle is at a stop. A higher
value means more friction. Keep this higher than __DamperMin__.

### `DamperMin` : `0` to `100`
Controls the friction feel when the vehicle is moving. A higher
value means more friction. Keep this lower than __DamperMax__.

### `DamperTargetSpeed` : `0` to any (in m/s)
Sets the speed at which the damper effect is minimal. This is in
meters per second!

### `PhysicsStrength` : Any
How much physics affect your steering wheel and pulls it left or right. A higher 
value means a stronger force feedback.

### `DetailStrength` : `0` to any
How strong the feedback is from suspension compression. Think for terrain
details like road texture, potholes, manhole covers, sidewalk curbs etc.

## `[INPUT_DEVICES]`
To this, add your device GUIDs and a name so you can remember what is which.
An example entry looks like this:

```
[INPUT_DEVICES]
DEV0 = Logitech G27 Racing Wheel USB
GUID0 = {F69653F0-19B9-11E6-8002-444553540000}
```

This is taken from the data the tool or Gears.asi generates in `ManualTransmission/WheelConfigurator.log`
or `Gears.log`. A sample detection entry looks like this:

```
[23:20:19.989] Found 3 device(s)
[23:20:19.989] Device: Logitech G27 Racing Wheel USB
[23:20:19.989] GUID:   {F69653F0-19B9-11E6-8002-444553540000}
```

__You should not need to configure this manually if you used `WheelConfigurator.exe` or the in-game menu!__

## Most controls

The button controls are listed below with how they can be used.

|Control|Usage|Effect|
|-------|-----|------|
|Toggle|Press|Toggle Manual Transmission on/off|
|ToggleH|Press|Switch between sequential, H-shifter or automatic|
|ShiftUp|Press|Shift up 1 gear (sequential/auto)|
|ShiftDown|Press|Shift down 1 gear (sequential/auto)|
|Handbrake|Hold|Applies the hand brake|
|Horn|Hold|Sound the horn|
|LookBack|Hold|Look back|
|Engine|Press|Restart the engine or turn it off|
|Lights|Press|Switch between off, low beam and full beam|
|Camera|Press|Switch through cameras|
|RadioNext|Press|Next radio channel|
|RadioPrev|Press|Previous radio channel|
|IndicatorLeft|Press|Switch on/off left indicator|
|IndicatorRight|Press|Switch on/off right indicator|
|IndicatorHazard|Press|Switch on/off hazard lights|

Every single control can be assigned to any device. 

## `[STEER]`, `[THROTTLE]`, `[BRAKES]`, `[CLUTCH]` and `[HANDBRAKE_ANALOG]`
__To properly configure your wheel, use WheelConfigurator.exe!__
These sections maps your wheel input axes.

### `DEVICE` : Any
The device associated with the control. Matches up against DEV[n] in `[INPUT_DEVICES]`

### `BUTTON` : Any
Mapping of the control to a button on your wheel/controller.

### `AXLE` : Any of Supported input axes
Analog mapping of the control to your hardware analog input.


### Supported input axes and ranges

	lX
	lY
	lZ
	lRx
	lRy
	lRz
	rglSlider0
	rglSlider1

### `MIN` : `0` to `65535` are usually reported.
Value of axis while pedal is not pressed (or steering is fully left)

### `MAX` : `0` to `65535` are usually reported.
Value of axis while pedal is fully pressed (or steering is fully right)

### `FFB` : Any of Supported input axes
Force feedback axis is usually the steering axis but you can reassign this to some
other axis.

### `SteerAngleMax` : Any
Physical steering wheel steering degrees (lock to lock), in angles. 
Match this with your wheel spec.

### `SteerAngleCar` : Any less than `SteerAngleMax`
Soft lock for in cars.

### `SteerAngleBike` : Any less than `SteerAngleMax`
Soft lock for on bikes.

### `SteerAngleAlt` : Any less than `SteerAngleMax`
Soft lock for in planes and boats.

## `[TO_KEYBOARD]`
In this section you can assign wheel buttons to keyboard keys. A few examples
have been given. The format is `[BUTTON] = [KEY]`. Up to 128 buttons
are supported. Any keyboard key can be chosen, but Num Lock needs to be OFF for
keys to be interpreted correctly.
Use the included __Keyboard_Keys.txt__ for reference!

Only one device can be used for this feature.

Examples:

* `7 = H` makes `Button 7` act as the `H` key, which turns on the headlights.
* `20 = E` makes `Button 20` act as the `E` key, which is the horn or emergency lights.
* `18 = X` makes `Button 18` act as the `X` key. If [Slam It](https://www.gta5-mods.com/scripts/slam-it)
is installed, it'll lower the car.
* `16 = LEFT` makes `Button 16` act as the `LEFT` key. If [Windscreen Wipers](https://www.gta5-mods.com/scripts/car-wipers)
is installed and a compatible car is used, the wipers are turned on.

## `settings_menu.ini`

You can change your menu keys here. Available keys are in Keyboard_Keys.txt. Pay attention to the OEM VK keys as they can differ for your locale.

# Troubleshooting
## Installation dependencies
This mod should work on a bare system with only GTA V, build 350 to 944.2 and
the necessary programs to run GTA V and ScriptHookV supporting that version of
GTA V.

## Non-conflicting software
The mod has been tested with GTA V version 944.2 to 1032.1 with:
* ScriptHookV
* ScriptHookVDotNet
* RAGEPluginHook
* ENB Series
* OpenIV
* FoV 1.33

Limited support for 350, 505.2 (FiveM), 617, 678, 791.2, 877.1. If anything crashes, lemme know.

Full FiveM support is on the way.

## Conflicting software
* __x360ce__ will conflict with input detection if throttle, brake or steering clutch
are mapped, but the mod should still register your wheel. Assigning inputs
without overlap is no problem.
* [__Strapped__](https://www.gta5-mods.com/scripts/pull-out-strap) will conflict with
inputs.
* [__CustomSteering__](https://www.gta5-mods.com/scripts/custom-steering) will
conflict with steering patching. Remove CustomSteering if `PatchSteering` is enabled.
* [__ScriptHookVDotNet__](https://github.com/crosire/scripthookvdotnet/releases) might crash the G920. Not sure if there's a workaround. 

## Steering wheel reports strange values
Check if your wheel is recognized correctly, a recent Windows 10 update forces
new Logitech software which will mess up older Logitech steering wheels.

Before using this mod it's highly recommended to test your wheel with other games
first. I'm not an AAA-dev, so I'll panic hard if I think something is my fault while
it's some other unrelated bug :wink:

## Steering wheel not detected
* Try toggling the mod (|\ key)
* Ensure you have removed xinput dlls from the GTA V directory
* Check back with `WheelConfigurator.exe` to see if that thing does see your wheel

# Credits
Massive thanks to these people!
* Rockstar Games
* Alexander Blade
* LeFix
* XMOD
* InfamousSabre
* leftas
* kagikn
* aXurez
* All others who helped :)

# Source code
This mod is fully open source. The source code is available at
[https://github.com/E66666666/GTAVManualTransmission](https://github.com/E66666666/GTAVManualTransmission).

Submitting issues, pull requests or contributing in any way is very welcome :blush:
