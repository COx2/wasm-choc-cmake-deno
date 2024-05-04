@echo off

set SCRIPT_DIRECTORY=%~dp0
cd "%SCRIPT_DIRECTORY%\.."

echo "Configure from preset..."
cmake --preset ninja-multi

echo "Build Debug version..."
cmake --build --preset ninja-debug

echo "Build Release version..."
cmake --build --preset ninja-release

exit /b 0

:FAILURE
echo ErrorLevel:%ERRORLEVEL%
echo ***Build Failed***
exit 1

:SUCCESS
echo ***Build Success***
exit /b 0
