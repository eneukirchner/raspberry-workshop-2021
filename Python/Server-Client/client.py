#!/usr/bin/env python3

# Echo client program
import socket

HOST = 'localhost'    # The remote host
PORT = 50007              # The same port as used by the server
with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.connect((HOST, PORT))
    s.sendall(b'Hallo liebe Leute!')
    data = s.recv(1024)
print('Received', data.decode("utf-8"))
