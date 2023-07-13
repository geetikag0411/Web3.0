# Problem statement:

Write a program that takes some data as string input. Then it tries to find a positive number x such that when x is appended to the end of the string, the SHA256 hash of this new string is less than the target, which is

0x00000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF

Also print the time it takes to get this nonce value. 

You are supposed to use pre-implemented libraries for hashing, such as the js crypto library or the go crypto library, and not implement your own hashing function. So the task should not be difficult to proceed with. You can do this in any language of your choice. However, the mentors are more familiar with crypto usage in js, python and go so it will be better if you can do the assignment in one of these languages.

# Explaination of the code:

I have imported two libraries "hashlib"(for sha256() function) and "time" (for time() func).

hashed_string = hashlib.sha256((s+str(i)).encode()).hexdigest() coverts the given string to hexadecimal number.

(encode() coverts the string to binary and hexdigest() coverts the output of hash func to hexadecimal number)
![image](https://user-images.githubusercontent.com/96648258/171408650-92c11165-493f-4354-b23e-f9c2f469ebc3.png)

