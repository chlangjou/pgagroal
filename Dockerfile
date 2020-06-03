FROM centos

COPY local/ /usr/local/
RUN export PATH=$PATH:/usr/local/lib64 \
    && export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/local/lib64 \
    && dnf install -y libev  openssl sudo \
    && echo /usr/local/lib64 > /etc/ld.so.conf.d/usrlocal.conf \
    && ldconfig 

CMD ["/usr/local/bin/start.sh"]
