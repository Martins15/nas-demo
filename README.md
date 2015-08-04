NAS Drupal project
======

Drupal project is for NAS

For obtaining development environment locally You should install vagrant and puppet and from console ran
```sh
vagrant up && vagrant ssh
```
afterwards.
You will be logged into virtual machine.

use
```sh
sh reinstall.sh
```
for drupal reinstallation from scratch

```sh
sh runsniffers.sh
```
for local execution of sniffers stack

Virtual host for accessing drupal installation

```
Default (English) locale

http://nas.192.168.56.132.xip.io
https://nas.192.168.56.132.xip.io

Spanish locale.

http://es.nas.192.168.56.132.xip.io
https://es.nas.192.168.56.132.xip.io
```

Adminer for mysql administration (credentials drupal:drupal and root:root)

```
http://192.168.56.132.xip.io/adminer.php
```


If ```xip.io``` not working - create row with

```hosts
192.168.56.132 nas.192.168.56.132.xip.io es.nas.192.168.56.132.xip.io
```

in ```/etc/hosts```

For Windows users

- install vagrant 1.5/1.6
- install puppet
- install cygwin console www.cygwin.com (Do select 32/64 bit depending of Your host system)
- Run cygwin via right mouse button with "Run as administrator"
- cd to project folder
- git clone project repo  (Git should be configured for unix file endings)
- vagrant up
