# import random
# import threading
# from time import sleep
'''
the first way to create a multi threading...
built a class subclassed by Thread
'''
# class SecondWay(threading.Thread):
#     def __init__(self):
#         threading.Thread.__init__(self)
#         self.message = 'Hello'

#     def print(self):
#         print(self.message)

#     def run(self):
#         for i in range(10):
#             self.print()
#             #print(f'sequence {i} in {threading.current_thread().name}')
#             sleep(random.random() * 2)


# print('process begin...')
# a = SecondWay()
# a.start()
# print('process end...')



import random
import threading
import time
'''
the second way to create a multi threading...
built a class subclassed by Thread
'''
def test(text):
    for item in text:
        print(f'{item} and {threading.current_thread().name}')
        time.sleep(random.random())


t1 = threading.Thread(target=test, name='kitty', args=(['a', 'b', 'c', 'd'],))


t2 = threading.Thread(target=test, name='hello', args=(['1', '22', '333', '4444'],))


print(f'{threading.current_thread().name} started.')
t1.start()
t2.start()
t1.join()
t2.join()

print(f'{threading.current_thread().name} ended.')
