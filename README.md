# hangman
funny word game

Written for HelenOS and hard changed SrBinOS

Do what you wont, with this app.

Make it better if you can, & share with us.


![start](https://github.com/user-attachments/assets/2316c966-caea-45fc-bd6c-ac02f4324c78)
![play](https://github.com/user-attachments/assets/80dd0bf9-f9c1-4d27-98ab-73ecc56dda8b)
![end](https://github.com/user-attachments/assets/4b3f8b5e-c3e5-444d-9e3e-a31805752dde)


Install
Add complete folder "hangman" with all files under "uspace/app/"

In file meson.build    "uspace/app/meson.build"

add line "hangman" as is below

'gfxdemo',

'gunzip',

'hangman',

'hbench',

NOTE: If you need more, or different words for game, change it or Add in file 
"words.h"..
First come word, than HINT for that word...

Enjou!
