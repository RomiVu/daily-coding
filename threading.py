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



# import threading
# import time


# def first_func():
#     print(f'{threading.current_thread().name} is starting...')
#     time.sleep(2)
#     print(f'{threading.current_thread().name} is closing...')


# def second_func():
#     print(f'{threading.current_thread().name} is starting...')
#     time.sleep(2)
#     print(f'{threading.current_thread().name} is closing...')


# def third_func():
#     print(f'{threading.current_thread().name} is starting...')
#     time.sleep(2)
#     print(f'{threading.current_thread().name} is closing...')


# if __name__ == '__main__':
#     t1 = threading.Thread(name='first_func', target=first_func)
#     t2 = threading.Thread(name='second_func', target=second_func)
#     t3 = threading.Thread(target=third_func)
#     t1.start()
#     t2.start()
#     t3.start()


# import threading
# import time

# ExitFlag = 0
# index = 0


# class MyThread(threading.Thread):
#     def __init__(self, thread_id, name, delay):
#         threading.Thread.__init__(self)
#         self.thread_id = thread_id
#         self.name = name
#         self.delay = delay

#     def run(self):
#         print('Starting  ' + self.name)
#         print_time(self.name, self.delay, 5)
#         print('Exiting  ' + self.name)


# def print_time(name, delay, counter):
#     global index
#     while counter:
#         index += 1
#         if ExitFlag:
#             thread.exit()

#         time.sleep(delay)
#         print(f'{name} starting at {time.ctime()} and index--> {index}')
#         counter -= 1


# t1 = MyThread(1, 'threading-1', 1)
# t2 = MyThread(2, 'threading-2', 1)

# t1.start()
# t2.start()
# print(f'Exiting {threading.current_thread().name}...')

# from threading import Thread, Condition
# import time

# items = []
# condition = Condition()


# class Consumer(Thread):
#     def __init__(self):
#         Thread.__init__(self)

#     def consume(self):
#         global condition
#         global items
#         condition.acquire()
#         if len(items) == 0:
#             condition.wait()
#             print('consumer notify --> no item to consume!')
#         print(f'{items.pop()} has been consumed')
#         print(f'{len(items)} after popping up...')
#         condition.notify()
#         condition.release()

#     def run(self):
#         for i in range(20):
#             time.sleep(1)
#             self.consume()


# class Producer(Thread):
#     def __init__(self):
#         Thread.__init__(self)

#     def produce(self):
#         global condition
#         global items
#         condition.acquire()
#         if len(items) == 10:
#             condition.wait()
#             print(f'{len(items)} can be consumed; and produce must be stopped.')
#         items.append(1)
#         print(f'{len(items)} after appending with...')
#         condition.notify()
#         condition.release()

#     def run(self):
#         for i in range(20):
#             time.sleep(2)
#             self.produce()


# if __name__ == '__main__':
#     p1 = Producer()
#     c1 = Consumer()
#     p1.start()
#     c1.start()
#     p1.join()
#     c1.join()

from queue import Queue
from threading import Thread, Event
import random
import time


class C(Thread):
    def __init__(self, queue):
        Thread.__init__(self)
        self.queue = queue

    def run(self):
        while True:
            item = self.queue.get()
            print(f'Consumer notify --> {item} {self.name} POP')
            self.queue.task_done()


class P(Thread):
    def __init__(self, queue):
        Thread.__init__(self)
        self.queue = queue

    def run(self):
        for i in range(10):
            item = random.randint(1, 256)
            self.queue.put(item)
            print(f'Producer notify --> {item} {self.name} ADD')
            time.sleep(random.random())


if __name__ == '__main__':
    queue = Queue()
    p1 = P(queue)
    c2 = C(queue)
    c3 = C(queue)
    c4 = C(queue)
    p1.start()
    c2.start()
    c3.start()
    c4.start()
    p1.join()
    c2.join()
    c3.join()
    c4.join()
