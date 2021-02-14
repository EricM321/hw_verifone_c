1. Install Visual Studio Code.
2. Install the C/C++ extension for VS Code. You can install the C/C++ extension by searching for 'c++' in the Extensions view (Ctrl+Shift+X).
3. Install Mingw-w64 via the SourceForge website. Click [Mingw-w64](https://sourceforge.net/projects/mingw-w64/files/Toolchains%20targetting%20Win32/Personal%20Builds/mingw-builds/installer/mingw-w64-install.exe/download) to download the Windows Mingw-w64 installer.
    1. Run the installer.
    2. For Architecture select x86_64 and then select Next.
    3. On the Installation Folder page, use the default installation folder. Copy the location as you will need it later.
    4. Select Next to start the installation.

4. Add the path to your Mingw-w64 bin folder to the Windows PATH environment variable by using the following steps:
    1. In the Windows search bar, type 'settings' to open your Windows Settings.
    2. Search for Edit environment variables for your account.
    3. Choose the Path variable and then select Edit.
    4. Select New and add the Mingw-w64 destination folder path to the system path. The exact path depends on which version of Mingw-w64 you have installed and where you installed it. If you used the settings above to install Mingw-w64, then add this to the path: C:\Program Files\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin.
    5. Select OK to save the updated PATH. You will need to reopen any console windows for the new PATH location to be available.

5. From cmd: mingw32-make
6. .\output\main.exe

The test framework used is check installation instructions [here](https://libcheck.github.io/check/)