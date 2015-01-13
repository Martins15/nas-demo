; PP WYSIWYG Makefile

api = 2
core = 7.x

; The WYSIWYG Module

projects[wysiwyg][subdir] = "contrib"
projects[wysiwyg][download][type] = "git"
projects[wysiwyg][download][branch] = "7.x-2.x"
projects[wysiwyg][download][revision] = "ee64524b3edb2aa21098a2309b0736e292010247"

; Include editors

libraries[ckeditor][download][type] = "get"
libraries[ckeditor][download][url] = "http://download.cksource.com/CKEditor/CKEditor/CKEditor%204.3.2/ckeditor_4.3.2_full.zip"
libraries[ckeditor][type] = "libraries"