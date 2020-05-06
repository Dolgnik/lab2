FROM centos

MAINTAINER AntonSO <Prototype5228@mail.ru>

RUN yum update -y && yum install -y epel-release && yum install -y gcc && yum install -y vim && yum install -y git && yum groupinstall -y "Development Tools" && yum install -y kernel-devel kernel-headers
