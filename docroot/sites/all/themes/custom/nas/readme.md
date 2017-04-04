# Recompiling CSS

Install Ruby 2.2.5:
`gpg --keyserver hkp://keys.gnupg.net --recv-keys 409B6B1796C275462A1703113804BB82D39DC0E3`

`\curl -sSL https://get.rvm.io | bash -s stable`

Restart sh client.

`rvm install ruby-2.2.5`

Set as default ruby:

`rvm --default use 2.2.5`

Install compass
`gem install compass`

Go to the theme folder and compile it
`compass compile`

You need to run `chmod +t /tmp` if you get `'tmpdir': could not find a temporary directory'` error

# Email templates.

Look native-plants-emails/README.md

## Dependencies

### Installing NPM

```curl -sL https://deb.nodesource.com/setup | sudo bash -
sudo apt-get install -y nodejs```


### Installing Foundation CLI tools

Follow http://foundation.zurb.com/emails/docs/sass-guide.html or just:

`sudo npm install --global foundation-cli`

## Creating a new foundation project (once per project)

Go to theme folder and exec:

`foundation new --framework emails`

## Updating email template for existing projects:

`foundation watch`


## Building (inlining)

npm run build
