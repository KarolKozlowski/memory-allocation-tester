# It's a mem-eater... watch out boy it'll chew you up

`mkdir /home/karol/.config/systemd/user/`

`# ln -s $(pwd)/mem.service /home/karol/.config/systemd/user/`

`cp mem.slice /etc/systemd/user/`

`cp mem.service /etc/systemd/user/`

`systemctl --user daemon-reload`

`systemctl --user start mem.service`
