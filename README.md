**⚡️ BadUSB Reverse Shell Attack**

A BadUSB project leveraging an Arduino to deploy reverse shell payloads on Windows and Linux targets. The Arduino emulates a keyboard, downloads malicious scripts from an Apache2 server, and executes them to establish a reverse shell connection back to your listener.

**🚀 Features**

🖥️ Cross-Platform – Supports both Windows (reverse_shell.bat) and Linux (reverse_shell.sh).

⚡️ Plug & Pwn – Just plug in the Arduino and let it do the rest.

🔄 Persistent Reconnection – Linux reverse shell attempts reconnection every 5 seconds if disconnected.


**📂 Project Structure**

badusb-reverse-shell/ 

├── arduino_badusb_script.ino # Arduino code for BadUSB attack 

├── reverse_shell.bat # Windows reverse shell payload 

├── reverse_shell.sh # Linux reverse shell payload 

└── README.md # You're here! 

**⚙️ Prerequisites**
Arduino (e.g., Leonardo, Micro) with BadUSB support
Apache2 server hosting the payloads (reverse_shell.bat & reverse_shell.sh)
Netcat listener on the attacker's machine: nc -lvnp 4444 
Arduino IDE with Keyboard.h library

**🛠️ Setup Instructions**

1️⃣ Configure Apache2 Server
Place reverse_shell.bat and reverse_shell.sh in /var/www/html/: ```
sudo cp reverse_shell /var/www/html/ 
sudo service apache2 start``` 
Ensure files are accessible: http://YOUR_SERVER_IP/reverse_shell.bat http://YOUR_SERVER_IP/reverse_shell.sh 

2️⃣ Update Arduino Script
Replace CHANGE_ME in the Arduino script with your Apache2 server's IP address.

3️⃣ Flash the Arduino
Open BadArduino.ino in Arduino IDE.
Select the correct Board and Port.
Upload the script.

4️⃣ Start Netcat Listener
On your attacking machine, run:
```nc -lvnp 4444``` 

5️⃣ Deploy the Attack
Plug in the Arduino to the target machine.
The Arduino will: 
Open a terminal/PowerShell.
Download the corresponding reverse shell script.
Execute it, establishing a reverse shell back to your listener.

**⚡️ How It Works**
Arduino emulates keystrokes to open PowerShell or Terminal.
Downloads reverse_shell.bat (Windows) or reverse_shell.sh (Linux) from your Apache2 server.
Executes the downloaded script.
A reverse shell is established to the attacker’s machine on port 4444.

**🔒 Disclaimer**

**⚠️ Educational Purposes Only!**
This project is intended for ethical hacking and security research. Unauthorized use against systems you do not own or have explicit permission to test is illegal.

**🤝 Contributing**
Pull requests are welcome! Feel free to fork the repo and improve it.

**📜 License**
This project is open-source under the MIT License.

**🔥 Happy Hacking! 🚀**
