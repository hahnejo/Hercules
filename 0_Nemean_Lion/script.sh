cat /etc/ssh/ssh_config | sed 's/Port 22/Port 4242' > .my_sshd_config
mv .my_sshd_config /etc/ssh/sshd_config
service ssh restart
# ss -l to check if port number has changed