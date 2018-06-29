## SetUp
- First Install wine for linux.
- Enable 32-bit architecture `sudo dpkg --add-architecture i386 `
- Add the repository
  - `wget -nc https://dl.winehq.org/wine-builds/Release.key`
  - `sudo apt-key add Release.key`
  - `sudo apt-add-repository https://dl.winehq.org/wine-builds/ubuntu/`
- Then Install wine `sudo apt-get install --install-recommends winehq-stable`

### How to use Wine?
After installation, you may run below command to initialize your wine configuration. You may be required to install other packages which is required for Windows applications to work well such as Mono and Gecko.
- Type `winecfg` for configuration.


### Installation of Windows Apps in Linux
Most binary Wine packages will associate Wine with .exe files for you. So you can double click on the .exe file and run it just like you would on Windows. You can also right-click on the file, choose "Run with", and choose "Wine".  Also, check out the [Wine Application Database](https://appdb.winehq.org/) to see which apps work with Wine and how easy it is to set them up.

You can also use `wine Setup.exe` in terminal to install your application.
