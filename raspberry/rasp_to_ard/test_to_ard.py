#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Le Raspbery Pi envoie des messages à l'Arduino

import serial  # bibliothèque permettant la communication série
import time    # pour le délai d'attente entre les messages

ser = serial.Serial('/dev/ttyUSB0', 9600)
compteur = 0
while True:     # boucle répétée jusqu'à l'interruption du programme
    if compteur < 6:
	    compteur = compteur + 1
    else:
	    compteur = 0
    ser.write(str(compteur).encode())
    time.sleep(1)               # on attend pendant 2 secondes
