##### login ssh

~~~
ssh alarm@10.124.4.150
sudo su

exit
exit
~~~

##### replace nano

~~~
ln -svf /usr/bin/vim /usr/bin/nano
~~~

##### config vim

~~~
echo '" /usr/share/vim/vimfiles/archlinux.vim' > /etc/vimrc
echo 'runtime! archlinux.vim' >> /etc/vimrc
echo 'autocmd BufWritePre * %s/\s\+$//e' >> /etc/vimrc
echo 'filetype plugin on' >> /etc/vimrc
echo 'set expandtab ts=4 sw=4 ai'  >> /etc/vimrc
echo 'filetype plugin indent on' >> /etc/vimrc
echo 'set ic is hls'  >> /etc/vimrc
echo 'set number'  >> /etc/vimrc
echo 'set wrap!'  >> /etc/vimrc
~~~

##### ssh server

~~~
systemctl enable sshd.service
~~~

##### disable audit messages (qemu-chroot)

~~~
sed -i '$s/$/ audit=0/' /boot/cmdline.txt
~~~

##### generate locale (qemu-chroot)

~~~
echo "LANG=en_US.UTF-8" > /etc/locale.conf
echo "en_US ISO-8859-1" >> /etc/locale.gen
echo "en_US.UTF-8 UTF-8" >> /etc/locale.gen
locale-gen
~~~

##### sudoers no password (qemu-chroot)

~~~
echo "%wheel ALL=(ALL) NOPASSWD: ALL" >> /etc/sudoers
~~~

##### disable passwords (qemu-chroot)

~~~
passwd -d root
~~~

##### configure tty access

~~~
sudo groupadd -fr lock
sudo groupadd -fr uucp

sudo gpasswd -a alarm lock
sudo gpasswd -a alarm uucp
~~~

##### console font (qemu-chroot)

~~~
echo "FONT=ter-112n
FONT_MAP=8859-2
" > /etc/vconsole.conf
~~~

##### cli autologin (qemu-chroot)

~~~
mkdir -p /etc/systemd/system/getty@tty1.service.d/

echo "[Service]
ExecStart=
ExecStart=-/sbin/agetty --autologin alarm --noclear %I 38400 linux
" > /etc/systemd/system/getty@tty1.service.d/autologin.conf
~~~
