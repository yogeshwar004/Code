class Time:
    pass

def add_time(t1,t2):
    sum=Time()
    sum.hour=t1.hour+t2.hour
    sum.minute=t1.minute+t2.minute
    sum.second=t1.second+t2.second

    while sum.second>=60:
        sum.second=sum.second-60
        sum.minute=sum.minute+1
    while sum.minute>=60:
        sum.minute=sum.minute-60
        sum.hour=sum.hour+1
    return sum

start=Time()
start.hour=9
start.minute=45
start.second=0

duration=Time()
duration.hour=1
duration.minute=35
duration.second=240

done=add_time(start,duration)
print(done.hour,done.minute,done.second,sep=':')

