#Email templates.

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
