#this is an attempt at recursive I.E BufferOverFlow Check Wit 2 Compliment Addition
import sys
global x,y
response = input(int(x))
response1 = input(int(x))

print("X is first then Y is Second\n\n\n\n\n",
      "<Enter | Input>:")

x = 0
y = 0

if x + y -2**32<= 2**32:
    sys.exit()
if 2**31 <=x+y:
    sys.exit()
if x+y == -2**31 <= x+y < 2**31:         
    sys.flush()
if x+y + 2**32 == x + y<-2**31:
    sys.exit()
    
