sed -i -e 's/#Port 22/Port 4242/' /etc/ssh/sshd_config
service ssh restart
# ss -l to check if port number has changed