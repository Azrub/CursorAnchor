# CursorAnchor

A Guild Wars 2 addon for [Nexus](https://github.com/RaidcoreGG/Nexus) that automatically centers your cursor when toggling between target and action camera modes.

## Description

CursorAnchor solves a common annoyance in Guild Wars 2: when switching between camera modes, the game remembers your cursor position, which can be problematic if you moved your cursor far away or to a second monitor. This addon ensures your cursor is always centered when toggling camera modes.

Particularly useful for players who:
- Primarily use action camera but occasionally need target camera for specific skills
- Use multiple monitors
- Want to avoid losing track of their cursor position

## Installation

1. Install [Nexus Addon Loader](https://github.com/RaidcoreGG/Nexus)
2. Download `CursorAnchor.dll` from the [latest release](https://github.com/Azrub/CursorAnchor/releases)
3. Place the DLL in your `Guild Wars 2/addons` folder
4. Start the game
5. Keep or change your existing action camera toggle keybind in your game settings
6. In Nexus keybinds, set up the same action camera toggle key that you use in-game
7. Configure a different key for this addon (what you are going to use to actually change camera)


## Building from Source

### Requirements
- Visual Studio 2022
- Windows SDK
- C++17 or later

### Steps
1. Clone the repository
2. Open the solution in Visual Studio
3. Build the solution in Release mode
4. The compiled DLL will be in `x64/Release/CursorAnchor.dll`

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgments

- Thanks to the Nexus team for providing the addon framework.
- Originally created as an AutoHotkey script by me for personal use, this addon has been rewritten in C++ to leverage Nexus addon loader's capabilities for better performance and smoother integration with Guild Wars 2.
