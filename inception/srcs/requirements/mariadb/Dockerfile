FROM debian:buster

RUN apt-get update
RUN apt-get install mariadb-server -y

EXPOSE 3306

COPY ./conf/50-server.cnf /etc/mysql/mariadb.conf.d/
COPY ./tools /var/www/

RUN service mysql start && mysql < /var/www/initial_db.sql && rm -f /var/www/initial-db.sql; 
## 수정

CMD ["mysqld"]