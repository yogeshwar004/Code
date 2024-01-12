class Time:
    pass

def time_to_int(time):
    minutes=time.hour*60+time.minute
    second=minutes*60+time.second
    return second

start=Time()
start.hour=9
start.minute=45
start.second=0

done=time_to_int(start)
print(done)

