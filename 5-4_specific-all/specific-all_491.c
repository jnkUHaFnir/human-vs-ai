mutexlock(mutex)
signal[i] = 1;
mutexunlock(mutex)

mutexlock(mutex)
while(signal[i] == 1) {
condwait(cond, mutex)
}
mutexunlock(mutex)
