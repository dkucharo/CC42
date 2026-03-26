*This project was made by dkucharo*

# Description

Debian 13.4
RAM 2048 MB
Processors 1 CPU

# Instructions

# Recources


DEBIAN OR ROCKY LINUX

Based on the requirements provided in the subject, Debian is highly recommended "Born to be Root" project. Here's why:

1- Stability and Ease of Use: Debian is known for its stability and reliability, making it an excellent choice for a server environment. It has a well-established release cycle and extensive documentation, making it suitable for both beginners and experienced users.

2- Strong Community Support: Debian has a large and active community with a wealth of resources available online. This support network can be invaluable, especially for those new to system administration.

3- Suitability for System Administration: The project specifically mentions that Debian is highly recommended for newcomers to system administration. Debian's user-friendly package management system (apt) and comprehensive documentation make it well-suited for learning and implementing the required tasks.

4- Security Features: Debian comes with robust security features, including SELinux, which must be running at startup and configured according to the project's needs. Additionally, AppArmor must be running at startup for Debian, further enhancing security.

5- Compatibility with Project Requirements: Debian aligns well with the project's requirements, including setting up encrypted partitions using LVM, implementing a strong password policy, configuring sudo, setting up SSH with restricted access, and configuring the firewall using UFW.

6- Bonus Part Consideration: If you decide to pursue the bonus part of the project, Debian provides a stable platform for setting up additional services such as WordPress or a custom service of your choice.

7- The latest version now that im writing this guide is Debian 12.5. Go to this link to download Debian image - https://www.debian.org/download.

![alt text](image-1.png)

Partitioning is essential for organizing disk space on your server. It divides the disk into separate sections, each serving a specific purpose.

1- use entire disk and set up encrypted LVM: This refers to selecting the guided partitioning option in the installation process, which will automatically partition the disk and set up encrypted Logical Volume Manager (LVM). This option is chosen because the project specifies that encrypted partitions must be used. BUT... ⚠️❗️ If you want to do the bonus you must click Manual and click here ❗️⚠️: This part serves as a reminder or alert for users who wish to complete the bonus part of the project. It instructs them that if they want to deviate from the automatic guided partitioning and set up the partitions manually (which may be necessary for certain bonus tasks), they should select the "Manual" option instead. I will do first what is required for the bonus but if you want you can skip it and go straight here.

![alt text](image-2.png)

GRUB: is the reference implementation of the Free Software Foundation's Multiboot Specification, which provides a user the choice to boot one of multiple operating systems installed on a computer or select a specific kernel configuration available on a particular operating system's partitions.

We will select Yes to install GRUB boot on the hard drive. GRUB plays a crucial role in the boot process of Linux-based operating systems, providing a flexible and customizable bootloader solution that facilitates system booting, kernel loading, and system recovery.

**sudo**
* sudo is a program for Unix-like computer operating systems that enables users to run programs with the security privileges of another user, by default the superuser. It originally stood for "superuser do", as that was all it did, and it is its most common usage; however, the official Sudo project page lists it as "su 'do' ".

* `su`  switch to root user for more rights
* `apt install sudo` - This command tells the package manager to install the required packages for sudo
* `sudo reboot` reboot machine
* `sudo apt update` - update the system
* `touch /etc/sudoers.d/sudo_config` sudo policies file, edit it:

* passwd_tries=3: Total tries for entering the sudo password.
* badpass_message="message": The message that will show when the password failed.
* logfile="/var/log/sudo/sudo_config": Path where will the sudo logs will be stored.
* log_input, log_output: What will be logged.
* iolog_dir="/var/log/sudo": What will be logged.
* requiretty: TTY become required
* secure_path="/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin": Folders that will be excluded of sudo

* `nano /etc/login.defs` file alredy existed, just modify it

* PASS_MAX_DAYS: expiration time in days for passwords
* PASS_MIN_DAYS: minimum number of days before password can be changed.
* PASS_WARN_AGE: triggers a warning message to users, notifying them of the impending expiration of their password within the specified number of days.

* `sudo apt install libpam-pwquality` password quality library installation
* `nano /etc/pam.d/common-password` modify the PAM (Pluggable Authentication Modules) configuration file

* minlen=10: Sets the minimum number of characters required for a password.
* ucredit=-1: Specifies that the password must include at least one uppercase letter.
* dcredit=-1: Requires the presence of at least one digit in the password.
* lcredit=-1: Ensures the password contains at least one lowercase letter.
* maxrepeat=3: Limits the repetition of the same character to a maximum of 3 times consecutively.
* reject_username: Prohibits the password from containing the username.
* difok=7: Specifies that at least 7 characters in the new password must differ from the old password.
* enforce_for_root: Enforces these password policies for the root user, enhancing security even for privileged accounts.

**GID**
* Ever heard of GID? It stands for Group Identifier, abbreviated as Group ID. Essentially, it's a unique identifier assigned to a group 🆔 in a Unix-like operating system. Just like how each user has a UID (User ID), each group gets its own GID. This identifier helps the system manage permissions and access control, allowing users within the same group to share resources and collaborate effectively. So, think of GID as the group's digital fingerprint—it ensures smooth coordination and organization within the operating system!

* `sudo adduser <login>` add user, if user exists it shows error and says it exists already
* `sudo addgroup user42` add group, if group exists it shows error and says it exists already
* `getent group <groupname>` check status of group
* `sudo adduser <username> <groupname>` adds user to group
* `getent group sudo user42` - check what users are in groups sudo and user42
* what means the sudo:x:27:dkucharo and user42:x:1001:dkucharo??

**SSH**
* SSH: The acronym SSH stands for "Secure Shell." The SSH protocol was designed as a secure alternative to unsecured remote shell protocols. It utilizes a client-server paradigm, in which clients and servers communicate via a secure channel. *SSH, or Secure Shell, is both a protocol and a program used for remote access to servers. It establishes a secure channel, encrypting all data exchanged between the client and server. This ensures confidentiality and integrity, making SSH a vital tool for secure remote administration and file transfer.*

* `sudo apt install onpenssh-server` - install the main tool for remote access with the SSH protocol, using OpenSSH
* `sudo service ssh status` - checks SSH service status, should give back active(running)
* `vim /etc/ssh/sshd_config`- access the file which needs to be modified
* `ssh dkucharo@localhost -p 4241` - connect via SSH from our machine to the virtual machine
* `logout` disconnects our machine from the VM

**UFW**
*  UFW, or Uncomplicated Firewall, is a user-friendly front-end for managing iptables, the default firewall configuration tool for many Linux distributions. It simplifies the process of configuring firewall rules through a straightforward command-line interface, allowing users to easily control network traffic and enhance system security with just a few simple commands. With UFW, even users with limited experience in firewall management can efficiently set up and maintain robust firewall policies to safeguard their systems against unauthorized access and potential threats.

1- 🛡️ To begin, the initial step is to install UFW. Execute the command sudo apt install ufw in your terminal. When prompted, type 'y' to confirm your intention to install the package, then patiently wait for the process to complete. This sets the stage for configuring your firewall and bolstering your system's security.

* `sudo apt install ufw` install the UFW package
* `sudo ufw enable` enable the firewall
* `sudo ufw allow 4242` allow our firewall to accept the connections from 4242 port
* `sudo ufw status` check state of firewall

# script
*  is a sequence of commands stored in a file that, when executed, will perform the function of each command.
* **Architecture**: For the architecture of the OS to be shown, you will use the command `uname -a` ("-a" == "--all"). This command prints all information, except if the CPU is unknown or the platform hardware.
* **Pyzsical Cores**: For the number of physical cores to be shown, we will use the file /proc/cpuinfo, which gives us information about the CPU: its type, brand, model, performance, etc. We will use `grep "physical id" /proc/cpuinfo | wc -l` with the `grep` command looking inside the file for "physical id" and with `wc -l` to count the lines of the grep output
* **Virtual Cores**: We will again use the file /proc/cpuinfo, but in this case we will use the command `grep processor /proc/cpuinfo | wc -l`; way of quantifying marks 0 if there is a processor.
* **RAM**: To show the RAM memory we will use the command `free` to see at the moment information about the RAM, the used part, free, reserved for other resources, etc. For more info about the command we will put `free --help`; `free --mega` for mb as a unit
* **Disk memory**: `df` (disk filesystem), get a complete summary of the use of disk space; -m as MB;grep to only show us the lines that contain "/dev/" and then we will do another grep with the -v flag to exclude lines that contain "/boot". Finally, we will use the awk command and sum the value of the third word of each line to once all the lines are summed, print the final result of the sum.
* **CPU usage percentage**: `vmstat` shows system statistics, allowing us to obtain a general detail of the processes, memory usage, CPU activity, system status, etc; `tail -1` produce the output only on the last line, so of the 4 generated, only the last one will be printed; we will only print word 15, which is the available memory usage
* **Last reboot**: ``who -b` shows us date and time of the last reboot but with "system boot" I do not want to see so the whole command is `who -b | awk '$1 == "system" {print $3 " " $4}'` that shows only date and time of the last reboot
* **LVM active**: logical volume management; `lsblk` (list block devices) info about all block devices (hard drives, SSDs, memory...) and we see where is lvm as type of manager; we need yes or no so we use `if`; count the number of lines in which "lvm" appears and if there are more than 0 we will print Yes, if there are 0 we will print No
* **TCP connections**: (Transmission control protocol) `ss` and `-ta` flag so only TCP connections are shown; `grep` to see those established and `wc -l` to count the number of lines
* **Number of users**: `users`  will show us the names of the users; `wc -w` to count the number of words in the command output
* **IP address & MAC**: `hostname -I` To obtain the host address; `ip link` to obtain the MAC (media access control)-  show or modify the network interfaces. As more than one interface, IP's etc. appear, use `grep`
* **Number of commands with sudo**: `journaclctl` tool responsible for collecting and managing the system logs; `_COMM=sudo` filter the entries by specifying its path *In our case we put _COMM because it refers to an executable script*; `grep COMMAND` will show only the command lines; `wc -l` for numbered lines

* `uname -a` get CPU architecture
* `grep "physical id" /proc/cpuinfo | wc -l` get number of physical cores;  grep command looking inside the file for "physical id" and with wc -l to count the lines of the grep output 
* `grep processor /proc/cpuinfo | wc -l` get number of virtual cores 
* `free --mega | awk '$1 == "Mem:" {print $3}'` number of mb used
* `free --mega | awk '$1 == "Mem:" {print $2}'` total mb
* `free --mega | awk '$1 == "Mem:" {printf("(%.2f%%)\n", $3/$2*100)}' ` calculate the percentage of used memory
* `df -m | grep "/dev/" | grep -v "/boot" | awk '{memory_use += $3} END {print memory_use}'` get number of occupied disk memory
* `vmstat 1 4 | tail -1 | awk '{print $15}' t` gets CPU usage; *The result of this command is only part of the final result since there is still some operation to be done in the script for it to be correct. What should be done is to subtract the amount returned by our command from 100, the result of this operation will be printed with one decimal and a % at the end and the operation would be finished.*
* `who -b | awk '$1 == "system" {print $3 " " $4}'` shows the date and time of the last reboot
* `if [ $(lsblk | grep "lvm" | wc -l) -gt 0 ]; then echo yes; else echo no; fi` is LVM active or not.
* `lsblk` list all block devices and info about them
* `ss -ta | grep ESTAB | wc -l` number of TCP connections
* `users | wc -w` to get number of users
* `ip link | grep "link/ether" | awk '{print $2}'` to get MAC address
* `hostname -I` host address
* `journalctl _COMM=sudo | grep COMMAND | wc -l` to get number of executed sudo commands

# Crontab
* a background process manager. The specified processes will be executed at the time you specify in the crontab file
* crontab is like the timekeeper of your system. It schedules background tasks to run at specific times or intervals. This enables automation of repetitive tasks without manual intervention.
To configure crontab properly, you'll need to edit the crontab file using the command sudo crontab -u root -e.
Within the file, you'll add the following command to execute your script every 10 minutes: */10 * * * * sh /path/to/your/script.
Remember, crontab is a powerful tool, but it requires careful configuration to ensure tasks run smoothly and efficiently. 🕒
* `sudo crontab -u root -e` edit the file with `*/10 * * * * sh /home/dkucharo/monitoring.sh`

* m: Represents the minute when the script will be executed. Valid values range from 0 to 59.
* h: Indicates the hour in the 24-hour format. Values range from 0 to 23, where 0 represents midnight (12:00 AM).
* dom: Stands for the day of the month. For example, setting it to 15 would execute the script on the 15th day of each month.
* dow: Denotes the day of the week, either as a numeric value (0 to 7, where 0 and 7 represent Sunday) or using the first three letters of the English day names: mon, tue, wed, thu, fri, sat, sun.
* user: Specifies the user who will execute the command. This can be root or another user with appropriate permissions to run the script.
* command: Refers to the command or the absolute path of the script to be executed.

# Signature.txt
* Since once you turn it on or modify something, the signature will change
* we will run `shasum debian.vdi` and this will give us the signature
* The result of this signature is what we will need to add to our signature.txt file and subsequently upload the file to the intra repository. It is very important not to reopen the machine since the signature will be modified. For corrections, remember to clone the machine so you can turn it on without fear of changing the signature.
* `shasum`: a command that allows you to identify the integrity of a file using the SHA hash check sum of a file
