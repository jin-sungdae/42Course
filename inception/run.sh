#!/bin/bash

apt-get install -y make
apt-get install -y vim

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
curl -fsSL https://download.docker.com/linux/debian/gpg | sudo apt-key add -
sudo add-apt-repository "deb [arch=amd64] https://download.docker.com/linux/debian $(lsb_release -cs) stable"
sudo apt update
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





