#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Wed Sep  4 16:40:21 2019

@author: itamar
"""

from unicodedata import normalize
def remover_acentos(txt):
    return normalize('NFKD', txt).encode('ASCII', 'ignore').decode('ASCII')
   
if __name__ == '__main__':
    from doctest import testmod
    testmod()
    
arquivo = open('result.txt', 'w')

with open("example.txt") as file:
    for line in file:
        arquivo.write(remover_acentos(line))
 

