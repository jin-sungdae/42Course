#!/bin/bash
## ubuntu install
sudo apt-get install -y make
sudo apt-get install -y vim

## vi /etc/resolv.conf 수정
echo "search 8.8.4.4\nnameserver 8.8.8.8" > resolv.conf
rm -rf /etc/resolv.conf
mv resolv.conf /etc

sudo passwd
0000

su root
0000

echo "127.0.0.1 $sjin.42.fr" >> /etc/hosts

## docker 설치
sudo apt update
sudo apt install apt-transport-https ca-certificates curl software-properties-common gnupg2
curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo apt-key add -
sudo add-apt-repository "deb [arch=amd64] https://download.docker.com/linux/ubuntu bionic stable"
sudo apt update
apt-cache policy docker-ce
sudo apt install docker-ce

## docker-compose 설치
sudo curl -L "https://github.com/docker/compose/releases/download/1.24.1/docker-compose-$(uname -s)-$(uname -m)" -o /usr/local/bin/docker-compose
sudo chmod +x /usr/local/bin/docker-compose
sudo ln -s /usr/local/bin/docker-compose /usr/bin/docker-compose

## volume directory 만들기
sudo mkdir -p /home/sjin/data/wordpress
sudo mkdir -p /home/sjin/data/mariadb

## inception 실행
make

sudo docker exec -it nginx bash

apt-get install net-tools
netstat -tulpn

ssh-rsa AAAAB3NzaC1yc2EAAAADAQABAAABgQDX06aXVwdn/Up+WC0uSZYi9RY7/K7+RDdYlrJ9cHlrTVslmufa9hw9gr9zU1qY8JkTvuMEeri+P+/uPhdFZXuGaDdQNKub3psfr27BdvRlo5583r28OKJqyPyM8/EZh4g0XdFAcgP8P8S8fST5I8rqOnHrFWsKfJoQh2COy/8FirvgzlrkqY4E8rlJ+lSEvpbxf/nQtgufF358nRm/1+6PaKzHpyZhMGz16Y9XlUrBJl0Qt5hZn3ZO2ntLD3fC7O/To4qAt1KCWwWPT/zAOOY+mcjpmIQkjC2kZXqSuCKu/l7oZix2lnYvvfY6HWuhmh+yjr48ebxbkWs2Igwg2ymLnQZjT5Juvm9bx3YwU6K9vBE0qu34Idt63GTV3YrZuNHlqUqsn5z5P10bMMlxp/Mka2HQWlCjkPuQXcpWAvRh/7/1IUOyb1jsJdw14gE2Bbg5g2iNtcMTxzswdKfkgKnBbKMMUDAz7ECsjsNsClrYfn4fya9ob1vsYkKCW3Ms7MU= sjin@sjin-VirtualBox