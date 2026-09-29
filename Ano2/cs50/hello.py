#ask user for name
name = input("What's your name? ")

#say hello to user
print("hello, " + name)     #one argument resulting from concatenate
print("hello,", name)       #two arguments, python puts the blank for you
print("hello, ", end='')    #print(*objs, sep=' ', end='\n', file=sys.stdout, flush=Flase)
print(name)