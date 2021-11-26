# vscode-skelly-avr

VSCode AVR skelleton base example project to work (develop) with Microchip-Atmel AVR microcontrollers on a Linux system without the need of a full IDE.

This project example target an atmega328p microcontroller, but the repository can be used as a reference to create new projects for other targets.

## Requirements

- Install required toolchain components:

```bash
sudo apt-get update
sudo apt-get -y install binutils
sudo apt-get -y install make
sudo apt-get -y install gcc-avr
sudo apt-get -y install avr-libc
sudo apt-get -y install cflow
```

- Install Flashing Tool:

```bash
sudo apt-get -y install avrdude
```

## How to Create a AVR project supported by vscode

Here is the steps that has been followed to create current project:

1. Create project directories and setup current project:

```bash
mkdir ~/vscode-skelly-avr
cd ~/vscode-skelly-avr
mkdir bin build doc inc lib src test tools
```

2. Create *src/main.cpp* source file with some basic application (i.e. blink).

3. Create a *build/Makefile* with expected targets and configurations to build the project.

4. Create a *./vscode/c_cpp_properties.json* file and setup C & C++ standard versions, Defines, compiler arguments that are used in project, and the include paths to system installed AVR libc to setup correctly intellisense functionality.

5. Create a ./vscode/tasks.json file and setup *make* commands to execute for each available tasks to be used from vscode.

6. Create a ./vscode/launch.json file and setup vscode project Run and Debug behaviour.

## Usage

Build:

1. Physically connect the hardware programmer to target device and the PC.

2. Using a shell, go to **build/** directory and run **make help** to see build instructions.

3. Run **make build DEVICE=X F_CPU=X** to launch the Build.

4. Run **make flash PROGRAMMER=X** to build and flash the firmware into target device.

Release Flash:

1. Press Ctrl+Shift+B to show the configured Tasks of the project.

2. Execute one of the Task to flash the firmware into the device through any of the supported and configured interfaces (*edbg*).
