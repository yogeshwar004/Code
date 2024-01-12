class Time:
    pass

def time_to_int(time):
    minutes=time.hour*60+time.minute
    second=minutes*60+time.second
    return second

def int_to_time(second):
    time=Time()
    minutes,time.second=divmod(second,60)
    time.hour,time.minute=divmod(minutes,60)
    return time

start=Time()
start.hour=9
start.minute=45
start.second=0

done=time_to_int(start)
print(done)

z=int_to_time(done)
print(z.hour,z.minute,z.second,sep=':')




