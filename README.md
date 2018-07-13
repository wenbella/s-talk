# s-talk

1. Description

I finish all requirements in assignment 2, i.e, 4 threads handle with differet tasks and two mutex lockers are applied to two buffers (sendBuff and receiveBuff).

2. How to test the code

step 1: complie the code by typing "make" 

step 2: open two terminals and within each of them, typing

"s-talk [local port number] [remote machine name] [remote port name]"

for example: terminal 1: s-talk 8080 localhost 8081
             terminal 2: s-talk 8081 localhost 8080
			 
To terminate the talking, type "!"			 

 
 
			 
