import ctypes
import os
import time
from datetime import datetime


class TimeSpec(ctypes.Structure):
    _fields_ = [
        ('tv_sec', ctypes.c_long),
        ('tv_nsec', ctypes.c_long)
    ]


def monotonic_time():
    CLOCK_MONOTONIC = 4
    lib = ctypes.CDLL('libSystem.dylib', use_errno=True)
    cg = lib.clock_gettime
    cg.argtypes = [ctypes.c_int, ctypes.POINTER(TimeSpec)]
    time = TimeSpec()
    if cg(CLOCK_MONOTONIC, ctypes.pointer(time)):
        errno_ = ctypes.get_errno()
        raise OSError(errno_, os.strerror(errno_))
    return time.tv_sec + time.tv_nsec * 1e-9


if __name__ == "__main__":
    print(monotonic_time())
    time.sleep(10)
    print(monotonic_time())

    print(datetime.now())
    time.sleep(10)
    print(datetime.now())