# def func(num):
#     if(num > 0):
#         print(num,end=" ")
#         func(num-1)
#         print(num,end=" ")

# func(3)
# import time
# cnt = 0
# start1 = time.time()
# for i in range(10000):
#     cnt+=1
# end1 = time.time()


# cnt = 0 
# start2 = time.time()
# for i in range(10000):
#     cnt += 1
#     print()
# end2 = time.time()
# print(end1 - start1,end2 - start2)
    
def count(n):
    if n == 0:
        return 0
    return 1 + count(n - 1)


print(count(4))