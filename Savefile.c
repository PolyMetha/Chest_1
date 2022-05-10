//
// Created by Quentin BALEZEAU on 07/05/2022.
//
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <time.h>           //requis par rand
#include <io.h>

#include "Savefile.h"
void savefile(){
    _setmode(_fileno(stdout), 0x00020000);
    wprintf(L"lol");
}