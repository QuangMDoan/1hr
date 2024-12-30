1. Install arduino IDE
2. Install C/C++ Pack/Extension for VSCode
3. Install Git History extension  for VSCode
4. Install CrunchLab Agent 
5. Get the code for Domino Robot
6. Install PlatformIO extension for VSCode
7. In the Command Pallette, type platformio and click the option that says PlatformIO Home. 
8. In the PlatformIO Home window, select Create New Project 
    
    Give the project a name. In Board Type, type ATmega328P and select the top option. Framework can be set to Arduino as default. Then select Finish.

9. Expand the src folder, main.cpp. Renaming main.cpp to main.ino, which is the arduino filetype. The reason for this is because the arduino file type is preprocessed, which means more flexible syntax such as where methods are located in the file iirc, and stuff like that.

9. For libraries. Open platformio home tab (use Command Palette again if it is closed). Click libraries. For each library needed, search for the library name and install the one that exactly matches. 

    The Domino Bot requires a library called SparkFun_TB6612. For this library, download the zip file from discord. Then in the arduino IDE go to Sketch -> Include Library -> Add .Zip Library, and open the downloaded zip file

10. Upload the code, click the dropdown next to the play icon in the top left and select Upload. 
