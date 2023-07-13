import hashlib
import time
s=input("Enter the required string : ")
initial_time=time.time()
i=1
hashed_string = hashlib.sha256((s+str(i)).encode()).hexdigest()
while(int(hashed_string,16))>(0x00000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF):
    i+=1
    hashed_string = hashlib.sha256((s+str(i)).encode()).hexdigest()
final_time=time.time()
print("Appended number : "+str(i))
print("Time taken : "+str(final_time-initial_time))
print("Corresponding hash : "+hashed_string)
