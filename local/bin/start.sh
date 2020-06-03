#!/bin/sh
# make library link
export PATH=$PATH:/usr/local/lib64
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/local/lib64

# start service with nobody
sudo -u nobody /usr/local/bin/pgagroal -c /usr/local/etc/pgagroal/pgagroal.conf -a /usr/local/etc/pgagroal/pgagroal_hba.conf
