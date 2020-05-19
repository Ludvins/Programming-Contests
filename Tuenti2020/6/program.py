from telnetlib import Telnet
from copy import deepcopy
from collections import Counter 
import numpy as np

size = 300
princess = [150,151]

def find(mapa, pos, goal):
    if (pos[0] < 0 or pos[0] >= size or pos[1] < 0 or pos[1] >= size):
        return (False, [], [])
    if pos == goal:
        return (True, [], [])
    if mapa[pos[0]][pos[1]] == '#':
        return (False, [], [])
    if mapa[pos[0]][pos[1]] == '?':
        return (False, [], [pos])
    
    mapa[ pos[0] ][ pos[1] ] = '#'
    
    di, dj = [1, 2, 2, 1, -1 , -2, -2, -1], [2, 1, -1, -2, -2, -1, 1, 2]
    moves = [ "1D2R", "2D1R", "2D1L", "1D2L", "1U2L", "2U1L", "2U1R", "1U2R"]
    unk = []
    for k in range(8):
        result = find(mapa, [ pos[0]+di[k], pos[1]+dj[k] ], goal)
        unk.extend(result[2])
        if result[0]:
            result[1].append( moves[k] )
            return (True, result[1], unk)
    return (False, [], unk)

def read_square(my_position, mapa, tn):
    for i in range(-2, 3):
        line = str(tn.read_until(b"\n"))[2:-3]
        for j in range(-2, 3):
            mapa[ my_position[0]+i ][my_position[1]+j ] = line[j+2]
    mapa[ my_position[0] ][my_position[1] ] = '.'
    tn.read_until(b"\n")

def dist(p):
    return abs(p[0]-princess[0]) + abs(p[1]-princess[1])

def update(move, my_position):
    moves = {"1U2L" :[-1,-2], 
             "2U1L" :[-2,-1],
             "2U1R" :[-2,1],
             "1U2R" :[-1,2],
             "1D2R" :[1,2],
             "2D1R" :[2,1],
             "2D1L" :[2,-1],
             "1D2L" :[1,-2]}
    m = moves[move]
    return [ my_position[0]+m[0], my_position[1]+m[1] ]

with Telnet('52.49.91.111', 2003) as tn:
    my_position = [150,150]
    mapa = [ [ '?' for i in range(size) ] for j in range(size) ] 
        
    read_square(my_position, mapa, tn)
        
    can_reach_princess = False
    while not can_reach_princess:
        
        mapacopy = deepcopy(mapa)
        can_reach_princess, path, unk = find(mapacopy, my_position, princess)
            
        if not can_reach_princess:
            mapacopy = deepcopy(mapa)
            unk.sort(key=dist)
            _, path, _ = find(mapacopy, my_position, unk[0])
                
        for move in reversed(path[1:]):
            my_position = update(move, my_position)
            #print(move)
            tn.write( ("{}\n".format(move)).encode() )
            read_square(my_position, mapa, tn)
            tn.read_until(b"\n")
            
        if can_reach_princess:
            tn.write( "{}\n".format(path[0]).encode())
            while True:
                line = str(tn.read_until(b"\n"))[2:-3]
                print(line)
