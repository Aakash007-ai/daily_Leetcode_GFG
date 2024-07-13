# name = "John"
# print(name)

# _hell = "Wick"
# print(_hell)

# # 123ow = "" we can't start name with this convention

# #python is an interpreted language means it runs directly line by line so, we get error at runtime and break and get out of program
# x=7
# print (x+2) # both are of same type get added

# y=2+"Wonder" #give syntax error here itself and break here
# print(y)

# print(x+'1') #give syntax error

# x= "wonder" # we can re assign a already declared variable with other data type

##########################################

# x = input() #every time it take inputas string
# print(type (x))

# y = int(input("Enter a number")) # throw error if any other value pu here

# y+=3 #in place operator

# print(y)

##########################################

# isTrue = False

# print(isTrue)
# print(2==2.0)
# print(3!=3)
# print(8.7== 8.70)


# ls = ["hello",1,"world"]
# ls[2]="wick"

# print(ls[0])
# print(ls[-1])#indexing start from last
# print(ls*3+ ["Gangsta Paradise"]) #list get merged

# print("wick" in ls)
# print("john" not in ls)

# ls.append("john")

# ls.pop() # remove from first

# print(ls)
# print(len(ls))

# ls.insert(1,"is") # move all elements right and insert at that index
# print(ls, ls.index('is')) #give us index 

# for i in ls:
#     print(i)

################################################################################
# i=1
# while i<5:
#     if i%2==0:
#         #continue
#         print(i)
    
#     if i==3:
#         break
#     i+=1


# for words in ["John" ,"Wick"]:
#     print(words)


# # range(10) from 0 to 9 inclusive
# # range(3,10) from range 3 to 9
# # rage = list(range(10))
# rage = list([i for i in range(3,10,2)])  # i+2 with step of 1 it skip 1 (i+1 surpass itself move to next, i+2 drop 1 index)
# print(rage)

###################################################################################################

# def my_func(word="hi"):
#     print("hello " + word)

# my_func()
# my_func("Wick")

# try:
#     print(1/0)
#     raise TypeError("a new way to raise error")
# except:
#     print("Error occured")
#     #raise  # again riasing captured error
# finally:
#     print("program continue")


# assert 2==1+1 , "called wheh became false"  #used for testing

#####################################################################################################
"""
    None is used to represent absence of a value, false when converted to boolean
"""
print(None==[]) # false   suppose a function return nothing return None to a variable

ages = {# keys must be hasable
    "John":2,
    "WICK":3,
    "abc":4,
}
print(ages["abc"])
# print(ages[0]) #give error as there is no key 0

# only immutable objects can be used as keys to dictionaries
# immutable objects are those that can't be change
#  key of dictionaries are immutable 
#  mutable objects are list and dictoinary we can change their value

# immmutable (they can't be changed)
# created using parenthesis () instead of {}
words= (1,2,3,4)

# words[0]=2    tupledoesn't support reassignmnet       

# list slices
ls = [i for i in range(10)]
print(ls[0:2]) # inclusive, exclusive
print(ls[:5])
print(ls[::-1]) #reverse a list

print(ls[-5:]) # starting from last 5th element to end

print(ls[1:8:2])# starting , ending , jumps elements-1
print(ls[2::-1]) # reverse it -1 meas indexing start from last : 2 , 1, 0
print("John {} Wick {} Chapter {}".format(1,2,3))
print("M1 : {x} and MI: {y}".format(x=2,y=3))
print(",".join("hello"))
print(" ".join(["John", "Wick"]))


# all[i>2 for i in ls] //return true or false when it run,if all are true or false
# any[i>2 for i in ls]

for index,item in enumerate(ls):
    print(index,item)

