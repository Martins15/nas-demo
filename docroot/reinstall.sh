#!/bin/sh

if [ "$1" = "--windows" ]; then
    time ansible-playbook -vvvv reinstall.yml -i 'localhost,' --connection=local --extra-vars "is_windows=true"
elif [ "$1" = "--debug" ]; then
    time ansible-playbook -vvvv reinstall.yml -i 'localhost,' --connection=local --extra-vars "active_environment=debug_migrate php_env_vars=APP_ENV=debug"
else
    time ansible-playbook -vvvv reinstall.yml -i 'localhost,' --connection=local
fi
